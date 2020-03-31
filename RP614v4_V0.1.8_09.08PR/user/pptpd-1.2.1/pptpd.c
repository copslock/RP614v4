/*
 * pptpd.c
 *
 * Grabs any command line argument and processes any further options in
 * the pptpd config file, before throwing over to pptpmanager.c.
 *
 * $Id: pptpd.c,v 1.1 2005/07/29 03:40:47 tony Exp $
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef __linux__
#define _GNU_SOURCE 1		/* strdup() prototype, broken arpa/inet.h */
#endif

#ifdef __svr4__
#define __EXTENSIONS__ 1	/* strdup() prototype */
#endif

#ifdef __sgi__
#define _XOPEN_SOURCE 500	/* strdup() prototype */
#endif

#include "our_syslog.h"
#include "our_getopt.h"

#include <fcntl.h>
#include <netdb.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>

#include "configfile.h"
#include "defaults.h"
#include "compat.h"
#include "pptpmanager.h"

#ifdef CONFIG_NETtel
#include <linux/ledman.h>
#endif

/* command line arg variables */
char *ppp_binary = NULL;
char *pppdoptstr = NULL;
char *speedstr = NULL;
char *bindaddr = NULL;
#ifdef BCRELAY
char *bcrelay = NULL;
#endif
int pptp_debug = 0;
int pptp_noipparam = 0;
int pptp_logwtmp = 0;

#if defined(PPPD_IP_ALLOC)
int pptp_stimeout = STIMEOUT_DEFAULT;
#endif

#if !defined(PPPD_IP_ALLOC)
int maxConnections = MAX_CONNECTIONS;

char localIP[MAX_CONNECTIONS][16];
char remoteIP[MAX_CONNECTIONS][16];

/* Local prototypes */
static void processIPStr(int type, char *ipstr);
#endif

#ifndef HAVE_DAEMON
static void my_daemon(int argc, char **argv);
#endif

static void log_pid(char *pid_file);
static char *lookup(char *);

#ifdef BCRELAY
static void launch_bcrelay();
static void killbcrelay(int sigraised);
static pid_t bcrelayfork;
#endif

static void showusage(char *prog)
{
	printf("\nPoptop v%s\n", VERSION);
	printf("The PPTP Server for Linux\n");
	printf("Usage: pptpd [options], where options are:\n\n");
#ifdef BCRELAY
	printf(" [-b] [--bcrelay if]       Use broadcast relay for broadcasts comming from.\n");
	printf("                           the specified interface (default is eth1).\n");
#endif
	printf(" [-c] [--conf file]        Specifies the config file to read default\n");
	printf("                           settings from (default is %s).\n", PPTPD_CONFIG_FILE_DEFAULT);
	printf(" [-d] [--debug]            Turns on debugging (to syslog).\n");
	printf(" [-e] [--ppp file]         Use alternate pppd binary, default %s.\n", PPP_BINARY);
	printf(" [-f] [--fg]               Run in foreground.\n");
	printf(" [-h] [--help]             Displays this help message.\n");
	printf(" [-i] [--noipparam]        Suppress the passing of the client's IP address\n");
	printf("                           to PPP, which is done by default otherwise.\n");
	printf(" [-l] [--listen x.x.x.x]   Specifies IP of local interface to listen to.\n");
#if !defined(BSDUSER_PPP)
	printf(" [-o] [--option file]      Specifies the PPP options file to use\n");
	printf("                           (default is /etc/ppp/options).\n");
#endif
	printf(" [-p] [--pidfile file]     Specifies the file to write the process ID to\n");
	printf("                           (default is /var/run/pptpd.pid).\n");
#if !defined(BSDUSER_PPP)
	printf(" [-s] [--speed baud]       Specifies the baud speed for the PPP daemon\n");
	printf("                           (default is 115200).\n");
#endif
	printf(" [-t] [--stimeout seconds] Specifies the timeout for the first packet. This is a DOS protection\n");
	printf("                           (default is 10).\n");
	printf(" [-v] [--version]          Displays the PoPToP version number.\n");
	printf(" [-w] [--logwtmp]          Update wtmp as users login.\n");

	printf("\n\nLogs and debugging go to syslog as DAEMON.");

	printf("\n\nCommand line options will override any default settings and any settings\n");
	printf("specified in the config file (default config file: %s).\n\n", PPTPD_CONFIG_FILE_DEFAULT);
}


