/*
 * Copyright c                Realtek Semiconductor Corporation, 2003
 * All rights reserved.
 * 
 * $Header: /home/cvsroot/uClinux-dist/user/boa/src/rtl865x/rtl_board.h,v 1.12 2005/12/12 03:24:12 tony Exp $
 *
 * $Author: tony $
 *
 * Abstract: rtl_board.h -- board config init implementations
 *
 * $Log: rtl_board.h,v $
 * Revision 1.12  2005/12/12 03:24:12  tony
 * +: new feature: support trusted user in url-filter.
 *
 * Revision 1.11  2005/12/09 06:21:28  rupert
 * +: Add IPSEC NAT Traversal Configuration
 *
 * Revision 1.10  2005/09/26 08:14:22  tony
 * +: add SNMP Daemon application.
 *
 * Revision 1.9  2005/07/29 12:42:33  chenyl
 * *: bug fix: init domain block when system init
 *
 * Revision 1.8  2005/07/29 09:44:00  chenyl
 * +: dns module in ROMEDRV
 * +: domain blocking (SDK + RomeDrv)
 *
 * Revision 1.7  2005/07/28 13:01:30  tony
 * *: bug fixed: Time Zone - in New York , add PPTP Server UI
 *
 * Revision 1.6  2005/07/06 12:02:36  tony
 * +: New Features: Gaming
 *
 * Revision 1.5  2005/06/29 05:47:07  chenyl
 * *: In configuration system, we ALWAYS store whole configurations regardless of
 * 	compile flags. (ex. PPTP/L2TP, IPSec...)
 *
 * Revision 1.4  2005/06/29 05:40:05  chenyl
 * *: set static Table ID for each item
 *
 * Revision 1.3  2005/06/29 05:22:19  chenyl
 * +: TLV based configuration setting.
 *
 * Revision 1.2  2005/05/04 02:34:24  shliu
 * *: extern modeCfgFactoryDefaultFunction
 *
 * Revision 1.1  2005/04/19 04:58:15  tony
 * +: BOA web server initial version.
 *
 * Revision 1.42  2004/12/28 09:50:48  rupert
 * +: Add IPSEC Support
 *
 * Revision 1.41  2004/11/29 07:42:16  chenyl
 * +: add Semaphore protection into tunekey when ip Up/Down events occur.
 *
 * Revision 1.40  2004/11/16 02:30:30  shliu
 * *** empty log message ***
 *
 * Revision 1.39  2004/11/01 06:09:04  cfliu
 * add CONFIG_CHANGE_RTL8185 to add wireless version info in status webpage
 *
 * Revision 1.38  2004/10/05 09:20:42  chenyl
 * +: web page to turn ON/OFF ip-multicast system
 *
 * Revision 1.37  2004/10/01 07:52:55  yjlou
 * +: add enable/disable PPPoE Passthru and IPv6 Passthru
 *
 * Revision 1.36  2004/09/03 03:00:10  chhuang
 * +: add new feature: pseudo VLAN
 *
 * Revision 1.35  2004/08/18 05:39:59  chenyl
 * +: napt special option web-based setting
 *
 * Revision 1.34  2004/07/14 13:55:59  chenyl
 * +: web page for MN queue
 *
 * Revision 1.33  2004/07/07 05:12:36  chhuang
 * +: add a new WAN type (DHCP+L2TP). But not complete yet!!
 *
 * Revision 1.32  2004/07/06 06:20:33  chhuang
 * +: add rate limit
 *
 * Revision 1.31  2004/06/08 10:57:40  cfliu
 * +: Add WLAN dual mode support. Not yet completed...
 *
 * Revision 1.30  2004/05/28 09:49:16  yjlou
 * +: support Protocol-Based NAT
 *
 * Revision 1.29  2004/05/20 08:43:55  chhuang
 * add Web Page for QoS
 *
 * Revision 1.28  2004/05/12 05:15:05  tony
 * support PPTP/L2TP in RTL865XB.
 *
 * Revision 1.27  2004/04/08 13:18:12  tony
 * add PPTP/L2TP routine for MII lookback port.
 *
 * Revision 1.26  2004/03/31 01:59:36  tony
 * add L2TP wan type UI pages.
 *
 * Revision 1.25  2004/03/03 03:43:32  tony
 * add static routing table in turnkey.
 *
 * Revision 1.24  2004/02/03 08:14:34  tony
 * add UDP Blocking web UI configuration.
 *
 * Revision 1.23  2004/01/29 09:46:34  tony
 * modify serverp_tableDriverAccess(), make it support multiple session.
 * add protocol type in server port UI.
 *
 * Revision 1.22  2004/01/08 12:13:45  tony
 * add Port Range into Server Port.
 * support Server Port for multiple session UI.
 *
 * Revision 1.21  2004/01/07 09:10:04  tony
 * add PPTP Client UI in Config Wizard.
 *
 * Revision 1.20  2003/12/19 04:33:01  tony
 * add Wireless Lan config pages: Basic Setting, Advance Setting, Security, Access Control, WDS
 *
 * Revision 1.19  2003/12/01 12:35:52  tony
 * make ALG is able to be configured by users(Web GUI).
 *
 * Revision 1.18  2003/10/24 10:25:58  tony
 * add DoS attack interactive webpage,
 * FwdEngine is able to get WAN status by rtl8651_wanStatus(0:disconnect,1:connect)
 *
 * Revision 1.17  2003/10/03 12:27:35  tony
 * add NTP time sync routine in management web page.
 *
 * Revision 1.16  2003/10/01 09:12:03  tony
 * move all the extern declare of factory deafult function to rtl_board.h
 *
 * Revision 1.15  2003/10/01 05:57:31  tony
 * add URL Filter routine
 *
 * Revision 1.14  2003/09/30 12:19:49  tony
 * arrange board_ipUpEventTableDriverAccess(), let upnp,ddns,dmz be able to start after dhcpc/pppoe started.
 *
 * Revision 1.13  2003/09/30 08:56:29  tony
 * remove newServerpCfgParam[] from flash, rename ram PPPoeCfg to ramPppoeCfgParam
 *
 * Revision 1.12  2003/09/29 12:58:34  tony
 * add DDNS start/stop routine.
 *
 * Revision 1.11  2003/09/29 05:06:27  orlando
 * add board_ipUp/DownEventTableDriverAccess:
 *
 * Revision 1.10  2003/09/25 02:15:32  orlando
 * Big Change
 *
 * Revision 1.9  2003/09/24 07:10:30  rupert
 * rearrange init sequence
 *
 * Revision 1.8  2003/09/23 11:44:33  tony
 * add UPNP daemon start/stop routine.
 *
 * Revision 1.7  2003/09/23 03:47:29  tony
 * add ddnsCfgParam,ddnsDefaultFactory,ddns_init
 *
 * Revision 1.6  2003/09/22 08:01:45  tony
 * add UPnP Web Configuration Function Routine
 *
 * Revision 1.5  2003/09/22 06:33:37  tony
 * add syslogd process start/stop by CGI.
 * add eventlog download/clear routine.
 *
 * Revision 1.4  2003/09/19 06:06:51  tony
 * *** empty log message ***
 *
 * Revision 1.3  2003/09/19 01:43:50  tony
 * add dmz routine
 *
 * Revision 1.2  2003/09/18 02:05:45  tony
 * modify pppoeCfgParam to array
 *
 * Revision 1.1.1.1  2003/08/27 06:20:15  rupert
 * uclinux initial
 *
 * Revision 1.1.1.1  2003/08/27 03:08:53  rupert
 *  initial version 
 *
 * Revision 1.13  2003/07/03 05:59:55  tony
 * add configChanged global param.
 *
 * Revision 1.12  2003/07/01 10:25:00  orlando
 * call table driver server port and acl API in board.c
 *
 * Revision 1.11  2003/07/01 03:09:06  tony
 * add aclGlobalCfgParam structure.
 * modify aclCfgParam and serverpCfgParam structure.
 *
 * Revision 1.10  2003/06/30 07:46:11  tony
 * add ACL and Server_Port structure
 *
 * Revision 1.9  2003/06/23 10:57:23  elvis
 * change include path of  rtl_types.h
 *
 * Revision 1.8  2003/06/20 12:59:45  tony
 * add dhcp client
 *
 * Revision 1.7  2003/06/16 08:08:30  tony
 * add dhcps & dns function
 *
 * Revision 1.6  2003/06/06 11:57:12  orlando
 * add pppoe cfg.
 *
 * Revision 1.5  2003/06/06 06:31:11  idayang
 * add mgmt table in cfgmgr.
 *
 * Revision 1.4  2003/06/03 10:57:05  orlando
 * add nat table in cfgmgr.
 *
 * Revision 1.3  2003/05/20 08:44:35  elvis
 * change the include path of "rtl_types.h"
 *
 * Revision 1.2  2003/05/05 05:02:45  orlando
 * make ifCfgParam[] not extern.
 *
 * Revision 1.1  2003/05/02 08:51:08  orlando
 * merge cfgmgr with old board.c/board.h.
 *
 */

