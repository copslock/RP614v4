/*
**    BPALogin - lightweight portable BIDS2 login client
**    Copyright (c) 2001-3 Shane Hyde, and others.
** 
**  This program is free software; you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation; either version 2 of the License, or
**  (at your option) any later version.
** 
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
** 
**  You should have received a copy of the GNU General Public License
**  along with this program; if not, write to the Free Software
**  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
**
*/ 

/**
 * Changes:
 * 2001-09-19:  wdrose    Fixed incorrect use of single fork() to put
 *                        BPALogin into background.  Replaced with
 *                        fork(), setsid(), fork().
 *
 * 2001-12-05:  wdrose    Added fix gleaned from Sam Johnston to include
 *                        errno.h for errno, rather than assuming it is an
 *                        extern int.
 */
#include "bpalogin.h"

#define BPALOGIN_BANNER \
        "BPALogin v2.0.2 - portable BigPond Broadband login client"

struct session s;
int debug_level = DEFAULT_DEBUG;
int dosyslog = 1;

//added by dvd.chen
//unsigned char bpaGatewayIP[32];
extern int g_need_listen;
extern int g_pkt_wanna_go_out;

int parse_parms(struct session *,char * conffile);
void usage( void );
void debug(int l,char *s,...);

void onconnected(int i)
{
    if(strcmp(s.connectedprog,""))
    {
        char buf[500];
		
		sprintf(buf,"%.500s %s %d", s.connectedprog, 
				inet_ntoa(s.authhost.sin_addr), s.listenport);

        debug(0,"Executing external command - %s\n",buf);
        system(buf);
    }
}

void ondisconnected(int reason)
{
    if(strcmp(s.disconnectedprog,""))
    {
        char buf[500];
        sprintf(buf,"%.500s %s %d %d",s.disconnectedprog, 
			inet_ntoa(s.authhost.sin_addr), s.listenport, reason);

        debug(0,"Executing external command - %s\n",buf);
        system(buf);
    }
}

void critical(char *s)
{
	// Modified by wayne.lu on 9/14/2004
	/*
    if(dosyslog)
    syslog(LOG_CRIT,"Critical error: %s\n",s);
    else
    printf("Critical error: %s\n",s);
    */
 	if(dosyslog)
 	{
		//log to syslog and stdout both
    		syslog(LOG_CRIT,"Critical error: %s\n",s);
		printf("Critical error: %s\n",s);	
 	}
	else
	{
    		printf("Critical error: %s\n",s);
	}
	
    //exit(1);
}

void debug(int l,char *s,...)
{
    va_list ap;
    va_start(ap,s);
    if(debug_level > l)
    {
        int pri;
        char buf[256];

        switch(l)
        {
        case 0:
            pri = LOG_INFO;
            break;
        case 1:
            pri = LOG_INFO;
            break;
        case 2:
        case 3:
        default:
            pri = LOG_INFO;
            break;
        }
        vsprintf(buf,s,ap);
	// Modified by wayne.lu on 9/14/2004
	/*
        if(dosyslog)
        syslog(pri,"%s",buf);
        else
        printf("%s",buf);
        */
	// End of modification		
		if(dosyslog)
		{
			sleep(0);
			syslog(pri,"%s",buf);
			printf("%s",buf);
		}
	       else
	    {
		   	printf("%s",buf);
		}
    }
    va_end(ap);
}

void noncritical(char *s,...)
{
    char buf[256];

    va_list ap;
    va_start(ap,s);
    vsprintf(buf,s,ap);
	// Modified by wayne.lu on 9/14/2004
	/*
    if(dosyslog)
    syslog(LOG_CRIT,buf);
    else
    printf(buf);
    */
    if(dosyslog)
	{
    	syslog(LOG_CRIT,buf);
		printf(buf);
	}
    else
    {
    	printf(buf);
	}
    va_end(ap);
}

//#include "shutils.h"
#include <dni_shutils.h>
#include <re865x.h>
void onsignal(int i)
{
	char	sig[5];
	int is_idle_timeouted;
	int ret;

	//added by dvd.chen on 01/16/2006, for bpa dial_on_demand
	if( i == SIGUSR1 )  //dial_on_demand signal
	{
		g_pkt_wanna_go_out = 1;
		return;
	}
	//end of dvd.chen
	
	//debug(1,"%s:: Signal caught: %d\n", __FUNCTION__, i);
	//added by dvd.chen on 01/11/2006, for bpa idle_timeout
    	if( (s.idle_interval > 0) && (i == SIGALRM) )
    	{
    		//check if idle timeout, if TRUE ==> fall through to logout
    		ret = re865xIoctl("eth0", GET_PPPD_IDLE_TIME, 0, &is_idle_timeouted, 0);
		debug(1,"%s:: Sig[%d], ret[%d]\n", __FUNCTION__, i, ret);
   		if ( !is_idle_timeouted )
   		{
   			alarm(BPA_CHK_IDLE_PERIOD);
			return;
   		}
		else  // fall through to logout
		{
			debug(1,"bpa idle timeouted fall through to logout\n");
		}
    	}
	//end of dvd.chen
    logout(0,&s);
	
    s.ondisconnected(0);  //call hb_disconnect_main to delete link.ppp0 file, and iptable:5050 entry
    
    g_need_listen=1;  //dvd.chen, logout button pressed OR handle_heartbeats faild(socket closed), turn on listen flag
    sprintf(sig, "-%d", SIGUSR1);
    eval("killall",sig,"CheckWan");  //signal CheckWan task that now is listening lan interface

    //closelog();
	
    //exit(1);  //don't exit , by dvd.chen
    signal(i, onsignal);
}

