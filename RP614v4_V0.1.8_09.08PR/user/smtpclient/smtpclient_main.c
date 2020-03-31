/*   ____  __  _ _____ ____     _ _            _   
**  / ___||  \/ |_   _|  _ \___| (_) ___ _ __ | |_ 
**  \___ \| |\/| || | | |_)/ __| | |/ _ \ '_ \| __|
**   ___) | |  | || | |  _| (__| | |  __/ | | | |_ 
**  |____/|_|  |_||_| |_|  \___|_|_|\___|_| |_|\__|
**   
**  SMTPclient -- simple SMTP client
**
**  This program is a minimal SMTP client that takes an email
**  message body and passes it on to a SMTP server (default is the
**  MTA on the local host). Since it is completely self-supporting,
**  it is especially suitable for use in restricted environments.
**
**  ======================================================================
**
**  Copyright (c) 1997 Ralf S. Engelschall, All rights reserved.
**
**  This program is free software; it may be redistributed and/or modified
**  only under the terms of either the Artistic License or the GNU General
**  Public License, which may be found in the SMTP source distribution.
**  Look at the file COPYING. 
**
**  This program is distributed in the hope that it will be useful, but
**  WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  ======================================================================
**
**  smtpclient_main.c -- program source
**
**  Based on smtp.c as of August 11, 1995 from
**      W.Z. Venema,
**      Eindhoven University of Technology,
**      Department of Mathematics and Computer Science,
**      Den Dolech 2, P.O. Box 513, 5600 MB Eindhoven, The Netherlands.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <syslog.h>
#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include <ctype.h>
#include <pwd.h>

#include <time.h> //add by Timo Wu
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

//#include "smtpclient_getopt.h"
#include "smtpclient_errno.h"
//#include "smtpclient_vers.h"
#include "hmac_md5.h"
#include "base64.h"

static char *cc_addr    = 0;
//static char *err_addr   = 0;
static char *from_addr  = NULL;
static char *mailhost   = NULL;
static int   mailport   = 25;
//static char *reply_addr = 0;
static char *subject    = 0;
static char *username   = 0;
static char *password   = 0;
//static int   mime_style = 0;
static int   verbose    = 0;
//static int   usesyslog  = 0;

static FILE *sfp;
static FILE *rfp;

// temp derivce configuration
#define SEND_LOG_FILE "/var/system.log"
int  temp_change_frome_mail = 1;
int  temp_smtp_auth_enable  = 1;
int temp_select_base64 = 1;

#if 0
char temp_to_addr[]    = "chenehi@ms16.hinet.net";
char temp_from_addr[]  = "chenehi@ms16.hinet.net";
char temp_mailhost[]   = "ms16.hinet.net";
char temp_subject[]    = "SMTP mode test";
char temp_username[]   = "chenehi";
char temp_password[]   = "2roixaui";
#endif

//char subject_in[]      = "subject_log";
char subject_log[50]     = "NETGEAR Security Log";
char subject_alert[50]   = "NETGEAR *Security Alert*"; 
/*******ERROR MESSAGE DEFINED HERE******/
#define MAIL_FILE_NOT_FOUND 	-3
#define FROM_MAIL_NOT_FOUND	-4
#define TO_MAIL_NOT_FOUND	-5
#define MAIL_HOST_NOT_FOUND	-6
#define CONNECT_TO_SERVER_ERROR	-7
#define AUTH_USERNAME_ERROR	-8
#define AUTH_PASSWORD_ERROR	-9
/*************END********/

#define dprintf  if (verbose) printf
#define dvprintf if (verbose) vprintf

static char base64chars[64] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
unsigned char get_greeting[BUFSIZ] = "";
unsigned char set_greeting[BUFSIZ] = "";
#define LOG_SHOW 0
//#define LOG_SHOW 1

/* hack for Ultrix */
#ifndef LOG_DAEMON
#define LOG_DAEMON 0
#endif

/*
**  logging support
*/
void log(char *str, ...)
{
#if(LOG_SHOW)
    va_list ap;
    char buf[1024];

    va_start(ap, str);
    vsprintf(buf, str, ap);
    fprintf(stderr, "SMTPclient: %s\n", buf);
    va_end(ap);
#endif
    return;
}

