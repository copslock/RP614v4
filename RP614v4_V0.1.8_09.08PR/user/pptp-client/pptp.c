/* pptp.c ... client shell to launch call managers, data handlers, and
 *            the pppd from the command line.
 *            C. Scott Ananian <cananian@alumni.princeton.edu>
 *
 * $Id: pptp.c,v 1.11 2004/10/28 11:09:31 chenyl Exp $
 */

#if 1
#include <board.h>
#include <sys/shm.h>
#endif

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <setjmp.h>
#include <errno.h>
#include <sys/wait.h>
#include <fcntl.h>
#ifdef EMBED
#include <syslog.h>
#endif
#include "pptp_callmgr.h"
#include "pptp_msg.h"
#include "pptp_gre.h"
#include "version.h"
#include "inststr.h"
#include "pty.h"

#include <sys/shm.h>
#ifdef USERAPP_NOMMU
#include <board.h>
#endif
#ifdef EMBED
#define	pptp_error(a...) syslog(LOG_INFO, ##a)
#else
#define	pptp_error(a...) ({ fprintf(stderr, ##a); fprintf(stderr, "\n"); })
#endif

#ifdef PPTPDEBUG
//#define pptp_debug(a...) pptp_error(##a)
#define pptp_debug(a...) printf(##a)
#else
#define pptp_debug(a...)
#endif

#ifdef USERAPP_NOMMU
static unsigned char waitForDial=0;
#endif

/*
 * because we can be run from init,  it seems unwise to just
 * exit quickly for errors that probably won't have resolved
 * themselves immediately,  wait a bit on exit just to slow
 * it all down a little
 */
#define RESPAWN_DELAY	10

#ifndef PPPD_BINARY
#define PPPD_BINARY "/bin/pppd"
#endif

struct in_addr get_ip_address(char *name);
int open_callmgr(struct in_addr inetaddr, int argc,char **argv,char **envp);
void launch_callmgr(struct in_addr inetaddr, int argc,char **argv,char **envp);
int get_call_id(int sock, pid_t gre,
		 u_int16_t *call_id, u_int16_t *peer_call_id);
void launch_pppd(char *ttydev, int argc, char **argv);

void usage(char *progname) {
  fprintf(stderr,
	  "%s\n"
	 "Usage:\n"
	 " %s hostname[,hostname[,...]] [pppd options]\n", version, progname);
#ifdef USERAPP_NOMMU	
	unlink("/var/run/pptp.pid");
#endif  
  exit(1);
}

#ifdef USERAPP_NOMMU
void pptpDial(int sig) { 
printf("pptp - get dial signal!\n"); 
	waitForDial=0;	
}
#endif


static int signaled = 0;

void do_nothing(int sig) { 
    /* do nothing signal handler. Better than SIG_IGN. */
    pptp_debug("pptp - do_nothing signal\n");
    signaled = 1;
}

void do_alarm(int sig) {
	/* the SIGALRM handler: sent by pptp_conn_destroy and means connections are destroyed */
}

int got_signal;
sigjmp_buf env;
void sighandler(int sig) {
  pptp_debug("pptp - sighandler\n");
  got_signal = sig;
  siglongjmp(env, 1);
}

void sigchild (int src)
{
    pid_t pid;
    int status;
    pid = waitpid (-1, &status, WNOHANG);
}


#ifdef USERAPP_NOMMU
void kill_child(int sig) {
  pptp_debug("kill-child\n");
  //printf("pptp --- child dead\n");
  waitpid(-1,NULL,NULL);
  
}
#endif

#define TOTAL_REDIAL_CNT 30
//#define REDIAL_DELAY	10
#define REDIAL_DELAY	2