static void showversion()
{
	printf("Poptop v%s\n", VERSION);
}

int main(int argc, char **argv)
{
	/* command line options */
	int c;

	/* function-local options */
	int foreground = FALSE;
	char *pid_file = NULL;

	/* config file */
	char *configFile = NULL;

	/* config file parsing temp strings */
	char tmp[MAX_CONFIG_STRING_SIZE], *tmpstr;

	/* open a connection to the syslog daemon */
	openlog("pptpd", LOG_PID, LOG_DAEMON);

	/* process command line options */
	while (1) {
		int option_index = 0;
#ifdef BCRELAY
		char *optstring = "b:c:de:fhil:o:p:s:t:vw";
#else
		char *optstring = "c:de:fhil:o:p:s:t:vw";
#endif

		static struct option long_options[] =
		{
#ifdef BCRELAY
			{"bcrelay", 1, 0, 0},
#endif
			{"conf", 1, 0, 0},
			{"debug", 0, 0, 0},
			{"ppp", 1, 0, 0},
			{"fg", 0, 0, 0},
			{"help", 0, 0, 0},
			{"noipparam", 0, 0, 0},
			{"listen", 1, 0, 0},
			{"option", 1, 0, 0},
			{"pidfile", 1, 0, 0},
			{"speed", 1, 0, 0},
			{"stimeout", 1, 0, 0},
			{"version", 0, 0, 0},
			{"logwtmp", 0, 0, 0},
			{0, 0, 0, 0}
		};

		c = getopt_long(argc, argv, optstring, long_options, &option_index);
		if (c == -1)
			break;
		/* convert long options to short form */
		if (c == 0)
#ifdef BCRELAY
			c = "bcdefhilopstvw"[option_index];
#else
			c = "cdefhilopstvw"[option_index];
#endif
		switch (c) {
#ifdef BCRELAY
		case 'b': /* --bcrelay */
			if (bcrelay) free(bcrelay);
			bcrelay = strdup(optarg);
			break;
#endif

		case 'l': /* --listen */
			tmpstr = lookup(optarg);
			if (!tmpstr) {
				syslog(LOG_ERR, "MGR: Invalid listening address: %s!", optarg);
				return 1;
			}
			if (bindaddr) free(bindaddr);
			bindaddr = strdup(tmpstr);
			break;

		case 'h': /* --help */
			showusage(argv[0]);
			return 0;

		case 'i': /* --noipparam */
			pptp_noipparam = TRUE;
			break;

		case 'e': /* --ppp */
			if (ppp_binary) free(ppp_binary);
			ppp_binary = strdup(optarg);
			break;

		case 'd': /* --debug */
			pptp_debug = TRUE;
			break;

		case 'f': /* --fg */
			foreground = TRUE;
			break;

		case 'v': /* --version */
			showversion();
			return 0;

		case 'w': /* --logwtmp */
		        pptp_logwtmp = TRUE;
			break;

		case 'o': /* --option */
			if (pppdoptstr) free(pppdoptstr);
			pppdoptstr = strdup(optarg);
			break;

		case 'p': /* --pidfile */
			if (pid_file) free(pid_file);
			pid_file = strdup(optarg);
			break;

		case 's': /* --speed */
			if (speedstr) free(speedstr);
			speedstr = strdup(optarg);
			break;

		case 't': /* --stimeout */
			pptp_stimeout = atoi(optarg);
			break;

		case 'c': /* --conf */
			{
				FILE *f;
				if (!(f = fopen(optarg, "r"))) {
					syslog(LOG_ERR, "MGR: Config file not found!");
					return 1;
				}
				fclose(f);
				if(configFile) free(configFile);
				configFile = strdup(optarg);
				break;
			}

		default:
			showusage(argv[0]);
			return 1;
		}
	}

	/* Now that we have all the command line args.. lets open the
	 * conf file and add anything else (remembering not to override
	 * anything since the command line has more privilages :-)
	 */

	if (!configFile)
		configFile = strdup(PPTPD_CONFIG_FILE_DEFAULT);

	if (!pptp_debug && read_config_file(configFile, DEBUG_KEYWORD, tmp) > 0)
		pptp_debug = TRUE;

#ifdef BCRELAY
	if (!bcrelay && read_config_file(configFile, BCRELAY_KEYWORD, tmp) > 0) 
		bcrelay = strdup(tmp);
#endif

	if (!pptp_stimeout && read_config_file(configFile, STIMEOUT_KEYWORD, tmp) > 0) {
		pptp_stimeout = atoi(tmp);
		if (pptp_stimeout <= 0)
			pptp_stimeout = STIMEOUT_DEFAULT;
	}

	if (!pptp_noipparam && read_config_file(configFile, NOIPPARAM_KEYWORD, tmp) > 0) {
		pptp_noipparam = TRUE;
	}

	if (!bindaddr && read_config_file(configFile, LISTEN_KEYWORD, tmp) > 0) {
		tmpstr = lookup(tmp);
		if(!tmpstr) {
			syslog(LOG_ERR, "MGR: Invalid listening address: %s!", tmp);
			return 1;
		}
		bindaddr = strdup(tmpstr);
	}

	if (!speedstr && read_config_file(configFile, SPEED_KEYWORD, tmp) > 0)
		speedstr = strdup(tmp);

	if (!pppdoptstr && read_config_file(configFile, PPPD_OPTION_KEYWORD, tmp) > 0) {
		pppdoptstr = strdup(tmp);
	}

	if (!ppp_binary && read_config_file(configFile, PPP_BINARY_KEYWORD, tmp) > 0) {
		ppp_binary = strdup(tmp);
	}

	if (!pptp_logwtmp && read_config_file(configFile, LOGWTMP_KEYWORD, tmp) > 0) {
		pptp_logwtmp = TRUE;
	}

	if (!pid_file)
		pid_file = strdup((read_config_file(configFile, PIDFILE_KEYWORD,
					tmp) > 0) ? tmp : PIDFILE_DEFAULT);

#if !defined(PPPD_IP_ALLOC)
	/* NOTE: remote then local, reason can be seen at the end of processIPStr */

	/* grab the remoteip string from the config file */
	if (read_config_file(configFile, REMOTEIP_KEYWORD, tmp) <= 0) {
		/* use "smart" defaults */
		strlcpy(tmp, DEFAULT_REMOTE_IP_LIST, sizeof(tmp));
	}
	processIPStr(REMOTE, tmp);

	/* grab the localip string from the config file */
	if (read_config_file(configFile, LOCALIP_KEYWORD, tmp) <= 0) {
		/* use "smart" defaults */
		strlcpy(tmp, DEFAULT_LOCAL_IP_LIST, sizeof(tmp));
	}
	processIPStr(LOCAL, tmp);
#endif

	free(configFile);

	/* if not yet set, adopt default PPP binary path */
	if (!ppp_binary) ppp_binary = strdup(PPP_BINARY);
	/* check that the PPP binary is executable */
	if (access(ppp_binary, X_OK) < 0) {
		syslog(LOG_ERR, "MGR: PPP binary %s not executable",
		       ppp_binary);
		return 1;
	}
	/* check that the PPP options file is readable */
	if (pppdoptstr && access(pppdoptstr, R_OK) < 0) {
		syslog(LOG_ERR, "MGR: PPP options file %s not readable",
		       pppdoptstr);
		return 1;
	}
#ifdef BCRELAY
	/* check that the bcrelay binary is executable */
	if (bcrelay && access(BCRELAY_BIN, X_OK) < 0) {
		syslog(LOG_ERR, "MGR: bcrelay binary %s not executable", 
		       BCRELAY_BIN);
		return 1;
	}
#endif

	if (!foreground) {
#if HAVE_DAEMON
		closelog();
		freopen("/dev/null", "r", stdin);
		daemon(0, 0);
		/* returns to child only */
		/* pid will have changed */
		openlog("pptpd", LOG_PID, LOG_DAEMON);
#else	/* !HAVE_DAEMON */
		my_daemon(argc, argv);
		/* returns to child if !HAVE_FORK
		 * never returns if HAVE_FORK (re-execs with -f)
		 */
#endif
	}

#ifdef BCRELAY
      if (bcrelay) {
             syslog(LOG_DEBUG, "CTRL: BCrelay incoming interface is %s", bcrelay);
             /* Launch BCrelay  */
#ifndef HAVE_FORK
             switch(bcrelayfork = vfork()){
#else
             switch(bcrelayfork = fork()){
#endif
             case -1:        /* fork() error */
                   syslog(LOG_ERR, "CTRL: Error forking to exec bcrelay");
                   _exit(1);

             case 0:         /* child */
                   syslog(LOG_DEBUG, "CTRL (BCrelay Launcher): Launching BCrelay with pid %i", bcrelayfork);
                   launch_bcrelay();
                   syslog(LOG_ERR, "CTRL (BCrelay Launcher): Failed to launch BCrelay.");
                   _exit(1);
             }
       } /* End bcrelay */
#endif

#ifdef CONFIG_NETtel
	/* turn the NETtel VPN LED on */
	ledman_cmd(LEDMAN_CMD_ON, LEDMAN_VPN);
#endif
	/* after we have our final pid... */
	log_pid(pid_file);

#ifdef BCRELAY
        /* be ready for a grisly death */
        signal(SIGTERM, &killbcrelay);
#endif

	pptp_manager(argc, argv);

        return 1;

}

#ifdef BCRELAY
static void killbcrelay(int sigraised) {
        if (sigraised) {
                syslog(LOG_DEBUG, "CTRL: Closing child BCrelay with pid %i", bcrelayfork);
                if (bcrelayfork > 0)
                kill(bcrelayfork, SIGQUIT);
		exit(0);
        }
}
#endif

static void log_pid(char *pid_file) {
        FILE    *f;
        pid_t   pid;

        pid = getpid();
        if ((f = fopen(pid_file, "w")) == NULL) {
                syslog(LOG_ERR, "PPTPD: failed to open(%s), errno=%d\n",
                        pid_file, errno);
                return;
        }
        fprintf(f, "%d\n", pid);
        fclose(f);
}

#ifndef HAVE_DAEMON
static void my_daemon(int argc, char **argv)
{
#ifndef HAVE_FORK
	/* need to use vfork - eg, uClinux */
	char **new_argv;
	int pid;
	extern char **environ;
	int fdr;

	new_argv = malloc((argc + 2) * sizeof(char **));
	fdr = open("/dev/null", O_RDONLY);
	syslog(LOG_INFO, "MGR: Option parse OK, re-execing as daemon");
	fflush(stderr);
	if ((pid = vfork()) == 0) {
		if (fdr != 0) { dup2(fdr, 0); close(fdr); }
		SETSIDPGRP();
		chdir("/");
		umask(0);
		memcpy(new_argv + 1, argv, (argc + 1) * sizeof(char **));
		new_argv[0] = PPTPD_BIN;
		new_argv[1] = "-f";
		execve(PPTPD_BIN, new_argv, environ);
		_exit(1);
	} else if (pid > 0) {
		exit(0);
	} else {
		syslog_perror("vfork");
		exit(1);
	}
#else
	int pid;

	closelog();
	if ((pid = fork()) < 0) {
		syslog_perror("fork");
		exit(1);
	} else if (pid)
		exit(0);
	freopen("/dev/null", "r", stdin);
	SETSIDPGRP();
	chdir("/");
	umask(0);
	/* pid will have changed */
	openlog("pptpd", LOG_PID, LOG_DAEMON);
#endif
}
#endif

/* added for hostname/address lookup    -tmk
 * returns NULL if not a valid hostname
 */
static char *lookup(char *hostname)
{
	struct hostent *ent;
	struct in_addr hst_addr;

	/* Try to parse IP directly */
	if (inet_addr(hostname) != -1)
		return hostname;

	/* Else lookup hostname, return NULL if it fails */
	if ((ent = gethostbyname(hostname)) == NULL)
		return NULL;

	/* That worked, print it back as a dotted quad. */
	memcpy(&hst_addr.s_addr, ent->h_addr, ent->h_length);
	return inet_ntoa(hst_addr);
}

#if !defined(PPPD_IP_ALLOC)

#define DEBUG_IP_PARSER 0

/* Return the address or NULL if not valid */
static char *validip(char *hostname)
{
	/* Try to parse IP directly */
	if (inet_addr(hostname) != -1)
		return hostname;
	else
		return NULL;
}

/* Check if it's a valid IP range */
static int isIpRange(char *str)
{
	int dashes = 0;
	int dots = 0;

#if DEBUG_IP_PARSER
	syslog(LOG_DEBUG, "MGR: Checking if %s is a valid IP range", str);
#endif
	do {
		if (*str == '-')
			dashes++;
		else if (*str == '.')
			dots++;
		else if (!strchr("0123456789", *str)) {
#if DEBUG_IP_PARSER
			syslog(LOG_DEBUG, "MGR: Not an IP range: character %c is not valid", *str);
#endif
			return 0;
		}
	} while (*++str);
#if DEBUG_IP_PARSER
	syslog(LOG_DEBUG, "MGR: Dashes = %d (wanted: 1), Dots = %d (wanted: 4)", dashes, dots);
#endif
	return (dashes == 1 && dots == 3);
}

/* process a type 0 (LOCAL) or type 1 (REMOTE) IP string */
static void processIPStr(int type, char *ipstr)
{
	int pos;

	char *tmpstr;
	/* char tmpstr2[20]; xxx.xxx.xxx.xxx-xxx (largest we can get) */
	char tmpstr2[128];	/* allow hostnames */
	char *tmpstr3;
	char tmpstr5[16];
	char *tmpstr6;
	char *tmpstr7;
	int num;

	char ipa[8];		/* xxx-xxx (largest we can get) */
	char ipb[8];
	char ipc[8];
	char ipd[8];

	char ip_pre[13];	/* xxx.xxx.xxx. (largest we can get) */
	char ip_post[13];

	char ipl[4];
	char ipu[4];

	int bail = FALSE;	/* so we know when to stop formatting the ip line */

	int lower, upper, n;

	num = 0;

	while (!bail) {
		if ((tmpstr = strchr(ipstr, ',')) == NULL) {
			/* last (or only) entry reached */
			strlcpy(tmpstr2, ipstr, sizeof(tmpstr2));
			bail = TRUE;
		} else {
			pos = tmpstr - ipstr;
			ipstr[pos] = '\0';
			strlcpy(tmpstr2, ipstr, sizeof(tmpstr2));
			ipstr = tmpstr + 1;
		}

#if DEBUG_IP_PARSER
		syslog(LOG_DEBUG, "MGR: Parsing segment: %s", tmpstr2);
#endif

		if (!isIpRange(tmpstr2)) {
			/* We got a normal IP
			 * Check if the IP address is valid, use it if so
			 */
			if ((tmpstr7 = lookup(tmpstr2)) == NULL) {
				syslog(LOG_ERR, "MGR: Bad IP address (%s) in config file!", tmpstr2);
				exit(1);
			}
			if (num == MAX_CONNECTIONS) {
				syslog(LOG_WARNING, "MGR: Max connections reached, extra IP addresses ignored");
				return;
			}
#if DEBUG_IP_PARSER
			syslog(LOG_DEBUG, "MGR: Setting IP %d = %s", num, tmpstr7);
#endif
			if (type == LOCAL)
				strlcpy(localIP[num], tmpstr7, 16);
			else
				strlcpy(remoteIP[num], tmpstr7, 16);
			num++;
		} else {
			/* Got a range;
			 * eg. 192.168.0.234-238
			 * or (thanx Kev! :-).. i thought i was finished :-)
			 * 192.168-178.1.231
			 */

			/* lose the "."'s */
			while ((tmpstr3 = strchr(tmpstr2, '.')) != NULL) {
				pos = tmpstr3 - tmpstr2;
				tmpstr2[pos] = ' ';
			}

			if ((tmpstr3 = strchr(tmpstr2, '-')) == NULL ||
			    strchr(tmpstr3 + 1, '-') != NULL) {
				syslog(LOG_ERR, "MGR: Confused in IP parse routines (multiple hyphens)");
				continue;
			}
			/* should be left with "192 168 0 234-238"
			 * or 192 168-178 1 231
			 */

			sscanf(tmpstr2, "%7s %7s %7s %7s", ipa, ipb, ipc, ipd);

			if ((tmpstr6 = strchr(ipd, '-')) != NULL) {
				pos = tmpstr6 - ipd;
				ipd[pos] = ' ';
				sscanf(ipd, "%3s %3s", ipl, ipu);
#if DEBUG_IP_PARSER
				syslog(LOG_DEBUG, "MGR: (lower upper) = (%s %s)", ipl, ipu);
#endif
				lower = atoi(ipl);
				upper = atoi(ipu);
#if DEBUG_IP_PARSER
				syslog(LOG_DEBUG, "MGR: Range = %d to %d on 4th segment", lower, upper);
#endif
				sprintf(ip_pre, "%.3s.%.3s.%.3s.", ipa, ipb, ipc);
				ip_post[0] = '\0';
#if DEBUG_IP_PARSER
				syslog(LOG_DEBUG, "MGR: Pre = %s Post = %s", ip_pre, ip_post);
#endif
			} else if ((tmpstr6 = strchr(ipc, '-')) != NULL) {
				pos = tmpstr6 - ipc;
				ipc[pos] = ' ';
				sscanf(ipc, "%3s %3s", ipl, ipu);
#if DEBUG_IP_PARSER
				syslog(LOG_DEBUG, "MGR: (lower upper) = (%s %s)", ipl, ipu);
#endif
				lower = atoi(ipl);
				upper = atoi(ipu);
#if DEBUG_IP_PARSER
				syslog(LOG_DEBUG, "MGR: Range = %d to %d on 3rd segment", lower, upper);
#endif
				sprintf(ip_pre, "%.3s.%.3s.", ipa, ipb);
				sprintf(ip_post, ".%.3s", ipd);
#if DEBUG_IP_PARSER
				syslog(LOG_DEBUG, "MGR: Pre = %s Post = %s", ip_pre, ip_post);
#endif
			} else if ((tmpstr6 = strchr(ipb, '-')) != NULL) {
				pos = tmpstr6 - ipb;
				ipb[pos] = ' ';
				sscanf(ipb, "%3s %3s", ipl, ipu);
#if DEBUG_IP_PARSER
				syslog(LOG_DEBUG, "MGR: (lower upper) = (%s %s)", ipl, ipu);
#endif
				lower = atoi(ipl);
				upper = atoi(ipu);
#if DEBUG_IP_PARSER
				syslog(LOG_DEBUG, "MGR: Range = %d to %d on 2nd segment", lower, upper);
#endif
				sprintf(ip_pre, "%.3s.", ipa);
				sprintf(ip_post, ".%.3s.%.3s", ipc, ipd);
#if DEBUG_IP_PARSER
				syslog(LOG_DEBUG, "MGR: Pre = %s Post = %s", ip_pre, ip_post);
#endif
			} else if ((tmpstr6 = strchr(ipa, '-')) != NULL) {
				pos = tmpstr6 - ipa;
				ipa[pos] = ' ';
				sscanf(ipa, "%3s %3s", ipl, ipu);
#if DEBUG_IP_PARSER
				syslog(LOG_DEBUG, "MGR: (lower upper) = (%s %s)", ipl, ipu);
#endif
				lower = atoi(ipl);
				upper = atoi(ipu);
#if DEBUG_IP_PARSER
				syslog(LOG_DEBUG, "MGR: Range = %d to %d on 1st segment", lower, upper);
#endif
				ip_pre[0] = '\0';
				sprintf(ip_post, ".%.3s.%.3s.%.3s", ipb, ipc, ipd);
#if DEBUG_IP_PARSER
				syslog(LOG_DEBUG, "MGR: Pre = %s Post = %s", ip_pre, ip_post);
#endif
			} else {
				syslog(LOG_ERR, "MGR: Confused in IP parse routines (lost hyphen)");
				continue;
			}

			for (n = lower; n <= upper; n++) {
				sprintf(tmpstr5, "%s%d%s", ip_pre, n, ip_post);
				/* Check if the ip address is valid */
				if ((tmpstr7 = validip(tmpstr5)) == NULL) {
					syslog(LOG_ERR, "MGR: Bad IP address (%s) in config file!", tmpstr5);
					exit(1);
				}
				if (num == MAX_CONNECTIONS) {
					syslog(LOG_WARNING, "MGR: Max connections reached, extra IP addresses ignored");
					return;
				}
#if DEBUG_IP_PARSER
				syslog(LOG_DEBUG, "MGR: Setting IP %d = %s", num, tmpstr7);
#endif
				if (type == LOCAL)
					strlcpy(localIP[num], tmpstr7, sizeof(localIP[num]));
				else
					strlcpy(remoteIP[num], tmpstr7, sizeof(remoteIP[num]));
				num++;
			}
		}
	}
	if (num == 1 && type == LOCAL && maxConnections > 1) {
#if DEBUG_IP_PARSER
		syslog(LOG_DEBUG, "MGR: Setting all %d local IPs to %s", maxConnections, localIP[0]);
#endif
		for (n = 1; n < maxConnections; n++)
			strcpy(localIP[n], localIP[0]);
	} else if (maxConnections > num)
		maxConnections = num;
}
#endif

#ifdef BCRELAY
/* launch_bcrelay
 * Launches broadcast relay. Broadcast relay is responsible for relaying broadcasts to the clients
 * retn: 0 on success, -1 on failure.
 */
static void launch_bcrelay() {
  char *bcrelay_argv[6];
  int an = 0;

      if (bcrelay) {
           syslog(LOG_DEBUG, "MGR: BCrelay incoming interface is %s", bcrelay);
           syslog(LOG_DEBUG, "MGR: BCrelay outgoing interface is regexp ppp[0-9].*");

	   bcrelay_argv[an++] = BCRELAY_BIN;
	   bcrelay_argv[an++] = "-i";
	   bcrelay_argv[an++] = bcrelay;
	   bcrelay_argv[an++] = "-o";
	   bcrelay_argv[an++] = "ppp[0-9].*";
           if (!pptp_debug) {
	         bcrelay_argv[an++] = "-n";
           }
	   bcrelay_argv[an++] = NULL;

           execvp(bcrelay_argv[0], bcrelay_argv);
      }
}
#endif