#ifndef _rtl_board_h_
#define _rtl_board_h_

#define CONFIG_CHANGE_FW_VER	1
#define CONFIG_CHANGE_LD_VER	(1<<1)
#define CONFIG_CHANGE_NAT		(1<<2)
#define CONFIG_CHANGE_HW_ACCEL	(1<<3)
#define CONFIG_CHANGE_LAN_IP	(1<<4)
#define CONFIG_CHANGE_LAN_MASK	(1<<5)
#define CONFIG_CHANGE_LAN_MAC	(1<<6)
#define CONFIG_CHANGE_DHCPS		(1<<7)
#define CONFIG_CHANGE_CONN_TYPE	(1<<8)
#define CONFIG_CHANGE_WAN_IP	(1<<9)
#define CONFIG_CHANGE_WAN_MASK	(1<<10)
#define CONFIG_CHANGE_WAN_GW	(1<<11)
#define CONFIG_CHANGE_WAN_DNS	(1<<12)
#define CONFIG_CHANGE_WAN_MAC	(1<<13)
#define CONFIG_CHANGE_RTL8185		(1<<14)

#include "rtl_types.h"
#include "board.h"
#include <linux/config.h>

/*
	For CFGMGR system control.
*/
typedef struct _board_cfgmgr_ctrl_s {
	uint16 tableId;
	void *dafaultPtr;
	uint32 defaultSize;
} _board_cfgmgr_ctrl_t;