int main(int argc, char **argv, char **envp) {
  struct in_addr inetaddr;
  char orgArgv[128];
  int orgArgc;
  int callmgr_sock = -1;
  char ptydev[PTYMAX], ttydev[TTYMAX];
  int pty_fd = -1;
  static volatile pid_t child_pid;
  u_int16_t call_id, peer_call_id;
  FILE *f;
  int autoRedial;
  int redialCnt;

	/* set initial variables */

	/* check if pptpd need auto redial or not */
	autoRedial = 0;
	f = fopen("/var/run/pptp_redial", "r");
	if (f)
	{
		fscanf(f, "%d", &autoRedial);
		fclose(f);
	}

	/* set redial count */
  	redialCnt = autoRedial?TOTAL_REDIAL_CNT:0;

	{	/* we store the original argc and argv */
		int i, cnt;
		int argMaxSize = sizeof(orgArgv) - 1;
		char *p1, *p2;
		
		orgArgc = argc;
		cnt = 0;
		p1 = orgArgv;
		for (i = 0 ; i < argc ; i ++)
		{
			if (cnt >= argMaxSize)
				break;
			p2 = argv[i];
			while (*p2 != '\0')
			{
				*p1 = *p2;
				p1 ++;
				p2 ++;
				cnt ++;
				if (cnt >= argMaxSize)
					break;
			}
			if (cnt >= argMaxSize)
				break;
			*p1 = ' ';
			p1 ++;
			cnt ++;			
		}
		*p1 = '\0';
	}

	signal(SIGCHLD, sigchild);
	
pptpStart:

	pty_fd = -1;
	callmgr_sock = -1;
	memset(&inetaddr, 0, sizeof(struct in_addr));
	memset(ptydev, 0, sizeof(ptydev));
	memset(ptydev, 0, sizeof(ttydev));
	child_pid = 0;
	call_id = 0;
	peer_call_id = 0;
	f = NULL;

  
#ifdef USERAPP_NOMMU
  romeCfgParam_t *rcp;
#if 0  
  unsigned long ptr;
  f=fopen("/var/romecfg.txt","r");
  fscanf(f,"%x",&rcp);  
  fclose(f);
#else
  int shmid=0;
  shmid=shmget(SHM_PROMECFGPARAM,sizeof(romeCfgParam_t),0666|IPC_CREAT);
  rcp=shmat(shmid,(void*)0,0);
#endif
#endif  //end ifdef USERAPP_NOMMU
#ifdef EMBED
  openlog(argv[0],LOG_PID,LOG_USER);
#endif

  if (argc < 2)
    usage(argv[0]);

	f=fopen("/var/run/pptp.pid","w");
	fprintf(f,"%d",getpid());
	fclose(f);  

  /* Step 1: Get IP address for the hostname in argv[1] */
  for (;;) {
    inetaddr = get_ip_address(argv[1]);
    if(inetaddr.s_addr != 0)
      break;
#if 1      
	goto shutdown;
#else
    sleep(RESPAWN_DELAY);
#endif
  }


#ifdef USERAPP_NOMMU
	  /* Step 3: Find an open pty/tty pair. */  

	  pty_fd = getpseudotty(ttydev, ptydev);
	  if (pty_fd < 0) {    
		pptp_error("Could not find free pty.");
		sleep(RESPAWN_DELAY);
	    exit(1);
	  }
	//  printf("pptp - using %s\n",ttydev);
	//pptp_debug("got a free ttydev\n");
 
	signal(SIGUSR2, pptpDial);
	waitForDial=0;
restartPptp:
	rcp->pptpCfgParam.dialState=PPTPCFGPARAM_DIALSTATE_OFF;
	fprintf(stderr,"pptp - waiting dial!\n"); 
	while(waitForDial==1)
	{
		sleep(1);
	}
	fprintf(stderr,"pptp - connecting!\n"); 
	init_global_gre();:
#endif 

  for (;;) {
    /* Step 2: Open connection to call manager
	 *         (Launch call manager if necessary.)
	 */
	callmgr_sock = open_callmgr(inetaddr, argc,argv,envp);
	if(callmgr_sock < 0){
	  pptp_error("Could not open connection to call manager - terminating");
	  sleep(RESPAWN_DELAY);
	  exit(1);
	}	
        pptp_debug("callmgr opened - fd = %x\n", callmgr_sock);	

	/* Step 5: Exchange PIDs, get call ID */
	if (get_call_id(callmgr_sock, getpid(), &call_id, &peer_call_id) >= 0)
		break;

	close(callmgr_sock);
  }

#ifdef USERAPP_NOMMU
#else
  /* Step 3: Find an open pty/tty pair. */
  pty_fd = getpseudotty(ttydev, ptydev);
  if (pty_fd < 0) {
    close(callmgr_sock);
	pptp_error("Could not find free pty.");
	sleep(RESPAWN_DELAY);
	exit(1);
  }
  pptp_debug("got a free ttydev");
#endif  

  /* Step 4: fork and wait. */
  signal(SIGUSR1, do_nothing); /* don't die */
  switch (child_pid = vfork()) {
  case -1:
    signal(SIGUSR1, SIG_DFL);
    pptp_debug("vfork failed %s\n", strerror(errno));
	sleep(RESPAWN_DELAY);
#ifdef USERAPP_NOMMU
	unlink("/var/run/pptp.pid");
	exit(1);
#else
	goto shutdown;
#endif
  case 0: /* I'm the child! */

#ifdef USERAPP_NOMMU
#else
    //signal(SIGUSR1, SIG_DFL); //disable 04/07/08 merge
#endif
	pptp_debug("entered child");
	close(callmgr_sock);
    launch_pppd(ttydev, argc-2, argv+2); /* launch pppd */
	sleep(RESPAWN_DELAY);
    exit(1); /* in case launch_pppd returns */
    break;
  default: /* parent */
    /*
     * There is still a very small race condition here.  If a signal
     * occurs after signaled is checked but before pause is called,
     * things will hang.
     */
#if 0
	if (!signaled) {
	  pause(); /* wait for the signal */
    }
    pptp_error("Error %s", strerror(errno));
#endif /*0*/
    break;
  }

#if 0
  /* Step 5b: Send signal to wake up pppd task */
  kill(parent_pid, SIGUSR1);
  sleep(2);
#endif /*0*/

  if (sigsetjmp(env, 1)!=0)
  {
	/* clear redialCnt */
	if (got_signal != SIGTERM)
  		redialCnt = 0;
  	goto shutdown;
  }
  signal(SIGINT,  sighandler);
  signal(SIGTERM, sighandler);
  signal(SIGKILL, sighandler);
#ifdef USERAPP_NOMMU
  signal(SIGCHLD, kill_child);
#endif
  {
	char buf[128];

	bzero(buf, sizeof(buf));
	snprintf(buf, sizeof(buf), "pptp: GRE-to-PPP gateway on %s", ptydev);
	inststr(argc,argv,envp, buf);
  }

  /* setup OK: Refill redialCnt */
  redialCnt = autoRedial?TOTAL_REDIAL_CNT:0;

  /* Step 6: Do GRE copy until close. */
  pptp_gre_copy(peer_call_id, call_id, pty_fd, inetaddr);

  {	/* restore original arg */
  	inststr(argc, argv, envp, orgArgv);
  }

shutdown:
  /* Make sure pppd exits as well */
  if (child_pid > 0)
    kill(child_pid, SIGTERM);
#ifdef USERAPP_NOMMU  
#else
  if (pty_fd != -1)
    close(pty_fd);
#endif  
  if (callmgr_sock != -1)
    close(callmgr_sock);  
  if (redialCnt == 0)
	  fprintf(stderr,"pptp - hang up!\n"); 

#if 1
{
   	int shmid=0;
   	romeCfgParam_t * pRomeCfgParam;
	shmid=shmget(SHM_PROMECFGPARAM,sizeof(romeCfgParam_t),0666|IPC_CREAT);
	pRomeCfgParam=shmat(shmid,(void*)0,0);
	pRomeCfgParam->pptpCfgParam.dialState=PPTPCFGPARAM_DIALSTATE_OFF;
	shmdt(pRomeCfgParam);
}
#endif

  
#ifdef USERAPP_NOMMU  
	  callmgr_sock=-1;
	  waitForDial=1;
	  goto restartPptp;
#else

	//if (redialCnt > 0)
	if (0)
	{
		redialCnt --;
		sleep(REDIAL_DELAY);
		goto pptpStart;
	}

#if 1
	printf("pptp got_signal = %d\n", got_signal);
	if (got_signal == SIGHUP || got_signal == SIGKILL)
		goto exit_pptp;
	sleep(REDIAL_DELAY);
	goto pptpStart;
#endif	
	
exit_pptp:
	/* remove PID file */
	unlink( "/var/run/pptp.pid" );

	exit(1); /* in case launch_pppd returns */
#endif
}

