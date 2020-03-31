/*
* --------------------------------------------------------------------------
* Copyright c                  Realtek Semiconductor Corporation, 2003
* All rights reserved.
* 
* $Header: /home/cvsroot/uClinux-dist/user/boa/src/rtl865x/ipupdown.c,v 1.4 2005/10/24 05:59:08 tony Exp $
*
* Abstract: pppoe/ppp interface up/down event handler
*
* $Author: tony $
*
* $Log: ipupdown.c,v $
* Revision 1.4  2005/10/24 05:59:08  tony
* *: add debug ipupdown info.
*
* Revision 1.3  2005/07/08 09:14:57  shliu
* *: init CFGMGR before doing IP up / down
*
* Revision 1.2  2005/06/01 07:45:57  tony
* +: support for 3g case
*
* Revision 1.1  2005/04/19 04:58:15  tony
* +: BOA web server initial version.
*
* Revision 1.30  2004/11/29 07:42:16  chenyl
* +: add Semaphore protection into tunekey when ip Up/Down events occur.
*
* Revision 1.29  2004/10/13 13:35:44  chenyl
* +: domain setting of DHCP Server
* +: real-DNS-server setting of DHCP Server
*
* Revision 1.28  2004/10/07 10:19:39  chenyl
* *: bug fix: variable assignment error
*
* Revision 1.27  2004/10/06 14:08:03  chenyl
* +: dhcp-server wins setting and broadcast to client
*
* Revision 1.26  2004/09/24 05:20:52  chenyl
* *: add secondary DNS server setting
*
* Revision 1.25  2004/07/12 07:03:47  tony
* +: add wan type dhcpl2tp.
*
* Revision 1.24  2004/07/07 05:12:36  chhuang
* +: add a new WAN type (DHCP+L2TP). But not complete yet!!
*
* Revision 1.23  2004/06/11 09:20:18  tony
* +: using share memory instead of direct access for pRomeCfgParam.
*
* Revision 1.22  2004/06/10 10:34:52  tony
* +: add PPTP dial status: disconnecting, make redial function correct.
*
* Revision 1.21  2004/06/09 12:32:16  tony
* +: add PPTP/L2TP UI page.(Dial and Hang_Up).
*
* Revision 1.20  2004/05/12 05:15:05  tony
* support PPTP/L2TP in RTL865XB.
*
* Revision 1.19  2004/04/08 13:18:12  tony
* add PPTP/L2TP routine for MII lookback port.
*
* Revision 1.18  2004/01/14 02:47:12  hiwu
* add PPTP configuration
*
* Revision 1.17  2004/01/09 09:24:28  hiwu
* fix pRomeCfgParam get incorrect pointer
*
* Revision 1.16  2003/11/19 02:40:15  rupert
* fix pppd_start_dial
*
* Revision 1.15  2003/10/16 09:06:58  orlando
* add association between pppoe table entry (pppObjId) and pppx by
* parameter parsing argv[9]
*
* Revision 1.14  2003/10/15 12:12:08  orlando
* add pppoeCfgParam[].pppx to keep track of hw ppp obj id (0,1,2,3,...)
* in association with linux ppp dial up interface (ppp0,ppp1,ppp2,ppp3,...)
*
* Revision 1.13  2003/10/08 10:38:23  orlando
* pppoe session was treated as hexadecimal, should be deciaml.
*
* Revision 1.12  2003/10/02 10:50:17  orlando
* add manualHangup and whichPppObjId fields in pppoeCfgParam_t for auto
* reconnect implementation
*
* Revision 1.11  2003/10/01 12:39:31  tony
* solve all the compiler warnning messages in ipupdown.c
*
* Revision 1.10  2003/09/29 13:28:19  rupert
* add primary and secondary fields of ifCfgParam_s
*
* Revision 1.9  2003/09/29 12:58:34  tony
* add DDNS start/stop routine.
*
* Revision 1.8  2003/09/29 05:04:47  orlando
* board_ipUp/DownEventTableDriverAccess()
*
* Revision 1.7  2003/09/26 06:02:44  orlando
* take care of pppoeCfgParam[].dialState upon up/down event
*
* Revision 1.6  2003/09/26 05:51:27  orlando
* tune ip/down sequences
*
* Revision 1.5  2003/09/26 01:54:44  orlando
* pppeCfgParam adds more fields. tune code to adapt the change
*
* Revision 1.4  2003/09/25 06:06:45  orlando
* adjust inclue files
*
* Revision 1.3  2003/09/25 05:21:43  orlando
* change file abstract in file header
*
* Revision 1.2  2003/09/25 05:20:31  orlando
* add file header for cvs control
*
*/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <re865x.h>
#include <board.h>
//#include <string.h>
#include <stdlib.h>
#include "rtl_board.h"
#include <linux/config.h>

/* global cfg structure pointer */
extern romeCfgParam_t *pRomeCfgParam;

#if defined(DNI)
unsigned long ppp_ipup_time = 0;
extern int ppp_mtu;
#endif


