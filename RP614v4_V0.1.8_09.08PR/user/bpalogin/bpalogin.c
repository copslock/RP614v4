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

#include "bpalogin.h"
//#include "shutils.h"
#include <dni_shutils.h>

int g_need_listen=0;  //dvd.chen
int g_pkt_wanna_go_out=0;
/*
**  Main processing loop.  Logs in, handles heartbeats, and logs out on request
**
**  Returns - 0 - We are no longer connected, and should not retry.
**            1 - We are no longer connnected and should retry.
*/
int mainloop(struct session * s)
{
	int err;
	struct sockaddr_in listenaddr;
	struct hostent * he;
	int addrsize;
	int ret;

	//added by dvd.chen, for listen lan pkt to trigger connection
	cprintf("g_need_listen:%d\n", g_need_listen);
	if(g_need_listen)
	{
#if 0
		ret=listen_lan_interface();
		//enum {L_FAIL, L_ERROR, L_UPGRADE, L_ESTABLISHED, L_SUCCESS};
		if( ret == 4)  //there is pkt wanna go out
		{
			char sig[5];
			
			g_need_listen = 0;
			s->debug(1, "\npkt wanna go out, goto login\n");
			sprintf(sig, "-%d", SIGUSR2);
    			eval("killall",sig,"CheckWan");  //signal CheckWan task that now is NOT listening lan interface
		}
		else	
		{
			s->debug(1, "\nNO pkt wanna go out, ret:%d\n", ret);
			sleep(1);
			goto no_login;
		}
#else  //for netgear dial_on_demand

		// 1. register for dial_on_demand
		//AddDemandRoute(5, 1);  
		/* move to hb_disconnect_main */
		/* NAPT does not works, after AddDemandRoute */

		// 2. wait for pkt_wanna_go_out signal 
		while( !g_pkt_wanna_go_out )
		{
			s->debug(1, "\nNO pkt wanna go out\n");
			sleep(1);
		}

		{
			char sig[5];
			
			g_need_listen = 0;
			g_pkt_wanna_go_out = 0;
			s->debug(1, "\npkt wanna go out, goto login\n");
			sprintf(sig, "-%d", SIGUSR2);
    			eval("killall",sig,"CheckWan");  //signal CheckWan task that now is NOT listening lan interface
		}
#endif
	}
	//end of dvd.chen

	s->lastheartbeat = 0;
	s->sequence = 0;
	s->listensock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	s->debug(1, "createListenSocket:%d\n", s->listensock);

	s->localaddr.sin_family = AF_INET;
	s->localaddr.sin_port = htons(s->localport);
	if(strcmp(s->localaddress,""))
	{
		s->debug(0,"Using local address %s\n",s->localaddress);
		he = gethostbyname(s->localaddress);

		if(he)
		{
			s->localaddr.sin_addr.s_addr = *((int*)(he->h_addr_list[0]));
		}
		else
		{
			s->localaddr.sin_addr.s_addr = inet_addr(s->localaddress);
		}
	}
	else
	{
		//s->debug(0,"local address: INADDR_ANY\n");
		s->localaddr.sin_addr.s_addr = INADDR_ANY;
	}

	addrsize = sizeof(struct sockaddr_in);
	err = bind(s->listensock,(struct sockaddr *)&s->localaddr,sizeof(s->localaddr));
	err = getsockname(s->listensock,(struct sockaddr *)&listenaddr,&addrsize);

	//move down after logging out, because we will change the value there, dvd.chen
	//s->sessionid = time(NULL);

	s->listenport = ntohs(listenaddr.sin_port);
	strcpy(s->osname,"whocares");
	strcpy(s->osrelease,"notme");

	he = gethostbyname(s->authserver);

	if(he)
	{
		//s->debug(1,"%s::gethostbyname(%s) success\n", __FUNCTION__, s->authserver);
		s->authhost.sin_addr.s_addr = *((int*)(he->h_addr_list[0]));
	}
	else
	{
		//s->debug(1,"%s::gethostbyname(%s) failed\n", __FUNCTION__, s->authserver);
		s->authhost.sin_addr.s_addr = inet_addr(s->authserver);
	}
	
	s->authhost.sin_port = htons(s->authport);
	s->authhost.sin_family = AF_INET;

	s->debug(0,"Auth host = %s:%d\n",s->authserver,s->authport);
	s->debug(0,"Listening on port %d\n",s->listenport);

	//added by dvd.chen on 09/01/2004, 
	//if session had NOT been loged-out when target restarted ==> logout this session
	//file: bpalogin.session will be removed whenever the session is successfully loged-out
	{
		FILE *fp;
		int ret;
		char *str_sessionid;
		
		if( (fp = fopen("/tmp/bpalogin.session", "r")) )
		{
			str_sessionid = file2str("/tmp/bpalogin.session");
			s->sessionid=atoi( str_sessionid );
			//cprintf("%s::getting sessionid[%d] from file: bpalogin.session\n", __FUNCTION__, s->sessionid);
			ret = logout(0, s);
			s->debug(1,"%s::foundsessionid[%d] from bpalogin.session, logout ret: %d\n", 
					__FUNCTION__ ,s->sessionid, ret);
			free(str_sessionid);
			fclose(fp);
		}
		else
		{
			s->debug(1,"%s::can't open bpalogin.session for read, no need to logout last session\n", __FUNCTION__);
		}
	}
	//end of chen
	
	//must get new sessionid here(afetr logout last session), dvd.chen
	s->sessionid = time(NULL);

	if(login(s))
	{
		//cprintf("%s::login success\n", __FUNCTION__);
		s->onconnected(s->listenport);
		if(!handle_heartbeats(s))
		{
			int i;
			s->ondisconnected(1); // --> Handle only udp port 5050 
			s->noncritical("handle_heartbeats fail, ret[0]:Sleeping for 60 seconds\n");
			for(i=0;i<60;i++)
			{
				//added by dvd.chen, for test
				if(g_need_listen)
					break;
				//end of dvd.chen
				if(s->shutdown)
					return 0;
				else
					sleep(1);
			}
		}
		else
		{
			//modified by dvd.chen on 09/08/2004
			/*
			closesocket(s->listensock);
			// Modified by wayne.lu on 8/10/2004
			//return 0;
			sleep(3);
			return 1;	// try again;
			*/
			//send signal:TERM to bpalogin task, it will trigger the logout process and remove iptables:5050 entry
			s->debug(1, "%s::handle_heartbeats fail, ret[1]:socket closed, signaling TERM to logout\n", __FUNCTION__);
			eval("killall", "bpalogin"); 
			//kill(getpid(), SIGTERM);
			sleep(1);
			//fall through to close listensock and try again
			//end of dvd.chen
		}
		closesocket(s->listensock);
		s->debug(1, "closeListenSocket:%d\n", s->listensock);
		
	}
	else
	{
		int i;
		//cprintf("%s::login fail\n", __FUNCTION__);
		s->noncritical("login failed: Sleeping for 60 seconds\n");
		for(i=0;i<60;i++)
		{
			//added by dvd.chen
			//cprintf("g_need_listen:%d\n",g_need_listen);
			if(g_need_listen)
				break;
			//end of dvd.chen
			if(s->shutdown)
				return 0;
			else
				sleep(1);
		}
		closesocket(s->listensock);
		s->debug(1, "closeListenSocket:%d\n", s->listensock);
	}
no_login:
	return 1;
}
