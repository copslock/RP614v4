/*
 * main.c - contains the main() function
 *
 * Copyright (C) 1998 Brad M. Garcia <garsh@home.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <grp.h>
#include <pwd.h>
#include <dirent.h>

#include "relay.h"
#include "cache.h"
#include "common.h"
#include "args.h"
#include "sig.h"
#include "master.h"
#include "domnode.h"
#include "lib.h"
#include "qid.h"
#include "query.h"

/*
 * main() - startup the program.
 *
 * In:      argc - number of command-line arguments.
 *          argv - string array containing command-line arguments.
 *
 * Returns: 0 on exit, -1 on error.
 *
 * Abstract: We set up the signal handler, parse arguments,
 *           turn into a daemon, write our pid to /var/run/dnrd.pid,
 *           setup our sockets, and then parse packets until we die.
 */
int main(int argc, char *argv[])
{
  /*    int                i;*/
    FILE              *filep;
    struct servent    *servent;   /* Let's be good and find the port numbers
				     the right way */
#ifndef EMBED
    struct passwd     *pwent;
    DIR               *dirp;
    struct dirent     *direntry;
    struct stat        st;
    int                rslt;
#endif
    domnode_t *p;
    srvnode_t *s;



    /*
     * Setup signal handlers.
     */
    signal(SIGHUP, sig_handler);		// hangup dnrd

    signal(SIGINT,  sig_handler);
    signal(SIGQUIT, sig_handler);
    signal(SIGTERM, sig_handler);
    signal(SIGUSR1, sig_handler);
    /*
     * Handling TCP requests is done by forking a child.  When they terminate
     * they send SIGCHLDs to the parent.  This will eventually interrupt
     * some system calls.  Because I don't know if this is handled it's better
     * to ignore them -- 14OCT99wzk
     */
    signal(SIGCHLD, SIG_IGN);

    /*
     * Initialization in common.h of recv_addr is broken, causing at
     * least the '-a' switch not to work.  Instead of assuming
     * positions of fields in the struct across platforms I thought it
     * safer to do a standard initialization in main().
     */
    memset(&recv_addr, 0, sizeof(recv_addr));
    recv_addr.sin_family = AF_INET;
    recv_addr.sin_port = htons(53);


    /* create the domain list */
    domain_list = alloc_domnode();
    /*
     * Parse the command line.
     */
    parse_args(argc, argv);

    filep = fopen(serv_file, "r");
    if (filep)	// serv file exist
    {
    	fclose(filep);
	parse_serfile();
    }

#ifndef EMBED
    openlog(progname, LOG_PID, LOG_DAEMON);
#endif
#ifdef ENABLE_PIDFILE
    /*
     * Kill any currently running copies of the program.
     */
    kill_current();
#endif

    /*
     * Setup the thread synchronization semaphore
     */
#ifndef EMBED
    if (sem_init(&dnrd_sem, 0, 1) == -1) {
	log_msg(LOG_ERR, "Couldn't initialize semaphore");
	cleanexit(-1);
    }
#endif
#ifdef ENABLE_PIDFILE
    /*
     * Write our pid to the appropriate file.
     * Just open the file here.  We'll write to it after we fork.
     */
    filep = fopen(pid_file, "w");
    if (!filep) {
	log_msg(LOG_ERR, "can't write to %s.  "
		"Check that dnrd was started by root.", pid_file);
	exit(-1);
    }
#endif

    /*
     * Pretend we don't know that we want port 53
     */
    servent = getservbyname("domain", "udp");
    if (servent != getservbyname("domain", "tcp")) {
	log_msg(LOG_ERR, "domain ports for udp & tcp differ.  "
	       "Check /etc/services");
	exit(-1);
    }
    recv_addr.sin_port = servent ? servent->s_port : htons(53);

    /*
     * Setup our DNS query reception socket.
     */
    if ((isock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
	log_msg(LOG_ERR, "isock: Couldn't open socket");
	cleanexit(-1);
    }
    else {
	int opt = 1;
	setsockopt(isock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    }

    if (bind(isock, (struct sockaddr *)&recv_addr, sizeof(recv_addr)) < 0) {
	log_msg(LOG_ERR, "isock: Couldn't bind local address");
	cleanexit(-1);
    }

    /*
     * Setup our DNS tcp proxy socket.
     */
#ifdef ENABLE_TCP
    if ((tcpsock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
	log_msg(LOG_ERR, "tcpsock: Couldn't open socket");
	cleanexit(-1);
    }
    else {
	int opt = 1;
	setsockopt(tcpsock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    }
    if (bind(tcpsock, (struct sockaddr *)&recv_addr, sizeof(recv_addr)) < 0) {
	log_msg(LOG_ERR, "tcpsock: Couldn't bind local address");
	cleanexit(-1);
    }
    if (listen(tcpsock, 5) != 0) {
	log_msg(LOG_ERR, "tcpsock: Can't listen");
	cleanexit(-1);
    }
#endif

    /* Initialise our cache */
    cache_init();

    /* init the qid pool */
    qid_init_pool();

#ifndef EXCLUDE_MASTER
    /* Initialise out master DNS */
    master_init();
#endif

    /* init query list */
    query_init();

#ifndef EMBED
    pwent = getpwnam("nobody");

    /*
     * Change our root and current working directories to
     * /usr/local/etc/dnrd.  Also, so some sanity checking on that
     * directory first.
     */
    dirp = opendir(dnrd_root);
    if (!dirp) {
	log_msg(LOG_ERR, "The directory %s must be created before "
		"dnrd will run", dnrd_root);
	cleanexit(-1);
    }

    rslt = stat(dnrd_root, &st);
    if (st.st_uid != 0) {
	log_msg(LOG_ERR, "The %s directory must be owned by root", dnrd_root);
	cleanexit(-1);
    }
    if ((st.st_mode & (S_IWGRP | S_IWOTH)) != 0) {
	log_msg(LOG_ERR,
		"The %s directory should only be user writable", dnrd_root);
	cleanexit(-1);
    }

    while ((direntry = readdir(dirp)) != NULL) {

	if (!strcmp(direntry->d_name, ".") ||
	    !strcmp(direntry->d_name, "..")) {
	    continue;
	}

	rslt = stat(direntry->d_name, &st);

	if (rslt) continue;
	if (S_ISDIR(st.st_mode)) {
	    log_msg(LOG_ERR, "The %s directory must not contain "
		    "subdirectories", dnrd_root);
	    cleanexit(-1);
	}
	if ((st.st_mode & (S_IXUSR|S_IXGRP|S_IXOTH|S_IWGRP|S_IWOTH)) != 0) {
	    log_msg(LOG_ERR, "A file in %s has either execute "
		    "permissions or non-user write permission.  Please do a "
		    "\"chmod a-x,go-w\" on all files in this directory",
		    dnrd_root);
	    cleanexit(-1);
	}
	if (st.st_uid != 0) {
	    log_msg(LOG_ERR, "All files in %s must be owned by root",
		    dnrd_root);
	    cleanexit(-1);
	}
    }
    closedir(dirp);

    if (chdir(dnrd_root)) {
	log_msg(LOG_ERR, "couldn't chdir to %s, %s",
		dnrd_root, strerror(errno));
	cleanexit(-1);
    }
    if (chroot(dnrd_root)) {
	log_msg(LOG_ERR, "couldn't chroot to %s, %s",
		dnrd_root, strerror(errno));
	cleanexit(-1);
    }

    /*
     * Change uid/gid to something other than root.
     */

    /* drop supplementary groups */
    if (setgroups(0, NULL) < 0) {
	log_msg(LOG_ERR, "can't drop supplementary groups");
	cleanexit(-1);
    }
    /*
     * Switch uid/gid to something safer than root if requested.
     * By default, attempt to switch to user & group id 65534.
     */

    if (daemongid != 0) {
	if (setgid(daemongid) < 0) {
	    log_msg(LOG_ERR, "couldn't switch to gid %i", daemongid);
	    cleanexit(-1);
	}
    }
    else if (!pwent) {
	log_msg(LOG_ERR, "Couldn't become the \"nobody\" user.  Please use "
		"the \"-uid\" option.\n"
		"       dnrd must become a non-root process.");
	cleanexit(-1);
    }
    else if (setgid(pwent->pw_gid) < 0){
	log_msg(LOG_ERR, "couldn't switch to gid %i", pwent->pw_gid);
	cleanexit(-1);
    }

    if (daemonuid != 0) {
	if (setuid(daemonuid) < 0) {
	    log_msg(LOG_ERR, "couldn't switch to uid %i", daemonuid);
	    cleanexit(-1);
	}
    }
    else if (!pwent) {
	log_msg(LOG_ERR, "Couldn't become the \"nobody\" user.  Please use "
		"the \"-uid\" option.\n"
		"       dnrd must become a non-root process.");
	cleanexit(-1);
    }
    else if (setuid(pwent->pw_uid) < 0){
	log_msg(LOG_ERR, "couldn't switch to uid %i", pwent->pw_uid);
	cleanexit(-1);
    }
#endif
    /*
     * Setup our DNS query forwarding socket.
     */
    p=domain_list;
    do {
      s=p->srvlist;
      while ((s=s->next) != p->srvlist) {
	/*
	if ((s->sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
	    log_msg(LOG_ERR, "osock: Couldn't open socket");
	    cleanexit(-1);
	}
	*/
	s->addr.sin_family = AF_INET;
	s->addr.sin_port   = htons(53);
      }
      /* set the first server as current */
      p->current = p->srvlist->next;
    } while ((p=p->next) != domain_list);

    /*
     * Now it's time to become a daemon.
     */
#ifdef DNRD_DAEMON
    if (!opt_debug) {
	pid_t pid = fork();
	if (pid < 0) {
	    log_msg(LOG_ERR, "%s: Couldn't fork\n", progname);
	    exit(-1);
	}
	if (pid != 0) exit(0);
	gotterminal = 0;
	setsid();
	chdir("/");
	umask(077);
	fclose(stdin);
	fclose(stdout);
	fclose(stderr);
    }
#endif
#ifdef ENABLE_PIDFILE
    /*
     * Write our pid to the appropriate file.
     * Now we actually write to it and close it.
     */
    fprintf(filep, "%i\n", (int)getpid());
    fclose(filep);
#endif

    /*
     * Run forever.
     */
    run();
    exit(0); /* to make compiler happy */
}