void base64encode(char *from, char *to, int len)
{
        char c1,c2,c3;
        int i;
        int lenDiv=len/3;
        int lenMod=len%3;

        for (i=0;i<lenDiv;i++)
        {
                c1=*from++;
                c2=*from++;
                c3=*from++;

                *to=base64chars[c1>>2];
                *to++=base64chars[c1>>2];
                *to++=base64chars[((c1<<4) | (c2 >> 4)) & 0x3f];
                *to++=base64chars[((c2<<2) | (c3 >> 6)) & 0x3f];
                *to++=base64chars[c3 & 0x3f];
        }
        if (lenMod == 1){
                c1=*from++;
                *to++=base64chars[(c1 & 0xfc) >> 2];
                *to++=base64chars[(c1 & 0x03) << 4];
                *to++='=';
                *to++='=';
        }
        if (lenMod == 2){
                c1=*from++;
                c2=*from++;
                *to++=base64chars[(c1 &0xfc) >>2];
                *to++=base64chars[((c1 &0x03) <<4) | ((c2 &0xf0) >>4)];
                *to++=base64chars[((c2 &0x0f) <<2)];
                *to++='=';
        }
        *to++='\0';

}

/*
**  examine message from server 
*/
void get_response(void)
{
    char buf[BUFSIZ];

    while (fgets(buf, sizeof(buf), rfp)) {
        buf[strlen(buf)-1] = 0;
        dprintf("%s --> %s\n", mailhost, buf);
	//printf("buf[0]=[%c],buf[1]=[%c],buf[2]=[%c]\n",buf[0],buf[1],buf[2]);
        if (!isdigit(buf[0]) || buf[0] > '3') {
            log("unexpected reply: %s", buf);
            unlink("/var/run/smtpclient.pid");
            exit(1);
        }
        if (buf[4] != '-')
            break;
    }
    return;
}

int get_response_auth(int auth_type)
{
    char buf[BUFSIZ];
                                                                                                 
    while (fgets(buf, sizeof(buf), rfp)) {
        buf[strlen(buf)-1] = 0;
        log("get_response_auth: %s --> %s\n", mailhost, buf);
        sprintf(get_greeting,"%s",buf+4);
        dprintf("%s --> %s\n", mailhost, buf);
	//printf("buf[0]=[%c],buf[1]=[%c],buf[2]=[%c]\n",buf[0],buf[1],buf[2]);
        if (!isdigit(buf[0])) {
            unlink("/var/run/smtpclient.pid");
            exit(1);
        }
	if (buf[0] == '3' && buf[1] == '3' && buf[2] == '4')
	{
		return 1;
	}
        if (buf[4] != '-')
            break;
    }
    return 0;
}

/*
**  say something to server and check the response
*/
void chat(char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    vfprintf(sfp, fmt, ap);
    va_end(ap);
  
    va_start(ap, fmt);
    dprintf("%s <-- ", mailhost);
    dvprintf(fmt, ap);
    va_end(ap);

    fflush(sfp);
    get_response();
}

void chat_auth(char *fmt, ...)
{
    va_list ap;
                                                                                                 
    va_start(ap, fmt);
    vfprintf(sfp, fmt, ap);
    va_end(ap);
                                                                                                 
    va_start(ap, fmt);
    dprintf("%s <-- ", mailhost);
    dvprintf(fmt, ap);
    va_end(ap);
                                                                                                 
    fflush(sfp);
}

void md5_main(unsigned char *username, unsigned char *password, unsigned char *greeting) {
  unsigned char *challenge;
  unsigned char digest[16];
  unsigned char digasc[33];
  int i;
  static char hextab[] = "0123456789abcdef";
  unsigned char *decoded;
  unsigned char *encoded;

  log("username: %s\n", username);
  log("password: %s\n", password);
  log("greeting: %s\n", greeting);

  challenge = b64decode_alloc(greeting);
  b64decode(greeting, challenge);

  log("challenge: %s\n", challenge);

  hmac_md5(challenge, strlen(challenge), password, strlen(password), digest);

  digasc[32] = 0;
  for (i = 0; i < 16; i++) {
    digasc[2*i] = hextab[digest[i] >> 4];
    digasc[2*i+1] = hextab[digest[i] & 0xf];
  }

  log("digest: %s\n", digasc);

  decoded = (unsigned char *) malloc(strlen(username)+strlen(digasc)+2);

  strcpy(decoded, username);
  decoded[strlen(username)] = ' ';
  strcpy(decoded+strlen(username)+1, digasc);
  decoded[strlen(username)+strlen(digasc)+1] = 0;

  log("base64 decoded: %s\n", decoded);

  encoded = b64encode_alloc(decoded);
  b64encode(decoded, encoded);

  log("base64 encoded: %s\n", encoded);
  sprintf(set_greeting, "%s", encoded);
}