int main(int argc,char* argv[])
{
    int makedaemon = 1;
    char conffile[256];

    int c;
    FILE *pid_fp;

    signal(SIGINT,onsignal);
    signal(SIGHUP,onsignal);
    signal(SIGTERM,onsignal);
    //signal(SIGUSR1,onsignal);
//added by dvd.chen on 01/11/2006, for bpa idle_timeout
    signal(SIGALRM, onsignal);
//end of dvd.chen
//added by dvd.chen on 01/16/2006, for dial_on_demand
    signal(SIGUSR1, onsignal);
//end of dvd.chen

    //s.user_input_authserver = 0;  //added by dvd.chen for netgear GUI
    strcpy(s.authserver,DEFAULT_AUTHSERVER);
    strcpy(s.authdomain,DEFAULT_AUTHDOMAIN);
    s.authport = DEFAULT_AUTHPORT;
    strcpy(s.username,"");
    strcpy(s.password,"");
    strcpy(s.connectedprog,"");
    strcpy(s.disconnectedprog,"");
    //strcpy(conffile,DEFAULT_CONFFILE);  //dvd.chen, we specify in conf file
    strcpy(s.localaddress,"");
    s.localport = 0;
    s.minheartbeat = 60;
    s.maxheartbeat = 420;

    while( (c = getopt( argc, argv, "c:d:l:D" )) > -1 ) {
        switch( c ) {
        case 'c':
            strncpy( conffile, optarg, MAXCONFFILE);
            break;
        case '?':
            usage();
            exit(1);
            break;
        }
    }

    if(!parse_parms(&s,conffile)) {
        printf( "bpalogin: Could not read configuration file (%s)\n\n",
                conffile );
        usage();
        exit(1);
    }

    optind = 1;
    while( (c = getopt( argc, argv, "c:d:l:Dt" )) > -1 ) {
        switch( c ) {
        case 'D':
            makedaemon = 0;
            break;
        case 'c':
            break;
        case 'd':
            debug_level = atoi(optarg);
            break;
	case 'l':
	    if( strcasecmp( optarg, "stdout" ) == 0 )
	      	dosyslog = 0;
	    else
		dosyslog = 1;
	    break;
        case '?':
            break;
        case ':':
            break;
        }
    }
//cprintf("Unixmain::dosyslog=%d\n",dosyslog);
    if(makedaemon) {
      /**
       * Original code did not perform the setsid() or second fork(), and
       * hence did not correctly make itself a daemon.  There is a library
       * call in FreeBSD (daemon) that does the actions below, but the
       * portability is unknown.
       */
      switch( fork() ) {
        case 0:
          break;
          
        case -1:
          perror("Could not run BPALogin in the background");
          exit(1);
          break;
          
        default:
          exit(0);
          break;
      }

      if( setsid() < 0 ) {
        perror("Could not run BPALogin in the background");
        exit(1);
      }

      /**
       * while not strictly necessary, the second fork ensures we stay
       * detached from a terminal by preventing the program using its
       * status as session leader to regain a terminal.
       */
      switch( fork() ) {
        case 0:
          break;

        case -1:
          perror("Could not run BPALogin in the background");
          exit(1);
          break;

        default:
          exit(0);
          break;
      }
    }

    //added by dvd.chen on 08/11/2004, write pid in file, in case of using in the future
    //printf("bpa_pid:%d\n", getpid());
    if (!(pid_fp = fopen("/var/run/bpalogin.pid", "w"))) {
	perror("/var/run/bpalogin.pid");
		return errno;
    }
    fprintf(pid_fp, "%d\n", getpid());
    fclose(pid_fp);
    //end of dvd.chen

    //openlog("bpalogin",LOG_PID,LOG_DAEMON);

    if(dosyslog)    
        syslog( LOG_INFO, BPALOGIN_BANNER "\n" );
    else
        printf( BPALOGIN_BANNER "\n");

    if(!strcmp(s.username,""))
    {
        critical("Username has not been set");
        exit(1);
    }
    if(!strcmp(s.password,""))
    {
        critical("Password has not been set");
        exit(1);
    }
    s.debug = debug;
    s.critical = critical;
    s.noncritical = noncritical;
    s.onconnected = onconnected;
    s.ondisconnected = ondisconnected;
printf("unixmain :: calling mainloop\n");
    while(mainloop(&s));
    s.ondisconnected(0);

    exit(0);
}