void ipupdown(int argc, char*argv[])
{
	uint32   i;
	char     tempStr[30];
	uint32   pppObjId;
	ipaddr_t myIp;
	ipaddr_t myGw;
	ipaddr_t myPrimaryDns;
	ipaddr_t mySecondaryDns;
	ipaddr_t myPrimaryWins;
	ipaddr_t mySecondaryWins;
	uint16   mySessionId;
	uint8    myMac[6];
	uint8    pppx;
#ifdef	CONFIG_WAN_LAN_MATCH_DETECTION

#define SIGSUBNETMATCH 90

	char *RetVal;
	uint32 wanip, lanip, lanmask;
#endif

	rtl8651_sem_wait(SEMAPHORE_IPUPDOWN);
	
	printf("entering ipupdown ...\n");

	/* init CFGMGR before doing IP up / down */
	board_cfgmgr_init(TRUE);

	if (strstr(argv[0],"ip-up"))
	{

		FILE *f;
		int i;

#if defined(DNI)
       pRomeCfgParam->pppoeCfgParam[0].uptime = GetSysUpTime();
       pRomeCfgParam->pptpCfgParam.uptime = GetSysUpTime();
       pRomeCfgParam->l2tpCfgParam.uptime = GetSysUpTime();
       
       log_message("WAN Connected");	       
#endif       

		f=fopen("/var/ip-up.txt","w");
		for(i=0;i<13;i++)				
			fprintf(f,"%02d [%s]\n",i,argv[i]);
		fclose(f);
	
		
		memset(tempStr,0,sizeof(tempStr));

		for (i=0;i<6;i++)
		{
			memcpy(tempStr,(char*)&argv[7][i*3],3);


			
			myMac[i]=(unsigned char)strtoul(tempStr,NULL,16);
		}
		
		myIp = (ipaddr_t)inet_addr(argv[5]);
		myGw = (ipaddr_t)inet_addr(argv[6]);
		myPrimaryDns = (ipaddr_t)inet_addr(argv[8]);
		mySecondaryDns = (ipaddr_t)inet_addr(argv[9]);
		mySessionId = (uint16)strtoul(argv[4],NULL,10);
		myPrimaryWins = (ipaddr_t)inet_addr(argv[11]);
		mySecondaryWins = (ipaddr_t)inet_addr(argv[12]);
		ppp_mtu = atoi(argv[13]);

		pppx = (uint8)(argv[1][3] - '0');
	
		//pppObjId = 0; /* default harmless value */
		//for(i=0;i<MAX_PPPOE_SESSION;i++)
		//	if (pRomeCfgParam->pppoeCfgParam[i].dialState == PPPOECFGPARAM_DIALSTATE_DIALED_TRYING)
		//	{
		//		pRomeCfgParam->pppoeCfgParam[i].pppx = pppx;
		//		pppObjId = i;
		//	}
		
		
		if (pRomeCfgParam->ifCfgParam[0].connType == IFCFGPARAM_CONNTYPE_PPPOE)
		{						
			pppObjId = (uint32)strtoul(argv[10],NULL,10);
			pRomeCfgParam->pppoeCfgParam[pppObjId].pppx = pppx;
			
			memcpy(pRomeCfgParam->ifCfgParam[0].ipAddr,&myIp,4);
			i=0xffffffff;memcpy(pRomeCfgParam->ifCfgParam[0].ipMask,&i,4);
			memcpy(pRomeCfgParam->ifCfgParam[0].gwAddr,&myGw,4);
			if (pRomeCfgParam->dnsCfgParam.enable == 0) {
			  memcpy(pRomeCfgParam->ifCfgParam[0].dnsPrimaryAddr,&myPrimaryDns,4);
			  memcpy(pRomeCfgParam->ifCfgParam[0].dnsSecondaryAddr,&mySecondaryDns,4);
			}  
			if (pRomeCfgParam->ifCfgParam[0].fwdWins == 1)
			{
				pRomeCfgParam->ifCfgParam[0].winsPrimaryAddr = myPrimaryWins;
				pRomeCfgParam->ifCfgParam[0].winsSecondaryAddr = mySecondaryWins;
			}
			memcpy(pRomeCfgParam->pppoeCfgParam[0].svrMac,myMac,6);
			pRomeCfgParam->pppoeCfgParam[0].sessionId=mySessionId;
		}
		else if (pRomeCfgParam->ifCfgParam[0].connType == IFCFGPARAM_CONNTYPE_PPTP)
		{
			memcpy(pRomeCfgParam->ifCfgParam[0].ipAddr,&myIp,4);
			i=0xffffffff;memcpy(pRomeCfgParam->ifCfgParam[0].ipMask,&i,4);
			memcpy(pRomeCfgParam->ifCfgParam[0].gwAddr,&myGw,4);
			if (pRomeCfgParam->dnsCfgParam.enable == 0) {
			  memcpy(pRomeCfgParam->ifCfgParam[0].dnsPrimaryAddr,&myPrimaryDns,4);
			  memcpy(pRomeCfgParam->ifCfgParam[0].dnsSecondaryAddr,&mySecondaryDns,4);
			}  
			if (pRomeCfgParam->ifCfgParam[0].fwdWins == 1)
			{
				pRomeCfgParam->ifCfgParam[0].winsPrimaryAddr = myPrimaryWins;
				pRomeCfgParam->ifCfgParam[0].winsSecondaryAddr = mySecondaryWins;
			}
			//system("/bin/iptables -t nat -A POSTROUTING -o ppp0 -j MASQUERADE");			
		}
		else if (pRomeCfgParam->ifCfgParam[0].connType == IFCFGPARAM_CONNTYPE_L2TP)
		{
			memcpy(pRomeCfgParam->ifCfgParam[0].ipAddr,&myIp,4);
			i=0xffffffff;memcpy(pRomeCfgParam->ifCfgParam[0].ipMask,&i,4);
			memcpy(pRomeCfgParam->ifCfgParam[0].gwAddr,&myGw,4);
			if (pRomeCfgParam->dnsCfgParam.enable == 0) {			
				memcpy(pRomeCfgParam->ifCfgParam[0].dnsPrimaryAddr,&myPrimaryDns,4);
				memcpy(pRomeCfgParam->ifCfgParam[0].dnsSecondaryAddr,&mySecondaryDns,4);
			}	
			if (pRomeCfgParam->ifCfgParam[0].fwdWins == 1)
			{
				pRomeCfgParam->ifCfgParam[0].winsPrimaryAddr = myPrimaryWins;
				pRomeCfgParam->ifCfgParam[0].winsSecondaryAddr = mySecondaryWins;
			}
			//system("/bin/iptables -t nat -A POSTROUTING -o ppp0 -j MASQUERADE");			
		}
		else {
			return ;
		}

#ifdef CONFIG_WAN_LAN_MATCH_DETECTION
	memcpy((void*)&lanip,pRomeCfgParam->ifCfgParam[1].ipAddr,sizeof(lanip));
	memcpy((void*)&lanmask,pRomeCfgParam->ifCfgParam[1].ipMask,sizeof(lanmask));
	RetVal = nvram_get("wan0_ipaddr");
	wanip=(uint32)inet_addr(RetVal);
	lanip &= lanmask;
	wanip &= lanmask;
	if(lanip == wanip) { 
		kill(1,SIGSUBNETMATCH);
	}
#endif

		//dhcps_start();
		
		/* configure the asic thru table driver APIs */
		
		board_ipUpEventTableDriverAccess();
		
	} /* end "ip-up" */

	
	/********************************************************************/
	/********************************************************************/
	/********************************************************************/
	
	if (strstr(argv[0],"ip-down"))
	{


		FILE *f;
		int i;

#if defined(DNI)
              pRomeCfgParam->pppoeCfgParam[0].uptime = 0;
       	      pRomeCfgParam->pptpCfgParam.uptime = 0;
 
	      log_message("WAN DisConnected");
#endif

		f=fopen("/var/ip-down.txt","w");
		for(i=0;i<10;i++)				
			fprintf(f,"%02d [%s]\n",i,argv[i]);
		fclose(f);

	
		myIp = (ipaddr_t)inet_addr(argv[5]);
		myGw = (ipaddr_t)inet_addr(argv[6]);
		myPrimaryDns = (ipaddr_t)inet_addr(argv[8]);
		mySecondaryDns = (ipaddr_t)inet_addr(argv[9]);


		/* fetch pRomeCfgParam from argument list */

		pppx=0;
		pppObjId=0;
		
		if (pRomeCfgParam->ifCfgParam[0].connType == IFCFGPARAM_CONNTYPE_DHCPC)
		{
			/* dhcp renew */
		}				
		else if (pRomeCfgParam->ifCfgParam[0].connType == IFCFGPARAM_CONNTYPE_PPPOE)
		{
			/* single pppoe hangup case */			
			pRomeCfgParam->pppoeCfgParam[0].dialState = PPPOECFGPARAM_DIALSTATE_OFF;
		}
		else if (pRomeCfgParam->ifCfgParam[0].connType == IFCFGPARAM_CONNTYPE_PPTP)
		{
			/* single pptp hangup case */			
			pRomeCfgParam->pptpCfgParam.dialState = PPTPCFGPARAM_DIALSTATE_DISCONNECTING;
			//system("/bin/iptables -t nat -F");			
		}
		else if (pRomeCfgParam->ifCfgParam[0].connType == IFCFGPARAM_CONNTYPE_L2TP)
		{
			/* single l2tp hangup case */			
			pRomeCfgParam->l2tpCfgParam.dialState = L2TPCFGPARAM_DIALSTATE_OFF;
			//system("/bin/iptables -t nat -F");			
		}
		else {
			return ;
		}

		/* configure the asic thru table driver APIs */
		board_ipDownEventTableDriverAccess();

	} /* end "ip-down" */

	rtl8651_sem_post(SEMAPHORE_IPUPDOWN);

} /* end ipupdown() */

/* end ipupdown.c */