enum _board_cfgmgr_tabId_e {
	CFGMGR_TABID_NULL					= 0, /* do not remove this line */
	/* ============================================================= */
	/* inter your module's ID below */
	CFGMGR_TABID_VLAN,
	CFGMGR_TABID_IF,
	CFGMGR_TABID_ROUTE,
	CFGMGR_TABID_ARP,
	CFGMGR_TABID_NAT,
	CFGMGR_TABID_MGMT,
	CFGMGR_TABID_PPPOE,
	CFGMGR_TABID_DHCPS,
	CFGMGR_TABID_DHCPC,
	CFGMGR_TABID_DNS,
	CFGMGR_TABID_DMZ,
	CFGMGR_TABID_LOG,
	CFGMGR_TABID_UPNP,
	CFGMGR_TABID_DDNS,
	CFGMGR_TABID_ACL,
	CFGMGR_TABID_ACL_GLOBAL,
	CFGMGR_TABID_SERVERP,
	CFGMGR_TABID_SPECIALAP,
	CFGMGR_TABID_TBLDRV,
	CFGMGR_TABID_URLFILTER,
	CFGMGR_TABID_DOS,
	CFGMGR_TABID_ALG,
	CFGMGR_TABID_TIME,
	CFGMGR_TABID_UDPBLOCK,
	CFGMGR_TABID_ROUTING,
	CFGMGR_TABID_PPTP,
	CFGMGR_TABID_QOS,
	CFGMGR_TABID_PBNAT,
	CFGMGR_TABID_RATELIMIT,
	CFGMGR_TABID_RATIOQOS,
	CFGMGR_TABID_NAPT,
	CFGMGR_TABID_MODE,
	CFGMGR_TABID_RIP,
	CFGMGR_TABID_PSEUDOVLAN,
	CFGMGR_TABID_PASSTHRU,
	CFGMGR_TABID_IPMULTICAST,
	CFGMGR_TABID_GAMING,	
	CFGMGR_TABID_DOMAINBLOCK,
	CFGMGR_TABID_URLFILTERTRUSTEDUSER,
	/* insert your module's ID above */
#if defined(DNI)	
	CFGMGR_TABID_SCHEDULE, //Add by Timo
	CFGMGR_TABID_EMAIL,	
	CFGMGR_TABID_TEL,
	CFGMGR_TABID_BLANK_STATE, //Append by Kevin
	CFGMGR_TABID_MNU,
//Yili 2006/1/10
	CFGMGR_TABID_HTTPC_INFO,	
#endif
	CFGMGR_TABID_L2TP,
//Added end
#ifdef CONFIG_WAN_LAN_MATCH_DETECTION
	CFGMGR_TABID_WAN_LAN_MATCH_DETECTION,
#endif
	/* ============================================================= */
	CFGMGR_TABID_MAX				/* do not remove this line */
};


