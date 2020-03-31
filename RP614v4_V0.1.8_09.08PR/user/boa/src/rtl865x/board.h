/*
* ----------------------------------------------------------------
* Copyright c                  Realtek Semiconductor Corporation, 2002  
* All rights reserved.
* 
* $Header: /home/cvsroot/uClinux-dist/user/boa/src/rtl865x/board.h,v 1.23 2005/12/12 03:24:12 tony Exp $
*
* Abstract: Board specific definitions.
*
* $Author: tony $
*
* $Log: board.h,v $
* Revision 1.23  2005/12/12 03:24:12  tony
* +: new feature: support trusted user in url-filter.
*
* Revision 1.22  2005/12/09 06:21:28  rupert
* +: Add IPSEC NAT Traversal Configuration
*
* Revision 1.21  2005/12/02 11:00:35  yjlou
* *: fixed the bug of re-entry flashdrv:
*    Since we used mutex lock thru ioctl(), it does not work.
*    Because when ioctl() returns to user-space, the 'IEc' flag will be recovered to 1 due to 'rfe' instruction.
*    Therefore, we must turn off GIRM to ensure no interrupt will be fired.
*    And also, we will kick watchdog when erasing and programming flash.
*
* Revision 1.20  2005/10/05 13:39:43  rupert
* +: Add MAX_IPSEC_SESSION Definition
*
* Revision 1.19  2005/10/05 09:54:53  chenyl
* +: BOTH setting for WLAN 8185 WPA/WPA2 configurations
* 	- support TKIP/AES clients simultaneously
*
* *: if the second WLAN interface is not installed, the 'Apply' 'Reset' button
* 	in advance setting web-page still must be visitable.
*
* Revision 1.18  2005/09/26 08:14:22  tony
* +: add SNMP Daemon application.
*
* Revision 1.17  2005/09/23 03:19:50  yjlou
* *: Port for 865xC FPGA (NEW_SPEC is undef, said, jblin version).
*    To enable final version, please define NEW_SPEC in the following files:
* 	linux-2.4.x/arch/mips/realtek/rtl865x/irq.c
* 	linux-2.4.x/arch/mips/realtek/rtl865x/setup.c
* 	linux-2.4.x/include/asm-mips/rtl865x/interrupt.h
*
* Revision 1.16  2005/09/20 09:20:30  shliu
* *: define Remote Management Configuration-related constant
*
* Revision 1.15  2005/09/05 08:00:00  chenyl
* +: WPA2 setting
*
* Revision 1.14  2005/08/03 08:42:07  chenyl
* *: modify some WLAN WEP/WPA code to fix bugs
*
* Revision 1.13  2005/07/29 09:44:00  chenyl
* +: dns module in ROMEDRV
* +: domain blocking (SDK + RomeDrv)
*
* Revision 1.12  2005/07/28 13:01:30  tony
* *: bug fixed: Time Zone - in New York , add PPTP Server UI
*
* Revision 1.11  2005/07/28 02:18:40  chhuang
* *: modify qos page
*
* Revision 1.10  2005/07/19 08:48:13  tony
* *** empty log message ***
*
* Revision 1.9  2005/07/11 07:20:23  shliu
* *: add feature of remote pptp/l2tp setting.
*
* Revision 1.8  2005/07/06 12:02:36  tony
* +: New Features: Gaming
*
* Revision 1.7  2005/07/06 11:44:45  chenyl
* *: bug fix: modify some 8185 setting code
*
* Revision 1.6  2005/06/28 06:38:59  tony
* *: support remote log
*
* Revision 1.5  2005/06/24 02:30:10  tony
* +: new features: mail alert
*
* Revision 1.4  2005/06/02 08:38:50  tony
* +: support new wan type - Static USB-ETHERNET
*
* Revision 1.3  2005/05/06 05:07:41  tony
* *: bug fixed: support PAP,CHAP auth mode by UI.
*
* Revision 1.2  2005/05/04 02:32:05  shliu
* *: add mode selection data structure.
*
* Revision 1.1  2005/04/19 04:58:15  tony
* +: BOA web server initial version.
*
* Revision 1.128  2005/03/29 08:29:41  shliu
* *: Let RIPD run on the WAN interface.
*
* Revision 1.127  2005/03/09 08:43:57  chenyl
* +: for the new default ACL action: RTL8651_ACL_L34_DROP
*
* Revision 1.126  2005/02/25 05:34:52  cfliu
* +Add wds support
*
* Revision 1.125  2005/02/17 09:59:40  cfliu
* +:Modify board.c, board.h, rome_Asp.c to support 8185 AP client mode
*
* Revision 1.124  2005/02/02 11:00:17  tony
* +: add crontab ACL scheduling.
*
* Revision 1.123  2005/01/20 10:52:00  ghhuang
* *: Modify web interface of Diffserv DSCP remarking
*
* Revision 1.122  2005/01/20 08:11:33  shliu
* *: Multiple DMZ-host added
*
* Revision 1.121  2005/01/19 09:38:17  ghhuang
* *: DMZ web interface modification & ratioQosCfgParam_t initial values modification
*
* Revision 1.120  2005/01/19 09:07:00  shliu
* *** empty log message ***
*
* Revision 1.119  2005/01/19 06:53:33  shliu
* *** empty log message ***
*
* Revision 1.118  2005/01/18 08:50:22  ghhuang
* +: Diffserv (DSCP) remarking support
*
* Revision 1.117  2005/01/09 08:56:35  cfliu
* +:Update UI config for dual band/card.
*
* Revision 1.116  2005/01/03 01:32:12  rupert
* +: IPSEC WEB access
*
* Revision 1.115  2004/12/28 09:50:48  rupert
* +: Add IPSEC Support
*
* Revision 1.114  2004/12/22 05:19:35  tony
* +: support new features: make ALG(FTP,SIP,NetMeeting) support MNQueue.
*
* Revision 1.113  2004/12/14 09:48:10  chenyl
* +: NAPT-Connection Control system
* *: add "NAPT-AddFail" error messages into ignore case.
*
* Revision 1.112  2004/12/06 10:51:09  ghhuang
* Multiple ACL entries can refer to one rate limit entry
*
* Revision 1.111  2004/12/02 03:08:38  yjlou
* +: support IPX/Netbios Passthru function
*
* Revision 1.110  2004/11/30 04:55:52  cfliu
* +: Update wireless ccfg structure info
*
* Revision 1.109  2004/11/29 07:42:16  chenyl
* +: add Semaphore protection into tunekey when ip Up/Down events occur.
*
* Revision 1.108  2004/11/18 08:05:22  shliu
* *** empty log message ***
*
* Revision 1.107  2004/11/16 02:30:30  shliu
* *** empty log message ***
*
* Revision 1.106  2004/11/10 05:32:19  cfliu
* *** empty log message ***
*
* Revision 1.105  2004/10/29 09:43:32  cfliu
* +add regulation domain field
*
* Revision 1.104  2004/10/21 11:47:57  chenyl
* +: web-based icmp/l4proto DMZ forward setting
*
* Revision 1.103  2004/10/13 13:35:44  chenyl
* +: domain setting of DHCP Server
* +: real-DNS-server setting of DHCP Server
*
* Revision 1.102  2004/10/11 10:23:08  yjlou
* *: restrict only 865xB revB code apply patch code.
*
* Revision 1.101  2004/10/11 04:50:48  yjlou
* +: add rtl8651_enableDropUnknownPppoePADT()
*
* Revision 1.100  2004/10/06 14:08:03  chenyl
* +: dhcp-server wins setting and broadcast to client
*
* Revision 1.99  2004/10/05 09:20:42  chenyl
* +: web page to turn ON/OFF ip-multicast system
*
* Revision 1.98  2004/10/04 09:26:59  cfliu
* change wireless configuration structure
*
* Revision 1.97  2004/10/01 07:52:55  yjlou
* +: add enable/disable PPPoE Passthru and IPv6 Passthru
*
* Revision 1.96  2004/09/03 03:00:09  chhuang
* +: add new feature: pseudo VLAN
*
* Revision 1.95  2004/09/02 08:54:14  yjlou
* *: fixed the bug of flashdrv_isOver5xBBootInstructions(): direct access CRMR in MMU user space is NOT allowed.
*
* Revision 1.94  2004/08/20 12:14:43  cfliu
* +: Add Loose UDP ctrl item
*
* Revision 1.93  2004/08/18 05:39:59  chenyl
* +: napt special option web-based setting
*
* Revision 1.92  2004/08/13 06:00:50  cfliu
* +: Update port number from 8650's 5 to 8650B's 9
*
* Revision 1.91  2004/08/10 12:13:20  yjlou
* *: modify to support kernel mode
*
* Revision 1.90  2004/08/04 14:58:27  yjlou
* *: By default, we DO NOT define _SUPPORT_LARGE_FLASH_ !!
*
* Revision 1.89  2004/08/04 14:50:18  yjlou
* *: change type of __flash_base from 'int*' to 'uint32'
*
* Revision 1.88  2004/07/27 07:23:52  chenyl
* +: DoS ignore type setting
*
* Revision 1.87  2004/07/14 13:55:59  chenyl
* +: web page for MN queue
*
* Revision 1.86  2004/07/12 07:35:32  chhuang
* *: modify rate limit web page
*
* Revision 1.85  2004/07/12 07:03:47  tony
* +: add wan type dhcpl2tp.
*
* Revision 1.84  2004/07/12 04:25:36  chenyl
* *: extend existing port scan mechanism
*
* Revision 1.83  2004/07/08 10:51:41  tony
* *: change ipUp routine to new arch.
*
* Revision 1.82  2004/07/07 05:12:36  chhuang
* +: add a new WAN type (DHCP+L2TP). But not complete yet!!
*
* Revision 1.81  2004/07/06 06:19:25  chhuang
* +: add rate limit
*
* Revision 1.80  2004/06/29 09:40:01  cfliu
* *: Change WLAN rate defines
*
* Revision 1.79  2004/06/14 13:48:17  rupert
* +: Add work properly with MMU kernel
*
* Revision 1.78  2004/06/14 09:47:25  tony
* *: fix PPTP can't compiler well  when not define PPTP/L2TP.
*
* Revision 1.77  2004/06/11 09:20:18  tony
* +: using share memory instead of direct access for pRomeCfgParam.
*
* Revision 1.76  2004/06/11 00:44:56  cfliu
* +: Add port ON/Off webpage
*
* Revision 1.75  2004/06/10 14:35:27  cfliu
* +: Add port config webpage
*
* Revision 1.74  2004/06/10 10:34:52  tony
* +: add PPTP dial status: disconnecting, make redial function correct.
*
* Revision 1.73  2004/06/09 12:32:16  tony
* +: add PPTP/L2TP UI page.(Dial and Hang_Up).
*
* Revision 1.72  2004/06/08 10:54:22  cfliu
* +: Add WLAN dual mode webpages. Not yet completed...
*
* Revision 1.71  2004/05/28 09:49:16  yjlou
* +: support Protocol-Based NAT
*
* Revision 1.70  2004/05/27 05:12:36  tony
* fix multiple pppoe dial problem.
*
* Revision 1.69  2004/05/26 06:51:49  yjlou
* *: use IS_865XB() instead of IS_REV_B()
* *: use IS_865XA() instead of IS_REV_A()
*
* Revision 1.68  2004/05/21 12:08:50  chenyl
* *: TCP/UDP/ICMP spoof -> check for (sip) == (dip)
* *: modify DOS prevention webpage
*
* Revision 1.67  2004/05/20 08:43:55  chhuang
* add Web Page for QoS
*
* Revision 1.66  2004/05/17 12:17:00  cfliu
* Add AC Name field
*
* Revision 1.65  2004/05/13 13:27:01  yjlou
* +: loader version is migrated to "00.00.07".
* +: new architecture for INTEL flash (code is NOT verified).
* *: FLASH_BASE is decided by IS_REV_A()
* -: remove flash_map.h (content moved to flashdrv.h)
* -: remove un-necessary calling setIlev()
*
* Revision 1.64  2004/05/12 08:09:56  chhuang
* +: dhcp static binding
*
* Revision 1.63  2004/05/12 07:20:15  chenyl
* +: source ip blocking
* *: modify dos mechanism
*
* Revision 1.62  2004/05/12 05:15:05  tony
* support PPTP/L2TP in RTL865XB.
*
* Revision 1.61  2004/05/10 05:49:20  chhuang
* add src ip blocking for url-filtering
*
* Revision 1.60  2004/05/05 08:27:07  tony
* new features: add remote management spec
*
* Revision 1.59  2004/05/03 15:02:51  cfliu
* Add 8650B extension port support.
* Revise all WLAN/extport related code.
*
* Revision 1.58  2004/04/08 13:18:12  tony
* add PPTP/L2TP routine for MII lookback port.
*
* Revision 1.57  2004/04/08 12:40:56  cfliu
* Update WLAN webpages and related ASP code.
*
* Revision 1.56  2004/03/31 01:59:36  tony
* add L2TP wan type UI pages.
*
* Revision 1.55  2004/03/19 09:51:18  tony
* make the 'lan permit' acl is able to select by user.
*
* Revision 1.54  2004/03/03 03:43:31  tony
* add static routing table in turnkey.
*
* Revision 1.53  2004/02/05 07:11:16  tony
* add acl filter field: IP.
*
* Revision 1.52  2004/02/04 03:46:10  tony
* change lantype from uint8 to uint32
*
* Revision 1.51  2004/02/03 08:14:34  tony
* add UDP Blocking web UI configuration.
*
* Revision 1.50  2004/01/30 12:03:05  tony
* make Special Application is able to support multiple session.
*
* Revision 1.49  2004/01/16 12:16:46  tony
* modify ALG cfg params and web UI,
* rearrange rtl8651a_setAlgStatus() must called after rtl8651_addIpIntf()
*
* Revision 1.48  2004/01/14 02:46:24  hiwu
* add PPTP configuration
*
* Revision 1.47  2004/01/08 13:28:29  orlando
* dos/url/log related changes
*
* Revision 1.46  2004/01/08 12:13:44  tony
* add Port Range into Server Port.
* support Server Port for multiple session UI.
*
* Revision 1.45  2004/01/08 07:23:21  tony
* support multiple session UI for ACL, URL Filter, DoS log.
*
* Revision 1.44  2004/01/07 10:59:56  tony
* Support multiple session UI plugin for ACL.
*
* Revision 1.43  2004/01/07 09:10:04  tony
* add PPTP Client UI in Config Wizard.
*
* Revision 1.42  2004/01/07 07:36:36  tony
* Support multiple session UI plugin for ALG.
*
* Revision 1.41  2004/01/06 13:50:25  tony
* Support multiple session UI plugin for the following functions:
* DMZ, URL Filter, Dos Prevention
*
* Revision 1.40  2003/12/19 04:33:01  tony
* add Wireless Lan config pages: Basic Setting, Advance Setting, Security, Access Control, WDS
*
* Revision 1.39  2003/12/12 01:34:54  tony
* add NAPT toggle in Unnumbered PPPoE.
*
* Revision 1.38  2003/12/09 13:44:34  tony
* add ACL,DoS,URL Filter logging function in kernel space.
*
* Revision 1.37  2003/12/02 10:24:47  tony
* Add Routine: support DoS is able to set threshold by user(Webs GUI).
*
* Revision 1.36  2003/12/01 12:35:52  tony
* make ALG is able to be configured by users(Web GUI).
*
* Revision 1.35  2003/11/18 09:04:47  tony
* add routine: support mtu configure by user in pppoe.
*
* Revision 1.34  2003/11/13 13:33:58  tony
* pppoe: automaic Hang up all the connections after save.
*
* Revision 1.33  2003/11/13 12:52:06  tony
* add MTU and MRU field in pppoe.
*
* Revision 1.32  2003/11/07 06:31:22  tony
* add type PPPOECFGPARAM_DESTNETTYPE_NONE in MultiPPPoE dest network.
*
* Revision 1.31  2003/11/06 02:25:08  tony
* add field in multi-pppoe cfg.
*
* Revision 1.30  2003/11/04 09:30:56  tony
* modfiy special-application list in board.c
*
* Revision 1.29  2003/10/29 10:20:41  tony
* modify acl policy list.
*
* Revision 1.28  2003/10/29 01:48:24  tony
* fix trigger port bug: when ouside host send a SYN to internal computer,
* gateway return a RST packet problem.
*
* Revision 1.27  2003/10/24 10:25:58  tony
* add DoS attack interactive webpage,
* FwdEngine is able to get WAN status by rtl8651_wanStatus(0:disconnect,1:connect)
*
* Revision 1.26  2003/10/15 12:12:08  orlando
* add pppoeCfgParam[].pppx to keep track of hw ppp obj id (0,1,2,3,...)
* in association with linux ppp dial up interface (ppp0,ppp1,ppp2,ppp3,...)
*
* Revision 1.25  2003/10/14 08:15:01  tony
* add user account management routine
*
* Revision 1.24  2003/10/03 12:27:35  tony
* add NTP time sync routine in management web page.
*
* Revision 1.23  2003/10/03 01:26:42  tony
* add ServiceName field in pppoeCfgParam_t.
* add dynamic check in PPPoE/Unnumbered PPPoE/Multiple PPPoE web page.
*
* Revision 1.22  2003/10/02 10:50:17  orlando
* add manualHangup and whichPppObjId fields in pppoeCfgParam_t for auto
* reconnect implementation
*
* Revision 1.21  2003/10/01 05:57:31  tony
* add URL Filter routine
*
* Revision 1.20  2003/09/30 08:56:29  tony
* remove newServerpCfgParam[] from flash, rename ram PPPoeCfg to ramPppoeCfgParam
*
* Revision 1.19  2003/09/29 13:21:03  rupert
* add primary and secondary dns fields of ifCfgParam_s
*
* Revision 1.18  2003/09/29 08:57:32  tony
* add routine: when pppoe config changed, the dial function will be disabled.
* add routine: dhcps is able to start/stop server on runtime.
*
* Revision 1.17  2003/09/29 05:05:42  orlando
* add pppoeCfgParam[].svrMac/sessionId
*
* Revision 1.16  2003/09/26 01:55:31  orlando
* clean the structure
*
* Revision 1.15  2003/09/25 10:44:50  tony
* small change
*
* Revision 1.14  2003/09/25 10:14:50  tony
* modify pppoe webpage, support unnumbered IP, PPPoE, Multiple PPPoE.
*
* Revision 1.13  2003/09/25 06:43:32  rupert
* add contant of routing function
*
* Revision 1.12  2003/09/25 06:06:45  orlando
* adjust inclue files
*
* Revision 1.11  2003/09/25 03:48:35  orlando
* add romecfg.txt file to pass romeCfgParam structure pointer for other user space application
*
* Revision 1.10  2003/09/25 03:37:36  orlando
* integration...
*
* Revision 1.9  2003/09/25 02:15:32  orlando
* Big Change
*
* Revision 1.8  2003/09/24 07:10:30  rupert
* rearrange init sequence
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
* Revision 1.24  2003/07/03 12:15:59  tony
* fix some warning messages.
*
* Revision 1.23  2003/07/03 06:01:11  tony
* change dhcpcCfgParam_s field order, for 4 bytes alignment.
*
* Revision 1.22  2003/07/01 10:25:22  orlando
* call table driver server port and acl API in board.c
*
* Revision 1.21  2003/07/01 03:09:06  tony
* add aclGlobalCfgParam structure.
* modify aclCfgParam and serverpCfgParam structure.
*
* Revision 1.20  2003/06/30 13:27:55  tony
* add a field in server_port table
*
* Revision 1.19  2003/06/30 07:46:12  tony
* add ACL and Server_Port structure
*
* Revision 1.18  2003/06/27 13:53:25  orlando
* remove dhcpcCfgParam.valid field, use ifCfgParam[0].connType field
* modify rtConfigHook() for cloneMac:
* use dhcpcCfgParam.cloneMac if ifCfgParam[0].connType is
* DHCPC and dhcpcCfgParam.cmacValid is 1 during boottime.
*
* Revision 1.17  2003/06/27 05:33:06  orlando
* adjust some structure.
*
* Revision 1.16  2003/06/26 03:22:29  tony
* remove some element in dhcpc data structure.
*
* Revision 1.15  2003/06/26 03:19:53  orlando
* add ifCfgParam_connType enumeration.
*
* Revision 1.14  2003/06/23 10:57:23  elvis
* change include path of  rtl_types.h
*
* Revision 1.13  2003/06/20 12:59:50  tony
* add dhcp client
*
* Revision 1.12  2003/06/16 08:08:30  tony
* add dhcps & dns function
*
* Revision 1.11  2003/06/11 11:39:29  tony
* add WAN IP connection Type (static, PPPoE, DHCP)
*
* Revision 1.10  2003/06/06 11:57:06  orlando
* add pppoe cfg.
*
* Revision 1.9  2003/06/06 06:31:45  idayang
* add mgmt table in cfgmgr.
*
* Revision 1.8  2003/06/03 10:56:57  orlando
* add nat table in cfgmgr.
*
* Revision 1.7  2003/05/20 08:45:03  elvis
* change the include path of "rtl_types.h"
*
* Revision 1.6  2003/05/09 12:22:20  kckao
* remove RTL8650_LOAD_COUNT
*
* Revision 1.5  2003/05/02 08:51:45  orlando
* merge cfgmgr with old board.c/board.h.
*
* Revision 1.4  2003/04/29 14:20:19  orlando
* modified for cfgmgr.
*
* Revision 1.3  2003/04/08 15:29:47  elvis
* add interface ,route and static arp configurations
*
* Revision 1.2  2003/04/04 02:28:48  elvis
* add constant definition for PHY0, ..., PHY4
*
* Revision 1.1  2003/04/03 01:52:37  danwu
* init
*
* ---------------------------------------------------------------
*/
#ifndef _BOARD_H_
#define _BOARD_H_

