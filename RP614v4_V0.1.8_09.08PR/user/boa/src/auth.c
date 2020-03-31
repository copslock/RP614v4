/*
 *  Boa, an http server
 *  Copyright (C) 1995 Paul Phillips <psp@well.com>
 *  Authorization "module" (c) 1998,99 Martin Hinner <martin@tdp.cz>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 1, or (at your option)
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

extern char *mgmtUserName(void);
extern char *mgmtPassword(void);

#include <stdio.h>
#include <fcntl.h>
#ifdef __UC_LIBC__
#include <unistd.h>
#else
#include <crypt.h>
#endif
#include "syslog.h"
#include "md5.h"
#include "boa.h"
#ifdef SHADOW_AUTH
#include <shadow.h>
#endif
#ifdef OLD_CONFIG_PASSWORDS
#include <crypt_old.h>
#endif
#ifdef EMBED
#include <sys/types.h>
#include <pwd.h>
#include <config/autoconf.h>
#endif

#ifdef SECURITY_COUNTS
#include "../../login/logcnt.c"
#endif

#ifdef USE_AUTH

struct _auth_dir_ {
	char *directory;
	FILE *authfile;
	int dir_len;
	struct _auth_dir_ *next;
};

typedef struct _auth_dir_ auth_dir;

static auth_dir *auth_hashtable [AUTH_HASHTABLE_SIZE];
#ifdef OLD_CONFIG_PASSWORDS
char auth_old_password[16];
#endif

/*
 * Name: get_auth_hash_value
 *
 * Description: adds the ASCII values of the file letters
 * and mods by the hashtable size to get the hash value
 */
inline int get_auth_hash_value(char *dir)
{
#ifdef EMBED
	return 0;
#else
	unsigned int hash = 0;
	unsigned int index = 0;
	unsigned char c;

	hash = dir[index++];
	while ((c = dir[index++]) && c != '/')
		hash += (unsigned int) c;

	return hash % AUTH_HASHTABLE_SIZE;
#endif
}

/*
 * Name: auth_add
 *
 * Description: adds 
 */
void auth_add(char *directory,char *file)
{
	auth_dir *new_a,*old;
	
	old = auth_hashtable [get_auth_hash_value(directory)];
	while (old)
	{
		if (!strcmp(directory,old->directory))
			return;
		old = old->next;
	}
	
	new_a = (auth_dir *)malloc(sizeof(auth_dir));
	/* success of this call will be checked later... */
	new_a->authfile = fopen(file,"rt");
	new_a->directory = strdup(directory);
	new_a->dir_len = strlen(directory);
	new_a->next = auth_hashtable [get_auth_hash_value(directory)];
	auth_hashtable [get_auth_hash_value(directory)] = new_a;
}

void auth_check()
{
	int hash;
	auth_dir *cur;
	
	for (hash=0;hash<AUTH_HASHTABLE_SIZE;hash++)
	{
  	cur = auth_hashtable [hash];
	  while (cur)
		{
			if (!cur->authfile)
			{
				log_error_time();
				fprintf(stderr,"Authentication password file for %s not found!\n",
						cur->directory);
			}
			cur = cur->next;
		}
	}
}

#ifdef LDAP_HACK
#include <lber.h>
#include <ldap.h>
#include <sg_configdd.h>
#include <sg_confighelper.h>
#include <sg_users.h>

/* Return a positive, negative or not possible result to the LDAP auth for
 * the specified user.
 */