/* semaphore */
uint32 rtl8651_sem_init(uint8 val);
void rtl8651_sem_wait(uint32 sem_type);
void rtl8651_sem_post(uint32 sem_type);

uint32 vlan_init(void);
uint32 if_init(void);
uint32 staticroute_init(void);
uint32 arp_init(void);
uint32 nat_init(void);
uint32 dhcpc_init(void);
uint32 dns_init(void);
uint32 dmz_init(void);
uint32 log_init(void);
uint32 upnp_init(void);
uint32 snmp_init(void);
uint32 time_init(void);
uint32 urlfilter_init(void);
uint32 urlfilterTrsutedUser_init(void);
uint32 ddns_init(void);
uint32 dhcps_init(void);
uint32 pppoecfg_init(void);
uint32 acl_init(void);
uint32 acl_tableDriverAccess(void);
uint32 serverp_init(void);
uint32 serverp_tableDriverAccess(uint32 dsid);
uint32 specialap_init(void);
uint32 gaming_init(void);
uint32 pptpserver_init(void);
uint32 domainBlock_init(void);
uint32 wlan_init(void);
uint32 udpblock_init(void);
uint32 routing_init(void);
uint32 board_ipUpEventTableDriverAccess(void);
uint32 board_ipDownEventTableDriverAccess(void);
uint32 pptp_init(void);

#if defined(DNI)
uint32 email_init(void);
uint32 tel_init(void);
uint32 mnu_init(void); //Yili 2006/1/10
#endif

uint32 pbnat_init(void);
uint32 passthru_init(void);
uint32 ipMulticast_init(void);


extern ifCfgParam_t			ramWanCfgParam;
extern ifCfgParam_t			ramLanCfgParam;
extern dhcpsCfgParam_t		ramDhcpsCfgParam;
extern dhcpcCfgParam_t		ramDhcpcCfgParam;
extern pptpCfgParam_t		ramPptpCfgParam;
#if defined(DNI)
extern telCfgParam_t		ramTelCfgParam;
extern mnuCfgParam_t		ramMnuCfgParam;
//Yili 2006/1/10
#endif
extern serverpCfgParam_t	ramServerpCfgParam[][];
extern pppoeCfgParam_t		ramPppoeCfgParam[];
extern uint32 				configChanged;
#endif /* _rtl_board_h_ */