#if defined(__KERNEL__) && defined(__linux__)
	/* kernel mode */
	#include "rtl865x/rtl_types.h"
	#include "rtl865x/asicRegs.h"
	#ifdef CONFIG_RTL865XC
		#define IS_865XC() (1)
		#define IS_865XB() (0)
		#define IS_865XA() (0)
	#else
		#define IS_865XC() (0)
		#define IS_865XB() ( ( REG32( CRMR ) & 0xffff ) == 0x5788 )
		#define IS_865XA() ( !IS_865XB() )
	#endif
	#define FLASH_BASE          (IS_865XA()?0xBFC00000:(IS_865XB()?0xBE000000:0xBD000000))
	#define CRMR_ADDR          CRMR
	#define WDTCNR_ADDR        WDTCNR
#else
	/* goahead */
	#include <rtl_types.h>
	#include <linux/config.h>
	#include <asicRegs.h>
	#ifdef __uClinux__
	/* non MMU */
	#ifdef CONFIG_RTL865XC
		#define IS_865XC() (1)
		#define IS_865XB() (0)
		#define IS_865XA() (0)
	#else
		#define IS_865XC() (0)
		#define IS_865XB() ( ( REG32( CRMR ) & 0xffff ) == 0x5788 )
		#define IS_865XA() ( !IS_865XB() )
	#endif
	#define FLASH_BASE          (IS_865XA()?0xBFC00000:(IS_865XB()?0xBE000000:0xBD000000))
	#define CRMR_ADDR          CRMR
	#define WDTCNR_ADDR        WDTCNR
	#else
	/* MMU */
	#ifdef CONFIG_RTL865XC
		#define IS_865XC() (1)
		#define IS_865XB() (0)
		#define IS_865XA() (0)
	#else
		#define IS_865XC() (0)
		#define IS_865XB() (1)
		#define IS_865XA() (0)
	#endif
	extern uint32 __flash_base;
	#define FLASH_BASE          __flash_base
	#define FLASH_BASE_REAL     (IS_865XA()?0xBFC00000:(IS_865XB()?0xBE000000:0xBD000000))
	extern uint32 __crmr_addr;
	extern uint32 __wdtcnr_addr;
	extern uint32 __gimr_addr;	
	#define CRMR_ADDR          __crmr_addr
	#define WDTCNR_ADDR        __wdtcnr_addr
	#define GIMR_ADDR          __gimr_addr	
	int rtl865x_mmap(int base,int length);
	#endif