static int ldap_auth(const char *const user, const char *const pswd) {
	static time_t last;
	static char *prev_user;
	LDAP *ld;
	int ldap_ver, r;
	char f[256];
	ConfigHandleType *c = config_load(amazon_ldap_config_dd);

	/* Don't repeat query too often if the user name hasn't changed */
	if (last && prev_user &&
			time(NULL) < (last + config_get_int(c, AMAZON_LDAP_CACHET)) &&
			strcmp(prev_user, user) == 0) {
		config_free(c);
		last = time(NULL);
		return 1;
	}
	if (prev_user != NULL)   { free(prev_user);	prev_user = NULL;   }
	last = 0;

	if ((ld = ldap_init(config_get_string(c, AMAZON_LDAP_HOST),
			config_get_int(c, AMAZON_LDAP_PORT))) == NULL) {
		syslog(LOG_ERR, "unable to initialise LDAP");
		config_free(c);
		return 0;
	}
	if (ldap_set_option(ld, LDAP_OPT_REFERRALS, LDAP_OPT_OFF) != LDAP_SUCCESS) {
		syslog(LOG_ERR, "unable to set LDAP referrals off");
		config_free(c);
		ldap_unbind(ld);
		return 0;
	}
	ldap_ver = config_get_int(c, AMAZON_LDAP_VERSION);
	if (ldap_ver > 0 && ldap_set_option(ld, LDAP_OPT_PROTOCOL_VERSION, &ldap_ver) != LDAP_SUCCESS) {
		syslog(LOG_ERR, "unable to set LDAP version %d", ldap_ver);
		config_free(c);
		ldap_unbind(ld);
		return 0;
	}
	snprintf(f, sizeof f, config_get_string(c, AMAZON_LDAP_BIND_DN), user);
	r = ldap_simple_bind_s(ld, f, pswd);
	if (r != LDAP_SUCCESS) {
		syslog(LOG_ERR, "unable to connect to LDAP (%s)", ldap_err2string(r));
		config_free(c);
		ldap_unbind(ld);
		return (r==LDAP_INVALID_CREDENTIALS)?-1:0;
	}
	config_free(c);
	ldap_unbind(ld);
	/* Caching timing details for next time through */
	prev_user = strdup(user);
	last = time(NULL);
	return 1;
}
static unsigned char ldap_succ;
#endif


/*
 * Name: auth_check_userpass
 *
 * Description: Checks user's password. Returns 0 when sucessful and password
 * 	is ok, else returns nonzero; As one-way function is used RSA's MD5 w/
 *  BASE64 encoding.
#ifdef EMBED
 * On embedded environments we use crypt(), instead of MD5.
#endif
 */
int auth_check_userpass(char *user,char *pass,FILE *authfile)
{

#ifdef LDAP_HACK
	/* Yeah, code before declarations will fail on older compilers... */
	switch (ldap_auth(user, pass)) {
	case -1:	ldap_succ = 0;				return 1;
	case 0:		ldap_succ = strcmp(user, "root")?0:1;	break;
	case 1:
		ldap_succ = 1;
		if (start_user_update(0) == 0)
			done_user_update(set_user_password(user, pass, 0)==0?1:0);
		return 0;
	}
#endif
#ifdef SHADOW_AUTH
	struct spwd *sp;

	sp = getspnam(user);
	if (!sp)
		return 2;

	if (!strcmp(crypt(pass, sp->sp_pwdp), sp->sp_pwdp))
		return 0;

#else

//#ifndef EMBED
#if 1

#if 0
	char temps[0x100],*pwd;
	struct MD5Context mc;
 	unsigned char final[16];
	char encoded_passwd[0x40];
  /* Encode password ('pass') using one-way function and then use base64
		 encoding. */
		 
//printf("pass=%s\n",pass);
		 
	MD5Init(&mc);
	{
//	char *pass="admin";
	MD5Update(&mc, pass, strlen(pass));
	}
	MD5Final(final, &mc);
	strcpy(encoded_passwd,"$1$");
	base64encode(final, encoded_passwd+3, 16);

	DBG(printf("auth_check_userpass(%s,%s,...);\n",user,pass);)

	fseek(authfile,0,SEEK_SET);
	while (fgets(temps,0x100,authfile))
	{
		if (temps[strlen(temps)-1]=='\n')
			temps[strlen(temps)-1] = 0;
		pwd = strchr(temps,':');
		if (pwd)
		{
			*pwd++=0;
			if (!strcmp(temps,user))
			{
//printf("pwd=%s ,encoded_passwd=%s\n",pwd,encoded_passwd);
				if (!strcmp(pwd,encoded_passwd))
					return 0;
			} else
				return 2;
		}
	}
#else
//printf("user=%s, pass=%s name=%s pass2=%s\n",user,pass,mgmtUserName(),mgmtPassword());
	if((strcmp(mgmtUserName(),user)==0)&&(strcmp(mgmtPassword(),pass)==0)) return 0;
	else if ((strcmp(mgmtUserName(),user)==0)) return 1;
	else return 2;
#endif

#else
	struct passwd *pwp;

	pwp = getpwnam(user);
	if (pwp != NULL) {
		if (strcmp(crypt(pass, pwp->pw_passwd), pwp->pw_passwd) == 0)
			return 0;
	} else 
#ifdef OLD_CONFIG_PASSWORDS
	/* For backwards compatibility we allow the global root password to work too */
	if ((auth_old_password[0] != '\0') && 
			((*user == '\0') || (strcmp(user, "root") == 0))) {
		if (strcmp(crypt_old(pass,auth_old_password),auth_old_password) == 0 ||
				strcmp(crypt(pass,auth_old_password),auth_old_password) == 0) {
			strcpy(user, "root");
			return 0;
		}
	} else
#endif	/* OLD_CONFIG_PASSWORDS */
		return 2;

#endif	/* ! EMBED */
#endif	/* SHADOW_AUTH */
	return 1;
}

