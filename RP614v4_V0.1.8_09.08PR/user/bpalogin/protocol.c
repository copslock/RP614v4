/*
**	BPALogin - lightweight portable BIDS2 login client
**	Copyright (c) 2001-3 Shane Hyde, and others.
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

#include <errno.h>
#include "bpalogin.h"
#include "md5.h"
//#include "shutils.h"
#include <dni_shutils.h>
#include <re865x.h>

extern int g_need_listen;

void genmd5(char *p,int len,char *digest)
{
    MD5_CTX context;
    MD5Init(&context);
    MD5Update(&context, p, len);
    MD5Final(digest, &context);
}

/*
**  This functions makes the MD5 based data packet which is used to login,
**  logout and handle heartbeats
*/
void makecredentials(char * credentials,struct session *s,INT2 msg,INT4 extra)
{
	INT2 j = htons(msg);
	int i=0;
	char buffer[150];
	INT4 ts = htonl(extra);

	memcpy(buffer,s->nonce,16);
	i += 16;
	memcpy(buffer+i,s->password,strlen(s->password));
	i += strlen(s->password);
	memcpy(buffer+i,&(ts),sizeof(INT4));
	i += sizeof(INT4);
	memcpy(buffer+i,&j,sizeof(INT2));
	i += sizeof(INT2);

	genmd5(buffer,i,credentials);
}