#endif

#undef _SUPPORT_LARGE_FLASH_ /* to support single 8MB/16MB flash */


#define DNI		1


/* Define flash device 
*/
#define MAX_PORT_NUM		9   
#define MAX_IP_INTERFACE	VLAN_LOAD_COUNT
#define MAX_ROUTE			MAX_IP_INTERFACE
#define MAX_STATIC_ARP		10
#define MAX_MGMT_USER		1
#if defined(DNI)		
/* netgear RP614v4 spec */
#define VLAN_LOAD_COUNT		8
#define MAX_ACL				20
#define MAX_SERVER_PORT	20
#define MAX_SPECIAL_AP		20
#define MAX_ROUTING		10
#define MAX_URL_FILTER		255
//#define MAX_URL_FILTER		20
#define MAX_URL_KEYWORDSTRING	50
#define MAX_HTTP_PASSWD_LENGTH	32
#define MAX_RESERVED_FIXED	30
#define MAX_ATTACHED_DEVICES	64	//ATTACHED_DEVICES
#define MAX_PPPOE_SESSION	1
#else
#define VLAN_LOAD_COUNT		8
#define MAX_ACL				8
#define MAX_SERVER_PORT	    8
#define MAX_SPECIAL_AP		8
#define MAX_ROUTING	5
#define MAX_URL_FILTER		8
#define MAX_RESERVED_FIXED	4
#define MAX_PPPOE_SESSION	2
#endif
#define MAX_GAMING		8
#define MAX_WLAN_CARDS		2
#define MAX_WLAN_AC		    8
#define MAX_WLAN_WDS		8
#define MAX_WLAN_CRYPT_MIX_TYPE	2		/* WPA2 mix : allow WPA/WPA2 -- 2 types */
#define	MAX_IP_STRING_LEN	48
#define MAX_QOS				10
//#define MAX_QOS				12
#define MAX_RATIO_QOS		10
#define MAX_PBNAT			4
#define MAX_USER_SEMAPHORE	2
#define ROMECFGFILE         "/var/romecfg.txt"
#define ALG_QOS_TYPES		3
#define MAX_DOMAIN_BLOCKING	8
#define MAX_ALLOW_DOMAINNAME_LEN	(32+1)
#define MAX_IPSEC_SESSION 	3
#define PHY0	            0x00000001	
#define PHY1	            0x00000002
#define PHY2	            0x00000004
#define PHY3	            0x00000008
#define PHY4	            0x00000010
#define PHYMII		0x00000020
#define MAX_PHYS	        5