static void timeout(int sig_no)
{
	unlink("/var/run/smtpclient.pid");
	exit(1);
}

int main(int argc, char **argv)
{
    char buf[BUFSIZ];
    char temp_buf[50];
    char my_name[BUFSIZ]="RP614v4";
    char encodeusername[128];
    char encodepassword[128];
    struct sockaddr_in sin;
    struct hostent *hp;
    //struct servent *sp;
    //int c;
    int s;
    int r;
    //int i;
    int usernamelen,passwordlen;
    struct passwd *pwd;
    char *cp;
    
    int  smtp_auth_enable = 0; 
    int select_base64;
    char *mail_file="";
    char *alert_trigger="";
    char mac_addr[20];
    //char *tmp_addr;
    static char mac[20]; 
     
    FILE *fp;
    int fd;
    //struct stat stat_buf;   
    
    /* 
     *  Go away when something gets stuck.
     */
//    alarm(60);

    /*
     *  Check pid first :timo
     */
     fp = fopen("/var/run/smtpclient.pid", "r");
     if (fp != NULL)
     {
     	log("smtpclient.pid is NULL\n");
     	exit(1);
     }
     /****   create pid file first by Timo Wu*****/
     {
  	FILE *f;
	pid_t pid;
	char *pidfile = "/var/run/smtpclient.pid";

	pid = getpid();
	if((f = fopen(pidfile, "w")) == NULL)
		exit(1);
	fprintf(f, "%d\n", pid);
	printf("smtpclient.pid %d\n", pid);
	fclose(f);	
     }
     
  /*
      * set smtp configuration
      */
  {
     /* argv[0] = smtpclient, argv[1] = subject, argv[2] = mail_file */
     cc_addr    = nvram_get("tomail");
     mailhost   = nvram_get("mailserver");
     subject    = argv[1];		/* argv[1] -> subject */
     mail_file  = argv[2];
     alert_trigger  = argv[3];
     
     memset(mac,0,20);
     strcpy(mac,nvram_get("wan0_hwaddr"));
     sprintf(mac_addr,"[%s]", mac+9);
     if(strcmp(subject, "subject_log")==0)
     {
     	//printf("subject_log\n");
     	strcat(subject_log, mac_addr);
     	//printf("subject_log %s\n",subject_log);
     	subject = subject_log;
     	//printf("subject %s\n", subject);
     }
     else
     {
     	//printf("subject_alert\n");
     	strcat(subject_alert, mac_addr);
     	//printf("subject_alert %s\n",subject_alert);
     	subject = subject_alert;
     	//printf("subject %s\n",subject);
     }		
     if (!mail_file)
     {
     	log("mail_file = %s\n\n", SEND_LOG_FILE);
     	mail_file = SEND_LOG_FILE;
     }
     
     fp = fopen(mail_file,"r");    
        			    
		
     if (fp == NULL)
     {
    	log("mail_file is not exist\n\n");
        exit(1); //exit this process
        //fprintf(fp, "..\r\n");
     }
     fclose(fp);
    
     log("mail_file = %s\n\n",mail_file);
     
     //from_addr  = nvram_get("frommail");
     from_addr = nvram_get("tomail");
     smtp_auth_enable = atoi(nvram_get("email_serverauth"));
     //smtp_auth_enable = 0; //disable for test
     username   = nvram_get("email_authname");
     password   = nvram_get("email_authpasswd");
     select_base64 = temp_select_base64;    
  }	  


    /*
     *  Determine SMTP server
     */
    if (mailhost == NULL) {
        if ((cp = getenv("SMTPSERVER")) != NULL) {
            mailhost = cp;
	}
        else {
            mailhost = "localhost";
	}
    }

    /*
     *  Find out my own host name for HELO; 
     *  if possible, get the FQDN.
     */
/*
    if (gethostname(my_name, sizeof(my_name) - 1) < 0) {
        //log("gethostname: %s", errorstr(errno));
        exit(1);
    }
    
    if ((hp = gethostbyname(my_name)) == NULL) {
        log("%s: unknown host-my_name\n", my_name);
        exit(1);
    }
    strcpy(my_name, hp->h_name);
*/
    /*
     *  Determine from address.
     */
    if (from_addr == NULL) {
        if ((pwd = getpwuid(getuid())) == 0) {
            sprintf(buf, "userid-%d@%s", getuid(), my_name);
        } else {
            sprintf(buf, "%s@%s", pwd->pw_name, my_name);
        }
	log("buf=%s\n",buf);
        from_addr = strdup(buf);
    }
    log("from_addr=%s\n\n",from_addr);

    /*
     *  Connect to smtp daemon on mailhost.
     */
    if ((hp = gethostbyname(mailhost)) == NULL) {
        log("%s: unknown host-mailhost\n", mailhost);
        unlink("/var/run/smtpclient.pid");
        exit(1);
    }
    log("mailhost=%s, hp->h_addrtype=%d\n\n",mailhost,hp->h_addrtype);

    if (hp->h_addrtype != AF_INET) {
        log("unknown address family: %d", hp->h_addrtype);
        unlink("/var/run/smtpclient.pid");
        exit(1);
    }
    memset((char *)&sin, 0, sizeof(sin));
    memcpy((char *)&sin.sin_addr, hp->h_addr, hp->h_length);
    sin.sin_family = hp->h_addrtype;
    sin.sin_port = htons(mailport);
    //fprintf(stderr,"sin_addr=%s, sin_family=%d, sin_port=%d\n\n",sin.sin_addr,sin.sin_family,sin.sin_port);
    
    if ((s = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        log("socket: %s", errorstr(errno));
        unlink("/var/run/smtpclient.pid");
        exit(1);
    }
    
    signal(SIGALRM, timeout);
    alarm(15);

    if (connect(s, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
        log("connect: %s", errorstr(errno));
        unlink("/var/run/smtpclient.pid");
        alarm(0);
        exit(1);
    }
    
    alarm(0); //close signal function
     
    if ((r = dup(s)) < 0) {
        log("dup: %s", errorstr(errno));
        unlink("/var/run/smtpclient.pid");
        exit(1);
    }
    if ((sfp = fdopen(s, "w")) == 0) {
        log("fdopen: %s", errorstr(errno));
        unlink("/var/run/smtpclient.pid");
        exit(1);
    }
    if ((rfp = fdopen(r, "r")) == 0) {
        log("fdopen: %s", errorstr(errno));
        unlink("/var/run/smtpclient.pid");
        exit(1);
    }

    /*
   	 usernamelen=strlen(username);
   	 passwordlen=strlen(password);	
    	 base64encode(username,encodeusername,usernamelen);
    	 base64encode(password,encodepassword,passwordlen);
    */
    /* 
     *  Give out SMTP headers.
     */
    get_response(); /* banner */
    log("send HELO\n");
    chat("HELO %s\r\n", my_name);

   
    if (smtp_auth_enable) {
        log("send AUTH LOGIN\n");
        //if (select_base64) {
            chat_auth("AUTH LOGIN\r\n");
            if (get_response_auth(0)) {
  	            usernamelen=strlen(username);
                passwordlen=strlen(password);
	            log("username(%d)=%s, password(%d)=%s\n",usernamelen,username,passwordlen,password);
                base64encode(username,encodeusername,usernamelen);
                base64encode(password,encodepassword,passwordlen);
	            chat("%s\r\n",encodeusername);
                chat("%s\r\n",encodepassword);
  	    }
       //}
       else {
            chat_auth("AUTH CRAM-MD5\r\n");
            if (get_response_auth(1)) {
            	log("get_greeting(%d)=%s\n",strlen(get_greeting),get_greeting);
            	md5_main(username, password,get_greeting);
            }            
	    chat("%s\r\n",set_greeting);
       }
    }
    log("send MAIL : %s\n",from_addr);
    chat("MAIL FROM: <%s>\r\n", from_addr);

    log("send RCPT : %s\n",from_addr);
/*
    for (i = optind; i < argc; i++)
        chat("RCPT TO: <%s>\r\n", argv[i]);
    if (cc_addr)
        chat("RCPT TO: <%s>\r\n", cc_addr);
*/
    chat("RCPT TO: <%s>\r\n", from_addr);
	    
    log("send DATA :\n");
    chat("DATA\r\n");

    /* 
     *  Give out Message header. 
     */
    log( "From: %s\n\n", from_addr);

    fprintf(sfp, "From: %s\r\n", from_addr);
    
    if (subject){
    //if (temp_subject){
        fprintf(sfp,"Subject: %s\r\n", subject);
        //fprintf(sfp,"Subject: %s\r\n", temp_subject);    
    	log("Subject: %s\r\n", subject);
    }

    fprintf(sfp, "Reply-To: %s\r\n", from_addr);

    log("Reply-To: %s\r\n", from_addr);
    
    sprintf(temp_buf,"Reply-To: %s\r\n", from_addr);

    if ((pwd = getpwuid(getuid())) == 0) {
        fprintf(sfp, "Sender: userid-%d@%s\r\n", getuid(), my_name);
    } else {
        fprintf(sfp, "Sender: %s@%s\r\n", pwd->pw_name, my_name);
    }

    //fprintf(sfp, "To: %s", argv[optind]);
    fprintf(sfp, "To: %s\r\n", cc_addr);    

    log("To: %s\r\n", cc_addr);	
    
    /*  Set tast data.....*/
    fprintf(sfp,"MIME-Version: 1.0\r\n");    
    fprintf(sfp,"Content-Type: text/plain; charset=us-ascii\r\n");
    fprintf(sfp, "\r\n");

    if( strcmp(mail_file , "/var/url.log")==0) //mail_file is /var/url.log
    {
    	
    	log("mail_file is var/url.log\n");
    	
    	fd=open(mail_file, O_RDONLY);
    	if(fd < 0)
    	{
		log("mail_file is not exist\n\n");
		unlink("/var/run/smtpclient.pid");
		exit(1);
    	}
    
   	flock(fd, LOCK_EX);	
        
        char temp_buffer[BUFSIZ-300];
        
    	read(fd , temp_buffer, sizeof(temp_buffer));    	
    	//printf("temp_buffer is %s\n", temp_buffer);    
    	
    	  
    	if( strcmp( temp_buffer ,"") != 0)
    	{
    		printf("smtpclient %s is not empty\n", mail_file);
    		
    	        temp_buffer[strlen(temp_buffer)-1] = 0;
                if (strcmp(buf, ".") == 0)  // quote alone dots
		    fprintf(sfp, "..\r\n");    
                else // pass thru mode 
		    fprintf(sfp, "%s\r\n", temp_buffer);   
		
		log("end: file_buf(%d)=%s\n",strlen(temp_buffer),temp_buffer);
		    
    		flock(fd, LOCK_UN);
    		//fstat(fd ,&stat_buf);
    		close(fd);

    	}	
    	else
    	{
    		printf("smtpclient %s is empty\n", mail_file);
    		flock(fd, LOCK_UN);
    		//fstat(fd ,&stat_buf);
    		close(fd);
    		
    		unlink("/var/run/smtpclient.pid");
    		exit(1);
    	}
    	
    }
    else
    {
      fp = fopen(mail_file,"r");    
      
      if (fp == NULL)
      {
    		log("mail_file is not exist\n\n");
        	fprintf(fp, "..\r\n");
      }
      else
      {
        char file_buf[BUFSIZ-300];
	
	while (fgets(file_buf, sizeof(file_buf), fp)) {
	    file_buf[strlen(file_buf)-1] = 0;
            if (strcmp(buf, ".") == 0)  // quote alone dots
		    fprintf(sfp, "..\r\n");    
             else { // pass thru mode 
		    fprintf(sfp, "%s\r\n", file_buf);              
	    }
	    log("end: file_buf(%d)=%s\n",strlen(file_buf),file_buf);
	}
        fclose(fp);
      }
    }	    
      fprintf(sfp, "\r\n");

    /* 
     *  Give out Message body.
     */
    //log("give out message body...mime_style=%d, BUFSIZ=%d\n",mime_style,BUFSIZ);
    fflush(sfp);
    
    chat(".\r\n");

    /* 
     *  Give out SMTP end.
     */
/*     
    log("send data end\n");
    chat(".\r\n");
*/
    log("send QUIT\n");
    chat("QUIT\r\n");

    //Add by Timo Wu
    /****** Clear the system.log*****/
        //log("%s", alert_trigger);
	if(strcmp(alert_trigger,"alert_trigger"))
	{
	   	timer_t timep;
	   	struct tm *tm;
	   	char *wday[]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
		char *wmonth[]={"Jan", "Feb","Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
		
	   	time(&timep);
	   	tm=gmtime(&timep);
	   	
		if(!(fp = fopen("/var/system.log", "w"))) {
			unlink("/var/run/smtpclient.pid");
			exit(1);
		}
	
		fprintf(fp, "%s, %02d %s %04d %02d:%02d:%02d [Log Cleared]\n",wday[tm->tm_wday], tm->tm_mday, wmonth[tm->tm_mon], (1900+tm->tm_year), tm->tm_hour, tm->tm_min, tm->tm_sec);

		fclose(fp);  		
	}
    	
    //rm pid file
    unlink("/var/run/smtpclient.pid");
    printf("smtpclient send success\n");
    /********end add*****/  
    /* 
     *  Die gracefully ...
     */
    exit(0);
}

/*EOF*/