int g_bLogin = 0;
int g_bBlankStateLogin = 0;

client_req_t client_req = {0};

int clr_http_client(void)
{
	g_bLogin = 0;
	g_bBlankStateLogin = 0;
	memset((char *)&client_req, 0x0, sizeof(client_req_t));	
	
}

int copy_httpc_info_to_client(char *ptr)
{
	
	memcpy((char *)&client_req, ptr, sizeof(client_req_t));	
}


#define HTTP_LOGIN_TIMEOUT	(5 * 60)	/* 5 minutes */

int httpd_check_auth(char *peerIP)
{
	if(   g_bLogin &&
		((GetSysUpTime() - client_req.lastaccess_time) > HTTP_LOGIN_TIMEOUT) ) {
				g_bLogin = 0;
				memset((char *)&client_req, 0x0, sizeof(client_req));
	}			
	
	if( g_bLogin )
	{
		if (strcmp(client_req.client_ip, peerIP) == 0)
		{
			client_req.lastaccess_time=GetSysUpTime();
			return 1;			
		}
		else
			return 0;	
	}
	else
		return 0;
}	

int BlankState_httpd_check_auth(request* req)
{
//	printf("%s:Request IP is %s, path name is %s, and login flag is %d\n",
//			__FUNCTION__,
//			req->remote_ip_addr,
//			req->pathname,
//			g_bBlankStateLogin);
	if(req== NULL) { 
		if(g_bBlankStateLogin) { clr_http_client(); }
		return 0;
	}

	if(g_bBlankStateLogin) {
		if((GetSysUpTime() - client_req.lastaccess_time) > HTTP_LOGIN_TIMEOUT) {
				char path[64] = "/www/CA_Welcome.html";

				g_bBlankStateLogin = 1;
				memset((char *)&client_req, 0x0, 20);
				memcpy((char *)&client_req.client_ip, req->remote_ip_addr, sizeof(req->remote_ip_addr));	
				send_r_request_ok(req);	
				do_ej(path, req);					
				client_req.lastaccess_time=GetSysUpTime();
				return 0;
		} else if (strcmp(client_req.client_ip, req->remote_ip_addr) == 0) {
			client_req.lastaccess_time=GetSysUpTime();
			return 1;			
		}
	} else {
		g_bBlankStateLogin=1;
		memset((char *)&client_req, 0x0, 20);
		memcpy((char *)&client_req.client_ip, req->remote_ip_addr, sizeof(req->remote_ip_addr));	
		client_req.lastaccess_time=GetSysUpTime();
		return 1;
	}

	{
		char path[64] = "/www/serverbusy.html";

		send_r_request_ok(req);	
		do_ej(path, req);					
	}	

	return 0;

}	