/* define semaphore types */
#define SEMAPHORE_IPUPDOWN	0	/* for IP Up/Down only */
#define SEMAPHORE_IPEVENT		1	/* for IP events in board.c */

/* add routing functions  constant*/
#define error_msg(fmt,args...) 
#define ENOSUPP(fmt,args...) 
#define RTACTION_ADD   1
#define RTACTION_DEL   2
#define RTACTION_HELP  3
#define RTACTION_FLUSH 4
#define RTACTION_SHOW  5
#define E_LOOKUP	-1
#define E_OPTERR	-2
#define E_SOCK	-3
#define mask_in_addr(x) (((struct sockaddr_in *)&((x).rt_genmask))->sin_addr.s_addr)
#define full_mask(x) (x)

#define ACL_SINGLE_HANDLE_ADD 1
#define ACL_SINGLE_HANDLE_DEL 2

//Add by Timo Wu
#define URLFILTER_SINGLE_HANDLE_ADD 1
#define URLFILTER_SINGLE_HANDLE_DEL 2
//End Add

#define SHM_PROMECFGPARAM 0x1000

/* define NAPT-mode/Router-mode/Bridge-mode constant. */
#define RTL865XB_L4GATEWAYMODE	4
#define RTL865XB_L3ROUTERMODE		3
#define RTL865XB_L2BRIDGEMODE		2

/* define Remote Management Configuration-related constant */
#define RTL865XB_MULTIPLE_PPPOE_PRIVATE_LAN		0
#define RTL865XB_MULTIPLE_PPPOE_UNNUMBER_LAN 	1

typedef struct vlanCfgParam_s
{
	uint32          vid;        /* VLAN index */
	uint32          memberPort; /* member port list */
	uint32	   enablePorts; /*Enabled Port Numbers*/
	uint32          mtu;        /* layer 3 mtu */
	uint32          valid;      /* valid */
	ether_addr_t	gmac;	    /* clone gateway mac address */
	uint8           rsv[2];     /* for 4 byte alignment */
} vlanCfgParam_t;


enum ifCfgParam_connType_e {
	IFCFGPARAM_CONNTYPE_STATIC = 0,
	IFCFGPARAM_CONNTYPE_PPPOE,
	IFCFGPARAM_CONNTYPE_DHCPC,
	IFCFGPARAM_CONNTYPE_PPPOE_UNNUMBERED,
	IFCFGPARAM_CONNTYPE_PPPOE_MULTIPLE_PPPOE,
	IFCFGPARAM_CONNTYPE_PPTP,	
//Yili 2006/1/6
#if defined(DNI)	
	IFCFGPARAM_CONNTYPE_TELSTRA,	
#endif
	IFCFGPARAM_CONNTYPE_L2TP,	
	IFCFGPARAM_CONNTYPE_DHCPL2TP,
	IFCFGPARAM_CONNTYPE_3G,
	IFCFGPARAM_CONNTYPE_USB_ETHERNET,
};

typedef struct ifCfgParam_s	/* Interface Configuration */
{
	uint32		if_unit;	/* interface unit; 0, 1(vl0, vl1)... */
	uint8		ipAddr[4];	/* ip address */
	uint8		ipAddr1[4];	/* ip address 1: this is for multiple DMZ host spec. */
	uint8		ipAddr2[4];	/* ip address 2: this is for multiple DMZ host spec. */
	uint8		ipMask[4];	/* network mask */
	uint8		ipMask1[4];	/* network mask 1: this is for multiple DMZ host spec.  */	
	uint8		ipMask2[4];	/* network mask 2: this is for multiple DMZ host spec.  */	
	uint8		gwAddr[4];  /* default gateway address */
	uint8		dnsPrimaryAddr[4]; /* dns address */
	uint8		dnsSecondaryAddr[4]; /* dns address */
	uint8		fwdWins;		/* propagate Wins server setting to LAN */
	ipaddr_t		winsPrimaryAddr;	/* wins primary server address */
	ipaddr_t		winsSecondaryAddr;	/* wins secondary server address */
	uint32		flags;	    /* flags for interface attributes */
	uint32		valid;	    /* valid */
	uint32		connType;	/* connection type: 0->static ip, 1->pppoe, 2->dhcp */
#if defined(DNI)
	uint8		hwaddr[6];
	uint16		mtu;	
#endif		
} ifCfgParam_t;



enum pptpCfgParam_dialState_e {
	PPTPCFGPARAM_DIALSTATE_OFF=0,
	PPTPCFGPARAM_DIALSTATE_DIALED_WAITING,			
	PPTPCFGPARAM_DIALSTATE_DIALED_TRYING,
	PPTPCFGPARAM_DIALSTATE_DIALED_SUCCESS,
	PPTPCFGPARAM_DIALSTATE_DISCONNECTING
};

enum l2tpCfgParam_dialState_e {
	L2TPCFGPARAM_DIALSTATE_OFF=0,
	L2TPCFGPARAM_DIALSTATE_DIALED_WAITING,			
	L2TPCFGPARAM_DIALSTATE_DIALED_TRYING,
	L2TPCFGPARAM_DIALSTATE_DIALED_SUCCESS,
	L2TPCFGPARAM_DIALSTATE_DISCONNECTING,
	L2TPCFGPARAM_DIALSTATE_DIALED_DHCP_DISCOVER,
};

enum pppParam_authType {
	PPPPARAM_AUTHTYPE_PAP=0,
	PPPPARAM_AUTHTYPE_CHAP	
};

typedef struct pptpCfgParam_s	/* PPTP Configuration */
{
	uint8	ipAddr[4];	/* ip address */
	uint8	ipMask[4];	/* network mask */
	uint8	svAddr[4];  /* pptp server ip address */
	uint8	gwAddr[4];  /* pptp default gw ip address */
	uint8   pptpid[64]; //Connection Name ID
	int8		username[61];  /* pptp server username */
	int8		password[51];  /* pptp server password */
	uint32	mtu;
	
	uint8			manualHangup;        /* only meaningful for ram version, to record a manual hangup event from web ui */	
	uint8			autoReconnect; /* 1/0 */
	uint8			demand;		   /* 1/0 */	
	uint8			dialState;	   /*  only meaningful for ram version, dial state */
	
	uint32			silentTimeout; /* in seconds */	
	uint32			authType;
	uint32			auto_connect;	
	uint32			uptime;
	uint8			manualStart;        		

} pptpCfgParam_t;

//Added by Yili 2005/12/27
#if defined(DNI)
typedef struct telCfgParam_s	/* Telstra Configuration */
{
	int8		username[61];  /* telstra server username */
	int8		password[51];  	/* telstra server password */
	int8		serviceName[129];  /* telstra service name */
	
	uint32		silentTimeout; 	/* in seconds */	
	uint8		auto_connect;	/* 1/0 */
	uint8		demand;	  	/* 1/0 */
	uint8		manualHangup;  
	uint8		manualStart;     	      	

} telCfgParam_t;
#endif
//Added end

//Yili 2006/1/10
#if defined(DNI)
typedef struct mnuCfgParam_s	/* MNU Configuration */
{
	uint8		enable;	  /* 1/0 */
	uint8		check_enable;	/* 1/0 */
	uint8		runtest_enable;	/* 1/0 */

} mnuCfgParam_t;

typedef struct http_client_ifno_s	
{
	char client_ip[20];
	char authed;	
	unsigned long lastaccess_time;
	int g_bLogin;	
	
} http_client_ifno_t;