/*
**  Login to the Authentication server
**
**  Returns - 0 - failed to login for some reason.
**            1 - Logged in successfully
*/
int login(struct session * s)
{
	int err;
	char credentials[16];
	time_t logintime;

	int authsocket;
	struct transaction t;
	INT2 transactiontype;
	int addrsize;


	s->localaddr.sin_port = htons(0);

	authsocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	s->debug(1, "createSocket:%d\n", authsocket);
	err = bind(authsocket,(struct sockaddr *)&s->localaddr,sizeof(struct sockaddr_in));
	if(err)
	{
		socketerror(s,"Error binding auth socket");
		closesocket(authsocket);
		s->debug(1, "closeSocket:%d\n", authsocket);
		return 0;
	}
		
	err = connect(authsocket,(struct sockaddr *)&s->authhost,sizeof(struct sockaddr_in));

	if(err)
	{
		socketerror(s,"Cant connect to auth server");
		closesocket(authsocket);
		s->debug(1, "closeSocket:%d\n", authsocket);
		return 0;
	}
	addrsize = sizeof(struct sockaddr_in);
	err = getsockname(authsocket,(struct sockaddr *)&s->localipaddress,&addrsize);

	/*
	** start the negotiation 
	*/
	start_transaction(&t,T_MSG_PROTOCOL_NEG_REQ,s->sessionid);
	add_field_INT2(s,&t,T_PARAM_CLIENT_VERSION,LOGIN_VERSION * 100);
	add_field_string(s,&t,T_PARAM_OS_IDENTITY,s->osname);
	add_field_string(s,&t,T_PARAM_OS_VERSION,s->osrelease);
	add_field_INT2(s,&t,T_PARAM_PROTOCOL_LIST,T_PROTOCOL_CHAL);

	send_transaction(s,authsocket,&t);

	transactiontype = receive_transaction(s,authsocket,&t);
	if(transactiontype != T_MSG_PROTOCOL_NEG_RESP)
	{
		s->debug(0,"T_MSG_PROTOCOL_NEG_RESP - error transaction type (%d)",transactiontype);
		closesocket(authsocket);	
		s->debug(1, "closeSocket:%d\n", authsocket);
		return 0;
	}

	extract_valueINT2(s,&t,T_PARAM_STATUS_CODE,&s->retcode);
	extract_valuestring(s,&t,T_PARAM_LOGIN_SERVER_HOST,s->loginserverhost);
	extract_valueINT2(s,&t,T_PARAM_PROTOCOL_SELECT,&s->protocol);

	if(s->protocol != T_PROTOCOL_CHAL)
	{
		s->debug(0,"T_MSG_PROTOCOL_NEG_RESP - Unsupported protocol (%d)",s->protocol);
		closesocket(authsocket);	
		s->debug(1, "closeSocket:%d\n", authsocket);
		return 0;
	}

	switch(s->retcode)
	{
	case T_STATUS_SUCCESS:
	case T_STATUS_LOGIN_SUCCESS_SWVER:
		break;
	case T_STATUS_LOGIN_FAIL_SWVER:
		{
		s->debug(0,"T_MSG_PROTOCOL_NEG_RESP - Login failure: software version");
		closesocket(authsocket);
		s->debug(1, "closeSocket:%d\n", authsocket);
		return 0;
		}
	case T_STATUS_LOGIN_FAIL_INV_PROT:
		{
		s->debug(0,"T_MSG_PROTOCOL_NEG_RESP - Login failure: invalid protocol");
		closesocket(authsocket);		
		s->debug(1, "closeSocket:%d\n", authsocket);
		return 0;
		}
	case T_STATUS_LOGIN_UNKNOWN:
		{
		s->debug(0,"T_MSG_PROTOCOL_NEG_RESP - Login failure: unknown");
		closesocket(authsocket);		
		s->debug(1, "closeSocket:%d\n", authsocket);
		return 0;
		}
	}

	closesocket(authsocket);
	s->debug(1, "closeSocket:%d\n", authsocket);

	authsocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	s->debug(1, "createSocket:%d\n", authsocket);
	err = bind(authsocket,(struct sockaddr *)&s->localaddr,sizeof(struct sockaddr_in));
	if(err)
	{
		socketerror(s,"Error binding auth socket 2");
		closesocket(authsocket);
		s->debug(1, "closeSocket:%d\n", authsocket);
		return 0;
	}
	err = connect(authsocket,(struct sockaddr *)&s->authhost,sizeof(struct sockaddr_in));
	if(err)
	{
		socketerror(s,"Error connecting auth socket 2");
		closesocket(authsocket);
		s->debug(1, "closeSocket:%d\n", authsocket);
		return 0;
	}

	start_transaction(&t,T_MSG_LOGIN_REQ,s->sessionid);
	add_field_string(s,&t,T_PARAM_USERNAME,s->username);
	add_field_INT2(s,&t,T_PARAM_CLIENT_VERSION,LOGIN_VERSION * 100);
	add_field_string(s,&t,T_PARAM_OS_IDENTITY,s->osname);
	add_field_string(s,&t,T_PARAM_OS_VERSION,s->osrelease);
	add_field_INT2(s,&t,T_PARAM_REASON_CODE,T_LOGIN_REASON_CODE_NORMAL);
	add_field_INT2(s,&t,T_PARAM_REQ_PORT,s->listenport);

	send_transaction(s,authsocket,&t);

	transactiontype = receive_transaction(s,authsocket,&t);
	if(transactiontype == T_MSG_LOGIN_RESP)
		goto skippo;

	if(transactiontype != T_MSG_AUTH_RESP)
	{
		s->debug(0,"T_MSG_AUTH_RESP - error transaction type (%d)",transactiontype);
		closesocket(authsocket);	
		s->debug(1, "closeSocket:%d\n", authsocket);
		return 0;
	}

	if(!extract_valueINT2(s,&t,T_PARAM_HASH_METHOD,&s->hashmethod))
	{
		s->debug(0,"T_MSG_AUTH_RESP - no hashmethod provided");
		closesocket(authsocket);
		s->debug(1, "closeSocket:%d\n", authsocket);
		return 0;
	}
	if(!extract_valuestring(s,&t,T_PARAM_NONCE,s->nonce))
	{
		s->debug(0,"T_MSG_AUTH_RESP - no nonce supplied");
		closesocket(authsocket);	
		s->debug(1, "closeSocket:%d\n", authsocket);
		return 0;
	}

	if(s->hashmethod == T_AUTH_MD5_HASH)
	{
		genmd5(s->password,strlen(s->password),s->password);
	}

	start_transaction(&t,T_MSG_LOGIN_AUTH_REQ,s->sessionid);

	s->timestamp = time(NULL);
	makecredentials(credentials,s,T_MSG_LOGIN_AUTH_REQ,s->timestamp);

	add_field_data(s,&t,T_PARAM_AUTH_CREDENTIALS,credentials,16);
	add_field_INT4(s,&t,T_PARAM_TIMESTAMP,s->timestamp);

	send_transaction(s,authsocket,&t);

	transactiontype = receive_transaction(s,authsocket,&t);
skippo:
	if(transactiontype != T_MSG_LOGIN_RESP)
	{
		s->debug(0,"T_MSG_LOGIN_RESP - error transaction type (%d)",transactiontype);
		closesocket(authsocket);		
		s->debug(1, "closeSocket:%d\n", authsocket);
		return 0;
	}

	extract_valueINT2(s,&t,T_PARAM_STATUS_CODE,&s->retcode);
	switch(s->retcode)
	{
	case T_STATUS_SUCCESS:
	case T_STATUS_LOGIN_SUCCESSFUL_SWVER:
	case T_STATUS_LOGIN_SUCCESSFUL_ALREADY_LOGGED_IN:
		break;
	case T_STATUS_USERNAME_NOT_FOUND:
		{
		s->debug(0,"T_MSG_LOGIN_RESP - Login failure: username not known");
		closesocket(authsocket);	
		s->debug(1, "closeSocket:%d\n", authsocket);
		return 0;
		}
	case T_STATUS_INCORRECT_PASSWORD:
		{
		s->debug(0,"T_MSG_LOGIN_RESP - Login failure: incorrect password");
		closesocket(authsocket);		
		s->debug(1, "closeSocket:%d\n", authsocket);
		return 0;
		}
	case T_STATUS_ACCOUNT_DISABLED:
		{
		s->debug(0,"T_MSG_LOGIN_RESP - Login failure: Account disabled");
		closesocket(authsocket);		
		s->debug(1, "closeSocket:%d\n", authsocket);
		return 0;
		}
	case T_STATUS_LOGIN_RETRY_LIMIT:
	case T_STATUS_USER_DISABLED:
	case T_STATUS_FAIL_USERNAME_VALIDATE:
	case T_STATUS_FAIL_PASSWORD_VALIDATE:
	case T_STATUS_LOGIN_UNKNOWN:
		{
		s->debug(0,"T_MSG_LOGIN_RESP - Login failure: other error");
		closesocket(authsocket);		
		s->debug(1, "closeSocket:%d\n", authsocket);
		return 0;
		}
	}

	extract_valueINT2(s,&t,T_PARAM_LOGOUT_SERVICE_PORT,&s->logoutport);
	extract_valueINT2(s,&t,T_PARAM_STATUS_SERVICE_PORT,&s->statusport);
	extract_valuestring(s,&t,T_PARAM_TSMLIST,s->tsmlist);
	extract_valuestring(s,&t,T_PARAM_RESPONSE_TEXT,s->resptext);
	{
		int i,n;
		char * p = s->tsmlist;
		char t[200];
		s->tsmcount = 0;

		while((n = strcspn(p," ,"))!=0)
		{
			strncpy(t,p,n);
			t[n] = 0;
			p += n +1;
			strcpy(s->tsmlist_s[s->tsmcount],t);
			strcat(s->tsmlist_s[s->tsmcount++],s->authdomain);
		}
		for(i=0;i<s->tsmcount;i++)
		{
			struct hostent * he;
			
			he = gethostbyname(s->tsmlist_s[i]);
			if(he)
			{
				s->tsmlist_in[i].sin_addr.s_addr = *((int*)(he->h_addr_list[0]));
			}
			else
			{
				//modified by dvd.chen on 09/14/2004
				//s->tsmlist_in[i].sin_addr.s_addr = inet_addr(s->tsmlist_s[i]);
				s->tsmlist_in[i].sin_addr.s_addr = inet_addr(s->authserver);
				
				s->debug(1,"%s::gethostbyname(%s) fail\n", __FUNCTION__, s->tsmlist_s[i]);
			}
			s->debug(1,"Will accept heartbeats from %s = %s\n",s->tsmlist_s[i],inet_ntoa(s->tsmlist_in[i].sin_addr));
		}
	}
	logintime = time(NULL);

	s->debug(0,"Logged on as %s - successful at %s",s->username,asctime(localtime(&logintime)));
	s->sequence = 0;
	s->lastheartbeat = time(NULL);
	s->recenthb = 0;

	// Modified by wayne.lu on 9/13/2004
	// Check return code if something gets wrong
	//closesocket(authsocket);
	while( closesocket(authsocket) )
	{
		int e;
		
		e=errno;
		if(e != EINTR)
		{
			s->debug(0, "%s::closesocket fail, errno: %d\n", __FUNCTION__, e);
			break;
		}
		//if errno == EINTR ==>continue to closesocket until success
	}
	s->debug(1, "closeSocket:%d\n", authsocket);
	//end of modification

	//added by dvd.chen on 09/01/2004, after successfully login, write sessionid to file: bpalogin.session
	{
		FILE *fp;
		
		if (!(fp = fopen("/tmp/bpalogin.session", "w")))
		{
			s->debug(1, "%s::fatal error!! can't open bpalogin.session for write\n", __FUNCTION__);
		}
		else
		{
			fprintf(fp, "%d", s->sessionid);
			fclose(fp);
			s->debug(1, "%s::bpalogin success, file: bpalogin.session updated\n", __FUNCTION__);
		}
	}
	//end of dvd.chen

	//added by dvd.chen on 01/11/2006, for bpa idle_timeout
	//register idle_timeout api in realtek
	if(s->idle_interval > 0)
	{
		int ret;

		ret=re865xIoctl("eth0", SET_PPPD_IDLE_TIME, 0, TRUE, s->idle_interval);
		if(ret)
		{
			s->debug(1, "%s:: rtl8651_setIdleTimeout failed, ret[%d]\n", __FUNCTION__, ret);
		}
		else
		{
			s->debug(1, "%s:: rtl8651_setIdleTimeout SUCCESS, idle_interval[%d]\n", __FUNCTION__, s->idle_interval);
    			alarm(BPA_CHK_IDLE_PERIOD);
		}
	}
	//end of dvd.chen
	
	return 1;
}