int auth_authorize(request * req)
{
        int hash;
	char *pwd;
	char auth_userpass[0x80];

  	DBG(printf("auth_authorize\n");)


	//if (httpd_check_auth(req->remote_ip_addr) == 0) {
	if (1) {
		  if (g_bLogin == 1) {
		    if (httpd_check_auth(req->remote_ip_addr) == 0) {	
		    	if (g_bLogin == 0) {	  	
				client_req.authed_send = 1;				
				strncpy(client_req.client_ip, req->remote_ip_addr, sizeof(client_req.client_ip));
				send_r_unauthorized(req,server_name);
				return 0;  	
  			}
  			else {
				char path[64] = "/www/serverbusy.html";
			
				send_r_request_ok(req);	
				do_ej(path, req);					
				return 0;
			}	
		    }	
		  }
		  //else {
		  {
			int denied = 1;
		
			if ((client_req.authed_send == 0) || (client_req.client_ip[0] == '\0')) {
				memset(client_req.client_ip, 0x0, 20);
				strncpy(client_req.client_ip, req->remote_ip_addr, sizeof(client_req.client_ip));
				client_req.authed_send = 1;				
				send_r_unauthorized(req,server_name);
				return 0;			
			}					
			//if (client_req.authed_send == 0 || strcmp(client_req.client_ip, req->remote_ip_addr) ) {
			if ((req->authorization == NULL) || strcmp(client_req.client_ip, req->remote_ip_addr) ) {			
				memset(client_req.client_ip, 0x0, 20);
				strncpy(client_req.client_ip, req->remote_ip_addr, sizeof(client_req.client_ip));
				client_req.authed_send = 1;				
				send_r_unauthorized(req,server_name);
				return 0;				
			}			
			
			if (strncasecmp(req->authorization,"Basic ",6))
			{
				syslog(LOG_ERR, "Can only handle Basic auth\n");
				send_r_bad_request(req);
				return 0;
			}
			
			base64decode(auth_userpass,req->authorization+6,sizeof(auth_userpass));
				
			if ( (pwd = strchr(auth_userpass,':')) == 0 )
			{
				syslog(LOG_ERR, "No user:pass in Basic auth\n");
				send_r_bad_request(req);
				return 0;
			}
				
			*pwd++=0;

			denied = auth_check_userpass(auth_userpass,pwd, NULL);
#ifdef SECURITY_COUNTS
			if (strncmp(get_mime_type(req->request_uri),"image/",6))
				access__attempted(denied, auth_userpass);
#endif
			if (denied) {
				switch (denied) {
					case 1:
						syslog(LOG_ERR, "Authentication attempt failed for %s from %s because: Bad Password\n",
								auth_userpass, req->remote_ip_addr);
#if defined(DNI)								
						log_message("Authentication attempt failed for %s from %s because: Bad Password",
								auth_userpass, req->remote_ip_addr);
#endif								
						break;								
					case 2:
						syslog(LOG_ERR, "Authentication attempt failed for %s from %s because: Invalid Username\n",
								auth_userpass, req->remote_ip_addr);
#if defined(DNI)								
						log_message("Authentication attempt failed for %s from %s because: Invalid Username",
								auth_userpass, req->remote_ip_addr);								
#endif								
				}
				send_r_unauthorized(req,server_name);
				client_req.authed_send = 1;				
				return 0;
			}
			//if (strcmp(client_req.client_ip, req->remote_ip_addr) != 0) {
			
				if ((g_bLogin == 0) && client_req.authed_send) {
					syslog(LOG_INFO, "Authentication successful for %s from %s\n", auth_userpass, req->remote_ip_addr);
					log_message("Authentication successful for %s from %s", auth_userpass, req->remote_ip_addr);
					memset(client_req.client_ip, 0x0, 20);
					strncpy(client_req.client_ip, req->remote_ip_addr, sizeof(client_req.client_ip));
				}
				g_bLogin = 1;					
				
				//client_req.authed_send = 0;
				//memset(client_req.client_ip, 0x0, 20);
				//strncpy(client_req.client_ip, req->remote_ip_addr, sizeof(client_req.client_ip));
				//syslog(LOG_INFO, "Authentication successful for %s from %s\n", auth_userpass, req->remote_ip_addr);
				//log_message("Authentication successful for %s from %s", auth_userpass, req->remote_ip_addr);
				client_req.lastaccess_time=GetSysUpTime();				
				
			//}
			/* Copy user's name to request structure */
#ifdef LDAP_HACK
			if (!ldap_succ) {
				strcpy(req->user, "noldap");
				syslog(LOG_INFO, "Access granted as noldap");
			} else
#endif
			strncpy(req->user, auth_userpass, 15);
			req->user[15] = '\0';
			return 1;
		  }	
	}
						
  	return 1;
}

void dump_auth(void)
{
	int i;
	auth_dir *temp;

	for (i = 0; i < AUTH_HASHTABLE_SIZE; ++i) {
		if (auth_hashtable[i]) {
			temp = auth_hashtable[i];
			while (temp) {
				auth_dir *temp_next;

				if (temp->directory)
					free(temp->directory);
				if (temp->authfile)
					fclose(temp->authfile);
				temp_next = temp->next;
				free(temp);
				temp = temp_next;
			}
			auth_hashtable[i] = NULL;
		}
	}
}

#endif