typedef struct loader_info_s	
{
	char version[20];
	char date[20];	
} loader_info_t;

#endif
//end

typedef struct pptpServerCfgParam_s	/* PPTP Configuration */
{
	int8		username[32];  /* pptp server username */
	int8		password[32];  /* pptp server password */
	uint8	range1;	/* start ip address */
	uint8	range2;	/* end ip address */
	uint8	status; /* 0:Stop , 1:Start */
	uint8	reserved;
} pptpServerCfgParam_t;

#if 0
typedef struct l2tpCfgParam_s	/* L2TP Configuration */
{
	uint8	ipAddr[4];	/* ip address */
	uint8	ipMask[4];	/* network mask */
	uint8	svAddr[4];  /* l2tp server ip address */
	uint8	gwAddr[4];  /* l2tp default gw ip address */
	int8		username[32];  /* pppoe server username */
	int8		password[32];  /* pppoe server password */
	uint32	mtu;
	
	uint8			manualHangup;        /* only meaningful for ram version, to record a manual hangup event from web ui */	
	uint8			autoReconnect; /* 1/0 */
	uint8			demand;		   /* 1/0 */	
	uint8			dialState;	   /*  only meaningful for ram version, dial state */
	
	uint32			silentTimeout; /* in seconds */	
	uint32			authType;

} l2tpCfgParam_t;
#endif

typedef struct l2tpCfgParam_s	/* L2TP Configuration */
{
	uint8	ipAddr[4];	/* ip address */
	uint8	ipMask[4];	/* network mask */
	uint8	svAddr[4];  	/* l2tp server ip address */
	uint8	gwAddr[4];  	/* l2tp default gw ip address */
	uint8   l2tpid[64]; 	//Connection Name ID
	int8		username[61];  /* l2tp server username */
	int8		password[51];  /* l2tp server password */
	uint32	mtu;
	
	uint8			manualHangup;        /* only meaningful for ram version, to record a manual hangup event from web ui */	
	uint8			autoReconnect;	 /* 1/0 */
	uint8			demand;		   /* 1/0 */	
	uint8			dialState;	   /*  only meaningful for ram version, dial state */
	
	uint32			silentTimeout; /* in seconds */	
	uint32			authType;
	uint32			auto_connect;	
	uint32			uptime;
	uint8			manualStart;        		

} l2tpCfgParam_t;


typedef struct routeCfgParam_s	/* Route Configuration */
{
	uint32          if_unit;	  /* interface unit; 0, 1(vl0, vl1)... */
	uint8           ipAddr[4];	  /* ip network address */
	uint8           ipMask[4];	  /* ip network mask */
	uint8           ipGateway[4]; /* gateway address */
	uint32          valid; 		  /* valid */
} routeCfgParam_t;

typedef struct arpCfgParam_s /* Static ARP Configuration */
{
	uint32          if_unit;	  /* interface unit; 0, 1(vl0, vl1)... */
	uint8           ipAddr[4];	  /* ip host address */
	uint32          port;
	uint32          valid;
	ether_addr_t	mac;
	uint8           rsv[2];       /* for 4 byte alignment */
} arpCfgParam_t;

typedef struct natCfgParam_s /* nat Configuration */
{
	uint8			enable;			/* 0: disable, 1: enable */	
	uint8			hwaccel;			/* 1:hardware acceleration,0:no hw accel */
	uint8			ipsecPassthru;	/* 1: passthru, 0: no passthru */
	uint8			pptpPassthru;	/* 1: passthru, 0: no passthru */
	uint8			l2tpPassthru;	/* 1: passthru, 0: no passthru */
	uint8			rsv[3];			/* for 4 byte alignment */
} natCfgParam_t;

enum ppppoeCfgParam_dialState_e {
	PPPOECFGPARAM_DIALSTATE_OFF=0,
	PPPOECFGPARAM_DIALSTATE_DIALED_WAITING,			
	PPPOECFGPARAM_DIALSTATE_DIALED_TRYING,
	PPPOECFGPARAM_DIALSTATE_DIALED_SUCCESS
};

enum ppppoeCfgParam_destnetType_e {
	PPPOECFGPARAM_DESTNETTYPE_NONE=0,
	PPPOECFGPARAM_DESTNETTYPE_IP,
	PPPOECFGPARAM_DESTNETTYPE_DOMAIN,
	PPPOECFGPARAM_DESTNETTYPE_TCPPORT,
	PPPOECFGPARAM_DESTNETTYPE_UDPPORT,	
};

enum ppppoeCfgParam_lanType_e {
	PPPOECFGPARAM_LANTYPE_NAPT=0,
	PPPOECFGPARAM_LANTYPE_UNNUMBERED,
};

typedef struct pppoeCfgParam_s
{
	uint8			enable;        /* 1:used/enabled, 0:no pppoe */
	uint8			defaultSession;   	/* default pppoe session  */
	uint8			unnumbered;		/* unnumbered pppoe */
	uint8			autoReconnect; /* 1/0 */
	
	uint8			demand;		   /* 1/0 */	
	uint8			dialState;	   /*  only meaningful for ram version, dial state */
	uint16			sessionId;	   /* pppoe session id */
	
	uint32			silentTimeout; /* in seconds */	
		
	uint8           ipAddr[4];	   /* ip address, for multiple pppoe only */
	uint8           ipMask[4];	   /* network mask, for multiple pppoe only */
	uint8           gwAddr[4];     /* default gateway address, for multiple pppoe only */
	uint8           dnsAddr[4];    /* dns address, for multiple pppoe only */	
	
	uint8           localHostIp[4]; /* nat's local host ip, for pppoe/nat case only */
	
	int8			username[65];  /* pppoe server username */

	int8			password[65];  /* pppoe server password */

	int8 			acName[32];

	int8			serviceName[51];  /* pppoe service name */
	
	int8			destnet[4][32];  /* pppoe destination network route 1~4 */
	
	int8			destnetType[4];  /* pppoe destination network type 1~4 */
	
	uint8			unnumberedIpAddr[4];  /* global IP assign by ISP */
	
	uint8			unnumberedIpMask[4];  /* global Network mask assign by ISP */	
	
	uint8           svrMac[6];     /* pppoe server mac address */
    uint8           pppx; /* i am pppx (0,1,2,3,...: ppp0,ppp1,ppp2,...) */    
    uint8           unnumberedNapt;
    
	uint8           whichPppObjId; /* only meaningful for ram version, and for pppoeCfgParam[0] only, to keep track of who is the up/down pppObjId */
	uint8           manualHangup; /* only meaningful for ram version, to record a manual hangup event from web ui */	
	uint16	mtu;

	uint32	lanType;
	uint32	authType;	
//Added by Yili 2005/12/27
#if defined(DNI)
	uint8           internetipAddr[4]; //Internet IP address.
	uint32          internetassign; //Internet IP address assign.
	uint32		auto_connect;		
	uint32		uptime;
	uint8		manualStart;     	
#endif
//Added end

} pppoeCfgParam_t;

typedef struct dhcpsCfgParam_s
{
	uint8           enable;     /* 1:used/enabled, 0:disable */
	uint8           startIp;    /* DHCP Server IP Pool Start IP */
	uint8           endIp;      /* DHCP Server IP Pool End IP */
	uint8	   rsv;     	/* for 4 byte alignment */
	uint8	   realDNSenable;	/* dhcp server provide real-DNS server ip address to dhcp client */
	uint8	   dhcpDomainFwd;	/* forward domain name got from WAN DHCP server */
	char	   domain[64];	/* domain name provided by dhcp server */
//Yili 2006/1/6
#if defined(DNI)	
	char	   lan_domain[51];	/* domain name provided by LAN DHCP server */
#endif	
	uint8	   manu_desc[MAX_RESERVED_FIXED][32];
	uint32	   manualIp[MAX_RESERVED_FIXED];
	uint8	   hardwareAddr[MAX_RESERVED_FIXED][6];
} dhcpsCfgParam_t;

typedef struct dhcpcCfgParam_s
{
	uint32      cmacValid; 	    	/* cmac valid */	
	uint8	    cloneMac[6];	/* clone mac address */
	uint8       hostname[51];  	/* host name */
	uint32	    lease;		/* lease time obtained */
	uint32	    lease_expired;	/* lease time expired */
	uint32	spoofmac_detected; /* spoofmac detected */
} dhcpcCfgParam_t;

typedef struct dnsCfgParam_s
{
	uint32          enable;  /* 1:used/enabled, 0:disable */
	uint8		    primary[4];  /* primary dns server ip */
	uint8		    secondary[4]; /* secondary dns server ip */
} dnsCfgParam_t;