int parse_parms(struct session *s,char * conffile)
{
    char buf[512];
    FILE * f;
    int user_input_authserver = 0;

    f = fopen(conffile,"rt");
    if(!f)
    {
        debug(0,"Cannot open conf file\n");
        return FALSE;
    }

    while(fgets(buf,400,f) != NULL)
    {
        char parm[100];
        char value[100];

        if(buf[0] == '#')
            continue;

        /**
         * Problem with using sscanf(buf, "%s %s"), parm, value):
         * usernames with periods et al are not picked up correctly.
         * Really need to use strtok.
         */
        sscanf(buf,"%s %s",parm,value);    
        debug(2,"Parameter %s set to %s\n",parm,value);

        if(!strcasecmp(parm,"username"))
        {
            strcpy(s->username,value);
        }
        else if(!strcasecmp(parm,"password"))
        {
            strcpy(s->password,value);
        }
//added by dvd.chen for bpa idle_timeout
	else if(!strcasecmp(parm,"idle_interval"))
	{
		s->idle_interval = atoi(value) * 60;
	}
//end of dvd.chen
        else if(!strcasecmp(parm,"authdomain"))
        {
            strcpy(s->authdomain,".");
            strcat(s->authdomain,value);	
        }
        else if(!strcasecmp(parm,"authserver"))
        {
            strcpy(s->authserver,value);
	     //added by dvd.chen for netgear GUI, if user input server URL or ip ==> don't attach authdomain
    	     //if user didn't input ==> use default authserver cancat authdomain
	     user_input_authserver = 1;
        }
        else if(!strcasecmp(parm,"localaddress"))
        {
            strcpy(s->localaddress,value);
        }
        else if(!strcasecmp(parm,"logging"))
        {
            if(!strcasecmp("stdout",value) ||
               !strcasecmp("sysout",value)) dosyslog = 0; // for compatibility
            if(!strcasecmp("syslog",value)) dosyslog = 1;
        }
        else if(!strcasecmp(parm,"debuglevel"))
        {
            debug_level = atoi(value);
        }
        else if(!strcasecmp(parm,"minheartbeatinterval"))
        {
            s->minheartbeat = atoi(value);   
        }
        else if(!strcasecmp(parm,"maxheartbeatinterval"))
        {
            s->maxheartbeat = atoi(value);   
        }
        else if(!strcasecmp(parm,"localport"))
        {
            s->localport = atoi(value);
        }
        else if(!strcasecmp(parm,"connectedprog"))
        {
            strcpy(s->connectedprog,value);
        }
        else if(!strcasecmp(parm,"disconnectedprog"))
        {
            strcpy(s->disconnectedprog,value);
        }
    }
    
    fclose(f);
    //marked of by dvd.chen on 09/22/2004, we use ipaddr as authserver
    //strcat(s->authserver,s->authdomain);
    //added by dvd.chen for netgear GUI,
    //if user didn't input authserver ==> s->authserver == DEFAULT_AUTHSERVER
    //and s->authdomain is got from dhcpc wan domain
    //otherwise(user had input authserver)  ==> just use s->authserver parsed from config file
    if( !user_input_authserver )
    {
    	if( strlen(s->authdomain) == 0 )
		debug(0,"parse_param:: ERROR!! no authdomain to be concatenated with authserver\n");
	strcat(s->authserver,s->authdomain);
    }
    //end of dvd.chen
    printf("s->authserver = %s\n", s->authserver);
	
    return TRUE;
}

void usage( void )
{
    printf( BPALOGIN_BANNER "\n");
    printf("Copyright (c) 2001-3 Shane Hyde and others\n\n");
    printf("This program is *not* a product of Big Pond Advance\n\n");
    printf("Usage: bpalogin [-c file] [-d level] [-l style] [-D]\n\n");
    printf(" -c file            Specifies the configuration file to use\n");
    printf("                    (default is %s)\n\n", DEFAULT_CONFFILE);
    printf(" -d level           Set the verbosity of log messages\n");
    printf("                    (0 is quiet, 2 is most verbose)\n\n");
    printf(" -l style           Use syslog or stdout for messages\n\n" );
    printf(" -D                 Dont run bpalogin as a daemon (run in "
           "foreground)\n\n");
    printf("Command line options override the values in the configuration "
           "file\n");
}

int closesocket(int s)
{
    return close(s);
}

void socketerror(struct session *s, const char * str)
{
    char buf[200];
    sprintf(buf,"%.100s - %.80s",str,strerror(errno));
    s->noncritical(buf);
}