/*
**  Handle heartbeats, wait for the following events to happen -
**    
**    1. A heartbeat packet arrives, in which case we reply correctly
**    2. A timeout occured (ie no heartbeat arrived within 7 minutes)
**    3. The socket was closed.
**
**  Returns - 0 - Heartbeat timeout, and subsequent login failed to connect
**            1 - Socket closed on us, presuming the user wants to shut down.
*/
int handle_heartbeats(struct session *s)
{
	INT2 transactiontype;
	struct transaction t;

	while( !g_need_listen )
	{
		transactiontype = receive_udp_transaction(s,s->listensock,&t,&s->fromaddr);

		if(transactiontype == 0xffff)
		{	
			s->debug(0,"Timed out waiting for heartbeat - logging on\n");
			if(!login(s))
				return 0;
		}
		else if(transactiontype == 0xfffd)
		{
			s->debug(0,"Badly structured packet received - discarding\n");
		}
		else if(transactiontype == 0xfffe)
		{
			s->debug(0,"Socket closed - shutting down\n");
			return 1;
		}
		else if(transactiontype == T_MSG_STATUS_REQ)
		{
			char buf[16];

			start_transaction(&t,T_MSG_STATUS_RESP,s->sessionid);
			add_field_INT2(s,&t,T_PARAM_STATUS_CODE,T_STATUS_TRANSACTION_OK);

			s->sequence++;
			makecredentials(buf,s,T_MSG_STATUS_RESP,s->sequence);
			add_field_data(s,&t,T_PARAM_STATUS_AUTH,buf,16);
			add_field_INT4(s,&t,T_PARAM_SEQNUM,s->sequence);

			send_udp_transaction(s,&t);

			s->lastheartbeat = time(NULL);

			s->debug(1,"Responded to heartbeat at %s",asctime(localtime(&s->lastheartbeat)));
		}
		else if(transactiontype == T_MSG_RESTART_REQ)
		{
			s->debug(0,"Restart request - unimplemented");
			return 0;
		}
		else
		{
			/*
			**  Melbourne servers were sending spurious UDP packets after authentication
			**  This works around it.
			*/
			s->debug(0,"Unknown heartbeat message %d ",transactiontype);
		}
	}
	/*
	**  Should never get here
	*/
	return 0;
}