typedef struct mgmtCfgParam_s 
{
	uint8	name[16];
	uint8	password[MAX_HTTP_PASSWD_LENGTH];
	uint32	valid; 		/* valid */
	uint32	remoteMgmtIp;
	uint32	remoteMgmtMask; /* reserved */	
	uint16	remoteMgmtPort; /* remote management port */
	uint8	remoteIcmpEnable; /* remote icmp enable */
	uint8	newfirm;	
} mgmtCfgParam_t;


typedef struct emailCfgParam_s 
{
	uint32	enable;		
	uint8	mailfrom[64];
	uint8	rcptto[64];
	uint8	smtpserver[64];
	uint8	logserver[64];	
	
	uint8   serverauth; //ServerAuth 1:enable 0:disable

	uint8   alertimm; //AlertImm 1:enable 0:disable

	uint8   alerttype; //AlertSelect 0-4
	uint8   alertday; //AlertTime 0-6
	uint8   alerthour; //AlertHour 1-12
	uint8   alertampm; //AlertaMpm 0:AM 1:PM
	
	uint8   time_zone;  //AlertGMT 0-24
	uint8   daylight; //Daylight 1:enable 0:disable
	uint8	smtp_name[65];
	uint8	smtp_password[65];	

} emailCfgParam_t;

enum aclGlobalCfgParam_e {
	ACLGLOBALCFGPARAM_ALLOWALLBUTACL = 0,
	ACLGLOBALCFGPARAM_DENYALLBUTACL,
	ACLGLOBALCFGPARAM_L34_DENYALLBUTACL,
	ACLGLOBALCFGPARAM_ALLOWALLBUTACL_LOG,	
};

typedef struct aclGlobalCfgParam_s 
{
	uint8		policy;				// 0: allow all except ACL , 1: deny all except ACL
	uint8		lanPermit;			// for sercomm spec	
	uint8		rsv[2];				// for 4 bytes alignment 
} aclGlobalCfgParam_t;

enum aclCfgParam_type_e {
	ACLCFGPARAM_PROTOCOL_TCP = 0,
	ACLCFGPARAM_PROTOCOL_UDP,
	ACLCFGPARAM_PROTOCOL_IP
};

enum aclCfgParam_direction_e {
	ACLCFGPARAM_DIRECTION_EGRESS_DEST = 0,
	ACLCFGPARAM_DIRECTION_INGRESS_DEST,
	ACLCFGPARAM_DIRECTION_EGRESS_SRC,
	ACLCFGPARAM_DIRECTION_INGRESS_SRC
};

typedef struct aclCfgParam_s 
{
	uint8		ip[4];		// IP address		/* 0 -> every one, else ip/netmask */
	uint8		ip_end[4];	
	uint16		port;		// IP port		/* 0 -> all ports, else specified port */
	uint16		port_e;		/* port range */
	uint8		enable;		// 0: disable,  1:enable
	uint8		direction;	// 0: egress dest, 1: ingress dest, 2: egress src, 3: ingress src
	
	uint8		type;		// 0: TCP, 1: UDP
	uint8		day;		// bit0:Sunday, bit1:Monday .... bit6:Saturday
	uint8		allday;
	uint8		start_hour;	
	uint8		start_minute;	
	
	uint8		end_hour;	
	uint8		end_minute;	
	uint8		desc[31];	
} aclCfgParam_t;



enum serverpCfgParam_e {
	SERVERPCFGPARAM_PROTOCOL_TCP = 0,
	SERVERPCFGPARAM_PROTOCOL_UDP,
};

typedef struct serverpCfgParam_s 
{
	uint32		enable;		// enable
	uint8		ip[4];		// Server IP address
	uint16		wanPortStart;	// WAN Port
	uint16		wanPortFinish;	// WAN Port	
	uint16		portStart;	// Server Port
	uint8           protocol;	// SERVERPCFGPARAM_PROTOCOL_TCP or SERVERPCFGPARAM_PROTOCOL_UDP
	uint8		desc[32];	
	
} serverpCfgParam_t;

enum specialapCfgParam_e {
	SPECIALACPCFGPARAM_PROTOCOL_TCP = 0,
	SPECIALACPCFGPARAM_PROTOCOL_UDP,
	SPECIALACPCFGPARAM_PROTOCOL_BOTH
};

#define SPECIAL_AP_MAX_IN_RANGE 80
typedef struct specialapCfgParam_s 
{
	uint8		name[16];		// name
	uint32		inType;			// incoming type
	uint8		inRange[SPECIAL_AP_MAX_IN_RANGE];	// incoming port range	/* string format */
	uint32		outType;		// outgoing type
	uint16		outStart;		// outgoing start port
	uint16		outFinish;		// outgoing finish port		
	uint8		enable;			// enable
#if defined(DNI)
	uint8		g_enable;
	uint16		g_triggertime;	
	uint8		ip[4];
#endif
		
} specialapCfgParam_t;


#define GAMING_MAX_RANGE 80
typedef struct gamingCfgParam_s 
{
	uint8		name[32];		// name
	uint32		ip;
	uint8		tcpRange[GAMING_MAX_RANGE];
	uint8		udpRange[GAMING_MAX_RANGE];
	uint8		enable;			// enable
	uint8		rsv[3];			// for 4 bytes alignment
} gamingCfgParam_t;

typedef struct tbldrvCfgParam_s 
{
	uint8		naptAutoAdd;		// napt auto add
	uint8       naptAutoDelete;     // napt auto delete
	uint16		naptIcmpTimeout;	// napt icmp timeout
	uint16      naptUdpTimeout;
	uint16		naptTcpLongTimeout;
	uint16      naptTcpMediumTimeout;
	uint16		naptTcpFastTimeout;
} tbldrvCfgParam_t;

typedef struct dmzCfgParam_s	/* DMZ Configuration */
{
	uint32		enable; 	/* 0:off 1:on */
	uint32		enable2;
	uint32		enable3;
	uint32		dmzIp;
	uint32		dmzIp2;
	uint32		dmzIp3;
	uint8		l4fwd;	/* forward various L4 protocol to DMZ */
	uint8		icmpfwd;	/* forward icmp packet to DMZ */
} dmzCfgParam_t;

typedef struct logCfgParam_s	/* Event Log Configuration */
{
	uint32		module;  /* each bit mapping to each module */
} logCfgParam_t;

typedef struct upnpCfgParam_s	/* UPnP Configuration */
{
	uint32		enable; 	/* 0:off 1:on */
	uint32		timetolive;	
	uint32		advertime;	
	
} upnpCfgParam_t;

typedef struct snmpCfgParam_s	/* SNMP Daemon Configuration */
{
	uint32		enable; 	/* 0:off 1:on */
	
} snmpCfgParam_t;


typedef struct ddnsCfgParam_s	/* DDNS Configuration */
{
	uint32		enable; 	/* 0:off 1:on */
	uint8		service[17];	
	uint8		username[33];
	uint8		password[33];
	uint8		hostname[33];	
	uint32		wildcard;
	uint32		ddns_status;
} ddnsCfgParam_t;


typedef struct urlfilterCfgParam_s	/* URL FILTER Configuration */
{
	uint32		enable; 	/* 0:off 1:on */
	uint8		string[MAX_URL_KEYWORDSTRING];
	uint32		ip_start;
	uint32		ip_end;
} urlfilterCfgParam_t;


typedef struct urlfilterTrustedUserCfgParam_s	/* URL FILTER Configuration */
{
	uint32		trustedIP;
	uint32		enable; 	
} urlfilterTrustedUserCfgParam_t;
#define URL_FILTER_MAX_TRUSTED_USERS 5

// Add by Timo Wu
enum schedulestatus_e
{
	BLOCK_NEVER=0,
	BLOCK_PERSCHEDULE,
	BLOCK_ALWAYS
};

#if defined(DNI) //Add by Timo Wu
typedef struct scheduleCfgParam_s
{
	uint8		day;		// bit0:Sunday, bit1:Monday .... bit6:Saturday
	uint8		allday;
	uint8		start_hour;	
	uint8		start_minute;	
	
	uint8		end_hour;	
	uint8		end_minute;
	uint8		aclstatus; // 0->Never, 1->Per schedule, 2-> Always
	uint8		isacl; // 0->acl not set, 1->acl set
	
	uint8		filterstatus;
	uint8		isfilter; //0->filter not set, 1->filter set
	uint8		rsv[2]; //4 bytes alignment
} scheduleCfgParam_t;

typedef struct BlankStateCfgParam_s
{
	uint32		SmtWzdDone;
	uint32		SmtWzdState;		
 	uint32		Buf_DetectedWanType;
	uint32		Buf_SuccWanConn; //4 bytes alignment
	
} BlankStateCfgParam_t;
#endif