/*
 * search through a possible list of ',' seperated ip addresses, try
 * each one,  if it works then use that one
 */
struct in_addr get_ip_address(char *name) {
  struct in_addr retval;
  struct sockaddr_in dest;
  int s;
  char *cp, *np;

  retval.s_addr = 0;
  for (cp = name; cp && *cp; cp = np) {

    if (np = strchr(cp, ','))
    	*np++ = '\0';
    pptp_error("Trying host %s ...", cp);
    if (inet_aton(cp, &retval) == 0) {
      struct hostent *host = gethostbyname(cp);
      if (host==NULL) {
	    if (h_errno == HOST_NOT_FOUND)
	      pptp_error("gethostbyname: HOST NOT FOUND");
	    else if (h_errno == NO_ADDRESS)
	      pptp_error("gethostbyname: NO IP ADDRESS");
	    else
	      pptp_error("gethostbyname: name server error");
	    continue;
      }
      if (host->h_addrtype != AF_INET) {
	    pptp_error("Host has non-internet address");
	    continue;
	  }
      memcpy(&retval.s_addr, host->h_addr, sizeof(retval.s_addr));
    }

    if (np)
    	*(np - 1) = ','; /* put string back how we found it */

    bzero(&dest, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_port   = htons(PPTP_PORT);
    dest.sin_addr   = retval;
    pptp_debug("socket\n");
    if ((s = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
      pptp_error("Cannot get socket: %s", strerror(errno));
      continue;
    }
    pptp_debug("Connect\n");
    signal(SIGALRM, do_alarm);
    alarm(15);
    if (connect(s, (struct sockaddr *) &dest, sizeof(dest)) != -1) {
      alarm(0);
      pptp_error("Connect succeeded");
      close(s);
      return(retval);
    }
    alarm(0);
	close(s);
    pptp_error("Connect failed: %s",strerror(errno));
  }
  retval.s_addr = 0;
  return retval;
}

int open_callmgr(struct in_addr inetaddr, int argc, char **argv, char **envp) {
  /* Try to open unix domain socket to call manager. */
  struct sockaddr_un where;
  const int NUM_TRIES = 3;
  int i, fd;

  /* Open socket */
  if ((fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
    pptp_error("Could not create unix domain socket: %s", strerror(errno));
    return(-1);
  }

  /* Make sure the socket is closed if callmgr is launched */
  fcntl(fd, F_SETFD, FD_CLOEXEC);

  /* Make address */
  where.sun_family = AF_UNIX;
  snprintf(where.sun_path, sizeof(where.sun_path), 
	   PPTP_SOCKET_PREFIX "%s", inet_ntoa(inetaddr));

  for (i=0; i<NUM_TRIES; i++) {
    if (connect(fd, (struct sockaddr *) &where, sizeof(where)) < 0) {
      /* couldn't connect.  We'll have to launch this guy. */
      launch_callmgr(inetaddr, argc,argv,envp);
      sleep(3);
    }
    else return fd;
  }
  close(fd);
  pptp_error("Could not launch call manager after %d tries.", i);
  return -1;   /* make gcc happy */
}

void launch_callmgr(struct in_addr inetaddr, int argc,char**argv,char**envp) {
  pid_t pid;
  int status;
  const char *callmgr = PPTP_CALLMGR_BINARY;

  /* fork and launch call manager process */
  switch (pid=vfork()) {
  case -1: /* baaad */
	pptp_error("callmgr vfork failed: %s", strerror(errno));
    break;
  case 0: /* child */
    {
#if 0
      int callmgr_main(int argc, char**argv, char**envp);
      char *my_argv[2] = { argv[0], inet_ntoa(inetaddr) };
      char buf[128];
      snprintf(buf, sizeof(buf), "pptp: call manager for %s", my_argv[1]);
      inststr(argc,argv,envp,buf);
      exit(callmgr_main(2, my_argv, envp));
#endif
      execlp(callmgr, callmgr, inet_ntoa(inetaddr), NULL);
      pptp_error("execlp() of call manager [%s] failed: %s", 
	      callmgr, strerror(errno));
      exit(1); /* or we trash our parents stack */
    }
  default: /* parent */
#if 0 /* we don't care about status */
    waitpid(pid, &status, 0);
    if (status!=0)
      pptp_error("Call manager exited with error %d", status);
#endif
    break;
  }
}

/* XXX need better error checking XXX */
int get_call_id(int sock, pid_t gre,
		 u_int16_t *call_id, u_int16_t *peer_call_id) {
  u_int16_t m_call_id, m_peer_call_id;
  /* write pid's to socket */
  /* don't bother with network byte order, because pid's are meaningless
   * outside the local host.
   */
  int rc;
  rc = write(sock, (char *)&gre, sizeof(gre));
  if (rc != sizeof(gre))
	  return -1;
  pptp_debug("wrote socket information, waiting for read...\n");
  rc = read(sock,  (char *)&m_call_id, sizeof(m_call_id));
  if (rc != sizeof(m_call_id))
	  return -1;
  rc = read(sock,  (char *)&m_peer_call_id, sizeof(m_peer_call_id));
  if (rc != sizeof(m_peer_call_id))
	  return -1;
  pptp_debug("Read socket information: call_id=%d, peer_call_id=%d\n",
		  m_call_id, m_peer_call_id);
  /* XXX FIX ME ... DO ERROR CHECKING & TIME-OUTS XXX */
  *call_id = m_call_id;
  *peer_call_id = m_peer_call_id;

  return 0;
}

void launch_pppd(char *ttydev, int argc, char **argv) {
  char *new_argv[argc+4]; /* XXX if not using GCC, hard code a limit here. */
  int i;
  FILE *f;

#ifdef USERAPP_NOMMU
  f=fopen("/var/run/pppd.tty","w");
  fprintf(f,"%s",ttydev);
  fclose(f);

  f=fopen("/var/run/pppd0.pid","r");
    	printf("pptp - launch_pppd!\n");
  if(f==NULL)
  {
  	char temp[64];
   	new_argv[0] = PPPD_BINARY;
	new_argv[1] = ttydev;
	new_argv[2] = "38400";	

	for (i=0; i<argc; i++)
	  new_argv[i+3] = argv[i];
	new_argv[i+3] = NULL;
	execvp(new_argv[0], new_argv);

	
  }
  else
  {
  	int pid;
  	fscanf(f,"%d",&pid);
  	kill(pid,16);  
  	fclose(f);
  }
#else
  new_argv[0] = PPPD_BINARY;
  new_argv[1] = ttydev;
  new_argv[2] = "38400";

  for (i=0; i<argc; i++)
    new_argv[i+3] = argv[i];
  new_argv[i+3] = NULL;
  execvp(new_argv[0], new_argv);
#endif
}

#if 0
/*************** COMPILE call manager into same binary *********/
#define main       callmgr_main
#define sighandler callmgr_sighandler
#define do_nothing callmgr_do_nothing
#include "pptp_callmgr.c"
#endif