/*
**  Logout of the BIDS2 system
**    
**  Returns - 0 - Could not connect to logout.
**            1 - Logout successful.
*/
int logout(INT2 reason,struct session * s)
{
	int err;
	char credentials[16];
	time_t logintime;

	int authsocket;
	struct transaction t;
	INT2 transactiontype;

	//added by dvd.chen on 09/01/2004, in case user keep pressing logout button on web GUI
	FILE *fp;
	if( !(fp = fopen("/tmp/bpalogin.session", "r")) )
	{
		s->debug(1, "%s::can't open file: bpalogin.session, no need to logout\n", __FUNCTION__);
		return 0;
	}
	else
	{
		fclose(fp);
	}
	//end of dvd.chen
	
	s->localaddr.sin_port = htons(0);
	authsocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	s->debug(1, "createSocket:%d\n", authsocket);
	err = bind(authsocket,(struct sockaddr *)&s->localaddr,sizeof(struct sockaddr_in));
	if(err)
	{
		socketerror(s,"Error binding logout auth socket");
		closesocket(authsocket);
		s->debug(1, "closeSocket:%d\n", authsocket);
		return 0;
	}
	err = connect(authsocket,(struct sockaddr *)&s->authhost,sizeof(struct sockaddr_in));
	if(err)
	{
		socketerror(s,"Error connecting logout auth socket");
		closesocket(authsocket);
		s->debug(1, "closeSocket:%d\n", authsocket);
		return 0;
	}

	/*
	** start the negotiation 
	*/
	start_transaction(&t,T_MSG_LOGOUT_REQ,s->sessionid);
	add_field_string(s,&t,T_PARAM_USERNAME,s->username);
	add_field_INT2(s,&t,T_PARAM_CLIENT_VERSION,LOGIN_VERSION * 100);
	add_field_string(s,&t,T_PARAM_OS_IDENTITY,s->osname);
	add_field_string(s,&t,T_PARAM_OS_VERSION,s->osrelease);
	add_field_INT2(s,&t,T_PARAM_REASON_CODE,reason);

	send_transaction(s,authsocket,&t);

	transactiontype = receive_transaction(s,authsocket,&t);
	if(transactiontype != T_MSG_AUTH_RESP)
	{
		s->critical("logic error");
	}

	if(!extract_valueINT2(s,&t,T_PARAM_HASH_METHOD,&s->hashmethod))
	{
		s->critical("AUTH: no hashmethod");
	}
	if(!extract_valuestring(s,&t,T_PARAM_NONCE,s->nonce))
	{
		s->critical("Auth: no nonce");
	}

	if(s->hashmethod == T_AUTH_MD5_HASH)
	{
		genmd5(s->password,strlen(s->password),s->password);
	}

	start_transaction(&t,T_MSG_LOGOUT_AUTH_RESP,s->sessionid);

	s->timestamp = time(NULL);
	makecredentials(credentials,s,T_MSG_LOGOUT_AUTH_RESP,s->timestamp);

	add_field_data(s,&t,T_PARAM_AUTH_CREDENTIALS,credentials,16);
	add_field_INT4(s,&t,T_PARAM_TIMESTAMP,s->timestamp);

	send_transaction(s,authsocket,&t);

	transactiontype = receive_transaction(s,authsocket,&t);
	if(transactiontype != T_MSG_LOGOUT_RESP)
	{
		s->critical("logic error");
	}

	extract_valueINT2(s,&t,T_PARAM_STATUS_CODE,&s->retcode);
	switch(s->retcode)
	{
	case T_STATUS_SUCCESS:
	case T_STATUS_LOGOUT_SUCCESSFUL_ALREADY_DISCONNECTED:
		break;
	case T_STATUS_USERNAME_NOT_FOUND:
		s->critical("Login failure: username not known");
	case T_STATUS_INCORRECT_PASSWORD:
		s->critical("Login failure: incorrect password");
	case T_STATUS_ACCOUNT_DISABLED:
		s->critical("Login failure: disabled");
	case T_STATUS_LOGIN_RETRY_LIMIT:
	case T_STATUS_USER_DISABLED:
	case T_STATUS_FAIL_USERNAME_VALIDATE:
	case T_STATUS_FAIL_PASSWORD_VALIDATE:
	case T_STATUS_LOGIN_UNKNOWN:
		s->critical("Login failure: other error");
	}

	extract_valueINT2(s,&t,T_PARAM_LOGOUT_SERVICE_PORT,&s->logoutport);
	extract_valueINT2(s,&t,T_PARAM_STATUS_SERVICE_PORT,&s->statusport);
	extract_valuestring(s,&t,T_PARAM_TSMLIST,s->tsmlist);
	extract_valuestring(s,&t,T_PARAM_RESPONSE_TEXT,s->resptext);

	logintime = time(NULL);

	s->debug(0,"Logged out successful at %s",asctime(localtime(&logintime)));
	
	closesocket(authsocket);
	s->debug(1, "closeSocket:%d\n", authsocket);

	//added by dvd.chen on 09/01/2004, after successfully logout, remove file: bpalogin.session,
	//so, if this file exists at the start of bpalogin process(system restart), it means last session had NOT been logout yet
	unlink("/tmp/bpalogin.session");
	s->debug(1, "%s::file: bpalogin.session found and removed\n", __FUNCTION__);
	//end of dvd.chen

	//added by dvd.chen on 01/11/2006, for bpa idle_timeout 
	//UNregister idle_timeout api in realtek
	if(s->idle_interval > 0)
	{
		int ret;

		ret=re865xIoctl("eth0", SET_PPPD_IDLE_TIME, 0, FALSE, 0);
		if(ret)
		{
			s->debug(1, "%s:: rtl8651_CancelIdleTimeout failed, ret[%d]\n", __FUNCTION__, ret);
		}
		else
		{
			s->debug(1, "%s:: rtl8651_CancelIdleTimeout SUCCESS\n", __FUNCTION__);
		}
		
	}
	//end of dvd.chen
	
	return 1;
}