#ifdef CONFIG_WAN_LAN_MATCH_DETECTION
typedef struct wanlan_match_det_s
{
	uint32		LAN_WAN_FLAG;	
} wanlan_match_det_t;
#endif

typedef struct timeCfgParam_s	/* Time Configuration */
{
	uint32		timeZoneIndex;
	uint8		timeZone[16];
	uint8		ntpServer1[32];
	uint8		ntpServer2[32];
	uint8		ntpServer3[32];
} timeCfgParam_t;

typedef struct dosCfgParam_s	/* DoS Configuration */
{
	uint32		enable;
	uint32		enableItem;
	uint8		ignoreLanSideCheck;
	/* connection count system */
	/* <---Whole System counter---> */
	uint16		tcpc;
	uint16		udpc;
	uint16		tcpudpc;
	/* <---Per source IP tracking---> */
	uint16		perSrc_tcpc;
	uint16		perSrc_udpc;
	uint16		perSrc_tcpudpc;
	/* flood check system */
	/* <---Whole System counter---> */
	uint16		syn;
	uint16		fin;
	uint16		udp;
	uint16		icmp;
	/* <---Per source IP tracking---> */
	uint16		perSrc_syn;
	uint16		perSrc_fin;		
	uint16		perSrc_udp;
	uint16		perSrc_icmp;
	/* <----Source IP blocking----> */
	uint16		sipblock_enable;
	uint16		sipblock_PrisonTime;
	/* <----Port Scan Level ----> */
	uint16		portScan_level;
} dosCfgParam_t;

typedef struct naptCfgParam_s	/* NAPT Option Configuration */
{
	uint8		weakNaptEnable;						/* Weak TCP mode */
	uint8 		looseUdpEnable;	/*Loose UDP mode*/
	uint8		tcpStaticPortMappingEnable;				/* TCP static port mapping mode */
	uint8		udpStaticPortMappingEnable;				/* UDP static port mapping mode */
} naptCfgParam_t;

typedef struct algCfgParam_s	/* ALG Configuration */
{
	uint32		algList;
	ipaddr_t		localIp[32];
} algCfgParam_t;


extern int totalWlanCards;

 typedef enum{
	CRYPT_NONE = 0, 
	CRYPT_WEP,
	CRYPT_WPA,
	CRYPT_WPA2,
	CRYPT_WPAMIX,
	CRYPT_MAX
}WlanCryptType;

typedef enum {
	CRYPT_SUB_NONE = 0,
	CRYPT_SUB_WEP_64,
	CRYPT_SUB_WEP_128,
	CRYPT_SUB_WPA_TKIP,
	CRYPT_SUB_WPA_AES,
	CRYPT_SUB_WPA_TKIPAES,
	CRYPT_SUB_MAX
} WlanCryptSubType;

 typedef enum{
 	AUTH_NONE=0,
	AUTH_KEY,
	AUTH_AUTO,
	AUTH_8021x, 
	AUTH_MAX
}WlanAuthType;

enum wlanDataRateModeCfgParam_e {
	WLAN_DATA_RATE_B=0,
	WLAN_DATA_RATE_G=1,
	WLAN_DATA_RATE_BG=2,
	WLAN_DATA_RATE_A=3
};


enum wlanDataRateCfgParam_e {
	WLAN_DATA_RATE_AUTO = 0,
	WLAN_DATA_RATE_54M,
	WLAN_DATA_RATE_48M,
	WLAN_DATA_RATE_36M,
	WLAN_DATA_RATE_24M,
	WLAN_DATA_RATE_18M,
	WLAN_DATA_RATE_12M,
	WLAN_DATA_RATE_9M,
	WLAN_DATA_RATE_6M,
	WLAN_DATA_RATE_11M,
	WLAN_DATA_RATE_5_5M,
	WLAN_DATA_RATE_2M,
	WLAN_DATA_RATE_1M
};

enum wlanPreambleTypeCfgParam_e {
	WLAN_PREAMBLE_TYPE_LONG = 0,
	WLAN_PREAMBLE_TYPE_SHORT = 1,
};


typedef struct wlanCfgParam_s	/* Wireless LAN Configuration */
{
	uint8	aliasName[32];
	uint8	ssid[16];

	uint8	enable;	
	uint8	channel; //0:auto
	uint8	dataRateMode; //enum  //
	uint8	dualAntenna;

	uint8 	protection;
	uint8 	rxChargePump;
	uint8 	txChargePump;
	uint8 	regDomain;
	
	uint16	dataRate; //enum	//
	uint16	frag;
	uint16	rts;
	uint16	beacon;

	uint8	preambleType; //enum
	uint8	broadcastSSID;
	uint8	range;
	uint8 	chipVer;

	uint8	authRadiusPasswd[16];

	uint8	cryptType; //enum
	uint8	cryptSubType[MAX_WLAN_CRYPT_MIX_TYPE];		/* array: for WPA mix-mode */
	uint8	authType;
	uint8	acEnable;
	uint8	wdsEnable; //for 4 bytes alignment

	uint8	wdsCount; //for 4 bytes alignment
	uint8	xxxReserved; //for 4 bytes alignment
	uint16	authRadiusPort;

	uint32	authRadiusIp;
	
	uint8	acMacList[MAX_WLAN_AC][6];
	uint8	acComment[MAX_WLAN_AC][8];
	
	uint8	wdsMacList[MAX_WLAN_WDS][6];
	
	uint8	key[68]; //10 hex for wep64,26 hex for wep128, 64 hex for WPA-PSK

	uint8	mode;
	uint8 	adhoc;
	uint8 	reserved[29];
 
} wlanCfgParam_t;

typedef struct udpblockCfgParam_s	/* UDP Blocking Configuration */
{
	uint32		enable;
	uint32		size;
} udpblockCfgParam_t;

enum routingInterfaceCfgParam_e {
	ROUTING_INTERFACE_NONE = 0,
	ROUTING_INTERFACE_LAN,
	ROUTING_INTERFACE_WAN	
};

typedef struct routingCfgParam_s	/* Routing Table Configuration */
{
	uint32		route;
	uint32		mask;
	uint32		gateway;
	uint8		interface;
	uint8		metric;	
	uint8		valid;
	uint8		desc[32];
	uint8		rip_private;	
} routingCfgParam_t;

#if 0
typedef struct qosCfgParam_s /* QoS Configuration */
{
	uint32		qosType;
	union {
		struct {
			uint16	portNumber;
			uint16	isHigh;
		} policy_based;
		struct {
			uint16	port;
			uint8	isHigh;
			uint8	enableFlowCtrl;
			uint32	inRL;
			uint32	outRL;
		} port_based;
	} un;
} qosCfgParam_t;
#endif

typedef struct qosCfgParam_s /* QoS Configuration */
{
	uint32		qosType;
	union {
		struct {
			uint16	portNumber;
			uint16	portNumber1;
			uint16	isHigh;
			uint16	protocol;
			uint16  enable;
			uint8   desc[33];
		} policy_based;
		struct {
			uint16	port;
			uint16	port1;			
			uint8	isHigh;
			uint8	enableFlowCtrl;
			uint16  protocol;
			uint16	enable;
			uint8   desc[33];			
			uint32	inRL;
			uint32	outRL;
		} port_based;
	} un;
} qosCfgParam_t;



typedef struct ratioAlgQosEntry_s	/* Ratio based ALG QoS entry */
{
	uint32	queueID;	/* 1 ~ max no. of queue */	
	uint8	isHigh;		/* 0: Low 1: High */
	uint8	ratio;		/* percentage */
	uint8	enable;		/* 0: disable, 1: enable */
	uint8 	rsv;			/* reserve for 32bits-alignment */
} ratioAlgQosEntry_t;

typedef struct ratioQosUpstreamCfgParam_s /* Ratio based QoS: Upstream total bandwidth Configuration */
{
	uint32	maxRate;
	uint8	maxRateUnit;		/* 0: Mbps, 1: Kbps */
	uint8	remainingRatio_h;	/* remaining ratio in high queue */
	uint8	remainingRatio_l;	/* remaining ratio in low queue */
	uint8	rsv;				/* reserve for 32bits-alignment */
	ratioAlgQosEntry_t algQosEntry[3];
	
} ratioQosUpstreamCfgParam_t;

typedef struct ratioQosEntry_s	/* Ratio based QoS entry */
{
	uint32	queueID;	/* 1 ~ max no. of queue */	
	uint32	ip;
	uint32	ipMask;
	uint16	s_port;
	uint16	e_port;
	uint8	enable;		/* 0: disable, 1: enable */
	uint8	isSrc;		/* 0: dst, 1: src */
	uint8	protoType;	/* 0: TCP, 1: UDP, 2: IP */
	uint8	isHigh;		/* 0: Low 1: High */
	uint8	ratio;		/* percentage */
	uint8	mark;		/* 0: DSCP marking disabled,  1: enabled */
	uint16	dscp;		/* DSCP value */
} ratioQosEntry_t;

typedef struct ratioQosCfgParam_s	/* Ratio based QoS Configuration */
{
	uint8 enable;							/* 0: disable, 1: enable */
	ratioQosUpstreamCfgParam_t upInfo;
	ratioQosEntry_t entry[MAX_RATIO_QOS];
} ratioQosCfgParam_t;

typedef struct pbnatCfgParam_s /* Protocol-Based NAT Configuration */
{
	uint8 protocol;
	uint8 enabled;
	ipaddr_t IntIp;
} pbnatCfgParam_t;

#define NULL_QOS						0x00
#define PORT_BASED_QOS				0x01
#define POLICY_BASED_QOS				0x02
#define ENABLE_QOS					0x04


typedef struct rateLimitEntry_s
{
	uint8		enable;		/* 0: disable, 1: enable */
	uint32		ip;	
	uint32		ipMask;
	uint16		s_port, e_port;		
	uint8		protoType;	/* 0: TCP, 1: UDP, 2: IP */
	uint8		isByteCount;	/* 0: Packet Count, 1: Byte Count */
	uint32		rate;	
	uint8		rateUnit;		/* 0: Kbps, 1: Mbps */
	uint32		maxRate;		/* Tolerance */
	uint8		maxRateUnit;	/* 0: Kbps, 1: Mbps */
	uint8		isDropLog;	/* 1: Drop & Log, 0: Drop */
	uint8		isSrcIp;
} rateLimitEntry_t;


typedef struct rateLimitCfgParam_s
{
	uint32		enable;		/* 0: disable, 1: enable */
	rateLimitEntry_t entry[16];
} rateLimitCfgParam_t;

typedef struct modeCfgParam_s
{
	uint32		Mode;
} modeCfgParam_t;


typedef struct ripCfgParam_s
{

	uint8		send_eth0;
	uint8		rcv_eth0;
	uint8		auth_eth0;
	char			pass_eth0[16];

	char			pass_eth1[16];
	uint8		send_eth1;
	uint8		rcv_eth1;
	uint8		auth_eth1;
	uint8		update_tr;
	uint8		timeout_tr;
	uint8		garbage_tr;
	uint16		resv;
#if defined(DNI)
	uint8		rip_dir;	/* 0: none, 1: only, 2:in only, 3:out only */
	uint8		rip_ver;	/* 0:disabled, 1: rip_1, 2: rip_2b, 3:rip_2m */
#endif
} ripCfgParam_t;


typedef struct pseudoVlanCfgParam_s
{
	uint8				enable;
	uint16				portVid[9];
	uint8 				rsv[1];
} pseudoVlanCfgParam_t;

typedef struct passthruCfgParam_s	/* Passthru Configuration */
{
	uint8	enabledPppoe;
	uint8	enabledDropUnknownPppoePADT;
	uint8	enabledIpv6;
	uint8	enabledIpx;
	uint8	enabledNetbios;
} passthruCfgParam_t;

typedef struct ipMulticastCfgParam_s	/* IP Multicast Configuration */
{
	uint8	enabledIpMulticast;
} ipMulticastCfgParam_t;

typedef struct ipsecGlobalCfgParam_s	/* IP Multicast Configuration */
{
	uint8	enableNatTraversal;
} ipsecGlobalCfgParam_t;



typedef struct ipsecConfigCfgParam_s	/* Ratio based QoS Configuration */
{
	uint8 enable;							/* 0: disable, 1: enable */
	uint8 encryption;
	uint8 authentication;
	uint8 pfs;

	uint32 localnet;
	uint32 remotegw;
	uint32 remotenet;
	uint32 ipsec_keylife;
	uint32 isakmp_keylife;
	uint8  secrets[80];
	
} ipsecConfigCfgParam_t;

typedef struct domainBlockCfgParam_s
{
	char domain[MAX_ALLOW_DOMAINNAME_LEN];
	ipaddr_t sip;
	ipaddr_t smask;
	uint8 enable;
} domainBlockCfgParam_t;

typedef struct romeCfgParam_s
{
	vlanCfgParam_t      vlanCfgParam[VLAN_LOAD_COUNT];
	ifCfgParam_t        ifCfgParam[MAX_IP_INTERFACE];
	routeCfgParam_t     routeCfgParam[MAX_ROUTE];
	arpCfgParam_t       arpCfgParam[MAX_STATIC_ARP];
	natCfgParam_t       natCfgParam;
	pppoeCfgParam_t     pppoeCfgParam[MAX_PPPOE_SESSION];
	dhcpsCfgParam_t     dhcpsCfgParam;
	dhcpcCfgParam_t     dhcpcCfgParam;
	dnsCfgParam_t       dnsCfgParam;
	mgmtCfgParam_t      mgmtCfgParam[MAX_MGMT_USER];
	aclGlobalCfgParam_t	aclGlobalCfgParam;
	aclCfgParam_t       aclCfgParam[MAX_PPPOE_SESSION][MAX_ACL];
	serverpCfgParam_t   serverpCfgParam[MAX_PPPOE_SESSION][MAX_SERVER_PORT];
	specialapCfgParam_t specialapCfgParam[MAX_PPPOE_SESSION][MAX_SPECIAL_AP];
	gamingCfgParam_t gamingCfgParam[MAX_PPPOE_SESSION][MAX_GAMING];
    dmzCfgParam_t       dmzCfgParam[MAX_PPPOE_SESSION];
	logCfgParam_t       logCfgParam[MAX_PPPOE_SESSION];
    upnpCfgParam_t      upnpCfgParam;
    //snmpCfgParam_t      snmpCfgParam;
    ddnsCfgParam_t      ddnsCfgParam;    
	tbldrvCfgParam_t    tbldrvCfgParam;
	urlfilterCfgParam_t	urlfilterCfgParam[MAX_PPPOE_SESSION][MAX_URL_FILTER];
	dosCfgParam_t		dosCfgParam[MAX_PPPOE_SESSION];
	naptCfgParam_t		naptCfgParam;
	timeCfgParam_t		timeCfgParam;	
	algCfgParam_t		algCfgParam[MAX_PPPOE_SESSION];
	//wlanCfgParam_t		wlanCfgParam[MAX_WLAN_CARDS];
	udpblockCfgParam_t	udpblockCfgParam[MAX_PPPOE_SESSION];	
	routingCfgParam_t	routingCfgParam[MAX_ROUTING];
	pptpCfgParam_t		pptpCfgParam;
	l2tpCfgParam_t		l2tpCfgParam;
	qosCfgParam_t		qosCfgParam[MAX_QOS];
	rateLimitCfgParam_t	rateLimitCfgParam;
	ratioQosCfgParam_t	ratioQosCfgParam;
	pbnatCfgParam_t		pbnatCfgParam[MAX_PPPOE_SESSION][MAX_PBNAT];
	pseudoVlanCfgParam_t pseudoVlanCfgParam;
	passthruCfgParam_t	passthruCfgParam;
	ipMulticastCfgParam_t	ipMulticastCfgParam;
	modeCfgParam_t		modeCfgParam;
	ripCfgParam_t			ripCfgParam;
	uint8				semaphore[MAX_USER_SEMAPHORE];	/* used by user level */
	domainBlockCfgParam_t	domainBlockCfgParam[MAX_DOMAIN_BLOCKING];
	//pptpServerCfgParam_t   pptpServerCfgParam;
	urlfilterTrustedUserCfgParam_t urlfilterTrustedUserCfgParam[URL_FILTER_MAX_TRUSTED_USERS];
#if defined(DNI) //Add by Timo Wu
	scheduleCfgParam_t	scheduleCfgParam;
	emailCfgParam_t		emailCfgParam;		
	telCfgParam_t		telCfgParam;
	BlankStateCfgParam_t	BlankStateCfgParam;
	mnuCfgParam_t		mnuCfgParam; //Yili 2006/1/10
	http_client_ifno_t	httpclientCfgParam;
	loader_info_t		loaderParam;	
#endif
#ifdef CONFIG_WAN_LAN_MATCH_DETECTION
	wanlan_match_det_t wanlan_ip_mat_det;
#endif 
//Added end
} romeCfgParam_t;



#endif /* _BOARD_H_ */
