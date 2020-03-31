/*
 * Copyright c                Realtek Semiconductor Corporation, 2003
 * All rights reserved.                                                    
 * 
 * $Header: /home/cvsroot/uClinux-dist/user/boa/src/rtl865x/rome_asp.c,v 1.54 2005/12/12 03:24:12 tony Exp $
 *
 * $Author: tony $
 *
 * Abstract:
 *
 *   rome_asp.c : rome_asp
 *
 * $Log: rome_asp.c,v $
 * Revision 1.54  2005/12/12 03:24:12  tony
 * +: new feature: support trusted user in url-filter.
 *
 * Revision 1.53  2005/12/09 06:21:28  rupert
 * +: Add IPSEC NAT Traversal Configuration
 *
 * Revision 1.52  2005/12/02 15:41:11  chenyl
 * *: circular buffer write protection by kernel mutex lock / unlock
 *
 * Revision 1.51  2005/12/02 10:04:46  chenyl
 * +: capture Log buffer's snapshot to user space memory under mutex lock/unlock protection.
 * *: shliu's new circ_msg write mechanism.
 *
 * Revision 1.50  2005/12/02 01:17:38  alva_zhang
 * +: add conditional support for MTD
 *
 * Revision 1.49  2005/11/30 13:05:20  tony
 * *: new features: support PPTP Server
 *
 * Revision 1.48  2005/11/30 12:56:09  chenyl
 * *: bug fix: we need to check if (buf == NULL) when doing
 *
 * Revision 1.47  2005/11/15 16:11:06  chenyl
 * +: ALG for TFTP (RFC 1350)
 *
 * Revision 1.46  2005/10/24 06:53:01  tony
 * *: support pppd-2.4.3 for MPPE/MPPC
 *
 * Revision 1.45  2005/10/05 09:54:53  chenyl
 * +: BOTH setting for WLAN 8185 WPA/WPA2 configurations
 * 	- support TKIP/AES clients simultaneously
 *
 * *: if the second WLAN interface is not installed, the 'Apply' 'Reset' button
 * 	in advance setting web-page still must be visitable.
 *
 * Revision 1.44  2005/10/04 15:33:31  jzchen
 * *: Configure ratio parameter when calling rtl8651_setAlgQosQueueId
 *
 * Revision 1.43  2005/09/30 13:00:11  chenyl
 * *: new item to reinit wlan interface from console
 *
 * Revision 1.42  2005/09/26 08:14:22  tony
 * +: add SNMP Daemon application.
 *
 * Revision 1.41  2005/09/13 13:02:17  chenyl
 * +: print something when RomeDrv CTRL message is gotten.
 *
 * Revision 1.40  2005/09/07 09:55:42  chenyl
 * +: set pure-sw forwarding via http-daemon
 *
 * Revision 1.39  2005/09/05 08:00:00  chenyl
 * +: WPA2 setting
 *
 * Revision 1.38  2005/08/17 08:55:19  chenyl
 * *: fix Firmware update bug
 *
 * Revision 1.37  2005/08/16 02:53:34  chenyl
 * *: fix typo error, for TCP/UDP ACLs, port use Lower/Upper bound instead of Mask,
 *    and we need to set Lower bound as 0 and Upper bound as 0xffff to allow any ports.
 *
 * Revision 1.36  2005/08/15 13:57:09  shliu
 * *: fix asp_qos error due to use "cvs update" wrongly.
 *
 * Revision 1.35  2005/08/04 06:48:32  shliu
 * *: modify ratelimit function to apply on d-cut
 *
 * Revision 1.34  2005/08/04 02:23:20  chenyl
 * *: remove CONFIG_RTL8185 compile flag in rome_asp.c's 'web-related code'
 *
 * Revision 1.33  2005/08/03 08:42:07  chenyl
 * *: modify some WLAN WEP/WPA code to fix bugs
 *
 * Revision 1.32  2005/07/29 12:42:33  chenyl
 * *: bug fix: init domain block when system init
 *
 * Revision 1.31  2005/07/29 09:44:00  chenyl
 * +: dns module in ROMEDRV
 * +: domain blocking (SDK + RomeDrv)
 *
 * Revision 1.30  2005/07/28 13:01:30  tony
 * *: bug fixed: Time Zone - in New York , add PPTP Server UI
 *
 * Revision 1.29  2005/07/28 02:18:40  chhuang
 * *: modify qos page
 *
 * Revision 1.28  2005/07/26 06:26:25  shliu
 * *: modify mode change web page handling
 *
 * Revision 1.27  2005/07/21 15:23:12  shliu
 * *: When user does not build zebra/ripd, the web page should not let user
 *    config ripd.
 *
 * Revision 1.26  2005/07/21 11:48:01  tony
 * *: bug fixed: for acl can't show page when submit.
 *
 * Revision 1.25  2005/07/19 08:48:13  tony
 * *** empty log message ***
 *
 * Revision 1.24  2005/07/11 07:23:23  shliu
 * *: add feature of remote pptp/l2tp setting.
 *
 * Revision 1.23  2005/07/06 12:02:36  tony
 * +: New Features: Gaming
 *
 * Revision 1.22  2005/06/29 05:22:19  chenyl
 * +: TLV based configuration setting.
 *
 * Revision 1.21  2005/06/28 06:38:59  tony
 * *: support remote log
 *
 * Revision 1.20  2005/06/24 02:30:10  tony
 * +: new features: mail alert
 *
 * Revision 1.19  2005/06/02 08:38:50  tony
 * +: support new wan type - Static USB-ETHERNET
 *
 * Revision 1.18  2005/06/01 08:12:01  tony
 * *: support 3g/gprs path, webcam tp6800
 *
 * Revision 1.17  2005/05/31 04:40:30  chenyl
 * *: bug fix: 8185 driver Rx MP test bug
 * +: 8185 driver MP - Tx continuously test can be stopped by keying-in anything.
 * *: bug fix: 8185 driver in AP/B+G mode, client with pure Mode B will fail to connect to GW.
 *
 * Revision 1.16  2005/05/27 11:40:58  yjlou
 * *: merge the 'rtl_image.h' file of loader and boa.
 * *: fixed the bug of Web page that cannot update CRAMFS and SQUASHFS.
 *
 * Revision 1.15  2005/05/26 05:24:52  shliu
 * *: asp_modeConfig: change form method from "GET" to "POST".
 *
 * Revision 1.14  2005/05/25 11:10:40  shliu
 * *: Function naming error.
 *
 * Revision 1.13  2005/05/16 06:09:14  shliu
 * *: Change wan type without rebooting.
 *
 * Revision 1.12  2005/05/11 09:37:53  shliu
 * *: Web changes in router/bridge mode.
 *
 * Revision 1.11  2005/05/09 05:05:46  shliu
 * *: Modify asp_setModeConfig() function a bit.
 *
 * Revision 1.10  2005/05/06 10:49:12  chenyl
 * *: modify wlan-set mechanism for more stable configuration
 *
 * Revision 1.9  2005/05/06 07:36:25  tony
 * *:bug fixed: support PAP,CHAP auth mode for DHCPL2TP wan type.
 *
 * Revision 1.8  2005/05/06 05:07:41  tony
 * *: bug fixed: support PAP,CHAP auth mode by UI.
 *
 * Revision 1.7  2005/05/04 02:33:38  shliu
 * *: add mode selection fucntion.
 *
 * Revision 1.6  2005/04/28 10:20:20  chhuang
 * *: bug fixed for compiler error
 *
 * Revision 1.5  2005/04/25 12:04:38  chenyl
 * *: copy configuration to system-config before restart dhcp server
 *
 * Revision 1.4  2005/04/20 02:18:12  chenyl
 * *: always turn-off all WDS interfaces before setting WLAN stuff.
 *
 * Revision 1.3  2005/04/19 14:11:39  tony
 * *: bug fixed: support "finial countdown page" in boa web server.
 *
 * Revision 1.2  2005/04/19 08:35:57  tony
 * *:remove debug message
 *
 * Revision 1.1  2005/04/19 04:58:15  tony
 * +: BOA web server initial version.
 *
 * Revision 1.256  2005/04/11 09:00:03  tony
 * *: starcraft support multi-user.
 *
 * Revision 1.255  2005/04/08 02:48:33  cfliu
 * *** empty log message ***
 *
 * Revision 1.254  2005/03/31 17:09:29  chenyl
 * +: completely process firmware update.
 *
 * Revision 1.253  2005/03/31 12:50:56  chenyl
 * +: check correctness (size, checksum, magic number) before updating firmware.
 *
 * Revision 1.252  2005/03/29 08:28:03  shliu
 * *: Modify RIP page.
 *
 * Revision 1.251  2005/03/09 08:43:57  chenyl
 * +: for the new default ACL action: RTL8651_ACL_L34_DROP
 *
 * Revision 1.250  2005/03/08 15:26:50  shliu
 * *: Hanging up the unnumbered PPPoE, changing configuration
 *    and then dialing up will cause problems.
 *    Try to fix this problem.
 *
 * Revision 1.249  2005/03/01 12:51:10  tony
 * *: fix bug for pptp/ipsec set.
 *
 * Revision 1.248  2005/03/01 09:13:01  tony
 * *: support PPTP/IPSEC ALG config dividedly.
 *
 * Revision 1.247  2005/02/25 05:37:06  cfliu
 * add WDS support
 *
 * Revision 1.246  2005/02/23 14:36:22  yjlou
 * +: add flashdrv_isLoaderOverwritten() to avoid loader crash.
 *
 * Revision 1.245  2005/02/22 02:28:14  rupert
 * +: Add AES encryption
 *
 * Revision 1.244  2005/02/17 09:59:40  cfliu
 * +:Modify board.c, board.h, rome_Asp.c to support 8185 AP client mode
 *
 * Revision 1.243  2005/02/16 13:26:13  tony
 * +: support IPSec Pass-through NAT-T mode.
 *
 * Revision 1.242  2005/02/16 01:57:26  chenyl
 * *: disable RTL8651B_CUT_C : disable RTL865xB C-Version Chip support.
 *
 * Revision 1.241  2005/02/02 11:00:17  tony
 * +: add crontab ACL scheduling.
 *
 * Revision 1.240  2005/01/26 06:00:59  tony
 * +: add new features: SDK support BitTorrent download!
 *
 * Revision 1.239  2005/01/25 15:07:28  ghhuang
 * +: Support 100us Ratelimit Refill Timer & Port-based 64M Bandwidth Control
 *
 * Revision 1.238  2005/01/20 11:56:48  ghhuang
 * *: Update DMZ web interface
 *
 * Revision 1.237  2005/01/20 10:52:00  ghhuang
 * *: Modify web interface of Diffserv DSCP remarking
 *
 * Revision 1.236  2005/01/20 08:11:33  shliu
 * *: Multiple DMZ-host added
 *
 * Revision 1.235  2005/01/19 10:33:47  ghhuang
 * *: DMZ web interface modification
 *
 * Revision 1.234  2005/01/19 09:38:17  ghhuang
 * *: DMZ web interface modification & ratioQosCfgParam_t initial values modification
 *
 * Revision 1.233  2005/01/19 09:05:57  shliu
 * *** empty log message ***
 *
 * Revision 1.232  2005/01/19 06:52:13  shliu
 * *** empty log message ***
 *
 * Revision 1.231  2005/01/18 13:33:37  ghhuang
 * *: Replace Diffserv API
 *
 * Revision 1.230  2005/01/18 08:50:22  ghhuang
 * +: Diffserv (DSCP) remarking support
 *
 * Revision 1.229  2005/01/11 03:22:55  ghhuang
 * *:MNQ bug fix - Correct ACL undeletion
 *
 * Revision 1.228  2005/01/09 08:57:07  cfliu
 * +: Update UI config for dual band/card.
 *
 * Revision 1.227  2005/01/03 01:32:12  rupert
 * +: IPSEC WEB access
 *
 * Revision 1.226  2004/12/28 09:50:48  rupert
 * +: Add IPSEC Support
 *
 * Revision 1.225  2004/12/22 05:19:35  tony
 * +: support new features: make ALG(FTP,SIP,NetMeeting) support MNQueue.
 *
 * Revision 1.224  2004/12/14 09:48:10  chenyl
 * +: NAPT-Connection Control system
 * *: add "NAPT-AddFail" error messages into ignore case.
 *
 * Revision 1.223  2004/12/06 10:51:09  ghhuang
 * Multiple ACL entries can refer to one rate limit entry
 *
 * Revision 1.222  2004/12/02 03:08:38  yjlou
 * +: support IPX/Netbios Passthru function
 *
 * Revision 1.221  2004/11/30 04:56:52  cfliu
 * +: Add new ASP functions for new wireless driver
 *
 * Revision 1.220  2004/11/18 08:05:22  shliu
 * *** empty log message ***
 *
 * Revision 1.219  2004/11/16 02:30:30  shliu
 * *** empty log message ***
 *
 * Revision 1.218  2004/11/12 07:46:45  chhuang
 * *: bug fixed: when diabled port based qos, set flow control to enable
 *
 * Revision 1.217  2004/11/10 05:34:30  cfliu
 * +: modify WLAN UI and use 8185 MP calibration param in flash to set Txpower and rx/tx chargepump
 * +: enable dual antenna and diversity ctrl
 *
 * Revision 1.216  2004/11/05 01:43:50  yjlou
 * *: fixed minor compile problem when not defined CONFIG_RTL8185.
 *
 * Revision 1.215  2004/10/29 09:44:51  cfliu
 * +add wlan client list function
 *
 * Revision 1.214  2004/10/22 11:56:13  cfliu
 * *: Default WEP key should be key0 not key1
 *
 * Revision 1.213  2004/10/21 11:47:57  chenyl
 * +: web-based icmp/l4proto DMZ forward setting
 *
 * Revision 1.212  2004/10/13 13:35:44  chenyl
 * +: domain setting of DHCP Server
 * +: real-DNS-server setting of DHCP Server
 *
 * Revision 1.211  2004/10/11 10:28:40  yjlou
 * *: fixed the bug of redirect to error page when restart system from remote management.
 *
 * Revision 1.210  2004/10/11 04:50:48  yjlou
 * +: add rtl8651_enableDropUnknownPppoePADT()
 *
 * Revision 1.209  2004/10/07 10:19:39  chenyl
 * *: bug fix: variable assignment error
 *
 * Revision 1.208  2004/10/06 14:08:03  chenyl
 * +: dhcp-server wins setting and broadcast to client
 *
 * Revision 1.207  2004/10/05 09:20:42  chenyl
 * +: web page to turn ON/OFF ip-multicast system
 *
 * Revision 1.206  2004/10/04 09:27:41  cfliu
 * add webpage change for wireless
 *
 * Revision 1.205  2004/10/01 07:55:04  jzchen
 * *: Port configuration extend to MII port setting
 *
 * Revision 1.204  2004/10/01 07:52:55  yjlou
 * +: add enable/disable PPPoE Passthru and IPv6 Passthru
 *
 * Revision 1.203  2004/09/24 05:21:48  chenyl
 * *: in multi-session pppoe, the "checked" WAN type will be set to "pppoe"
 *
 * Revision 1.202  2004/09/22 09:48:03  tony
 * *: fix bug for software PPTP pass-through
 *
 * Revision 1.201  2004/09/16 13:30:13  tony
 * *: add pptp softeare solution
 *
 * Revision 1.200  2004/09/14 13:49:15  chhuang
 * *: allow mtu to be set to 1460 for PPTP
 *
 * Revision 1.199  2004/09/03 03:00:10  chhuang
 * +: add new feature: pseudo VLAN
 *
 * Revision 1.198  2004/08/24 04:09:29  yjlou
 * +: add Loader Version option in menuconfig. Runtime code also supports old-fashion loader now.
 *
 * Revision 1.197  2004/08/23 07:16:01  yjlou
 * *: The type of communication section has changed from "function pointer" to "string".
 *
 * Revision 1.196  2004/08/20 12:24:01  cfliu
 * *** empty log message ***
 *
 * Revision 1.195  2004/08/20 12:16:33  cfliu
 * +: Add WDS support webpage
 *
 * Revision 1.194  2004/08/18 05:39:59  chenyl
 * +: napt special option web-based setting
 *
 * Revision 1.193  2004/08/13 06:02:51  cfliu
 * +: Rewrite WLAN pages for RTL8185
 *
 * Revision 1.192  2004/08/11 07:28:22  tony
 * +: new features: support quickcam web camera.
 *
 * Revision 1.191  2004/08/04 14:51:18  yjlou
 * +: support booting from single 8MB/16MB flash (_SUPPORT_LARGE_FLASH_)
 *
 * Revision 1.190  2004/07/27 13:38:29  tony
 * *: make pppoe support hang up when connecting...
 *
 * Revision 1.189  2004/07/27 07:23:52  chenyl
 * +: DoS ignore type setting
 *
 * Revision 1.188  2004/07/23 09:29:14  cfliu
 * +: Add WLAN access control webpage
 *
 * Revision 1.187  2004/07/21 12:46:18  tony
 * +: add new features: PPTP Pass-through support server in mode.
 *
 * Revision 1.186  2004/07/18 11:27:10  chhuang
 * *: modify M-N-1 Queue's web page
 *
 * Revision 1.185  2004/07/16 11:47:20  tony
 * *: make PPTP/L2TP redial usable.
 *
 * Revision 1.184  2004/07/15 13:16:01  cfliu
 * +: Update Webpage message
 *
 * Revision 1.183  2004/07/14 14:27:31  chenyl
 * *: modify interface
 *
 * Revision 1.182  2004/07/14 13:55:59  chenyl
 * +: web page for MN queue
 *
 * Revision 1.181  2004/07/12 11:22:21  cfliu
 * +:Update Webpage messages
 *
 * Revision 1.180  2004/07/12 07:35:32  chhuang
 * *: modify rate limit web page
 *
 * Revision 1.179  2004/07/12 07:03:47  tony
 * +: add wan type dhcpl2tp.
 *
 * Revision 1.178  2004/07/12 05:56:31  cfliu
 * *: correct OFDM set error
 *
 * Revision 1.177  2004/07/12 04:25:36  chenyl
 * *: extend existing port scan mechanism
 *
 * Revision 1.176  2004/07/11 11:28:54  cfliu
 * +: Update WDS and Wireless access control webpage
 *
 * Revision 1.175  2004/07/08 10:51:41  tony
 * *: change ipUp routine to new arch.
 *
 * Revision 1.174  2004/07/07 05:56:39  tony
 * *: fix tabid bug.
 *
 * Revision 1.173  2004/07/07 05:12:36  chhuang
 * +: add a new WAN type (DHCP+L2TP). But not complete yet!!
 *
 * Revision 1.172  2004/07/06 06:20:12  chhuang
 * +: add rate limit
 *
 * Revision 1.171  2004/07/05 11:58:44  tony
 * *: modify UI control for UPNPD.
 *
 * Revision 1.170  2004/07/05 03:39:38  jzchen
 * +: New bandwidth control may configured fail due to rate range limitaion, must check the configure success and then new setting can be accepted
 * +: Extend port bandwidth control range to 16M and 32M
 *
 * Revision 1.169  2004/07/02 10:30:08  chenyl
 * *: bug fix: per-source Flooding check bug (counter error)
 * *: bug fix: ip-spoofing ACL add function error
 * *: bug fix: ICMP ping-of-death : threshold from 65500 to 65535 (follows cisco)
 * *: bug fix: item name change of DOS check: UDP Bomb -> UDP EchoChargen (follows cisco)
 * +: new feature: New DoS check item, UDP Bomb
 * 		- Triggered if (Length of UDP header) < (Length of IP header)
 * 		- allow (Length of UDP header) > (Length of IP header)
 * 		- follows cisco
 *
 * Revision 1.168  2004/06/29 16:16:06  cfliu
 * +: define USERAPP_NOMMU only when MMU is not enabled
 *
 * Revision 1.167  2004/06/29 09:42:31  cfliu
 * +: Add auto probe WLAN card mechanism.
 *
 * Revision 1.166  2004/06/29 03:38:34  yjlou
 * *: fixed the bug of free-style flash editor: support multi-block update.
 *
 * Revision 1.165  2004/06/28 13:57:34  yjlou
 * +: support Free-style flash editor
 *
 * Revision 1.164  2004/06/18 08:11:33  tony
 * +: add new features: SYN,FIN,ACK Port Scan.
 *
 * Revision 1.163  2004/06/16 04:42:18  tony
 * *: support reboot and get loader version for MMU.
 *
 * Revision 1.162  2004/06/15 13:06:02  tony
 * *: fix log bug, for mmu model.
 *
 * Revision 1.161  2004/06/15 10:08:46  tony
 * *: using share memory instead of direct access in syslog.
 *
 * Revision 1.160  2004/06/14 06:15:24  chenyl
 * +: USERAPP_NOMMU for upnp application
 * +: _UPNP_MM_ for upnp memory management
 *
 * Revision 1.159  2004/06/11 10:53:59  cfliu
 * +: Add Cable Meter and Interface counter webpage
 *
 * Revision 1.158  2004/06/11 02:06:45  cfliu
 * +: Add NAT throughput webpage
 *
 * Revision 1.157  2004/06/11 00:44:48  cfliu
 * +: Add port ON/Off webpage
 *
 * Revision 1.156  2004/06/10 14:36:03  cfliu
 * +: Add port config webpage
 *
 * Revision 1.155  2004/06/10 10:34:52  tony
 * +: add PPTP dial status: disconnecting, make redial function correct.
 *
 * Revision 1.154  2004/06/10 02:20:21  tony
 * +: add compiler flag for pptp/l2tp.
 *
 * Revision 1.153  2004/06/09 12:32:16  tony
 * +: add PPTP/L2TP UI page.(Dial and Hang_Up).
 *
 * Revision 1.152  2004/06/08 10:57:20  cfliu
 * +: Add WLAN dual mode webpages. Not yet completed...
 *
 * Revision 1.151  2004/06/02 12:51:46  tony
 * make PPPoE/L2TP is able to run multi-times in single process.
 * and fix pppoe can't run dial-on-demand problem.
 *
 * Revision 1.150  2004/05/28 09:49:16  yjlou
 * +: support Protocol-Based NAT
 *
 * Revision 1.149  2004/05/27 05:19:17  cfliu
 * update WLAN setting command
 *
 * Revision 1.148  2004/05/27 05:12:36  tony
 * fix multiple pppoe dial problem.
 *
 * Revision 1.147  2004/05/26 13:25:31  tony
 * fix pppd idle timeout bug.(for new pppd)
 *
 * Revision 1.146  2004/05/26 10:11:55  tony
 * make pppoe daemon always run at the same process.
 *
 * Revision 1.145  2004/05/24 02:19:58  chhuang
 * bug fixed for url-filtering
 *
 * Revision 1.144  2004/05/22 03:21:58  chenyl
 * * bug fix of web page setting/initial setting
 *
 * Revision 1.143  2004/05/21 12:08:50  chenyl
 * *: TCP/UDP/ICMP spoof -> check for (sip) == (dip)
 * *: modify DOS prevention webpage
 *
 * Revision 1.142  2004/05/20 08:43:55  chhuang
 * add Web Page for QoS
 *
 * Revision 1.141  2004/05/19 08:42:10  orlando
 * init button related change
 *
 * Revision 1.140  2004/05/19 06:25:26  cfliu
 * Highlight ASIC hardware features.
 *
 * Revision 1.139  2004/05/17 12:17:28  cfliu
 * Add AC Name field
 *
 * Revision 1.138  2004/05/17 07:22:17  tony
 * fix pppoe silent timeout bug and make PPTP/L2TP support silent timeout.
 *
 * Revision 1.137  2004/05/14 10:39:32  chenyl
 * *: fix bugs of system log
 *
 * Revision 1.136  2004/05/13 13:27:01  yjlou
 * +: loader version is migrated to "00.00.07".
 * +: new architecture for INTEL flash (code is NOT verified).
 * *: FLASH_BASE is decided by IS_REV_A()
 * -: remove flash_map.h (content moved to flashdrv.h)
 * -: remove un-necessary calling setIlev()
 *
 * Revision 1.135  2004/05/12 08:09:56  chhuang
 * +: dhcp static binding
 *
 * Revision 1.134  2004/05/12 07:20:15  chenyl
 * +: source ip blocking
 * *: modify dos mechanism
 *
 * Revision 1.133  2004/05/12 05:15:05  tony
 * support PPTP/L2TP in RTL865XB.
 *
 * Revision 1.132  2004/05/10 05:50:19  chhuang
 * 1: add src ip blocking for url-filtering
 * 2: bug fixed for logging
 *
 * Revision 1.131  2004/05/05 08:27:07  tony
 * new features: add remote management spec
 *
 * Revision 1.130  2004/04/13 08:25:02  tony
 * set the limit MTU size in PPTP/L2TP mode is 1452.
 *
 * Revision 1.129  2004/04/08 13:18:12  tony
 * add PPTP/L2TP routine for MII lookback port.
 *
 * Revision 1.128  2004/04/08 12:29:39  cfliu
 * Add WDS support on extension port API
 *
 * Revision 1.127  2004/03/31 01:59:36  tony
 * add L2TP wan type UI pages.
 *
 * Revision 1.126  2004/03/21 07:32:00  cfliu
 * no message
 *
 * Revision 1.125  2004/03/19 09:51:18  tony
 * make the 'lan permit' acl is able to select by user.
 *
 * Revision 1.124  2004/03/12 08:23:22  tony
 * add new ALGs.
 *
 * Revision 1.123  2004/03/03 03:43:32  tony
 * add static routing table in turnkey.
 *
 * Revision 1.122  2004/02/27 05:14:11  tony
 * fix ACL bug: when set IP to 0.0.0.0 and port=0, ACL will drop all packets which go to external interface.
 *
 * Revision 1.121  2004/02/11 08:49:19  tony
 * modify UI: when LAN Type is Unnumbered IP, turn Destination Network off.
 *
 * Revision 1.120  2004/02/06 11:42:35  tony
 * fix bug: mIRC don't list in ALG UI.
 *
 * Revision 1.119  2004/02/05 07:11:16  tony
 * add acl filter field: IP.
 *
 * Revision 1.118  2004/02/04 08:35:52  tony
 * add field Unnumbered IP Address , Unnumbered Network Mask  in multiple pppoe mode.
 *
 * Revision 1.117  2004/02/04 06:23:49  rupert
 * Add UDP Block Support
 *
 * Revision 1.116  2004/02/04 02:30:50  tony
 * when addDmzHost failed, disable the function in UI.
 *
 * Revision 1.115  2004/02/04 02:10:30  tony
 * fix bug: lanType only be used in multiple pppoe mode.
 *
 * Revision 1.114  2004/02/03 09:17:33  tony
 * add field "LAN Type" in multiple PPPoE.
 *
 * Revision 1.113  2004/02/03 08:14:34  tony
 * add UDP Blocking web UI configuration.
 *
 * Revision 1.112  2004/01/30 12:03:05  tony
 * make Special Application is able to support multiple session.
 *
 * Revision 1.111  2004/01/30 02:53:09  orlando
 * turnon setDosThreshold() in asp_setDos()
 *
 * Revision 1.110  2004/01/29 10:56:08  orlando
 * turnon dos related settings
 *
 * Revision 1.109  2004/01/29 09:46:33  tony
 * modify serverp_tableDriverAccess(), make it support multiple session.
 * add protocol type in server port UI.
 *
 * Revision 1.108  2004/01/28 07:58:52  tony
 * add ICUII ALG.
 *
 * Revision 1.107  2004/01/16 12:16:46  tony
 * modify ALG cfg params and web UI,
 * rearrange rtl8651a_setAlgStatus() must called after rtl8651_addIpIntf()
 *
 * Revision 1.106  2004/01/14 03:37:18  tony
 * Support single session in rtl8651_setAlgStatus (for old user)
 *
 * Revision 1.105  2004/01/14 02:48:40  hiwu
 * add PPTP configuration
 *
 * Revision 1.104  2004/01/12 09:49:27  orlando
 * update asp_setUrlFilter()
 *
 * Revision 1.103  2004/01/09 09:03:24  tony
 * change rtl8651_add(del)DmzHost  to rtl8651a_add(del)DmzHost
 *
 * Revision 1.102  2004/01/09 08:59:57  tony
 * change define
 *
 * Revision 1.101  2004/01/09 08:03:55  tony
 * make the code architecture of ALG is able to support multiple dial session.
 *
 * Revision 1.100  2004/01/08 13:26:02  orlando
 * url/dos/log related changes
 *
 * Revision 1.99  2004/01/08 12:13:44  tony
 * add Port Range into Server Port.
 * support Server Port for multiple session UI.
 *
 * Revision 1.98  2004/01/08 07:23:21  tony
 * support multiple session UI for ACL, URL Filter, DoS log.
 *
 * Revision 1.97  2004/01/07 10:59:56  tony
 * Support multiple session UI plugin for ACL.
 *
 * Revision 1.96  2004/01/07 09:10:04  tony
 * add PPTP Client UI in Config Wizard.
 *
 * Revision 1.95  2004/01/07 07:36:36  tony
 * Support multiple session UI plugin for ALG.
 *
 * Revision 1.92  2004/01/06 13:50:25  tony
 * Support multiple session UI plugin for the following functions:
 * DMZ, URL Filter, Dos Prevention
 *
 * Revision 1.91  2003/12/19 07:56:46  tony
 * make "Wireless Security Setup" support interactive web page.
 *
 * Revision 1.90  2003/12/19 05:03:49  tony
 * Should allow only 578-1492 in mtu field.
 *
 * Revision 1.89  2003/12/19 04:33:01  tony
 * add Wireless Lan config pages: Basic Setting, Advance Setting, Security, Access Control, WDS
 *
 * Revision 1.88  2003/12/17 08:29:08  tony
 * add "parse_ipRange()" fucntion.
 *
 * Revision 1.87  2003/12/15 01:55:51  tony
 * fix bug: MTU will set to 150 when config by wizard.
 *
 * Revision 1.86  2003/12/12 01:34:54  tony
 * add NAPT toggle in Unnumbered PPPoE.
 *
 * Revision 1.85  2003/12/10 03:08:58  tony
 * make logging function support time zone in kernel space.
 *
 * Revision 1.84  2003/12/09 13:44:34  tony
 * add ACL,DoS,URL Filter logging function in kernel space.
 *
 * Revision 1.83  2003/12/09 03:05:44  tony
 * add a param in rtl8651_setPppoeMtu function.
 *
 * Revision 1.82  2003/12/09 02:06:18  tony
 * enable mtu configure in each session
 *
 * Revision 1.81  2003/12/08 13:56:52  tony
 * add new ALG: support SIP protocol (for single session)
 *
 * Revision 1.80  2003/12/08 03:37:26  tony
 * add new ALG: L2TP v2 multiple-session
 *
 * Revision 1.79  2003/12/02 12:30:45  tony
 * the common.h is replace by rtl8651_dos.h and rtl8651_alg_init.h
 *
 * Revision 1.78  2003/12/02 10:24:47  tony
 * Add Routine: support DoS is able to set threshold by user(Webs GUI).
 *
 * Revision 1.77  2003/12/02 09:29:15  tony
 * rename alg.h to common.h(used for RomeDrvier and Turnkey)
 *
 * Revision 1.76  2003/12/01 12:35:52  tony
 * make ALG is able to be configured by users(Web GUI).
 *
 * Revision 1.75  2003/11/27 03:26:57  tony
 * fix bug:if default session is changed, old route table will can't delete correctly.
 * must del old route before setting new default session.
 *
 * Revision 1.74  2003/11/21 02:41:17  tony
 * add check function when un-checked dial-on-demand in PPPoE.
 *
 * Revision 1.73  2003/11/19 03:52:09  tony
 * modify unnumbered pppoe netmask gui.
 *
 * Revision 1.72  2003/11/18 09:04:47  tony
 * add routine: support mtu configure by user in pppoe.
 *
 * Revision 1.71  2003/11/18 04:30:48  tony
 * add PPPoE GUI input check
 *
 * Revision 1.70  2003/11/17 03:21:30  tony
 * small change
 *
 * Revision 1.69  2003/11/17 03:17:30  tony
 * support circular buffer in Eventlog (16k buffer)
 *
 * Revision 1.68  2003/11/14 10:40:01  rupert
 * add dhcp client list
 *
 * Revision 1.67  2003/11/14 09:13:36  tony
 * modify multiple pppoe web page
 *
 * Revision 1.66  2003/11/13 13:33:58  tony
 * pppoe: automaic Hang up all the connections after save.
 *
 * Revision 1.65  2003/11/13 12:52:06  tony
 * add MTU and MRU field in pppoe.
 *
 * Revision 1.64  2003/11/12 03:32:26  tony
 * fix bug: PPPoE can't dial
 *
 * Revision 1.63  2003/11/10 13:49:36  tony
 * fix multi-pppoe bugs:
 * 1:dialState set to zero when boot.
 * 2:disable Dial-on-Demand and Silent Timeout.
 * 3:must hang up all the connection before save configuration.
 * 4:only default session dial-on when boot.
 *
 * Revision 1.62  2003/11/07 11:05:59  rupert
 * for multiple pppoe
 *
 * Revision 1.61  2003/11/07 06:31:22  tony
 * add type PPPOECFGPARAM_DESTNETTYPE_NONE in MultiPPPoE dest network.
 *
 * Revision 1.60  2003/11/07 05:34:36  tony
 * modify YMSG ALG, it'll not have to cooperate with trigger port.
 *
 * Revision 1.59  2003/11/06 13:50:21  tony
 * add parse_ipNet parse_portRange functions
 *
 * Revision 1.58  2003/11/06 12:42:00  tony
 * fix bug in asp_setPppoe
 *
 * Revision 1.57  2003/11/06 02:25:08  tony
 * add field in multi-pppoe cfg.
 *
 * Revision 1.56  2003/10/29 10:20:41  tony
 * modify acl policy list.
 *
 * Revision 1.55  2003/10/29 01:48:24  tony
 * fix trigger port bug: when ouside host send a SYN to internal computer,
 * gateway return a RST packet problem.
 *
 * Revision 1.54  2003/10/24 10:25:58  tony
 * add DoS attack interactive webpage,
 * FwdEngine is able to get WAN status by rtl8651_wanStatus(0:disconnect,1:connect)
 *
 * Revision 1.53  2003/10/21 08:07:02  tony
 * add DoS attack log routine
 *
 * Revision 1.52  2003/10/16 09:23:30  tony
 * add check/uncheck all in acl page
 *
 * Revision 1.51  2003/10/16 05:12:41  tony
 * check Makefile param "MULTIPLE_PPPOE_SUPPORT" in Config Wizard
 *
 * Revision 1.50  2003/10/16 03:43:49  tony
 * add routine: check Makefile flag "MULTIPLE_PPPOE_SUPPORT"
 *
 * Revision 1.49  2003/10/15 13:58:36  tony
 * fix bug: mutliple pppoe default session status error when pppoe disconnect
 *
 * Revision 1.48  2003/10/14 13:11:56  tony
 * modify trigger port overlap checking function
 *
 * Revision 1.47  2003/10/14 12:46:05  tony
 * modify trigger port overlap checking function
 *
 * Revision 1.46  2003/10/14 08:38:15  tony
 * add RomeDriver version information
 *
 * Revision 1.45  2003/10/14 08:15:01  tony
 * add user account management routine
 *
 * Revision 1.44  2003/10/14 03:37:16  tony
 * fix small bug
 *
 * Revision 1.43  2003/10/14 03:24:42  tony
 * add Trigger port range overlap checking.
 *
 * Revision 1.42  2003/10/14 02:28:30  tony
 * add trigger port routine
 *
 * Revision 1.41  2003/10/09 13:23:44  tony
 * TRIGGER_PORT: add function rtl8651_flushTriggerPortRules,rtl8651_addTriggerPortRule
 *
 * Revision 1.40  2003/10/07 06:18:17  rupert
 * servie name
 *
 * Revision 1.39  2003/10/03 12:27:35  tony
 * add NTP time sync routine in management web page.
 *
 * Revision 1.38  2003/10/03 03:08:15  rupert
 * fix upload firmware
 *
 * Revision 1.37  2003/10/03 02:50:34  rupert
 * update filename
 *
 * Revision 1.36  2003/10/03 02:36:10  rupert
 * add upload firmware function
 *
 * Revision 1.35  2003/10/03 02:32:18  tony
 * change interactive messages in PPPoE.
 *
 * Revision 1.34  2003/10/03 01:26:42  tony
 * add ServiceName field in pppoeCfgParam_t.
 * add dynamic check in PPPoE/Unnumbered PPPoE/Multiple PPPoE web page.
 *
 * Revision 1.33  2003/10/02 10:50:03  tony
 * add ping routine in webpage.
 *
 * Revision 1.32  2003/10/02 07:53:49  orlando
 * asp_setPppoe() will pass valid argument to pppd_stop() now
 *
 * Revision 1.31  2003/10/02 02:16:43  tony
 * let wizard can show original wan setting in static mode.
 *
 * Revision 1.30  2003/10/01 13:25:49  tony
 * fix connection type can't change in wizard.
 *
 * Revision 1.29  2003/10/01 12:25:53  tony
 * solve all the compiler warnning messages in rome_asp.c
 *
 * Revision 1.28  2003/10/01 09:41:32  orlando
 * check in dial-on-demand and silent timeout related code
 *
 * Revision 1.27  2003/10/01 09:05:18  tony
 * debug: user set to static mode in wizard, all the wan data will be cleared when connection type is dhcpc.
 *
 * Revision 1.26  2003/10/01 07:48:06  orlando
 * modify asp_setpppoe to set pppoeCfgParam[].dialState to ..._DIALED_TRYING before
 * calling /bin/pppd
 *
 * Revision 1.25  2003/10/01 05:57:31  tony
 * add URL Filter routine
 *
 * Revision 1.24  2003/09/30 12:19:49  tony
 * arrange board_ipUpEventTableDriverAccess(), let upnp,ddns,dmz be able to start after dhcpc/pppoe started.
 *
 * Revision 1.23  2003/09/30 09:57:38  tony
 * make dmz support multiple conntion types.
 *
 * Revision 1.22  2003/09/30 09:46:38  tony
 * add dmz_tableDriverAccess()
 *
 * Revision 1.21  2003/09/30 08:56:29  tony
 * remove newServerpCfgParam[] from flash, rename ram PPPoeCfg to ramPppoeCfgParam
 *
 * Revision 1.20  2003/09/30 02:14:55  tony
 * small change in ddns
 *
 * Revision 1.19  2003/09/29 13:28:19  rupert
 * add primary and secondary fields of ifCfgParam_s
 *
 * Revision 1.18  2003/09/29 12:58:34  tony
 * add DDNS start/stop routine.
 *
 * Revision 1.17  2003/09/29 08:57:32  tony
 * add routine: when pppoe config changed, the dial function will be disabled.
 * add routine: dhcps is able to start/stop server on runtime.
 *
 * Revision 1.16  2003/09/29 03:13:23  tony
 * debug - view dhcps webpage crash when dhcps didn't start.
 *
 * Revision 1.15  2003/09/26 12:06:15  tony
 * modify pppoe Dial/Hang_Up routine
 *
 * Revision 1.14  2003/09/26 10:23:52  tony
 * add PPPoE dial,hang-up routine
 *
 * Revision 1.13  2003/09/26 08:43:17  tony
 * update Status Web Page
 *
 * Revision 1.12  2003/09/26 04:41:25  tony
 * modify Wizard page, support pppoe, unnumbered pppoe
 *
 * Revision 1.11  2003/09/26 02:09:48  tony
 * add/del UPnP default route in upnp_init() and asp_setUpnp()
 *
 * Revision 1.10  2003/09/25 10:44:50  tony
 * small change
 *
 * Revision 1.9  2003/09/25 10:14:50  tony
 * modify pppoe webpage, support unnumbered PPPoE, PPPoE, Multiple PPPoE.
 *
 * Revision 1.8  2003/09/25 06:54:00  tony
 * changae dhcpc lease list page
 *
 * Revision 1.7  2003/09/25 02:15:32  orlando
 * Big Change
 *
 * Revision 1.5  2003/09/23 11:44:33  tony
 * add UPNP daemon start/stop routine.
 *
 * Revision 1.4  2003/09/23 07:27:51  tony
 * modify all form action name.
 *
 * Revision 1.3  2003/09/23 07:13:18  tony
 * rename all webpage asp function
 *
 * Revision 1.2  2003/09/23 05:31:17  tony
 * move common.c to rome_asp.c
 *
 * Revision 1.1  2003/09/23 03:46:21  tony
 * move ASP page from net_asp.c,cfgmgr.c to rome_asp.c
 *
 * Revision 1.8  2003/09/22 08:01:45  tony
 * add UPnP Web Configuration Function Routine
 *
 * Revision 1.7  2003/09/22 06:33:37  tony
 * add syslogd process start/stop by CGI.
 * add eventlog download/clear routine.
 *
 * Revision 1.6  2003/09/19 09:06:38  tony
 * add special application webpage
 *
 * Revision 1.5  2003/09/19 06:06:51  tony
 * *** empty log message ***
 *
 * Revision 1.4  2003/09/19 01:43:50  tony
 * add dmz routine
 *
 * Revision 1.3  2003/09/18 05:07:40  tony
 * add event log webpage
 *
 *
 */

#include "rtl_types.h"
#include "rtl_flashdrv.h"
#include "flashdrv.h"
//#include "rtl_cfgmgr.h"
//#include "rtl_board.h"
#include <sys/types.h>
#include <sys/stat.h>

#include <stdio.h>
//#include <wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <net/if_arp.h>
#include <time.h>
#include <linux/if_ether.h>
#include <linux/config.h>
#include <net/route.h>
#include <re865x.h>
#include <version.h>
//#include "../wsIntrn.h"
#include "rtl_image.h"
//#include <signal.h>
#include "rtl_cfgmgr.h"
#include "rtl_board.h"
#include <rtl8651_tblDrv.h>
#include <rtl8651_tblDrvFwd.h>
#include <rtl8651_alg_init.h>
#include <rtl8651_dos.h>
#include <sys/shm.h>
#include <dirent.h> //for file search
//#include "../../../bittorrent/bt.h"
#include <config/autoconf.h>
#include <assert.h>

#undef CONFIG_MTD

#ifdef CONFIG_MTD
#include <linux/mtd/mtd.h>
#endif


#define SIGHUP		 1	/* Hangup (POSIX).  */
#define SIGUSR1		16	/* User-defined signal 1 (POSIX).  */
#define SIGUSR2		17	/* User-defined signal 2 (POSIX).  */

#define MAX(a,b)		((a>b)?a:b)
#define MIN(a,b)		((a>b)?b:a)


#ifdef CONFIG_RTL8185
#include "rtl_wireless.h"
	#define SIOCGIWRTLSTAINFO		0x8B30
	#define SIOCGIWRTLSTANUM		0x8B31
	#define SIOCGIWRTLDRVVERSION    0x8B32
	#define SIOCGIWRTLSCANREQ		0x8B33
	#define SIOCGIWRTLGETBSSDB		0x8B34
	#define SIOCGIWRTLJOINREQ		0x8B35
	#define SIOCGIWRTLJOINREQSTATUS	0x8B36
	#define SIOCGIWRTLGETBSSINFO	0x8B37
	#define SIOCGIWRTLGETWDSINFO	0x8B38
	#define STA_INFO_FLAG_80211A        	0x10
	#define STA_INFO_FLAG_80211B        	0x20   //if this bit is not set, it is a 11G station
	typedef struct _sta_info_2_web {
		unsigned short	aid;
		unsigned char		addr[6];
		unsigned long		tx_packets;
		unsigned long		rx_packets;
		unsigned long		expired_time;	// 10 msec unit
		unsigned short	flags;
		unsigned char		TxOperaRate;
		unsigned char		rssi;
		unsigned long		link_time;		// 1 sec unit
		unsigned long		tx_fail;
		unsigned char 	resv[16];
	} sta_info_2_web;
#endif

#define RIMR	(*((volatile uint32 *)0xbd012000))

#ifdef CONFIG_RTL8185
#define	MAX_BSS_DESC	64
#define SSID_LEN	32
typedef enum _BssType {
    infrastructure = 1,
    independent = 2,
} BssType;

typedef struct _OCTET_STRING {
    unsigned char *Octet;
    unsigned short Length;
} OCTET_STRING;

typedef	struct _IbssParms {
    unsigned short	atimWin;
} IbssParms;


typedef struct _BssDscr {
    unsigned char bdBssId[6];
    unsigned char bdSsIdBuf[SSID_LEN];
    OCTET_STRING  bdSsId;
    BssType bdType;
    unsigned short bdBcnPer;			// beacon period in Time Units
    unsigned char bdDtimPer;			// DTIM period in beacon periods
    unsigned long bdTstamp[2];			// 8 Octets from ProbeRsp/Beacon
    IbssParms bdIbssParms;			// empty if infrastructure BSS
    unsigned short bdCap;				// capability information
    unsigned char ChannelNumber;			// channel number
    unsigned long bdBrates;
    unsigned long bdSupportRates;		
    unsigned char bdsa[6];			// SA address
    unsigned char rssi, sq;			// RSSI and signal strength
    unsigned char network;			// 1: 11B, 2: 11G, 4:11G
} BssDscr, *pBssDscr;

typedef struct _bss_info {
    unsigned char state;
    unsigned char channel;
    unsigned char txRate;
    unsigned char bssid[6];
    unsigned char rssi, sq;	// RSSI  and signal strength
    unsigned char ssid[SSID_LEN+1];
} bss_info;

typedef enum { INFRASTRUCTURE=0, ADHOC=1 } NETWORK_TYPE_T;
typedef enum { BAND_11B=1, BAND_11G=2, BAND_11BG=3, BAND_11A=4 } BAND_TYPE_T;
typedef enum { AP_MODE=0, CLIENT_MODE=1, WDS_MODE=2, AP_WDS_MODE=3	} WLAN_MODE_T;
typedef enum _wlan_mac_state {
    STATE_DISABLED=0, STATE_IDLE, STATE_SCANNING, STATE_STARTED, STATE_CONNECTED
} wlan_mac_state;

typedef enum _Capability {
    cESS 		= 0x01,
    cIBSS		= 0x02,
    cPollable		= 0x04,
    cPollReq		= 0x01,
    cPrivacy		= 0x10,
    cShortPreamble	= 0x20,
} Capability;

typedef struct _sitesurvey_status {
    unsigned char number;
    unsigned char pad[3];
    BssDscr bssdb[MAX_BSS_DESC];
} SS_STATUS_T, *SS_STATUS_Tp;


static SS_STATUS_Tp pStatus=NULL;
int8 selectedAPIdx[MAX_WLAN_CARDS];


typedef enum _Synchronization_Sta_State{
    STATE_Min		= 0,
    STATE_No_Bss	= 1,
    STATE_Bss		= 2,
    STATE_Ibss_Active	= 3,
    STATE_Ibss_Idle	= 4,
    STATE_Act_Receive	= 5,
    STATE_Pas_Listen	= 6,
    STATE_Act_Listen	= 7,
    STATE_Join_Wait_Beacon = 8,
    STATE_Max		= 9
} Synchronization_Sta_State;


#endif

/* defined in board.c */
extern romeCfgParam_t * pRomeCfgParam;
extern int INET_setroute(int action, int options, char **args);
//int getWlBssInfo(char *interface, bss_info *pInfo);
extern flashdrv_filewrite(FILE *,int,void *);
struct env_t
{ 
	char *name;
	int idx;
	int off;
};

struct env_t env_tuple[]=
{
	{"lan11",1,0},
	{"lan12",1,4},
};

struct env_t env_tuplec[]=
{
	{"lan111",1,0},
	{"lan112",1,1},
	{"lan113",1,2},
	{"lan114",1,3},
	{"mask111",1,12},
	{"mask112",1,13},
	{"mask113",1,14},
	{"mask114",1,15},
	{"wan111",0,0},
	{"wan112",0,1},
	{"wan113",0,2},
	{"wan114",0,3},
	{"wanip1_1",0,4},
	{"wanip1_2",0,5},
	{"wanip1_3",0,6},
	{"wanip1_4",0,7},	
	{"wanip2_1",0,8},
	{"wanip2_2",0,9},
	{"wanip2_3",0,10},
	{"wanip2_4",0,11},	
	{"mask211",0,12},
	{"mask212",0,13},
	{"mask213",0,14},
	{"mask214",0,15},
	{"wansm1_1",0,16},
	{"wansm1_2",0,17},
	{"wansm1_3",0,18},
	{"wansm1_4",0,19},	
	{"wansm2_1",0,20},
	{"wansm2_2",0,21},
	{"wansm2_3",0,22},
	{"wansm2_4",0,23},	
	{"g1",0,24},
	{"g2",0,25},
	{"g3",0,26},
	{"g4",0,27},
	{"dn1",0,28},
	{"dn2",0,29},
	{"dn3",0,30},
	{"dn4",0,31},
};

int total_tuple = sizeof(env_tuple)/sizeof(struct env_t);

extern int re865xIoctl(char *name,unsigned long arg0, unsigned long arg1, unsigned long arg2, unsigned long arg3);

// local use
char *inet_string(uint32 dst);
void cfgmgr_task(void);
void pppd_start(uint32 identity);
int32 pppd_stop(uint32 pppObjId);
void dhcps_start(void);
int do_kill(char *filename);
uint32 upnp_start(void);
void upnp_stop(void);
void ddns_start(void);

#define MULTIPLE_PPPOE_SUPPORT 1

/************************************************************
 *	
 *	Local_Function
 *	
 ************************************************************/
static void Sys_Restart(request * wp)
{
	void (*start)(void);
	uint32 reboot;

//	websHeader(wp);
	Sys_Restart_noHeader(wp);

}
extern request *request_ready;

static void Sys_Restart_noHeader(request * wp)
{
	websWrite(wp, T("<html><head><style>\n" \
		"#cntdwn{ border-color: white;border-width: 0px;font-size: 12pt;color: red;text-align:left; font-weight:bold; }\n" \
		"</style><script language=javascript>\n" \
		"var h=30;\n" \
		"function stop() { clearTimeout(id); }\n"\
		"function start() { h--; if (h >= 0) { frm.time.value = h; id=setTimeout(\"start()\",1000); }\n" \
		"if (h == 0) { window.open(\"/status.asp\",target=\"show_area\"); }}\n" \
		"</script></head><body bgcolor=white  onLoad=\"start();\" onUnload=\"stop();\">" \
		"<form name=frm><B><font color=red>System restarting, please wait ...\n" \
		"<INPUT TYPE=text NAME=time size=1 id=\"cntdwn\"></form></body></html>") );

		wp->status = REBOOT;
}

void reboot()
{
	sleep(2);	
	re865xIoctl("eth0",RTL8651_IOCTL_REBOOT,0,0,0);
	RIMR=0;
	while(1){};
	
}

void reboot_()
{
	REG32( WDTCNR_ADDR ) = 0;	
	//re865xIoctl1("eth0",RTL8651_IOCTL_REBOOT,0,0,0);
	REG32( GIMR_ADDR ) = 0;	
	while(1){};
}

/*
 * re865x Ioctl (to call kernel functions including rtl8651 table driver APIs
 */
int re865xIoctl1(char *name, unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
	unsigned int args[4];
	struct ifreq ifr;
	int sockfd;

	args[0] = arg0;
	args[1] = arg1;
	args[2] = arg2;
	args[3] = arg3;

	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("fatal error socket\n");
		return -3;
	}
	strcpy((char*)&ifr.ifr_name, name);
	((uint32 *)(&ifr.ifr_data))[0] = (uint32)args;
	if (ioctl(sockfd, SIOCDEVPRIVATE, &ifr)<0)
	{
		perror("device ioctl:");
		close(sockfd);
		return -1;
	}
	close(sockfd);
	return 0;
} /* end re865xIoctl */

#if !defined(DNI)
int send_signal(char *name,int id)
{

	FILE *fp;
	int pid;
	fp = fopen(name,"r");
	if (fp)
	{
		fscanf(fp,"%d",&pid);
		printf("pid1 %d\n",pid);
		kill(pid,id);
		fclose(fp);
		return 0;
	}
	return -1;
}

void getDialStateString(uint8 session,char *str)
{
	int dialState;
	if(session<MAX_PPPOE_SESSION) dialState=pRomeCfgParam->pppoeCfgParam[session].dialState;
#if defined(CONFIG_RTL865X_PPTPL2TP)||defined(CONFIG_RTL865XB_PPTPL2TP)	
	else if(session==MAX_PPPOE_SESSION) dialState=pRomeCfgParam->pptpCfgParam.dialState; //for pptp
	else if(session==MAX_PPPOE_SESSION+1) dialState=pRomeCfgParam->l2tpCfgParam.dialState; //for l2tp	
	
#endif	
	else return;
	
	switch(dialState)
	{	
		case PPPOECFGPARAM_DIALSTATE_OFF:
		case L2TPCFGPARAM_DIALSTATE_DIALED_DHCP_DISCOVER:			
			sprintf(str,"Disconnect");
			break;

		case PPPOECFGPARAM_DIALSTATE_DIALED_WAITING:			
			sprintf(str,"Dial on Demand...");
			break;
			
		
		case PPPOECFGPARAM_DIALSTATE_DIALED_TRYING:			
			sprintf(str,"Connecting...");
			break;
				
		case PPPOECFGPARAM_DIALSTATE_DIALED_SUCCESS:
			sprintf(str,"Connected");
			break;
#if defined(CONFIG_RTL865X_PPTPL2TP)||defined(CONFIG_RTL865XB_PPTPL2TP)
		case PPTPCFGPARAM_DIALSTATE_DISCONNECTING:
			sprintf(str,"Disconnecting...");
			break;			
#endif		
		default:
			sprintf(str,"UNKNOW");
			break;			
	}
}
#endif

#if 0
void parse_ipNet(char *temp,ipaddr_t *ip,ipaddr_t *netmask)
{
	char ip_str[32],ip_str2[32];
	char netmask_str[32]={0};
	int flag=0,ipflag=0,j;
	memcpy(ip_str,temp,32);
	*ip=0;
				
	for(j=0;j<strlen(ip_str)+1;j++)
	{
											
		if(flag!=0)  netmask_str[j-flag]=ip_str[j]; 
		ip_str2[j-ipflag]=ip_str[j];	
		if((ip_str[j]=='.')||(ip_str[j]=='/')||(ip_str[j]==0)) 
			{
				if((flag!=0)&&(ip_str[j]==0)) break;
				ip_str2[j-ipflag]=0;
				*ip=(*ip<<8)|(atoi(ip_str2)&0xff);
				ipflag=j+1;
				if(ip_str[j]==0) {ip_str[flag-1]=0; break;}
				else if(ip_str[j]=='/')  flag=j+1;												
			}						
	}
	j=atoi(netmask_str);
	if(netmask_str[0]==0) j=32;
	*netmask=0xffffffff<<(32-j);										
}
#else
void parse_ipRange(char *temp, ipaddr_t *ip, ipaddr_t *ip2)
{
	int j,ipflag=0;
	ipaddr_t temp_ip;
	char ip_str[32],ip_str2[32];
	memcpy(ip_str,temp,32);
	*ip=0;
	*ip2=0;

	for(j=0;j<strlen(ip_str)+1;j++)
	{		
		ip_str2[j-ipflag]=ip_str[j];	
		if((ip_str[j]=='.')||(ip_str[j]=='-')||(ip_str[j]==0)) 
		{			
			ip_str2[j-ipflag]=0;
			*ip=(*ip<<8)|(atoi(ip_str2)&0xff);
			ipflag=j+1;				
			if(ip_str[j]=='-') { *ip2=*ip; *ip=0; }
			if(ip_str[j]==0) break;
		}						
	}

	if(*ip2==0) *ip2=*ip;
	if(*ip2<*ip) {temp_ip=*ip; *ip=*ip2; *ip2=temp_ip; }
	
	
}
#endif

void parse_portRange(char *temp,uint16 *port_start,uint16 *port_finish)
{
	char temp2[32];
	int j;
	uint16 port_temp;	
	memcpy(temp2,temp,32);
	*port_start=atoi(temp);
	*port_finish=atoi(temp);
	for(j=0;j<strlen(temp2);j++)
	{
		if(temp2[j]=='-') 
		{
			temp2[j]=0;
			*port_start=atoi(temp2);
			*port_finish=atoi(temp2+j+1);
			break;
		}
	}
	if(*port_finish<*port_start) { port_temp=*port_finish; *port_finish=*port_start; *port_start=port_temp; }
}


void parse_mac(char *temp,uint8 *mac)
{
	int i,j=0;
	char temp2[32];

	for(i=0;i<6;i++) mac[i]=0;
	
	memcpy(temp2,temp,32);
	for(i=0;i<17;i++)
	{
		if((temp2[i]>='0')&&(temp2[i]<='9'))		
			mac[j]=(mac[j]<<4)+(temp2[i]-'0');		
		else if((temp2[i]>='a')&&(temp2[i]<='f'))
			mac[j]=(mac[j]<<4)+(temp2[i]-'a')+10;				
		else if((temp2[i]>='A')&&(temp2[i]<='F'))
			mac[j]=(mac[j]<<4)+(temp2[i]-'A')+10;
		else
			{ j++; if(j>=6) break; }		
	}
	
}


#if !defined(DNI)

/************************************************************
 *	
 *	Multiple Session Configuration (return which session)
 *	
 ************************************************************/
int asp_multiSession( request * wp, int argc, char **argv)
{
#ifdef RTL8651_DSID_SUPPORT
	int ms=atoi(websGetVar(wp,"ms",""));
	int setted=0;
	int i;

	if((argc>0)&&(argv[0]!=NULL)&&(strcmp(argv[0],"ms")==0))
	{
	
		if(pRomeCfgParam->ifCfgParam[0].connType==IFCFGPARAM_CONNTYPE_PPPOE_MULTIPLE_PPPOE) 
		{
		
			websWrite(wp,"<form name=msform><B>Dial Session: </B><select name=\"ms\"  onchange=\"changeMs(ms.value);\">");

			for(i=0;i<MAX_PPPOE_SESSION;i++)
			{
				if(pRomeCfgParam->pppoeCfgParam[i].enable==1)
				{
					if(setted==0&&ms==0) {ms=i; setted=1;}

					websWrite(wp,"<option value=\"%d\"%s>PPPoE %d</option>",i,(i==ms)?" selected":"",i);

				}
			}

			websWrite(wp,"</select></form>");

		}
	}
	else
	{
		if((pRomeCfgParam->ifCfgParam[0].connType==IFCFGPARAM_CONNTYPE_PPPOE_MULTIPLE_PPPOE)&&(ms==0)) 
		{
			for(i=0;i<MAX_PPPOE_SESSION;i++)
			{
				if(pRomeCfgParam->pppoeCfgParam[i].enable==1)
				{
					if(setted==0) {ms=i; setted=1;}
				}
			}
		}
	}
	
#else
	int ms=0;

#endif
	return ms;

}

/************************************************************
 *	
 *	Status Extended for ( Multiple PPPoE )
 *	
 ************************************************************/
int asp_statusExtended(request * wp, int argc, char **argv)
{
	int i;
	char str[30];
	switch(pRomeCfgParam->ifCfgParam[0].connType)
	{
		case IFCFGPARAM_CONNTYPE_PPPOE:
		case IFCFGPARAM_CONNTYPE_PPPOE_UNNUMBERED:
			getDialStateString(0,str);
			websWrite(wp,"<tr><td bgColor=#aaddff>Dial State</td><td bgColor=#ddeeff><font color=black>%s</td></tr>",str);
			break;
		case IFCFGPARAM_CONNTYPE_PPPOE_MULTIPLE_PPPOE:
			websWrite(wp,"<tr><td bgColor=#aaddff>Dial State</td><td bgColor=#ddeeff><font color=black>");
			for(i=0;i<MAX_PPPOE_SESSION;i++)
			{
				if(pRomeCfgParam->pppoeCfgParam[i].defaultSession==1)
				{
					getDialStateString(i,str);
					websWrite(wp,"%s",str);
					websWrite(wp,"&nbsp;&nbsp;&nbsp;&nbsp;<B>[<font color=blue>Default</font>]</b>");
					break;
				}
			}			
			websWrite(wp,"</td></tr>");
			
			for(i=0;i<MAX_PPPOE_SESSION;i++)
			{				
				if((pRomeCfgParam->pppoeCfgParam[i].defaultSession!=1)&&(pRomeCfgParam->pppoeCfgParam[i].enable==1))
				{
					websWrite(wp,"<tr><td colspan=2>&nbsp;</td></tr>\n");
					getDialStateString(i,str);
					websWrite(wp,"<tr><td bgColor=#aaddff>IP Address</td><td bgColor=#ddeeff><font color=black>%s</td></tr>\n"
					,(pRomeCfgParam->pppoeCfgParam[i].dialState==PPPOECFGPARAM_DIALSTATE_DIALED_SUCCESS)?(inet_string((uint32)&(pRomeCfgParam->pppoeCfgParam[i].ipAddr))):"0.0.0.0");
					websWrite(wp,"<tr><td bgColor=#aaddff>Subnet Mask</td><td bgColor=#ddeeff><font color=black>%s</td></tr>\n"
					,(pRomeCfgParam->pppoeCfgParam[i].dialState==PPPOECFGPARAM_DIALSTATE_DIALED_SUCCESS)?(inet_string((uint32)&(pRomeCfgParam->pppoeCfgParam[i].ipMask))):"0.0.0.0");
					websWrite(wp,"<tr><td bgColor=#aaddff>Dial State</td><td bgColor=#ddeeff><font color=black>");
					websWrite(wp,"%s&nbsp;&nbsp;&nbsp;&nbsp;<B>[<font color=blue>%d</font>]</b></td></tr>\n",str,i);
				}
			}
			break;
	} //end switch
	return 0;
}

/************************************************************
 *	
 *	Status Config Changed 
 *	
 ************************************************************/
int asp_configChanged(request * wp, int argc, char **argv)
{
	int flag=0;
	if(!strcmp(argv[0],"CONFIG_CHANGE_MESSAGE"))
	{
		if(configChanged)
		{
			websWrite(wp,"<BR><font color=red><B>Configuration has been changed, please restart system<BR>to make new configureation take effect.");
		}
		return 0;
	}
	if(!strcmp(argv[0],"CONFIG_CHANGE_FW_VER")) {if(configChanged&CONFIG_CHANGE_FW_VER) flag=1;}
	//else if(!strcmp(argv[0],"CONFIG_CHANGE_LD_VER")) {if(configChanged&CONFIG_CHANGE_LD_VER) flag=1;}
	//else if(!strcmp(argv[0],"CONFIG_CHANGE_NAT")) {if(configChanged&CONFIG_CHANGE_NAT) flag=1;}
	//else if(!strcmp(argv[0],"CONFIG_CHANGE_HW_ACCEL")) {if(configChanged&CONFIG_CHANGE_HW_ACCEL) flag=1;}
	//else if(!strcmp(argv[0],"CONFIG_CHANGE_LAN_IP")) {if(configChanged&CONFIG_CHANGE_LAN_IP) flag=1;}
	//else if(!strcmp(argv[0],"CONFIG_CHANGE_LAN_MASK")) {if(configChanged&CONFIG_CHANGE_LAN_MASK) flag=1;}
	//else if(!strcmp(argv[0],"CONFIG_CHANGE_LAN_MAC")) {if(configChanged&CONFIG_CHANGE_LAN_MAC) flag=1;}
	//else if(!strcmp(argv[0],"CONFIG_CHANGE_DHCPS")) {if(configChanged&CONFIG_CHANGE_DHCPS) flag=1;}
	else if(!strcmp(argv[0],"CONFIG_CHANGE_CONN_TYPE")) {if(configChanged&CONFIG_CHANGE_CONN_TYPE) flag=1;}
	//else if(!strcmp(argv[0],"CONFIG_CHANGE_WAN_IP")) {if(configChanged&CONFIG_CHANGE_WAN_IP) flag=1;}
	//else if(!strcmp(argv[0],"CONFIG_CHANGE_WAN_MASK")) {if(configChanged&CONFIG_CHANGE_WAN_MASK) flag=1;}
	//else if(!strcmp(argv[0],"CONFIG_CHANGE_WAN_GW")) {if(configChanged&CONFIG_CHANGE_WAN_GW) flag=1;}
	//else if(!strcmp(argv[0],"CONFIG_CHANGE_WAN_DNS")) {if(configChanged&CONFIG_CHANGE_WAN_DNS) flag=1;}
	//else if(!strcmp(argv[0],"CONFIG_CHANGE_WAN_MAC")) {if(configChanged&CONFIG_CHANGE_WAN_MAC) flag=1;}
	else if(!strcmp(argv[0],"CONFIG_CHANGE_RTL8185")) {if(configChanged&CONFIG_CHANGE_RTL8185) flag=1;}
	websWrite(wp,"%s",(flag==1)?"<font color=red><b>":"<font color=black>");
	return 0;
}

/************************************************************
 *	
 *	NAT & Hardware Accelerator
 *	
 ************************************************************/
void asp_setNat(request * wp, char *path, char *query)
{
	int result;
	char *valstr;

	DEBUG_P("hwaccel string %s\n",websGetVar(wp,T("hwaccel"),T("")));
	valstr=(websGetVar(wp,T("hwaccel"),T("")));
	if (!strcmp(valstr,"on"))
		pRomeCfgParam->natCfgParam.hwaccel=1;
	else
		pRomeCfgParam->natCfgParam.hwaccel=0;

	result = cfgmgr_write(CFGMGR_TABID_NAT,(void*)&(pRomeCfgParam->natCfgParam), sizeof(natCfgParam_t));
	cfgmgr_task();
	websRedirect(wp, T("/nat.asp"));
	return;
}



/************************************************************
 *	
 *	PPPoE/Unnumbered PPPoE/Multiple PPPoE setup for Advanced
 *	
 ************************************************************/
int pppoe_status;
void asp_setPppoe(request * wp, char *path, char *query)
{
	char temp1[32],*temp2,*temp3;
	int i,j,k,newDefaultSession=0;
	int pppoeType=atoi(websGetVar(wp,"pppoeType",""));
	pppoeCfgParam_t tempPppoeCfgParam[4];
	int32 ret = FAILED;

	temp3=websGetVar(wp,"submit2","");
	if(memcmp(temp3,"Dial",4)==0)
	{
		int session_id=0;
		printf("Dial: %s\n",websGetVar(wp,"sessionID",""));
		/* replace following code to call pppd_start() defined in board.c
		 * cause we have to overwrite /ppp/options[x] every time we call pppd
		 */
		//do_exec("/bin/pppd",websGetVar(wp,"sessionID",""));
		//pRomeCfgParam->pppoeCfgParam[atoi(websGetVar(wp,"sessionID",""))].dialState=PPPOECFGPARAM_DIALSTATE_DIALED_TRYING;		
		session_id=atoi(websGetVar(wp,"sessionID",""));

		/*   2005.3.8 Patch:
		  *   Hanging up the unnumbered PPPoE, changing configuration and then dialing up will cause problems.
		  *   Originally, rebooting the system can take new configuration effect.
		  *   But we don't want to reboot the system.
		  *   Therefore, when dialing up unnumbered PPPoE again, we re-do some configurations.
		  */
		if (pRomeCfgParam->ifCfgParam[0].connType==IFCFGPARAM_CONNTYPE_PPPOE_UNNUMBERED) {
			ipaddr_t ipMaskStub, ipStub;

			memcpy((void*)&ipStub,pRomeCfgParam->pppoeCfgParam[0].unnumberedIpAddr,4);
			memcpy((void*)&ipMaskStub,pRomeCfgParam->pppoeCfgParam[0].unnumberedIpMask,4);
			/* Change old ip alias in protocol stack to new ip alias in protocol stack. */
			{
				int 	ipValue;
				char	*av[5];
				char	*ip_string;
				char	*ipmask_string;
				char	pname[]="/bin/ifconfig";

				ip_string     = malloc(MAX_IP_STRING_LEN);
				ipmask_string = malloc(MAX_IP_STRING_LEN);
				ipValue=(int)ipStub;
				sprintf(ip_string,"%u.%u.%u.%u",(ipValue>>24)&0xff, (ipValue>>16)&0xff, (ipValue>>8)&0xff, ipValue&0xff);
				ipValue=(int)ipMaskStub;
				sprintf(ipmask_string,"%u.%u.%u.%u",(ipValue>>24)&0xff, (ipValue>>16)&0xff, (ipValue>>8)&0xff, ipValue&0xff);
				
				av[0]=pname;
				av[1]="eth1:1";
				av[2]=ip_string;
				av[3]="netmask";
				av[4]=ipmask_string;
				av[5]=NULL;
				runProgram(pname,av);
				free(ip_string);
				free(ipmask_string);
			}

			/* Add ip interface. */
			ret = rtl8651_addIpIntf("eth1", (ipaddr_t)ipStub, (ipaddr_t)ipMaskStub);
			if (ret)
				printf("rtl8651_addIpIntf: ret %d\n", ret);

		}
		pppd_start(session_id);		
		sleep(1);
	}
	else if(memcmp(temp3,"Hang up",7)==0)
	{
		uint32 pppObjId;
		printf("Hang_Up: %s\n",websGetVar(wp,"sessionID",""));
		//sprintf(temp1,"/var/run/pppd%s.pid",websGetVar(wp,"sessionID",""));
		//pRomeCfgParam->pppoeCfgParam[atoi(websGetVar(wp,"sessionID",""))].dialState=PPPOECFGPARAM_DIALSTATE_OFF;
		//do_kill(temp1);

		/*   2005.3.8 Patch:
		  *   Hanging up the unnumbered PPPoE, changing configuration and then dialing up will cause problems.
		  *   Originally, rebooting the system can take new configuration effect.
		  *   But we don't want to reboot the system.
		  *   Therefore, when hanging up unnumbered PPPoE again, we clear some configurations.
		  */
		if (pRomeCfgParam->ifCfgParam[0].connType==IFCFGPARAM_CONNTYPE_PPPOE_UNNUMBERED) {
			ipaddr_t ipMaskStub, ipStub;
			
			memcpy((void*)&ipStub,pRomeCfgParam->pppoeCfgParam[0].unnumberedIpAddr,4);
			memcpy((void*)&ipMaskStub,pRomeCfgParam->pppoeCfgParam[0].unnumberedIpMask,4);

			ret = rtl8651_delNaptMapping(ipStub);
			if (ret)
				printf("rtl8651_delNaptMapping: ret %d\n",ret);

			ret = rtl8651_resetPppoeSessionProperty((uint32)0);
			if (ret)
				printf("rtl8651_resetPppoeSessionProperty: ret %d\n",ret);

			ret = rtl8651_setLanSideExternalIpInterface("eth1", ipStub, ipMaskStub, 0 /* isExternal:false */);
			if (ret)
				printf("rtl8651_setLanSideExternalIpInterface: ret %d\n",ret);

			ret = rtl8651_delIpIntf("eth1", ipStub, ipMaskStub);
			if (ret)
				printf("rtl8651_delIpIntf: ret %d\n",ret);
		}

		pppObjId = (uint32)atoi(websGetVar(wp,"sessionID",""));
		pppd_stop(pppObjId);

	}
	else if(memcmp(temp3,"Refresh",7)==0)
	{
		printf("Refresh\n");
	}	
	else
	{
		temp2=websGetVar(wp,temp1,"");
				
		for(i=0;i<MAX_PPPOE_SESSION;i++)
		{						
			if((pppoeType!=IFCFGPARAM_CONNTYPE_PPPOE_MULTIPLE_PPPOE)&&(i>0)) break;

			memcpy((void *)&(tempPppoeCfgParam[i]),(void *)&(pRomeCfgParam->pppoeCfgParam[i]),sizeof(struct pppoeCfgParam_s));
			
			sprintf(temp1,"username%d",i);
			temp2=websGetVar(wp,temp1,"");
			memcpy((char*)&(pRomeCfgParam->pppoeCfgParam[i].username),temp2,strlen(temp2)+1);
				
			sprintf(temp1,"password%d",i);
			temp2=websGetVar(wp,temp1,"");
			memcpy((char*)&(pRomeCfgParam->pppoeCfgParam[i].password),temp2,strlen(temp2)+1);
			
			sprintf(temp1,"serviceName%d",i);
			temp2=websGetVar(wp,temp1,"");
			if (temp2)
			memcpy((char*)&(pRomeCfgParam->pppoeCfgParam[i].serviceName),temp2,strlen(temp2)+1);
			else pRomeCfgParam->pppoeCfgParam[i].serviceName[0]=0x0;

			sprintf(temp1,"acName%d",i);
			temp2=websGetVar(wp,temp1,"");
			if (temp2)
			memcpy((char*)&(pRomeCfgParam->pppoeCfgParam[i].acName),temp2,strlen(temp2)+1);
			else pRomeCfgParam->pppoeCfgParam[i].acName[0]=0x0;

			sprintf(temp1,"authType%d",i);
			temp2=websGetVar(wp,temp1,"");
			pRomeCfgParam->pppoeCfgParam[i].authType=atoi(temp2);
		
			if(pppoeType==IFCFGPARAM_CONNTYPE_PPPOE_MULTIPLE_PPPOE)
			{

				sprintf(temp1,"lanType%d",i);
				pRomeCfgParam->pppoeCfgParam[i].lanType=atoi(websGetVar(wp,temp1,""));

				if(pRomeCfgParam->pppoeCfgParam[i].lanType==PPPOECFGPARAM_LANTYPE_UNNUMBERED)
				{
					uint32 netmask=0xffffffff;
					uint8 *netmask_p=(uint8 *)&netmask;
					for(j=0;j<4;j++)
					{
						sprintf(temp1,"unnumberedIpAddr%d%d",i,j+1);
						temp2=websGetVar(wp,temp1,"");
						pRomeCfgParam->pppoeCfgParam[i].unnumberedIpAddr[j]=atoi(temp2);
					}	

					sprintf(temp1,"unnumberedIpMask%d",i);
					netmask=(netmask>>(32-atoi(websGetVar(wp,temp1,""))))<<(32-atoi(websGetVar(wp,temp1,"")));
					pRomeCfgParam->pppoeCfgParam[i].unnumberedIpMask[0]=netmask_p[0];
					pRomeCfgParam->pppoeCfgParam[i].unnumberedIpMask[1]=netmask_p[1];
					pRomeCfgParam->pppoeCfgParam[i].unnumberedIpMask[2]=netmask_p[2];
					pRomeCfgParam->pppoeCfgParam[i].unnumberedIpMask[3]=netmask_p[3];					
				}
			
				for(k=0;k<4;k++)
				{
					if(pRomeCfgParam->pppoeCfgParam[i].defaultSession==1) continue;
					sprintf(temp1,"destnet%d%d",i,k+1);
					temp2=websGetVar(wp,temp1,"");
					memcpy((char*)&(pRomeCfgParam->pppoeCfgParam[i].destnet[k]),temp2,strlen(temp2)+1);

					sprintf(temp1,"destnettype%d%d",i,k+1);
					pRomeCfgParam->pppoeCfgParam[i].destnetType[k]=atoi(websGetVar(wp,temp1,""));

					if(strlen(pRomeCfgParam->pppoeCfgParam[i].destnet[k])!=0)
						{
							switch(pRomeCfgParam->pppoeCfgParam[i].destnetType[k])
							{
								case PPPOECFGPARAM_DESTNETTYPE_IP:
									{
										ipaddr_t ip;
#if 0										
										ipaddr_t netmask;
										int j=0;
										parse_ipNet(pRomeCfgParam->pppoeCfgParam[i].destnet[k], &ip, &netmask);
										if(netmask!=0xffffffff) while(netmask<<j) j++;
										else j=32;
										sprintf(pRomeCfgParam->pppoeCfgParam[i].destnet[k],"%u.%u.%u.%u/%u",NIPQUAD(ip),j);
#else
										ipaddr_t ip2;
										parse_ipRange(pRomeCfgParam->pppoeCfgParam[i].destnet[k], &ip, &ip2);
										sprintf(pRomeCfgParam->pppoeCfgParam[i].destnet[k],"%u.%u.%u.%u-%u.%u.%u.%u",NIPQUAD(ip),NIPQUAD(ip2));
#endif

									}
									break;
								case PPPOECFGPARAM_DESTNETTYPE_DOMAIN:
									//pRomeCfgParam->pppoeCfgParam[i].destnet[k]
									break;
								case PPPOECFGPARAM_DESTNETTYPE_TCPPORT:
								case PPPOECFGPARAM_DESTNETTYPE_UDPPORT:
									{
										uint16 port_start,port_finish;
										parse_portRange(pRomeCfgParam->pppoeCfgParam[i].destnet[k],&port_start,&port_finish);
										sprintf(pRomeCfgParam->pppoeCfgParam[i].destnet[k],"%u-%u",port_start,port_finish);
									}
									break;
							}
					}
					
				}	
	
				
				sprintf(temp1,"enable%d",i);
				pRomeCfgParam->pppoeCfgParam[i].enable=atoi(websGetVar(wp,temp1,""));
				
				
			}
			
			if(pppoeType==IFCFGPARAM_CONNTYPE_PPPOE_UNNUMBERED)
			{
				uint32 netmask=0xffffffff;
				uint8 *netmask_p=(uint8 *)&netmask;
				for(j=0;j<4;j++)
				{
					sprintf(temp1,"unnumberedIpAddr%d",j+1);
					temp2=websGetVar(wp,temp1,"");
					pRomeCfgParam->pppoeCfgParam[i].unnumberedIpAddr[j]=atoi(temp2);
				}	
				netmask=(netmask>>(32-atoi(websGetVar(wp,"unnumberedIpMask",""))))<<(32-atoi(websGetVar(wp,"unnumberedIpMask","")));
				pRomeCfgParam->pppoeCfgParam[i].unnumberedIpMask[0]=netmask_p[0];
				pRomeCfgParam->pppoeCfgParam[i].unnumberedIpMask[1]=netmask_p[1];
				pRomeCfgParam->pppoeCfgParam[i].unnumberedIpMask[2]=netmask_p[2];
				pRomeCfgParam->pppoeCfgParam[i].unnumberedIpMask[3]=netmask_p[3];
				pRomeCfgParam->pppoeCfgParam[i].unnumberedNapt=atoi(websGetVar(wp,"unnumberedNapt",""));
				
			}
			
			sprintf(temp1,"demand%d",i);
			pRomeCfgParam->pppoeCfgParam[i].demand=atoi(websGetVar(wp,temp1,""));
			
			sprintf(temp1,"silentTimeout%d",i);
			pRomeCfgParam->pppoeCfgParam[i].silentTimeout=atoi(websGetVar(wp,temp1,""));
			
			sprintf(temp1,"autoReconnect%d",i);
			pRomeCfgParam->pppoeCfgParam[i].autoReconnect=atoi(websGetVar(wp,temp1,""));

			sprintf(temp1,"mtu%d",i);
			pRomeCfgParam->pppoeCfgParam[i].mtu=atoi(websGetVar(wp,temp1,""));
			if(pRomeCfgParam->pppoeCfgParam[i].mtu>1492) pRomeCfgParam->pppoeCfgParam[i].mtu=1492;
			if(pRomeCfgParam->pppoeCfgParam[i].mtu<576) pRomeCfgParam->pppoeCfgParam[i].mtu=576;
		
			
			//pRomeCfgParam->pppoeCfgParam[i].mru=atoi(websGetVar(wp,"mru",""));
			
		}


		// set default session -- for mutliple pppoe
		
		if(pppoeType==IFCFGPARAM_CONNTYPE_PPPOE_MULTIPLE_PPPOE)
		{				
			if(pRomeCfgParam->pppoeCfgParam[atoi(websGetVar(wp,"default_session",""))].enable==1)
			{
				newDefaultSession=atoi(websGetVar(wp,"default_session",""));
				rtl8651_setPppoeDefaultDialSessionId((uint32)newDefaultSession);
			}
			else
			{
				for(i=0;i<MAX_PPPOE_SESSION;i++)
				{
					if(pRomeCfgParam->pppoeCfgParam[i].enable==1)
					{
						newDefaultSession=i;
						break;
					}
				}
			}
		}

		//disconnect pppoe when cfg be changed
		for(i=0;i<MAX_PPPOE_SESSION;i++)
		{
			if((pppoeType!=IFCFGPARAM_CONNTYPE_PPPOE_MULTIPLE_PPPOE)&&(i>0)) break;

			if((memcmp((void *)&(tempPppoeCfgParam[i]),(void *)&(pRomeCfgParam->pppoeCfgParam[i]),sizeof(struct pppoeCfgParam_s)))||
				(pRomeCfgParam->pppoeCfgParam[i].defaultSession!=(newDefaultSession==i?1:0)))
			{
				if(pRomeCfgParam->pppoeCfgParam[i].dialState!=PPPOECFGPARAM_DIALSTATE_OFF) 
				{
					board_ipDownEventTableDriverAccess(); 
					//tony: if default session is changed, old route table will can't delete correctly.
					// must del old route before set new default session.
					pppd_stop(i);			
				}
			}
		}
				
		if(pppoeType==IFCFGPARAM_CONNTYPE_PPPOE_MULTIPLE_PPPOE)
		{				
			for(i=0;i<MAX_PPPOE_SESSION;i++)	
			{					
				pRomeCfgParam->pppoeCfgParam[i].defaultSession=0;
			}
			pRomeCfgParam->pppoeCfgParam[newDefaultSession].defaultSession=1;
			pRomeCfgParam->pppoeCfgParam[newDefaultSession].lanType=PPPOECFGPARAM_LANTYPE_NAPT;
		}
		
		
		if(pppoeType!=pRomeCfgParam->ifCfgParam[0].connType) configChanged|=CONFIG_CHANGE_CONN_TYPE;
		if(pppoeType==IFCFGPARAM_CONNTYPE_PPPOE_MULTIPLE_PPPOE) pRomeCfgParam->ifCfgParam[0].connType=IFCFGPARAM_CONNTYPE_PPPOE_MULTIPLE_PPPOE;
		if(pppoeType==IFCFGPARAM_CONNTYPE_PPPOE) pRomeCfgParam->ifCfgParam[0].connType=IFCFGPARAM_CONNTYPE_PPPOE;
		if(pppoeType==IFCFGPARAM_CONNTYPE_PPPOE_UNNUMBERED) pRomeCfgParam->ifCfgParam[0].connType=IFCFGPARAM_CONNTYPE_PPPOE_UNNUMBERED;

		cfgmgr_write(CFGMGR_TABID_IF,(void*)pRomeCfgParam->ifCfgParam, sizeof(pRomeCfgParam->ifCfgParam));
		cfgmgr_write(CFGMGR_TABID_PPPOE,(void*)pRomeCfgParam->pppoeCfgParam,sizeof(struct pppoeCfgParam_s)*MAX_PPPOE_SESSION);
		cfgmgr_task();
		
	}
	sprintf(temp1,"/pppoe.asp?pppoeType=%d",pppoeType);
	websRedirect(wp, temp1);
}

int asp_flashGetPppoeParam(request * wp, int argc, char **argv)
{
	char str[30];
	int i;
	
	if (!strcmp(argv[0],"username") )
		{websWrite(wp, "%s",pRomeCfgParam->pppoeCfgParam[0].username);return 0;}			

	if (!strcmp(argv[0],"password") )
		{websWrite(wp, "%s",pRomeCfgParam->pppoeCfgParam[0].password);return 0;}			

	if (!strcmp(argv[0],"demand") )
		{websWrite(wp,"%s",(pRomeCfgParam->pppoeCfgParam[0].demand==1)?"checked":"");return 0;}			

	if (!strcmp(argv[0],"silentTimeout") )
		{websWrite(wp,"%d",pRomeCfgParam->pppoeCfgParam[0].silentTimeout);return 0;}			
	if (!strcmp(argv[0],"autoReconnect") )
		{websWrite(wp,"%s",(pRomeCfgParam->pppoeCfgParam[0].autoReconnect==1)?"checked":"");return 0;}
		
	
	for(i=0;i<4;i++)
	{
		sprintf(str,"unnumberedIpAddr%d",i+1);
		if (!strcmp(argv[0],str))
			{websWrite(wp,"%d",pRomeCfgParam->pppoeCfgParam[0].unnumberedIpAddr[i]);return 0;}
		
		sprintf(str,"unnumberedIpMask%d",i+1);
		if (!strcmp(argv[0],str))
			{websWrite(wp,"%d",pRomeCfgParam->pppoeCfgParam[0].unnumberedIpMask[i]);return 0;}
	}

	for(i=0;i<MAX_PPPOE_SESSION;i++)
	{
		sprintf(str,"dialState%d",i);
		if (!strcmp(argv[0],str))
		{
			getDialStateString(i,str);
			{websWrite(wp,"%s",str); return 0;}
		}
	}

	return 0;
}


/************************************************************
 *	
 *	Management
 *	
 ************************************************************/
void asp_systemDefault(request * wp, char * path, char * query)
{
	cfgmgr_factoryDefault(0);
	Sys_Restart(wp);
}

void asp_restart(request * wp, char * path, char * query)
{
	Sys_Restart(wp);
}

static inline int _checkImage(FILE *fp, uint32 startPos, uint32 size)
{
	fileImageHeader_t	imghdr;
	uint8			*pdata;
	int				i;
	int				len;
	uint8			chksum;
#define CHKSUM_BUFF_SIZE			1024
	uint8			buffer[CHKSUM_BUFF_SIZE];

	printf("Check correctness of Image (size: %u)\n", size);

	/*
		check total size
	*/
	/* Load bdinfo first */
	flashdrv_read((void*)&bdinfo,(void*)FLASH_MAP_BOARD_INFO_ADDR,sizeof(bdinfo));

	printf("startPos=%u size=%u bdinfo.rootMaxSize=%u\n",startPos,size,bdinfo.rootMaxSize);
	
	if (size > bdinfo.rootMaxSize)
	{
		printf("Total Size (%u) exceeds Flash Size (%u)\n", size, bdinfo.rootMaxSize);
		goto check_fail;
	}

	fseek(fp, startPos, SEEK_SET);



	/*
		get image header
	*/
	if (size < sizeof(fileImageHeader_t))
	{
		printf("Image size(%d) is too small!\n", size);
		goto check_fail;
	}

	if (fread((void *)&imghdr, 1, sizeof(fileImageHeader_t), fp) == NULL)
	{
		printf("Image header (size : %d) parse fail!\n", size);
		goto check_fail;
	}

	{
		uint16 tmp16_d;
		printf("Get Image Header Success :\n");
		tmp16_d = imghdr.date >> 16;
		printf("================================================\n");
		printf("\tVersion: %d\n", imghdr.imageHdrVer);
		printf("\tTime: %u/%u/%u %u:%u:%u\n", ntohs(tmp16_d), ((imghdr.date>>8)&0xff), imghdr.date&0xff,
											(imghdr.time >> 16)&0xff, (imghdr.time >> 8)&0xff, imghdr.time&0xff);
		printf("\tMagic Number: %x\n", imghdr.productMagic);
		printf("\tHeader checksum: %x\n", imghdr.imageHdrCksm);
		printf("\tBody checksum: %x\n", imghdr.imageBdyCksm);
		printf("\tImage Type: %x\n", imghdr.imageType);
		printf("\tImage Length: %d\n", imghdr.imageLen);
		printf("================================================\n");
	}

	/* Check image length */
	if (imghdr.imageLen != (size - sizeof(fileImageHeader_t)))
	{
		printf("Image size mismatch (%d : %d) !\n", size - sizeof(fileImageHeader_t), imghdr.imageLen);
		goto check_fail;
	}

	/* Check product magic number */
	if (imghdr.productMagic != RTL_PRODUCT_MAGIC)
	{
		printf("Image product magic number(%x) error!\n", imghdr.productMagic);
		goto check_fail;
	}

	/* Check image type (For ROMFS, CRAMFS, and SQUASHFS) */
	if ((imghdr.imageType != RTL_IMAGE_TYPE_RUN)&&
	    (imghdr.imageType != RTL_IMAGE_TYPE_KFS))
	{
		printf("Image type(%x) error!\n", imghdr.imageType);
		goto check_fail;
	}

	/* Check image header checksum */
	pdata = (uint8 *)&imghdr;
	len = sizeof(fileImageHeader_t) - 1;
	chksum = 0;

	for (i=0; i<len; i++)
		chksum ^= *pdata++;

	if ( chksum != imghdr.imageHdrCksm )
	{
		printf("Image header checksum mismatch (%x : %x)!\n", chksum, imghdr.imageHdrCksm);
		goto check_fail;
	}
    
	/* Check body checksum */
	len = (size - sizeof(fileImageHeader_t));
	chksum = 0;

	/* get Image from file */
	while (len > 0)
	{
		int buflen;

		/**/
		if (len > CHKSUM_BUFF_SIZE)
		{
			buflen = CHKSUM_BUFF_SIZE;
			len -= CHKSUM_BUFF_SIZE;
		}else
		{
			buflen = len;
			len = 0;
		}

		if (fread((void *)&buffer, 1, buflen, fp) == NULL)
		{
			printf("Image body (size : %d) parse fail!\n", size);
			goto check_fail;
		}

		pdata = buffer;
		for ( i=0 ; i<buflen ; i++ )
		{
			chksum ^= *pdata++;
		}
	}

#undef CHKSUM_BUFF_SIZE

	if ( chksum != imghdr.imageBdyCksm )
	{
		printf("Image checksum mismatch (%x : %x)!\n", chksum, imghdr.imageBdyCksm);
		goto check_fail;
	}

	printf("Image Correctness Check OK !\n");
	
	return 0;

check_fail:
	printf("Image Correctness Check FAILED !\n");
	return -1;
}

void asp_upload(request * req, char* path, char* query)
{

	unsigned int startPos,endPos;
	FILE	*fp=NULL;	
	struct stat statbuf;	
	unsigned char c; 

	/* find the start and end positive of run time image */
	printf("\nTry to get file size of new firmware\n");
	
	if (req->method == M_POST)
	{
		fstat(req->post_data_fd, &statbuf);
		lseek(req->post_data_fd, SEEK_SET, 0);
//		read(req->post_data_fd,buf,statbuf.st_size);
		printf("file size=%d\n",statbuf.st_size);
		fp=fopen(req->post_file_name,"rb");
		if(fp==NULL) goto fail;
	}
	else goto fail;

	do
	{
		if(feof(fp))
		{
			printf("Cannot find start of file\n");
			goto fail;
		}
		c= fgetc(fp);
		if (c!=0xd)
			continue;
		c= fgetc(fp);
		if (c!=0xa)
			continue;
		c= fgetc(fp);
		if (c!=0xd)
			continue;
		c= fgetc(fp);
		if (c!=0xa)
			continue;
		break;
	}while(1);
	startPos=ftell(fp);
	
	if(fseek(fp,statbuf.st_size-0x100,SEEK_SET)<0) goto fail;
	do
	{
		if(feof(fp))
		{
			printf("Cannot find end of file\n");
			goto fail;
		}
		c= fgetc(fp);
		if (c!=0xd)
			continue;
		c= fgetc(fp);
		if (c!=0xa)
			continue;
		c= fgetc(fp);
		if (c!='-')
			continue;
		c= fgetc(fp);
		if (c!='-')
			continue;
		break;
	}while(1);
	endPos=ftell(fp);

	/* check header and checksum of this image */
	printf("endPos=%u startPos=%u\n",endPos,startPos);
	if (_checkImage(fp, startPos, endPos-startPos-4) != 0)
		goto fail;
	
	/* redirect to error page */
	printf("Redirect web page to upload_ok.asp\n");
	{
		char tmpStr[96];
		sprintf(tmpStr,"/upload_ok.asp?startPos=%d&endPos=%d&filename=%s", startPos, endPos,req->post_file_name);
		free(req->post_file_name);
		close(req->post_data_fd);
		req->post_file_name=NULL;
		req->post_data_fd=NULL;
		websRedirect(req, tmpStr);
		//websWrite(req,"write ok\n");
	}

	return;

fail:

	if(fp!=NULL) fclose(fp);
	
	printf("\n[Note] Firmware upload Fail.\n\n");
	

	/* redirect to error page */
	printf("Redirect web page to upload_err.asp\n");
	{
		char tmpStr[30];
		sprintf(tmpStr,"/upload_err.asp");
		websRedirect(req, tmpStr);
		//websWrite(req,"update error..........<BR>");
	}
	
	return;
}

int asp_getGwInfo(request * wp, int argc, char **argv)
{
	uint32 startPos, endPos;
	char* filename;

	filename = websGetVar(wp,"filename","");
	startPos = atoi(websGetVar(wp,"startPos",""));
	endPos = atoi(websGetVar(wp,"endPos",""));

	websWrite(wp,"<input type=hidden name=\"%s\" value=\"%s\">\n", "filename", filename);
	websWrite(wp,"<input type=hidden name=\"%s\" value=\"%d\">\n", "startPos", startPos);
	websWrite(wp,"<input type=hidden name=\"%s\" value=\"%d\">\n", "endPos", endPos);

	return 0;
}

void asp_updateFW(request * wp, char* path, char* query)
{
	FILE *fp;
	uint32 startPos, endPos;
	char *ptr;

	ptr=websGetVar(wp,"filename","");
	fp = fopen(ptr, "rb");
	if (!fp)
	{
		printf("[Assertion fail!] fp=%d\n", fp);
		return 0;
	}
	startPos = atoi(websGetVar(wp,"startPos",""));
	endPos = atoi(websGetVar(wp,"endPos",""));
	/* update firmware */
	printf("Update Firmsize %d \n",endPos-4-startPos);	

	fseek(fp,startPos,SEEK_SET);

#ifdef _SUPPORT_LARGE_FLASH_
	/* Load bdinfo first */
	flashdrv_read((void*)&bdinfo,(void*)FLASH_MAP_BOARD_INFO_ADDR,sizeof(bdinfo));
#endif/*_SUPPORT_LARGE_FLASH_*/

	printf("Start Flash Writing . . .\n");
	flashdrv_filewrite(fp,endPos-4-startPos,(void*)FLASH_MAP_RUN_IMAGE_ADDR);
	fclose(fp);
	printf("Flash write OK, reboot to activate new firmware.\n");

	/* remove firmware in SD Ram */
	system("rm -f /var/run.bix");

	{
		char tmpStr[96];
		sprintf(tmpStr,"/reboot.asp");
		websRedirect(wp, tmpStr);
	}

	return 0;
}

int asp_reboot(request * wp, int argc, char **argv)
{
	Sys_Restart_noHeader(wp);
	return 0;
}

/************************************************************
 *	
 *	Status 
 *	
 ************************************************************/
char *inet_string(uint32 dst)
{
	struct in_addr	in;
	memcpy((char*)&in,(char*)dst,sizeof(in));
	return (inet_ntoa(in));
}


int asp_flashGetCfgParam(request * wp, int argc, char **argv)
{
	int		i;
	char		*Str;
	struct	env_t	*ep;
	struct ifCfgParam_s *pIfCfg;

//	a_assert(websValid(wp));
	if (argc>1)	
	{
//		a_assert(argv);
		return -1;
	}

	for (i=0;i<total_tuple;i++)
	{
		ep = &env_tuple[i];
		if (!strcmp(ep->name,argv[0]))
		{
			pIfCfg = &(pRomeCfgParam->ifCfgParam[ep->idx]);
			//fprintf(stderr," idx %x addr %x\n",ep->idx,ep->off);
			Str = inet_string((uint32)((char*)(&pIfCfg->ipAddr)+((ep->off)*4)));
			goto fin;
		}
	}
	return 0;
fin:	
	if (websWriteBlock(wp,Str,strlen(Str) ) < 0) 
		return -1;
	else 
		return 0;

}


int total_tuplec = sizeof(env_tuplec)/sizeof(struct env_t);
int asp_flashGetCloneMac(request * wp, int argc, char **argv)
{
	int i=0;
	char str[8];
	for (i=0;i<6;i++)
	{
		sprintf(str,"cmac%d",i+1);
		if(!strcmp(str,argv[0]))
		{
			websWrite(wp,T("%02X"),pRomeCfgParam->dhcpcCfgParam.cloneMac[i]);
			break;
		}
	}
	if(!strcmp("cmacValid",argv[0]))
		if (pRomeCfgParam->dhcpcCfgParam.cmacValid)
			websWrite(wp,T("checked"));
	return 0;
}

/* 
     Get IP address IP mask ...
*/
     
int asp_flashGetIpElement(request * wp, int argc, char **argv)
{
	int		i;
	char	Str[16]={0};
	struct	env_t	*ep;
	struct ifCfgParam_s *pIfCfg;
	//a_assert(websValid(wp));
	if (argc>1)	
	{
		//a_assert(argv);
		return -1;
	}

	for (i=0;i<total_tuplec;i++)
	{
		ep = &env_tuplec[i];
		if (!strcmp(ep->name,argv[0]))
		{
			pIfCfg = &(pRomeCfgParam->ifCfgParam[ep->idx]);
			//fprintf(stderr," idx %x addr %x\n",ep->idx,ep->off);
			sprintf(Str,"%d", *(unsigned char*)((char*)(&(pIfCfg->ipAddr))+(ep->off)));
			goto fin;
		}
	}
	return 0;
fin:	
	websWrite(wp,"%s",Str);
	return 0;

}



/* 
	Get constant string 
*/
int asp_flashGetString(request * wp, int argc, char **argv)
{
	fileImageHeader_t *imgHdr;
	if (!strcmp(argv[0],T("fwVer")))
	{
		websWrite(wp,T("%s"),PKG_VERSION);				
		return 0;
	}
	if (!strcmp(argv[0],T("rtl8185DrvVer")))
	{
#ifdef CONFIG_RTL8185
		websWrite(wp,T("%s"),WLANDRVPKG_VERSION);				
		return 0;
#else
		websWrite(wp,T("%s"),"Not loaded");
		return 0;
#endif
	}
	
	if (!strcmp(argv[0],T("wanIpType")))
	{
		switch (pRomeCfgParam->ifCfgParam[0].connType)
		{
			case IFCFGPARAM_CONNTYPE_STATIC:
				websWrite(wp,"Static");
				break;
			case IFCFGPARAM_CONNTYPE_DHCPC :
				websWrite(wp,"DHCP Client");
				break;
			case IFCFGPARAM_CONNTYPE_PPPOE:
				websWrite(wp,T("PPPoE"));
				break;
			case IFCFGPARAM_CONNTYPE_PPPOE_UNNUMBERED:
				websWrite(wp,"Unnumbered PPPoE");
				break;
			case IFCFGPARAM_CONNTYPE_PPPOE_MULTIPLE_PPPOE:
				websWrite(wp,"Multiple PPPoE");
				break;

#if defined(CONFIG_RTL865X_PPTPL2TP)||defined(CONFIG_RTL865XB_PPTPL2TP)

			case IFCFGPARAM_CONNTYPE_PPTP:
				websWrite(wp,"PPTP");
				break;
			case IFCFGPARAM_CONNTYPE_L2TP:
				websWrite(wp,"L2TP");
				break;
			case IFCFGPARAM_CONNTYPE_DHCPL2TP:
				websWrite(wp, "DHCPL2TP");
				break;
#endif	
#ifdef CONFIG_RTL865XB_3G
			case IFCFGPARAM_CONNTYPE_3G:
				websWrite(wp, "3G");
				break;	

			case IFCFGPARAM_CONNTYPE_USB_ETHERNET:
				websWrite(wp, "Static USB-ETHERNET");
				break;					
#endif				
			
		}
		
		return 0;
	}
		
	if (!strcmp(argv[0],T("wanstatic")))
	{
		websWrite(wp,T("%s") ,pRomeCfgParam->ifCfgParam[0].connType==IFCFGPARAM_CONNTYPE_STATIC ? "checked":" ");
		return 0;
	}

	if (!strcmp(argv[0],T("wandhcp")))
	{
		websWrite(wp,T("%s") ,pRomeCfgParam->ifCfgParam[0].connType==IFCFGPARAM_CONNTYPE_DHCPC ? "checked":" ");
		return 0;
	}
	
	if (!strcmp(argv[0],T("wanpppoe")))
	{
		websWrite(wp,T("%s") ,(pRomeCfgParam->ifCfgParam[0].connType==IFCFGPARAM_CONNTYPE_PPPOE ||	pRomeCfgParam->ifCfgParam[0].connType==IFCFGPARAM_CONNTYPE_PPPOE_MULTIPLE_PPPOE) ? "checked":"   ");
		return 0;
	}




	if (!strcmp(argv[0],T("dhcpmac_1_1")))
	{
		websWrite(wp, "%02x",  pRomeCfgParam->dhcpsCfgParam.hardwareAddr[0][0]);
	}	
	if (!strcmp(argv[0],T("dhcpmac_1_2")))
	{
		websWrite(wp, "%02x",  pRomeCfgParam->dhcpsCfgParam.hardwareAddr[0][1]);
	}
	if (!strcmp(argv[0],T("dhcpmac_1_3")))
	{
		websWrite(wp, "%02x",  pRomeCfgParam->dhcpsCfgParam.hardwareAddr[0][2]);
	}
	if (!strcmp(argv[0],T("dhcpmac_1_4")))
	{
		websWrite(wp, "%02x",  pRomeCfgParam->dhcpsCfgParam.hardwareAddr[0][3]);
	}
	if (!strcmp(argv[0],T("dhcpmac_1_5")))
	{
		websWrite(wp, "%02x",  pRomeCfgParam->dhcpsCfgParam.hardwareAddr[0][4]);
	}
	if (!strcmp(argv[0],T("dhcpmac_1_6")))
	{
		websWrite(wp, "%02x",  pRomeCfgParam->dhcpsCfgParam.hardwareAddr[0][5]);
	}
	if (!strcmp(argv[0],T("dhcpmac_2_1")))
	{
		websWrite(wp, "%02x",  pRomeCfgParam->dhcpsCfgParam.hardwareAddr[1][0]);
	}	
	if (!strcmp(argv[0],T("dhcpmac_2_2")))
	{
		websWrite(wp, "%02x",  pRomeCfgParam->dhcpsCfgParam.hardwareAddr[1][1]);
	}
	if (!strcmp(argv[0],T("dhcpmac_2_3")))
	{
		websWrite(wp, "%02x",  pRomeCfgParam->dhcpsCfgParam.hardwareAddr[1][2]);
	}
	if (!strcmp(argv[0],T("dhcpmac_2_4")))
	{
		websWrite(wp, "%02x",  pRomeCfgParam->dhcpsCfgParam.hardwareAddr[1][3]);
	}
	if (!strcmp(argv[0],T("dhcpmac_2_5")))
	{
		websWrite(wp, "%02x",  pRomeCfgParam->dhcpsCfgParam.hardwareAddr[1][4]);
	}
	if (!strcmp(argv[0],T("dhcpmac_2_6")))
	{
		websWrite(wp, "%02x",  pRomeCfgParam->dhcpsCfgParam.hardwareAddr[1][5]);
	}	
	if (!strcmp(argv[0],T("dhcpip_1_1")))
	{
		websWrite(wp, "%03u",  pRomeCfgParam->dhcpsCfgParam.manualIp[0]>>24);
		
	}
	if (!strcmp(argv[0],T("dhcpip_1_2")))
	{
		websWrite(wp, "%03u", ( pRomeCfgParam->dhcpsCfgParam.manualIp[0]&0X00ff0000)>>16);
		
	}	
	if (!strcmp(argv[0],T("dhcpip_1_3")))
	{
		websWrite(wp, "%03u",  (pRomeCfgParam->dhcpsCfgParam.manualIp[0]&0x0000ff00)>>8);
		
	}	
	if (!strcmp(argv[0],T("dhcpip_1_4")))
	{
		websWrite(wp, "%03u",  pRomeCfgParam->dhcpsCfgParam.manualIp[0]&0xff);
		
	}	
	if (!strcmp(argv[0],T("dhcpip_2_1")))
	{
		websWrite(wp, "%03u",  pRomeCfgParam->dhcpsCfgParam.manualIp[1]>>24);
		
	}
	if (!strcmp(argv[0],T("dhcpip_2_2")))
	{
		websWrite(wp, "%03u", ( pRomeCfgParam->dhcpsCfgParam.manualIp[1]&0X00ff0000)>>16);
		
	}	
	if (!strcmp(argv[0],T("dhcpip_2_3")))
	{
		websWrite(wp, "%03u",  (pRomeCfgParam->dhcpsCfgParam.manualIp[1]&0x0000ff00)>>8);
		
	}	
	if (!strcmp(argv[0],T("dhcpip_2_4")))
	{
		websWrite(wp, "%03u",  pRomeCfgParam->dhcpsCfgParam.manualIp[1]&0xff);
		
	}	


	
	if ((!strcmp(argv[0],T("wanunnumbered")))&&(MULTIPLE_PPPOE_SUPPORT))
	{
		websWrite(wp,"<tr><td bgColor=#aaddff>Unnumbered PPPoE</td>");
		websWrite(wp,"<td bgColor=#ddeeff><input type=radio name=\"wantype\" value=\"3\" ");
		websWrite(wp,T("%s") ,pRomeCfgParam->ifCfgParam[0].connType==IFCFGPARAM_CONNTYPE_PPPOE_UNNUMBERED ? "checked":"   ");
		websWrite(wp,"></td><td bgColor=#eeddff>Wirespeed</td></tr>");
		return 0;
	}	

#if defined(CONFIG_RTL865X_PPTPL2TP)||defined(CONFIG_RTL865XB_PPTPL2TP)
	if (!strcmp(argv[0],"pptpl2tp"))
	{
		websWrite(wp,"<tr><td bgColor=#aaddff>PPTP</td>");
		websWrite(wp,"<td bgColor=#ddeeff><input type=radio name=\"wantype\" value=\"5\" ");
		websWrite(wp,T("%s") ,pRomeCfgParam->ifCfgParam[0].connType==IFCFGPARAM_CONNTYPE_PPTP ? "checked":"   ");
		websWrite(wp,"></td><td bgColor=#eeddff>Accerelated</td></tr>");
		websWrite(wp,"<tr><td bgColor=#aaddff>L2TP</td>");
		websWrite(wp,"<td bgColor=#ddeeff><input type=radio name=\"wantype\" value=\"6\" ");
		websWrite(wp,T("%s") ,pRomeCfgParam->ifCfgParam[0].connType==IFCFGPARAM_CONNTYPE_L2TP ? "checked":"   ");
		websWrite(wp,"></td><td bgColor=#eeddff>Accelerated</td></tr>");		
		return 0;
	}

	if (!strcmp(argv[0], "dhcpl2tp"))
	{
		websWrite(wp, "<tr><td bgColor=#aaddff>DHCP + L2TP</td>");
		websWrite(wp, "<td bgColor=#ddeeff><input type=radio name=\"wantype\" value=\"7\" ");
		websWrite(wp,T("%s") ,pRomeCfgParam->ifCfgParam[0].connType==IFCFGPARAM_CONNTYPE_DHCPL2TP ? "checked":"   ");
		websWrite(wp,"></td><td bgColor=#eeddff>Accerelated</td></tr>");
		return 0;
	}
#endif	

#ifdef CONFIG_RTL865XB_3G
	if (!strcmp(argv[0], "3g"))
	{
		websWrite(wp, "<tr><td bgColor=#aaddff>3G/GPRS</td>");
		websWrite(wp, "<td bgColor=#ddeeff><input type=radio name=\"wantype\" value=\"8\" ");
		websWrite(wp,T("%s") ,pRomeCfgParam->ifCfgParam[0].connType==IFCFGPARAM_CONNTYPE_3G ? "checked":"   ");
		websWrite(wp,"></td><td bgColor=#eeddff>Accerelated</td></tr>");
		return 0;
	}

	if (!strcmp(argv[0], "usbethernet"))
	{
		websWrite(wp, "<tr><td bgColor=#aaddff>Static USB-ETHERNET</td>");
		websWrite(wp, "<td bgColor=#ddeeff><input type=radio name=\"wantype\" value=\"9\" ");
		websWrite(wp,T("%s") ,pRomeCfgParam->ifCfgParam[0].connType==IFCFGPARAM_CONNTYPE_USB_ETHERNET? "checked":" ");
		websWrite(wp,"></td><td bgColor=#eeddff>Accerelated</td></tr>");
		return 0;
	}	
#endif
	
	if (!strcmp(argv[0],T("dhcpsS")))
	{
		websWrite(wp,T("%d %s") ,pRomeCfgParam->dhcpsCfgParam.startIp,pRomeCfgParam->dhcpsCfgParam.enable==1 ? "enable":"disable");
		return 0;
	}
	if (!strcmp(argv[0],T("dhcpsE")))
	{
		websWrite(wp,T("%d %s") ,pRomeCfgParam->dhcpsCfgParam.endIp,pRomeCfgParam->dhcpsCfgParam.enable==1?"enable":"disable");
		return 0;
	}
	
	if (!strcmp(argv[0],T("dhcpsToggle")))
	{
		websWrite(wp,T("%s") ,pRomeCfgParam->dhcpsCfgParam.enable ==1 ?"Enable":"Disable");
		return 0;
	}

	if (!strcmp(argv[0],T("dhcps_check")))
	{
		websWrite(wp,T("%s") ,pRomeCfgParam->dhcpsCfgParam.enable ==1 ? " checked":"");
		return 0;
	}
	
	if (!strcmp(argv[0],T("hwacc_check")))
	{
		websWrite(wp,T("%s") ,pRomeCfgParam->natCfgParam.hwaccel ==1 ? " checked":"");
	}

	if (!strcmp(argv[0],T("ldVer")))
	{
		/* 
		 * Old-fashion loader places a function pointer in communication section.
		 * New-fashion loader places a string in communication section.
		 */
#ifdef CONFIG_RTL865X_LOADER_00_00_11
		uint8 version_msg[16]; /* 00.00.00 */

		re865xIoctl("eth0",RTL8651_IOCTL_GETLDVER,0,0,version_msg);

		websWrite(wp,T("%s"),version_msg);
		return 0;

#else /* CONFIG_RTL865X_LOADER_00_00_11 */
		uint32	ver;

		re865xIoctl("eth0",RTL8651_IOCTL_GETLDVER,0,0,&ver);

		websWrite(wp,T("%u.%u.%u"),(ver>>16)&0xff,(ver>>8)&0xff,ver&0xff );
		return 0;
#endif/* CONFIG_RTL865X_LOADER_00_00_11 */

	}

	if (!strcmp(argv[0],T("romeDrvVer")))
	{
		websWrite(wp,T("%s"),ROMEDRIVER_VERSION);
		return 0;
	}
	
	if (!strcmp(argv[0],T("hwAcc")))
	{
		websWrite(wp,T("%s"),pRomeCfgParam->natCfgParam.hwaccel==1 ? "Enable":"Disable");
		return 0;
	}
	
	if (!strcmp(argv[0],T("nat")))
	{
		websWrite(wp,T("%s"),pRomeCfgParam->natCfgParam.enable==1 ? "Enable":"Disable");
		return 0;
	}
	
	if (!strcmp(argv[0],T("fwDate")))
	{
		//memcpy(&imgHdr,(void*)FLASH_MAP_RUN_IMAGE_ADDR,sizeof(imgHdr));
#ifdef __mips__
		imgHdr=(fileImageHeader_t *)(FLASH_MAP_RUN_IMAGE_ADDR);
		//,sizeof(imgHdr));
#else
		imgHdr=(fileImageHeader_t *)(shadow);
#endif
		websWrite(wp,T("%04u/%02u/%02u %02u:%02u:%02u"),
					*(uint16*)&imgHdr->date,
					*((uint8*)&imgHdr->date+2),
					*((uint8*)&imgHdr->date+3),
					*((uint8*)&imgHdr->time),
					*((uint8*)&imgHdr->time+1),
					*((uint8*)&imgHdr->time+2));
		return 0;
	}
	
	if (!strcmp(argv[0],T("lanMac")))
	{
		uint8 mac[8];
#ifdef __mips__
		
		//bdinfo_getMac((macaddr_t*)&mac);
		re865xIoctl("eth1",GET_MAC,(uint32)&mac,0,0);
#endif
		websWrite(wp,T("%02X:%02X:%02X:%02X:%02X:%02X"),mac[0],mac[1],mac[2],mac[3],mac[4],mac[5]);
		return 0;
	}
	
	if (!strcmp(argv[0],T("wanMac")))
	{
		uint8 mac[8];
#ifdef __mips__
		re865xIoctl("eth0",GET_MAC,(uint32)&mac,0,0);
#endif
		websWrite(wp,T("%02X:%02X:%02X:%02X:%02X:%02X"),mac[0],mac[1],mac[2],mac[3],mac[4],mac[5]);
		return 0;
	}

	/* DHCP server WINS setting */
	if (!strcmp(argv[0],T("WINS1")))
	{
		int i;
		uint8 octet[4];

		octet[0] = pRomeCfgParam->ifCfgParam[0].winsPrimaryAddr >> 24;
		octet[1] = (pRomeCfgParam->ifCfgParam[0].winsPrimaryAddr & 0x00ff0000) >> 16;
		octet[2] = (pRomeCfgParam->ifCfgParam[0].winsPrimaryAddr & 0x0000ff00) >> 8;
		octet[3] = pRomeCfgParam->ifCfgParam[0].winsPrimaryAddr & 0x000000ff;
		
		for (i = 0 ; i < 4 ; i ++)
		{
			websWrite(wp, T("<input type=text name=wins1_%d size=3 maxlength=3 value=%u >"), i, octet[i]);
			if (i < 3)
			{
				websWrite(wp, T(".\n"));
			}
		}
		return 0;
	}

	if (!strcmp(argv[0],T("WINS2")))
	{
		int i;
		uint8 octet[4];

		octet[0] = pRomeCfgParam->ifCfgParam[0].winsSecondaryAddr >> 24;
		octet[1] = (pRomeCfgParam->ifCfgParam[0].winsSecondaryAddr & 0x00ff0000) >> 16;
		octet[2] = (pRomeCfgParam->ifCfgParam[0].winsSecondaryAddr & 0x0000ff00) >> 8;
		octet[3] = pRomeCfgParam->ifCfgParam[0].winsSecondaryAddr & 0x000000ff;
		
		for (i = 0 ; i < 4 ; i ++)
		{
			websWrite(wp, T("<input type=text name=wins2_%d size=3 maxlength=3 value=%u >"), i, octet[i]);
			if (i < 3)
			{
				websWrite(wp, T(".\n"));
			}
		}
	}

	if (!strcmp(argv[0],T("DHCP_DOMAIN")))
	{
		if (pRomeCfgParam->dhcpsCfgParam.dhcpDomainFwd == 0)
		{
			websWrite(wp, T("<tr><td bgColor=#aaddff>Domain</td><td bgColor=#ddeeff>"));
			websWrite(wp, T("<input type=text name=dhcps_domain size=18 maxlength=%d value='%s' >\n"), (sizeof(ramDhcpsCfgParam.domain) - 1), ramDhcpsCfgParam.domain);
			websWrite(wp, T("</td></tr>"));
		}
	}

	if (!strcmp(argv[0],T("DOMAIN_DHCP_FWD")))
	{
		if ((pRomeCfgParam->ifCfgParam[0].connType == IFCFGPARAM_CONNTYPE_DHCPC) ||
			(pRomeCfgParam->ifCfgParam[0].connType == IFCFGPARAM_CONNTYPE_DHCPL2TP))
		{
			websWrite(wp, T("<tr><td bgColor=#aaddff>Domain form upper DHCP</td><td bgColor=#ddeeff>"));
			websWrite(wp, T("<input type=checkbox name=dhcps_domainFwd onClick='Domain();' value=1 %s>"), pRomeCfgParam->dhcpsCfgParam.dhcpDomainFwd?"checked":"");
			websWrite(wp, T("</td></tr>"));
		}
	}

	if (!strcmp(argv[0],T("DHCP_REALDNS")))
	{
		websWrite(wp, T("<input type=checkbox name=dhcps_realDNSenable onClick='Domain();' value=1 %s>"), pRomeCfgParam->dhcpsCfgParam.realDNSenable?"checked":"");
	}

	return 0;
} 

/************************************************************
 *	
 *	Status (WAN IP Info)
 *	
 ************************************************************/
int asp_getWanAddress(request * wp, int argc, char **argv)
{
	int i; 
	switch(pRomeCfgParam->ifCfgParam[0].connType)
	{
		case IFCFGPARAM_CONNTYPE_PPPOE:
		case IFCFGPARAM_CONNTYPE_PPPOE_UNNUMBERED:
		
			if(pRomeCfgParam->pppoeCfgParam[0].dialState!=PPPOECFGPARAM_DIALSTATE_DIALED_SUCCESS) 
			{
				websWrite(wp,"0.0.0.0");
				return 0;
			}
			if (!strcmp(argv[0],"wanip"))
				{websWrite(wp,"%s", inet_string((uint32)&(pRomeCfgParam->ifCfgParam[0].ipAddr)));return 0;}
			if (!strcmp(argv[0],"wanmask"))
				{websWrite(wp,"%s", inet_string((uint32)&(pRomeCfgParam->ifCfgParam[0].ipMask)));return 0;}
			if (!strcmp(argv[0],"gateway"))
				{websWrite(wp,"%s", inet_string((uint32)&(pRomeCfgParam->ifCfgParam[0].gwAddr)));return 0;}
			if (!strcmp(argv[0],"dns"))
				{websWrite(wp,"%s", inet_string((uint32)&(pRomeCfgParam->ifCfgParam[0].dnsPrimaryAddr)));return 0;}
			break;
#if defined(CONFIG_RTL865X_PPTPL2TP)||defined(CONFIG_RTL865XB_PPTPL2TP)					
		case IFCFGPARAM_CONNTYPE_PPTP:	
			if(pRomeCfgParam->pptpCfgParam.dialState!=PPPOECFGPARAM_DIALSTATE_DIALED_SUCCESS) 
			{
				websWrite(wp,"0.0.0.0");
				return 0;
			}
			if (!strcmp(argv[0],"wanip"))
				{websWrite(wp,"%s", inet_string((uint32)&(pRomeCfgParam->ifCfgParam[0].ipAddr)));return 0;}
			if (!strcmp(argv[0],"wanmask"))
				{websWrite(wp,"%s", inet_string((uint32)&(pRomeCfgParam->ifCfgParam[0].ipMask)));return 0;}
			if (!strcmp(argv[0],"gateway"))
				{websWrite(wp,"%s", inet_string((uint32)&(pRomeCfgParam->ifCfgParam[0].gwAddr)));return 0;}
			if (!strcmp(argv[0],"dns"))
				{websWrite(wp,"%s", inet_string((uint32)&(pRomeCfgParam->ifCfgParam[0].dnsPrimaryAddr)));return 0;}
			break;

		case IFCFGPARAM_CONNTYPE_L2TP:
		case IFCFGPARAM_CONNTYPE_DHCPL2TP:	
			if(pRomeCfgParam->l2tpCfgParam.dialState!=PPPOECFGPARAM_DIALSTATE_DIALED_SUCCESS)
			{
				websWrite(wp,"0.0.0.0");
				return 0;
			}
			if (!strcmp(argv[0],"wanip"))
				{websWrite(wp,"%s", inet_string((uint32)&(pRomeCfgParam->ifCfgParam[0].ipAddr)));return 0;}
			if (!strcmp(argv[0],"wanmask"))
				{websWrite(wp,"%s", inet_string((uint32)&(pRomeCfgParam->ifCfgParam[0].ipMask)));return 0;}
			if (!strcmp(argv[0],"gateway"))
				{websWrite(wp,"%s", inet_string((uint32)&(pRomeCfgParam->ifCfgParam[0].gwAddr)));return 0;}
			if (!strcmp(argv[0],"dns"))
				{websWrite(wp,"%s", inet_string((uint32)&(pRomeCfgParam->ifCfgParam[0].dnsPrimaryAddr)));return 0;}
			break;
#endif			
		case IFCFGPARAM_CONNTYPE_USB_ETHERNET:
		case IFCFGPARAM_CONNTYPE_3G:
		case IFCFGPARAM_CONNTYPE_STATIC:
		case IFCFGPARAM_CONNTYPE_DHCPC:	
			
			if (!strcmp(argv[0],"wanip"))
				{websWrite(wp,"%s", inet_string((uint32)&(pRomeCfgParam->ifCfgParam[0].ipAddr)));return 0;}
			if (!strcmp(argv[0],"wanmask"))
				{websWrite(wp,"%s", inet_string((uint32)&(pRomeCfgParam->ifCfgParam[0].ipMask)));return 0;}
			if (!strcmp(argv[0],"gateway"))
				{websWrite(wp,"%s", inet_string((uint32)&(pRomeCfgParam->ifCfgParam[0].gwAddr)));return 0;}
			if (!strcmp(argv[0],"dns"))
				{websWrite(wp,"%s", inet_string((uint32)&(pRomeCfgParam->ifCfgParam[0].dnsPrimaryAddr)));return 0;}
			break;
		case IFCFGPARAM_CONNTYPE_PPPOE_MULTIPLE_PPPOE:
			// print default pppoe info
			for(i=0;i<MAX_PPPOE_SESSION;i++)
			{
				if(pRomeCfgParam->pppoeCfgParam[i].defaultSession==1) 
				{
					if (!strcmp(argv[0],"wanip"))
						{websWrite(wp,"%s",(pRomeCfgParam->pppoeCfgParam[i].dialState==PPPOECFGPARAM_DIALSTATE_DIALED_SUCCESS)?(inet_string((uint32)&(pRomeCfgParam->pppoeCfgParam[i].ipAddr))):"0.0.0.0");return 0;}
					if (!strcmp(argv[0],"wanmask"))
						{websWrite(wp,"%s",(pRomeCfgParam->pppoeCfgParam[i].dialState==PPPOECFGPARAM_DIALSTATE_DIALED_SUCCESS)?(inet_string((uint32)&(pRomeCfgParam->pppoeCfgParam[i].ipMask))):"0.0.0.0");return 0;}
					if (!strcmp(argv[0],"gateway"))
						{websWrite(wp,"%s",(pRomeCfgParam->pppoeCfgParam[i].dialState==PPPOECFGPARAM_DIALSTATE_DIALED_SUCCESS)?(inet_string((uint32)&(pRomeCfgParam->pppoeCfgParam[i].gwAddr))):"0.0.0.0");return 0;}
					if (!strcmp(argv[0],"dns"))
						{websWrite(wp,"%s",(pRomeCfgParam->pppoeCfgParam[i].dialState==PPPOECFGPARAM_DIALSTATE_DIALED_SUCCESS)?(inet_string((uint32)&(pRomeCfgParam->pppoeCfgParam[i].dnsAddr))):"0.0.0.0");return 0;}
					break;
				}			

			}
			
			break;
	} //end switch
	return 0;
}

/************************************************************
 *	
 *	DHCPD Server Client List Action
 *	
 ************************************************************/
void asp_dhcpServerAdvance(request * wp, char *path, char *query)
{
	int domainToRunTime;
	int renewDHCPC;
	char tmp[128];
	char	*valstr;
	valstr = websGetVar(wp, T("dhcps_switch"), T(""));

	domainToRunTime = FALSE;
	renewDHCPC = FALSE;

	if ((pRomeCfgParam->ifCfgParam[0].connType == IFCFGPARAM_CONNTYPE_DHCPC) ||
		(pRomeCfgParam->ifCfgParam[0].connType == IFCFGPARAM_CONNTYPE_DHCPL2TP))
	{	/* we modify the setting about "domain" */
		uint8 orgSwitch;

//		ramDhcpsCfgParam.dhcpDomainFwd =  pRomeCfgParam->dhcpsCfgParam.dhcpDomainFwd;

		orgSwitch = ramDhcpsCfgParam.dhcpDomainFwd;

		ramDhcpsCfgParam.dhcpDomainFwd = atoi(websGetVar(wp,"dhcps_domainFwd",""));
		pRomeCfgParam->dhcpsCfgParam.dhcpDomainFwd = ramDhcpsCfgParam.dhcpDomainFwd;

		if (ramDhcpsCfgParam.dhcpDomainFwd == 0)
		{
			if (orgSwitch == 0)
			{	/* set RunTime and RAM domain from web */
				domainToRunTime = TRUE;
				memset(ramDhcpsCfgParam.domain, 0, sizeof(ramDhcpsCfgParam.domain));
				strncpy(ramDhcpsCfgParam.domain, websGetVar(wp,"dhcps_domain",""), (sizeof(ramDhcpsCfgParam.domain) - 1));
				memset(pRomeCfgParam->dhcpsCfgParam.domain, 0, sizeof(pRomeCfgParam->dhcpsCfgParam.domain));
				strcpy(pRomeCfgParam->dhcpsCfgParam.domain, ramDhcpsCfgParam.domain);
			}else
			{	/* set RunTime domain from RAM */
				domainToRunTime = TRUE;
				memset(pRomeCfgParam->dhcpsCfgParam.domain, 0, sizeof(pRomeCfgParam->dhcpsCfgParam.domain));
				strcpy(pRomeCfgParam->dhcpsCfgParam.domain, ramDhcpsCfgParam.domain);
			}
		}else
		{
			if (orgSwitch == 0)	/* turn on domain-fwd */
			{
				/* let dhcp-client to send renew */
				renewDHCPC = TRUE;
			}else
			{	/* don't change, do nothing */
			}
		}
	}else
	{	/* ramDhcpsCfgParam store the real forward switch, but "Non-DHCP wan type" always disable it and use the domain set by user */
		/* set RunTime and RAM domain from web */
		domainToRunTime = TRUE;
		memset(ramDhcpsCfgParam.domain, 0, sizeof(ramDhcpsCfgParam.domain));
		strncpy(ramDhcpsCfgParam.domain, websGetVar(wp,"dhcps_domain",""), (sizeof(ramDhcpsCfgParam.domain) - 1));
		memset(pRomeCfgParam->dhcpsCfgParam.domain, 0, sizeof(pRomeCfgParam->dhcpsCfgParam.domain));
		strcpy(pRomeCfgParam->dhcpsCfgParam.domain, ramDhcpsCfgParam.domain);	
	}

	{	/* before we change the status of wins server, we modify wins server information */
		
		char tmpStr[30];
		uint8 tmpIp;
		int i;
		uint32 getIp;

		getIp = 0;
		for (i = 0 ; i < 4 ; i ++)
		{
			snprintf(tmpStr, sizeof(tmpStr), "wins1_%d", i);
			tmpIp = (char)atoi(websGetVar(wp,T(tmpStr)," "));
			getIp = tmpIp + (getIp << 8);
		}
		pRomeCfgParam->ifCfgParam[0].winsPrimaryAddr = (ipaddr_t)getIp;

		getIp = 0;
		for (i = 0 ; i < 4 ; i ++)
		{
			snprintf(tmpStr, sizeof(tmpStr), "wins2_%d", i);
			tmpIp = (char)atoi(websGetVar(wp,T(tmpStr)," "));
			getIp = tmpIp + (getIp << 8);
		}
		pRomeCfgParam->ifCfgParam[0].winsSecondaryAddr = (ipaddr_t)getIp;

		cfgmgr_write(CFGMGR_TABID_IF,(void*)pRomeCfgParam->ifCfgParam,sizeof(ifCfgParam_t)*MAX_IP_INTERFACE);
		cfgmgr_task();
	}

	{	/* setting about Real DNS forwarding */
		ramDhcpsCfgParam.realDNSenable = atoi(websGetVar(wp,"dhcps_realDNSenable",""));
		pRomeCfgParam->dhcpsCfgParam.realDNSenable = ramDhcpsCfgParam.realDNSenable;
	}

	if (!strcmp(valstr,T("on")))
	{
		FILE *f;		
		ramDhcpsCfgParam.enable=1;
		ramDhcpsCfgParam.startIp = (char)atoi(websGetVar(wp,T("dhcps_ippool_start")," "));
		ramDhcpsCfgParam.endIp =   (char)atoi(websGetVar(wp,T("dhcps_ippool_end")," "));	
		ramDhcpsCfgParam.manualIp[0] = (atoi(websGetVar(wp, T("dip_1_1"), " "))<<24)  | (atoi(websGetVar(wp, T("dip_1_2"), " "))<<16) | (atoi(websGetVar(wp, T("dip_1_3"), " "))<<8) | atoi(websGetVar(wp, T("dip_1_4"), " "));
		ramDhcpsCfgParam.manualIp[1] = (atoi(websGetVar(wp, T("dip_2_1"), " "))<<24)  | (atoi(websGetVar(wp, T("dip_2_2"), " "))<<16) | (atoi(websGetVar(wp, T("dip_2_3"), " "))<<8) | atoi(websGetVar(wp, T("dip_2_4"), " "));
		ramDhcpsCfgParam.hardwareAddr[0][0] = strtol(websGetVar(wp, T("mac_1_1"), " "), NULL, 16); //atoi(websGetVar(wp, T("mac_1_1"), " "));
		ramDhcpsCfgParam.hardwareAddr[0][1] = strtol(websGetVar(wp, T("mac_1_2"), " "), NULL, 16);//atoi(websGetVar(wp, T("mac_1_2"), " "));
		ramDhcpsCfgParam.hardwareAddr[0][2] = strtol(websGetVar(wp, T("mac_1_3"), " "), NULL, 16);//atoi(websGetVar(wp, T("mac_1_3"), " "));
		ramDhcpsCfgParam.hardwareAddr[0][3] = strtol(websGetVar(wp, T("mac_1_4"), " "), NULL, 16);//atoi(websGetVar(wp, T("mac_1_4"), " "));
		ramDhcpsCfgParam.hardwareAddr[0][4] = strtol(websGetVar(wp, T("mac_1_5"), " "), NULL, 16);//atoi(websGetVar(wp, T("mac_1_5"), " "));
		ramDhcpsCfgParam.hardwareAddr[0][5] = strtol(websGetVar(wp, T("mac_1_6"), " "), NULL, 16);//atoi(websGetVar(wp, T("mac_1_6"), " "));
		ramDhcpsCfgParam.hardwareAddr[1][0] = strtol(websGetVar(wp, T("mac_2_1"), " "), NULL, 16);//atoi(websGetVar(wp, T("mac_2_1"), " "));
		ramDhcpsCfgParam.hardwareAddr[1][1] = strtol(websGetVar(wp, T("mac_2_2"), " "), NULL, 16);//atoi(websGetVar(wp, T("mac_2_2"), " "));
		ramDhcpsCfgParam.hardwareAddr[1][2] = strtol(websGetVar(wp, T("mac_2_3"), " "), NULL, 16);//atoi(websGetVar(wp, T("mac_2_3"), " "));
		ramDhcpsCfgParam.hardwareAddr[1][3] = strtol(websGetVar(wp, T("mac_2_4"), " "), NULL, 16);//atoi(websGetVar(wp, T("mac_2_4"), " "));
		ramDhcpsCfgParam.hardwareAddr[1][4] = strtol(websGetVar(wp, T("mac_2_5"), " "), NULL, 16);//atoi(websGetVar(wp, T("mac_2_5"), " "));
		ramDhcpsCfgParam.hardwareAddr[1][5] = strtol(websGetVar(wp, T("mac_2_6"), " "), NULL, 16);//atoi(websGetVar(wp, T("mac_2_6"), " "));

		memcpy((void*)&(pRomeCfgParam->dhcpsCfgParam),(void*)&ramDhcpsCfgParam,sizeof(pRomeCfgParam->dhcpsCfgParam));

		dhcps_start();
	}	
	else
	{
		ramDhcpsCfgParam.enable=0;
		do_kill("/var/run/udhcpd.pid");		
	}
	
	//if(memcmp(&ramDhcpsCfgParam,&pRomeCfgParam->dhcpsCfgParam,sizeof(ramDhcpsCfgParam))) configChanged|=CONFIG_CHANGE_DHCPS;

	if (domainToRunTime == FALSE)
	{	/* we can NOT overwrite the domain information in pRomeCfgParam with the data in ramDhcpsCfgParam */
		/* backup domain in pRomeCfgParam */
		memset(tmp, 0, sizeof(tmp));
		strncpy(tmp, pRomeCfgParam->dhcpsCfgParam.domain, sizeof(tmp));
	}
	memcpy((void*)&(pRomeCfgParam->dhcpsCfgParam),(void*)&ramDhcpsCfgParam,sizeof(pRomeCfgParam->dhcpsCfgParam));
	cfgmgr_write(CFGMGR_TABID_DHCPS,(void*)&(pRomeCfgParam->dhcpsCfgParam), sizeof(pRomeCfgParam->dhcpsCfgParam));
	cfgmgr_task();

	if (domainToRunTime == FALSE)
	{
		/* restore original domain information */
		strncpy(pRomeCfgParam->dhcpsCfgParam.domain, tmp, sizeof(pRomeCfgParam->dhcpsCfgParam.domain));
	}

	if (!((pRomeCfgParam->ifCfgParam[0].connType == IFCFGPARAM_CONNTYPE_DHCPC) ||
		(pRomeCfgParam->ifCfgParam[0].connType == IFCFGPARAM_CONNTYPE_DHCPL2TP)))
	{	/* other wan type except DHCP: never forward domain */
		pRomeCfgParam->dhcpsCfgParam.dhcpDomainFwd = 0;
	}

	if (renewDHCPC == TRUE)
	{
		send_signal("/var/run/udhcpc.pid", SIGUSR1);
	}

	websRedirect(wp, T("/dhcpd_adv.asp"));
	return;
}

/************************************************************
 *	
 *	DCHP Server Client List Subroutine
 *	
 ************************************************************/
int asp_dhcpServerLeaseList(request * wp, int argc, char **argv)
{
	#define DHCP_CLIENT_FILE 	"/var/dhcps_client"
	FILE *fp;
	char *linebuf;
	char buf1[20],buf2[20],buf3[32];

	send_signal("/var/run/udhcpd.pid",SIGUSR2);
	

	fp = fopen(DHCP_CLIENT_FILE,"r");
	if(fp==NULL) return 0;


	linebuf=malloc(80);

	websWrite(wp, "<tr><td colspan=2><BR><b>Dynamic DHCP Client List</b></td></tr>\n");	
    websWrite(wp, "<tr><td bgColor=#aaddff>Hardware Address</td>");
	websWrite(wp," <td bgColor=#aaddff><font color=black >%s </td>","Assigned IP");
	websWrite(wp," <td bgColor=#aaddff><font color=black >%s </td></tr>","Hostname");
	  while(!feof(fp))	
	{	
		fgets(linebuf,80,fp);
		memset(buf3,0,sizeof(buf3));
		sscanf(linebuf,"%s %s %s",buf1,buf2,buf3);	
        	if (!memcmp(buf1,"@@",2)) break;
		websWrite(wp, "<tr><td bgColor=#ddeeff>%s</td>",buf1);
		websWrite(wp," <td bgColor=#ddeeff><font color=black >%s </td>",buf2);
		if (!buf3[0])
			strcpy(buf3," ");	
		websWrite(wp," <td bgColor=#ddeeff><font color=black >%s </td></tr>",buf3);
	}
	fclose(fp);	
	free(linebuf);
	unlink(DHCP_CLIENT_FILE);
	return 0;
}

/************************************************************
 *	
 *	Event log
 *	
 ************************************************************/

struct circ_buf {
	int size;			
	int head;			
	int tail;			
	char data[1];		
};

struct circ_buf *getCircBufPtrByModuleId(int moduleId)
{
		int tmp_moduleId = moduleId;
		int idx = 0,i;
		uint32 ptr;
		int shmid;
		FILE *f;
		struct circ_buf *buf;
		
		while (tmp_moduleId>1)
		{
			idx ++;
			tmp_moduleId = tmp_moduleId >> 1;
		}
		
		switch(moduleId)
		{
			case RTL8651_LOGMODULE_SYS:
				if ((shmid = shmget(0x414e4547, 16000+sizeof(struct circ_buf), IPC_CREAT | 0666)) == -1) {
					return -1;
				}
				if ((buf = shmat(shmid, NULL, 0)) == NULL) {
					return -1;
                }				
				break;
			case RTL8651_LOGMODULE_ACL:
			case RTL8651_LOGMODULE_DOS:
			case RTL8651_LOGMODULE_URL:
			case RTL8651_LOGMODULE_NEWFLOW:
				f = fopen("/proc/log_module","r");
				if(f==NULL) return -1;
				for(i=0;i<idx;i++)
					fscanf(f,"%x",&ptr);
				fscanf(f,"%x",&ptr);
				fclose(f);
				if(ptr==0) return -1;
#ifdef __uClinux__
				buf=ptr;	
#else		
				buf=rtl865x_kmmap(ptr-0x80000000,sizeof(struct circ_buf)+16000);
#endif					
				break;	
		}
		return buf;
}

int asp_eventLog(request * wp, int argc, char **argv)
{
	struct circ_buf *buf;
	int show=0;
	int head,size,tail;
	uint32 moduleId=0;
	char module_name[16];
	uint8 ms;

	if(memcmp(websGetVar(wp, "action", ""),"acl",3)==0) {sprintf(module_name,"ACL"); moduleId=RTL8651_LOGMODULE_ACL;}
	else if(memcmp(websGetVar(wp, "action", ""),"dos",3)==0) {sprintf(module_name,"DoS"); moduleId=RTL8651_LOGMODULE_DOS;}
	else if(memcmp(websGetVar(wp, "action", ""),"urlfilter",9)==0) {sprintf(module_name,"URL Filter"); moduleId=RTL8651_LOGMODULE_URL;}
	else if(memcmp(websGetVar(wp, "action", ""),"new_napt",9)==0) {sprintf(module_name,"New NAPT"); moduleId=RTL8651_LOGMODULE_NEWFLOW;}
	else {sprintf(module_name,"System"); moduleId=RTL8651_LOGMODULE_SYS;}	

	websWrite(wp,
		"<html>\n" \
		"<head>\n" \
		"<meta http-equiv=\"Content-Type\" content=\"text/html; charset=big5\">\n" \
		"<script language=javascript>" \
		"function changeMs(a)" \
		"{" \
		"	fn.ms.value=a;" \
		"	fn.submit();" \
		"}" );


	if(moduleId!=RTL8651_LOGMODULE_SYS) 
	{	
		websWrite(wp,
			"function clickEnable() { if(eventform.enable.checked==0) {eventform.mailalert.checked=0;eventform.remotelog.checked=0; }  } \n" \	
			"function clickMailAlert() { if(eventform.mailalert.checked==1) eventform.enable.checked=1;  } \n");
	}
	else
	{
		websWrite(wp,"function clickEnable() { if(eventform.enable.checked==0) eventform.remotelog.checked=0;  }\n");
	}

	websWrite(wp,"function clickRemoteLog() { if(eventform.remotelog.checked==1) eventform.enable.checked=1;  } \n" );

	websWrite(wp,
		"</script>" \
		"<title>Event Log</title>\n" \
		"</head>\n" \
		"<body bgcolor=\"#ffffff\" text=\"#000000\">\n" \
		"<B>Event Log Configuration</B><BR>" );

	{
		char *msargv[]={"ms"};
		if(moduleId==RTL8651_LOGMODULE_SYS) ms=0;
		else	 ms=asp_multiSession(wp,1,msargv);
	}
	 
	websWrite(wp,		
		"<form action=\"eventlog.asp\" name=\"fn\"><input type=hidden name=action value=\"%s\"><input type=hidden name=ms value=0></form>" \
		"<form action=\"/goform/asp_setEventLog\" name=\"eventform\">\n" \
		"<input type=hidden name=ms value=%d>\n" \
		"<table cellSpacing=1 cellPadding=2 border=0><tr><td bgColor=#aaddff>%s Log</td><td bgColor=#ddeeff><input type=checkbox name=enable onclick=\"javascript:clickEnable();\"  value=1 %s>Enable ("
		,websGetVar(wp, "action", ""),ms,module_name,(pRomeCfgParam->logCfgParam[ms].module&moduleId)?"checked":"");


	if(moduleId!=RTL8651_LOGMODULE_SYS) 
	{
		websWrite(wp,
		"<input type=checkbox name=mailalert onclick=\"javascript:clickMailAlert();\" value=1 %s>Mail Alert, ",(pRomeCfgParam->logCfgParam[ms].module&(moduleId<<8))?"checked":"");
	}

		websWrite(wp,
		" <input type=checkbox name=remotelog onclick=\"javascript:clickRemoteLog();\" value=1 %s>Remote Log",(pRomeCfgParam->logCfgParam[ms].module&(moduleId<<16))?"checked":"");
	

		websWrite(wp,
		")<input type=hidden name=\"moduleId\" value=%d></td>\n" \
		"<tr><td colspan=2 align=center><input type=submit name=smt value=\"Apply\"></td></tr></table><HR><BR>",moduleId);


	if(pRomeCfgParam->logCfgParam[ms].module&moduleId)
	{
		uint32 index=0;
		int i=-1;
		void* circBuff = NULL;

		if ( moduleId == RTL8651_LOGMODULE_SYS)
		{
			buf = getCircBufPtrByModuleId(moduleId);
		} else
		{
			circBuff = malloc(sizeof(struct circ_buf)+16000);
			if ( circBuff )
			{
				memset(circBuff, 0, (sizeof(struct circ_buf)+16000));
				if (rtl8651_getLogFromKernel(circBuff, moduleId, (sizeof(struct circ_buf)+16000)) == SUCCESS)
				{
					buf = (struct circ_buf *)circBuff;
				} else
				{
					buf = NULL;
				}
			} else
			{
				buf = NULL;
			}
		}

		websWrite(wp,
			"<table cellSpacing=1 cellPadding=2 border=0>\n" \
			"<tr>\n" \
			"	<td bgColor=#aaddff>%s Log</td>\n" \
			"</tr>\n",module_name);

		if (	(buf != -1) &&
			(buf != NULL) )
		{
			head = buf->head;
			size = buf->size;
			tail = buf->tail;

			if (size == 0)
			{
				printf("buffer size is out of range\n");
			} else
			{
				if (head > tail)
				{
					tail += size;
				}

				websWrite(wp,"<tr><td bgColor=#ddeeff nowrap><font size=-1>");

				/*
					determine show message or not according to the "prefix" of each message:
						show message only when this message is not dsid related ('x') or the dsid is same as the dsid(it's "ms") we select now.
				*/
				if((buf->data[head%size]==(ms+'0')) || buf->data[head%size] == 'x')
				{
					show = 1;
				}else
				{
					show = 0;
				}
	 
				if (moduleId != RTL8651_LOGMODULE_SYS)
				{
					head ++;
				}

				for ( i = head ; i < tail ; i++ )
				{
					int idx = i;
					char getChar;

					while (idx >= size)
					{
						idx -= size;
					}

					getChar = buf->data[idx];

					if (getChar == 13)
					{	/* CR: Carriage Return, we ignore it */ 
						continue;
					}

					if (getChar == 10) 
					{	/* LF: Line Feed, we add new line in html form */
						if (show == 1 || moduleId == RTL8651_LOGMODULE_SYS)
						{
							websWrite(wp,"</font></td></tr>\n<tr><td bgColor=#ddeeff nowrap><font size=-1>");
						}
						continue;
					}

					if (getChar == 0) 
					{	/* end of string: check next message */
						if((buf->data[(idx+1)%size] == (ms+'0')) || (buf->data[(idx+1)%size] == 'x'))
						{
							show = 1;
						} else
						{
							show = 0;
						}
						
						if (moduleId != RTL8651_LOGMODULE_SYS)
						{
							i++;
						}
						continue;						
					}
					if (show == 1||moduleId == RTL8651_LOGMODULE_SYS)
					{
						websWrite(wp,"%c", getChar);
					}
				}
			}
		}
		websWrite(wp,
			"</font></td><tr><tr><td align=center>" \
			"<input type=submit name=smt value=\"Save\">&nbsp;&nbsp;&nbsp;&nbsp;" \
			"<input type=submit name=smt value=\"Clear\"></td></tr></form></body></html>\n");

		if(moduleId==RTL8651_LOGMODULE_SYS)
		{
			shmdt(buf);
		}

		if (circBuff)
		{
			free(circBuff);
		}
	}
}

void asp_setEventLog(request * wp, char *path, char *query)
{
	FILE *f;
	uint32 i,shmid;
	uint32 moduleId;
	uint32 tail,size,head;
	char tmpstr[32];
	int	ms=atoi(websGetVar(wp,"ms",""));

	moduleId=atoi(websGetVar(wp,"moduleId",""));
	
	//clear event log
	if(strcmp(websGetVar(wp,"smt",""),"Apply")==0)
	{	
		if(atoi(websGetVar(wp,"enable",""))==1)
		{
			pRomeCfgParam->logCfgParam[ms].module|=moduleId;
			rtl8651a_enableLogging(ms,moduleId, 1);
			switch(moduleId)
			{
				case RTL8651_LOGMODULE_SYS:
					f=fopen("/var/run/syslogd.pid","r");
					if(f==NULL)
					{
						system("/bin/syslogd &");
						system("/bin/klogd &");
					}				
					else
					{			
						fclose(f);
					}					
					break;
				default:
			}
		}
		else //disable
		{
			int pid=0;
			pRomeCfgParam->logCfgParam[ms].module&=(~moduleId);
			rtl8651a_enableLogging(ms,moduleId, 0);
			switch(moduleId)
			{
				case RTL8651_LOGMODULE_SYS:					
					f=fopen("/var/run/syslogd.pid","r");
					if(f!=NULL)
					{
						fscanf(f,"%d",&pid);
						kill(pid,15);
						remove("/var/run/syslogd.pid");						
						fclose(f);
					}
					f=fopen("/var/run/klogd.pid","r");
					if(f!=NULL)
					{
						fscanf(f,"%d",&pid);
						kill(pid,15);
						remove("/var/run/klogd.pid");
						fclose(f);
					}
					break;
			}
		}

		if(atoi(websGetVar(wp,"mailalert",""))==1)
		{
			pRomeCfgParam->logCfgParam[ms].module|=(moduleId<<8);
		}
		else
		{
			pRomeCfgParam->logCfgParam[ms].module&=(~(moduleId<<8));
		}


		if(atoi(websGetVar(wp,"remotelog",""))==1)
		{
			pRomeCfgParam->logCfgParam[ms].module|=(moduleId<<16);
		}
		else
		{
			pRomeCfgParam->logCfgParam[ms].module&=(~(moduleId<<16));
		}

		
		
		/* save to cfgmgr */
		cfgmgr_write(CFGMGR_TABID_LOG,(void*)(pRomeCfgParam->logCfgParam),sizeof(struct logCfgParam_s)*MAX_PPPOE_SESSION);
		cfgmgr_task();
	}

	else if(strcmp(websGetVar(wp,"smt",""),"Save")==0)
	{
		int show=0;
		struct circ_buf *buf;
		void* circBuff = NULL;

		if ( moduleId == RTL8651_LOGMODULE_SYS)
		{
			buf = getCircBufPtrByModuleId(moduleId);
		} else
		{
			circBuff = malloc(sizeof(struct circ_buf)+16000);
			if ( circBuff )
			{
				memset(circBuff, 0, (sizeof(struct circ_buf)+16000));
				if (rtl8651_getLogFromKernel(circBuff, moduleId, (sizeof(struct circ_buf)+16000)) == SUCCESS)
				{
					buf = (struct circ_buf *)circBuff;
				} else
				{
					buf = NULL;
				}
			} else
			{
				buf = NULL;
			}
		}

		if ((buf != -1) && (buf != NULL))
		{
			tail=buf->tail;
			head=buf->head;
			size=buf->size;
		
			f=fopen("/var/system.log","w");			

			if ( f == NULL )
			{
				printf("Error Open /var/system.log FAILED\n");
			} else
			{
				if(head>tail) tail+=size;
				fprintf(f,"Event Log:\r\n\r\n");

				if(buf->data[head]==(ms+'0')) show=1;
				if(moduleId!=RTL8651_LOGMODULE_SYS) head++;
				for(i=head;i<tail;i++)
				{
					int idx=i;
					while(idx>=size) idx-=size;
					if(buf->data[idx]==10) 
					{
						if(show==1||moduleId==RTL8651_LOGMODULE_SYS)
						{ fputc(0x0d,f); fputc(0x0a,f); }
						continue; 
					}
					if(buf->data[idx]==0) 
					{
						if(buf->data[(idx+1)%size]==(ms+'0')) show=1;
						else show=0;
						if(moduleId!=RTL8651_LOGMODULE_SYS) i++;	
						continue;
					}
					fputc(buf->data[idx],f);
				}						
				fclose(f);
			}
		}
		
		if (moduleId==RTL8651_LOGMODULE_SYS)
		{
			shmdt(buf);
		}
		websRedirect(wp, T("/system.log"));

		if (circBuff)
		{
			free(circBuff);
		}

		return;
	}

	else //CLEAR
	{			
		struct circ_buf *buf;		

		if ( moduleId == RTL8651_LOGMODULE_SYS )
		{
			buf = getCircBufPtrByModuleId(moduleId);
			if ((buf != -1) && (buf != NULL))
			{
				buf->head=0;
				buf->tail=0;

			}
			if(moduleId==RTL8651_LOGMODULE_SYS)
			{
				shmdt(buf);
			}
		} else
		{
			rtl8651_clearLogFromKernel(moduleId);
		}
		
	}

	switch(moduleId)
	{
		case RTL8651_LOGMODULE_SYS:	
			sprintf(tmpstr,"/eventlog.asp?action=system&ms=%d",ms);
			break;
		case RTL8651_LOGMODULE_ACL:
			sprintf(tmpstr,"/eventlog.asp?action=acl&ms=%d",ms);
			break;
		case RTL8651_LOGMODULE_DOS:
			sprintf(tmpstr,"/eventlog.asp?action=dos&ms=%d",ms);
			break;
		case RTL8651_LOGMODULE_URL:
			sprintf(tmpstr,"/eventlog.asp?action=urlfilter&ms=%d",ms);
			break;
		case RTL8651_LOGMODULE_NEWFLOW:
			sprintf(tmpstr,"/eventlog.asp?action=new_napt&ms=%d",ms);
			break;
	}

	websRedirect(wp, tmpstr);
	return;
	
}

/************************************************************
 *	
 *	DMZ host
 *	
 ************************************************************/
int asp_dmz(request * wp, int argc, char **argv)
{

	int ms=asp_multiSession(wp,argc,argv);

 	if(strcmp(argv[0],"dmzIp")==0)
 	{
 		uint8 *iplist;
 		iplist=(uint8 *)&(pRomeCfgParam->dmzCfgParam[ms].dmzIp);

		websWrite(wp, 
    		"<td bgColor=#aaddff>DMZ Host #1 (default)</td>" \
    		"<td bgColor=#ddeeff>" \
    		"<input type=text name=dmzip11 size=3 maxlength=3 value=%u>." \
    		"<input type=text name=dmzip12 size=3 maxlength=3 value=%u>." \
    		"<input type=text name=dmzip13 size=3 maxlength=3 value=%u>." \
    		"<input type=text name=dmzip14 size=3 maxlength=3 value=%u>" \
    		"&nbsp;&nbsp;&nbsp;" \
	    	"</td>", *iplist, *(iplist+1), *(iplist+2), *(iplist+3));
	}
 	else if((pRomeCfgParam->ifCfgParam[0].connType==IFCFGPARAM_CONNTYPE_STATIC) &&
                  (strcmp(argv[0],"dmzIp2")==0) )
 	{
 		uint8 *iplist;
 		iplist=(uint8 *)&(pRomeCfgParam->dmzCfgParam[ms].dmzIp2);

		websWrite(wp, 
    		"<td bgColor=#aaddff>DMZ Host #2</td>" \
    		"<td bgColor=#ddeeff>" \
    		"<input type=text name=dmzip21 size=3 maxlength=3 value=%u>." \
    		"<input type=text name=dmzip22 size=3 maxlength=3 value=%u>." \
    		"<input type=text name=dmzip23 size=3 maxlength=3 value=%u>." \
    		"<input type=text name=dmzip24 size=3 maxlength=3 value=%u>" \
    		"&nbsp;&nbsp;&nbsp;" \
	    	"</td>", *iplist, *(iplist+1), *(iplist+2), *(iplist+3));
	}
 	else if((pRomeCfgParam->ifCfgParam[0].connType==IFCFGPARAM_CONNTYPE_STATIC) &&
                  (strcmp(argv[0],"dmzIp3")==0) )
 	{
 		uint8 *iplist;
 		iplist=(uint8 *)&(pRomeCfgParam->dmzCfgParam[ms].dmzIp3);

		websWrite(wp, 
    		"<td bgColor=#aaddff>DMZ Host #3</td>" \
    		"<td bgColor=#ddeeff>" \
    		"<input type=text name=dmzip31 size=3 maxlength=3 value=%u>." \
    		"<input type=text name=dmzip32 size=3 maxlength=3 value=%u>." \
    		"<input type=text name=dmzip33 size=3 maxlength=3 value=%u>." \
    		"<input type=text name=dmzip34 size=3 maxlength=3 value=%u>" \
    		"&nbsp;&nbsp;&nbsp;" \
	    	"</td>", *iplist, *(iplist+1), *(iplist+2), *(iplist+3));
	}	
 	else if((pRomeCfgParam->ifCfgParam[0].connType==IFCFGPARAM_CONNTYPE_STATIC) &&
                  (strcmp(argv[0],"gwIp")==0) )
 	{
 		uint8 *iplist;
 		iplist=(uint8 *)&(pRomeCfgParam->ifCfgParam[0].ipAddr);

		websWrite(wp, 
    		"<td bgColor=#ddeeff>Gateway IP</td>" \
    		"<td bgColor=#ddeeff>" \
    		"<input disabled type=text name=gwip11 size=3 maxlength=3 value=%u>." \
    		"<input disabled type=text name=gwip12 size=3 maxlength=3 value=%u>." \
    		"<input disabled type=text name=gwip13 size=3 maxlength=3 value=%u>." \
    		"<input disabled type=text name=gwip14 size=3 maxlength=3 value=%u>" \
    		"&nbsp;&nbsp;&nbsp;" \
	    	"</td>", *iplist, *(iplist+1), *(iplist+2), *(iplist+3));
	}
 	else if((pRomeCfgParam->ifCfgParam[0].connType==IFCFGPARAM_CONNTYPE_STATIC) &&
                  (strcmp(argv[0],"gwIp2")==0) )
 	{
 		uint8 *iplist;
 		iplist=(uint8 *)&(pRomeCfgParam->ifCfgParam[0].ipAddr1);

		websWrite(wp, 
    		"<td bgColor=#ddeeff>Gateway IP</td>" \
    		"<td bgColor=#ddeeff>" \
    		"<input disabled type=text name=gwip21 size=3 maxlength=3 value=%u>." \
    		"<input disabled type=text name=gwip22 size=3 maxlength=3 value=%u>." \
    		"<input disabled type=text name=gwip23 size=3 maxlength=3 value=%u>." \
    		"<input disabled type=text name=gwip24 size=3 maxlength=3 value=%u>" \
    		"&nbsp;&nbsp;&nbsp;" \
	    	"</td>", *iplist, *(iplist+1), *(iplist+2), *(iplist+3));
	}
 	else if((pRomeCfgParam->ifCfgParam[0].connType==IFCFGPARAM_CONNTYPE_STATIC) &&
                  (strcmp(argv[0],"gwIp3")==0) )
 	{
 		uint8 *iplist;
 		iplist=(uint8 *)&(pRomeCfgParam->ifCfgParam[0].ipAddr2);

		websWrite(wp, 
    		"<td bgColor=#ddeeff>Gateway IP</td>" \
    		"<td bgColor=#ddeeff>" \
    		"<input disabled type=text name=gwip31 size=3 maxlength=3 value=%u>." \
    		"<input disabled type=text name=gwip32 size=3 maxlength=3 value=%u>." \
    		"<input disabled type=text name=gwip33 size=3 maxlength=3 value=%u>." \
    		"<input disabled type=text name=gwip34 size=3 maxlength=3 value=%u>" \
    		"&nbsp;&nbsp;&nbsp;" \
	    	"</td>", *iplist, *(iplist+1), *(iplist+2), *(iplist+3));
	}	
 	else if(strcmp(argv[0],"MS")==0)
 	{
 		websWrite(wp,"%d",ms);
 	}
	else if (strcmp(argv[0], "l4fwd")==0)
	{
		if (pRomeCfgParam->dmzCfgParam[ms].l4fwd==1) websWrite(wp, "checked");
	}
	else if (strcmp(argv[0], "icmpfwd")==0)
	{
		if (pRomeCfgParam->dmzCfgParam[ms].icmpfwd==1) websWrite(wp, "checked");
	}
	else if (strcmp(argv[0], "enable")==0)
	{
		if(pRomeCfgParam->dmzCfgParam[ms].enable==1)
		{
			websWrite(wp,
		    	"<td bgColor=#ddeeff>" \
	    		"<input type=checkbox name=\"enable\" value=1 checked>Enable" \
	    		"</td>" );
		}
		else
		{
			websWrite(wp,
		    	"<td bgColor=#ddeeff>" \
	    		"<input type=checkbox name=\"enable\" value=1>Enable" \
	    		"</td>" );
		}
	}
	else if ((pRomeCfgParam->ifCfgParam[0].connType==IFCFGPARAM_CONNTYPE_STATIC) &&
		     (strcmp(argv[0], "enable2")==0) )
	{
		if(pRomeCfgParam->dmzCfgParam[ms].enable2==1)
		{
			websWrite(wp,
		    	"<td bgColor=#ddeeff>" \
	    		"<input type=checkbox name=\"enable2\" value=1 checked>Enable" \
	    		"</td>" );
		}
		else
		{
			websWrite(wp,
		    	"<td bgColor=#ddeeff>" \
	    		"<input type=checkbox name=\"enable2\" value=1>Enable" \
	    		"</td>" );
		}
	}
	else if ((pRomeCfgParam->ifCfgParam[0].connType==IFCFGPARAM_CONNTYPE_STATIC) &&
		     (strcmp(argv[0], "enable3")==0) )
	{
		if(pRomeCfgParam->dmzCfgParam[ms].enable3==1)
		{
			websWrite(wp,
		    	"<td bgColor=#ddeeff>" \
	    		"<input type=checkbox name=\"enable3\" value=1 checked>Enable" \
	    		"</td>" );
		}
		else
		{
			websWrite(wp,
		    	"<td bgColor=#ddeeff>" \
	    		"<input type=checkbox name=\"enable3\" value=1>Enable" \
	    		"</td>" );
		}
	}
	return 0;
}

void asp_setDmz(request * wp, char *path, char *query)
{
	uint32	ipaddr=0, ipaddr2=0, ipaddr3=0;
	ipaddr_t	naptIp=0, naptIp2=0, naptIp3=0;
	uint8	tempip;
	char		tmpstr[32]={0};	
	int		ms=atoi(websGetVar(wp,"ms",""));
	int		i;

	if(pRomeCfgParam->ifCfgParam[0].connType!=IFCFGPARAM_CONNTYPE_PPPOE_MULTIPLE_PPPOE)
	{
		memcpy(&naptIp,pRomeCfgParam->ifCfgParam[0].ipAddr,4);
		memcpy(&naptIp2,pRomeCfgParam->ifCfgParam[0].ipAddr1,4);
		memcpy(&naptIp3,pRomeCfgParam->ifCfgParam[0].ipAddr2,4);		
	}
	else //IFCFGPARAM_CONNTYPE_PPPOE_MULTIPLE_PPPOE
	{
		memcpy((void*)&naptIp,pRomeCfgParam->pppoeCfgParam[ms].ipAddr,4);		
	}
	
	tempip=atoi(websGetVar(wp,"dmzip11",""));
	ipaddr|=((tempip<<24)&0xff000000);
	tempip=atoi(websGetVar(wp,"dmzip12",""));
	ipaddr|=((tempip<<16)&0xff0000);
	tempip=atoi(websGetVar(wp,"dmzip13",""));
	ipaddr|=((tempip<<8)&0xff00);
	tempip=atoi(websGetVar(wp,"dmzip14",""));
	ipaddr|=(tempip&0xff);	
	pRomeCfgParam->dmzCfgParam[ms].dmzIp=ipaddr;

	tempip=atoi(websGetVar(wp,"dmzip21",""));
	ipaddr2|=((tempip<<24)&0xff000000);
	tempip=atoi(websGetVar(wp,"dmzip22",""));
	ipaddr2|=((tempip<<16)&0xff0000);
	tempip=atoi(websGetVar(wp,"dmzip23",""));
	ipaddr2|=((tempip<<8)&0xff00);
	tempip=atoi(websGetVar(wp,"dmzip24",""));
	ipaddr2|=(tempip&0xff);	
	pRomeCfgParam->dmzCfgParam[ms].dmzIp2=ipaddr2;

	tempip=atoi(websGetVar(wp,"dmzip31",""));
	ipaddr3|=((tempip<<24)&0xff000000);
	tempip=atoi(websGetVar(wp,"dmzip32",""));
	ipaddr3|=((tempip<<16)&0xff0000);
	tempip=atoi(websGetVar(wp,"dmzip33",""));
	ipaddr3|=((tempip<<8)&0xff00);
	tempip=atoi(websGetVar(wp,"dmzip34",""));
	ipaddr3|=(tempip&0xff);	
	pRomeCfgParam->dmzCfgParam[ms].dmzIp3=ipaddr3;

	{
		int l4fwd;
		int icmpfwd;

		l4fwd = atoi(websGetVar(wp, "l4fwd", ""));
		icmpfwd = atoi(websGetVar(wp, "icmpfwd", ""));

		for (i = 0 ; i < MAX_PPPOE_SESSION ; i ++)
		{
			pRomeCfgParam->dmzCfgParam[i].l4fwd = l4fwd;
			pRomeCfgParam->dmzCfgParam[i].icmpfwd = icmpfwd;
		}
		
		rtl8651_setDmzL4Fwd(l4fwd);
		rtl8651_setDmzIcmpFwd(icmpfwd);
	}
	
	if(atoi(websGetVar(wp,"enable",""))==1)
	{
		int r;
		
		rtl8651a_delDmzHost(ms,(ipaddr_t)naptIp);
		r=rtl8651a_addDmzHost(ms,(ipaddr_t)naptIp, (ipaddr_t)ipaddr);
		if(r==0) pRomeCfgParam->dmzCfgParam[ms].enable=1;
	}	
	else
	{		
		rtl8651a_delDmzHost(ms,(ipaddr_t)naptIp);
		pRomeCfgParam->dmzCfgParam[ms].enable=0;
	}

	if(atoi(websGetVar(wp,"enable2",""))==1)
	{
		int r;
		
		rtl8651a_delDmzHost(ms,(ipaddr_t)naptIp2);
		r=rtl8651a_addDmzHost(ms,(ipaddr_t)naptIp2, (ipaddr_t)ipaddr2);
		if(r==0) pRomeCfgParam->dmzCfgParam[ms].enable2=1;
	}	
	else
	{		
		rtl8651a_delDmzHost(ms,(ipaddr_t)naptIp2);
		pRomeCfgParam->dmzCfgParam[ms].enable2=0;
	}

	if(atoi(websGetVar(wp,"enable3",""))==1)
	{
		int r;
		
		rtl8651a_delDmzHost(ms,(ipaddr_t)naptIp3);
		r=rtl8651a_addDmzHost(ms,(ipaddr_t)naptIp3, (ipaddr_t)ipaddr3);
		if(r==0) pRomeCfgParam->dmzCfgParam[ms].enable3=1;
	}	
	else
	{		
		rtl8651a_delDmzHost(ms,(ipaddr_t)naptIp3);
		pRomeCfgParam->dmzCfgParam[ms].enable3=0;
	}		
	cfgmgr_write(CFGMGR_TABID_DMZ,(void*)pRomeCfgParam->dmzCfgParam, sizeof(struct dmzCfgParam_s)*MAX_PPPOE_SESSION);
	cfgmgr_task();

	sprintf(tmpstr,"/dmz.asp?ms=%d",ms);	
	websRedirect(wp, tmpstr);
	
}

/************************************************************
 *	
 *	Special Application
 *	
 ************************************************************/
int asp_specialApplication(request * wp, int argc, char **argv)
{
	int i;

	int ms=asp_multiSession(wp,argc,argv);

	if(strcmp(argv[0],"JS")==0)
	{
		websWrite(wp,	
		"function checkRange()\n" \
		"{\n" \
		" var row_e=%d,max_rows=%d;\n" \
		" var type_idx=%d,trigger_s=%d,trigger_f=%d,enable_idx=%d;\n" \
		" for(i=0;i<max_rows-1;i++)\n",7,MAX_SERVER_PORT,3,4,5,6);
	
		websWrite(wp,
		" {\n" \
		"   if(!formname.elements[i*row_e+enable_idx].checked) continue;\n" \
		"  for(j=i+1;j<max_rows;j++)\n" \
		"  {\n" \
		"  var itype=parseInt(formname.elements[i*row_e+type_idx].value);\n" \
		"  var jtype=parseInt(formname.elements[j*row_e+type_idx].value);\n" \
		"   if(!formname.elements[j*row_e+enable_idx].checked) continue;\n" \
		"  if(itype==jtype) {\n" \
		"    var flag=0;\n" \
		"    var istart=parseInt(formname.elements[i*row_e+trigger_s].value);\n" \
		"    var jstart=parseInt(formname.elements[j*row_e+trigger_s].value);\n" \
		"    var ifinish=parseInt(formname.elements[i*row_e+trigger_f].value);\n" \
		"    var jfinish=parseInt(formname.elements[j*row_e+trigger_f].value);\n" \
		"    if((jstart>=istart)&&(jstart<=ifinish)) flag=1;\n" \
		"    if((jfinish>=istart)&&(jfinish<=ifinish)) flag=1;\n" \
		"    if((jstart<=istart)&&(jfinish>=ifinish)) flag=1;\n" \
		"    if(flag==1) { alert('Trigger port range overlap!'); return false;} }\n" \
		"  }\n" \
		" }\n" \
		"}\n" \
		"</script>\n");
	}
	else if(strcmp(argv[0],"content")==0)
	{
	
		websWrite(wp,
		"<input type=hidden name=ms value=%d>\n" \
/*	"onSubmit=\"return checkRange();\"" \ */
		"<table cellSpacing=1 cellPadding=2 border=0>\n" \
		"<tr><td bgColor=#aaddff>Name</td><td bgColor=#aaddff>Incoming<BR>Type</td><td bgColor=#aaddff>Incoming Port Range</td><td bgColor=#aaddff>Trigger<BR>Type</td><td bgColor=#aaddff>Trigger<BR>Start Port</td><td bgColor=#aaddff>Trigger<BR>Finish Port</td><td bgColor=#aaddff>Enable</td></tr>\n",ms);

	for(i=1;i<=MAX_SPECIAL_AP;i++)
	{
		//name
		websWrite(wp,"<tr><td bgColor=#ddeeff><input type=text name=n%02u size=15 maxlength=15 value=\"%s\"></td>\n",i,pRomeCfgParam->specialapCfgParam[ms][i-1].name);
		
		//incoming type
		websWrite(wp,"<td bgColor=#ddeeff><select name=it%02u><option value=0 %s>TCP</option><option value=1 %s>UDP</option><option value=2 %s>BOTH</option></td>\n",i,(pRomeCfgParam->specialapCfgParam[ms][i-1].inType==SPECIALACPCFGPARAM_PROTOCOL_TCP)?"selected":"",(pRomeCfgParam->specialapCfgParam[ms][i-1].inType==SPECIALACPCFGPARAM_PROTOCOL_UDP)?"selected":"",(pRomeCfgParam->specialapCfgParam[ms][i-1].inType==SPECIALACPCFGPARAM_PROTOCOL_BOTH)?"selected":"");

		//incoming start port
		websWrite(wp,"<td bgColor=#ddeeff><input type=text name=ir%02u size=40 maxlength=80 value=\"%s\"></td>\n",i,pRomeCfgParam->specialapCfgParam[ms][i-1].inRange);
		
		//outgoing type
		websWrite(wp,"<td bgColor=#ddeeff><select name=ot%02u><option value=0 %s>TCP</option><option value=1 %s>UDP</option><option value=2 %s>BOTH</option></td>\n",i,(pRomeCfgParam->specialapCfgParam[ms][i-1].outType==SPECIALACPCFGPARAM_PROTOCOL_TCP)?"selected":"",(pRomeCfgParam->specialapCfgParam[ms][i-1].outType==SPECIALACPCFGPARAM_PROTOCOL_UDP)?"selected":"",(pRomeCfgParam->specialapCfgParam[ms][i-1].outType==SPECIALACPCFGPARAM_PROTOCOL_BOTH)?"selected":"");

		//outgoing start port
		websWrite(wp,"<td bgColor=#ddeeff><input type=text name=os%02u size=5 maxlength=5 value=%u></td>\n",i,pRomeCfgParam->specialapCfgParam[ms][i-1].outStart);
		
		//outgoing finish port
		websWrite(wp,"<td bgColor=#ddeeff><input type=text name=of%02u size=5 maxlength=5 value=%u></td>\n",i,pRomeCfgParam->specialapCfgParam[ms][i-1].outFinish);

		//enable
		websWrite(wp,"<td bgColor=#ddeeff><input type=checkbox name=e%02u value=1 %s></td></tr>\n",i,(pRomeCfgParam->specialapCfgParam[ms][i-1].enable==1)?"checked":"");
	} //end for
    }

		
	return 0;
}

void asp_setSpecialApplication(request * wp, char *path, char *query)
{
	char tmpstr[5]={0};
	char tmpstr2[32]={0};
	uint8 i,j,shift;
	int8 in_range[SPECIAL_AP_MAX_IN_RANGE];
	int ms=atoi(websGetVar(wp,"ms",""));
	
	// delete all trigger port
	//TriggerPortLinkCleanup();

	for(i=0;i<MAX_SPECIAL_AP;i++)
	{
		
		//name
		sprintf(tmpstr,"n%02u",i+1);
		memset(pRomeCfgParam->specialapCfgParam[ms][i].name,0,sizeof(pRomeCfgParam->specialapCfgParam[ms][i].name));
		sprintf(tmpstr2,"%s",websGetVar(wp,tmpstr,""));
		memcpy(pRomeCfgParam->specialapCfgParam[ms][i].name,tmpstr2,sizeof(pRomeCfgParam->specialapCfgParam[ms][i].name)+1);
			
		//incoming type
		sprintf(tmpstr,"it%02u",i+1);
		pRomeCfgParam->specialapCfgParam[ms][i].inType=atoi(websGetVar(wp,tmpstr,""));
		
		//incoming port range
		sprintf(tmpstr,"ir%02u",i+1);
		pRomeCfgParam->specialapCfgParam[ms][i].inRange[0]=0;
		
		memcpy(in_range,(void *)websGetVar(wp,tmpstr,""),strlen(websGetVar(wp,tmpstr,""))+1);
		shift=0;
		for(j=0;j<SPECIAL_AP_MAX_IN_RANGE;j++)
		{
			if(((in_range[j]>='0')&&(in_range[j]<='9'))||(in_range[j]==',')||(in_range[j]=='-')||(in_range[j]==0)||(in_range[j]==' '))
			{
				if(in_range[j]==' ') in_range[j]=',';
				pRomeCfgParam->specialapCfgParam[ms][i].inRange[shift++]=in_range[j];
				if(in_range[j]==0) break;			
			}		
		}

		//outgoing type		
		sprintf(tmpstr,"ot%02u",i+1);
		pRomeCfgParam->specialapCfgParam[ms][i].outType=atoi(websGetVar(wp,tmpstr,""));
		
		//outgoing start port
		sprintf(tmpstr,"os%02u",i+1);
		pRomeCfgParam->specialapCfgParam[ms][i].outStart=atoi(websGetVar(wp,tmpstr,""));
			
		//outgoing finish port
		sprintf(tmpstr,"of%02u",i+1);
		pRomeCfgParam->specialapCfgParam[ms][i].outFinish=atoi(websGetVar(wp,tmpstr,""));

		//enable			
		sprintf(tmpstr,"e%02u",i+1);
		pRomeCfgParam->specialapCfgParam[ms][i].enable=atoi(websGetVar(wp,tmpstr,""));
			
	} /* end for i */
	
	
	// the packets of special application will trap to CPU by ACL
	acl_tableDriverAccess();
	
	/* save to cfgmgr */
	cfgmgr_write(CFGMGR_TABID_SPECIALAP,(void*)pRomeCfgParam->specialapCfgParam,sizeof(struct specialapCfgParam_s)*MAX_PPPOE_SESSION*MAX_SPECIAL_AP);
	cfgmgr_task();

	sprintf(tmpstr2,"/specialap.asp?ms=%d\n",ms);
	websRedirect(wp, tmpstr2);	
}



/************************************************************
 *	
 *	Gaming
 *	
 ************************************************************/
int asp_gaming(request * wp, int argc, char **argv)
{
	int i;

	int ms=asp_multiSession(wp,argc,argv);
	if(strcmp(argv[0],"content")==0)
	{
		char *ipaddr;
		char *idx;
		int del;
		char ipaddr2[16]={0};
		ipaddr=websGetVar(wp,"ip","");
		idx=websGetVar(wp,"idx","");
		del=atoi(websGetVar(wp,"del",""));

		
		if(strlen(ipaddr)==0) sprintf(ipaddr2,"0.0.0.0"); 
		else sprintf(ipaddr2,"%s",ipaddr);


		if(del!=0)
		{
			websWrite(wp,
			"<body onLoad=\"document.formname.submit()\">");
		}
		else
		{
			int flag=0;
			for(i=0;i<MAX_GAMING;i++)
				if(pRomeCfgParam->gamingCfgParam[ms][i].ip==0) { flag=1; break;}

			if(flag==0) 
				websWrite(wp,"<script language=\"JavaScript\">alert('Game rules are full, can not add more entry!');</script>");
			
			
			websWrite(wp,
			"<body bgcolor=\"#ffffff\" text=\"#000000\" onLoad=\"javascript:formLoad();\"><b>%s Game Rule</b>%s",(strlen(idx)==0)?"Add":"Edit",(strlen(idx)==0)?"":" [<a href=\"gaming.asp\">Add New</a>]");
		}


		websWrite(wp,
		"<form action=\"gaming.asp\" name=\"fn\"><input type=hidden name=ms value=0></form>" \
		"<form method=get action=\"/goform/asp_setGaming\" name=\"formname\">");
		
		if(del!=0)
		{
			int i=atoi(idx);
			websWrite(wp,"<input type=hidden name=idx value=\"%d\">",i);
			websWrite(wp,"<input type=hidden name=del value=1></form>");
			return 0;
		}

		websWrite(wp,
		"<table cellSpacing=1 cellPadding=2 border=0>" \
		"<tr><td bgColor=#aaddff>Name</td><td bgColor=#aaddff>IP Address</td><td bgColor=#aaddff>TCP Port to Open</td><td bgColor=#aaddff>UDP Port to Open</td><td bgColor=#aaddff>Enable</td></tr>");

		websWrite(wp,
		"<tr><td bgColor=#ddeeff><input type=text name=\"game\" size=20  maxlength=20 value=\"%s\">&lt;&lt; <select name=\"gamelist\" onChange=\"javascript:changeItem();\"></select></td>" \
		"<td bgColor=#ddeeff><input type=text name=\"ip\" size=15  maxlength=15 value=\"%s\"></td>" \
		"<td bgColor=#ddeeff><input type=text name=\"tcpopen\" size=32  maxlength=32 value=\"%s\"></td>" \
		"<td bgColor=#ddeeff><input type=text name=\"udpopen\" size=32  maxlength=32 value=\"%s\"></td>" \
		"<td bgColor=#ddeeff><input type=checkbox name=\"open\" value=1 %s></td>" \
		"<input type=hidden name=idx value=%s>" \		
		"</tr></table>"
		,websGetVar(wp,"game","")
		,ipaddr2
		,websGetVar(wp,"tcpopen","")
		,websGetVar(wp,"udpopen","")
		,(atoi(websGetVar(wp,"enable",""))==1)?"checked":""
		,(strlen(idx)==0)?"-1":idx
		);

		websWrite(wp,
		"<input type=submit value=%s>&nbsp;&nbsp;&nbsp;&nbsp;" \
		"<input type=reset value=Reset><BR><BR>",(strlen(idx)==0)?"Add":"Edit");

		websWrite(wp,
		"<b>Game Rules List</b>\n" \
		"<input type=hidden name=ms value=%d>\n" \
/*	"onSubmit=\"return checkRange();\"" \ */
		"<table cellSpacing=1 cellPadding=2 border=0>\n" \
		"<tr><td bgColor=#aaddff>Name</td><td bgColor=#aaddff>IP</td><td bgColor=#aaddff>TCP Port to Open</td><td bgColor=#aaddff>UDP Port to Open</td><td bgColor=#aaddff>Enable</td><td bgColor=#aaddff>Edit / Delete</td></tr>\n",ms);

		for(i=0;i<MAX_GAMING;i++)
		{
			if(pRomeCfgParam->gamingCfgParam[ms][i].ip==0) continue;

			//Name
			websWrite(wp,"<tr><td bgColor=#ddeeff>%s</td>\n",pRomeCfgParam->gamingCfgParam[ms][i].name);

			//IP
			websWrite(wp,"<td bgColor=#ddeeff>%u.%u.%u.%u</td>\n",NIPQUAD(pRomeCfgParam->gamingCfgParam[ms][i].ip));

			//TCP port to open
			websWrite(wp,"<td bgColor=#ddeeff>%s</td>\n",pRomeCfgParam->gamingCfgParam[ms][i].tcpRange);

			//UDP port to open
			websWrite(wp,"<td bgColor=#ddeeff>%s</td>\n",pRomeCfgParam->gamingCfgParam[ms][i].udpRange);

			//Enable
			websWrite(wp,"<td bgColor=#ddeeff>%s</td>\n",(pRomeCfgParam->gamingCfgParam[ms][i].enable==1)?"Enable":"Disable");
			
			// Edit / Delete
			websWrite(wp,"<td bgColor=#ddeeff><a href=\"gaming.asp?game=%s&ip=%u.%u.%u.%u&tcpopen=%s&udpopen=%s&enable=%d&idx=%d\">Edit</a> / <a href=\"gaming.asp?del=1&idx=%d\">Delete</a></td>\n"
			,pRomeCfgParam->gamingCfgParam[ms][i].name,NIPQUAD(pRomeCfgParam->gamingCfgParam[ms][i].ip)
			,pRomeCfgParam->gamingCfgParam[ms][i].tcpRange,pRomeCfgParam->gamingCfgParam[ms][i].udpRange
			,pRomeCfgParam->gamingCfgParam[ms][i].enable,i,i
			);

		} //end for
	}

		
	return 0;
}

void asp_setGaming(request * wp, char *path, char *query)
{
	char tmpstr[5]={0};
	char tmpstr2[32]={0};
	uint8 i,j,shift;
	
	int8 in_range[GAMING_MAX_RANGE];
	int ms=atoi(websGetVar(wp,"ms",""));
	int del=atoi(websGetVar(wp,"del",""));
	int idx=atoi(websGetVar(wp,"idx",""));

	
	// delete all trigger port
	//TriggerPortLinkCleanup();

	if(del==1)
	{
		int i=atoi(websGetVar(wp,"idx",""));
		memset(&pRomeCfgParam->gamingCfgParam[ms][i],0,sizeof(struct gamingCfgParam_s));
	}
	else
	{
		for(i=0;i<MAX_GAMING;i++)
		{
			ipaddr_t ip2;

			if(idx==-1)
			{
				if(pRomeCfgParam->gamingCfgParam[ms][i].ip!=0) continue;  //find a empty entry
			}
			else
			{
				i=idx;  //edit the index entry
			}		

			//ip
			sprintf(tmpstr2,"%s",websGetVar(wp,"ip",""));
			parse_ipRange(tmpstr2,(ipaddr_t *)&pRomeCfgParam->gamingCfgParam[ms][i].ip,&ip2);

			
			//name
			sprintf(tmpstr2,"%s",websGetVar(wp,"game",""));
			memcpy(pRomeCfgParam->gamingCfgParam[ms][i].name,tmpstr2,strlen(tmpstr2)+1);

			//tcp open port
			memcpy(in_range,(void *)websGetVar(wp,"tcpopen",""),strlen(websGetVar(wp,"tcpopen",""))+1);
			shift=0;
			for(j=0;j<GAMING_MAX_RANGE;j++)
			{
				if(((in_range[j]>='0')&&(in_range[j]<='9'))||(in_range[j]==',')||(in_range[j]=='-')||(in_range[j]==0)||(in_range[j]==' '))
				{
					if(in_range[j]==' ') in_range[j]=',';
					pRomeCfgParam->gamingCfgParam[ms][i].tcpRange[shift++]=in_range[j];
					if(in_range[j]==0) break;			
				}		
			}

			//udp open port
			memcpy(in_range,(void *)websGetVar(wp,"udpopen",""),strlen(websGetVar(wp,"udpopen",""))+1);
			shift=0;
			for(j=0;j<GAMING_MAX_RANGE;j++)
			{
				if(((in_range[j]>='0')&&(in_range[j]<='9'))||(in_range[j]==',')||(in_range[j]=='-')||(in_range[j]==0)||(in_range[j]==' '))
				{
					if(in_range[j]==' ') in_range[j]=',';
					pRomeCfgParam->gamingCfgParam[ms][i].udpRange[shift++]=in_range[j];
					if(in_range[j]==0) break;			
				}		
			}

			//enable
			pRomeCfgParam->gamingCfgParam[ms][i].enable=atoi(websGetVar(wp,"open",""));
			break;
				
		} /* end for i */
		
		
		// the packets of special application will trap to CPU by ACL
	
	}

	acl_tableDriverAccess();
	/* save to cfgmgr */

	cfgmgr_write(CFGMGR_TABID_GAMING,(void*)pRomeCfgParam->gamingCfgParam,sizeof(struct gamingCfgParam_s)*MAX_PPPOE_SESSION*MAX_GAMING);
	cfgmgr_task();

	sprintf(tmpstr2,"/gaming.asp?ms=%d\n",ms);
	websRedirect(wp, tmpstr2);	
}


/************************************************************
 *	
 *	UPnP
 *	
 ************************************************************/
int asp_upnp(request * wp, int argc, char **argv)
{
 	if(pRomeCfgParam->upnpCfgParam.enable==1) websWrite(wp,"checked");
 	return 0;
}

#if 0 // PSEUDO_ICSD
#ifdef __uClinux__
#define USERAPP_NOMMU
#endif
#ifdef USERAPP_NOMMU
void asp_setUpnp(request * wp, char *path, char *query)
{
	FILE *f;
	
	pRomeCfgParam->upnpCfgParam.enable = atoi(websGetVar(wp,"enable",""));
	
	if(pRomeCfgParam->upnpCfgParam.enable == 1) //enable
	{
		upnp_start();
	}
	else //disable
	{
		int pid=0;
						
		f=fopen("/var/run/pseudoicsd.pid","r");
		if(f != NULL)
		{
			
			char *argv[6];

			/*
				Stop upnp daemon
			*/
			fscanf(f,"%d",&pid);
			fclose(f);
			if (kill(pid,SIGTERM))
			{
				// process not exist: remove pid file
				printf("pseudoicsd.pid pid error: remove it!\n");
				unlink("/var/run/pseudoicsd.pid");
			}

			/*
				del upnp route
			*/
			argv[0]="-net";
			argv[1]="239.0.0.0";
			argv[2]="netmask";
			argv[3]="255.0.0.0";
			argv[4]="eth1";
			argv[5]=NULL;
			INET_setroute(RTACTION_DEL, 0, argv);
//			if(remove("/var/run/pseudoicsd.pid")) printf("Can't remove /var/run/pseudoicsd.pid\n");	
		}
		
	}

	cfgmgr_write(CFGMGR_TABID_UPNP,(void*)&(pRomeCfgParam->upnpCfgParam), sizeof(pRomeCfgParam->upnpCfgParam));
	cfgmgr_task();
	
	websRedirect(wp, T("upnp.asp"));
}

#else /* USERAPP_NOMMU */
void asp_setUpnp(request * wp, char *path, char *query)
{
	FILE *f;
	
	pRomeCfgParam->upnpCfgParam.enable=atoi(websGetVar(wp,"enable",""));
	
	if(pRomeCfgParam->upnpCfgParam.enable==1) //enable
	{
		upnp_start();
	}
	else //disable
	{
		int pid=0;
						
		f=fopen("/var/run/pseudoicsd.pid","r");
		if(f!=NULL)
		{
			
			char *argv[6];
			fscanf(f,"%d",&pid);
			kill(pid,SIGTERM);
			
			// del upnp route
			argv[0]="-net";
			argv[1]="239.0.0.0";
			argv[2]="netmask";
			argv[3]="255.0.0.0";
			argv[4]="eth1";
			argv[5]=NULL;
			INET_setroute(RTACTION_DEL, 0, argv);
			fclose(f);
			if(remove("/var/run/pseudoicsd.pid")) printf("Can't remove /var/run/pseudoicsd.pid\n");	
		}
		
	}

	cfgmgr_write(CFGMGR_TABID_UPNP,(void*)&(pRomeCfgParam->upnpCfgParam), sizeof(pRomeCfgParam->upnpCfgParam));
	cfgmgr_task();
	
	websRedirect(wp, T("upnp.asp"));
}
#endif /* USERAPP_NOMMU */
#else // LINUX-IGD
void asp_setUpnp(request * wp, char *path, char *query)
{
	FILE *f;
	
	pRomeCfgParam->upnpCfgParam.enable=atoi(websGetVar(wp,"enable",""));
	
	if(pRomeCfgParam->upnpCfgParam.enable==1) //enable
	{
		upnp_start();
	}
	else //disable
	{
		upnp_stop();		
	}

	cfgmgr_write(CFGMGR_TABID_UPNP,(void*)&(pRomeCfgParam->upnpCfgParam), sizeof(pRomeCfgParam->upnpCfgParam));
	cfgmgr_task();
	
	websRedirect(wp, T("/upnp.asp"));
}
#endif


/************************************************************
 *	
 *	SNMP Daemon
 *	
 ************************************************************/
int asp_snmp(request * wp, int argc, char **argv)
{
 	if(pRomeCfgParam->snmpCfgParam.enable==1) websWrite(wp,"checked");
 	return 0;
}

void asp_setSnmp(request * wp, char *path, char *query)
{
	FILE *f;
	
	pRomeCfgParam->snmpCfgParam.enable=atoi(websGetVar(wp,"enable",""));
	
	if(pRomeCfgParam->snmpCfgParam.enable==1) //enable
	{
		snmp_start();
	}
	else //disable
	{
		snmp_stop();		
	}

	cfgmgr_write(CFGMGR_TABID_UPNP,(void*)&(pRomeCfgParam->snmpCfgParam), sizeof(pRomeCfgParam->snmpCfgParam));
	cfgmgr_task();
	
	websRedirect(wp, T("/snmp.asp"));
}

/************************************************************
 *	
 *	DDNS
 *	
 ************************************************************/
int asp_ddns(request * wp, int argc, char **argv)
{
	int i;
	if(strcmp(argv[0],"enable")==0)	
 		if(pRomeCfgParam->ddnsCfgParam.enable==1) websWrite(wp,"checked");
 	if(strcmp(argv[0],"username")==0)
 		websWrite(wp,"%s",pRomeCfgParam->ddnsCfgParam.username);
	if(strcmp(argv[0],"password")==0)
 		websWrite(wp,"%s",pRomeCfgParam->ddnsCfgParam.password);

 	if(strcmp(argv[0],"username2")==0)
 		websWrite(wp,"%s",pRomeCfgParam->ddnsCfgParam.username2);
	if(strcmp(argv[0],"password2")==0)
 		websWrite(wp,"%s",pRomeCfgParam->ddnsCfgParam.password2);
	if(strcmp(argv[0],"hostname")==0)
 		websWrite(wp,"%s",pRomeCfgParam->ddnsCfgParam.hostname);

	{
		char dlist[16][16]={"ezip","justlinux","dhs","dyndns","dyndns-static","dyndns-custom","ods","gnudip","tzo","easydns","easydns-partner","dyns","zoneedit","hn","heipv6tb","pgpow"};
		
		for(i=0;i<16;i++)
		{
			if(strcmp(argv[0],dlist[i])==0) if(strcmp(dlist[i],pRomeCfgParam->ddnsCfgParam.service)==0) websWrite(wp,"selected");
		}
	}
	
	if(strcmp(argv[0],"hosts")==0)	
	{
		FILE *f;
		char c;
 		f=fopen("/var/run/no-ip2.conf","rb");
		if(f!=NULL)
		{
			while(!feof(f))
			{
				c=fgetc(f);
				if(feof(f)) break;
				if(c=='h')
				{
					c=fgetc(f);
					if(feof(f)) break;
					if(c=='[')
					{
						c=fgetc(f);
						if(feof(f)) break;
						if(c==']')
						{
							c=fgetc(f);
							if(feof(f)) break;
							if(c=='=')
							{
								while(1)
								{
									c=fgetc(f);
									if(c=='&') { websWrite(wp,"<BR>"); break;}
									if(feof(f)) break;
									websWrite(wp,"%c",c);
								}
							}							
						}
					}
				}
			}
			
			fclose(f);
		}
		else
		{
			websWrite(wp,"&lt;NONE&gt;");
		}
	}
 	return 0;		
}

void asp_setDdns(request * wp, char *path, char *query)
{


	if(strcmp(websGetVar(wp,"submit",""),"Apply")==0) // no-ip
	{
		pRomeCfgParam->ddnsCfgParam.enable=atoi(websGetVar(wp,"enable",""));
		sprintf(pRomeCfgParam->ddnsCfgParam.username,"%s",websGetVar(wp,"username",""));
		sprintf(pRomeCfgParam->ddnsCfgParam.password,"%s",websGetVar(wp,"password",""));
		
		if(pRomeCfgParam->ddnsCfgParam.enable==1)
		{
			ddns_start();
		}
		else
		{
			remove("/var/run/no-ip2.conf");
			do_kill("/var/run/no-ip2.pid");		
		}
	}
	else // ez-ipupdate
	{
		sprintf(pRomeCfgParam->ddnsCfgParam.service,"%s",websGetVar(wp,"service",""));
		sprintf(pRomeCfgParam->ddnsCfgParam.username2,"%s",websGetVar(wp,"username2",""));
		sprintf(pRomeCfgParam->ddnsCfgParam.password2,"%s",websGetVar(wp,"password2",""));
		sprintf(pRomeCfgParam->ddnsCfgParam.hostname,"%s",websGetVar(wp,"hostname",""));
		ddns_start();		
	}
	
	cfgmgr_write(CFGMGR_TABID_DDNS,(void*)&(pRomeCfgParam->ddnsCfgParam), sizeof(pRomeCfgParam->ddnsCfgParam));
	cfgmgr_task();
	
	websRedirect(wp, T("/ddns.asp"));
}


/************************************************************
 *	
 *	Wizard Save to Flash and Restart (Local Function)
 *	
 ************************************************************/
void wizardSaveToFlash(uint32 connType)
{
	int result;
	switch(connType)
	{
	case IFCFGPARAM_CONNTYPE_DHCPC:		
		cfgmgr_write(CFGMGR_TABID_DHCPC,(void*)&ramDhcpcCfgParam,sizeof(pRomeCfgParam->dhcpcCfgParam));
		break;
#if defined(CONFIG_RTL865X_PPTPL2TP)||defined(CONFIG_RTL865XB_PPTPL2TP)
	case IFCFGPARAM_CONNTYPE_PPTP:
		cfgmgr_write(CFGMGR_TABID_PPTP,(void*)&ramPptpCfgParam,sizeof(pRomeCfgParam->pptpCfgParam));
		break;
	case IFCFGPARAM_CONNTYPE_L2TP:
	case IFCFGPARAM_CONNTYPE_DHCPL2TP:		
		cfgmgr_write(CFGMGR_TABID_L2TP,(void*)&ramL2tpCfgParam,sizeof(pRomeCfgParam->l2tpCfgParam));
		break;
#endif		
	case IFCFGPARAM_CONNTYPE_PPPOE:		
	case IFCFGPARAM_CONNTYPE_PPPOE_UNNUMBERED:
		cfgmgr_write(CFGMGR_TABID_PPPOE,(void*)ramPppoeCfgParam,sizeof(pppoeCfgParam_t)*MAX_PPPOE_SESSION);
		break;
	}	
	memcpy((char*)&(pRomeCfgParam->ifCfgParam[1]),(char*)&ramLanCfgParam,sizeof(ramLanCfgParam));
	memcpy((char*)&(pRomeCfgParam->ifCfgParam[0]),(char*)&ramWanCfgParam,sizeof(ramWanCfgParam));
	result = cfgmgr_write(CFGMGR_TABID_VLAN,(void*)&(pRomeCfgParam->vlanCfgParam), sizeof(struct vlanCfgParam_s)*VLAN_LOAD_COUNT);
	result = cfgmgr_write(CFGMGR_TABID_IF,(void*)pRomeCfgParam->ifCfgParam,sizeof(ifCfgParam_t)*MAX_IP_INTERFACE);
	result = cfgmgr_write(CFGMGR_TABID_DHCPS,(void*)&ramDhcpsCfgParam,sizeof(dhcpsCfgParam_t));
	//DEBUG_P("write result %d\n", result);
	cfgmgr_task();
	

}

/************************************************************
 *	
 *	LAN IP Setup (Wizard)
 *	
 ************************************************************/
void asp_setLan(request * wp, char *path, char *query)
{
	//FILE *fp;
	int 	i;
	int	val;
	char	*valstr;	
	char	sstr[8];
	//char  *buf;
	//char	*name, *address;
	//name = websGetVar(wp, T("name"), T("Joe Smith")); 
	val=0;
	for (i=0;i<4;i++)
	{

		memset(sstr,0,sizeof(sstr));
		sprintf(sstr,"lanip_%d",i+1);
		valstr = websGetVar(wp, T(sstr), T("")); 
		ramLanCfgParam.ipAddr[i]= atoi(valstr);
	}
	for (i=0;i<4;i++)
	{

		memset(sstr,0,sizeof(sstr));
		sprintf(sstr,"lansm_%d",i+1);
		valstr = websGetVar(wp, T(sstr), T("")); 
		ramLanCfgParam.ipMask[i]= atoi(valstr);
	}

	valstr = websGetVar(wp, T("dhcps_switch"), T("")); 
	
	if (!strcmp(valstr,T("on")))
	{
	
		ramDhcpsCfgParam.enable=1;
		ramDhcpsCfgParam.startIp = (char)atoi(websGetVar(wp,T("dhcps_ippool_start")," "));
		ramDhcpsCfgParam.endIp =   (char)atoi(websGetVar(wp,T("dhcps_ippool_end")," "));
	
	}	
	else
		ramDhcpsCfgParam.enable=0;

	websRedirect(wp, T("/wan.asp"));

	return;
	
	/*
	fp = fopen("/www/wan.asp","r");
	buf = malloc(MAX_LINE_SIZE);
	if (!fp || !buf)
	{
		websError(wp, 400, T("Insufficient args\n"));
		return 1;
	}
	while (!feof(fp))
	{
		fgets(buf,MAX_LINE_SIZE,fp);
		websWrite(wp,T("%s"),buf);
	}
	free (buf);
	fclose(fp);
	websDone(wp, 200);
	*/
}

/************************************************************
 *	
 *	WAN IP Setup (Wizard)
 *	
 ************************************************************/
void asp_wanIp(request * wp, char *path, char *query)
{

	ramWanCfgParam.connType=atoi(websGetVar(wp,"wantype",""));
	
	switch(ramWanCfgParam.connType)
	{
		case IFCFGPARAM_CONNTYPE_PPPOE :
			websRedirect(wp, T("/pppoe.asp?pppoeType=1&wizard=1"));
			break;	
		case IFCFGPARAM_CONNTYPE_DHCPC :
			websRedirect(wp, T("/dhcpc.asp"));
			break;
		case IFCFGPARAM_CONNTYPE_PPPOE_UNNUMBERED :
			websRedirect(wp, T("/pppoe.asp?pppoeType=3&wizard=3"));
			break;
#if defined(CONFIG_RTL865X_PPTPL2TP)||defined(CONFIG_RTL865XB_PPTPL2TP)			
		case IFCFGPARAM_CONNTYPE_PPTP:
			websRedirect(wp, T("/wanpptp.asp?wizard=1"));
			break;
		case IFCFGPARAM_CONNTYPE_L2TP:
			websRedirect(wp, T("/wanl2tp.asp?wizard=1"));
			break;
		case IFCFGPARAM_CONNTYPE_DHCPL2TP:
			websRedirect(wp, T("/wandhcpl2tp.asp?wizard=1"));
			break;
#endif			
		default:						
			memcpy((void*)pRomeCfgParam->ifCfgParam[0].ipAddr,(void*)ramWanCfgParam.ipAddr,4);
			memcpy((void*)pRomeCfgParam->ifCfgParam[0].ipMask,(void*)ramWanCfgParam.ipMask,4);
			memcpy((void*)pRomeCfgParam->ifCfgParam[0].gwAddr,(void*)ramWanCfgParam.gwAddr,4);
			memcpy((void*)pRomeCfgParam->ifCfgParam[0].dnsPrimaryAddr,(void*)ramWanCfgParam.dnsPrimaryAddr,4);
			websRedirect(wp, T("/wanstatic.asp"));
			break;
	}
	return;
	/*
	fp = fopen("/www/wanstatic.asp","r");
	buf = malloc(MAX_LINE_SIZE);
	if (!fp || !buf)
	{
		websError(wp, 400, T("Insufficient args\n"));
		return ;
	}
	while (!feof(fp))
	{
		fgets(buf,MAX_LINE_SIZE,fp);
		websWrite(wp,T("%s"),buf);
	}
	free (buf);
	fclose(fp);
	//websFooter(wp);
	websDone(wp, 200);
	*/
	
	/*
 	 *	Extract the form name
 	 */
}

/************************************************************
 *	
 *	Static IP (Wizard)
 *	
 ************************************************************/
void asp_setStaticWizard(request * wp, char *path, char *query)
{
	int 	i;
	int	    val;
	int32 ret;
	char	sstr[8]={0};
	uint32 past_wanType = pRomeCfgParam->ifCfgParam[0].connType;
	
	val=0;
	for (i=0;i<4;i++)
	{
		sprintf(sstr,"wanip_%d",i+1);
		ramWanCfgParam.ipAddr[i]= atoi(websGetVar(wp, sstr, ""));

		/* "ipAddr1" is for multiple DMZ hosts spec. */
		sprintf(sstr,"wanip1_%d",i+1);
		ramWanCfgParam.ipAddr1[i]= atoi(websGetVar(wp, sstr, ""));

		/* "ipAddr2" is for multiple DMZ hosts spec. */
		sprintf(sstr,"wanip2_%d",i+1);
		ramWanCfgParam.ipAddr2[i]= atoi(websGetVar(wp, sstr, ""));

		sprintf(sstr,"wandns_%d",i+1);
		ramWanCfgParam.dnsPrimaryAddr[i]= atoi(websGetVar(wp, sstr, ""));

		sprintf(sstr,"wangw_%d",i+1);
		ramWanCfgParam.gwAddr[i]= atoi(websGetVar(wp, sstr, ""));
	
		sprintf(sstr,"wansm_%d",i+1);
		ramWanCfgParam.ipMask[i]= atoi(websGetVar(wp, sstr, ""));

		/* "ipMask1" is for multiple DMZ hosts spec. */
		sprintf(sstr,"wansm1_%d",i+1);
		ramWanCfgParam.ipMask1[i]= atoi(websGetVar(wp, sstr, ""));

		/* "ipMask2" is for multiple DMZ hosts spec. */
		sprintf(sstr,"wansm2_%d",i+1);
		ramWanCfgParam.ipMask2[i]= atoi(websGetVar(wp, sstr, ""));
		
	}
	
	wizardSaveToFlash(IFCFGPARAM_CONNTYPE_STATIC);
	sysReinit(past_wanType);
	websRedirect(wp, "/status.asp");	
	//Sys_Restart(wp);	
}

#if defined(CONFIG_RTL865X_PPTPL2TP)||defined(CONFIG_RTL865XB_PPTPL2TP)
/************************************************************
 *	
 *	PPTP Client Setup Function (Wizard)
 *	
 ************************************************************/
void  asp_setPptpWizard(request * wp, char *path, char *query)
{
	int	i;
	int	val=0;
	int	wizard=atoi(websGetVar(wp,"wizard",""));
	char	*valstr;
	char	sstr[8]={0};
	uint32 past_wanType = pRomeCfgParam->ifCfgParam[0].connType;

	if(strcmp(websGetVar(wp,"submit2",""),"Refresh")==0)
	{
		websRedirect(wp,"/wanpptp.asp");
		return;
	}
	else if(strcmp(websGetVar(wp,"submit2",""),"Dial")==0)
	{
		pptp_start(0);		
		sleep(1);
		websRedirect(wp,"/wanpptp.asp");
		return;
	}
	else if(strcmp(websGetVar(wp,"submit2",""),"Hang Up")==0)
	{
		send_signal("/var/run/pppd0.pid",1);
		send_signal("/var/run/ppp0.pid",1);
		sleep(1);
#ifdef __uClinux__
#else
		send_signal("/var/run/pptp.pid",9);	
#endif
		pRomeCfgParam->pptpCfgParam.dialState=PPTPCFGPARAM_DIALSTATE_OFF;
		websRedirect(wp,"/wanpptp.asp");		
		return;
	}	
	else
	{
		memcpy(&ramPptpCfgParam,&pRomeCfgParam->pptpCfgParam,sizeof(ramPptpCfgParam));
		for (i=0;i<4;i++)
		{
			sprintf(sstr,"wanip_%d",i+1);
			ramPptpCfgParam.ipAddr[i]= atoi(websGetVar(wp, sstr, ""));

			sprintf(sstr,"wansv_%d",i+1);
			ramPptpCfgParam.svAddr[i]= atoi(websGetVar(wp, sstr, ""));
	
			sprintf(sstr,"wansm_%d",i+1);
			ramPptpCfgParam.ipMask[i]= atoi(websGetVar(wp, sstr, ""));

			sprintf(sstr,"wangw_%d",i+1);
			ramPptpCfgParam.gwAddr[i]= atoi(websGetVar(wp, sstr, ""));
		}

		valstr=(websGetVar(wp,"username",""));
		memset((char*)ramPptpCfgParam.username,0,sizeof(ramPptpCfgParam.username));
		memcpy((char*)ramPptpCfgParam.username,valstr,strlen(valstr));
		valstr=(websGetVar(wp,"password",""));
		memset((char*)&ramPptpCfgParam.password,0,sizeof(ramPptpCfgParam.password));
		memcpy((char*)&ramPptpCfgParam.password,valstr,strlen(valstr));
		ramPptpCfgParam.mtu=atoi(websGetVar(wp,"wanmtu",""));
		ramPptpCfgParam.silentTimeout=atoi(websGetVar(wp,"silentTimeout",""));
		ramPptpCfgParam.autoReconnect=atoi(websGetVar(wp,"autoReconnect",""));
		ramPptpCfgParam.demand=atoi(websGetVar(wp,"dialOnDemand",""));
		ramPptpCfgParam.authType=atoi(websGetVar(wp,"authType",""));
		if(ramPptpCfgParam.mtu>1460) ramPptpCfgParam.mtu=1460;
		if(wizard==1)
		{
			wizardSaveToFlash(IFCFGPARAM_CONNTYPE_PPTP);
			sysReinit(past_wanType);
			websRedirect(wp, "/status.asp");			
			//Sys_Restart(wp);	
		}
		else
		{			
			memcpy(&pRomeCfgParam->pptpCfgParam,&ramPptpCfgParam,sizeof(ramPptpCfgParam));			
			if(pRomeCfgParam->ifCfgParam[0].connType!=IFCFGPARAM_CONNTYPE_PPTP) configChanged|=CONFIG_CHANGE_CONN_TYPE;
			pRomeCfgParam->ifCfgParam[0].connType=IFCFGPARAM_CONNTYPE_PPTP;			
			cfgmgr_write(CFGMGR_TABID_PPTP,(void*)&ramPptpCfgParam,sizeof(ramPptpCfgParam));
			cfgmgr_write(CFGMGR_TABID_IF,(void*)&pRomeCfgParam->ifCfgParam[0], sizeof(ifCfgParam_t)*MAX_IP_INTERFACE);
			cfgmgr_task();			
			websRedirect(wp,"/wanpptp.asp");
		}	
	}
}

int asp_pptpWizard(request * wp, int argc, char **argv)
{
	int i;
	for(i=0;i<4;i++)		
	{
		char temp[16]={0};
		sprintf(temp,"ip%d",i+1);
		if (strcmp(argv[0],temp)==0) websWrite(wp,"%u",pRomeCfgParam->pptpCfgParam.ipAddr[i]);
		sprintf(temp,"sm%d",i+1);
		if (strcmp(argv[0],temp)==0) websWrite(wp,"%u",pRomeCfgParam->pptpCfgParam.ipMask[i]);
		sprintf(temp,"sv%d",i+1);
		if (strcmp(argv[0],temp)==0) websWrite(wp,"%u",pRomeCfgParam->pptpCfgParam.svAddr[i]);		
		sprintf(temp,"gw%d",i+1);
		if (strcmp(argv[0],temp)==0) websWrite(wp,"%u",pRomeCfgParam->pptpCfgParam.gwAddr[i]);		
	}
	
	if(strcmp(argv[0],"username")==0) {websWrite(wp,"%s",pRomeCfgParam->pptpCfgParam.username);}
	else if(strcmp(argv[0],"password")==0) {websWrite(wp,"%s",pRomeCfgParam->pptpCfgParam.password);}
	else if(strcmp(argv[0],"mtu")==0) {websWrite(wp,"%d",pRomeCfgParam->pptpCfgParam.mtu);}
	else if(strcmp(argv[0],"silentTimeout")==0) {websWrite(wp,"%d",pRomeCfgParam->pptpCfgParam.silentTimeout);}
	else if(strcmp(argv[0],"dialOnDemand")==0){ websWrite(wp,"%s",pRomeCfgParam->pptpCfgParam.demand?"checked":"");}
	else if(strcmp(argv[0],"autoReconnect")==0){ websWrite(wp,"%s",pRomeCfgParam->pptpCfgParam.autoReconnect?"checked":"");}
	else if(strcmp(argv[0],"authTypePap")==0){ websWrite(wp,"%s",(pRomeCfgParam->pptpCfgParam.authType==PPPPARAM_AUTHTYPE_PAP)?"checked":"");}
	else if(strcmp(argv[0],"authTypeChap")==0){ websWrite(wp,"%s",(pRomeCfgParam->pptpCfgParam.authType==PPPPARAM_AUTHTYPE_CHAP)?"checked":"");}
	else if(strcmp(argv[0],"autoRefresh")==0)
	{
		if((pRomeCfgParam->pptpCfgParam.dialState==PPTPCFGPARAM_DIALSTATE_DIALED_TRYING)||(pRomeCfgParam->pptpCfgParam.dialState==PPTPCFGPARAM_DIALSTATE_DISCONNECTING))
    	{
			websWrite(wp,"<META HTTP-EQUIV=Refresh CONTENT=\"2; URL=wanpptp.asp\">");
    	}
	}
	else if(strcmp(argv[0],"dialStatus")==0) 
	{
		char tempStr[32];
		getDialStateString(0+MAX_PPPOE_SESSION,tempStr);
		websWrite(wp,"%s",tempStr);
	}
	else if(strcmp(argv[0],"submit")==0) 
	{
		if(atoi(websGetVar(wp,"wizard",""))==1)
		{
    		websWrite(wp,"<input type=hidden name=\"wizard\" value=1>" \
    		"<input type=\"button\" value=\"< Back\" onclick=\"javascript:history.back();\">" \
	    	"&nbsp;&nbsp;&nbsp;&nbsp;" \
    		"<input type=\"submit\" value=\"Save and Reinit\">" \
    		"&nbsp;&nbsp;&nbsp;&nbsp;" \
	    	"<input type=\"reset\" value=\"Reset\">" \
    		"&nbsp;&nbsp;&nbsp;&nbsp;" \
    		"<input type=\"button\" value=\"Cancel\" onclick=\"javascript:location.replace('status.asp');\">");
		}
		else
		{
			int dialOn=0,hangupOn=1;			
			if(pRomeCfgParam->pptpCfgParam.dialState==PPTPCFGPARAM_DIALSTATE_OFF) dialOn=1;
			//if(pRomeCfgParam->pptpCfgParam.dialState==PPTPCFGPARAM_DIALSTATE_DIALED_TRYING) hangupOn=0;
			if(pRomeCfgParam->pptpCfgParam.dialState==PPTPCFGPARAM_DIALSTATE_DISCONNECTING) hangupOn=0;

			if((pRomeCfgParam->ifCfgParam[0].connType!=IFCFGPARAM_CONNTYPE_PPTP)||(configChanged&CONFIG_CHANGE_CONN_TYPE))
			{
				dialOn=0; 
				hangupOn=0;
			}
			
			websWrite(wp,"<input type=submit value=Dial name=submit2 %s>&nbsp;" \
			"<input type=submit value=\"Hang Up\" name=submit2 %s>&nbsp;&nbsp;&nbsp;&nbsp;" \
			"<input type=submit value=\"Save\" name=submit2>&nbsp;" \
			"<input type=submit value=\"Refresh\" name=submit2>&nbsp;" \
			"<input type=reset value=\"Reset\">",(!dialOn)?"disabled":"",(!hangupOn)?"disabled":"");
		}
	}
	
	return 0;
}
#endif

#if defined(CONFIG_RTL865X_PPTPL2TP)||defined(CONFIG_RTL865XB_PPTPL2TP)
/************************************************************
 *	
 *	L2TP Client Setup Function (Wizard)
 *	
 ************************************************************/
void  asp_setL2tpWizard(request * wp, char *path, char *query)
{
	int 	i;
	int    val=0;
	int	wizard=atoi(websGetVar(wp,"wizard",""));
	char *valstr;
	char	sstr[8]={0};
	uint32 past_wanType = pRomeCfgParam->ifCfgParam[0].connType;
	
	if(strcmp(websGetVar(wp,"submit2",""),"Refresh")==0)
	{
		websRedirect(wp,"/wanl2tp.asp");
		return;
	}
	else if(strcmp(websGetVar(wp,"submit2",""),"Dial")==0)
	{
		l2tp_start(0);		
		sleep(1);
		websRedirect(wp,"/wanl2tp.asp");
		return;
	}
	else if(strcmp(websGetVar(wp,"submit2",""),"Hang Up")==0)
	{

		send_signal("/var/run/pppd0.pid",1);
		sleep(1);	
#ifdef __uClinux__
#else		
//		send_signal("/var/run/l2tpd.pid",9);
#endif

		websRedirect(wp,"/wanl2tp.asp");
		return;
	}	
	else
	{

		memcpy(&ramL2tpCfgParam,&pRomeCfgParam->l2tpCfgParam,sizeof(l2tpCfgParam_t));
		for (i=0;i<4;i++)
		{
			sprintf(sstr,"wanip_%d",i+1);
			ramL2tpCfgParam.ipAddr[i]= atoi(websGetVar(wp, sstr, ""));
	
			sprintf(sstr,"wansv_%d",i+1);
			ramL2tpCfgParam.svAddr[i]= atoi(websGetVar(wp, sstr, ""));
		
			sprintf(sstr,"wansm_%d",i+1);
			ramL2tpCfgParam.ipMask[i]= atoi(websGetVar(wp, sstr, ""));

			sprintf(sstr,"wangw_%d",i+1);
			ramL2tpCfgParam.gwAddr[i]= atoi(websGetVar(wp, sstr, ""));
		}

		valstr=(websGetVar(wp,"username",""));
		memset((char*)ramL2tpCfgParam.username,0,sizeof(ramL2tpCfgParam.username));
		memcpy((char*)ramL2tpCfgParam.username,valstr,strlen(valstr));
		valstr=(websGetVar(wp,"password",""));
		memset((char*)&ramL2tpCfgParam.password,0,sizeof(ramL2tpCfgParam.password));
		memcpy((char*)&ramL2tpCfgParam.password,valstr,strlen(valstr));
		ramL2tpCfgParam.mtu=atoi(websGetVar(wp,"wanmtu",""));
		ramL2tpCfgParam.silentTimeout=atoi(websGetVar(wp,"silentTimeout",""));
		ramL2tpCfgParam.autoReconnect=atoi(websGetVar(wp,"autoReconnect",""));
		ramL2tpCfgParam.demand=atoi(websGetVar(wp,"dialOnDemand",""));	
		ramL2tpCfgParam.authType=atoi(websGetVar(wp,"authType",""));		
		if(ramL2tpCfgParam.mtu>1452) ramL2tpCfgParam.mtu=1452;
		if(wizard==1)
		{	
			wizardSaveToFlash(IFCFGPARAM_CONNTYPE_L2TP);
			sysReinit(past_wanType);
			websRedirect(wp, "/status.asp");			
			//Sys_Restart(wp);	
		}
		else
		{

			memcpy(&pRomeCfgParam->l2tpCfgParam,&ramL2tpCfgParam,sizeof(l2tpCfgParam_t));
			if(pRomeCfgParam->ifCfgParam[0].connType!=IFCFGPARAM_CONNTYPE_L2TP) configChanged|=CONFIG_CHANGE_CONN_TYPE;
			pRomeCfgParam->ifCfgParam[0].connType=IFCFGPARAM_CONNTYPE_L2TP;			
			cfgmgr_write(CFGMGR_TABID_L2TP,(void*)&ramL2tpCfgParam,sizeof(l2tpCfgParam_t));
			cfgmgr_write(CFGMGR_TABID_IF,(void*)&pRomeCfgParam->ifCfgParam[0], sizeof(ifCfgParam_t)*MAX_IP_INTERFACE);
			cfgmgr_task();
			websRedirect(wp,"/wanl2tp.asp");
		}		
	}
}


int asp_l2tpWizard(request * wp, int argc, char **argv)
{
	int i;
	for(i=0;i<4;i++)		
	{
		char temp[16]={0};
		sprintf(temp,"ip%d",i+1);
		if (strcmp(argv[0],temp)==0) websWrite(wp,"%u",pRomeCfgParam->l2tpCfgParam.ipAddr[i]);
		sprintf(temp,"sm%d",i+1);
		if (strcmp(argv[0],temp)==0) websWrite(wp,"%u",pRomeCfgParam->l2tpCfgParam.ipMask[i]);
		sprintf(temp,"sv%d",i+1);
		if (strcmp(argv[0],temp)==0) websWrite(wp,"%u",pRomeCfgParam->l2tpCfgParam.svAddr[i]);		
		sprintf(temp,"gw%d",i+1);
		if (strcmp(argv[0],temp)==0) websWrite(wp,"%u",pRomeCfgParam->l2tpCfgParam.gwAddr[i]);		
	}
	if(strcmp(argv[0],"username")==0) {websWrite(wp,"%s",pRomeCfgParam->l2tpCfgParam.username);}
	else if(strcmp(argv[0],"password")==0) {websWrite(wp,"%s",pRomeCfgParam->l2tpCfgParam.password);}
	else if(strcmp(argv[0],"mtu")==0) {websWrite(wp,"%d",pRomeCfgParam->l2tpCfgParam.mtu);}
	else if(strcmp(argv[0],"silentTimeout")==0) {websWrite(wp,"%d",pRomeCfgParam->l2tpCfgParam.silentTimeout);}
	else if(strcmp(argv[0],"dialOnDemand")==0) {websWrite(wp,"%s",pRomeCfgParam->l2tpCfgParam.demand?"checked":"");	}
	else if(strcmp(argv[0],"autoReconnect")==0) {websWrite(wp,"%s",pRomeCfgParam->l2tpCfgParam.autoReconnect?"checked":"");}
	else if(strcmp(argv[0],"authTypePap")==0){ websWrite(wp,"%s",(pRomeCfgParam->l2tpCfgParam.authType==PPPPARAM_AUTHTYPE_PAP)?"checked":"");}
	else if(strcmp(argv[0],"authTypeChap")==0){ websWrite(wp,"%s",(pRomeCfgParam->l2tpCfgParam.authType==PPPPARAM_AUTHTYPE_CHAP)?"checked":"");}
	else if(strcmp(argv[0],"autoRefresh")==0)
	{
		if((pRomeCfgParam->l2tpCfgParam.dialState==L2TPCFGPARAM_DIALSTATE_DIALED_TRYING)||(pRomeCfgParam->l2tpCfgParam.dialState==L2TPCFGPARAM_DIALSTATE_DISCONNECTING))
    	{
			websWrite(wp,"<META HTTP-EQUIV=Refresh CONTENT=\"2; URL=wanl2tp.asp\">");
    	}
	}
	else if(strcmp(argv[0],"dialStatus")==0) 
	{
		char tempStr[32];
		getDialStateString(1+MAX_PPPOE_SESSION,tempStr); //l2tp
		websWrite(wp,"%s",tempStr);
	}
	else if(strcmp(argv[0],"submit")==0) 
	{
		if(atoi(websGetVar(wp,"wizard",""))==1)
		{
    		websWrite(wp,"<input type=hidden name=\"wizard\" value=1>" \
    		"<input type=\"button\" value=\"< Back\" onclick=\"javascript:history.back();\">" \
	    	"&nbsp;&nbsp;&nbsp;&nbsp;" \
    		"<input type=\"submit\" value=\"Save and Reinit\">" \
    		"&nbsp;&nbsp;&nbsp;&nbsp;" \
	    	"<input type=\"reset\" value=\"Reset\">" \
    		"&nbsp;&nbsp;&nbsp;&nbsp;" \
    		"<input type=\"button\" value=\"Cancel\" onclick=\"javascript:location.replace('status.asp');\">");
		}
		else
		{
			int dialOn=0,hangupOn=1;			
			if(pRomeCfgParam->l2tpCfgParam.dialState==L2TPCFGPARAM_DIALSTATE_OFF) dialOn=1;
			else if(pRomeCfgParam->l2tpCfgParam.dialState==L2TPCFGPARAM_DIALSTATE_DIALED_DHCP_DISCOVER) dialOn=1;
			else if(pRomeCfgParam->l2tpCfgParam.dialState==L2TPCFGPARAM_DIALSTATE_DIALED_TRYING) hangupOn=0;

			if((!((pRomeCfgParam->ifCfgParam[0].connType==IFCFGPARAM_CONNTYPE_L2TP)||
				  (pRomeCfgParam->ifCfgParam[0].connType==IFCFGPARAM_CONNTYPE_DHCPL2TP)))||
				  (configChanged&CONFIG_CHANGE_CONN_TYPE))
			{
				dialOn=0; 
				hangupOn=0;
			}
			
			websWrite(wp,"<input type=submit value=Dial name=submit2 %s>&nbsp;" \
			"<input type=submit value=\"Hang Up\" name=submit2 %s>&nbsp;&nbsp;&nbsp;&nbsp;" \
			"<input type=submit value=\"Save\" name=submit2>&nbsp;" \
			"<input type=submit value=\"Refresh\" name=submit2>&nbsp;" \
			"<input type=reset value=\"Reset\">",(!dialOn)?"disabled":"",(!hangupOn)?"disabled":"");
		}
	}
	
	return 0;
}




void  asp_setDhcpL2tpWizard(request * wp, char *path, char *query)
{
	int 	i;
	int    val=0;
	int	wizard=atoi(websGetVar(wp,"wizard",""));
	char *valstr;
	char	sstr[8]={0};
	uint32 past_wanType = pRomeCfgParam->ifCfgParam[0].connType;
	
	if(strcmp(websGetVar(wp,"submit2",""),"Refresh")==0)
	{
		websRedirect(wp,"/wandhcpl2tp.asp");
		return;
	}
	else if(strcmp(websGetVar(wp,"submit2",""),"Dial")==0)
	{
		l2tp_start(0);		
		sleep(1);
		websRedirect(wp,"/wandhcpl2tp.asp");
		return;
	}
	else if(strcmp(websGetVar(wp,"submit2",""),"Hang Up")==0)
	{
		send_signal("/var/run/pppd0.pid",1);		
		sleep(1);	
#ifdef __uClinux__
#else		
//		send_signal("/var/run/l2tpd.pid",9);
#endif		
		websRedirect(wp,"/wandhcpl2tp.asp");
		return;
	}	
	else
	{

		memcpy(&ramL2tpCfgParam,&pRomeCfgParam->l2tpCfgParam,sizeof(l2tpCfgParam_t));
		valstr=(websGetVar(wp,"username",""));
		memset((char*)ramL2tpCfgParam.username,0,sizeof(ramL2tpCfgParam.username));
		memcpy((char*)ramL2tpCfgParam.username,valstr,strlen(valstr));
		valstr=(websGetVar(wp,"password",""));
		memset((char*)&ramL2tpCfgParam.password,0,sizeof(ramL2tpCfgParam.password));
		memcpy((char*)&ramL2tpCfgParam.password,valstr,strlen(valstr));
		ramL2tpCfgParam.mtu=atoi(websGetVar(wp,"wanmtu",""));
		ramL2tpCfgParam.silentTimeout=atoi(websGetVar(wp,"silentTimeout",""));
		ramL2tpCfgParam.autoReconnect=atoi(websGetVar(wp,"autoReconnect",""));
		ramL2tpCfgParam.demand=atoi(websGetVar(wp,"dialOnDemand",""));	
		ramL2tpCfgParam.authType=atoi(websGetVar(wp,"authType",""));			
		if(ramL2tpCfgParam.mtu>1452) ramL2tpCfgParam.mtu=1452;
		if(wizard==1)
		{
			wizardSaveToFlash(IFCFGPARAM_CONNTYPE_DHCPL2TP);
			sysReinit(past_wanType);
			websRedirect(wp, "/status.asp");			
			//Sys_Restart(wp);	
		}
		else
		{

			memcpy(&pRomeCfgParam->l2tpCfgParam,&ramL2tpCfgParam,sizeof(l2tpCfgParam_t));
			if(pRomeCfgParam->ifCfgParam[0].connType!=IFCFGPARAM_CONNTYPE_DHCPL2TP) configChanged|=CONFIG_CHANGE_CONN_TYPE;
			pRomeCfgParam->ifCfgParam[0].connType=IFCFGPARAM_CONNTYPE_DHCPL2TP;			
			cfgmgr_write(CFGMGR_TABID_L2TP,(void*)&ramL2tpCfgParam,sizeof(l2tpCfgParam_t));
			cfgmgr_write(CFGMGR_TABID_IF,(void*)&pRomeCfgParam->ifCfgParam[0], sizeof(ifCfgParam_t)*MAX_IP_INTERFACE);
			cfgmgr_task();
			websRedirect(wp,"/wandhcpl2tp.asp");
		}		
	}
}


int asp_dhcpL2tpWizard(request * wp, int argc, char **argv)
{
	int i;
	
	if(strcmp(argv[0],"username")==0) {websWrite(wp,"%s",pRomeCfgParam->l2tpCfgParam.username);}
	else if(strcmp(argv[0],"password")==0) {websWrite(wp,"%s",pRomeCfgParam->l2tpCfgParam.password);}
	else if(strcmp(argv[0],"mtu")==0) {websWrite(wp,"%d",pRomeCfgParam->l2tpCfgParam.mtu);	}
	else if(strcmp(argv[0],"silentTimeout")==0) {websWrite(wp,"%d",pRomeCfgParam->l2tpCfgParam.silentTimeout);}
	else if(strcmp(argv[0],"dialOnDemand")==0) {websWrite(wp,"%s",pRomeCfgParam->l2tpCfgParam.demand?"checked":"");}	
	else if(strcmp(argv[0],"autoReconnect")==0) {websWrite(wp,"%s",pRomeCfgParam->l2tpCfgParam.autoReconnect?"checked":"");}
	else if(strcmp(argv[0],"authTypePap")==0){ websWrite(wp,"%s",(pRomeCfgParam->l2tpCfgParam.authType==PPPPARAM_AUTHTYPE_PAP)?"checked":"");}
	else if(strcmp(argv[0],"authTypeChap")==0){ websWrite(wp,"%s",(pRomeCfgParam->l2tpCfgParam.authType==PPPPARAM_AUTHTYPE_CHAP)?"checked":"");}
	else if(strcmp(argv[0],"dialStatus")==0) 
	{
		char tempStr[32];
		getDialStateString(1+MAX_PPPOE_SESSION,tempStr); //l2tp
		websWrite(wp,"%s",tempStr);
	}
	else if(strcmp(argv[0],"submit")==0) 
	{
		if(atoi(websGetVar(wp,"wizard",""))==1)
		{
    		websWrite(wp,"<input type=hidden name=\"wizard\" value=1>" \
    		"<input type=\"button\" value=\"< Back\" onclick=\"javascript:history.back();\">" \
	    	"&nbsp;&nbsp;&nbsp;&nbsp;" \
    		"<input type=\"submit\" value=\"Save and Reinit\">" \
    		"&nbsp;&nbsp;&nbsp;&nbsp;" \
	    	"<input type=\"reset\" value=\"Reset\">" \
    		"&nbsp;&nbsp;&nbsp;&nbsp;" \
    		"<input type=\"button\" value=\"Cancel\" onclick=\"javascript:location.replace('status.asp');\">");
		}
		else
		{
			int dialOn=0,hangupOn=1;			
			if(pRomeCfgParam->l2tpCfgParam.dialState==L2TPCFGPARAM_DIALSTATE_OFF) dialOn=1;
			if(pRomeCfgParam->l2tpCfgParam.dialState==L2TPCFGPARAM_DIALSTATE_DIALED_TRYING) hangupOn=0;

			if((pRomeCfgParam->ifCfgParam[0].connType!=IFCFGPARAM_CONNTYPE_DHCPL2TP)||(configChanged&CONFIG_CHANGE_CONN_TYPE))
			{
				dialOn=0; 
				hangupOn=0;
			}
			
			websWrite(wp,"<input type=submit value=Dial name=submit2 %s>&nbsp;" \
			"<input type=submit value=\"Hang Up\" name=submit2 %s>&nbsp;&nbsp;&nbsp;&nbsp;" \
			"<input type=submit value=\"Save\" name=submit2>&nbsp;" \
			"<input type=submit value=\"Refresh\" name=submit2>&nbsp;" \
			"<input type=reset value=\"Reset\">",(!dialOn)?"disabled":"",(!hangupOn)?"disabled":"");
		}
	}
	
	return 0;
}

#endif

/************************************************************
 *	
 *	DHCP Client Setup Function (Wizard)
 *	
 ************************************************************/
void asp_setDhcpClient(request * wp, char *path, char *query)
{	
	int i=0;
	char str[8];
	uint32 past_wanType = pRomeCfgParam->ifCfgParam[0].connType;
	
	if (!strcmp(websGetVar(wp,T("cmacToggle"),T("")),"on"))
	{
		ramDhcpcCfgParam.cmacValid=1;
		for (i=0;i<6;i++)
		{
			sprintf(str,"cmac%d",i+1);
			ramDhcpcCfgParam.cloneMac[i]=strtol(websGetVar(wp, T(str), T("")),NULL,16 ); 
		}
	}
	else
		ramDhcpcCfgParam.cmacValid=0;
	
	wizardSaveToFlash(IFCFGPARAM_CONNTYPE_DHCPC);
	sysReinit(past_wanType);
	websRedirect(wp, "/status.asp");
	//Sys_Restart(wp);	
}

/************************************************************
 *	
 *	PPPoE (Wizard)
 *	
 ************************************************************/
void asp_setPppoeWizard(request * wp, char *path, char *query)
{
	char *valstr;
	uint32 past_wanType = pRomeCfgParam->ifCfgParam[0].connType;


	valstr=(websGetVar(wp,"username0",""));
	DEBUG_P(stderr,"user %s\n",valstr);
	memset((char*)&ramPppoeCfgParam[0].username,0,sizeof(ramPppoeCfgParam[0].username));
	memcpy((char*)&ramPppoeCfgParam[0].username,valstr,strlen(valstr));
	valstr=(websGetVar(wp,"password0",""));		
	DEBUG_P(stderr,"passwd %s\n",valstr);
	memset((char*)&ramPppoeCfgParam[0].password,0,sizeof(ramPppoeCfgParam[0].password));
	memcpy((char*)&ramPppoeCfgParam[0].password,valstr,strlen(valstr));
	valstr=(websGetVar(wp,"serviceName0",""));
	memset((char*)&ramPppoeCfgParam[0].serviceName,0,sizeof(ramPppoeCfgParam[0].serviceName));
	memcpy((char*)&ramPppoeCfgParam[0].serviceName,valstr,strlen(valstr));
	valstr=(websGetVar(wp,"acName0",""));
	memset((char*)&ramPppoeCfgParam[0].acName,0,sizeof(ramPppoeCfgParam[0].acName));
	memcpy((char*)&ramPppoeCfgParam[0].acName,valstr,strlen(valstr));

	pRomeCfgParam->pppoeCfgParam[0].authType=atoi(websGetVar(wp,"authType0",""));

	ramPppoeCfgParam[0].mtu=atoi(websGetVar(wp,"mtu0",""));	
	if(ramPppoeCfgParam[0].mtu>1492) ramPppoeCfgParam[0].mtu=1492;
	if(ramPppoeCfgParam[0].mtu<576) ramPppoeCfgParam[0].mtu=576;
	ramPppoeCfgParam[0].demand=atoi(websGetVar(wp,"demand0",""));
	ramPppoeCfgParam[0].silentTimeout=atoi(websGetVar(wp,"silentTimeout0",""));
	ramPppoeCfgParam[0].autoReconnect=atoi(websGetVar(wp,"autoReconnect0",""));


	wizardSaveToFlash(IFCFGPARAM_CONNTYPE_PPPOE);

	sysReinit(past_wanType);
	websRedirect(wp, "/status.asp");
	//Sys_Restart(wp);	
}

/************************************************************
 *	
 *	Unnumbered PPPoE (Wizard)
 *	
 ************************************************************/
void asp_setUnnumberedWizard(request * wp, char *path, char *query)
{
	char *valstr;
	int i;
	char tempStr[20]={0};
	uint32 netmask=0xffffffff;
	uint8 *netmask_p=(uint8 *)&netmask;
	uint32 past_wanType = pRomeCfgParam->ifCfgParam[0].connType;
	
	valstr=(websGetVar(wp,"username0",""));
	DEBUG_P(stderr,"user %s\n",valstr);
	memset((char*)&ramPppoeCfgParam[0].username,0,sizeof(ramPppoeCfgParam[0].username));
	memcpy((char*)&ramPppoeCfgParam[0].username,valstr,strlen(valstr));
	valstr=(websGetVar(wp,"password0",""));		
	DEBUG_P(stderr,"passwd %s\n",valstr);
	memset((char*)&ramPppoeCfgParam[0].password,0,sizeof(ramPppoeCfgParam[0].password));
	memcpy((char*)&ramPppoeCfgParam[0].password,valstr,strlen(valstr));
	valstr=(websGetVar(wp,"serviceName0",""));
	memset((char*)&ramPppoeCfgParam[0].serviceName,0,sizeof(ramPppoeCfgParam[0].serviceName));
	memcpy((char*)&ramPppoeCfgParam[0].serviceName,valstr,strlen(valstr));
	valstr=(websGetVar(wp,"acName0",""));
	memset((char*)&ramPppoeCfgParam[0].acName,0,sizeof(ramPppoeCfgParam[0].acName));
	memcpy((char*)&ramPppoeCfgParam[0].acName,valstr,strlen(valstr));

	ramPppoeCfgParam[0].mtu=atoi(websGetVar(wp,"mtu0",""));	
	if(ramPppoeCfgParam[0].mtu>1492) ramPppoeCfgParam[0].mtu=1492;
	if(ramPppoeCfgParam[0].mtu<576) ramPppoeCfgParam[0].mtu=576;
		
	ramPppoeCfgParam[0].demand=atoi(websGetVar(wp,"demand0",""));
	ramPppoeCfgParam[0].silentTimeout=atoi(websGetVar(wp,"silentTimeout0",""));
	ramPppoeCfgParam[0].autoReconnect=atoi(websGetVar(wp,"autoReconnect0",""));
	ramPppoeCfgParam[0].unnumberedNapt=atoi(websGetVar(wp,"unnumberedNapt",""));

	for(i=0;i<4;i++)
	{
		sprintf(tempStr,"unnumberedIpAddr%d",i+1);
		ramPppoeCfgParam[0].unnumberedIpAddr[i]=atoi(websGetVar(wp,tempStr,""));
	}

	netmask=(netmask>>(32-atoi(websGetVar(wp,"unnumberedIpMask",""))))<<(32-atoi(websGetVar(wp,"unnumberedIpMask","")));
	ramPppoeCfgParam[0].unnumberedIpMask[0]=netmask_p[0];
	ramPppoeCfgParam[0].unnumberedIpMask[1]=netmask_p[1];
	ramPppoeCfgParam[0].unnumberedIpMask[2]=netmask_p[2];
	ramPppoeCfgParam[0].unnumberedIpMask[3]=netmask_p[3];
		
	wizardSaveToFlash(IFCFGPARAM_CONNTYPE_PPPOE_UNNUMBERED);
	sysReinit(past_wanType);
	websRedirect(wp, "/status.asp");
	
	//Sys_Restart(wp);	
}

#if 0
int asp_aclPage(request * wp, int argc, char **argv)
{
	if (pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L4GATEWAYMODE) {
		websWrite(wp, "acl.asp");
	}
	else {
		websWrite(wp, "error.asp");
	}

	return 0;
}
#endif

int asp_serverpPage(request * wp, int argc, char **argv)
{
	if (pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L4GATEWAYMODE) {
		websWrite(wp, "<a href=\"serverp.asp\" target=\"show_area\"><span style=\"font-size: 12pt;\">Virtual Server*</span></a>");
	}
	else {
		websWrite(wp, "<span style=\"font-size: 12pt;\">Virtual Server*</span>");
	}

	return 0;
}

int asp_urlfilterPage(request * wp, int argc, char **argv)
{
	if (pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L4GATEWAYMODE) {
		websWrite(wp, "<a href=\"urlfilter.asp\" target=\"show_area\"><span style=\"font-size: 12pt;\">URL Filter*</span></a>");
	}
	else {
		websWrite(wp, "<span style=\"font-size: 12pt;\">URL Filter*</span>");
	}

	return 0;
}

int asp_qosPage(request * wp, int argc, char **argv)
{
	if (pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L4GATEWAYMODE) {
		websWrite(wp, "<a href=\"qos.asp\" target=\"show_area\"><span style=\"font-size: 12pt;\">Port-based QoS*</span></a>");
	}
	else {
		websWrite(wp, "<span style=\"font-size: 12pt;\">Port-based QoS*</span>");
	}

	return 0;
}

int asp_ratelimitPage(request * wp, int argc, char **argv)
{
	if (pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L4GATEWAYMODE) {
		websWrite(wp, "<a href=\"ratelimit.asp\" target=\"show_area\"><span style=\"font-size: 12pt;\">Rate Policing QoS*</span></a>");
	}
	else {
		websWrite(wp, "<span style=\"font-size: 12pt;\">Rate Policing QoS*</span>");
	}

	return 0;
}

int asp_ratio_qosPage(request * wp, int argc, char **argv)
{
	if (pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L4GATEWAYMODE) {
		websWrite(wp, "<a href=\"ratio_qos.asp\" target=\"show_area\"><span style=\"font-size: 12pt;\">Guaranteed/Spare Class QoS*</span></a>");
	}
	else {
		websWrite(wp, "<span style=\"font-size: 12pt;\">Guaranteed/Spare Class QoS*</span>");
	}

	return 0;
}

int asp_routingPage(request * wp, int argc, char **argv)
{
	if (pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L4GATEWAYMODE || pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L3ROUTERMODE) {
		websWrite(wp, "<a href=\"routing.asp\" target=\"show_area\"><span style=\"font-size: 12pt;\">Static Route*</span></a>");
	}
	else {
		websWrite(wp, "<span style=\"font-size: 12pt;\">Static Route*</span>");
	}

	return 0;
}

int asp_ripPage(request * wp, int argc, char **argv)
{
	if (pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L4GATEWAYMODE || pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L3ROUTERMODE) {
#ifdef CONFIG_USER_ZEBRA_RIPD_RIPD
		websWrite(wp, "<a href=\"rip.asp\" target=\"show_area\"><span style=\"font-size: 12pt;\">RIP</span></a>");
#else
		websWrite(wp, "<span style=\"font-size: 11pt;\">RIP</span>");
#endif
	}
	else {
		websWrite(wp, "<span style=\"font-size: 12pt;\">RIP</span>");
	}

	return 0;
}

int asp_ddnsPage(request * wp, int argc, char **argv)
{
	if (pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L4GATEWAYMODE) {
		websWrite(wp, "<a href=\"ddns.asp\" target=\"show_area\"><span style=\"font-size: 12pt;\">Dynamic DNS</span></a>");
	}
	else {
		websWrite(wp, "<span style=\"font-size: 12pt;\">Dynamic DNS</span>");
	}

	return 0;
}

int asp_specialapPage(request * wp, int argc, char **argv)
{
	if (pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L4GATEWAYMODE) {
		websWrite(wp, "<a href=\"specialap.asp\" target=\"show_area\"><span style=\"font-size: 12pt;\">Special Application</span></a>");
	}
	else {
		websWrite(wp, "<span style=\"font-size: 12pt;\">Special Application</span>");
	}

	return 0;
}

int asp_gamingPage(request * wp, int argc, char **argv)
{
	if (pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L4GATEWAYMODE) {
		websWrite(wp, "<a href=\"gaming.asp\" target=\"show_area\"><span style=\"font-size: 12pt;\">Gaming</span></a>");
	}
	else {
		websWrite(wp, "<span style=\"font-size: 12pt;\">Gaming</span>");
	}
	return 0;
}


int asp_algPage(request * wp, int argc, char **argv)
{
	if (pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L4GATEWAYMODE) {
		websWrite(wp, "<a href=\"alg.asp\" target=\"show_area\"><span style=\"font-size: 12pt;\">ALG</span></a>");
	}
	else {
		websWrite(wp, "<span style=\"font-size: 12pt;\">ALG</span>");
	}

	return 0;
}

int asp_dmzPage(request * wp, int argc, char **argv)
{
	if (pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L4GATEWAYMODE) {
		websWrite(wp, "<a href=\"dmz.asp\" target=\"show_area\"><span style=\"font-size: 12pt;\">DMZ Host*</span></a>");
	}
	else {
		websWrite(wp, "<span style=\"font-size: 12pt;\">DMZ Host*</span>");
	}

	return 0;
}

int asp_dosPage(request * wp, int argc, char **argv)
{
	if (pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L4GATEWAYMODE) {
		websWrite(wp, "<a href=\"dos.asp\" target=\"show_area\"><span style=\"font-size: 12pt;\">Anti-DoS</span></a>");
	}
	else {
		websWrite(wp, "<span style=\"font-size: 12pt;\">Anti-DoS</span>");
	}

	return 0;
}

int asp_udpblockingPage(request * wp, int argc, char **argv)
{
	if (pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L4GATEWAYMODE) {
		websWrite(wp, "<a href=\"udpblocking.asp\" target=\"show_area\"><span style=\"font-size: 12pt;\">UDP Blocking</span></a>");
	}
	else {
		websWrite(wp, "<span style=\"font-size: 12pt;\">UDP Blocking</span>");
	}

	return 0;
}

int asp_pbnatPage(request * wp, int argc, char **argv)
{
	if (pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L4GATEWAYMODE) {
		websWrite(wp, "<a href=\"pbnat.asp\" target=\"show_area\"><span style=\"font-size: 12pt;\">Protocol-based NAT</span></a>");
	}
	else {
		websWrite(wp, "<span style=\"font-size: 12pt;\">Protocol-based NAT</span>");
	}

	return 0;
}

int asp_pingPage(request * wp, int argc, char **argv)
{
	if (pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L4GATEWAYMODE) {
		websWrite(wp, "<a href=\"ping.asp\" target=\"show_area\"><span style=\"font-size: 12pt;\">Ping toolkit</span></a>");
	}
	else {
		websWrite(wp, "<span style=\"font-size: 12pt;\">Ping toolkit</span>");
	}

	return 0;
}

int asp_naptoptPage(request * wp, int argc, char **argv)
{
	if (pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L4GATEWAYMODE) {
		websWrite(wp, "<a href=\"naptopt.asp\" target=\"show_area\"><span style=\"font-size: 12pt;\">NAPT options*</span></a>");
	}
	else {
		websWrite(wp, "<span style=\"font-size: 12pt;\">NAPT options*</span>");
	}

	return 0;
}

int asp_pseudovlanPage(request * wp, int argc, char **argv)
{
	if (pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L4GATEWAYMODE) {
		websWrite(wp, "<a href=\"pseudovlan.asp\" target=\"show_area\"><span style=\"font-size: 12pt;\">Pseudo-VLAN</span></a>");
	}
	else {
		websWrite(wp, "<span style=\"font-size: 12pt;\">Pseudo-VLAN</span>");
	}

	return 0;
}

int asp_passthruPage(request * wp, int argc, char **argv)
{
	if (pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L4GATEWAYMODE) {
		websWrite(wp, "<a href=\"passthru.asp\" target=\"show_area\"><span style=\"font-size: 12pt;\">PPPoE/IPv6 Passthru*</span></a>");
	}
	else {
		websWrite(wp, "<span style=\"font-size: 12pt;\">PPPoE/IPv6 Passthru*</span>");
	}

	return 0;
}

int asp_mcastPage(request * wp, int argc, char **argv)
{
	if (pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L4GATEWAYMODE) {
		websWrite(wp, "<a href=\"mcast.asp\" target=\"show_area\"><span style=\"font-size: 12pt;\">IP Multicast*</span></a>");
	}
	else {
		websWrite(wp, "<span style=\"font-size: 12pt;\">IP Multicast*</span>");
	}

	return 0;
}

int asp_bittorrentPage(request * wp, int argc, char **argv)
{
	if (pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L4GATEWAYMODE) {
		websWrite(wp, "<a href=\"bittorrent.asp\" target=\"show_area\"><span style=\"font-size: 12pt;\">BitTorrent Download</span></a>");
	}
	else {
		websWrite(wp, "<span style=\"font-size: 12pt;\">BitTorrent Download</span>");
	}

	return 0;
}

int asp_domainBlocktPage(request * wp, int argc, char **argv)
{
	if (pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L4GATEWAYMODE) {
		websWrite(wp, "<a href=\"dblock.asp\" target=\"show_area\"><span style=\"font-size: 12pt;\">Domain Blocking</span></a>");
	}
	else {
		websWrite(wp, "<span style=\"font-size: 12pt;\">Domain Blocking</span>");
	}

	return 0;
}


int asp_pptpdPage(request * wp, int argc, char **argv)
{
#ifdef CONFIG_RTL865XB_PPTPSERVER
	websWrite(wp, "<a href=\"pptp_basic.asp\" target=\"show_area\"><span style=\"font-size: 12pt;\">PPTP Server</span></a>");
#else
	websWrite(wp, "<span style=\"font-size: 12pt;\">PPTP Server</span>");
#endif
	return 0;
}

/************************************************************
 *	
 *	ACL
 *	
 ************************************************************/
int asp_acl(request * wp, int argc, char **argv)
{
	int i,j;
	int ms=0;

#if 0		
	websWrite(wp,		
	"function checkall()\n" \
	"{\n" \
	"	for(i=1;i<=%d;i++)	\n" \
	"		fm.elements[i*8].checked=true;\n" \
	"}\n" \
	"function uncheckall()\n" \
	"{\n" \
	"	for(i=1;i<=%d;i++)\n" \
	"		fm.elements[i*8].checked=false;\n" \
	"}\n" \
	"</script>\n" ,MAX_ACL,MAX_ACL);
#else
	websWrite(wp,"</script>");
#endif
	
	websWrite(wp,
	"<body bgcolor=\"#ffffff\" text=\"#000000\">\n" \
	"<b>Hardware Access Control List</b><BR>");

	ms=asp_multiSession(wp,argc,argv);

	websWrite(wp,		
		"<form action=\"acl.asp\" name=\"fn\"><input type=hidden name=ms value=0></form>\n" \
		"<form method=post action=\"/goform/asp_setAcl\" name=fm>\n" \
		"<B>Policy:</B><select name=\"policy\">" \
		"<option value=0 %s>Allow all except ACL (without log)</option>" \
/*		"<option value=1 %s>Deny all except ACL.</option>" \
		"<option value=2 %s>Deny all L34 packets except ACL (L2 permitted)</option>" \					*/
		"<option value=3 %s>Allow all except ACL (with log)</select><BR><BR>",
		(pRomeCfgParam->aclGlobalCfgParam.policy==0)?"selected":"",
/*
		(pRomeCfgParam->aclGlobalCfgParam.policy==1)?"selected":"",
		(pRomeCfgParam->aclGlobalCfgParam.policy==2)?"selected":"",
*/
		(pRomeCfgParam->aclGlobalCfgParam.policy==3)?"selected":""
	);

	websWrite(wp,	
	"<table cellSpacing=1 cellPadding=2 border=0>\n" \
	"<tr><td bgColor=#aaddff>Priority</td><td bgColor=#aaddff>Direction/IP</td><td bgColor=#aaddff>Type</td><td bgColor=#aaddff>Port</td><td bgColor=#aaddff>Day</td><td bgColor=#aaddff>Time</td><td bgColor=#aaddff>Enable</td></tr>\n");

	websWrite(wp,"<tr><td bgColor=#ddeeff align=center>0</td><td bgColor=#ddeeff align=center>Ingress, Dest IP/Port<BR>%u.%u.%u.%u/%u.%u.%u.%u</td><td bgColor=#ddeeff align=center>IP</td><td bgColor=#ddeeff>&nbsp;</td><td bgColor=#ddeeff>&nbsp;</td><td bgColor=#ddeeff>&nbsp;</td><td bgColor=#ddeeff align=center><input type=checkbox name=lanPermit value=1 %s>" \
				,pRomeCfgParam->ifCfgParam[1].ipAddr[0]&pRomeCfgParam->ifCfgParam[1].ipMask[0]
				,pRomeCfgParam->ifCfgParam[1].ipAddr[1]&pRomeCfgParam->ifCfgParam[1].ipMask[1]
				,pRomeCfgParam->ifCfgParam[1].ipAddr[2]&pRomeCfgParam->ifCfgParam[1].ipMask[2]
				,pRomeCfgParam->ifCfgParam[1].ipAddr[3]&pRomeCfgParam->ifCfgParam[1].ipMask[3]
				,pRomeCfgParam->ifCfgParam[1].ipMask[0]
				,pRomeCfgParam->ifCfgParam[1].ipMask[1]
				,pRomeCfgParam->ifCfgParam[1].ipMask[2]
				,pRomeCfgParam->ifCfgParam[1].ipMask[3]
				,(pRomeCfgParam->aclGlobalCfgParam.lanPermit==1)?"checked":"");

	for(i=1;i<=MAX_ACL;i++)
	{
		websWrite(wp,
		"<tr><td bgColor=#ddeeff align=center>%d</td><td bgColor=#ddeeff align=center>\n" \
		"<select name=\"d%02d\">\n" \
		"<option value=\"0\" %s>Egress, Dest IP/Port</option>\n" \
		"<option value=\"1\" %s>Ingress, Dest IP/Port</option>\n" \
		"<option value=\"2\" %s>Egress, Src IP/Port</option>\n" \
		"<option value=\"3\" %s>Ingress, Src IP/Port</option>\n" \
		"</select><BR>\n",i,i,(pRomeCfgParam->aclCfgParam[ms][i-1].direction==0)?"selected":""
		             ,(pRomeCfgParam->aclCfgParam[ms][i-1].direction==1)?"selected":""
		             ,(pRomeCfgParam->aclCfgParam[ms][i-1].direction==2)?"selected":""
		             ,(pRomeCfgParam->aclCfgParam[ms][i-1].direction==3)?"selected":"");

		// ip/network
		for(j=1;j<=4;j++)
		{
			websWrite(wp,"<input type=text name=\"ip%02d%d\" size=3 maxlength=3 value=%u>\n",i,j,pRomeCfgParam->aclCfgParam[ms][i-1].ip[j-1]);
			if(j<4) websWrite(wp,".");
		}
		websWrite(wp,"</td>\n");

		//type
		websWrite(wp,
		"<td bgColor=#ddeeff>" \
			"<select name=\"t%02d\">" \
				"<option value=\"0\" %s>TCP</option>" \
				"<option value=\"1\" %s>UDP</option>" \
				"<option value=\"2\" %s>IP</option>" \
			"</select>" \
		"</td>\n",i,(pRomeCfgParam->aclCfgParam[ms][i-1].type==ACLCFGPARAM_PROTOCOL_TCP)?"selected":""
				   ,(pRomeCfgParam->aclCfgParam[ms][i-1].type==ACLCFGPARAM_PROTOCOL_UDP)?"selected":""
                               ,(pRomeCfgParam->aclCfgParam[ms][i-1].type==ACLCFGPARAM_PROTOCOL_IP)?"selected":"");

		// port
		websWrite(wp,
		"<td bgColor=#ddeeff>" \
			"<input type=text size=5 maxlength=5 name=\"p%02d\" value=%u>" \
		"</td>\n",i,pRomeCfgParam->aclCfgParam[ms][i-1].port);

		// day		
		{
			int k;
			char day[7][4]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
			websWrite(wp,"<td bgColor=#ddeeff align=center>" );
			for(j=0,k=1;j<7;j++,k<<=1)
			{
				websWrite(wp,"<input type=checkbox name=\"d%02d%d\" %s value=1>%s " 
				,i,j,(pRomeCfgParam->aclCfgParam[ms][i-1].day&k)?"checked":"",day[j]);
				if(j==2) websWrite(wp,"<BR>");
			}
			websWrite(wp,"</td>\n");
		}

		// time
		websWrite(wp,"<td bgColor=#ddeeff align=center>From:<select name=tsh%02d>",i);
		for(j=0;j<24;j++)
		{
			websWrite(wp,"<option value=%d%s>%d</option>\n",j,(pRomeCfgParam->aclCfgParam[ms][i-1].start_hour==j)?" selected":"",j);
			
		}
		websWrite(wp,"</select>:<select name=tsm%02d>\n",i);
		for(j=0;j<60;j++)
		{
			websWrite(wp,"<option value=%d%s>%d</option>\n",j,(pRomeCfgParam->aclCfgParam[ms][i-1].start_minute==j)?" selected":"",j);
		}
		websWrite(wp,"</select><BR>To:<select name=teh%02d>\n",i);
		for(j=0;j<24;j++)
		{
			websWrite(wp,"<option value=%d%s>%d</option>\n",j,(pRomeCfgParam->aclCfgParam[ms][i-1].end_hour==j)?" selected":"",j);			
			
		}
		websWrite(wp,"</select>:<select name=tem%02d>\n",i);
		for(j=0;j<60;j++)
		{
			websWrite(wp,"<option value=%d%s>%d</option>\n",j,(pRomeCfgParam->aclCfgParam[ms][i-1].end_minute==j)?" selected":"",j);
		}	
		
		websWrite(wp,"</td>\n");
		
		// enable
		websWrite(wp,
		"<td bgColor=#ddeeff align=center>" \
			"<input type=checkbox name=\"e%02d\" %s value=1>" \
		"</td>\n",i,(pRomeCfgParam->aclCfgParam[ms][i-1].enable==0)?"":"checked");

		websWrite(wp,"<input type=hidden name=ms value=%d>",ms);

	} //end for
	return 0;
}

void asp_setAcl(request * wp, char *path, char *query)
{
	char tmpstr[16]={0};
	int	i,j;
	int	ms=atoi(websGetVar(wp,"ms",""));
				
	pRomeCfgParam->aclGlobalCfgParam.policy=atoi(websGetVar(wp,"policy",""));
	pRomeCfgParam->aclGlobalCfgParam.lanPermit=atoi(websGetVar(wp,"lanPermit",""));
	
	for(i=0;i<MAX_ACL;i++)
	{
		sprintf(tmpstr,"d%02d",i+1);
		pRomeCfgParam->aclCfgParam[ms][i].direction=atoi(websGetVar(wp,tmpstr,""));
		
		sprintf(tmpstr,"t%02d",i+1);
		pRomeCfgParam->aclCfgParam[ms][i].type=atoi(websGetVar(wp,tmpstr,""));
		
		sprintf(tmpstr,"p%02d",i+1);
		pRomeCfgParam->aclCfgParam[ms][i].port=atoi(websGetVar(wp,tmpstr,""));
		
		for(j=0;j<4;j++)
		{
			sprintf(tmpstr,"ip%02d%d",i+1,j+1);
			pRomeCfgParam->aclCfgParam[ms][i].ip[j]=atoi(websGetVar(wp,tmpstr,""));
		}

		pRomeCfgParam->aclCfgParam[ms][i].day=0;
		for(j=0;j<7;j++)
		{
			sprintf(tmpstr,"d%02d%d",i+1,j);	
			if(atoi(websGetVar(wp,tmpstr,""))==1)
			{
				pRomeCfgParam->aclCfgParam[ms][i].day|=(1<<j);
			}
		}
		
		sprintf(tmpstr,"tsh%02d",i+1);
		pRomeCfgParam->aclCfgParam[ms][i].start_hour=atoi(websGetVar(wp,tmpstr,""));
		sprintf(tmpstr,"tsm%02d",i+1);
		pRomeCfgParam->aclCfgParam[ms][i].start_minute=atoi(websGetVar(wp,tmpstr,""));
		sprintf(tmpstr,"teh%02d",i+1);
		pRomeCfgParam->aclCfgParam[ms][i].end_hour=atoi(websGetVar(wp,tmpstr,""));
		sprintf(tmpstr,"tem%02d",i+1);
		pRomeCfgParam->aclCfgParam[ms][i].end_minute=atoi(websGetVar(wp,tmpstr,""));

			
		sprintf(tmpstr,"e%02d",i+1);		
		if(atoi(websGetVar(wp,tmpstr,""))==1)
			pRomeCfgParam->aclCfgParam[ms][i].enable=1; 
		else
			pRomeCfgParam->aclCfgParam[ms][i].enable=0;

		//failed setting: start time > end time , disable this ACL
		if((uint32)(pRomeCfgParam->aclCfgParam[ms][i].end_hour)*60+(pRomeCfgParam->aclCfgParam[ms][i].end_minute)<=
			(uint32)(pRomeCfgParam->aclCfgParam[ms][i].start_hour)*60+(pRomeCfgParam->aclCfgParam[ms][i].start_minute))
				pRomeCfgParam->aclCfgParam[ms][i].enable=0;	

		//failed setting: ip=0 or port=0 , disable this ACL
		if((pRomeCfgParam->aclCfgParam[ms][i].ip[0]==0)&&(pRomeCfgParam->aclCfgParam[ms][i].ip[1]==0)&&
                  (pRomeCfgParam->aclCfgParam[ms][i].ip[2]==0)&&(pRomeCfgParam->aclCfgParam[ms][i].ip[3]==0)&&
                  (pRomeCfgParam->aclCfgParam[ms][i].port==0)) pRomeCfgParam->aclCfgParam[ms][i].enable=0;
		
	}
	
	/* access table driver, return value not checked ? */
	acl_tableDriverAccess();
	
	/* save to cfgmgr */	
	cfgmgr_write(CFGMGR_TABID_ACL,(void*)pRomeCfgParam->aclCfgParam,sizeof(struct aclCfgParam_s)*MAX_ACL*MAX_PPPOE_SESSION);
	cfgmgr_write(CFGMGR_TABID_ACL_GLOBAL,(void*)&(pRomeCfgParam->aclGlobalCfgParam),sizeof(aclGlobalCfgParam_t));	
	cfgmgr_task();

	sprintf(tmpstr,	"/acl.asp?ms=%d",ms);
	websRedirect(wp, tmpstr);
}

/************************************************************
 *	
 *	Multiple PPPoE and Unnumbered PPPoE
 *	
 ************************************************************/
int asp_pppoe(request * wp, int argc, char **argv)
{
	int i,j;
	int pppoeType=0;
	int wizard=0;
	char str[32];
	
	pppoeType=atoi(websGetVar(wp,"pppoeType",""));
	wizard=atoi(websGetVar(wp,"wizard",""));	
	if(pppoeType==0)
	{
		pppoeType=pRomeCfgParam->ifCfgParam[0].connType;
	}
	
	websWrite(wp,"<html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=big5\">\n" \
	"<title>PPPoE Configuration</title>\n");

	for(i=0;i<MAX_PPPOE_SESSION;i++)
    {
    	if(pRomeCfgParam->pppoeCfgParam[i].dialState==PPPOECFGPARAM_DIALSTATE_DIALED_TRYING)
    	{
			websWrite(wp,"<META HTTP-EQUIV=Refresh CONTENT=\"2; URL=pppoe.asp\">");
			break;
    	}
	}

	websWrite(wp,"<script language=\"javascript\">\n" \
    "function disconnect_alert() { \n" \
    "	msg = \"If configuration have been changed, the PPPoE seesion will disconnect automatic.\\n\\nClick OK to continue or Cancel to abort\"; \n" \
    "	if (confirm(msg)) \n" \
    "	{ formname.submit(); } \n" \
    "}\n" \
    "function changePppoeType(a) { \n" \
    "	formpppoe.pppoeType.value=a; \n" \
    "	formpppoe.submit(); \n" \
    "}\n" \
    "function changeSessionID(b) { \n" \
    "	formname.sessionID.value=b; \n" \
    "}\n");
	
    for(i=0;i<MAX_PPPOE_SESSION;i++)
    {
    	if(pppoeType==IFCFGPARAM_CONNTYPE_PPPOE_MULTIPLE_PPPOE)
    		sprintf(str,"Multiple PPPoE %d: ",i);
    	else 
    		sprintf(str,"");
    	websWrite(wp,
		"function clickAutoReconnect%d()\n" \
		"{ 	if(formname.autoReconnect%d.checked==1) {\n" \
		"		if((formname.silentTimeout%d.value!=0)&&(formname.demand%d.checked==0))\n" \
		"			{ alert('%sIf you want to turn auto reconnect on, you have to set silent timeout to zero second.');\n" \
		"  			  formname.autoReconnect%d.checked=0; }\n" \
		" } else { formname.demand%d.checked=0; } }\n" \
		"function clickDialOnDemand%d() { if(formname.demand%d.checked==1) formname.autoReconnect%d.checked=1; else clickAutoReconnect%d(); } \n" \
		"function changeSilentTimeout%d()\n" \
		"{ if((formname.silentTimeout%d.value!=0)&&(formname.autoReconnect%d.checked==1)&&(formname.demand%d.checked==0))\n" \
		"	{ alert('%sSilent timeout can\\\'t run with auto reconnect on.');" \
		"		formname.autoReconnect%d.checked=0;	} } \n" \
		,i,i,i,i,str,i,i,i,i,i,i,i,i,i,i,str,i);

	if(pppoeType!=IFCFGPARAM_CONNTYPE_PPPOE_MULTIPLE_PPPOE) break;
	
    	websWrite(wp,
	"function lanTypeChange%d()\n" \
	"{ \n" \
	"var tf=false; if(formname.lanType%d.value==0) tf=true; \n" \
	"formname.unnumberedIpAddr%d1.disabled=tf; \n" \
	"formname.unnumberedIpAddr%d2.disabled=tf; \n" \
	"formname.unnumberedIpAddr%d3.disabled=tf; \n" \
	"formname.unnumberedIpAddr%d4.disabled=tf; \n" \
	"for(var k=0;k<formname.unnumberedIpAddr%d1.length;k++)\n" \
	"  { formname.unnumberedIpAddr%d1[k].disabled=tf; } \n" \
	"for(k=0;k<formname.unnumberedIpAddr%d2.length;k++)\n" \
	"  { formname.unnumberedIpAddr%d2[k].disabled=tf; } \n" \
	"for(k=0;k<formname.unnumberedIpAddr%d3.length;k++)\n" \
	"  { formname.unnumberedIpAddr%d3[k].disabled=tf; } \n" \
	"for(k=0;k<formname.unnumberedIpAddr%d4.length;k++)\n" \
	"  { formname.unnumberedIpAddr%d4[k].disabled=tf; } \n" \
	"formname.unnumberedIpMask%d.disabled=tf; \n",i,i,i,i,i,i,i,i,i,i,i,i,i,i,i);

	if(pRomeCfgParam->pppoeCfgParam[i].defaultSession==0)
	{		
    		websWrite(wp,
		"tf=!tf; \n" \
		"formname.destnettype%d1.disabled=tf; \n" \
		"formname.destnettype%d2.disabled=tf; \n" \
		"formname.destnettype%d3.disabled=tf; \n" \
		"formname.destnettype%d4.disabled=tf; \n" \
		"formname.destnet%d1.disabled=tf; \n" \
		"formname.destnet%d2.disabled=tf; \n" \
		"formname.destnet%d3.disabled=tf; \n" \
		"formname.destnet%d4.disabled=tf; \n" \
		"for(var k=0;k<formname.destnet%d1.length;k++)\n" \
		"  { formname.destnet%d1[k].disabled=tf; } \n" \
		"for(k=0;k<formname.destnet%d2.length;k++)\n" \
		"  { formname.destnet%d2[k].disabled=tf; } \n" \
		"for(k=0;k<formname.destnet%d3.length;k++)\n" \
		"  { formname.destnet%d3[k].disabled=tf; } \n" \
		"for(k=0;k<formname.destnet%d4.length;k++)\n" \
		"  { formname.destnet%d4[k].disabled=tf; } \n" \
    		,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i);
	}	

	websWrite(wp,"} \n");

    }
    
    websWrite(wp,
	"</script>\n" \
    "</head>\n" \
    "<body bgcolor=ffffff text=\"#000000\">\n");

    if(wizard==0)
    	{
	    websWrite(wp,
	    "<form action=\"pppoe.asp\" name=formpppoe><input type=hidden value=1 name=pppoeType></form>\n" );
    	}

    switch(wizard)
    	{
    	case IFCFGPARAM_CONNTYPE_PPPOE:
    		websWrite(wp,"<form method=\"get\" action=\"/goform/asp_setPppoeWizard\" name=\"formname\">");
    		break;
    	case IFCFGPARAM_CONNTYPE_PPPOE_UNNUMBERED:
    		websWrite(wp,"<form method=\"get\" action=\"/goform/asp_setUnnumberedWizard\" name=\"formname\">");
		break;
    	default:
		websWrite(wp,"<form method=\"get\" action=\"/goform/asp_setPppoe\" name=\"formname\">\n");
    		break;
    	}

    if(wizard==0)
    	{
   	 websWrite(wp,
	    "<input type=hidden value=\"0\" name=sessionID>");
    
	websWrite(wp,"<B>PPPoE Type:</b><select name=\"pppoeType\" onchange=\"changePppoeType(formname.pppoeType.value);\">");
	websWrite(wp,"<option value=%d %s>PPPoE</option>",IFCFGPARAM_CONNTYPE_PPPOE,(pppoeType==IFCFGPARAM_CONNTYPE_PPPOE)?"selected":"");
	if(MULTIPLE_PPPOE_SUPPORT!=0)
	{
		websWrite(wp,"<option value=%d %s>Unnumbered PPPoE</option><option value=%d %s>Multiple PPPoE</option>"
		,IFCFGPARAM_CONNTYPE_PPPOE_UNNUMBERED,(pppoeType==IFCFGPARAM_CONNTYPE_PPPOE_UNNUMBERED)?"selected":""
		,IFCFGPARAM_CONNTYPE_PPPOE_MULTIPLE_PPPOE,(pppoeType==IFCFGPARAM_CONNTYPE_PPPOE_MULTIPLE_PPPOE)?"selected":"");
	}
	websWrite(wp,"</select>");
       
	   if(pppoeType==IFCFGPARAM_CONNTYPE_PPPOE_MULTIPLE_PPPOE)
	   { 
   		websWrite(wp,"&nbsp;&nbsp;&nbsp;&nbsp;<b>Default:</b><select name=\"default_session\">");
   		for(i=0;i<MAX_PPPOE_SESSION;i++)
   		{
   			if(pRomeCfgParam->pppoeCfgParam[i].enable==1) websWrite(wp,"<option value=%d %s>PPPoE %d</option>",i,(pRomeCfgParam->pppoeCfgParam[i].defaultSession==1)?"selected":"",i);
   		}
   		websWrite(wp,"</select>");
	    }
   	   websWrite(wp,"<br><HR><BR>");
    	}
   	

	for(i=0;i<MAX_PPPOE_SESSION;i++)
   	{
   		int action;
   		   		

    	if(pppoeType==IFCFGPARAM_CONNTYPE_PPPOE_MULTIPLE_PPPOE)
    	{
   			websWrite(wp,"<b>Multiple PPPoE %d Configuration</b>\n",i);
	   	}
	   	else if(pppoeType==IFCFGPARAM_CONNTYPE_PPPOE_UNNUMBERED)
	   	{
	   		if(i>0) break;
	   		websWrite(wp,"<B>Unnumbered PPPoE Configuration</b>\n");
	   	}
	   	else
    	{
    		if(i>0) break;
    		websWrite(wp,"<b>PPPoE Configuration</b>\n");
    	}

    	websWrite(wp,"<table cellSpacing=1 cellPadding=2 border=0>\n" \
    	"<tr>\n" \
    	"<td bgColor=#aaddff colspan=1>Login ID</td>\n" \
    	"<td bgColor=#ddeeff colspan=3><input type=text name=username%d size=32 maxlength=32 value=\"%s\"></td>\n" \
    	"</tr>\n",i,pRomeCfgParam->pppoeCfgParam[i].username);

   		websWrite(wp,
	    "<tr>\n" \
    	"   <td bgColor=#aaddff colspan=1>Password</td>\n" \
	    "   <td bgColor=#ddeeff colspan=3><input type=password name=password%d size=32 maxlength=32 value=\"%s\"></td>\n" \
	    "</tr>\n"
	    ,i,pRomeCfgParam->pppoeCfgParam[i].password); 

   		websWrite(wp,
	    "<tr>\n" \
    	"   <td bgColor=#aaddff colspan=1>Service Name</td>\n" \
	    "   <td bgColor=#ddeeff colspan=3><input type=text name=serviceName%d size=32 maxlength=32 value=\"%s\"></td>\n" \
	    "</tr>\n"
	    ,i,pRomeCfgParam->pppoeCfgParam[i].serviceName); 

   		websWrite(wp,
	    "<tr>\n" \
    	"   <td bgColor=#aaddff colspan=1>AC Name</td>\n" \
	    "   <td bgColor=#ddeeff colspan=3><input type=text name=acName%d size=32 maxlength=32 value=\"%s\"></td>\n" \
	    "</tr>\n"
	    ,i,pRomeCfgParam->pppoeCfgParam[i].acName); 


	websWrite(wp,
		"<tr>\n" \
		"   <td bgColor=#aaddff colspan=1>MTU</td>\n" \
    		"   <td bgColor=#ddeeff colspan=3><input type=text size=4 maxlength=4 name=mtu%d  value=\"%d\"></td>\n" \
		"</tr>\n",i,pRomeCfgParam->pppoeCfgParam[i].mtu);
	    	    
	    if(pppoeType==IFCFGPARAM_CONNTYPE_PPPOE_MULTIPLE_PPPOE)
	    {
		uint32 netmask=0;
		int k=0;
		uint8 *netmask_p=(uint8 *)&netmask;	

		websWrite(wp,
		"<tr>\n" \
		"   <td bgColor=#aaddff colspan=1>LAN Type</td>\n" \
    		"   <td bgColor=#ddeeff colspan=3><select name=lanType%d %s onclick=\"javascript:lanTypeChange%d();\"><option value=0 %s>NAPT</option><option value=1 %s>Unnumbered</option></td>\n" \
		"</tr>\n",i,
		pRomeCfgParam->pppoeCfgParam[i].defaultSession==1?"disabled":"",i,
		pRomeCfgParam->pppoeCfgParam[i].lanType==PPPOECFGPARAM_LANTYPE_NAPT?"selected":"",
		pRomeCfgParam->pppoeCfgParam[i].lanType==PPPOECFGPARAM_LANTYPE_UNNUMBERED?"selected":"");

		websWrite(wp,
		"<tr>\n" \
		"   <td bgColor=#aaddff colspan=1>Unnumbered IP Address</td>\n" \
    		"   <td bgColor=#ddeeff colspan=3><input type=text name=unnumberedIpAddr%d1 size=3 maxlength=3 value=%u>.\n" \
    		"   <input type=text name=unnumberedIpAddr%d2 size=3 maxlength=3 value=%u>.\n" \
    		"   <input type=text name=unnumberedIpAddr%d3 size=3 maxlength=3 value=%u>.\n" \
    		"   <input type=text name=unnumberedIpAddr%d4 size=3 maxlength=3 value=%u>\n" \
    		"</td>\n" \
		"</tr>\n",
		i,pRomeCfgParam->pppoeCfgParam[i].unnumberedIpAddr[0],
	    	i,pRomeCfgParam->pppoeCfgParam[i].unnumberedIpAddr[1],
	    	i,pRomeCfgParam->pppoeCfgParam[i].unnumberedIpAddr[2],
	    	i,pRomeCfgParam->pppoeCfgParam[i].unnumberedIpAddr[3]);	

		j=0;			
		netmask_p[0]=pRomeCfgParam->pppoeCfgParam[i].unnumberedIpMask[0];
		netmask_p[1]=pRomeCfgParam->pppoeCfgParam[i].unnumberedIpMask[1];
		netmask_p[2]=pRomeCfgParam->pppoeCfgParam[i].unnumberedIpMask[2];
		netmask_p[3]=pRomeCfgParam->pppoeCfgParam[i].unnumberedIpMask[3];
		if(netmask==0xffffffff) j=32;
		else while(netmask<<j) j++;
			
		websWrite(wp,
    		"<tr>\n" \
	    	"   <td bgColor=#aaddff colspan=1>Unnumbered Network Mask</td>\n" \
    		"   <td bgColor=#ddeeff colspan=3>" \
    		"		<select name=unnumberedIpMask%d>",i);

		for(k=31;k>=0;k--)
		{
			if(k!=0)
			{
				netmask=0xffffffff;
				netmask=(netmask>>(32-k))<<(32-k);
			}
			else
				netmask=0;
			websWrite(wp,
				"		<option value=\"%d\" %s>%u.%u.%u.%u</option>\n"
				,k,(k==j)?"selected":"",netmask_p[0],netmask_p[1],netmask_p[2],netmask_p[3]);
		}

			websWrite(wp,
    		"		</select>" \
	    	"</td></tr>\n");		

	
	    	for(j=0;j<4;j++)
	    	{
	    		websWrite(wp,
	    		"<tr>\n" \
		    	"   <td bgColor=#aaddff colspan=1>Destination Network %d</td>\n" \
    			"   <td bgColor=#ddeeff colspan=3><select name=destnettype%d%d %s>" \
    			"<option value=0 %s>NONE</option>" \
	    		"<option value=1 %s>IP RANGE</option>" \
    			"<option value=2 %s>DOMAIN</option>" \
	    		"<option value=3 %s>TCP PORT</option>" \
    			"<option value=4 %s>UDP PORT</option>" \
    			"<input type=text name=destnet%d%d size=32 maxlength=32 value=\"%s\" %s></td>\n" \
	    		"</tr>\n" ,j+1,i,j+1
	    		,(pRomeCfgParam->pppoeCfgParam[i].defaultSession==1)?"disabled":""
		    	,(pRomeCfgParam->pppoeCfgParam[i].destnetType[j]==0)?"selected":""
		    	,(pRomeCfgParam->pppoeCfgParam[i].destnetType[j]==1)?"selected":""
	    		,(pRomeCfgParam->pppoeCfgParam[i].destnetType[j]==2)?"selected":""
		    	,(pRomeCfgParam->pppoeCfgParam[i].destnetType[j]==3)?"selected":""
		    	,(pRomeCfgParam->pppoeCfgParam[i].destnetType[j]==4)?"selected":""
		    	,i,j+1,pRomeCfgParam->pppoeCfgParam[i].destnet[j]
		    	,(pRomeCfgParam->pppoeCfgParam[i].defaultSession==1)?"disabled":"");
	    	}
   		
		websWrite(wp,
    		"<tr>\n" \
	    	"   <td bgColor=#aaddff>Default</td>\n" \
	    	"   <td bgColor=#ddeeff><input type=checkbox %s disabled><script language=javascript>lanTypeChange%d();</script></td>\n" \
	       "   <td bgColor=#aaddff>Enable</td>\n" \
    		"   <td bgColor=#ddeeff><input type=checkbox name=enable%d value=1 %s></td>\n" \
	    	"</tr>\n",(pRomeCfgParam->pppoeCfgParam[i].defaultSession==1)?"checked":"",i,i,(pRomeCfgParam->pppoeCfgParam[i].enable==1)?"checked":"");
		}
		
		if(pppoeType==IFCFGPARAM_CONNTYPE_PPPOE_UNNUMBERED)
		{
			uint32 netmask=0;
			int k=0;
			uint8 *netmask_p=(uint8 *)&netmask;			
			
		websWrite(wp,
    		"<tr>\n" \
	    	"   <td bgColor=#aaddff colspan=1>IP Address</td>\n" \
    		"   <td bgColor=#ddeeff colspan=3>" \
    		"		<input type=text name=unnumberedIpAddr1 size=3 maxlength=3 value=\"%d\">.\n" \
    		"		<input type=text name=unnumberedIpAddr2 size=3 maxlength=3 value=\"%d\">.\n" \
    		"		<input type=text name=unnumberedIpAddr3 size=3 maxlength=3 value=\"%d\">.\n" \
    		"		<input type=text name=unnumberedIpAddr4 size=3 maxlength=3 value=\"%d\">\n" \
	    	"</td></tr>\n"
	    	,pRomeCfgParam->pppoeCfgParam[0].unnumberedIpAddr[0]
	    	,pRomeCfgParam->pppoeCfgParam[0].unnumberedIpAddr[1]
	    	,pRomeCfgParam->pppoeCfgParam[0].unnumberedIpAddr[2]
	    	,pRomeCfgParam->pppoeCfgParam[0].unnumberedIpAddr[3]);	

		j=0;			
		netmask_p[0]=pRomeCfgParam->pppoeCfgParam[0].unnumberedIpMask[0];
		netmask_p[1]=pRomeCfgParam->pppoeCfgParam[0].unnumberedIpMask[1];
		netmask_p[2]=pRomeCfgParam->pppoeCfgParam[0].unnumberedIpMask[2];
		netmask_p[3]=pRomeCfgParam->pppoeCfgParam[0].unnumberedIpMask[3];
		if(netmask==0xffffffff) j=32;
		else while(netmask<<j) j++;
			
		websWrite(wp,
    		"<tr>\n" \
	    	"   <td bgColor=#aaddff colspan=1>Network Mask</td>\n" \
    		"   <td bgColor=#ddeeff colspan=3>" \
    		"		<select name=unnumberedIpMask>");

		for(k=31;k>=0;k--)
		{
			if(k!=0)
			{
				netmask=0xffffffff;
				netmask=(netmask>>(32-k))<<(32-k);
			}
			else
				netmask=0;
			websWrite(wp,
				"		<option value=\"%d\" %s>%u.%u.%u.%u</option>\n"
				,k,(k==j)?"selected":"",netmask_p[0],netmask_p[1],netmask_p[2],netmask_p[3]);
		}

			websWrite(wp,
    		"		</select>" \
	    	"</td></tr>\n");

		websWrite(wp,
    		"<tr>\n" \
	    	"   <td bgColor=#aaddff colspan=1>NAPT for LAN hosts</td>\n" \
    		"   <td bgColor=#ddeeff colspan=3>" \
    		"   <input type=checkbox name=\"unnumberedNapt\" value=\"1\" %s>" \
    		"</tr>",(pRomeCfgParam->pppoeCfgParam[i].unnumberedNapt==1)?"checked":"");
	    	    	
		}

	   websWrite(wp,
    	"<tr>\n" \
	    "   <td bgColor=#aaddff>Dial-On-Demand</td>\n" \
    	"   <td bgColor=#ddeeff><input type=checkbox value=1 name=demand%d %s onclick=\"javascript:clickDialOnDemand%d(); \"></td>\n" \
	    "   <td bgColor=#aaddff>Silent Timeout</td>\n" \
    	"   <td bgColor=#ddeeff><input type=text size=8 maxlength=8 name=silentTimeout%d value=\"%d\" onblur=\"javascript:changeSilentTimeout%d();\">seconds</td>\n" \
	    "</tr>\n",i,((pRomeCfgParam->pppoeCfgParam[i].demand)==1)?"checked":"",i,i,(pRomeCfgParam->pppoeCfgParam[i].silentTimeout),i);

			
		action=0; //0:Normal(disconnect), 1:Can't Dial(connecting...,connected), 2:Can't Dial and Hang-up.(config changed)
		if(pRomeCfgParam->pppoeCfgParam[i].dialState!=PPPOECFGPARAM_DIALSTATE_OFF) action=1;
		if(pRomeCfgParam->pppoeCfgParam[i].dialState==PPPOECFGPARAM_DIALSTATE_DIALED_TRYING) action=1;
		if(pppoeType!=pRomeCfgParam->ifCfgParam[0].connType) action=2;
		if(!((pppoeType==IFCFGPARAM_CONNTYPE_PPPOE)||(pppoeType==IFCFGPARAM_CONNTYPE_PPPOE_UNNUMBERED)||(pppoeType==IFCFGPARAM_CONNTYPE_PPPOE_MULTIPLE_PPPOE))) action=2;
		if(configChanged) action=2;
		
		
		getDialStateString(i,str);
		
   		websWrite(wp,
	    "<tr>\n" \
	    "   <td bgColor=#aaddff>Auto Reconnect</td>\n" \
	    "   <td bgColor=#ddeeff><input type=checkbox value=1 name=autoReconnect%d %s onclick=\"javascript:clickAutoReconnect%d();\"></td>\n" \
	    "   <td bgColor=#aaddff>Dial Status</td>\n" \
    	"   <td bgColor=#ddeeff>%s</td>\n" \
	    "</tr>\n",i,(pRomeCfgParam->pppoeCfgParam[i].autoReconnect==1)?"checked":"",i,str);

		websWrite(wp,
    		"<tr>\n" \
	    	"   <td bgColor=#aaddff colspan=1>Auth Type</td>\n" \
    		"   <td bgColor=#ddeeff colspan=3>" \
    		"   <input type=radio name=authType%d value=0 %s>PAP ,<input type=radio name=authType%d value=1 %s>CHAP</tr>",i,(pRomeCfgParam->pppoeCfgParam[i].authType==PPPPARAM_AUTHTYPE_PAP)?"checked":"",i,(pRomeCfgParam->pppoeCfgParam[i].authType==PPPPARAM_AUTHTYPE_CHAP)?"checked":"");

		websWrite(wp,
    		"<tr>\n" \
	    	"   <td bgColor=#aaddff colspan=1>Performance</td>\n" \
    		"   <td bgColor=#ddeeff colspan=3>" \
    		"   %s routing %s</tr>",(pRomeCfgParam->pppoeCfgParam[i].defaultSession)?"Wirespeed":"Software",(pppoeType==IFCFGPARAM_CONNTYPE_PPPOE_UNNUMBERED&&pRomeCfgParam->pppoeCfgParam[i].unnumberedNapt==0)?"":"and NAPT");


	if(wizard==0)
	{
   		websWrite(wp,
    		"<tr>\n" \
	    	"   <td align=center colspan=4>\n" \
	    	"       <input type=\"submit\" name=\"submit2\" value=\"Dial\" onClick=\"javascript:changeSessionID(%d);\" %s>\n" \
		"       <input type=\"submit\" name=\"submit2\" value=\"Hang up\" onClick=\"javascript:changeSessionID(%d);\" %s>\n" \
	    	"   </td>\n" \
	    	"</tr>"
		,i,(action>=1)?"disabled":"",i,(action==2)?"disabled":"");
	}


	websWrite(wp,"</table><BR>\n");
    } /* end for i */

   //for(i=0;i<MAX_PPPOE_SESSION;i++)
   //	if(pRomeCfgParam->pppoeCfgParam[i].dialState!=PPPOECFGPARAM_DIALSTATE_OFF) break;

   switch(wizard)
   {
    case IFCFGPARAM_CONNTYPE_PPPOE: //for wizard
    case IFCFGPARAM_CONNTYPE_PPPOE_UNNUMBERED: //for wizard
    	websWrite(wp,
    	"<input type=\"button\" value=\"< Back\" onclick=\"javascript:history.back();\">&nbsp;&nbsp;&nbsp;&nbsp;\n" \
	"<input type=submit value=\"Save and Reinit\" name=\"submitBtn\">&nbsp;&nbsp;&nbsp;&nbsp;\n" \
	"<input type=reset value=\"Reset\">&nbsp;&nbsp;&nbsp;&nbsp;\n" \
	"<input type=\"button\" value=\"Cancel\" onclick=\"javascript:location.replace('status.asp');\">\n");
    	break;    	
   default:
    	websWrite(wp,"<input type=\"button\" name=\"submit2\" value=\"Save All Configuration\" onclick=\"javascript:disconnect_alert();\">" \
    	"&nbsp;&nbsp;&nbsp;&nbsp;<input type=\"submit\" name=\"submit2\" value=\"Refresh\">" \
    	"&nbsp;&nbsp;&nbsp;&nbsp;<input type=\"reset\" value=\"Reset\"></form>");
    	break;    	
   }
	return 0;
}

/************************************************************
 *	
 *	Server Port
 *	
 ************************************************************/ 
int asp_serverPort(request * wp, int argc, char **argv)
{
	/* Server port function is only provided in gateway mode. */
	if(pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L4GATEWAYMODE) {
		uint8 i,j;
		int ms;

		if(pRomeCfgParam->natCfgParam.hwaccel == 0)
		{
			websWrite(wp,
			"<B><font color=red>This function must run in \"Hardware Acceleration\" mode, <BR>"\
			"please turn it on, and try again...\n");
			return;
		}

		//header
		websWrite(wp,
		"<html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=big5\">\n" \
		"<title>Server Port Configuration</title>\n" \
		"<script language=javascript>\n" \
		"function changeMs(a)\n" \
		"{	fn.ms.value=a; 	fn.submit();  }\n" \
		"function changeRange(op)\n" \
		"{ \n");


		for(i=1;i<=MAX_SERVER_PORT;i++)
		{
			websWrite(wp,
			"	var wps%d=parseInt(spform.wps%d.value);\n" \
			"	var wpf%d=parseInt(spform.wpf%d.value);\n" \
			"	var sp%d=parseInt(spform.sp%d.value);\n",i,i,i,i,i,i);
		}

		for(i=1;i<=MAX_SERVER_PORT;i++)
		{
			websWrite(wp,
			"	if((wps%d>wpf%d)&&(op==3)) { spform.wpf%d.value=wps%d; spform.wps%d.value=wpf%d; spform.spf%d.value=wps%d-wpf%d+sp%d; }\n" \
			"	else {spform.spf%d.value=wpf%d-wps%d+sp%d;} \n",i,i,i,i,i,i,i,i,i,i,i,i,i,i);
		}

		websWrite(wp,
		"} \n" \
		"</script>\n" \
		"</head>\n" \
		"<body bgcolor=\"#ffffff\" text=\"#000000\"><b>Virtual Server</b>\n");

		{
			char *spargv[]={{"ms"}};
			ms=asp_multiSession(wp,1,spargv);
		}

		websWrite(wp,
		"<form action=\"serverp.asp\" name=\"fn\"><input type=hidden name=ms value=0></form>" \
		"<form method=get action=\"/goform/asp_setServerPort\" name=spform onSubmit=\"changeRange(3);\">\n" \
		"<input type=hidden name=ms value=%d>\n" \
		"<table cellSpacing=1 cellPadding=2 border=0>\n" \
		"<tr><td bgColor=#aaddff>WAN Port Range</td><td bgColor=#aaddff>Server IP Address</td><td bgColor=#aaddff>Server Port Range</td><td bgColor=#aaddff>Protocol</td><td bgColor=#aaddff>Enable</td></tr>\n",ms);

		for(i=1;i<=MAX_SERVER_PORT;i++)
		{
			//wan port
			websWrite(wp,"<tr><td bgColor=#ddeeff><input type=text name=wps%u size=5 maxlength=5 value=%u onKeyUp=\"changeRange(1);\">~<input type=text name=wpf%u size=5 maxlength=5 value=%u onKeyUp=\"changeRange(2);\">==></td><td bgColor=#ddeeff>\n",i,pRomeCfgParam->serverpCfgParam[ms][i-1].wanPortStart,i,pRomeCfgParam->serverpCfgParam[ms][i-1].wanPortFinish);

			// server ip
			for(j=1;j<=4;j++)
			{
				websWrite(wp,"<input type=text name=sip%u%u size=3 maxlength=3 value=%u>\n",i,j,pRomeCfgParam->serverpCfgParam[ms][i-1].ip[j-1]);
				if(j<4) websWrite(wp,".");
			}

			//server port
			websWrite(wp,"</td><td bgColor=#ddeeff><input type=text name=sp%u size=5 maxlength=5 value=%u onKeyUp=\"changeRange(3);\">~<input type=text name=spf%u size=5 maxlength=5 value=%u disabled></td>\n",i,pRomeCfgParam->serverpCfgParam[ms][i-1].portStart,i,pRomeCfgParam->serverpCfgParam[ms][i-1].wanPortFinish-pRomeCfgParam->serverpCfgParam[ms][i-1].wanPortStart+pRomeCfgParam->serverpCfgParam[ms][i-1].portStart);

			//protocol
			websWrite(wp,"</td><td bgColor=#ddeeff><select name=proto%u><option value=0 %s>TCP</option><option value=1 %s>UDP</option></td>\n",i,(pRomeCfgParam->serverpCfgParam[ms][i-1].protocol==SERVERPCFGPARAM_PROTOCOL_TCP)?"selected":"",(pRomeCfgParam->serverpCfgParam[ms][i-1].protocol==SERVERPCFGPARAM_PROTOCOL_UDP)?"selected":"");

			//enable
			websWrite(wp,"<td bgColor=#ddeeff><input type=checkbox name=e%u value=1 %s></td>\n",i,(pRomeCfgParam->serverpCfgParam[ms][i-1].enable==1)?"checked":"");

		} //end for

		websWrite(wp,
		"<tr><td colspan=3 align=center><input type=submit value=Apply>&nbsp;&nbsp;&nbsp;&nbsp;<input type=reset value=Reset></td></tr>\n" \
		"</tr></table>");
		websWrite(wp,"<ul><li>Virtual servers using single port number is accelerated by hardware at wirespeed.</ul></body></html>");
	}
	else if (pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L3ROUTERMODE) {
		websWrite(wp, "<b>Does not support server port in router mode!</b>\n");
	}
	else {
		websWrite(wp, "<b>Does not support server port in bridge mode!</b>\n");
	}
	
	return 0;
}

void asp_setServerPort(request * wp, char *path, char *query)
{
	char tmpstr[32]={0};
	uint8 i,j;
	int	ms=atoi(websGetVar(wp,"ms",""));

	memcpy(ramServerpCfgParam,pRomeCfgParam->serverpCfgParam,sizeof(serverpCfgParam_t)*MAX_SERVER_PORT*MAX_PPPOE_SESSION);
	for(i=0;i<MAX_SERVER_PORT;i++)
	{		
		sprintf(tmpstr,"wps%u",i+1);
		pRomeCfgParam->serverpCfgParam[ms][i].wanPortStart=atoi(websGetVar(wp,tmpstr,""));

		sprintf(tmpstr,"wpf%u",i+1);
		pRomeCfgParam->serverpCfgParam[ms][i].wanPortFinish=atoi(websGetVar(wp,tmpstr,""));
		
		
		for(j=0;j<4;j++)
		{
			sprintf(tmpstr,"sip%u%u",i+1,j+1);
			pRomeCfgParam->serverpCfgParam[ms][i].ip[j]=atoi(websGetVar(wp,tmpstr,""));
		}

		sprintf(tmpstr,"sp%u",i+1);
		pRomeCfgParam->serverpCfgParam[ms][i].portStart=atoi(websGetVar(wp,tmpstr,""));

		sprintf(tmpstr,"proto%u",i+1);
		pRomeCfgParam->serverpCfgParam[ms][i].protocol=atoi(websGetVar(wp,tmpstr,""));
		
		sprintf(tmpstr,"e%u",i+1);
		pRomeCfgParam->serverpCfgParam[ms][i].enable=atoi(websGetVar(wp,tmpstr,""));
		
	} /* end for i */

	serverp_tableDriverAccess(ms); /* return value not important ? */
	
	/* save to cfgmgr */
	cfgmgr_write(CFGMGR_TABID_SERVERP,(void*)pRomeCfgParam->serverpCfgParam,sizeof(struct serverpCfgParam_s)*MAX_SERVER_PORT*MAX_PPPOE_SESSION);
	cfgmgr_task();

	sprintf(tmpstr,"/serverp.asp?ms=%d",ms);
	websRedirect(wp, tmpstr);
}


/************************************************************
 *	
 *	Protocol-Based NAT
 *	
 ************************************************************/ 
int asp_pbnat(request * wp, int argc, char **argv)
{
	uint8 i,j;
	int ms;
	

	char *spargv[]={{"ms"}};
	ms=asp_multiSession(wp,1,spargv);

	websWrite(wp,"\n\n\t<form action=\"/goform/asp_setPbnat\" name=\"fm\">\n");
	websWrite(wp,"\t<input type=hidden name=ms value=%d>\n",ms);
	websWrite(wp,"\t<table><tr><th>IP Protocol Number</th><th>Internal IP</th><th>Enabled</th></tr>\n");
	
	for(i=0;i<MAX_PBNAT;i++)
	{
		//protocol
		ipaddr_t IntIp = pRomeCfgParam->pbnatCfgParam[ms][i].IntIp;
		
		websWrite(wp,
			"\t\t<tr>"
			"\t\t<td><input type=input name=protocol_%d size=3 maxlength=3 value='%d'></td>"
			"\t\t<td><input type=input name=IntIp_%d size=15 maxlength=15 value='%d.%d.%d.%d'></td>"
			"\t\t<td><input type=checkbox name=enabled_%d value='1' %s></td>"
			"\t\t</tr>\n",
			i, pRomeCfgParam->pbnatCfgParam[ms][i].protocol,
			i, IntIp>>24, (IntIp&0x00ff0000)>>16, (IntIp&0x0000ff00)>>8,  IntIp&0x000000ff,
			i, pRomeCfgParam->pbnatCfgParam[ms][i].enabled?"checked":"" );
	}


	websWrite(wp,"\t</table>\n");
	websWrite(wp,"\t<input type=submit value='Apply'>\n");
	websWrite(wp,"\t</form>\n");
	
	return 0;
}

void asp_setPbnat(request * wp, char *path, char *query)
{
	char tmpstr[32]={0};
	uint8 i,j;
	char* pch;
	int	ms;
	ipaddr_t msIp;
	
	ms = atoi(websGetVar(wp,"ms",""));
	msIp = board_getExternalIp( ms );

	/* clear table first */
	pbnat_ipdown( ms, msIp );

	/* then, update configuration according to form request */
	for(i=0;i<MAX_PBNAT;i++)
	{		
		sprintf(tmpstr,"protocol_%u",i);
		pRomeCfgParam->pbnatCfgParam[ms][i].protocol = atoi(websGetVar(wp,tmpstr,""));

		pRomeCfgParam->pbnatCfgParam[ms][i].IntIp = 0;
		sprintf(tmpstr,"IntIp_%u",i);
		for( j = 0, pch = strtok( websGetVar(wp,tmpstr,""), "." );
		     j < 4 && pch;
		     j++, pch = strtok( NULL, "." ) )
		{
			pRomeCfgParam->pbnatCfgParam[ms][i].IntIp |= atoi(pch) << ((3-j)*8);
		}
		
		sprintf(tmpstr,"enabled_%u",i);
		pRomeCfgParam->pbnatCfgParam[ms][i].enabled = atoi(websGetVar(wp,tmpstr,""));
	}

	//serverp_tableDriverAccess(ms); /* return value not important ? */
	
	/* save to cfgmgr */
	cfgmgr_write(CFGMGR_TABID_PBNAT,(void*)pRomeCfgParam->pbnatCfgParam,sizeof(struct pbnatCfgParam_s)*MAX_PBNAT*MAX_PPPOE_SESSION);
	cfgmgr_task();

	/* insert to table again */
	pbnat_ipup( ms, msIp );

	sprintf(tmpstr,"/pbnat.asp?ms=%d",ms);
	websRedirect(wp, tmpstr);
}


/************************************************************
 *	
 *	URL Filter
 *	
 ************************************************************/ 
int asp_urlFilter(request * wp, int argc, char **argv)
{

//	if(pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L4GATEWAYMODE) {
		int i;
		int setted=0;
		int ms=asp_multiSession(wp,argc,argv);
		int8 string[32];
		if(argc==0)
		{
			websWrite(wp,"<input type=hidden name=ms value=%d>",ms);	
			for(i=0;i<MAX_URL_FILTER;i++)
			{
				sprintf(string, "%u.%u.%u.%u-%u.%u.%u.%u", NIPQUAD(pRomeCfgParam->urlfilterCfgParam[ms][i].ip_start), NIPQUAD(pRomeCfgParam->urlfilterCfgParam[ms][i].ip_end));
				websWrite(wp,"<tr><td bgColor=#ddeeff><input type=text size=32 maxlength=32 name=string%d value=\"%s\"></td>\n",i,pRomeCfgParam->urlfilterCfgParam[ms][i].string);
				websWrite(wp, "<td bgColor=#ddeeff align=center><input type=text size=31 maxlength=31 name=ipRange%d value=\"%s\"></td>\n", i, string);
				websWrite(wp,"<td bgColor=#ddeeff align=center><input type=checkbox value=1 name=enable%d %s></td></tr>\n",i,(pRomeCfgParam->urlfilterCfgParam[ms][i].enable==1)?"checked":"");			
			}
		}
		else
		{
		 	if(strcmp(argv[0],"TrustedUser")==0)	
		 	{
		 		for(i=0;i<URL_FILTER_MAX_TRUSTED_USERS;i++)
		 		{
		 			websWrite(wp,"<tr><td bgColor=#ddeeff><input type=text size=15 maxlength=15 name=\"trusted%d\" value=\"%u.%u.%u.%u\"></td>",i,NIPQUAD(pRomeCfgParam->urlfilterTrustedUserCfgParam[i].trustedIP));
					websWrite(wp,"<td bgColor=#ddeeff align=center><input type=checkbox value=1 name=\"tenable%d\" %s></td></tr>\n",i,(pRomeCfgParam->urlfilterTrustedUserCfgParam[i].enable==1)?"checked":"");
		 		}
		 	}
		}
		
//	}
//	else if(pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L3ROUTERMODE) {
//		websWrite(wp, "<b>Does not support url filter function in router mode.</b>\n");
//	}
//	else if(pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L2BRIDGEMODE) {
//		websWrite(wp, "<b>Does not support url filter function in bridge mode.</b>\n");
//	}
	return 0;

}

void asp_setUrlFilter(request * wp, char *path, char *query)
{
	char tmpstr[32]={0};
	int i;
	int ms=atoi(websGetVar(wp,"ms",""));

	/* add trusted users */
	rtl8651_flushUrlFilterTrustedUser();
	for(i=0;i<URL_FILTER_MAX_TRUSTED_USERS;i++)
	{
		ipaddr_t ip2;
		sprintf(tmpstr,"tenable%u",i);
		pRomeCfgParam->urlfilterTrustedUserCfgParam[i].enable=atoi(websGetVar(wp,tmpstr,"")); 

		sprintf(tmpstr,"trusted%u",i);		
		parse_ipRange(websGetVar(wp, tmpstr, ""), &pRomeCfgParam->urlfilterTrustedUserCfgParam[i].trustedIP, &ip2);
		
		if((pRomeCfgParam->urlfilterTrustedUserCfgParam[i].trustedIP!=0) && (pRomeCfgParam->urlfilterTrustedUserCfgParam[i].enable==1))
			rtl8651_addUrlFilterTrustedUser(pRomeCfgParam->urlfilterTrustedUserCfgParam[i].trustedIP);
	}
	
	for(i=0;i<MAX_URL_FILTER;i++)
	{
		//delete old url filter string
		if(pRomeCfgParam->urlfilterCfgParam[ms][i].enable==1)
		{
			//rtl8651a_delURLfilterString(ms,pRomeCfgParam->urlfilterCfgParam[ms][i].string, strlen(pRomeCfgParam->urlfilterCfgParam[ms][i].string));
			rtl8651_delURLFilterRule(ms, pRomeCfgParam->urlfilterCfgParam[ms][i].string, strlen(pRomeCfgParam->urlfilterCfgParam[ms][i].string), 
								pRomeCfgParam->urlfilterCfgParam[ms][i].ip_start, pRomeCfgParam->urlfilterCfgParam[ms][i].ip_end);
		}
		
		//get new url filter string params
		sprintf(tmpstr,"string%u",i);
		memcpy(pRomeCfgParam->urlfilterCfgParam[ms][i].string,websGetVar(wp,tmpstr,""),sizeof(pRomeCfgParam->urlfilterCfgParam[ms][i].string));		
		sprintf(tmpstr,"enable%u",i);
		pRomeCfgParam->urlfilterCfgParam[ms][i].enable=atoi(websGetVar(wp,tmpstr,"")); 
		sprintf(tmpstr, "ipRange%u", i);
		parse_ipRange(websGetVar(wp, tmpstr, ""), &pRomeCfgParam->urlfilterCfgParam[ms][i].ip_start, &pRomeCfgParam->urlfilterCfgParam[ms][i].ip_end);
		
		
		//add new url filter string
		if(pRomeCfgParam->urlfilterCfgParam[ms][i].enable==1)
		{
			//rtl8651a_addURLfilterString(ms,pRomeCfgParam->urlfilterCfgParam[ms][i].string, strlen(pRomeCfgParam->urlfilterCfgParam[ms][i].string));
			rtl8651_addURLFilterRule(ms, pRomeCfgParam->urlfilterCfgParam[ms][i].string, strlen(pRomeCfgParam->urlfilterCfgParam[ms][i].string), 
								pRomeCfgParam->urlfilterCfgParam[ms][i].ip_start, pRomeCfgParam->urlfilterCfgParam[ms][i].ip_end);
		}
		sprintf(tmpstr,"ipRange%u",i);
		parse_ipRange(websGetVar(wp,tmpstr,""),   &pRomeCfgParam->urlfilterCfgParam[ms][i].ip_start, &pRomeCfgParam->urlfilterCfgParam[ms][i].ip_end);
	}


	cfgmgr_write(CFGMGR_TABID_URLFILTERTRUSTEDUSER,(void*)pRomeCfgParam->urlfilterTrustedUserCfgParam,sizeof(urlfilterTrustedUserCfgParam_t)*URL_FILTER_MAX_TRUSTED_USERS);
	cfgmgr_task();
		
	cfgmgr_write(CFGMGR_TABID_URLFILTER,(void*)pRomeCfgParam->urlfilterCfgParam,sizeof(urlfilterCfgParam_t)*MAX_URL_FILTER*MAX_PPPOE_SESSION);
	cfgmgr_task();

	sprintf(tmpstr,"/urlfilter.asp?ms=%d",ms);
	websRedirect(wp, tmpstr);	
	
}

/************************************************************
 *	
 *	PING
 *	
 ************************************************************/
static int ping_sec=0; 
int asp_ping(request * wp, int argc, char **argv)
{
	char tempStr[160];
	FILE *f,*f2;
	int finished=0;
	if(strcmp(argv[0],"pingstr")==0)
	{
		websWrite(wp,"%s",websGetVar(wp,"pingstr",""));
		return 0;
	}
	f2=fopen("/var/run/ping.pid","r");
	if(f2!=NULL)
	{
		if(strcmp(argv[0],"refresh")==0)
			{
				ping_sec++;				
				sprintf(tempStr,"<META HTTP-EQUIV=Refresh CONTENT=\"1; URL=ping.asp?pingstr=%s\">",websGetVar(wp,"pingstr",""));
				websWrite(wp,tempStr);
				fclose(f2);
				return 0;				
			}
		if(strcmp(argv[0],"enable")==0)
			{
				websWrite(wp,"disabled");
				fclose(f2);
				return 0;
			}	
		fclose(f2);	
	}
	
	if(strcmp(argv[0],"response")==0)
	{
		f=fopen("/var/run/ping.txt","r");
		if(f!=NULL)
		{				
			while(!feof(f))
			{
				fgets(tempStr,160,f);
				if(memcmp(tempStr,"--END--",7)==0) {ping_sec=0;finished=1;break;}
				if(feof(f)) break;
				websWrite(wp,"%s<BR>",tempStr);
				
			}
			fclose(f);
		}
		else
		{
			if(ping_sec>=20)
			{				
				ping_sec=0;
				websWrite(wp,"Destination Unreachable");
			}
			else if(ping_sec>=19)
			{
				unlink("/var/run/ping.pid");
				websWrite(wp,"Destination Unreachable");
			}
			else if(ping_sec>=1)
			{
				websWrite(wp,"Pinging...");
			}
			else
				websWrite(wp,"&lt;Empty&gt;");
		}
		if(finished==1) unlink("/var/run/ping.txt");
	}
	return 0;
}

void asp_setPing(request * wp, char *path, char *query)
{
	char tempStr[160];
	ping_sec=0;	
	sprintf(tempStr,"ping -f -c 4 %s &",websGetVar(wp,"pingstr",""));
	system(tempStr);
	sleep(1);
	sprintf(tempStr,"/ping.asp?pingstr=%s",websGetVar(wp,"pingstr",""));
	websRedirect(wp, tempStr);
}

/************************************************************
 *	
 *	Time Zone
 *	
 ************************************************************/
int asp_TZ(request * wp, int argc, char **argv)
{
	if(atoi(argv[0])==pRomeCfgParam->timeCfgParam.timeZoneIndex) websWrite(wp," selected");
	return 0;
}

int asp_TZ2(request * wp, int argc, char **argv)
{
	if(strcmp(argv[0],"ntpServer1")==0) websWrite(wp,"%s",pRomeCfgParam->timeCfgParam.ntpServer1);
	if(strcmp(argv[0],"ntpServer2")==0) websWrite(wp,"%s",pRomeCfgParam->timeCfgParam.ntpServer2);
	if(strcmp(argv[0],"ntpServer3")==0) websWrite(wp,"%s",pRomeCfgParam->timeCfgParam.ntpServer3);
	if(strcmp(argv[0],"dateTime")==0) 
	{
		clock_t t;
		time(&t);		
		websWrite(wp,"%s (GMT ",ctime(&t));
		if(pRomeCfgParam->timeCfgParam.timeZone[0]=='-')
			{websWrite(wp,"+");}
		else
			{websWrite(wp,"-");}
		websWrite(wp,"%s)",pRomeCfgParam->timeCfgParam.timeZone+1);	
		
	}
	return 0;
}

void asp_setTZ(request * wp, char *path, char *query)
{
	char tmp[32]={0};
	if(strcmp(websGetVar(wp,"submit",""),"Save / Time Sync")==0)
	{
		int32 timezone_diff;
		memcpy(tmp,websGetVar(wp,"timeZone",""),3);
		pRomeCfgParam->timeCfgParam.timeZoneIndex=atoi(tmp);
		strcpy(pRomeCfgParam->timeCfgParam.ntpServer1,websGetVar(wp,"ntpServer1",""));
		strcpy(pRomeCfgParam->timeCfgParam.ntpServer2,websGetVar(wp,"ntpServer2",""));
		strcpy(pRomeCfgParam->timeCfgParam.ntpServer3,websGetVar(wp,"ntpServer3",""));
		strcpy(tmp,websGetVar(wp,"timeZone",""));
		strcpy(pRomeCfgParam->timeCfgParam.timeZone,(char *)(tmp+3));
		
		timezone_diff=(tmp[4]-'0')*36000+(tmp[5]-'0')*3600+(tmp[7]-'0')*600+(tmp[8]-'0')*60;
		if(tmp[3]=='+') timezone_diff*=-1;
		rtl8651_setTimeZone(timezone_diff);

//		sprintf(tmp,"std%s",pRomeCfgParam->timeCfgParam.timeZone);
//		setenv("TZ",tmp, 1);

		zone_init();
		
		time_start();
		cfgmgr_write(CFGMGR_TABID_TIME,(void*)&pRomeCfgParam->timeCfgParam,sizeof(timeCfgParam_t));
		cfgmgr_task();
	}
	websRedirect(wp, "/mgmt.asp");
}


/************************************************************
 *	
 *	Remote Management
 *	
 ************************************************************/
int asp_remoteMgmt(request * wp, int argc, char **argv)
{
	if(strcmp(argv[0],"remoteMgmtIp")==0)  websWrite(wp,"%u.%u.%u.%u",NIPQUAD(pRomeCfgParam->mgmtCfgParam[0].remoteMgmtIp));
	if(strcmp(argv[0],"remoteMgmtMask")==0)  websWrite(wp,"%u.%u.%u.%u",NIPQUAD(pRomeCfgParam->mgmtCfgParam[0].remoteMgmtMask));
	if(strcmp(argv[0],"remoteMgmtPort")==0)  websWrite(wp,"%d",pRomeCfgParam->mgmtCfgParam[0].remoteMgmtPort);
	if(strcmp(argv[0],"remoteIcmpEnable")==0)  if(pRomeCfgParam->mgmtCfgParam[0].remoteIcmpEnable==1) websWrite(wp,"checked");
	return 0;
}

void asp_setRemoteMgmt(request * wp, char *path, char *query)
{
	uint32 tmp;
	pRomeCfgParam->mgmtCfgParam[0].remoteMgmtPort=atoi(websGetVar(wp,"remoteMgmtPort",""));
	pRomeCfgParam->mgmtCfgParam[0].remoteIcmpEnable=atoi(websGetVar(wp,"remoteIcmpEnable",""));	
	
	parse_ipRange(websGetVar(wp,"remoteMgmtIp",""),&pRomeCfgParam->mgmtCfgParam[0].remoteMgmtIp,&tmp);
	parse_ipRange(websGetVar(wp,"remoteMgmtMask",""),&pRomeCfgParam->mgmtCfgParam[0].remoteMgmtMask,&tmp);	
	remoteMgmt_tableDriverAccess();
	cfgmgr_write(CFGMGR_TABID_MGMT,(void*)pRomeCfgParam->mgmtCfgParam,sizeof(mgmtCfgParam_t)*MAX_MGMT_USER);
	cfgmgr_task();	
	websRedirect(wp, "/mgmt.asp");
}

/************************************************************
 *	
 *	User Management
 *	
 ************************************************************/
int asp_user(request * wp, int argc, char **argv)
{
	if(strcmp(argv[0],"account")==0)  websWrite(wp,"%s",pRomeCfgParam->mgmtCfgParam[0].name);
	if(strcmp(argv[0],"password")==0)  websWrite(wp,"%s",pRomeCfgParam->mgmtCfgParam[0].password);
	return 0;
}

void asp_setUser(request * wp, char *path, char *query)
{
				
	strcpy(pRomeCfgParam->mgmtCfgParam[0].name,websGetVar(wp,"account",""));
	strcpy(pRomeCfgParam->mgmtCfgParam[0].password,websGetVar(wp,"password",""));

	time_start();
	cfgmgr_write(CFGMGR_TABID_MGMT,(void*)pRomeCfgParam->mgmtCfgParam,sizeof(mgmtCfgParam_t)*MAX_MGMT_USER);
	cfgmgr_task();
	
	websRedirect(wp, "/mgmt.asp");
}

/************************************************************
 *	
 *	Mail Alert Management
 *	
 ************************************************************/
int asp_mailAlert(request * wp, int argc, char **argv)
{
	if(strcmp(argv[0],"mailfrom")==0)  websWrite(wp,"%s",pRomeCfgParam->mgmtCfgParam[0].mailfrom);
	if(strcmp(argv[0],"rcptto")==0)  websWrite(wp,"%s",pRomeCfgParam->mgmtCfgParam[0].rcptto);
	if(strcmp(argv[0],"smtpserver")==0)  websWrite(wp,"%s",pRomeCfgParam->mgmtCfgParam[0].smtpserver);	
	return 0;
}

void asp_setMailAlert(request * wp, char *path, char *query)
{
			
	strcpy(pRomeCfgParam->mgmtCfgParam[0].mailfrom,websGetVar(wp,"mailfrom",""));
	strcpy(pRomeCfgParam->mgmtCfgParam[0].rcptto,websGetVar(wp,"rcptto",""));
	strcpy(pRomeCfgParam->mgmtCfgParam[0].smtpserver,websGetVar(wp,"smtpserver",""));	

	cfgmgr_write(CFGMGR_TABID_MGMT,(void*)pRomeCfgParam->mgmtCfgParam,sizeof(mgmtCfgParam_t)*MAX_MGMT_USER);
	cfgmgr_task();
	
	websRedirect(wp, "/mgmt.asp");
}


/************************************************************
 *	
 *	Remote Log Management
 *	
 ************************************************************/
int asp_remoteLog(request * wp, int argc, char **argv)
{
	if(strcmp(argv[0],"logserver")==0)  websWrite(wp,"%s",pRomeCfgParam->mgmtCfgParam[0].logserver);	
	return 0;
}

void asp_setRemoteLog(request * wp, char *path, char *query)
{
			
	strcpy(pRomeCfgParam->mgmtCfgParam[0].logserver,websGetVar(wp,"logserver",""));	

	cfgmgr_write(CFGMGR_TABID_MGMT,(void*)pRomeCfgParam->mgmtCfgParam,sizeof(mgmtCfgParam_t)*MAX_MGMT_USER);
	cfgmgr_task();
	
	websRedirect(wp, "/mgmt.asp");
}

/************************************************************
 *	
 *	Napt Options
 *	
 ************************************************************/
#define NAPT_OPTCNT	4

void asp_setNaptOpt(request * wp, char *path, char *query)
{
	char tmpstr[64];
	uint32 idx;
	char* naptOptItem[NAPT_OPTCNT] = {"UDP_Static_Port_Translation", "TCP_Static_Port_Translation", "TCP_Weak_NAPT","LOOSE_UDP"};
	uint8* romeCfg[NAPT_OPTCNT] =
		{	&pRomeCfgParam->naptCfgParam.udpStaticPortMappingEnable,
			&pRomeCfgParam->naptCfgParam.tcpStaticPortMappingEnable,
			&pRomeCfgParam->naptCfgParam.weakNaptEnable,
			&pRomeCfgParam->naptCfgParam.looseUdpEnable
		};
	
	/* store napt options */
	for (idx = 0 ; idx < NAPT_OPTCNT ; idx ++)
	{
		sprintf(tmpstr, "Enable_%s", naptOptItem[idx]);
		*romeCfg[idx] = atoi(websGetVar(wp,tmpstr,""));
	}

	/* set napt options */
	rtl8651_WeakNaptCtrl(pRomeCfgParam->naptCfgParam.weakNaptEnable);
	rtl8651_TcpNaptStaticPortMappingCtrl(pRomeCfgParam->naptCfgParam.tcpStaticPortMappingEnable);
	rtl8651_UdpNaptStaticPortMappingCtrl(pRomeCfgParam->naptCfgParam.udpStaticPortMappingEnable);
	rtl8651_looseUdpCtrl(pRomeCfgParam->naptCfgParam.looseUdpEnable);
	/* update flash and refresh web page */
	cfgmgr_write(CFGMGR_TABID_NAPT, (void*)&(pRomeCfgParam->naptCfgParam), sizeof(struct naptCfgParam_s));
	cfgmgr_task();
	sprintf(tmpstr, "/naptopt.asp");
	websRedirect(wp, tmpstr);
}

int asp_naptOpt(request * wp, int argc, char **argv)
{
	int32 idx;
	char* naptOptName[NAPT_OPTCNT] = {"Default don't masquerade source port number for new UDP flows", "Default don't masquerade source port number for new TCP flows", "Create TCP flows without stateful tracking","Create UDP flows regardless of destination info"};
	char* naptOptItem[NAPT_OPTCNT] = {"UDP_Static_Port_Translation", "TCP_Static_Port_Translation", "TCP_Weak_NAPT","LOOSE_UDP"};
	uint8 romeCfg[NAPT_OPTCNT] =
		{pRomeCfgParam->naptCfgParam.udpStaticPortMappingEnable,
		pRomeCfgParam->naptCfgParam.tcpStaticPortMappingEnable,
		pRomeCfgParam->naptCfgParam.weakNaptEnable,
		pRomeCfgParam->naptCfgParam.looseUdpEnable
	};

	if (strcmp(argv[0], "ListALL") == 0)
	{	/* List setting fields of all options */
		for (idx = 0 ; idx < NAPT_OPTCNT ; idx ++)
		{
			websWrite(wp, "<tr>");
				websWrite(wp, "<td bgColor=#aaddff>%s</td>", naptOptName[idx]);
				websWrite(wp, "<td bgColor=#ddeeff>");
				websWrite(wp, "<input type=checkbox name=\"Enable_%s\" value=1 %s>", naptOptItem[idx], (romeCfg[idx]?"checked":""));
				websWrite(wp, "</td>");
			websWrite(wp, "</tr>");
		}
	}
#if 0
	else if (strcmp(argv[0], "DescriptAll") == 0)
	{	/* print descriptors of all options */
		/* static port translation */
		websWrite(wp, "<li>TCP/UDP Static NAPT port translation mode: keep source port for normal outbound TCP/UDP napt flows\n");
		websWrite(wp, "<ul>\n");
			websWrite(wp, "<li>Try to keep source port of normal oubound TCP/UDP napt flow except the following situations:");
			websWrite(wp, "<ul>\n");
			websWrite(wp, "<li>This port is used by protocol stack\n");
			websWrite(wp, "<li>This port is used by other active-napt flow\n");
			websWrite(wp, "<li>This port is registered by triggered trigger port\n");
			websWrite(wp, "<li>This port is registered by server port\n");
			websWrite(wp, "<li>This port is registered by uPnP\n");
			websWrite(wp, "</ul>\n");
		websWrite(wp, "</ul>\n");
		/* weak NAPT */
		websWrite(wp, "<li>Weak napt mode: Apply weak napt SPI checking for TCP flows:\n");
		websWrite(wp, "<ul>\n");
			websWrite(wp, "<li>For Outbound unknown non-SYN TCP packets, system create an ESTABLISHED flow for them.\n");
			websWrite(wp, "<li>For Inbound unknown non-SYN TCP packets, if Virtual Server/DMZ Host/uPnP is set for them, system create an ESTABLISHED flow for them.\n");
			websWrite(wp, "<li>Co-operate with trigger port:\n");
			websWrite(wp, "<ul>\n");
				websWrite(wp, "<li>For Outbound unknown non-SYN TCP packets which can trigger trigger ports: system will trigger corresponding ports for them.");
				websWrite(wp, "<li>For Inbound unknown non-SYN TCP packets which match the ports triggered: system will apply the triggered ports for them.");
			websWrite(wp, "</ul>\n");
			websWrite(wp, "<b>");
			websWrite(wp, "<font color=block>");
				websWrite(wp, "[");
			websWrite(wp, "</font>");
			websWrite(wp, "<font color=red>");
				websWrite(wp, "NOTE");
			websWrite(wp, "</font>");
			websWrite(wp, "<font color=block>");
				websWrite(wp, "]");
			websWrite(wp, "</font>");
			websWrite(wp, "<font color=blue>");
			websWrite(wp, " This option will disable napt SPI and suggested to turn-ON only for testing.");
			websWrite(wp, "</font>");
			websWrite(wp, "</b>");
		websWrite(wp, "</ul>\n");
	}
#endif	
	return 0;
}

/************************************************************
 *	
 *	DoS
 *	
 ************************************************************/

#define asp_dos_PktInspectDosCheckCnt		11
/* for flood check */
#define asp_dos_PktCountDosCnt				2
#define asp_dos_PktCountDosCheckCnt		4
/* for connection control */
#define asp_dos_ConnCountDosCnt			2
#define asp_dos_ConnCountDosCheckCnt		3
/* for port scan check */
#define asp_dos_AdjustableDosCnt			1
#define asp_dos_AdjustableDosLevelCnt		2

int asp_dos(request * wp, int argc, char **argv)
{
	int i, j;
	int ms=asp_multiSession(wp,argc,argv);

	char* PktInspectDosList[]			= {"TcpScan", "TcpSynWithData", "TcpLand", "UdpEchoChargen", "UdpBomb", "UdpLand", "PingOfDeath", "IcmpSmurf", "IcmpLand", "IpSpoof", "TearDrop"};
	char* PktCountDosList[] 			= {"Whole System Flood", "Per-Source IP Flood"};
	char* PktCountDosCheckList[]		= {"SYN", "FIN", "UDP", "ICMP"};
	char* ConnCountDosList[]			= {"Whole System FlowCnt Control", "Per-Source IP FlowCnt Control"};
	char* ConnCountDosCheckList[]	= {"TCP_Flow", "UDP_Flow", "Both"};
	char* AdjustableList[]				= {"TcpUdpPortScan"};
	char* AdjustableLevelList[]		= {"Low", "High"};

	if (strcmp(argv[0], "ENABLE") == 0)
	{
		if (pRomeCfgParam->dosCfgParam[ms].enable)
			websWrite(wp, "checked");
	}else if (strcmp(argv[0],"MS") == 0)
	{
		websWrite(wp, "%d", ms);
	}else if (strcmp(argv[0], "Ignore_Lan") == 0)
	{
		if (pRomeCfgParam->dosCfgParam[ms].ignoreLanSideCheck)
			websWrite(wp, "checked");
	}else if (strcmp(argv[0],"dosList")==0)
	{
		char* checkStream = "checked";
		char* nullStream = "";
		/* Show dos List */
		
		/* flood check */
		for (i = 0 ; i < asp_dos_PktCountDosCnt ; i ++)
		{
			websWrite(wp,	"<tr>\n" \
							"<td bgColor=#aaddff>%s</td>\n" \
							"<td>\n" \
							"<table width=100%%>\n", PktCountDosList[i]);

			for (j = 0 ; j < asp_dos_PktCountDosCheckCnt ; j ++)
			{
				char** checkPtr;
				uint16 threshold;
				checkPtr = &nullStream;
				switch(j)
				{
					case 0:	/* SYN */
						if (i == 0)
						{
							threshold = pRomeCfgParam->dosCfgParam[ms].syn;
							if (pRomeCfgParam->dosCfgParam[ms].enableItem&RTL8651_DOS_SYNFLOOD)		checkPtr = &checkStream;
						}
						if (i == 1)
						{
							threshold = pRomeCfgParam->dosCfgParam[ms].perSrc_syn;
							if (pRomeCfgParam->dosCfgParam[ms].enableItem&RTL8651_DOS_SRC_SYNFLOOD)	checkPtr = &checkStream;
						}
						break;
					case 1:	/* FIN */
						if (i == 0)
						{
							threshold = pRomeCfgParam->dosCfgParam[ms].fin;
							if (pRomeCfgParam->dosCfgParam[ms].enableItem&RTL8651_DOS_STEALTHFIN)		checkPtr = &checkStream;
						}
						if (i == 1)
						{
							threshold = pRomeCfgParam->dosCfgParam[ms].perSrc_fin;
							if (pRomeCfgParam->dosCfgParam[ms].enableItem&RTL8651_DOS_SRC_STEALTHFIN)	checkPtr = &checkStream;
						}
						break;
					case 2:	/* UDP */
						if (i == 0)
						{
							threshold = pRomeCfgParam->dosCfgParam[ms].udp;
							if (pRomeCfgParam->dosCfgParam[ms].enableItem&RTL8651_DOS_UDPFLOOD)		checkPtr = &checkStream;
						}
						if (i == 1)
						{
							threshold = pRomeCfgParam->dosCfgParam[ms].perSrc_udp;
							if (pRomeCfgParam->dosCfgParam[ms].enableItem&RTL8651_DOS_SRC_UDPFLOOD)	checkPtr = &checkStream;
						}
						break;
					case 3:	/* ICMP */
						if (i == 0)
						{
							threshold = pRomeCfgParam->dosCfgParam[ms].icmp;
							if (pRomeCfgParam->dosCfgParam[ms].enableItem&RTL8651_DOS_ICMPFLOOD)		checkPtr = &checkStream;
						}
						if (i == 1)
						{
							threshold = pRomeCfgParam->dosCfgParam[ms].perSrc_icmp;
							if (pRomeCfgParam->dosCfgParam[ms].enableItem&RTL8651_DOS_SRC_ICMPFLOOD)	checkPtr = &checkStream;
						}
						break;
				}
				websWrite(wp,	"<tr>\n"\
								"<td bgColor=#ddeeff><input type=checkbox name=Enable_%s_%d value=1 %s></td>\n"\
								"<td bgColor=#aaddff>%s</td>\n"\
								"<td bgColor=#ddeeff><input type=text name=Count_%s_%d value=%d size=3 maxlength=3 >Packets/Second</td>\n" \
								"</tr>\n", \
								PktCountDosCheckList[j], i, *checkPtr, PktCountDosCheckList[j], PktCountDosCheckList[j], i, threshold);
			}
			
			websWrite(wp,	"</table>\n" \
							"</td>\n" \
							"</tr>\n");
		}

		/* connection count check */
		for (i = 0 ; i < asp_dos_ConnCountDosCnt ; i ++)
		{
			websWrite(wp,	"<tr>\n" \
							"<td bgColor=#aaddff>%s</td>\n" \
							"<td>\n" \
							"<table width=100%%>\n", ConnCountDosList[i]);

			for (j = 0 ; j < asp_dos_ConnCountDosCheckCnt ; j ++)
			{
				char** checkPtr;
				uint16 threshold;
				checkPtr = &nullStream;
				switch(j)
				{
					case 0:	/* TCP */
						if (i == 0)
						{
							threshold = pRomeCfgParam->dosCfgParam[ms].tcpc;
							if (pRomeCfgParam->dosCfgParam[ms].enableItem&RTL8651_DOS_TCPCONNOVERFLOW)	checkPtr = &checkStream;
						}
						if (i == 1)
						{
							threshold = pRomeCfgParam->dosCfgParam[ms].perSrc_tcpc;
							if (pRomeCfgParam->dosCfgParam[ms].enableItem&RTL8651_DOS_SRC_TCPCONNOVERFLOW)	checkPtr = &checkStream;
						}
						break;
					case 1:	/* UDP */
						if (i == 0)
						{
							threshold = pRomeCfgParam->dosCfgParam[ms].udpc;
							if (pRomeCfgParam->dosCfgParam[ms].enableItem&RTL8651_DOS_UDPCONNOVERFLOW)		checkPtr = &checkStream;
						}
						if (i == 1)
						{
							threshold = pRomeCfgParam->dosCfgParam[ms].perSrc_udpc;
							if (pRomeCfgParam->dosCfgParam[ms].enableItem&RTL8651_DOS_SRC_UDPCONNOVERFLOW)	checkPtr = &checkStream;
						}
						break;
					case 2:	/* Both */
						if (i == 0)
						{
							threshold = pRomeCfgParam->dosCfgParam[ms].tcpudpc;
							if (pRomeCfgParam->dosCfgParam[ms].enableItem&RTL8651_DOS_TCPUDPCONNOVERFLOW)		checkPtr = &checkStream;
						}
						if (i == 1)
						{
							threshold = pRomeCfgParam->dosCfgParam[ms].perSrc_tcpudpc;
							if (pRomeCfgParam->dosCfgParam[ms].enableItem&RTL8651_DOS_SRC_TCPUDPCONNOVERFLOW)	checkPtr = &checkStream;
						}
						break;
				}
				websWrite(wp,	"<tr>\n"\
								"<td bgColor=#ddeeff><input type=checkbox name=Enable_%s_%d value=1 %s></td>\n"\
								"<td bgColor=#aaddff>%s</td>\n"\
								"<td bgColor=#ddeeff><input type=text name=Count_%s_%d value=%d size=4 maxlength=4 >Flows</td>\n" \
								"</tr>\n", \
								ConnCountDosCheckList[j], i, *checkPtr, ConnCountDosCheckList[j], ConnCountDosCheckList[j], i, threshold);
			}
			
			websWrite(wp,	"</table>\n" \
							"</td>\n" \
							"</tr>\n");
		}

		/* adjustable check */
		for (i = 0 ; i < asp_dos_AdjustableDosCnt ; i ++)
		{
				char** checkPtr;

				checkPtr = &nullStream;
				switch(i)
				{
					case 0:	/* TCP/UDP Port Scan */
						if (pRomeCfgParam->dosCfgParam[ms].enableItem&RTL8651_DOS_PORTSCAN)
							checkPtr = &checkStream;
						break;
				}		
			websWrite(wp,	"<tr>\n" \
				"<td bgColor=#aaddff>%s</td>\n" \
				"<td>\n" \
				"<table  width=100%%>\n", AdjustableList[i]);

			/* generate check box and Level select icon */
			websWrite(wp, "<tr>\n"\
							"<td bgColor=#ddeeff><input type=checkbox name=Enable_%s value=1 %s></td>\n"\
							"<td bgColor=#aaddff>Level</td>\n"\
							"<td bgColor=#ddeeff><select name=Level_%s>"\
							, AdjustableList[i], *checkPtr, AdjustableList[i]);
			for (j = 0 ; j < asp_dos_AdjustableDosLevelCnt ; j ++)
			{	/* list total Levels */
				websWrite(wp, "<option  value=%d %s>%s", j, ((pRomeCfgParam->dosCfgParam[ms].portScan_level == j)?"selected":""), AdjustableLevelList[j]);
			}
			websWrite(wp, "</select>Sensitivity</td></tr>\n");
			websWrite(wp,	"</table>\n" \
							"</td>\n" \
							"</tr>\n");
		}
		
		/* packet inspect check */
		for (i = 0 ; i < asp_dos_PktInspectDosCheckCnt ; i ++)
		{
			char** checkPtr;
			checkPtr = &nullStream;
			switch(i)
			{
				case 0:	/* tcp scan */
					if (pRomeCfgParam->dosCfgParam[ms].enableItem&RTL8651_DOS_SCAN)		checkPtr = &checkStream;
					break;
				case 1:	/* syn with data */
					if (pRomeCfgParam->dosCfgParam[ms].enableItem&RTL8651_DOS_SYNWITHDATA)	checkPtr = &checkStream;
					break;
				case 2:	/* tcp land */
					if (pRomeCfgParam->dosCfgParam[ms].enableItem&RTL8651_DOS_TCPLAND)		checkPtr = &checkStream;
					break;
				case 3:	/* udp echo chargen */
					if (pRomeCfgParam->dosCfgParam[ms].enableItem&RTL8651_DOS_ECHOCHARGEN)	checkPtr = &checkStream;
					break;
				case 4:	/* udp bomb */
					if (pRomeCfgParam->dosCfgParam[ms].enableItem&RTL8651_DOS_UDPBOMB)		checkPtr = &checkStream;
					break;
				case 5:	/* udp land */
					if (pRomeCfgParam->dosCfgParam[ms].enableItem&RTL8651_DOS_UDPLAND)		checkPtr = &checkStream;
					break;
				case 6:	/* ping of death */
					if (pRomeCfgParam->dosCfgParam[ms].enableItem&RTL8651_DOS_PINGOFDEATH)	checkPtr = &checkStream;
					break;
				case 7:	/* icmp smurf */
					if (pRomeCfgParam->dosCfgParam[ms].enableItem&RTL8651_DOS_SMURF)		checkPtr = &checkStream;
					break;
				case 8:	/* icmp land */
					if (pRomeCfgParam->dosCfgParam[ms].enableItem&RTL8651_DOS_ICMPLAND)	checkPtr = &checkStream;
					break;
				case 9:	/* ip spoof */
					if (pRomeCfgParam->dosCfgParam[ms].enableItem&RTL8651_DOS_IPSPOOF)		checkPtr = &checkStream;
					break;
				case 10:	/* tear drop */
					if (pRomeCfgParam->dosCfgParam[ms].enableItem&RTL8651_DOS_TEARDROP)	checkPtr = &checkStream;
					break;
			}
			websWrite(wp,	"<tr>\n"  \
							"<td bgColor=#aaddff>%s</td>\n" \
							"<td bgColor=#ddeeff><input type=checkbox name=Enable_%s value=1 %s></td>\n" \
							"</tr>\n" \
							, PktInspectDosList[i], PktInspectDosList[i], *checkPtr);
		}
		/* "select all" button and "clear all" button */
		websWrite(wp,	"<tr>\n" \
						"<td bgColor=#aaddff></td>\n" \
						"<td bgColor=#ddeeff>\n" \
						"<input type=button align=center name=selectall value=\"SelectALL\" onClick=\"dos_SelectAll();\">\n" \
						"<input type=button align=center name=clearall value=\"ClearALL\" onClick=\"dos_ClearAll();\">\n" \
						"</td></tr>\n");

	}else if (strcmp(argv[0], "dosItemAvailable") == 0)
	{	/* make check list available */
		/* flood check */
		for (i = 0 ; i < asp_dos_PktCountDosCnt ; i++)
		for (j = 0 ; j < asp_dos_PktCountDosCheckCnt ; j++)
		{
			websWrite(wp,	"\t\tdos.Enable_%s_%d.disabled = false;\n" \
							"\t\tdos.Count_%s_%d.disabled = false;\n" \
							, PktCountDosCheckList[j], i, PktCountDosCheckList[j], i);
		}
		/* connection count control */
		for (i = 0 ; i < asp_dos_ConnCountDosCnt ; i++)
		for (j = 0 ; j < asp_dos_ConnCountDosCheckCnt ; j++)
		{
			websWrite(wp,	"\t\tdos.Enable_%s_%d.disabled = false;\n" \
							"\t\tdos.Count_%s_%d.disabled = false;\n" \
							, ConnCountDosCheckList[j], i, ConnCountDosCheckList[j], i);
		}
		/* level Adjustable check */
		for (i = 0 ; i < asp_dos_AdjustableDosCnt ; i ++)
		{
			websWrite(wp,	"\t\tdos.Enable_%s.disabled = false;\n" \
							"\t\tdos.Level_%s.disabled = false;\n" \
							, AdjustableList[i], AdjustableList[i]);
		}
		/* packet inspect check */
		for (i = 0 ; i < asp_dos_PktInspectDosCheckCnt ; i ++)
		{
			websWrite(wp,	"\t\tdos.Enable_%s.disabled = false;\n" \
							, PktInspectDosList[i]);
		}
		/* select/clear all button */
		websWrite(wp,		"\t\tdos.selectall.disabled = false;\n" \
							"\t\tdos.clearall.disabled = false;\n");
	}else if (strcmp(argv[0], "dosItemUnavailable") == 0)
	{	/* make check list Unavailable */
		/* flood check */
		for (i = 0 ; i < asp_dos_PktCountDosCnt ; i++)
		for (j = 0 ; j < asp_dos_PktCountDosCheckCnt ; j++)
		{
			websWrite(wp,	"\t\tdos.Enable_%s_%d.disabled = true;\n" \
							"\t\tdos.Count_%s_%d.disabled = true;\n" \
							, PktCountDosCheckList[j], i, PktCountDosCheckList[j], i);
		}
		/* connection count control */
		for (i = 0 ; i < asp_dos_ConnCountDosCnt ; i++)
		for (j = 0 ; j < asp_dos_ConnCountDosCheckCnt ; j++)
		{
			websWrite(wp,	"\t\tdos.Enable_%s_%d.disabled = true;\n" \
							"\t\tdos.Count_%s_%d.disabled = true;\n" \
							, ConnCountDosCheckList[j], i, ConnCountDosCheckList[j], i);
		}
		/* level Adjustable check */
		for (i = 0 ; i < asp_dos_AdjustableDosCnt ; i ++)
		{
			websWrite(wp,	"\t\tdos.Enable_%s.disabled = true;\n" \
							"\t\tdos.Level_%s.disabled = true;\n" \
							, AdjustableList[i], AdjustableList[i]);
		}
		/* packet inspect check */
		for (i = 0 ; i < asp_dos_PktInspectDosCheckCnt ; i ++)
		{
			websWrite(wp,	"\t\tdos.Enable_%s.disabled = true;\n" \
							, PktInspectDosList[i]);
		}
		/* select/clear all button */
		websWrite(wp,		"\t\tdos.selectall.disabled = true;\n" \
							"\t\tdos.clearall.disabled = true;\n");
	}else if (strcmp(argv[0], "ThresHoldCheck") == 0)
	{
		/* flooding */
		for (i = 0 ; i < asp_dos_PktCountDosCnt ; i++)
		for (j = 0 ; j < asp_dos_PktCountDosCheckCnt ; j++)
		{
			websWrite(wp,	"\t\tif ((dos.Enable_%s_%d.checked == 1) && (dos.Count_%s_%d.value == 0))\n" \
							"\t\t{alert('ThresHold Can NOT be 0.'); return false;}\n" \
							, PktCountDosCheckList[j], i, PktCountDosCheckList[j], i);
		}
		/* connection count control */
		for (i = 0 ; i < asp_dos_ConnCountDosCnt ; i++)
		for (j = 0 ; j < asp_dos_ConnCountDosCheckCnt ; j++)
		{
			websWrite(wp,	"\t\tif ((dos.Enable_%s_%d.checked == 1) && (dos.Count_%s_%d.value == 0))\n" \
							"\t\t{alert('ThresHold Can NOT be 0.'); return false;}\n" \
							, ConnCountDosCheckList[j], i, ConnCountDosCheckList[j], i);
		}
	}else if (strcmp(argv[0], "SelectAllItem") == 0)
	{
		/* flood check */
		for (i = 0 ; i < asp_dos_PktCountDosCnt ; i++)
		for (j = 0 ; j < asp_dos_PktCountDosCheckCnt ; j++)
		{
			websWrite(wp,	"\t\tdos.Enable_%s_%d.checked = true;\n" \
							, PktCountDosCheckList[j], i);
		}
		/* connection count control */
		for (i = 0 ; i < asp_dos_ConnCountDosCnt ; i++)
		for (j = 0 ; j < asp_dos_ConnCountDosCheckCnt ; j++)
		{
			websWrite(wp,	"\t\tdos.Enable_%s_%d.checked = true;\n" \
							, ConnCountDosCheckList[j], i);
		}
		/* level Adjustable check */
		for (i = 0 ; i < asp_dos_AdjustableDosCnt ; i ++)
		{
			websWrite(wp,	"\t\tdos.Enable_%s.checked = true;\n" \
							, AdjustableList[i]);
		}
		/* packet inspect check */
		for (i = 0 ; i < asp_dos_PktInspectDosCheckCnt ; i ++)
		{
			websWrite(wp,	"\t\tdos.Enable_%s.checked = true;\n" \
							, PktInspectDosList[i]);
		}
	}else if (strcmp(argv[0], "ClearAllItem") == 0)
	{
		/* flood check */
		for (i = 0 ; i < asp_dos_PktCountDosCnt ; i++)
		for (j = 0 ; j < asp_dos_PktCountDosCheckCnt ; j++)
		{
			websWrite(wp,	"\t\tdos.Enable_%s_%d.checked = false;\n" \
							, PktCountDosCheckList[j], i);
		}
		/* connection count control */
		for (i = 0 ; i < asp_dos_ConnCountDosCnt ; i++)
		for (j = 0 ; j < asp_dos_ConnCountDosCheckCnt ; j++)
		{
			websWrite(wp,	"\t\tdos.Enable_%s_%d.checked = false;\n" \
							, ConnCountDosCheckList[j], i);
		}
		/* level Adjustable check */
		for (i = 0 ; i < asp_dos_AdjustableDosCnt ; i ++)
		{
			websWrite(wp,	"\t\tdos.Enable_%s.checked = false;\n" \
							, AdjustableList[i]);
		}
		/* packet inspect check */
		for (i = 0 ; i < asp_dos_PktInspectDosCheckCnt ; i ++)
		{
			websWrite(wp,	"\t\tdos.Enable_%s.checked = false;\n" \
							, PktInspectDosList[i]);
		}
	}
 	return 0;
}

void asp_setDos(request * wp, char *path, char *query)
{
	char tmpstr[64];
	int i,j;
	int ms=atoi(websGetVar(wp,"ms",""));
	char* PktInspectDosList[]			= {"TcpScan", "TcpSynWithData", "TcpLand", "UdpBomb", "UdpLand", "PingOfDeath", "IcmpSmurf", "IcmpLand", "IpSpoof", "TearDrop"};
	char* PktCountDosList[] 			= {"Whole System Flood", "Per-Source IP Flood"};
	char* PktCountDosCheckList[]		= {"SYN", "FIN", "UDP", "ICMP"};
	char* ConnCountDosList[]			= {"Whole System FlowCnt Control", "Per-Source IP FlowCnt Control"};
	char* ConnCountDosCheckList[]	= {"TCP_Flow", "UDP_Flow", "Both"};
	char* AdjustableList[]				= {"TcpUdpPortScan"};
	char* AdjustableLevelList[]		= {"Low", "High"};

	
	pRomeCfgParam->dosCfgParam[ms].enable = atoi(websGetVar(wp,"enable",""));

	pRomeCfgParam->dosCfgParam[ms].enableItem = 0;	// reset enable Item
	if (atoi(websGetVar(wp, "Enable_SYN_0","")))			{pRomeCfgParam->dosCfgParam[ms].enableItem |= RTL8651_DOS_SYNFLOOD;}
	if (atoi(websGetVar(wp, "Enable_FIN_0","")))			{pRomeCfgParam->dosCfgParam[ms].enableItem |= RTL8651_DOS_STEALTHFIN;}
	if (atoi(websGetVar(wp, "Enable_UDP_0","")))			{pRomeCfgParam->dosCfgParam[ms].enableItem |= RTL8651_DOS_UDPFLOOD;}
	if (atoi(websGetVar(wp, "Enable_ICMP_0","")))		{pRomeCfgParam->dosCfgParam[ms].enableItem |= RTL8651_DOS_ICMPFLOOD;}
	if (atoi(websGetVar(wp, "Enable_SYN_1","")))			{pRomeCfgParam->dosCfgParam[ms].enableItem |= RTL8651_DOS_SRC_SYNFLOOD;}
	if (atoi(websGetVar(wp, "Enable_FIN_1","")))			{pRomeCfgParam->dosCfgParam[ms].enableItem |= RTL8651_DOS_SRC_STEALTHFIN;}
	if (atoi(websGetVar(wp, "Enable_UDP_1","")))			{pRomeCfgParam->dosCfgParam[ms].enableItem |= RTL8651_DOS_SRC_UDPFLOOD;}
	if (atoi(websGetVar(wp, "Enable_ICMP_1","")))		{pRomeCfgParam->dosCfgParam[ms].enableItem |= RTL8651_DOS_SRC_ICMPFLOOD;}
	if (atoi(websGetVar(wp, "Enable_TCP_Flow_0","")))		{pRomeCfgParam->dosCfgParam[ms].enableItem |= RTL8651_DOS_TCPCONNOVERFLOW;}
	if (atoi(websGetVar(wp, "Enable_UDP_Flow_0","")))		{pRomeCfgParam->dosCfgParam[ms].enableItem |= RTL8651_DOS_UDPCONNOVERFLOW;}
	if (atoi(websGetVar(wp, "Enable_Both_0","")))			{pRomeCfgParam->dosCfgParam[ms].enableItem |= RTL8651_DOS_TCPUDPCONNOVERFLOW;}
	if (atoi(websGetVar(wp, "Enable_TCP_Flow_1","")))		{pRomeCfgParam->dosCfgParam[ms].enableItem |= RTL8651_DOS_SRC_TCPCONNOVERFLOW;}
	if (atoi(websGetVar(wp, "Enable_UDP_Flow_1","")))		{pRomeCfgParam->dosCfgParam[ms].enableItem |= RTL8651_DOS_SRC_UDPCONNOVERFLOW;}
	if (atoi(websGetVar(wp, "Enable_Both_1","")))			{pRomeCfgParam->dosCfgParam[ms].enableItem |= RTL8651_DOS_SRC_TCPUDPCONNOVERFLOW;}
	if (atoi(websGetVar(wp, "Enable_TcpScan","")))		{pRomeCfgParam->dosCfgParam[ms].enableItem |= RTL8651_DOS_SCAN;}
	if (atoi(websGetVar(wp, "Enable_TcpSynWithData","")))	{pRomeCfgParam->dosCfgParam[ms].enableItem |= RTL8651_DOS_SYNWITHDATA;}
	if (atoi(websGetVar(wp, "Enable_TcpLand","")))		{pRomeCfgParam->dosCfgParam[ms].enableItem |= RTL8651_DOS_TCPLAND;}
	if (atoi(websGetVar(wp, "Enable_UdpEchoChargen",""))){pRomeCfgParam->dosCfgParam[ms].enableItem |= RTL8651_DOS_ECHOCHARGEN;}
	if (atoi(websGetVar(wp, "Enable_UdpBomb","")))		{pRomeCfgParam->dosCfgParam[ms].enableItem |= RTL8651_DOS_UDPBOMB;}
	if (atoi(websGetVar(wp, "Enable_UdpLand","")))		{pRomeCfgParam->dosCfgParam[ms].enableItem |= RTL8651_DOS_UDPLAND;}
	if (atoi(websGetVar(wp, "Enable_PingOfDeath","")))	{pRomeCfgParam->dosCfgParam[ms].enableItem |= RTL8651_DOS_PINGOFDEATH;}
	if (atoi(websGetVar(wp, "Enable_IcmpSmurf","")))		{pRomeCfgParam->dosCfgParam[ms].enableItem |= RTL8651_DOS_SMURF;}
	if (atoi(websGetVar(wp, "Enable_IcmpLand","")))		{pRomeCfgParam->dosCfgParam[ms].enableItem |= RTL8651_DOS_ICMPLAND;}
	if (atoi(websGetVar(wp, "Enable_IpSpoof","")))		{pRomeCfgParam->dosCfgParam[ms].enableItem |= RTL8651_DOS_IPSPOOF;}
	if (atoi(websGetVar(wp, "Enable_TearDrop","")))		{pRomeCfgParam->dosCfgParam[ms].enableItem |= RTL8651_DOS_TEARDROP;}
	if (atoi(websGetVar(wp, "Enable_TcpUdpPortScan","")))	{pRomeCfgParam->dosCfgParam[ms].enableItem |= RTL8651_DOS_PORTSCAN;}
	

	if (pRomeCfgParam->dosCfgParam[ms].enableItem == 0)
	{
		pRomeCfgParam->dosCfgParam[ms].enable = 0;
	}

	/* threshold */
	/* flooding */
	pRomeCfgParam->dosCfgParam[ms].syn=atoi(websGetVar(wp,"Count_SYN_0",""));
	pRomeCfgParam->dosCfgParam[ms].fin=atoi(websGetVar(wp,"Count_FIN_0",""));	
	pRomeCfgParam->dosCfgParam[ms].udp=atoi(websGetVar(wp,"Count_UDP_0",""));
	pRomeCfgParam->dosCfgParam[ms].icmp=atoi(websGetVar(wp,"Count_ICMP_0",""));	
		
	pRomeCfgParam->dosCfgParam[ms].perSrc_syn=atoi(websGetVar(wp,"Count_SYN_1",""));
	pRomeCfgParam->dosCfgParam[ms].perSrc_fin=atoi(websGetVar(wp,"Count_FIN_1",""));
	pRomeCfgParam->dosCfgParam[ms].perSrc_udp=atoi(websGetVar(wp,"Count_UDP_1",""));
	pRomeCfgParam->dosCfgParam[ms].perSrc_icmp=atoi(websGetVar(wp,"Count_ICMP_1",""));

	rtl8651a_setDosThreshold(ms,RTL8651_DOS_SYN_THRESHOLD,pRomeCfgParam->dosCfgParam[ms].syn);
	rtl8651a_setDosThreshold(ms,RTL8651_DOS_FIN_THRESHOLD,pRomeCfgParam->dosCfgParam[ms].fin);
	rtl8651a_setDosThreshold(ms,RTL8651_DOS_UDP_THRESHOLD,pRomeCfgParam->dosCfgParam[ms].udp);
	rtl8651a_setDosThreshold(ms,RTL8651_DOS_ICMP_THRESHOLD,pRomeCfgParam->dosCfgParam[ms].icmp);

	rtl8651a_setPerSrcDosThreshold(ms, RTL8651_DOS_SYN_THRESHOLD, pRomeCfgParam->dosCfgParam[ms].perSrc_syn);
	rtl8651a_setPerSrcDosThreshold(ms, RTL8651_DOS_FIN_THRESHOLD, pRomeCfgParam->dosCfgParam[ms].perSrc_fin);
	rtl8651a_setPerSrcDosThreshold(ms, RTL8651_DOS_UDP_THRESHOLD, pRomeCfgParam->dosCfgParam[ms].perSrc_udp);
	rtl8651a_setPerSrcDosThreshold(ms, RTL8651_DOS_ICMP_THRESHOLD, pRomeCfgParam->dosCfgParam[ms].perSrc_icmp);

	/* connection count control */
	pRomeCfgParam->dosCfgParam[ms].tcpc=atoi(websGetVar(wp,"Count_TCP_Flow_0",""));
	pRomeCfgParam->dosCfgParam[ms].udpc=atoi(websGetVar(wp,"Count_UDP_Flow_0",""));
	pRomeCfgParam->dosCfgParam[ms].tcpudpc=atoi(websGetVar(wp,"Count_Both_0",""));

	pRomeCfgParam->dosCfgParam[ms].perSrc_tcpc=atoi(websGetVar(wp,"Count_TCP_Flow_1",""));
	pRomeCfgParam->dosCfgParam[ms].perSrc_udpc=atoi(websGetVar(wp,"Count_UDP_Flow_1",""));
	pRomeCfgParam->dosCfgParam[ms].perSrc_tcpudpc=atoi(websGetVar(wp,"Count_Both_1",""));
	{
		int i;
		for ( i = 0 ; i < RTL8651_MAX_DIALSESSION ; i ++)
		{
			if (i == ms)
				continue;
			pRomeCfgParam->dosCfgParam[i].tcpc=pRomeCfgParam->dosCfgParam[ms].tcpc;
			pRomeCfgParam->dosCfgParam[i].udpc=pRomeCfgParam->dosCfgParam[ms].udpc;
			pRomeCfgParam->dosCfgParam[i].tcpudpc=pRomeCfgParam->dosCfgParam[ms].tcpudpc;

			pRomeCfgParam->dosCfgParam[i].perSrc_tcpc=pRomeCfgParam->dosCfgParam[ms].perSrc_tcpc;
			pRomeCfgParam->dosCfgParam[i].perSrc_udpc=pRomeCfgParam->dosCfgParam[ms].perSrc_udpc;
			pRomeCfgParam->dosCfgParam[i].perSrc_tcpudpc=pRomeCfgParam->dosCfgParam[ms].perSrc_tcpudpc;
		}
	}
	/* we don't care "ms" (dsid) here */
	rtl8651a_setDosThreshold(0, RTL8651_DOS_TCPCONN_THRESHOLD, pRomeCfgParam->dosCfgParam[ms].tcpc);
	rtl8651a_setDosThreshold(0, RTL8651_DOS_UDPCONN_THRESHOLD, pRomeCfgParam->dosCfgParam[ms].udpc);
	rtl8651a_setDosThreshold(0, RTL8651_DOS_TCPUDPCONN_THRESHOLD, pRomeCfgParam->dosCfgParam[ms].tcpudpc);

	rtl8651a_setPerSrcDosThreshold(0, RTL8651_DOS_TCPCONN_THRESHOLD, pRomeCfgParam->dosCfgParam[ms].perSrc_tcpc);
	rtl8651a_setPerSrcDosThreshold(0, RTL8651_DOS_UDPCONN_THRESHOLD, pRomeCfgParam->dosCfgParam[ms].perSrc_udpc);
	rtl8651a_setPerSrcDosThreshold(0, RTL8651_DOS_TCPUDPCONN_THRESHOLD, pRomeCfgParam->dosCfgParam[ms].perSrc_tcpudpc);

	/* port scan */
	{
		uint32 threshold;

		pRomeCfgParam->dosCfgParam[ms].portScan_level=atoi(websGetVar(wp,"Level_TcpUdpPortScan",""));
		switch (pRomeCfgParam->dosCfgParam[ms].portScan_level)
		{
			case 0:
					threshold = DOS_PORTSCAN_LOW_VAL;
					break;
			case 1:
					threshold = DOS_PORTSCAN_HIGH_VAL;
					break;
			default:
					pRomeCfgParam->dosCfgParam[ms].portScan_level = 0;
					threshold = DOS_PORTSCAN_LOW_VAL;
		}
		rtl8651_dosScanTrackingSetPara(ms, RTL8651_DOS_SCAN_MOINTOR_WIN_DEFAULT, threshold);
	}

	/* ignore dos check if packet from internal vlan */
	{
		pRomeCfgParam->dosCfgParam[ms].ignoreLanSideCheck=atoi(websGetVar(wp, "ignore_lan",""));
		for(i=0;i<MAX_PPPOE_SESSION;i++)
		{
			if (i != ms)
				pRomeCfgParam->dosCfgParam[i].ignoreLanSideCheck = pRomeCfgParam->dosCfgParam[ms].ignoreLanSideCheck;
		}
		if (pRomeCfgParam->dosCfgParam[ms].ignoreLanSideCheck)
		{
			rtl8651_addDosIgnoreType(RTL8651_DOS_IGNORETYPE_FROM_LAN);
		}else
		{
			rtl8651_delDosIgnoreType(RTL8651_DOS_IGNORETYPE_FROM_LAN);
		}
	}

	rtl8651a_setDosStatus(ms, ((pRomeCfgParam->dosCfgParam[ms].enable)?(pRomeCfgParam->dosCfgParam[ms].enableItem):0));
	
	cfgmgr_write(CFGMGR_TABID_DOS,(void*)(pRomeCfgParam->dosCfgParam), sizeof(struct dosCfgParam_s)*MAX_PPPOE_SESSION);
	cfgmgr_task();
	sprintf(tmpstr,"/dos.asp?ms=%d",ms);
	websRedirect(wp,tmpstr);
}

int asp_dosProc(request * wp, int argc, char **argv)
{

	int ms=asp_multiSession(wp,argc,argv);
	
	if (strcmp(argv[0],"SIPBLOCK_ENABLE")==0)
 	{
 		if (pRomeCfgParam->dosCfgParam[ms].sipblock_enable ==1){ websWrite(wp,"checked");}
 	}
	else if(strcmp(argv[0],"MS")==0) {websWrite(wp,"%d",ms);}
	else if(strcmp(argv[0],"SIPBLOCK_PRISONTIME")==0)
		{websWrite(wp,"%d",pRomeCfgParam->dosCfgParam[ms].sipblock_PrisonTime);}
 	return 0;
}


void asp_setDosProc(request * wp,  char *path, char *query)
{
	char tmpstr[64];
	int32 idx;
	int ms=atoi(websGetVar(wp,"ms",""));

	/* Check if "Free All Blocked IP" button been clicked or not */
	if (strcmp(websGetVar(wp,"blockAllBlockedIp",""), "FreeALL") == 0)
	{
		rtl8651_dosProc_blockSip_freeAll();	// free all blocked IP
		goto redirect;
	}

	pRomeCfgParam->dosCfgParam[ms].sipblock_enable=atoi(websGetVar(wp,"sipblock_enable",""));

	if (pRomeCfgParam->dosCfgParam[ms].sipblock_enable == 1)
	{	// only modify parameters when source-ip block is enabled
		pRomeCfgParam->dosCfgParam[ms].sipblock_PrisonTime=atoi(websGetVar(wp,"sipblock_prisontime",""));
		for (idx = 0; idx < MAX_PPPOE_SESSION ; idx ++)
		{	// all session share the same Prison Time
			if (idx == ms) continue;
			pRomeCfgParam->dosCfgParam[idx].sipblock_PrisonTime = pRomeCfgParam->dosCfgParam[ms].sipblock_PrisonTime;
		}
		rtl8651_dosProc_blockSip_setPrisonTime(pRomeCfgParam->dosCfgParam[ms].sipblock_PrisonTime);
	}

	rtl8651_dosProc_blockSip_enable(ms, pRomeCfgParam->dosCfgParam[ms].sipblock_enable);

	cfgmgr_write(CFGMGR_TABID_DOS,(void*)(pRomeCfgParam->dosCfgParam), sizeof(struct dosCfgParam_s)*MAX_PPPOE_SESSION);
	cfgmgr_task();
redirect:
	sprintf(tmpstr,"/dos.asp?ms=%d",ms);
	websRedirect(wp,tmpstr);

}

/************************************************************
 *	
 *	ALG
 *	
 ************************************************************/
int asp_alg(request * wp, int argc, char **argv)
{

	int algargc = RTL8651_ALG_MAX_IDX, i;

	#define ALG_TYPE_CLIENT						1
	#define ALG_TYPE_CLIENT_SERVER				2	
	#define ALG_TYPE_CLIENT_SERVER_WITH_IP	3
	uint32 algtype[]={ALG_TYPE_CLIENT_SERVER_WITH_IP,ALG_TYPE_CLIENT_SERVER_WITH_IP,ALG_TYPE_CLIENT
	,ALG_TYPE_CLIENT_SERVER_WITH_IP,ALG_TYPE_CLIENT_SERVER_WITH_IP,ALG_TYPE_CLIENT_SERVER_WITH_IP
	,ALG_TYPE_CLIENT_SERVER_WITH_IP,ALG_TYPE_CLIENT_SERVER_WITH_IP,ALG_TYPE_CLIENT_SERVER
	,ALG_TYPE_CLIENT_SERVER,ALG_TYPE_CLIENT_SERVER,ALG_TYPE_CLIENT
	,ALG_TYPE_CLIENT,ALG_TYPE_CLIENT,ALG_TYPE_CLIENT_SERVER_WITH_IP
	,ALG_TYPE_CLIENT,ALG_TYPE_CLIENT,ALG_TYPE_CLIENT_SERVER_WITH_IP
	};	

	char *algstr[]={"PPTP","IPSec","L2TP","FTP","Net Meeting","DirectX 7","SIP","ICUII","ICQ / AOL Instant Messenger","Yahoo Messenger","mIRC","VDOlive","Quake","Counter Strike / Half Life","Blizzard Battlenet (StarCraft, DiabloII)","RealAudio","CUseeMe","TFTP"};
	char *algargv[]={"PPTP","IPSEC","L2TP","FTP","NETMEETING","DX7","SIP","ICUII","ICQ","YAHOOMSG","IRC","VDOLIVE","QUAKE","CS","BATTLENET","REALAUDIO","CUSEEME","TFTP"};

	uint32 algmask[]={RTL8651_ALG_PPTP,RTL8651_ALG_IPSEC,RTL8651_ALG_L2TP
	,RTL8651_ALG_FTP,RTL8651_ALG_NETMEETING,RTL8651_ALG_DX7
	,RTL8651_ALG_SIP,RTL8651_ALG_ICUII,RTL8651_ALG_ICQ
	,RTL8651_ALG_YAHOOMSG,RTL8651_ALG_IRC,RTL8651_ALG_VDOLIVE
	,RTL8651_ALG_QUAKE,RTL8651_ALG_CS,RTL8651_ALG_BATTLENET
	,RTL8651_ALG_REALAUDIO,RTL8651_ALG_CUSEEME,RTL8651_ALG_TFTP
	};

	uint32 algidx[]={RTL8651_ALG_PPTP_IDX,RTL8651_ALG_IPSEC_IDX,RTL8651_ALG_L2TP_IDX
	,RTL8651_ALG_FTP_IDX,RTL8651_ALG_NETMEETING_IDX,RTL8651_ALG_DX7_IDX
	,RTL8651_ALG_SIP_IDX,RTL8651_ALG_ICUII_IDX,RTL8651_ALG_ICQ_IDX
	,RTL8651_ALG_YAHOOMSG_IDX,RTL8651_ALG_IRC_IDX,RTL8651_ALG_VDOLIVE_IDX
	,RTL8651_ALG_QUAKE_IDX,RTL8651_ALG_CS_IDX,RTL8651_ALG_BATTLENET_IDX
	,RTL8651_ALG_REALAUDIO_IDX,RTL8651_ALG_CUSEEME_IDX,RTL8651_ALG_TFTP_IDX
	};	

	int ms = asp_multiSession(wp,argc,argv);


	if(strcmp(argv[0],"web")==0) 
	{		
		uint32 algc=pRomeCfgParam->algCfgParam[ms].algList;
		websWrite(wp,"<input type=hidden name=ms value=%d>\n",ms);
		for(i=0;i<algargc;i++)	
		{
			websWrite(wp,"<tr>\n" \
			"<td bgColor=#ddeeff>%s" ,algstr[i]);

			if(strcmp(algstr[i],"PPTP")==0)
			{
				uint8 checked=0;
				if((pRomeCfgParam->algCfgParam[0].algList&RTL8651_ALG_PPTP_SOFTWARE)!=0) checked=1;
				websWrite(wp," (Enable software solution <input type=checkbox name=pptpsoft value=1 %s>)",(checked)?"checked":"");
			}
			

			websWrite(wp,"</td>\n" \
			"<td bgColor=#ddeeff >\n" \
			"<input type=checkbox name=%s value=1 %s>Client",algargv[i],(algc&algmask[i])?"checked":"");

			if(algtype[i]==ALG_TYPE_CLIENT_SERVER)
				websWrite(wp,"/Server ");

			if(algtype[i]==ALG_TYPE_CLIENT_SERVER_WITH_IP)
				{
					websWrite(wp,"/Server(IP:\n" \
					"<input type=text name=%ssip size=15 maxlength=15 value=\"%u.%u.%u.%u\">)\n"
					,algargv[i],NIPQUAD(pRomeCfgParam->algCfgParam[ms].localIp[algidx[i]]));
				}

			websWrite(wp,"</td></tr>\n");
			
		}
	}
	return 0;
}

void asp_setAlg(request * wp, char *path, char *query)
{
	uint32 algc = 0;
	int algargc = RTL8651_ALG_MAX_IDX, i;
	char tmpstr[32];
	uint8 soft;

	char *algargv[]={"PPTP","IPSEC","L2TP","FTP","NETMEETING","DX7","SIP","ICUII","ICQ","YAHOOMSG","IRC","VDOLIVE","QUAKE","CS","BATTLENET","REALAUDIO","CUSEEME","TFTP"};

	uint32 algmask[]={RTL8651_ALG_PPTP,RTL8651_ALG_IPSEC,RTL8651_ALG_L2TP
	,RTL8651_ALG_FTP,RTL8651_ALG_NETMEETING,RTL8651_ALG_DX7
	,RTL8651_ALG_SIP,RTL8651_ALG_ICUII,RTL8651_ALG_ICQ
	,RTL8651_ALG_YAHOOMSG,RTL8651_ALG_IRC,RTL8651_ALG_VDOLIVE
	,RTL8651_ALG_QUAKE,RTL8651_ALG_CS,RTL8651_ALG_BATTLENET
	,RTL8651_ALG_REALAUDIO,RTL8651_ALG_CUSEEME,RTL8651_ALG_TFTP
	};

	uint32 algidx[]={RTL8651_ALG_PPTP_IDX,RTL8651_ALG_IPSEC_IDX,RTL8651_ALG_L2TP_IDX
	,RTL8651_ALG_FTP_IDX,RTL8651_ALG_NETMEETING_IDX,RTL8651_ALG_DX7_IDX
	,RTL8651_ALG_SIP_IDX,RTL8651_ALG_ICUII_IDX,RTL8651_ALG_ICQ_IDX
	,RTL8651_ALG_YAHOOMSG_IDX,RTL8651_ALG_IRC_IDX,RTL8651_ALG_VDOLIVE_IDX
	,RTL8651_ALG_QUAKE_IDX,RTL8651_ALG_CS_IDX,RTL8651_ALG_BATTLENET_IDX
	,RTL8651_ALG_REALAUDIO_IDX,RTL8651_ALG_CUSEEME_IDX,RTL8651_ALG_TFTP_IDX
	};	

	int ms = atoi(websGetVar(wp,"ms",""));

	for(i=0;i<algargc;i++)
	{
		sprintf(tmpstr,"%s",algargv[i]);
		algc|=(atoi(websGetVar(wp,tmpstr,""))==1)?algmask[i]:0;
	}
	

	for(i=0;i<algargc;i++)
	{
		ipaddr_t ip=0,ip2=0;
		sprintf(tmpstr,"%ssip",algargv[i]);
		parse_ipRange(websGetVar(wp,tmpstr,""), &ip, &ip2);
		pRomeCfgParam->algCfgParam[ms].localIp[algidx[i]]=ip;		
		if(algidx[i]==RTL8651_ALG_PPTP_IDX)
		{
			if(ip==0) algc&=(~RTL8651_ALG_PPTP_SERVER);
			else algc|=RTL8651_ALG_PPTP_SERVER;
		}
		if(algidx[i]==RTL8651_ALG_IPSEC_IDX)
		{
			if(ip==0) algc&=(~RTL8651_ALG_IPSEC_SERVER);
			else algc|=RTL8651_ALG_IPSEC_SERVER;
		}		
		//printf("%s ip=%u.%u.%u.%u\n",algargv[i],NIPQUAD(ip));
	}

	soft=atoi(websGetVar(wp,"pptpsoft",""));
		
	if(ms==0)
	{
		algc&=0x7fffffff;	
		if(soft==1) algc|=0x80000000;
	}

	pRomeCfgParam->algCfgParam[ms].algList=algc;

	rtl8651a_setAlgStatus(0,algc,pRomeCfgParam->algCfgParam[0].localIp);	
	rtl8651a_setAlgStatus(ms,algc,pRomeCfgParam->algCfgParam[ms].localIp);
	cfgmgr_write(CFGMGR_TABID_ALG,(void*)pRomeCfgParam->algCfgParam,sizeof(algCfgParam_t)*MAX_PPPOE_SESSION);
	cfgmgr_task();

	sprintf(tmpstr,"/alg.asp?ms=%d",ms);
	websRedirect(wp, tmpstr);
}
/* end rome_asp.c */



/************************************************************
 *	
 *	Wireless LAN Basic
 *	
 ************************************************************/

int asp_wlanBasic(request * wp, int argc, char **argv)
{
	char cmdBuf[80];
	int i;

	 #define IF_VAR_MATCH(cmp, fmt, args...) \
	 		memset(cmdBuf, 0, sizeof(cmdBuf)); \
			sprintf(cmdBuf, fmt, ## args); \
			if ((strlen(cmp) == strlen(cmdBuf)) && (strncmp(cmp, cmdBuf, strlen(cmp))) == 0)

	//No WLAN card probed
	if(strcmp(argv[0],"exist0")==0){
		websWrite(wp,"%d",totalWlanCards?1:0);
		return 0;
	}
	if(strcmp(argv[0],"exist1")==0){
		websWrite(wp,"%d",totalWlanCards>1?1:0);
		return 0;
	}

	/* read cfg from cfgmgr */

	if (cfgmgr_read(CFGMGR_TABID_WLAN,(void*)(pRomeCfgParam->wlanCfgParam), sizeof(struct wlanCfgParam_s)*MAX_WLAN_CARDS)!=0)
	{
		printf("asp_wlanBasic: call cfgmgr_read fail\n");
		/* take proper actions */
		return 1;
	}

#ifdef CONFIG_RTL8185
	for(i=0;i<MAX_WLAN_CARDS;i++){
		bss_info bss;
		memset(&bss,0,sizeof(bss_info));
		sprintf(cmdBuf, "wlan%d", i);
		if ((i<totalWlanCards)&& getWlBssInfo(cmdBuf, &bss) < 0) {
			printf("Get bssinfo failed!");
			free(pStatus);
			pStatus = NULL;
			return 0;
		}
		
		sprintf(cmdBuf, "name%d",i);
		if(strcmp(argv[0],cmdBuf)==0){
			if(i>=totalWlanCards)
				return 0;
			if(strlen(pRomeCfgParam->wlanCfgParam[i].aliasName))
				{websWrite(wp,"%s",pRomeCfgParam->wlanCfgParam[i].aliasName);}
			else
				{websWrite(wp,"(Untitled)");}
			return 0;
		}
		sprintf(cmdBuf,"dataRateMode%d",i);
		if(strcmp(argv[0],cmdBuf)==0){  
			websWrite(wp,"%d",pRomeCfgParam->wlanCfgParam[i].dataRateMode);
			break;
		}

		sprintf(cmdBuf,"dataRateMode%d_%d",i,pRomeCfgParam->wlanCfgParam[i].dataRateMode);
		if(strcmp(argv[0],cmdBuf)==0){  
			websWrite(wp,"selected");
			break;
		}
		
		sprintf(cmdBuf, "ssid%d",i);
		if(strcmp(argv[0],cmdBuf)==0){
			if(i>=totalWlanCards)
				return 0;
			websWrite(wp,"%s",pRomeCfgParam->wlanCfgParam[i].ssid);
			return 0;
		}
		sprintf(cmdBuf, "bssid%d",i);
		if(strcmp(argv[0],cmdBuf)==0){
			macaddr_t macStr;
			unsigned char *p=(unsigned char *)&macStr;
			if(i>=totalWlanCards)
				return 0;
			if(!bdinfo_getWlanMac((macaddr_t*)&macStr, i)){//get hardware MAC
				websWrite(wp,"%02X:%02X:%02X:%02X:%02X:%02X",p[0],p[1],p[2],p[3],p[4],p[5]);
			}
			return 0;
		}
		sprintf(cmdBuf, "enable%d",i);
		if(strcmp(argv[0],cmdBuf)==0){
			if(i>=totalWlanCards)
				{websWrite(wp,"");}
			else
				{websWrite(wp,"%s",pRomeCfgParam->wlanCfgParam[i].enable?"checked":"");}
			return 0;
		}
		sprintf(cmdBuf, "show%d", i);
		if(strcmp(argv[0],cmdBuf)==0)
		{
			if ( i >= totalWlanCards)
			{
				websWrite(wp,"disabled");
			}else
			{
				websWrite(wp,"%s",pRomeCfgParam->wlanCfgParam[i].enable?"":"disabled");
			}
			return 0;
		}		
		sprintf(cmdBuf, "active%d",i);
		if(strcmp(argv[0],cmdBuf)==0){
			if(i>=totalWlanCards)
				return 0;
			else if(totalWlanCards){
				websWrite(wp,"%s",pRomeCfgParam->wlanCfgParam[i].enable?"Enabled":"Not Enabled");
			}else
				websWrite(wp,"(Not installed)");
			return 0;
		}
		sprintf(cmdBuf,"regDomain%d",i);
		if(strcmp(argv[0],cmdBuf)==0){
			websWrite(wp,"%d",(int)pRomeCfgParam->wlanCfgParam[i].regDomain);
			return 0;
		}
		sprintf(cmdBuf,"channel%d",i);
		if(strcmp(argv[0],cmdBuf)==0){
			websWrite(wp,"%d",(int)pRomeCfgParam->wlanCfgParam[i].channel);
			return 0;
		}		
		sprintf(cmdBuf,"channelName%d",i);
		if(strcmp(argv[0],cmdBuf)==0){
			if(pRomeCfgParam->wlanCfgParam[i].channel==0)
				{websWrite(wp,"Auto");}
			else
				{websWrite(wp,"%d",(int)pRomeCfgParam->wlanCfgParam[i].channel);}
			return 0;
		}		

		sprintf(cmdBuf,"sum%d",i);
		if(strcmp(argv[0],cmdBuf)==0){
			char states[][16]={"Disabled", "Idled","Scanning","Started","Connected"};
			websWrite(wp, "%s, Channel %d, %d.%dMbps", states[bss.state],(int)bss.channel, bss.txRate>>1,bss.txRate&1);
			return 0;
		}		
		if(i<totalWlanCards){
			sprintf(cmdBuf,"ver%d_%d",i,pRomeCfgParam->wlanCfgParam[i].chipVer);
			if(strcmp(argv[0],cmdBuf)==0){
				websWrite(wp,"selected");
				return 0;
			}		
			sprintf(cmdBuf,"mode%d_%d",i,pRomeCfgParam->wlanCfgParam[i].mode);
			if(strcmp(argv[0],cmdBuf)==0){
				websWrite(wp,"selected");
				return 0;
			}
			sprintf(cmdBuf,"regDomain%d_%d",i,pRomeCfgParam->wlanCfgParam[i].regDomain);
			if(strcmp(argv[0],cmdBuf)==0){
				websWrite(wp,"selected");
				return 0;
			}		
		}
	}

	/* Global setting check */
	IF_VAR_MATCH(argv[0], "showEach")
	{
		int leastOneEntryEnable = FALSE;

		for ( i = 0 ; i < totalWlanCards ; i ++ )
		{
			if (pRomeCfgParam->wlanCfgParam[i].enable == TRUE)
			{
				leastOneEntryEnable = TRUE;
			}
		}
		websWrite(wp, (leastOneEntryEnable==TRUE)?"":"disabled");
		return 0;
	}

#endif
	return 0;
}


void asp_setWlanBasic(request * wp, char *path, char *query)
{
	char cmdBuf[80];
	int i;

	for(i=0;i<totalWlanCards;i++){
		sprintf(cmdBuf, "name%d",i);
		memcpy(pRomeCfgParam->wlanCfgParam[i].aliasName,websGetVar(wp,cmdBuf,""),strlen(websGetVar(wp,cmdBuf,""))+1);
		sprintf(cmdBuf, "mode%d",i);
		pRomeCfgParam->wlanCfgParam[i].mode=atoi(websGetVar(wp,cmdBuf,""));
		sprintf(cmdBuf, "enable%d",i);
		pRomeCfgParam->wlanCfgParam[i].enable=atoi(websGetVar(wp,cmdBuf,""));
		sprintf(cmdBuf, "ssid%d",i);
		memcpy(pRomeCfgParam->wlanCfgParam[i].ssid,websGetVar(wp,cmdBuf,""),strlen(websGetVar(wp,cmdBuf,""))+1);
		sprintf(cmdBuf, "channel%d",i);
		pRomeCfgParam->wlanCfgParam[i].channel=atoi(websGetVar(wp,cmdBuf,""));
		sprintf(cmdBuf, "version%d",i);
		pRomeCfgParam->wlanCfgParam[i].chipVer=atoi(websGetVar(wp,cmdBuf,""));
		sprintf(cmdBuf, "regDomain%d",i);
		pRomeCfgParam->wlanCfgParam[i].regDomain=atoi(websGetVar(wp,cmdBuf,""));
		sprintf(cmdBuf, "dataRateMode%d",i);
		pRomeCfgParam->wlanCfgParam[i].dataRateMode=
			atoi(websGetVar(wp,cmdBuf,""));
		
	}

	cfgmgr_write(CFGMGR_TABID_WLAN,(void*)pRomeCfgParam->wlanCfgParam,sizeof(wlanCfgParam_t)*MAX_WLAN_CARDS);

	cfgmgr_task();
	websRedirect(wp, "/wireless_basic.asp");
#ifdef CONFIG_RTL8185	
	wlan_setup(0);
#endif
}

/************************************************************
 *	
 *	Wireless LAN Advance
 *	
 ************************************************************/

int asp_wlanAdvance(request * wp, int argc, char **argv)
{
	char cmdBuf[80];
	int i;
	//No WLAN card probed
	if(totalWlanCards==0){
		if(strcmp(argv[0],"alias0")==0){
			websWrite(wp,"Not installed");
			return 0;
		}
		if(strcmp(argv[0],"alias1")==0){
			websWrite(wp,"Not installed");
			return 0;
		}
		return 0;
	}

	//Only one card probed, always disabled second one.
	if(totalWlanCards==1){
		if(strcmp(argv[0],"alias1")==0){
			websWrite(wp,"Not installed");
			return 0;
		}
	}	


		/* read cfg from cfgmgr */
	if (cfgmgr_read(CFGMGR_TABID_WLAN,(void*)pRomeCfgParam->wlanCfgParam, sizeof(struct wlanCfgParam_s)*MAX_WLAN_CARDS)!=0)
	{
		printf("asp_wlanAdvance: call cfgmgr_read fail\n");
		/* take proper actions */
		return 1;
	}

	for(i=0;i<totalWlanCards;i++){		
		
		sprintf(cmdBuf, "alias%d",i);
		if(strcmp(argv[0],cmdBuf)==0){  
			websWrite(wp,"%s",pRomeCfgParam->wlanCfgParam[i].aliasName);
			break;
		}
		sprintf(cmdBuf, "frag%d",i);
		if(strcmp(argv[0],cmdBuf)==0){  
			websWrite(wp,"%d",pRomeCfgParam->wlanCfgParam[i].frag);
			break;
		}
		sprintf(cmdBuf, "rts%d",i);
		if(strcmp(argv[0],cmdBuf)==0){
			websWrite(wp,"%d",pRomeCfgParam->wlanCfgParam[i].rts);
			break;
		}
		sprintf(cmdBuf, "beacon%d",i);
		if(strcmp(argv[0],cmdBuf)==0){
			websWrite(wp,"%d",pRomeCfgParam->wlanCfgParam[i].beacon);
			break;
		}
		sprintf(cmdBuf, "dualAntenna%d",i);
		if(strcmp(argv[0],cmdBuf)==0){
			websWrite(wp,"%d",pRomeCfgParam->wlanCfgParam[i].dualAntenna);
			break;
		}

		sprintf(cmdBuf,"rxChargePump%d_%d",i,pRomeCfgParam->wlanCfgParam[i].rxChargePump);
		if(strcmp(argv[0],cmdBuf)==0){  
			websWrite(wp,"selected");
			break;
		}
		sprintf(cmdBuf,"txChargePump%d_%d",i,pRomeCfgParam->wlanCfgParam[i].txChargePump);
		if(strcmp(argv[0],cmdBuf)==0){  
			websWrite(wp,"selected");
			break;
		}
		sprintf(cmdBuf,"dataRate%d_%d",i,pRomeCfgParam->wlanCfgParam[i].dataRate);
		if(strcmp(argv[0],cmdBuf)==0){
			websWrite(wp,"selected");
			break;
		}
		sprintf(cmdBuf,"preamble%d_%d",i,pRomeCfgParam->wlanCfgParam[i].preambleType);
		if(strcmp(argv[0],cmdBuf)==0){  
			websWrite(wp,"checked");	
			break;
		}
		sprintf(cmdBuf,"range%d_%d",i,pRomeCfgParam->wlanCfgParam[i].range);
		if(strcmp(argv[0],cmdBuf)==0){  
			websWrite(wp,"selected");	
			break;
		}		
		sprintf(cmdBuf,"broadcastSSID%d",i);
		if(strcmp(argv[0],cmdBuf)==0){
			websWrite(wp,"%s",pRomeCfgParam->wlanCfgParam[i].broadcastSSID?"checked":"");
			break;
		}
		sprintf(cmdBuf,"protection%d",i);
		if(strcmp(argv[0],cmdBuf)==0){
			websWrite(wp,"%s",pRomeCfgParam->wlanCfgParam[i].protection?"checked":"");
			break;
		}
	}
	return 0;

}	
void asp_setWlanAdvance(request * wp, char *path, char *query)
{
	uint16 i,basicRateSet[13]={0,4095,2047,1023,511,255,127,63,31,15,7,3,1};
	uint16 opRateSet[13]={0/*Auto*/,4095,2047,1023,511,255,127,63,31,15,7,3,1};
	int x, dualAntenna=0;
	char cmdBuf[40]={0};
	for(i=0;i<totalWlanCards;i++){

		sprintf(cmdBuf, "rxChargePump%d",i);
		pRomeCfgParam->wlanCfgParam[i].rxChargePump=
			atoi(websGetVar(wp,cmdBuf,""));

		sprintf(cmdBuf, "txChargePump%d",i);
		pRomeCfgParam->wlanCfgParam[i].txChargePump=
			atoi(websGetVar(wp,cmdBuf,""));

		sprintf(cmdBuf, "preamble%d",i);
		pRomeCfgParam->wlanCfgParam[i].preambleType=
			atoi(websGetVar(wp,cmdBuf,""));
		sprintf(cmdBuf, "dualAntenna%d",i);
		pRomeCfgParam->wlanCfgParam[i].dualAntenna=
			atoi(websGetVar(wp,cmdBuf,""));


		sprintf(cmdBuf, "dataRate%d",i);
		pRomeCfgParam->wlanCfgParam[i].dataRate=
			atoi(websGetVar(wp,cmdBuf,""));

		sprintf(cmdBuf, "preamble%d",i);
		pRomeCfgParam->wlanCfgParam[i].preambleType=
			atoi(websGetVar(wp,cmdBuf,""));

		sprintf(cmdBuf, "broadcastSSID%d",i);
		pRomeCfgParam->wlanCfgParam[i].broadcastSSID=
			atoi(websGetVar(wp,cmdBuf,""));

		sprintf(cmdBuf, "protection%d",i);
		pRomeCfgParam->wlanCfgParam[i].protection=
			atoi(websGetVar(wp,cmdBuf,""));	

		sprintf(cmdBuf, "frag%d",i);
		pRomeCfgParam->wlanCfgParam[i].frag=
			(uint32)atoi(websGetVar(wp,cmdBuf,""));

		if(pRomeCfgParam->wlanCfgParam[i].frag>2346)
			pRomeCfgParam->wlanCfgParam[i].frag=2346;
		else if(pRomeCfgParam->wlanCfgParam[i].frag<256)
			pRomeCfgParam->wlanCfgParam[i].frag=256;

		sprintf(cmdBuf, "rts%d",i);
		pRomeCfgParam->wlanCfgParam[i].rts=
			(uint32)atoi(websGetVar(wp,cmdBuf,""));
		if(pRomeCfgParam->wlanCfgParam[i].rts>2347)
			pRomeCfgParam->wlanCfgParam[i].rts=2347;

		sprintf(cmdBuf, "beacon%d",i);
		pRomeCfgParam->wlanCfgParam[i].beacon=
			(uint32)atoi(websGetVar(wp,cmdBuf,""));
		if(pRomeCfgParam->wlanCfgParam[i].beacon<20)
			pRomeCfgParam->wlanCfgParam[i].beacon=20;			
		else if(pRomeCfgParam->wlanCfgParam[i].beacon>1024)
			pRomeCfgParam->wlanCfgParam[i].beacon=1024;

		sprintf(cmdBuf, "range%d",i);
		pRomeCfgParam->wlanCfgParam[i].range=
			(uint32)atoi(websGetVar(wp,cmdBuf,""));
	
	}
	cfgmgr_write(CFGMGR_TABID_WLAN,(void*)pRomeCfgParam->wlanCfgParam,sizeof(wlanCfgParam_t)*MAX_WLAN_CARDS);
	cfgmgr_task();
#ifdef CONFIG_RTL8185
	wlan_setup(0);
#endif
	websRedirect(wp, "/wireless_advance.asp");	
}	

/************************************************************
 *	
 *	Wireless LAN Security
 *	
 ************************************************************/
int asp_wlanSecurity(request * wp, int argc, char **argv)
{
	char cmdBuf[40];
	int32 i, crypt = 0, cryptSub = 0, auth = 0;

	/*
		in wireless_security.asp:

			<option value=0>No encryption</option>
			<option value=1>WEP</option>
			<option value=2>WPA</option>
			<option value=3>WPA2</option>
			<option value=4>WPA - AUTO</option>
	*/
	int32 cryptValue[CRYPT_MAX] = {
			CRYPT_NONE,
			CRYPT_WEP,
			CRYPT_WPA,
			CRYPT_WPA2,
			CRYPT_WPAMIX
	};

	/*
		in wireless_security.asp:

			wep_sub[0]='64 bits';
			wep_sub[1]='128 bits';
	*/
	#define MAX_WEP_ITEM					2
	int32 cryptSubValue_wep[MAX_WEP_ITEM] = {
		CRYPT_SUB_WEP_64,
		CRYPT_SUB_WEP_128
	};

	/*
		in wireless_security.asp:

			wpa_sub[0]='TKIP';
			wpa_sub[1]='AES';
			wpa_sub[2]='BOTH';
	*/
	#define MAX_WPA_ITEM					3
	int32 cryptSubValue_wpa[MAX_WPA_ITEM] = {
		CRYPT_SUB_WPA_TKIP,
		CRYPT_SUB_WPA_AES,
		CRYPT_SUB_WPA_TKIPAES
	};

	/*
		in wireless_security.asp:

			wpa_mix_sub[0]='WPA1(TKIP) WPA2(TKIP)';
			wpa_mix_sub[1]='WPA1(TKIP) WPA2(AES)';
			wpa_mix_sub[2]='WPA1(AES) WPA2(TKIP)';
			wpa_mix_sub[3]='WPA1(AES) WPA2(AES)';
			wpa_mix_sub[4]='WPA1(BOTH) WPA2(BOTH)';
	*/
	#define MAX_WPA_MIX_ITEM					5
	#define MAX_WPA_MIX_ITEM_COMBINE_CNT	2
	int32 cryptSubValue_wpaMix[MAX_WPA_MIX_ITEM][MAX_WPA_MIX_ITEM_COMBINE_CNT] = {
		{CRYPT_SUB_WPA_TKIP, CRYPT_SUB_WPA_TKIP},
		{CRYPT_SUB_WPA_TKIP, CRYPT_SUB_WPA_AES},
		{CRYPT_SUB_WPA_AES, CRYPT_SUB_WPA_TKIP},
		{CRYPT_SUB_WPA_AES, CRYPT_SUB_WPA_AES},
		{CRYPT_SUB_WPA_TKIPAES, CRYPT_SUB_WPA_TKIPAES}
	};

	int16 authType[CRYPT_MAX/*encryption selection*/][AUTH_MAX/*auth selection*/] = {
		/*No encrypt*/	{	AUTH_NONE	,AUTH_8021x	,-1			,-1			},
		/*WEP*/			{	AUTH_NONE	,AUTH_KEY	,AUTH_AUTO	,AUTH_8021x	},
		/*WPA*/			{	AUTH_KEY	,AUTH_8021x	,-1			,-1			},
		/*WPA2*/		{	AUTH_KEY	,AUTH_8021x	,-1			,-1			},
		/*WPA-MIX*/		{	AUTH_KEY	,AUTH_8021x	,-1			,-1			}
	};

	 #define IF_VAR_MATCH(cmp, fmt, args...) \
	 		memset(cmdBuf, 0, sizeof(cmdBuf)); \
			sprintf(cmdBuf, fmt, ## args); \
			if ((strlen(cmp) == strlen(cmdBuf)) && (strncmp(cmp, cmdBuf, strlen(cmp))) == 0)



	switch ( totalWlanCards )
	{
		case 0:	/* No Any WLAN card probed */
			if (	(strcmp(argv[0], "alias0") == 0) ||
				(strcmp(argv[0], "alias1") == 0))
			{
				websWrite(wp, "Not installed");
			}
			return 0;
		case 1:	/* Only WLAN 0 probed */
			if (strcmp(argv[0], "alias1") == 0)
			{
				websWrite(wp, "Not installed");
				return 0;
			}
			break;
	}

	/* get WLAN configuration */
	if (cfgmgr_read(	CFGMGR_TABID_WLAN,
					(void*)(pRomeCfgParam->wlanCfgParam),
					sizeof(struct wlanCfgParam_s)*MAX_WLAN_CARDS)
					!= 0
	)
	{
		printf("asp_wlanSecurity: call cfgmgr_read fail\n");
		/* take proper actions */
		return 1;
	}
	
	for ( i = 0 ; i < totalWlanCards ; i++ )
	{
		/* alias name */
		IF_VAR_MATCH(argv[0], "alias%d", i)
		{
			websWrite(wp, "%s", pRomeCfgParam->wlanCfgParam[i].aliasName);
			break;
		}

		/* cryption type */
		IF_VAR_MATCH(argv[0], "cryptType%d", i)
		{
			int idx;
			for ( idx = 0 ; idx < CRYPT_MAX ; idx ++ )
			{
				if (cryptValue[idx] == pRomeCfgParam->wlanCfgParam[i].cryptType)
				{
					crypt = idx;
					break;
				}
			}
			if (idx == CRYPT_MAX)
			{
				printf("FATAL: unknown ENCRYPTION TYPE: %d\n", pRomeCfgParam->wlanCfgParam[i].cryptType);
				crypt = 0;
			}

			websWrite(wp,"%d", crypt);
			break;
		}

		/* cryption sub type */
		IF_VAR_MATCH(argv[0], "cryptSubType%d", i)
		{
			int idx, sub_idx, itemCnt = 0;
			int32 *tbl = NULL;

			switch (pRomeCfgParam->wlanCfgParam[i].cryptType)
			{
				case CRYPT_NONE:
					cryptSub = CRYPT_SUB_NONE;
					break;
				case CRYPT_WEP:

					tbl = cryptSubValue_wep;
					itemCnt = MAX_WEP_ITEM;

					/* Fall through */
				case CRYPT_WPA:
				case CRYPT_WPA2:

					if (tbl == NULL)
					{
						tbl = cryptSubValue_wpa;
						itemCnt = MAX_WPA_ITEM;
					}

					for ( idx = 0 ; idx < itemCnt ; idx ++ )
					{
						if (tbl[idx] == pRomeCfgParam->wlanCfgParam[i].cryptSubType[0])
						{
							cryptSub = idx;
							break;
						}
					}
					if (idx == itemCnt)
					{
						printf("FATAL: unknown ENCRYPTION SUBTYPE: %d\n", pRomeCfgParam->wlanCfgParam[i].cryptSubType[0]);
						cryptSub = 0;
					}
					break;
				case CRYPT_WPAMIX:
					for ( idx = 0 ; idx < MAX_WPA_MIX_ITEM ; idx ++ )
					{
						for ( sub_idx = 0 ; sub_idx < MAX_WPA_MIX_ITEM_COMBINE_CNT ; sub_idx ++ )
						{
							if (pRomeCfgParam->wlanCfgParam[i].cryptSubType[sub_idx] != cryptSubValue_wpaMix[idx][sub_idx])
								break;
						}
						if (sub_idx == MAX_WPA_MIX_ITEM_COMBINE_CNT)
						{	/* all items are the same */
							cryptSub = idx;
							break;
						}
					}
					if (idx == MAX_WPA_MIX_ITEM)
					{
						printf("FATAL: unknown ENCRYPTION SUBTYPE: %d\n", pRomeCfgParam->wlanCfgParam[i].cryptSubType[0]);
						cryptSub = 0;
					}
					break;
			}

			websWrite(wp, "%d", cryptSub);
			break;
		}

		/* authentication type */
		IF_VAR_MATCH(argv[0], "authType%d", i)
		{
			int idx;

			/* before get AUTH type, we need to get ENCRYPTION type first */
			for ( idx = 0 ; idx < CRYPT_MAX ; idx ++ )
			{
				if (cryptValue[idx] == pRomeCfgParam->wlanCfgParam[i].cryptType)
				{
					crypt = idx;
					break;
				}
			}
			if (idx == CRYPT_MAX)
			{
				printf("FATAL: unknown ENCRYPTION TYPE: %d\n", pRomeCfgParam->wlanCfgParam[i].cryptType);
				crypt = 0;
			}

			/* get AUTH type */
			for ( idx = 0 ; idx < AUTH_MAX ; idx ++ )
			{
				if (authType[crypt][idx] == pRomeCfgParam->wlanCfgParam[i].authType)
				{
					auth = idx;
					break;
				}
			}
			if (idx == AUTH_MAX)
			{
				printf("FATAL: unknown AUTHENTICATION TYPE: %d\n", pRomeCfgParam->wlanCfgParam[i].authType);
				auth = 0;
			}

			websWrite(wp,"%d",auth);
			break;
		}

		/* Key of WEP/WPA */
		IF_VAR_MATCH(argv[0], "key%d", i)
		{
			if (pRomeCfgParam->wlanCfgParam[i].cryptType)
			{
				websWrite(wp,"%s",pRomeCfgParam->wlanCfgParam[i].key);
			}
			break;
		}

		IF_VAR_MATCH(argv[0], "keyType%d", i)
		{
			if (pRomeCfgParam->wlanCfgParam[i].cryptType)
			{
				int32 keyLen = strlen(pRomeCfgParam->wlanCfgParam[i].key);

				if ( keyLen<=0 )
				{
					websWrite(wp,"(Empty)");
				}else
				{
					uint32 keyCorrection = TRUE;
					if (	wlan_chkKey(	pRomeCfgParam->wlanCfgParam[i].key,
										pRomeCfgParam->wlanCfgParam[i].cryptType,
										&(pRomeCfgParam->wlanCfgParam[i].cryptSubType)) < 0)
					{
						keyCorrection = FALSE;
					}
					switch (pRomeCfgParam->wlanCfgParam[i].cryptType)
					{
						/*
							For WEP
						*/
						case CRYPT_WEP:

							switch (pRomeCfgParam->wlanCfgParam[i].cryptSubType[0])
							{
								case CRYPT_SUB_WEP_64:
									websWrite (	wp,
												(keyCorrection==TRUE)?
													"Key accepted(10 hex digits)":
													"<font color=red>Key is invalid. Should be 10 hex digits</font>");
									break;
								case CRYPT_SUB_WEP_128:
									websWrite (	wp,
												(keyCorrection==TRUE)?
													"Key accepted(26 hex digits)":
													"<font color=red>Key is invalid. Should be 26 hex digits</font>");
									break;
								default:
									printf("FATAL: Un-match CYRPT type , sub type: %d : %d\n",
											pRomeCfgParam->wlanCfgParam[i].cryptType,
											pRomeCfgParam->wlanCfgParam[i].cryptSubType);
									break;
							}
							break;
						/*
							For WPA
						*/
						case CRYPT_WPA:
						case CRYPT_WPA2:
						case CRYPT_WPAMIX:
							websWrite (	wp,
										(keyCorrection==TRUE)?
											((keyLen == 64)?"Key accepted(64 hex digits)":"Passphrase accepted"):
											"<font color=red>Key is invalid(%d digits). Should be 64 hex digits or 8~63 char passphrase</font>");
							break;
					}
				}
			}
			break;
		}

		/* Radius setting of WEP/WPA */
		IF_VAR_MATCH(argv[0], "port%d", i)
		{
			websWrite(wp, "%d", pRomeCfgParam->wlanCfgParam[i].authRadiusPort);
			break;
		}

		IF_VAR_MATCH(argv[0], "ipaddr%d", i)
		{
			websWrite(wp,"%u.%u.%u.%u", NIPQUAD(pRomeCfgParam->wlanCfgParam[i].authRadiusIp));
			break;
		}

		IF_VAR_MATCH(argv[0], "passwd%d", i)
		{
			websWrite(wp, "%s", pRomeCfgParam->wlanCfgParam[i].authRadiusPasswd);
			break;
		}
	}

	if ( i == totalWlanCards )
	{
		IF_VAR_MATCH(argv[0], "cryptType%d", i)
		{
			websWrite(wp, "0");
			return 0;
		}

		IF_VAR_MATCH(argv[0], "cryptSubType%d", i)
		{
			websWrite(wp, "0");
			return 0;
		}

		IF_VAR_MATCH(argv[0], "authType%d", i)
		{
			websWrite(wp, "0");
			return 0;
		}
	}

	return 0;
}	

void asp_setWlanSecurity(request * wp, char *path, char *query)
{
	char cmdBuf[64]={0};
    	uint32 tempip, i, j;

	/*
		in wireless_security.asp:

			<option value=0>No encryption</option>
			<option value=1>WEP</option>
			<option value=2>WPA</option>
			<option value=3>WPA2</option>
			<option value=4>WPA - AUTO</option>
	*/
	int32 cryptValue[CRYPT_MAX] = {
			CRYPT_NONE,
			CRYPT_WEP,
			CRYPT_WPA,
			CRYPT_WPA2,
			CRYPT_WPAMIX
	};

	/*
		in wireless_security.asp:

			wep_sub[0]='64 bits';
			wep_sub[1]='128 bits';
	*/
	#define MAX_WEP_ITEM					2
	int32 cryptSubValue_wep[MAX_WEP_ITEM] = {
		CRYPT_SUB_WEP_64,
		CRYPT_SUB_WEP_128
	};

	/*
		in wireless_security.asp:

			wpa_sub[0]='TKIP';
			wpa_sub[1]='AES';
			wpa_sub[2]='BOTH';
	*/
	#define MAX_WPA_ITEM					3
	int32 cryptSubValue_wpa[MAX_WPA_ITEM] = {
		CRYPT_SUB_WPA_TKIP,
		CRYPT_SUB_WPA_AES,
		CRYPT_SUB_WPA_TKIPAES
	};

	/*
		in wireless_security.asp:

			wpa_mix_sub[0]='WPA1(TKIP) WPA2(TKIP)';
			wpa_mix_sub[1]='WPA1(TKIP) WPA2(AES)';
			wpa_mix_sub[2]='WPA1(AES) WPA2(TKIP)';
			wpa_mix_sub[3]='WPA1(AES) WPA2(AES)';
			wpa_mix_sub[4]='WPA1(BOTH) WPA2(BOTH)';
	*/
	#define MAX_WPA_MIX_ITEM					5
	#define MAX_WPA_MIX_ITEM_COMBINE_CNT	2
	int32 cryptSubValue_wpaMix[MAX_WPA_MIX_ITEM][MAX_WPA_MIX_ITEM_COMBINE_CNT] = {
		{CRYPT_SUB_WPA_TKIP, CRYPT_SUB_WPA_TKIP},
		{CRYPT_SUB_WPA_TKIP, CRYPT_SUB_WPA_AES},
		{CRYPT_SUB_WPA_AES, CRYPT_SUB_WPA_TKIP},
		{CRYPT_SUB_WPA_AES, CRYPT_SUB_WPA_AES},
		{CRYPT_SUB_WPA_TKIPAES, CRYPT_SUB_WPA_TKIPAES}
	};

	int16 authType[CRYPT_MAX/*encryption selection*/][AUTH_MAX/*auth selection*/] = {
		/*No encrypt*/	{	AUTH_NONE	,AUTH_8021x	,-1			,-1			},
		/*WEP*/			{	AUTH_NONE	,AUTH_KEY	,AUTH_AUTO	,AUTH_8021x	},
		/*WPA*/			{	AUTH_KEY	,AUTH_8021x	,-1			,-1			},
		/*WPA2*/		{	AUTH_KEY	,AUTH_8021x	,-1			,-1			},
		/*WPA-MIX*/		{	AUTH_KEY	,AUTH_8021x	,-1			,-1			}
	};

	for ( i = 0 ; i < totalWlanCards ; i++ )
	{
		int8 KEY[65] = {0};
		int32 keyOK;
		int32 tmpInt32, crypt, cryptSub[MAX_WLAN_CRYPT_MIX_TYPE] = {CRYPT_SUB_NONE}, auth;

		/* get encryption type */
		sprintf(cmdBuf, "cryptType%d", i);
		crypt = atoi(websGetVar(wp, cmdBuf, ""));
		if (crypt >= CRYPT_MAX)
		{
			printf("** ERROR : Invalid ENCRYPTION TYPE: %d\n", crypt);
			return;
		}

		{
			int32 cryptSubIdxFromHTML, itemCnt = 0;
			int32 *tbl = NULL;

			sprintf(cmdBuf, "cryptSubType%d", i);
			cryptSubIdxFromHTML = atoi(websGetVar(wp, cmdBuf, ""));

			switch ( crypt )
			{
				case CRYPT_NONE:
					/* use default value : all of them are CRYPT_SUB_NONE */
					break;
				case CRYPT_WEP:

					tbl = cryptSubValue_wep;
					itemCnt = MAX_WEP_ITEM;
					/* fall through */

				case CRYPT_WPA:
				case CRYPT_WPA2:
					if (tbl == NULL)
					{
						tbl = cryptSubValue_wpa;
						itemCnt = MAX_WPA_ITEM;
					}

					if (cryptSubIdxFromHTML >= itemCnt)
					{
						printf("** ERROR : Invalid ENCRYPTION IDX: %d (cryption type %d)\n", cryptSubIdxFromHTML, crypt);
						return;
					}

					for ( j = 0 ; j < MAX_WLAN_CRYPT_MIX_TYPE ; j ++ )
					{
						cryptSub[j] = tbl[cryptSubIdxFromHTML];
					}
					break;

				case CRYPT_WPAMIX:
					
					if (cryptSubIdxFromHTML >= MAX_WPA_MIX_ITEM)
					{
						printf("** ERROR : Invalid ENCRYPTION IDX: %d (cryption type %d)\n", cryptSubIdxFromHTML, crypt);
						return;
					}

					for ( j = 0 ; j < MAX_WPA_MIX_ITEM_COMBINE_CNT ; j ++ )
					{
						cryptSub[j] = cryptSubValue_wpaMix[cryptSubIdxFromHTML][j];
					}
					break;

				default:
					assert(0);
					return;
			}
		}

		for ( j = 0 ; j < MAX_WLAN_CRYPT_MIX_TYPE ; j ++ )
		{
			if (cryptSub[j] >= CRYPT_SUB_MAX)
			{
				printf("** ERROR : Invalid ENCRYPTION SUB TYPE: %d\n", cryptSub[j]);
				return;
			}
		}

		sprintf(cmdBuf, "authType%d", i);
		auth = atoi(websGetVar(wp,cmdBuf,""));
		if (	(auth >= AUTH_MAX) ||
			(authType[crypt][auth] < 0)	/* invalid entry*/)
		{
			printf("** ERROR : Invalid AUTHENTICATION TYPE: %d (encryption type: %d, sub type: %d)\n", auth, crypt, cryptSub);
			return;
		}

		/* Varify the configuration of AUTH/ CRYPT/ CRYPT-SUB */

		for ( j = 0 ; j < MAX_WLAN_CRYPT_MIX_TYPE ; j ++ )
		{
			switch (crypt)
			{
				case CRYPT_NONE:
				{	/* we don't check sub-type, just clear them */
					cryptSub[j] = CRYPT_SUB_NONE;
					break;
				}

				case CRYPT_WEP:
				{
					/* WEP has no any MIX mode, so we just clear cryptSub[j] if j > 0 */
					if ( j > 0 )
					{
						cryptSub[j] = CRYPT_SUB_NONE;
						break;
					}

					switch (cryptSub[j])
					{
						case CRYPT_SUB_WEP_64:
						case CRYPT_SUB_WEP_128:
							/* valid */
							break;
						default:
							printf("** ERROR : Invalid crypt type / sub-type pair (%d , %d)\n", crypt, cryptSub[j]);
							return;
					}
					break;
				}

				case CRYPT_WPA:
				case CRYPT_WPA2:
				{
					if ( j > 0 )
					{
						cryptSub[j] = CRYPT_SUB_NONE;
						break;
					}
				}
				/* Fall through */
				case CRYPT_WPAMIX:
				{
					switch (cryptSub[j])
					{
						case CRYPT_SUB_WPA_AES:
						case CRYPT_SUB_WPA_TKIP:
						case CRYPT_SUB_WPA_TKIPAES:
							/* valid */
							break;
						default:
							printf("** ERROR : Invalid crypt type / sub-type pair (%d , %d)\n", crypt, cryptSub[j]);
					}
					break;
				}
				default:
					printf("** ERROR : Unknown cryption type: %d\n", crypt);
			}
		}

		/* ========================= Store configuration auth/crypt/cryptSub ========================= */

		pRomeCfgParam->wlanCfgParam[i].cryptType = cryptValue[crypt];
		pRomeCfgParam->wlanCfgParam[i].authType = authType[crypt][auth];

		for ( j = 0 ; j < MAX_WLAN_CRYPT_MIX_TYPE ; j ++ )
		{
			pRomeCfgParam->wlanCfgParam[i].cryptSubType[j] = cryptSub[j];
		}

		printf("\n================================================\n");
		printf("\tCrypt:\t\t%d\n",
				pRomeCfgParam->wlanCfgParam[i].cryptType);
		for ( j = 0 ; j < MAX_WLAN_CRYPT_MIX_TYPE ; j ++ )
		{
			printf("\tCrypt SubType:\t%d\n",
					pRomeCfgParam->wlanCfgParam[i].cryptSubType[j]);
		}
		printf("\tAuth:\t\t%d\n\n",
				pRomeCfgParam->wlanCfgParam[i].authType);

		/* ========================================================================================== */

		/* Get AUTH TYPE */
		switch (pRomeCfgParam->wlanCfgParam[i].authType)
		{
			case AUTH_NONE:
				if (pRomeCfgParam->wlanCfgParam[i].cryptType == CRYPT_NONE)
				{
					/* do nothing */
					break;
				}
				/* KEY FOR ENCRYPTION */
			case AUTH_AUTO:
			case AUTH_KEY:
			{
				/* check and store KEY information */
				sprintf (cmdBuf, "key%d", i);
				memcpy (	KEY,
							websGetVar(wp,cmdBuf,""),
							strlen(websGetVar(wp,cmdBuf,""))+1);

				keyOK = wlan_chkKey(	KEY,
										pRomeCfgParam->wlanCfgParam[i].cryptType,
										&(pRomeCfgParam->wlanCfgParam[i].cryptSubType));

				if (keyOK < 0)
				{
					printf("\tKEY check:\tFAILED\n");
				}
				strcpy(pRomeCfgParam->wlanCfgParam[i].key, KEY);
				printf("\tKEY:\t\t[%s]\n", pRomeCfgParam->wlanCfgParam[i].key);
				printf("\tKEY Length:\t%d\n", strlen(pRomeCfgParam->wlanCfgParam[i].key));
				break;
			}
			case AUTH_8021x:
			{
				uint16 radiusPort;
				uint32 radiusIp;
				uint8 passwd[16];

				/* store RADIUS information */
				sprintf (cmdBuf, "port%d", i);
				radiusPort = atoi(websGetVar(wp,cmdBuf,""));

				sprintf (cmdBuf, "ipaddr%d", i);
				parse_ipRange(websGetVar(wp,cmdBuf,""), &radiusIp, &tempip);

				sprintf (cmdBuf, "passwd%d", i);
				memset(passwd, 0, sizeof(passwd));
				memcpy(	passwd,
							websGetVar(wp,cmdBuf,""),
							MIN(strlen(websGetVar(wp,cmdBuf,""))+1, (sizeof(passwd)-1)));

				pRomeCfgParam->wlanCfgParam[i].authRadiusPort = radiusPort;
				pRomeCfgParam->wlanCfgParam[i].authRadiusIp = radiusIp;
				strncpy(		pRomeCfgParam->wlanCfgParam[i].authRadiusPasswd,
							passwd,
							MIN(strlen(passwd), sizeof(pRomeCfgParam->wlanCfgParam[i].authRadiusPasswd)));

				printf("\tRADIUS:\n\t\tPort:\t\t%d\n\t\tIP Addr:\t%u.%u.%u.%u\n\t\tPWD:\t\t(%s)\n",
					pRomeCfgParam->wlanCfgParam[i].authRadiusPort,
					NIPQUAD(pRomeCfgParam->wlanCfgParam[i].authRadiusIp),
					pRomeCfgParam->wlanCfgParam[i].authRadiusPasswd);
				break;
			}
		}
		printf("\n================================================\n");
	}

	cfgmgr_write(	CFGMGR_TABID_WLAN,
					(void*)pRomeCfgParam->wlanCfgParam,
					sizeof(wlanCfgParam_t)*MAX_WLAN_CARDS);

	cfgmgr_task();
#ifdef CONFIG_RTL8185	
	wlan_setup(0);	
#endif
	websRedirect(wp, "/wireless_security.asp");	
}	

/************************************************************
 *	
 *	Wireless LAN Access Control
 *	
 ************************************************************/

int asp_wlanAccessCtrl(request * wp, int argc, char **argv)
{
	int i,j;
	char cmdBuf[40];
	/* read cfg from cfgmgr */

	if (cfgmgr_read(CFGMGR_TABID_WLAN,(void*)&(pRomeCfgParam->wlanCfgParam), sizeof(struct wlanCfgParam_s)*MAX_WLAN_CARDS)!=0)
	{
		printf("asp_wlanAccessCtrl: call cfgmgr_read fail\n");
		/* take proper actions */
		return 1;
	}
	
	for(i=0;i<totalWlanCards;i++){		
		sprintf(cmdBuf, "alias%d",i); 
		if(strcmp(argv[0],cmdBuf)==0){
			if(pRomeCfgParam->wlanCfgParam[i].aliasName[0]='\0')
				{websWrite(wp,"Untitled");}
			else
				{websWrite(wp,"%s",pRomeCfgParam->wlanCfgParam[i].aliasName);}
			break;
		}
		sprintf(cmdBuf, "enable%d_%d",i,pRomeCfgParam->wlanCfgParam[i].acEnable);
		if(strcmp(argv[0],cmdBuf)==0){ 
			websWrite(wp,"selected");
			break;
		}
		sprintf(cmdBuf, "list%d",i);		
		if(strcmp(argv[0],cmdBuf)==0)
		{
			char temp[6]={0}, count=0;

			for(j=0;j<MAX_WLAN_AC;j++)
			{			
				if(memcmp(pRomeCfgParam->wlanCfgParam[i].acMacList[j],temp,6)==0) 
					continue;
				websWrite(wp,
		 		"<tr bgColor=#ddeeff><td>%d</td><td>%02X-%02X-%02X-%02X-%02X-%02X</td><td>%s</td><td><input type=checkbox value=1 name=ac%d_%d></td></tr>\n",
				j,
	 			pRomeCfgParam->wlanCfgParam[i].acMacList[j][0],
	 			pRomeCfgParam->wlanCfgParam[i].acMacList[j][1],
	 			pRomeCfgParam->wlanCfgParam[i].acMacList[j][2],
	 			pRomeCfgParam->wlanCfgParam[i].acMacList[j][3],
	 			pRomeCfgParam->wlanCfgParam[i].acMacList[j][4],
	 			pRomeCfgParam->wlanCfgParam[i].acMacList[j][5], 			
	 			pRomeCfgParam->wlanCfgParam[i].acComment[j],i,j);
				count++;
			} 
			if(count==0)
				websWrite(wp,
		 		"<tr bgColor=#ddeeff><td colspan=4 align=center>--client list is empty now--</td></tr>\n");
			break;
		}	
	}
	return 0;
}	
void asp_setWlanAccessCtrl(request * wp, char *path, char *query)
{
	int w,i, total=-1;
	char zero[6]={0};	
	//rtl8651_tblDrvAclRule_t tempAclRule;
	char cmdBuf[40],cmdBuf1[40];
	/* read cfg from cfgmgr */
	for(w=0;w<totalWlanCards;w++){	
		sprintf(cmdBuf, "deleteSelected%d",w);
		sprintf(cmdBuf1, "deleteAll%d",w);
		if(strcmp(websGetVar(wp,cmdBuf,""),"Delete Selected")==0)
		{
			char str[8];
			for(i=0;i<MAX_WLAN_AC;i++)
			{
				sprintf(str,"ac%d_%d",w,i);
				if(atoi(websGetVar(wp,str,""))==1)
				{
					total=i;
					memset(pRomeCfgParam->wlanCfgParam[w].acMacList[i], 0, 6);
					memset(pRomeCfgParam->wlanCfgParam[w].acComment[i], 0, 8);					
				}else if(total>=0&&memcmp(pRomeCfgParam->wlanCfgParam[w].acMacList[i],zero,6)==0){
					//move last to first
					memcpy(pRomeCfgParam->wlanCfgParam[w].acMacList[total],pRomeCfgParam->wlanCfgParam[w].acMacList[i-1],6);
					total=i;
					break;
				}
			}
		}
		else if(strcmp(websGetVar(wp,cmdBuf1,""),"Delete All")==0)	
		{
			//cleanup all Access control configuration in flash
			memset(pRomeCfgParam->wlanCfgParam[w].acMacList, 0, MAX_WLAN_AC*6);
			memset(pRomeCfgParam->wlanCfgParam[w].acComment, 0, MAX_WLAN_AC*8);
		}
		else
		{
			sprintf(cmdBuf, "enable%d",w);
			pRomeCfgParam->wlanCfgParam[w].acEnable=
				atoi(websGetVar(wp,cmdBuf,""));

			sprintf(cmdBuf, "mac%d",w);
			if(strlen(websGetVar(wp,cmdBuf,""))!=0)
			{
				for(i=0;i<MAX_WLAN_AC;i++)
				{		
					if(memcmp(pRomeCfgParam->wlanCfgParam[w].acMacList[i],zero,6)==0)	
						break;
				}
				if(i==MAX_WLAN_AC) 
					return; // ac list full	
				parse_mac(websGetVar(wp,cmdBuf,""),pRomeCfgParam->wlanCfgParam[w].acMacList[i]);

				sprintf(cmdBuf, "comment%d",w);
				memcpy(pRomeCfgParam->wlanCfgParam[w].acComment[i],websGetVar(wp,cmdBuf,""),(strlen(websGetVar(wp,cmdBuf,""))+1)>8?8:(strlen(websGetVar(wp,cmdBuf,""))+1));
				i++;
				total=i;
				for(;i<MAX_WLAN_AC;i++){
					memset(pRomeCfgParam->wlanCfgParam[w].acMacList[i],0, 6);
					memset(pRomeCfgParam->wlanCfgParam[w].acComment[i],0, 6);
				}
			}
		}
	}
	cfgmgr_write(CFGMGR_TABID_WLAN,(void*)pRomeCfgParam->wlanCfgParam,sizeof(wlanCfgParam_t)*MAX_WLAN_CARDS);
	cfgmgr_task();
#ifdef CONFIG_RTL8185
	wlan_setup(0);
#endif
	websRedirect(wp, "/wireless_ac.asp");
}

/************************************************************
 *	
 *	Wireless Distribution System
 *	
 ************************************************************/


#ifdef CONFIG_RTL8185
int rtl8185GetStaInfo(char *name, unsigned char *dataptr, unsigned int *size)
{
	struct iwreq wrq;
	struct sta_info_2_web *info;
	int sockfd, retval=-1;
	if(!size){
		retval=-2;
		goto out;
	}else if(*size==0 || *size>(sizeof( sta_info_2_web)*64)){
		retval=-3;
		goto out;
	}
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		retval=-4;
		goto out;
	}
	memset(&wrq, 0, sizeof(struct iwreq));
	strncpy(wrq.ifr_name, name, IFNAMSIZ);
	memset(dataptr, 0, *size);
	wrq.u.data.pointer = (caddr_t)dataptr;
	wrq.u.data.length = *size;
	retval=ioctl(sockfd, SIOCGIWRTLSTAINFO, &wrq);
	if(retval<0){
       	*size=0;
       }else{
       	*size=retval;
		retval=0;
	   }
	close(sockfd);
out:
        return retval;
}

void printSTA(request * wp, int index, sta_info_2_web *info){
				
	/*
	<table cellSpacing=1 cellPadding=2 border=0  bgColor=white>
		<tr bgColor=#aaddff>
		<td>No.</td><td>AID</td>
		<td>MAC</td><td>Band</td>
		<td>TxRate</td><td>Signal Strength</td>
		<td>RxPkt</td><td>TxPkt</td>
		<td>LinkTime</td>
	</tr>
	*/

		websWrite(wp,
	 		"<tr bgColor=#ddeeff>"
	 		"<td>%d</td><td>%d</td>"
	 		"<td>%02X-%02X-%02X-%02X-%02X-%02X</td><td>%c</td>"
	 		"<td>%d.%c</td><td>%d</td>"
	 		"<td>%d</td><td>%d</td>"
			"<td>%d </td>"
	 		"</tr>\n",
				index,
				info->aid,
				info->addr[0],info->addr[1],info->addr[2],info->addr[3],info->addr[4],info->addr[5],
				(info->flags & STA_INFO_FLAG_80211A)?'A':((info->flags & STA_INFO_FLAG_80211B)?'B':'G'),
				info->TxOperaRate>>1, (info->TxOperaRate&1)?'5':'0',
				info->rssi,
				info->rx_packets, info->tx_packets,
				info->link_time
		);
} 
#endif

int asp_wlanClientList(request * wp, int argc, char **argv)
{
	int w;
	char cmdBuf[40];
	char iface[16];
#define GETSIZE   64
#ifdef CONFIG_RTL8185
	sta_info_2_web  info[GETSIZE];
#endif/*CONFIG_RTL8185*/
	
	for ( w=0 ; w<totalWlanCards ; w++ )
	{
		int total, i, j;
		sprintf(iface, "wlan%d",w); 
		sprintf(cmdBuf, "list%d",w); 		
		if ( strcmp(argv[0],cmdBuf) == 0 )
		{
#ifdef CONFIG_RTL8185
			int i,count=0, retval=-1;
			int size;
			int oldsize;
			char temp[6]={0};
next_round:
			size = sizeof(info);
			oldsize = size;
			memset(&info[0], 0, sizeof(info));
			retval = rtl8185GetStaInfo(iface, &info[0], &size);

			if ( 0 != retval )
			{
				/* do nothing because get station fail */
				printf("Get Station Info not success: %d\n", retval);
			}else if ( size != oldsize )
			{
				if (size)
				{
					/* buffer not filled completely. reached the end of list*/
					for( i = 0 ; i < size/sizeof(sta_info_2_web) ; i++ )
					{
						printSTA(wp, count+i,&info[i]);
					}
					count += size/sizeof(sta_info_2_web);
				}else if( count == 0 )
				{
					//No clients associated. List is empty now
					websWrite(wp,
			 		"<tr bgColor=#ddeeff>"
			 		"<td colspan=9 align=center>--No clients associated--</td></tr>\n");
				}
			}else
			{
				/*buffer filled. Get next round*/
				for( i = 0 ; i < size/sizeof(sta_info_2_web) ; i++ )
				{
					printSTA(wp, count+i,&info[i]);
				}
				count += size/sizeof(sta_info_2_web);
				if (count < GETSIZE)
				{
					goto next_round;
				}
			}			
			break;
#endif			
		}	
	}		
	return 0;
	
}	

#ifdef CONFIG_RTL8185

static inline int iw_get_ext(int skfd,           /* Socket to the kernel */
           char *               ifname,         /* Device name */
           int                  request,        /* WE ID */
           struct iwreq *       pwrq)           /* Fixed part of the request */
{
  /* Set device name */
  strncpy(pwrq->ifr_name, ifname, IFNAMSIZ);
  /* Do the request */
  return(ioctl(skfd, request, pwrq));
}

int getWlSiteSurveyRequest(char *interface, int *pStatus)
{
    int skfd;
    struct iwreq wrq;
    unsigned char result;

    skfd = socket(AF_INET, SOCK_DGRAM, 0);

    /* Get wireless name */
    if ( iw_get_ext(skfd, interface, SIOCGIWNAME, &wrq) < 0)
      /* If no wireless name : no wireless extensions */
        return -1;

    wrq.u.data.pointer = (caddr_t)&result;
    wrq.u.data.length = sizeof(result);

    if (iw_get_ext(skfd, interface, SIOCGIWRTLSCANREQ, &wrq) < 0)
	return -1;

    close( skfd );

    if ( result == 0xff )
    	*pStatus = -1;
    else
	*pStatus = (int) result;

    return 0;
}

int getWlSiteSurveyResult(char *interface, SS_STATUS_Tp pStatus )
{
    int skfd;
    struct iwreq wrq;

    skfd = socket(AF_INET, SOCK_DGRAM, 0);

    /* Get wireless name */
    if ( iw_get_ext(skfd, interface, SIOCGIWNAME, &wrq) < 0)
      /* If no wireless name : no wireless extensions */
        return -1;

    wrq.u.data.pointer = (caddr_t)pStatus;

    if ( pStatus->number == 0 )
    	wrq.u.data.length = sizeof(SS_STATUS_T);
    else
        wrq.u.data.length = sizeof(pStatus->number);

    if (iw_get_ext(skfd, interface, SIOCGIWRTLGETBSSDB, &wrq) < 0)
	return -1;

    close( skfd );
    return 0;
}

int getWlBssInfo(char *interface, bss_info *pInfo)
{
    int skfd;
    struct iwreq wrq;

    skfd = socket(AF_INET, SOCK_DGRAM, 0);

    /* Get wireless name */
    if ( iw_get_ext(skfd, interface, SIOCGIWNAME, &wrq) < 0)
      /* If no wireless name : no wireless extensions */
        return -1;

    wrq.u.data.pointer = (caddr_t)pInfo;
    wrq.u.data.length = sizeof(bss_info);

    if (iw_get_ext(skfd, interface, SIOCGIWRTLGETBSSINFO, &wrq) < 0)
	return -1;
    close( skfd );
    return 0;
}



int getWlJoinRequest(char *interface, pBssDscr pBss, unsigned char *res)
{
    int skfd;
    struct iwreq wrq;

    skfd = socket(AF_INET, SOCK_DGRAM, 0);

    /* Get wireless name */
    if ( iw_get_ext(skfd, interface, SIOCGIWNAME, &wrq) < 0)
      /* If no wireless name : no wireless extensions */
        return -1;

    wrq.u.data.pointer = (caddr_t)pBss;
    wrq.u.data.length = sizeof(BssDscr);

    if (iw_get_ext(skfd, interface, SIOCGIWRTLJOINREQ, &wrq) < 0)
	return -1;

    close( skfd );
    
    *res = wrq.u.data.pointer[0];
    return 0;
}

int getWlJoinResult(char *interface, unsigned char *res)
{
    int skfd;
    struct iwreq wrq;

    skfd = socket(AF_INET, SOCK_DGRAM, 0);

    /* Get wireless name */
    if ( iw_get_ext(skfd, interface, SIOCGIWNAME, &wrq) < 0)
      /* If no wireless name : no wireless extensions */
        return -1;

    wrq.u.data.pointer = (caddr_t)res;
    wrq.u.data.length = 1;

    if (iw_get_ext(skfd, interface, SIOCGIWRTLJOINREQSTATUS, &wrq) < 0)
	return -1;
    close( skfd );
    return 0;
}

#endif

static int _apListPrintHeader(request * wp){
	websWrite(wp, T("<tr bgcolor=\"#aaddff\"><td align=center width=\"20%%\" ><font size=\"2\"><b>SSID</b></font></td>\n<td align=center width=\"20%%\" ><font size=\"2\"><b>BSSID</b></font></td>\n<td align=center width=\"5%%\" ><font size=\"2\"><b>Channel</b></font></td>\n<td align=center width=\"5%%\" ><font size=\"2\"><b>Type</b></font></td>\n<td align=center width=\"5%%\" ><font size=\"2\"><b>Encrypt</b></font></td>\n<td align=center width=\"5%%\" ><font size=\"2\"><b>Signal</b></font></td>\n<td align=center width=\"30%%\" bgcolor=\"#808080\"><font size=\"2\"><b>Action</b></font></td></tr>"));
}

int asp_wlanNeighborApList(request * wp, int argc, char **argv)
{
#ifdef CONFIG_RTL8185
	int w, i, j,wait_time, status, is11a=0;
	char cmdBuf[64];
	char scanIf[16];	
	BssDscr *pBss;
	char tmpBuf[100], ssidbuf[40], tmp1Buf[10];
	WLAN_MODE_T mode;
	int8 *wdsApFlag=NULL;
	bss_info thisBss;	
	if(totalWlanCards<1){
		return 0;
	}
	int8 joinable[4][4]={
		/*client:  b   g   b+g   a */
	/*b*/		{1,	0,	1,	0},
	/*g*/		{0,	1,	1,	0},
	/*AP:b+g*/	{1,	1,	1,	0},
	/*a*/		{0,	0,	0,	1},
	};
	

	if (cfgmgr_read(CFGMGR_TABID_WLAN,(void*)(pRomeCfgParam->wlanCfgParam), sizeof(struct wlanCfgParam_s)*MAX_WLAN_CARDS)!=0)
	{
		printf("asp_wlanNeighborApList: call cfgmgr_read fail\n");
		/* take proper actions */
		return 0;
	}

	//check if interface is enabled for WDS
	for(w=0;w<MAX_WLAN_CARDS;w++){		
		sprintf(cmdBuf, "wds_enable%d",w); 
		if(strcmp(argv[0],cmdBuf)==0){
			if(pRomeCfgParam->wlanCfgParam[w].mode>CLIENT_MODE){
				websWrite(wp,"%s",pRomeCfgParam->wlanCfgParam[w].wdsEnable?"checked":"");
			}else{
				websWrite(wp,"disabled");
			}
			return 0;
		}
	}
	
	wdsApFlag=malloc(MAX_WLAN_WDS*totalWlanCards);
	if(!wdsApFlag)
		return 0;
	memset(wdsApFlag, 0, MAX_WLAN_WDS*totalWlanCards);
	//argv[0] is '11a' or '11g'
	
	//do site survey on requested band then display discovered APs.
	//If WDS is enabled on any card which runs in this band, display configured WDS APs and
	//let user add/remove

	for(i=0;i<totalWlanCards;i++){
		if(pRomeCfgParam->wlanCfgParam[i].enable == 1){
			sprintf(scanIf, "wlan%d",i);
			if(strcmp("11a",argv[0])==0){
				if(pRomeCfgParam->wlanCfgParam[i].dataRateMode == WLAN_DATA_RATE_A){
					is11a=1;
					break;
				}
			}else{
				if(pRomeCfgParam->wlanCfgParam[i].dataRateMode != WLAN_DATA_RATE_A)
					break;
			}

		}
	}

	if(i==totalWlanCards){
		websWrite(wp, "--No WLAN card operating in 802.%s band found--", argv[0]);
		//No wlan card is operating in indicated band.
		_apListPrintHeader(wp);
		goto out; 
	} 
	//A wlan card operating in indicated band found. 
	wait_time = 0;
	sprintf(cmdBuf, "wlan%d", i);
	if (getWlBssInfo(scanIf, &thisBss) < 0) {
		printf("Get bssinfo failed!");
		free(pStatus);
		pStatus = NULL;
		goto out;
	}
	
	// Do site survey
	while (1) {
		if ( getWlSiteSurveyRequest(scanIf,  &status) < 0 ) {
			strcpy(tmpBuf, T("Site-survey request failed!"));
			printf("Can't start site survey\n");
			_apListPrintHeader(wp);			
			goto list;
		}
		{
			int timerCount;
			for (timerCount=0;timerCount<10;timerCount++)
				sleep(1);
		}
		if (status != 0) {	// not ready
			if (wait_time++ > 5) {
				strcpy(tmpBuf, T("scan request timeout!"));
				printf("site survey timeout\n");
				_apListPrintHeader(wp);
				goto list;
			}
			sleep(1);
		}
		else
			break;
	}

	//About to redo site survey so flush old site survey result.
	if(pStatus){
		free(pStatus); 
		pStatus = NULL;
	}
	//Allocate a new buffer to store site survey result
	pStatus = calloc(1, sizeof(SS_STATUS_T));
	memset(selectedAPIdx,-1, sizeof(selectedAPIdx));
	
	if ( pStatus == NULL ) {
		printf("Allocate site survey buffer failed!\n");
		_apListPrintHeader(wp);		
		goto list;
	}
	pStatus->number = 0; // request BSS DB
	if ( getWlSiteSurveyResult(scanIf, pStatus) < 0 ) {
		//ERR_MSG("Read site-survey status failed!");
		_apListPrintHeader(wp);
		free(pStatus);
		goto list;
	}
	_apListPrintHeader(wp);

	printf("%d found\n", pStatus->number);
	for (i=0; i<pStatus->number && pStatus->number!=0xff; i++) {
		int thisApBand;
		pBss = &pStatus->bssdb[i];
		snprintf(tmpBuf, 200, T("%02x:%02x:%02x:%02x:%02x:%02x"),
			pBss->bdBssId[0], pBss->bdBssId[1], pBss->bdBssId[2],
			pBss->bdBssId[3], pBss->bdBssId[4], pBss->bdBssId[5]);

		memcpy(ssidbuf, pBss->bdSsIdBuf, pBss->bdSsId.Length);
		ssidbuf[pBss->bdSsId.Length] = '\0';

		if (pBss->network==BAND_11B){
			strcpy(tmp1Buf, T(" (B)"));
			thisApBand=WLAN_DATA_RATE_B;;
		}else if (pBss->network==BAND_11G){
			strcpy(tmp1Buf, T(" (G)"));	
			thisApBand=WLAN_DATA_RATE_G;;
		}else if (pBss->network==(BAND_11G|BAND_11B)){
			strcpy(tmp1Buf, T(" (B+G)"));
			thisApBand=WLAN_DATA_RATE_BG;
		}else{
			strcpy(tmp1Buf, T(" (A)"));	
			thisApBand=WLAN_DATA_RATE_A;
		}
		 websWrite(wp, T("<tr bgcolor=#ddeeff><td align=left ><font size=\"2\">%s</td>\n<td align=center ><font size=\"2\">%s</td>\n<td align=center><font size=\"2\">%d%s</td>\n<td align=center><font size=\"2\">%s</td>\n<td align=center><font size=\"2\">%s</td>\n<td align=center><font size=\"2\">%d</td>\n"),
			ssidbuf, tmpBuf, pBss->ChannelNumber, tmp1Buf,			
			((pBss->bdCap & cIBSS) ? "Ad hoc" : "AP"),
			((pBss->bdCap & cPrivacy) ? "yes" : "no"), pBss->rssi);

		websWrite(wp,T("<td align=center width=\"10%%\">"));
		for(j=0;j<totalWlanCards;j++){
			int index;
			if(pRomeCfgParam->wlanCfgParam[j].enable==0)
				continue;

			if(pRomeCfgParam->wlanCfgParam[j].mode==CLIENT_MODE){ //is AP client mode
				
				if(joinable[thisApBand][pRomeCfgParam->wlanCfgParam[j].dataRateMode]==1){
					 websWrite(wp,T("<input type=\"radio\" name=\"ap%dconnect\" value=\"%d\">Connect %s to this AP<br>" ),
						i, j, pRomeCfgParam->wlanCfgParam[j].aliasName); 
				}
				continue;
			}
			//Not AP client mode....
			
			if(pRomeCfgParam->wlanCfgParam[j].wdsEnable==0)
				continue;//wds not enabled, check next card

			if((is11a&&pRomeCfgParam->wlanCfgParam[j].dataRateMode != WLAN_DATA_RATE_A)||
				(is11a==0&&pRomeCfgParam->wlanCfgParam[j].dataRateMode == WLAN_DATA_RATE_A))
				continue;
				
			//is this BSSID already a configured WDS link?
			for(index=0;index<MAX_WLAN_WDS;index++){
				if(memcmp(pBss->bdBssId,pRomeCfgParam->wlanCfgParam[j].wdsMacList[index],6)==0){
					websWrite(wp,T("<input type=\"radio\" name=\"ap%ddelete\" value=\"%d\">Delete from %s's WDS list<br>"),
						i,j,pRomeCfgParam->wlanCfgParam[j].aliasName);
					wdsApFlag[j*MAX_WLAN_WDS+index]=1;
					break;
				}
			}
			if(index<MAX_WLAN_WDS)
				break;//yes, already configured.
			if(joinable[pRomeCfgParam->wlanCfgParam[j].dataRateMode][thisApBand]==0){
				continue; //Can't add this AP to wlan card's wds list since not in same RF band
			}
			if(thisBss.channel!=pBss->ChannelNumber){
				continue; //Can't add, not in same channel
			}
			//Ok, can be added to WDS list.
			websWrite(wp,T("<input type=\"radio\" name=\"ap%dadd\" value=\"%d\" >Add to %s's WDS list<br>"),
				i,j, pRomeCfgParam->wlanCfgParam[j].aliasName);
		}
		websWrite(wp, T("</td></tr>\n"));
	}

list:	

	for(w=0;w<totalWlanCards;w++){		
		int i;
		char temp[6]={0,0,0,0,0,0};
		if(pRomeCfgParam->wlanCfgParam[w].wdsEnable==0)
			continue;

		if((is11a&&pRomeCfgParam->wlanCfgParam[w].dataRateMode != WLAN_DATA_RATE_A)||
			(is11a==0&&pRomeCfgParam->wlanCfgParam[w].dataRateMode == WLAN_DATA_RATE_A))
			continue;
			
		for(i=0;i<MAX_WLAN_WDS;i++)
		{			
			if(wdsApFlag[w*MAX_WLAN_WDS+i]==0){
				if(memcmp(pRomeCfgParam->wlanCfgParam[w].wdsMacList[i],temp,6)==0) {
					continue; //this entry is empty, skip..
				}
				//Non-zero MAC. A valid entry.
				websWrite(wp,T("<tr bgcolor=#ddeeff><td></td><td>%02X-%02X-%02X-%02X-%02X-%02X</td><td></td><td></td><td></td><td></td><td><input type=\"radio\" name=\"wds%ddelete\" value=\"%d\">Delete inactive AP from %s's WDS list</td></tr>\n"),
	 			pRomeCfgParam->wlanCfgParam[w].wdsMacList[i][0],
	 			pRomeCfgParam->wlanCfgParam[w].wdsMacList[i][1],
	 			pRomeCfgParam->wlanCfgParam[w].wdsMacList[i][2],
	 			pRomeCfgParam->wlanCfgParam[w].wdsMacList[i][3],
	 			pRomeCfgParam->wlanCfgParam[w].wdsMacList[i][4],
	 			pRomeCfgParam->wlanCfgParam[w].wdsMacList[i][5],
				i, w,
				pRomeCfgParam->wlanCfgParam[w].aliasName);
			}
		} 
		break;
	}		
out:
	free(wdsApFlag);
#endif
	return 0;
}	



#ifdef CONFIG_RTL8185
#define ERR_MSG(msg) { \
	websHeader(wp); \
   	websWrite(wp, T("<body><blockquote><h4>%s</h4>\n"), msg); \
	websWrite(wp, T("<form><input type=\"button\" onclick=\"history.go (-1)\" value=\"&nbsp;&nbsp;OK&nbsp;&nbsp\" name=\"OK\"></form></blockquote></body>")); \
   	websFooter(wp); \
	websDone(wp, 200); \
}



//cardIdx: # of WLAN card to join
//thisAp: BSS info collected from site survey. If NULL, do site survey.
int32 clientFindAp(int32 cardIdx,BssDscr *thisAp)
{
 	char  *connect, *strSel;
	int status;
	unsigned char res, *pMsg=NULL;
	int wait_time, i, j;
	char tmpBuf[100];
	uint32 maxRSSI;
	NETWORK_TYPE_T net;
	int chan;
	uint8 iface[8];
	sprintf(iface, "wlan%d", cardIdx);

	if(!thisAp){
		uint32 findBestAP=0;
		if(!pStatus){
			// Do site survey
			printf("Doing site survey on %s...", iface);
			while (1) {
				if ( getWlSiteSurveyRequest(iface,  &status) < 0 ) {
					printf("Site survey failed\n");
					return FAILED; //can't do site survey. Abort.
				}
				{
					int timerCount;
					for (timerCount=0;timerCount<5;timerCount++)
						sleep(1);
				}
				if (status != 0) {	// not ready
					if (wait_time++ > 5) {
						printf("Site survey timed out\n");
						return FAILED;
					}
					sleep(1);
				}
				else
					break;
			}
			//Allocate a new buffer to store site survey result
			pStatus = calloc(1, sizeof(SS_STATUS_T));
			memset(selectedAPIdx,-1, sizeof(selectedAPIdx));
			if ( pStatus == NULL ) {
				printf("No more buffer for site survey result!\n");
				return FAILED;
			}
			pStatus->number = 0; 
			if ( getWlSiteSurveyResult(iface, pStatus) < 0 ) {
				printf("Read site-survey status failed!\n");
				free(pStatus);
				return FAILED;
			}
			printf("%d APs found\n",pStatus->number);
		}
		//If SSID not yet set, find best one.
		findBestAP=strlen(pRomeCfgParam->wlanCfgParam[cardIdx].ssid)?0:1;
		//traverse the site survey result, to find the best AP to join
		for (i=0, j=-1, maxRSSI=0 ; i<pStatus->number && pStatus->number!=0xff; i++) {
			uint8 tmpBuf[32];
			thisAp= &pStatus->bssdb[i];
			memcpy(tmpBuf,  thisAp->bdSsIdBuf, thisAp->bdSsId.Length);
			tmpBuf[thisAp->bdSsId.Length]='\0';
			//see if SSID is the same
			if(strcmp(pRomeCfgParam->wlanCfgParam[cardIdx].ssid, tmpBuf)==0){
				//actually should check if this is the desired BSSID to join, but we just pick the first match now
				selectedAPIdx[cardIdx]=i;
				break;	
			}
			//SSID not identical, but see if this is the AP which has strongest signal so far.
			if(findBestAP&& maxRSSI<thisAp->rssi){
				j=i;
				maxRSSI=thisAp->rssi;	
				//remember this one has best signal quality
			}
		}
		if(i==pStatus->number){
			//No matching
			if(findBestAP&&j>=0){
				thisAp= &pStatus->bssdb[j];
				selectedAPIdx[cardIdx]=j;
			}else{
				printf("Can't associate to any AP now\n");
				return FAILED; 
			}
		}
	}
	if(!thisAp){
		printf("No AP found\n");
		return FAILED;
	}		
	// Set SSID, network type
	printf("Selecting SSID='%s'\n", thisAp->bdSsIdBuf);
	if(thisAp->bdSsId.Length>sizeof(pRomeCfgParam->wlanCfgParam[cardIdx].ssid)){
		strncpy(pRomeCfgParam->wlanCfgParam[cardIdx].ssid, thisAp->bdSsIdBuf,sizeof(pRomeCfgParam->wlanCfgParam[cardIdx].ssid));
		pRomeCfgParam->wlanCfgParam[cardIdx].ssid[sizeof(pRomeCfgParam->wlanCfgParam[cardIdx].ssid)-1]='\0';
	}else{
		strncpy(pRomeCfgParam->wlanCfgParam[cardIdx].ssid, thisAp->bdSsIdBuf,thisAp->bdSsId.Length);
		pRomeCfgParam->wlanCfgParam[cardIdx].ssid[thisAp->bdSsId.Length]='\0';
	}
	if ( thisAp->bdCap & cESS ){
		//infrastructure client mode
		pRomeCfgParam->wlanCfgParam[cardIdx].adhoc=0;
	}else{
		//adhoc client mode
		pRomeCfgParam->wlanCfgParam[cardIdx].adhoc=1;
	}	
	pRomeCfgParam->wlanCfgParam[cardIdx].channel = thisAp->ChannelNumber;
	cfgmgr_write(CFGMGR_TABID_WLAN,(void*)pRomeCfgParam->wlanCfgParam,sizeof(wlanCfgParam_t)*MAX_WLAN_CARDS);
	cfgmgr_task();
	return SUCCESS;
}

int32 apClientJoin(int32 cardIdx, int32 booting)
{
	BssDscr *thisAp=NULL;
	unsigned char res, *pMsg=NULL;
	int wait_time, i, j;
	uint8 iface[8];	
	sprintf(iface, "wlan%d", cardIdx);

	if(booting){
		//should do site survey now.
		if(SUCCESS==clientFindAp(cardIdx, NULL))
			return 1;
	}
	if(!pStatus||selectedAPIdx[cardIdx]<0){
		printf("No site survey info\n");
		return FAILED;
	}

	thisAp= &pStatus->bssdb[selectedAPIdx[cardIdx]];

	if(!thisAp){
		printf("No AP selected to join for %s\n", iface);	
		return FAILED;
	}

	printf("\n %s: Try to associate with AP....\n", iface);	
	/////////////////////////
	res = 0;
	wait_time = 0;
	while (1) {

		if ( getWlJoinRequest(iface, thisAp, &res) < 0 ) {
			printf("Join request failed 1 !\n");
			return FAILED;;
		}
		if ( res == 1 ) { // wait
			if (wait_time++ > 5) {
				printf("Join request timed out 1 !\n");
				return FAILED;
			}
			sleep(1);
			continue;
		}
		break;
	}
	if ( res == 2 ){ // invalid index
		printf("Connect failed!");
		return FAILED;
	}else {
		wait_time = 0;
		while (1) {
			if ( getWlJoinResult(iface, &res) < 0 ) {
				printf("Join request failed 2 !\n");
				return FAILED;
			}
			if ( res != 0xff ) { // completed
				if (wait_time++ > 10) {
					printf("Join request timed out 2!\n");
					return FAILED;
				}
				break;
			}
			sleep(1);
		}

		if ( res!=STATE_Bss && res!=STATE_Ibss_Idle && res!=STATE_Ibss_Active ){
			printf("Join request failed !\n");
			return FAILED;
		}else{
			printf("Connect successfully!\n");
		}
	}
	return SUCCESS;
}
#endif


void asp_selectWlanNeighborAp(request * wp, char *path, char *query)
{
	int32 restart=0;
#ifdef CONFIG_RTL8185
	int card,i, ap, wds;
	char temp[6]={0,0,0,0,0,0};	
	char cmdBuf[64];
	int32 wdsCount;
	BssDscr *thisAp=NULL;

	for(card=0;card<MAX_WLAN_CARDS;card++){
		if(pRomeCfgParam->wlanCfgParam[card].enable){
			uint8 orgEnable = pRomeCfgParam->wlanCfgParam[card].wdsEnable;
			sprintf(cmdBuf, "enable%d",card);
			pRomeCfgParam->wlanCfgParam[card].wdsEnable=atoi(websGetVar(wp,cmdBuf,""));
			/* when we dynamically turn on/off WDS, restart is necessary */
			if (pRomeCfgParam->wlanCfgParam[card].wdsEnable != orgEnable) {
				restart=1;
			}
		}
	}
	
	if(!pStatus){
		printf("No site survey result, can't select\n");
		goto out;
	}

	printf("Total %d APs found\n", pStatus->number);
	
	for(ap=0;ap<pStatus->number;ap++){
		sprintf(cmdBuf, "ap%dconnect",ap);
		if(strlen(websGetVar(wp,cmdBuf,""))>0){
			card=atoi(websGetVar(wp,cmdBuf,""));
			/*connect to this AP for wlan #card*/
			selectedAPIdx[card]=ap;
			thisAp=&pStatus->bssdb[ap];

			// Set SSID, network type
			printf("Connecting wlan%d to ap%d(%s), SSID: '%s', ", card, ap,ether_ntoa(thisAp->bdBssId),thisAp->bdSsIdBuf);
			if(thisAp->bdSsId.Length>sizeof(pRomeCfgParam->wlanCfgParam[card].ssid)){
				strncpy(pRomeCfgParam->wlanCfgParam[card].ssid, thisAp->bdSsIdBuf,sizeof(pRomeCfgParam->wlanCfgParam[card].ssid));
				pRomeCfgParam->wlanCfgParam[card].ssid[sizeof(pRomeCfgParam->wlanCfgParam[card].ssid)-1]='\0';
			}else{
				strncpy(pRomeCfgParam->wlanCfgParam[card].ssid, thisAp->bdSsIdBuf,thisAp->bdSsId.Length);
				pRomeCfgParam->wlanCfgParam[card].ssid[thisAp->bdSsId.Length]='\0';
			}
			if ( thisAp->bdCap & cESS ){
				//infrastructure client mode
				pRomeCfgParam->wlanCfgParam[card].adhoc=0;
				printf("Infrastructure mode\n");
			}else{
				//adhoc client mode
				pRomeCfgParam->wlanCfgParam[card].adhoc=1;
				printf("Adhoc mode\n");
			}	
			pRomeCfgParam->wlanCfgParam[card].channel = thisAp->ChannelNumber;
			restart=1;
			goto out;
		}
		sprintf(cmdBuf, "ap%ddelete",ap);
		if(strlen(websGetVar(wp,cmdBuf,""))>0){
			card=atoi(websGetVar(wp,cmdBuf,""));
			wdsCount=pRomeCfgParam->wlanCfgParam[card].wdsCount;
			if(wdsCount){
				//printf("Deleting ap%d(%s) from wlan%d's WDS link\n", ap, ether_ntoa(pStatus->bssdb[ap].bdBssId), card);
				for(i=0;i<MAX_WLAN_WDS;i++){
					if(0==memcmp(pRomeCfgParam->wlanCfgParam[card].wdsMacList[i],pStatus->bssdb[ap].bdBssId,6)){
						memset(pRomeCfgParam->wlanCfgParam[card].wdsMacList[i], 0, 6);
						pRomeCfgParam->wlanCfgParam[card].wdsCount--;
						//printf("Deleted! Total WDS: %d\n", pRomeCfgParam->wlanCfgParam[card].wdsCount);
						restart=1;
						break;						
					}
				}
				//if(i==MAX_WLAN_WDS)
				//	printf("Failed! BSSID not found\n");
				continue;
			}
		}
		sprintf(cmdBuf, "ap%dadd",ap);
		if(strlen(websGetVar(wp,cmdBuf,""))>0){
			uint8 zeroMac[6]={0,0,0,0,0,0};
			card=atoi(websGetVar(wp,cmdBuf,""));
			wdsCount=pRomeCfgParam->wlanCfgParam[card].wdsCount;
			if(wdsCount<MAX_WLAN_WDS){
				//printf("Adding WDS link(%s) to wlan%d...", ether_ntoa(pStatus->bssdb[ap].bdBssId),card);
				for(i=0;i<MAX_WLAN_WDS;i++){
					if(0==memcmp(pRomeCfgParam->wlanCfgParam[card].wdsMacList[i],
							zeroMac,6)){
						memcpy(pRomeCfgParam->wlanCfgParam[card].wdsMacList[i], pStatus->bssdb[ap].bdBssId, 6);
						pRomeCfgParam->wlanCfgParam[card].wdsCount++;
						//printf("Added! Total WDS: %d\n", pRomeCfgParam->wlanCfgParam[card].wdsCount);
						restart=1;
						break;
					}
				}
				//if(i==MAX_WLAN_WDS)
				//	printf("Failed! No available buffer?\n");
				continue;
			}//else
			//	printf("Can't add %s to wlan%d's WDS list: Over capacity...", ether_ntoa(pStatus->bssdb[ap].bdBssId),card);				
		}
	}

	for(wds=0;wds<MAX_WLAN_WDS;wds++){
		sprintf(cmdBuf, "wds%ddelete",wds);
		if(strlen(websGetVar(wp,cmdBuf,""))>0){
			card=atoi(websGetVar(wp,cmdBuf,""));
			wdsCount=pRomeCfgParam->wlanCfgParam[card].wdsCount;
			//printf("wlan%d-wds%d: Deleting inactive AP(%s) from wlan%d's WDS list\n total:%d\n", card, wds, ether_ntoa(pRomeCfgParam->wlanCfgParam[card].wdsMacList[wds]), card, wdsCount);
			memset(pRomeCfgParam->wlanCfgParam[card].wdsMacList[wds], 0, 6);
			pRomeCfgParam->wlanCfgParam[card].wdsCount--;
			restart=1;
			//printf("Deleted! Total WDS: %d\n", pRomeCfgParam->wlanCfgParam[card].wdsCount);
			continue;
		}
	}

out:
	cfgmgr_write(CFGMGR_TABID_WLAN,(void*)pRomeCfgParam->wlanCfgParam,sizeof(wlanCfgParam_t)*MAX_WLAN_CARDS);
	cfgmgr_task();

#ifdef CONFIG_RTL8185
	//must restart WLAN card in 8185 driver...:(
	if(restart)
		wlan_setup(0);
#endif	
	websRedirect(wp, "/wireless_wds.asp");
#endif

}



/************************************************************
 *	
 *	UDP Blocking
 *	
 ************************************************************/
int asp_udpBlocking(request * wp, int argc, char **argv)
{

	int ms=asp_multiSession(wp,argc,argv);
	
 	if(strcmp(argv[0],"size")==0)
 	{
		int i;
		for(i=3;i<=30;i++)			
	 		websWrite(wp,"<option value=%d%s>%d</option>\n",i,(pRomeCfgParam->udpblockCfgParam[ms].size==i)?" selected":"",i);
	}
 	else if(strcmp(argv[0],"MS")==0)
 	{
 		websWrite(wp,"%d",ms);
 	}
	else if(strcmp(argv[0],"enable")==0)
	{
		if(pRomeCfgParam->udpblockCfgParam[ms].enable==1) websWrite(wp,"checked");
	}
	
	return 0;
}

void asp_setUdpBlocking(request * wp, char *path, char *query)
{
	char		tmpstr[32]={0};	
	int		ms=atoi(websGetVar(wp,"ms",""));

	pRomeCfgParam->udpblockCfgParam[ms].size=atoi(websGetVar(wp,"size",""));

	if(atoi(websGetVar(wp,"enable",""))==1)
	{	
		pRomeCfgParam->udpblockCfgParam[ms].enable=1;
	}	
	else
	{
		pRomeCfgParam->udpblockCfgParam[ms].enable=0;	
	}

	cfgmgr_write(CFGMGR_TABID_UDPBLOCK,(void*)pRomeCfgParam->udpblockCfgParam, sizeof(struct udpblockCfgParam_s)*MAX_PPPOE_SESSION);
	cfgmgr_task();

	sprintf(tmpstr,"/udpblocking.asp?ms=%d",ms);	
	udp_tableDriverAccess(ms);
	websRedirect(wp, tmpstr);

}


/************************************************************
 *	
 *	Routing Table
 *	
 ************************************************************/
int asp_routing(request * wp, int argc, char **argv)
{
	int i;
	for(i=0;i<5;i++)
	{

		websWrite(wp,
		"<tr>\n" \
		"<td bgColor=#ddeeff>\n" \
		"		<input type=text name=route%d size=15 maxlength=15 value=\"%u.%u.%u.%u\">\n" \
		"	</td>\n" \
		"	<td bgColor=#ddeeff>\n" \
		"		<input type=text name=mask%d size=15 maxlength=15 value=\"%u.%u.%u.%u\">\n" \
		"	</td>\n" \
		"    <td bgColor=#ddeeff>\n" \
		"		<input type=text name=gateway%d size=15 maxlength=15 value=\"%u.%u.%u.%u\">\n" \
		"	</td>\n" \
		"    <td bgColor=#ddeeff>\n" \
		"		<select name=interface%d><option value=0>------<option value=1 %s>LAN<option value=2 %s>WAN</select>\n" \
		"	</td>\n" \
		"</tr>\n" ,i,NIPQUAD(pRomeCfgParam->routingCfgParam[i].route)
				,i,NIPQUAD(pRomeCfgParam->routingCfgParam[i].mask)
				,i,NIPQUAD(pRomeCfgParam->routingCfgParam[i].gateway)
				,i,(pRomeCfgParam->routingCfgParam[i].interface==1)?"selected":""
				,(pRomeCfgParam->routingCfgParam[i].interface==2)?"selected":"");

	}

	return 0;
}

void asp_setRouting(request * wp, char *path, char *query)
{
	int i,ret;
	char	 tmpstr[32]={0};

	for(i=0;i<MAX_ROUTING;i++)
	{
		if(pRomeCfgParam->routingCfgParam[i].interface!=ROUTING_INTERFACE_NONE)
		{
			ret=rtl8651_delRoute((ipaddr_t)pRomeCfgParam->routingCfgParam[i].route,(ipaddr_t)pRomeCfgParam->routingCfgParam[i].mask);
			if (ret)
			{
				printf("rtl8651_delRoute(default): ret %d\n",ret);
			}
		}
	}
	

	for(i=0;i<MAX_ROUTING;i++)
	{
		ipaddr_t ip=0,ip2=0;

		sprintf(tmpstr,"mask%d",i);
		parse_ipRange(websGetVar(wp,tmpstr,""), &ip, &ip2);
		pRomeCfgParam->routingCfgParam[i].mask=ip;
		
		sprintf(tmpstr,"route%d",i);
		parse_ipRange(websGetVar(wp,tmpstr,""), &ip, &ip2);
		pRomeCfgParam->routingCfgParam[i].route=ip&pRomeCfgParam->routingCfgParam[i].mask;



		sprintf(tmpstr,"gateway%d",i);
		parse_ipRange(websGetVar(wp,tmpstr,""), &ip, &ip2);
		pRomeCfgParam->routingCfgParam[i].gateway=ip;
		
		sprintf(tmpstr,"interface%d",i);
		pRomeCfgParam->routingCfgParam[i].interface=atoi(websGetVar(wp,tmpstr,""));

		if(pRomeCfgParam->routingCfgParam[i].interface!=ROUTING_INTERFACE_NONE)
		{
			char interface[8]={0};
			if(pRomeCfgParam->routingCfgParam[i].interface==ROUTING_INTERFACE_WAN) sprintf(interface,"eth0");
			if(pRomeCfgParam->routingCfgParam[i].interface==ROUTING_INTERFACE_LAN) sprintf(interface,"eth1");
			ret=rtl8651_addRoute((ipaddr_t)pRomeCfgParam->routingCfgParam[i].route,
								  (ipaddr_t)pRomeCfgParam->routingCfgParam[i].mask,
								  (int8*)interface,(ipaddr_t)pRomeCfgParam->routingCfgParam[i].gateway);
			if (ret)
			{
				pRomeCfgParam->routingCfgParam[i].interface=ROUTING_INTERFACE_NONE;
				printf("rtl8651_addRoute %x: ret %d\n",pRomeCfgParam->routingCfgParam[i].route,ret);				
			}
		}		
	}


				
	cfgmgr_write(CFGMGR_TABID_ROUTING,(void*)pRomeCfgParam->routingCfgParam, sizeof(struct routingCfgParam_s)*MAX_ROUTING);
	cfgmgr_task();
	websRedirect(wp, "/routing.asp");
	
}

#if 0
int asp_GWFeature(request *wp, int argc, char **argv)
{
	websWrite(wp, "<tr><td><span id=\"spanHead4\" onclick=\"menu4()\">\n" \
		"<a href=\"#\"><B>Gateway Features</a><BR>\n" \
		"</span>\n" \
		"<div id=\"spanMenu4\" STYLE=\"display:none\">\n");
	
	websWrite(wp, "<table CELLSPACING=0 CELLPADDING=0>\n" \
			"<tr><td width=10></td><td><a href=\"acl.asp\" target=\"show_area\">\n" \
			"<span style=\"font-size: 12pt;\">Access Control List*</span></a></td></tr>\n" \
			"<tr><td width=10></td><td><a href=\"urlfilter.asp\" target=\"show_area\">\n" \
			"<span style=\"font-size: 12pt;\">URL Filter*</span></a></td></tr>\n" \
			"<tr><td width=10></td><td><a href=\"pseudovlan.asp\" target=\"show_area\">\n" \
			"<span style=\"font-size: 12pt;\">Pseudo-VLAN</span></a></td></tr>\n"
		);
	if (pRomeCfgParam->modeCfgParam.Mode >= RTL865XB_L3ROUTERMODE) {
		websWrite(wp, "<tr><td width=10></td><td><a href=\"qos.asp\" target=\"show_area\">\n" \
			"<span style=\"font-size: 12pt;\">Port-based QoS*</span></a></td></tr>\n" \
			"<tr><td width=10></td><td><a href=\"ratelimit.asp\" target=\"show_area\">\n" \
			"<span style=\"font-size: 12pt;\">Rate Policing QoS*</span></a></td></tr>\n" \
			"<tr><td width=10></td><td><a href=\"ratio_qos.asp\" target=\"show_area\">\n" \
			"<span style=\"font-size: 12pt;\">Guaranteed/Spare Class QoS*</span></a></td></tr>\n" \
			"<tr><td width=10></td><td><a href=\"routing.asp\" target=\"show_area\">\n" \
			"<span style=\"font-size: 12pt;\">Static Route*</span></a></div></td></tr>\n" \
			"<tr><td width=10></td><td><a href=\"rip.asp\" target=\"show_area\">\n" \
			"<span style=\"font-size: 12pt;\">RIP</span></a></div></td></tr>\n" \
			"<tr><td width=10></td><td><a href=\"ddns.asp\" target=\"show_area\">\n" \
			"<span style=\"font-size: 12pt;\">Dynamic DNS</span></a></td></tr>\n" \
			"<tr><td width=10></td><td><a href=\"udpblocking.asp\" target=\"show_area\">\n" \
			"<span style=\"font-size: 12pt;\">UDP Blocking</span></a></td></tr>\n" \
			"<tr><td width=10></td><td><a href=\"ping.asp\" target=\"show_area\">\n" \
			"<span style=\"font-size: 12pt;\">Ping toolkit</span></a></td></tr>\n" \
			"<tr><td width=10></td><td><a href=\"mcast.asp\" target=\"show_area\">\n" \
			"<span style=\"font-size: 12pt;\">IP Multicast*</span></a></td></tr>\n"
		);
	}

	if (pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L4GATEWAYMODE) {
		websWrite(wp, "<tr><td width=10></td><td><a href=\"serverp.asp\" target=\"show_area\"><span style=\"font-size: 12pt;\">\n" \
			"Virtual Server*</span></a></td></tr>\n" \
			"<tr><td width=10></td><td><a href=\"specialap.asp\" target=\"show_area\">\n" \
			"<span style=\"font-size: 12pt;\">Special Application</span></a></td></tr>\n" \
			"<tr><td width=10></td><td><a href=\"alg.asp\" target=\"show_area\">\n" \
			"<span style=\"font-size: 12pt;\">ALG</span></a></td></tr>\n" \
			"<tr><td width=10></td><td><a href=\"dmz.asp\" target=\"show_area\">\n" \
			"<span style=\"font-size: 12pt;\">DMZ Host*</span></a></td></tr>\n" \
			"<tr><td width=10></td><td><a href=\"dos.asp\" target=\"show_area\">\n" \
			"<span style=\"font-size: 12pt;\">Anti-DoS</span></a></td></tr>\n" \
			"<tr><td width=10></td><td><a href=\"pbnat.asp\" target=\"show_area\">\n" \
			"<span style=\"font-size: 12pt;\">Protocol-based NAT </span></a></td></tr>\n" \
			"<tr><td width=10></td><td><a href=\"ping.asp\" target=\"show_area\">\n" \
			"<span style=\"font-size: 12pt;\">Ping toolkit</span></a></td></tr>\n" \
			"<tr><td width=10></td><td><a href=\"naptopt.asp\" target=\"show_area\">\n" \
			"<span style=\"font-size: 12pt;\">NAPT options*</span></a></td></tr>\n" \
			"<tr><td width=10></td><td><a href=\"passthru.asp\" target=\"show_area\">\n" \
			"<span style=\"font-size:12pt;\">PPPoE/IPv6 Passthru*</span></a></td></tr>\n" \
			"<tr><td width=10></td><td><a href=\"mcast.asp\" target=\"show_area\">\n" \
			"<span style=\"font-size: 12pt;\">IP Multicast*</span></a></td></tr>\n" \
			"<tr><td width=10></td><td><a href=\"bittorrent.asp\" target=\"show_area\">\n" \
			"<span style=\"font-size: 12pt;\">BitTorrent Download</span></a></td></tr>\n" \
			);
	}
	websWrite(wp, "<tr><td colspan=2</td><span style=\"font-size: 10pt;\">*:Hardware accelereted</span></tr>\n" \
		"</table>\n" \
		);

	websWrite(wp, "</td></tr>");

	return 0;
}
#endif

/*******************************************************
*
*	Mode Selection: Gateway mode/Router mode/Bridge mode
*
********************************************************/
int asp_modeConfig(request *wp, int argc, char **argv)
{
	int mChanged = atoi(websGetVar(wp,"mChanged",""));

	if (mChanged == 1) {
		websWrite(wp, "<body bgcolor=\"#ffffff\" text=\"#000000\" onload=\"menu_reload();\">\n");
	}
	else {
		websWrite(wp, "<body bgcolor=\"#ffffff\" text=\"#000000\">\n");
	}
	

	websWrite(wp, "<form method=\"post\" action=\"/goform/asp_setModeConfig\" name=\"modeForm\">\n" \
		"<b>Operation Mode Selection</b><BR>\n" \
		"<BR>\n" \
		"<table cellSpacing=1 cellPadding=2 border=0>\n" \
		"<tr>\n" \
		"	<td bgColor=#aaddff>Mode</td>\n" \
		"	<td bgColor=#ddeeff>\n" \
		"		<select name = \"opMode\">\n" \
		"			<option value=4 %s>Gateway Mode<option value=3 %s>Router Mode<option value=2 %s>Bridge Mode\n" \
		"		</select>\n" \
		"	</td>\n" \
		"</tr>\n" \
		"<tr>\n" \
		"	<td colspan=2>\n" \
		"		<input type=submit value=\"Save\">\n" \
		"	</td>\n" \
		"</tr>\n" \
		"</table>\n" \
		"</form>\n",
		(pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L4GATEWAYMODE) ? "selected" : "",
		(pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L3ROUTERMODE) ? "selected" : "",
		(pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L2BRIDGEMODE) ? "selected" : ""
		);

		return 0;
}

/* Process mode selection: Gateway/Router/Bridge mode. */
void asp_setModeConfig(request * wp, char *path, char *query)
{
	char	*av[3];	
	char	pname[] = "/bin/ifconfig";
	int32 ret;
	uint32 tmpMode;
	char tmpstr[16]={0};
	int mChanged = 0;

	tmpMode = pRomeCfgParam->modeCfgParam.Mode;
	
	// Retrieve user configurations in the web page, and store them into the Mode "Configuration Data Structures".
	pRomeCfgParam->modeCfgParam.Mode = (uint32) atoi(websGetVar(wp, "opMode", ""));

	if (tmpMode != pRomeCfgParam->modeCfgParam.Mode) {
		mChanged = 1;
		cfgmgr_write(CFGMGR_TABID_MODE, (void*) &pRomeCfgParam->modeCfgParam, sizeof(struct modeCfgParam_s));
		cfgmgr_task();

		// protocol stack setting
		av[0] = pname;
		av[1] = "eth0";
		av[2] = "down";
		runProgram(pname,av);

		av[1] = "eth1";
		runProgram(pname,av);
		
		ret = rtl8651_tblDrvReinit();
		if (ret)
			printf("rtl8651_tblDrvReinit: ret %d\n", ret);

		ret = rtl8651_fwdEngineReinit();
		if (ret)
			printf("rtl8651_fwdEngineReinit: ret %d\n", ret);
#if 0
		if (pRomeCfgParam->modeCfgParam.Mode == RTL865XB_L2BRIDGEMODE) {
			ret = rtl8651_fwdEngineDropPktCase(FWDENG_ARP_OTHERS, &trueFlag);
			if (ret)
				printf("rtl8651_fwdEngineDropPktCase: ret %d", ret);
		}
#endif
		sysInit();
	}

	sprintf(tmpstr,	"/mgmt.asp?mChanged=%d", mChanged);
	websRedirect(wp, tmpstr);
	

}
/*************************************************
*
*	RIP Configuration
*
**************************************************/
int asp_RipConfig(request * wp, int argc, char **argv)
{
	websWrite(wp, "<b>RIP Configuration</b><BR>\n" \
		"<form method=\"post\" action=\"/goform/asp_setRipConfig\">\n");
	
	websWrite(wp,
		"<table cellSpacing=1 cellPadding=2 border=0>\n" \
		"<tr><td><b>WAN</b></td></tr>\n" \
		"<br>\n" \
		"<tr><td bgColor=#aaddff>  send version  </td><td bgColor=#aaddff>  receive version  </td><td bgColor=#aaddff>  enable passwd authentication  </td></tr>\n" \
		"<tr>\n" \
		"	<td bgColor=#ddeeff>\n" \
		"		<select name=send_eth0><option value=0 %s>1&2<option value=1 %s>1<option value=2 %s>2</select>\n" \
		"	</td>\n" \
		"	<td bgColor=#ddeeff>\n"\
		"		<select name=rcv_eth0><option value=0 %s>1&2<option value=1 %s>1<option value=2 %s>2</select>\n" \
		"	</td>\n" \
		"	<td bgColor=#ddeeff> \n" \
		"		Enable: <input type=checkbox name=auth_eth0 value=1 %s>\n" \
		"		Password: <input type=password name=pass_eth0 size=16>\n" \
		"	</td>\n" \
		"</tr>\n" \
		"</table>\n",
		(pRomeCfgParam->ripCfgParam.send_eth0==0)?"selected":"",
		(pRomeCfgParam->ripCfgParam.send_eth0==1)?"selected":"",
		(pRomeCfgParam->ripCfgParam.send_eth0==2)?"selected":"",
		(pRomeCfgParam->ripCfgParam.rcv_eth0==0)?"selected":"",
		(pRomeCfgParam->ripCfgParam.rcv_eth0==1)?"selected":"",
		(pRomeCfgParam->ripCfgParam.rcv_eth0==2)?"selected":"",
		(pRomeCfgParam->ripCfgParam.auth_eth0==1)?"checked":""
		);

	websWrite(wp,
		"<table cellSpacing=1 cellPadding=2 border=0>\n" \
		"<tr><td><b>LAN</b></td></tr>\n"\
		"<br>\n"\
		"<tr><td bgColor=#aaddff>  send version  </td><td bgColor=#aaddff>  receive version  </td><td bgColor=#aaddff>  enable passwd authentication  </td></tr>\n"\
		"<tr>\n"\
		"	<td bgColor=#ddeeff>\n"\
		"		<select name=send_eth1><option value=0 %s>1&2<option value=1 %s>1<option value=2 %s>2</select>\n"\
		"	</td>\n"\
		"	<td bgColor=#ddeeff>\n"\
		"		<select name=rcv_eth1><option value=0 %s>1&2<option value=1 %s>1<option value=2 %s>2</select>\n"\
		"	</td>\n"\
		"	<td bgColor=#ddeeff> \n" \
		"		Enable: <input type=checkbox name=auth_eth1 value=1 %s>\n" \
		"		Password: <input type=password name=pass_eth1 size=16>\n" \
		"	</td>\n" \
		"</tr>\n" \
		"</table>\n",
		(pRomeCfgParam->ripCfgParam.send_eth1==0)?"selected":"",
		(pRomeCfgParam->ripCfgParam.send_eth1==1)?"selected":"",
		(pRomeCfgParam->ripCfgParam.send_eth1==2)?"selected":"",
		(pRomeCfgParam->ripCfgParam.rcv_eth1==0)?"selected":"",
		(pRomeCfgParam->ripCfgParam.rcv_eth1==1)?"selected":"",
		(pRomeCfgParam->ripCfgParam.rcv_eth1==2)?"selected":"",
		(pRomeCfgParam->ripCfgParam.auth_eth1==1)?"checked":""
		);
	websWrite(wp,
		"<table cellSpacing=1 cellPadding=2 border=0>\n" \
		"<tr><td><b>RIP setting</b></td></tr>\n"\
		"<br>\n"\
		"<tr><td bgColor=#aaddff>  update timer  </td><td bgColor=#aaddff>  timeout timer  </td><td bgColor=#aaddff>  garbage timer  </td></tr>\n"\
		"<tr>\n"\
		"	<td bgColor=#ddeeff>\n"\
		"		<input type=text name=update_tr size=6 maxlength=6 value=%d>\n"\
		"	</td>\n"\
		"	<td bgColor=#ddeeff>\n"\
		"		<input type=text name=timeout_tr size=6 maxlength=6 value=%d>\n"\
		"	</td>\n"\
		"	<td bgColor=#ddeeff>\n"\
		"		<input type=text name=garbage_tr size=6 maxlength=6 value=%d>\n"\
		"	</td>\n"\
		"</tr>\n" \
		"</table>\n",
		pRomeCfgParam->ripCfgParam.update_tr,
		pRomeCfgParam->ripCfgParam.timeout_tr,
		pRomeCfgParam->ripCfgParam.garbage_tr
		);

	websWrite(wp,
		"<table cellSpacing=1 cellPadding=2 border=0>\n" \
		"<tr>\n" \
		"<td colspan=4 align=center><input type=submit value=Save>&nbsp;&nbsp;<input type=reset value=Reset></td>\n" \
		"</tr>\n" \
		"</table>\n" \
		"</form>\n");

}

/* Process RIP user settings in the web page */
void asp_setRipConfig(request * wp, char *path, char *query)
{
	// Retrieve user configurations in the web page, and store them into the RIP "Configuration Data Structures".

	pRomeCfgParam->ripCfgParam.send_eth0 = atoi(websGetVar(wp,"send_eth0",""));
	pRomeCfgParam->ripCfgParam.rcv_eth0 = atoi(websGetVar(wp,"rcv_eth0",""));
	pRomeCfgParam->ripCfgParam.auth_eth0 = atoi(websGetVar(wp,"auth_eth0",""));
	strncpy(pRomeCfgParam->ripCfgParam.pass_eth0, websGetVar(wp,"pass_eth0",""), (sizeof(pRomeCfgParam->ripCfgParam.pass_eth0) - 1));

	pRomeCfgParam->ripCfgParam.send_eth1 = atoi(websGetVar(wp,"send_eth1",""));
	pRomeCfgParam->ripCfgParam.rcv_eth1 = atoi(websGetVar(wp,"rcv_eth1",""));
	pRomeCfgParam->ripCfgParam.auth_eth1 = atoi(websGetVar(wp,"auth_eth1",""));
	strncpy(pRomeCfgParam->ripCfgParam.pass_eth1, websGetVar(wp,"pass_eth1",""), (sizeof(pRomeCfgParam->ripCfgParam.pass_eth1) - 1));
	pRomeCfgParam->ripCfgParam.update_tr = atoi(websGetVar(wp,"update_tr",""));
	pRomeCfgParam->ripCfgParam.timeout_tr = atoi(websGetVar(wp,"timeout_tr",""));
	pRomeCfgParam->ripCfgParam.garbage_tr = atoi(websGetVar(wp,"garbage_tr",""));

	// Write "Configuration Data Structure" into the FLASH.
	cfgmgr_write(CFGMGR_TABID_RIP,(void*)&pRomeCfgParam->ripCfgParam, sizeof(struct ripCfgParam_s));
	cfgmgr_task();

	//Re-create "/var/zebra" & "/var/ripd". First creation of these files are in 'rip_init()' of 'board.c'.
	if(CreateRipCfgFile())
		printf("asp_setRipConfig: create rip cfg file fail\n");

	//Ask RIPD to reload configuration file "ripd.conf".
	send_signal("/var/run/ripd.pid", SIGHUP);
	websRedirect(wp, "/rip.asp");
}


int asp_qos(request * wp, int argc, char **argv)
{
	char *tagName[] = { "telnet_switch", "http_switch", "pop3_switch", "smtp_switch", "specific_1", "specific_2", "specific_3" };
	char *labelName[] = { "TELNET", "HTTP", "POP3", "SMTP", "port_1", "	port_2", "port_3" };
	char *string_0[] = { "Port 0", "Port 1", "Port 2", "Port 3", "Port 4" };
	char *string_1[] = { "pq_priority_0", "pq_priority_1", "pq_priority_2", "pq_priority_3", "pq_priority_4" };
	char *string_2[] = { "pq_flowctl_0", "pq_flowctl_1", "pq_flowctl_2", "pq_flowctl_3", "pq_flowctl_4" };
	char *string_3[] = { "pq_inrl_0", "pq_inrl_1", "pq_inrl_2", "pq_inrl_3", "pq_inrl_4" };
	char *string_4[] = { "pq_outrl_0", "pq_outrl_1", "pq_outrl_2", "pq_outrl_3", "pq_outrl_4" };
	int index;	
	char chipName[16] = {0};
	int32 chipRevId = 0;
	rtl8651_getChipVersion(chipName, sizeof(chipName), &chipRevId);
	
	/* Application-Based QoS */
	websWrite(wp,
		"<form method=\"get\" action=\"/goform/asp_setQos\" name=qosform1>\n"\
		"<tr><td><b>Hardware QoS by Application</b></td></tr>\n"\
		"<br>\n"\
		"<td bgColor=#ddeeff><input type=checkbox name=ab_switch %s value=1 onClick=\"itemSwitch1();\">Enable</td>\n"\
		"<table cellSpacing=1 cellPadding=2 border=0>\n"\
		"<tr><td bgColor=#aaddff>  Protocol  </td><td bgColor=#aaddff>  High Priority  </td><td bgColor=#aaddff>  Low Priority  </td></tr>\n",
		((pRomeCfgParam->qosCfgParam[0].qosType&ENABLE_QOS)? "checked": "")
	);
	
	
	for(index=0; index<4; index++) {
		websWrite(wp,
			"<tr>\n"\
			"<td bgColor=#ddeeff>%s</td>\n"\
			"<td bgColor=#ddeeff><input type=radio name=%s value=high %s></td>\n"\
			"<td bgColor=#ddeeff><input type=radio name=%s value=low %s></td>\n"\
			"</tr>\n", 
			labelName[index], 
			tagName[index], ((pRomeCfgParam->qosCfgParam[index].un.policy_based.isHigh==TRUE)? "checked": " "),
			tagName[index], ((pRomeCfgParam->qosCfgParam[index].un.policy_based.isHigh==FALSE)? "checked": " ")
		);
	}

	websWrite(wp, "<tr><td bgColor=#aaddff>  Specific Port#  </td><td bgColor=#aaddff>  High Priority  </td><td bgColor=#aaddff>  Low Priority  </td></tr>\n");

	for(index=4; index<7; index++) {
		websWrite(wp,
			"<tr>\n"\
			"<td bgColor=#ddeeff><input type=text name=%s size = 5 maxlength=5 enable value=%d></td>\n"\
			"<td bgColor=#ddeeff><input type=radio name=%s value=high %s></td>\n"\
			"<td bgColor=#ddeeff><input type=radio name=%s value=low %s></td>\n",
			labelName[index], pRomeCfgParam->qosCfgParam[index].un.policy_based.portNumber,
			tagName[index],   ((pRomeCfgParam->qosCfgParam[index].un.policy_based.isHigh==TRUE)? "checked": " "),
			tagName[index],  ((pRomeCfgParam->qosCfgParam[index].un.policy_based.isHigh==FALSE)? "checked": " ")
		);
	}
	
	websWrite(wp,
		"<tr>\n"\
		"<td colspan=2 align=center>\n"\
		"<input type=submit value=Apply>\n"\
		"<input type=reset value=Reset>\n"\
		"</td>\n"\
	   	"</tr>\n"\
	   	"</table> </form>\n"
	 );



	/* Port-Based QoS */
	websWrite(wp,
		"<form method=\"get\" action=\"/goform/asp_setQos1\" name=qosform2>\n"\
		"<tr><td><b>Hardware QoS by device port number</b></td></tr>\n"\
		"<br>\n"\
		"<td bgColor=#ddeeff><input type=checkbox name=ab_switch %s value=1 onClick=\"itemSwitch2();\">Enable</td>\n"\
		"<table cellSpacing=1 cellPadding=2 border=0>\n"\
		"<tr>\n"\
		"<td bgColor=#aaddff>  Port #  </td>\n"\
		"<td bgColor=#aaddff>  Flow Control  </td>\n"\
		"<td bgColor=#aaddff>  Incoming Rate Limit </td>\n"\
		"<td bgColor=#aaddff>  Outgoing Rate Limit </td>\n"\
		"<td bgColor=#aaddff>  Port-Based Priority  </td>\n"\
		"</tr>",
		((pRomeCfgParam->qosCfgParam[7].qosType&ENABLE_QOS)? "checked": "")
	);

	
	for(index=7; index<MAX_QOS; index++) {
		/* After RTL865xB c-cut, 64Mbps bandwidth control is provided. */
		if(chipName[strlen(chipName) - 1] == 'B' && chipRevId >= 0x02) {
			websWrite(wp,
				"<tr>\n"\
				"<td bgColor=#ddeeff>%s</td>\n"\
				"<td bgColor=#ddeeff><select name=%s><option %s>Enable<option %s>Disable</select></td>\n"\
				"<td bgColor=#ddeeff>\n"\
				"<select name=%s>\n"\
				"<option %s>Full\n"\
				"<option %s>64M<option %s>32M<option %s>16M<option %s>8M<option %s>4M<option %s>2M<option %s>1M<option %s>512K<option %s>256K<option %s>128K\n"\
				"</select>\n"\
				"</td>\n"\
				"<td bgColor=#ddeeff>\n"\
				"<select name=%s>\n"\
				"<option %s>Full<option %s>64M<option %s>32M<option %s>16M<option %s>8M<option %s>4M<option %s>2M<option %s>1M	<option %s>512K<option %s>256K<option %s>128K\n"\
				"</select>\n"\
				"</td>\n"\
				"<td bgColor=#ddeeff><select name=%s><option %s>High<option %s>Low</select></td>\n"\
				"</tr>\n",
				string_0[index-7], 
				string_2[index-7], ((pRomeCfgParam->qosCfgParam[index].un.port_based.enableFlowCtrl==TRUE)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.enableFlowCtrl==FALSE)? "selected": " "),
				string_3[index-7], ((pRomeCfgParam->qosCfgParam[index].un.port_based.inRL==RTL8651_BC_FULL)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.inRL==RTL8651_BC_64M)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.inRL==RTL8651_BC_32M)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.inRL==RTL8651_BC_16M)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.inRL==RTL8651_BC_8M)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.inRL==RTL8651_BC_4M)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.inRL==RTL8651_BC_2M)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.inRL==RTL8651_BC_1M)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.inRL==RTL8651_BC_512K)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.inRL==RTL8651_BC_256K)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.inRL==RTL8651_BC_128K)? "selected": " "),
				string_4[index-7],  ((pRomeCfgParam->qosCfgParam[index].un.port_based.outRL==RTL8651_BC_FULL)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.outRL==RTL8651_BC_64M)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.outRL==RTL8651_BC_32M)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.outRL==RTL8651_BC_16M)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.outRL==RTL8651_BC_8M)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.outRL==RTL8651_BC_4M)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.outRL==RTL8651_BC_2M)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.outRL==RTL8651_BC_1M)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.outRL==RTL8651_BC_512K)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.outRL==RTL8651_BC_256K)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.outRL==RTL8651_BC_128K)? "selected": " "),
				string_1[index-7], ((pRomeCfgParam->qosCfgParam[index].un.port_based.isHigh==TRUE)? "selected": " "), 
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.isHigh==FALSE)? "selected": " ")
			);

		}
		else {
			websWrite(wp,
				"<tr>\n"\
				"<td bgColor=#ddeeff>%s</td>\n"\
				"<td bgColor=#ddeeff><select name=%s><option %s>Enable<option %s>Disable</select></td>\n"\
				"<td bgColor=#ddeeff>\n"\
				"<select name=%s>\n"\
				"<option %s>Full\n"\
				"<option %s>32M<option %s>16M<option %s>8M<option %s>4M<option %s>2M<option %s>1M<option %s>512K<option %s>256K<option %s>128K\n"\
				"</select>\n"\
				"</td>\n"\
				"<td bgColor=#ddeeff>\n"\
				"<select name=%s>\n"\
				"<option %s>Full<option %s>32M<option %s>16M<option %s>8M<option %s>4M<option %s>2M<option %s>1M	<option %s>512K<option %s>256K<option %s>128K\n"\
				"</select>\n"\
				"</td>\n"\
				"<td bgColor=#ddeeff><select name=%s><option %s>High<option %s>Low</select></td>\n"\
				"</tr>\n",
				string_0[index-7], 
				string_2[index-7], ((pRomeCfgParam->qosCfgParam[index].un.port_based.enableFlowCtrl==TRUE)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.enableFlowCtrl==FALSE)? "selected": " "),
				string_3[index-7], ((pRomeCfgParam->qosCfgParam[index].un.port_based.inRL==RTL8651_BC_FULL)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.inRL==RTL8651_BC_32M)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.inRL==RTL8651_BC_16M)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.inRL==RTL8651_BC_8M)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.inRL==RTL8651_BC_4M)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.inRL==RTL8651_BC_2M)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.inRL==RTL8651_BC_1M)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.inRL==RTL8651_BC_512K)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.inRL==RTL8651_BC_256K)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.inRL==RTL8651_BC_128K)? "selected": " "),
				string_4[index-7],  ((pRomeCfgParam->qosCfgParam[index].un.port_based.outRL==RTL8651_BC_FULL)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.outRL==RTL8651_BC_32M)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.outRL==RTL8651_BC_16M)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.outRL==RTL8651_BC_8M)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.outRL==RTL8651_BC_4M)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.outRL==RTL8651_BC_2M)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.outRL==RTL8651_BC_1M)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.outRL==RTL8651_BC_512K)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.outRL==RTL8651_BC_256K)? "selected": " "),
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.outRL==RTL8651_BC_128K)? "selected": " "),
				string_1[index-7], ((pRomeCfgParam->qosCfgParam[index].un.port_based.isHigh==TRUE)? "selected": " "), 
							      ((pRomeCfgParam->qosCfgParam[index].un.port_based.isHigh==FALSE)? "selected": " ")
			);
		}
	}


	websWrite(wp,
		"<tr>\n"\
		"<td colspan=2 align=center>\n"\
		"<input type=submit value=Apply>\n"\
		"<input type=reset value=Reset>\n"\
		"</td>\n"\
	   	"</tr>\n"\
		"</table>\n"\
		"</form>\n"
	);

}

void asp_setQos(request * wp, char *path, char *query)
{
	{
		char *tagName[] = { "telnet_switch", "http_switch", "pop3_switch", "smtp_switch", "specific_1", "specific_2", "specific_3" };
		char *spec[] = { "port_1", "port_2", "port_3" };
		rtl8651_tblDrvPolicy_t policy;
		char *str;
		int index;

		str = websGetVar(wp,"ab_switch","");
		if (strcmp(str, "1") == 0) {
			pRomeCfgParam->qosCfgParam[0].qosType |= ENABLE_QOS;
			rtl8651_flushPolicyBasedQoS();
			for(index=0; index<7; index++) {
				str = websGetVar(wp,T(tagName[index])," ");
				if (strcmp(str, "low") == 0)
					pRomeCfgParam->qosCfgParam[index].un.policy_based.isHigh = FALSE;
				else pRomeCfgParam->qosCfgParam[index].un.policy_based.isHigh = TRUE;
				if (index > 3) {
					pRomeCfgParam->qosCfgParam[index].un.policy_based.portNumber = atoi(websGetVar(wp, spec[index-4], " "));
				}
				if (pRomeCfgParam->qosCfgParam[index].un.policy_based.portNumber != 0) {
					bzero(&policy, sizeof(rtl8651_tblDrvPolicy_t));
					policy.proto = RTL8651_POLICY_TCP;
					//Server is in the WAN
					policy.dport_start = 0; policy.dport_end = 0xffff;
					policy.sport_start = policy.sport_end = pRomeCfgParam->qosCfgParam[index].un.policy_based.portNumber;
					rtl8651_addPolicyBasedQoS("eth0", &policy, pRomeCfgParam->qosCfgParam[index].un.policy_based.isHigh);
					//Server is in the LAN
					policy.sport_start = 0; policy.sport_end = 0xffff;
					policy.dport_start = policy.dport_end = pRomeCfgParam->qosCfgParam[index].un.policy_based.portNumber;
					rtl8651_addPolicyBasedQoS("eth0", &policy, pRomeCfgParam->qosCfgParam[index].un.policy_based.isHigh);

					bzero(&policy, sizeof(rtl8651_tblDrvPolicy_t));
					policy.proto = RTL8651_POLICY_TCP;
					//Server is in the WAN
					policy.sport_start = 0; policy.sport_end = 0xffff;
					policy.dport_start = policy.dport_end = pRomeCfgParam->qosCfgParam[index].un.policy_based.portNumber;
					rtl8651_addPolicyBasedQoS("eth1", &policy, pRomeCfgParam->qosCfgParam[index].un.policy_based.isHigh);
					//Server is in the LAN
					policy.dport_start = 0; policy.dport_end = 0xffff;
					policy.sport_start = policy.sport_end = pRomeCfgParam->qosCfgParam[index].un.policy_based.portNumber;
					rtl8651_addPolicyBasedQoS("eth1", &policy, pRomeCfgParam->qosCfgParam[index].un.policy_based.isHigh);

					if (index > 3) {
						bzero(&policy, sizeof(rtl8651_tblDrvPolicy_t));
						policy.proto = RTL8651_POLICY_UDP;
						//Server is in the WAN
						policy.dport_start = 0; policy.dport_end = 0xffff;
						policy.sport_start = policy.sport_end = pRomeCfgParam->qosCfgParam[index].un.policy_based.portNumber;
						rtl8651_addPolicyBasedQoS("eth0", &policy, pRomeCfgParam->qosCfgParam[index].un.policy_based.isHigh);
						//Server is in the LAN
						policy.sport_start = 0; policy.sport_end = 0xffff;
						policy.dport_start = policy.dport_end = pRomeCfgParam->qosCfgParam[index].un.policy_based.portNumber;
						rtl8651_addPolicyBasedQoS("eth0", &policy, pRomeCfgParam->qosCfgParam[index].un.policy_based.isHigh);

						bzero(&policy, sizeof(rtl8651_tblDrvPolicy_t));
						policy.proto = RTL8651_POLICY_UDP;
						//Server is in the WAN
						policy.sport_start = 0; policy.sport_end = 0xffff;
						policy.dport_start = policy.dport_end = pRomeCfgParam->qosCfgParam[index].un.policy_based.portNumber;
						rtl8651_addPolicyBasedQoS("eth1", &policy, pRomeCfgParam->qosCfgParam[index].un.policy_based.isHigh);
						//Server is in the LAN
						policy.dport_start = 0; policy.dport_end = 0xffff;
						policy.sport_start = policy.sport_end = pRomeCfgParam->qosCfgParam[index].un.policy_based.portNumber;
						rtl8651_addPolicyBasedQoS("eth1", &policy, pRomeCfgParam->qosCfgParam[index].un.policy_based.isHigh);


					}
				}
			}
		}
		else {
			pRomeCfgParam->qosCfgParam[0].qosType &= ~ENABLE_QOS;
			rtl8651_flushPolicyBasedQoS();
		}
		
		cfgmgr_write(CFGMGR_TABID_QOS,(void*)pRomeCfgParam->qosCfgParam, sizeof(struct qosCfgParam_s)*MAX_QOS);
		cfgmgr_task();
		websRedirect(wp, "/qos.asp");
	}
}



void asp_setQos1(request * wp, char *path, char *query)
{
	char *string_1[] = { "pq_priority_0", "pq_priority_1", "pq_priority_2", "pq_priority_3", "pq_priority_4" };
	char *string_2[] = { "pq_flowctl_0", "pq_flowctl_1", "pq_flowctl_2", "pq_flowctl_3", "pq_flowctl_4" };
	char *string_3[] = { "pq_inrl_0", "pq_inrl_1", "pq_inrl_2", "pq_inrl_3", "pq_inrl_4" };
	char *string_4[] = { "pq_outrl_0", "pq_outrl_1", "pq_outrl_2", "pq_outrl_3", "pq_outrl_4" };
	int index;
	char *str;
	uint32 newInputRate, newOutputRate;
	char chipName[16] = {0};
	int32 chipRevId = 0;
	rtl8651_getChipVersion(chipName, sizeof(chipName), &chipRevId);

	str = websGetVar(wp,"ab_switch","");
	if (strcmp(str, "1") == 0) {
		pRomeCfgParam->qosCfgParam[7].qosType |= ENABLE_QOS;
		for(index=0; index<5; index++) {
			str = websGetVar(wp,T(string_1[index])," ");
			if (strcmp(str, "Low") == 0) 
				pRomeCfgParam->qosCfgParam[index+7].un.port_based.isHigh = FALSE;
			else pRomeCfgParam->qosCfgParam[index+7].un.port_based.isHigh = TRUE;
			rtl8651_setPortPriorityQueue(index, pRomeCfgParam->qosCfgParam[index+7].un.port_based.isHigh);

			str = websGetVar(wp, T(string_2[index]), " ");
			if (strcmp(str, "Disable") == 0)
				pRomeCfgParam->qosCfgParam[index+7].un.port_based.enableFlowCtrl = FALSE;
			else pRomeCfgParam->qosCfgParam[index+7].un.port_based.enableFlowCtrl = TRUE;
			rtl8651_setFlowControl(index, pRomeCfgParam->qosCfgParam[index+7].un.port_based.enableFlowCtrl);

			str = websGetVar(wp, T(string_3[index]), " ");

			/* After RTL865xB c-cut, 64Mbps bandwidth control is provided. */
			if(chipName[strlen(chipName) - 1] == 'B' && chipRevId >= 0x02) {
				if (strcmp(str, "Full") == 0)
					newInputRate = RTL8651_BC_FULL;
				else if (strcmp(str, "64M") == 0)
					newInputRate= RTL8651_BC_64M;
				else if (strcmp(str, "32M") == 0)
					newInputRate= RTL8651_BC_32M;
				else if (strcmp(str, "16M") == 0)
					newInputRate= RTL8651_BC_16M;
				else if (strcmp(str, "8M") == 0)
					newInputRate= RTL8651_BC_8M;
				else if (strcmp(str, "4M") == 0)
					newInputRate= RTL8651_BC_4M;
				else if (strcmp(str, "2M") == 0)
					newInputRate = RTL8651_BC_2M;
				else if (strcmp(str, "1M") == 0)
					newInputRate= RTL8651_BC_1M;
				else if (strcmp(str, "512K") == 0)
					newInputRate = RTL8651_BC_512K;
				else if (strcmp(str, "256K") == 0)
					newInputRate = RTL8651_BC_256K;
				else 	newInputRate = RTL8651_BC_128K;
			}
			else {
				if (strcmp(str, "Full") == 0)
					newInputRate = RTL8651_BC_FULL;
				else if (strcmp(str, "32M") == 0)
					newInputRate= RTL8651_BC_32M;
				else if (strcmp(str, "16M") == 0)
					newInputRate= RTL8651_BC_16M;
				else if (strcmp(str, "8M") == 0)
					newInputRate= RTL8651_BC_8M;
				else if (strcmp(str, "4M") == 0)
					newInputRate= RTL8651_BC_4M;
				else if (strcmp(str, "2M") == 0)
					newInputRate = RTL8651_BC_2M;
				else if (strcmp(str, "1M") == 0)
					newInputRate= RTL8651_BC_1M;
				else if (strcmp(str, "512K") == 0)
					newInputRate = RTL8651_BC_512K;
				else if (strcmp(str, "256K") == 0)
					newInputRate = RTL8651_BC_256K;
				else 	newInputRate = RTL8651_BC_128K;
			}
			if(rtl8651_setEthernetPortBandwidthControl(index, TRUE, newInputRate) == SUCCESS)
				pRomeCfgParam->qosCfgParam[index+7].un.port_based.inRL = newInputRate;

			str = websGetVar(wp, T(string_4[index]), " ");

			/* After RTL865xB c-cut, 64Mbps bandwidth control is provided. */
			if(chipName[strlen(chipName) - 1] == 'B' && chipRevId >= 0x02) {
				if (strcmp(str, "Full") == 0)
					newOutputRate= RTL8651_BC_FULL;
				else if (strcmp(str, "64M") == 0)
					newOutputRate= RTL8651_BC_64M;
				else if (strcmp(str, "32M") == 0)
					newOutputRate= RTL8651_BC_32M;
				else if (strcmp(str, "16M") == 0)
					newOutputRate= RTL8651_BC_16M;
				else if (strcmp(str, "8M") == 0)
					newOutputRate= RTL8651_BC_8M;
				else if (strcmp(str, "4M") == 0)
					newOutputRate= RTL8651_BC_4M;
				else if (strcmp(str, "2M") == 0)
					newOutputRate= RTL8651_BC_2M;
				else if (strcmp(str, "1M") == 0)
					newOutputRate= RTL8651_BC_1M;
				else if (strcmp(str, "512K") == 0)
					newOutputRate= RTL8651_BC_512K;
				else if (strcmp(str, "256K") == 0)
					newOutputRate= RTL8651_BC_256K;
				else 	newOutputRate = RTL8651_BC_128K;
			}
			else {
				if (strcmp(str, "Full") == 0)
					newOutputRate= RTL8651_BC_FULL;
				else if (strcmp(str, "32M") == 0)
					newOutputRate= RTL8651_BC_32M;
				else if (strcmp(str, "16M") == 0)
					newOutputRate= RTL8651_BC_16M;
				else if (strcmp(str, "8M") == 0)
					newOutputRate= RTL8651_BC_8M;
				else if (strcmp(str, "4M") == 0)
					newOutputRate= RTL8651_BC_4M;
				else if (strcmp(str, "2M") == 0)
					newOutputRate= RTL8651_BC_2M;
				else if (strcmp(str, "1M") == 0)
					newOutputRate= RTL8651_BC_1M;
				else if (strcmp(str, "512K") == 0)
					newOutputRate= RTL8651_BC_512K;
				else if (strcmp(str, "256K") == 0)
					newOutputRate= RTL8651_BC_256K;
				else 	newOutputRate = RTL8651_BC_128K;
			}
			if(rtl8651_setEthernetPortBandwidthControl(index, FALSE, newOutputRate) == SUCCESS)
				pRomeCfgParam->qosCfgParam[index+7].un.port_based.outRL = newOutputRate;
		}
	}
	else {
		pRomeCfgParam->qosCfgParam[7].qosType &= ~ENABLE_QOS;

		for(index=0; index<5; index++) {
			rtl8651_setFlowControl(index, TRUE);
			rtl8651_setPortPriorityQueue(index, FALSE);
			rtl8651_setEthernetPortBandwidthControl(index, TRUE, RTL8651_BC_FULL);
			rtl8651_setEthernetPortBandwidthControl(index, FALSE, RTL8651_BC_FULL);
		}
	}
	
	cfgmgr_write(CFGMGR_TABID_QOS,(void*)pRomeCfgParam->qosCfgParam, sizeof(struct qosCfgParam_s)*MAX_QOS);
	cfgmgr_task();
	websRedirect(wp, "/qos.asp");
}


int asp_pseudovlan(request * wp, int argc, char **argv)
{
	uint32 port, startVid;

	if (pRomeCfgParam->vlanCfgParam[0].vid > pRomeCfgParam->vlanCfgParam[1].vid)
		startVid = pRomeCfgParam->vlanCfgParam[0].vid+1;
	else startVid = pRomeCfgParam->vlanCfgParam[1].vid+1;

	websWrite(wp,
		"<form method=\"get\" action=\"/goform/asp_setpseudovlan\" name=pseudovlanform>\n"\
		"<tr><td><b>Pseudo VLAN</b></td></tr>\n"\
		"<br>\n"\
		"<td bgColor=#ddeeff><input type=checkbox name=isEnable %s value=1 onClick=\"itemSwitch();\">Enable</td>\n"\
		"<table cellSpacing=1 cellPadding=2 border=0>\n"\
		"<tr><td bgColor=#aaddff>Port#</td><td bgColor=#aaddff>WAN/LAN</td><td bgColor=#aaddff>VLAN ID</td><td bgColor=#aaddff>Pseudo VLAN</td></tr>\n",
		((pRomeCfgParam->pseudoVlanCfgParam.enable==TRUE)? "checked": "")
	);

	for(port=0; port<RTL8651_PORT_NUMBER; port++) {
		websWrite(wp,
			"<tr>\n"\
			"<td bgColor=#ddeeff>Port %d</td>\n"\
			"<td bgColor=#ddeeff>%s</td>\n"\
			"<td bgColor=#ddeeff>%d</td>\n"\
			"<td bgColor=#ddeeff><select name=status%d><option %s>None<option %s>subVlan1<option %s>subVlan2<option %s>subVlan3<option %s>subVlan4<option %s>subVlan5<option %s>subVlan6</selected>\n"\
			"</tr>\n", 
			port, 
			((pRomeCfgParam->vlanCfgParam[0].memberPort & (1<<port))? "WAN": "LAN"),
			((pRomeCfgParam->vlanCfgParam[0].memberPort & (1<<port))? pRomeCfgParam->vlanCfgParam[0].vid: pRomeCfgParam->vlanCfgParam[1].vid),
			port,
			((pRomeCfgParam->pseudoVlanCfgParam.portVid[port]==0)? "selected": ""),
			((pRomeCfgParam->pseudoVlanCfgParam.portVid[port]==startVid)? "selected": ""),
			((pRomeCfgParam->pseudoVlanCfgParam.portVid[port]==startVid+1)? "selected": ""),
			((pRomeCfgParam->pseudoVlanCfgParam.portVid[port]==startVid+2)? "selected": ""),
			((pRomeCfgParam->pseudoVlanCfgParam.portVid[port]==startVid+3)? "selected": ""),
			((pRomeCfgParam->pseudoVlanCfgParam.portVid[port]==startVid+4)? "selected": ""),
			((pRomeCfgParam->pseudoVlanCfgParam.portVid[port]==startVid+5)? "selected": "")
		);
	}

	websWrite(wp,
		"<tr>\n"\
		"<td colspan=2 align=center>\n"\
		"<input type=submit value=Apply>\n"\
		"<input type=reset value=Reset>\n"\
		"</td>\n"\
	   	"</tr>\n"\
	   	"</table> </form>\n"
	 );
	return 0;
}

void asp_setpseudovlan(request * wp, char *path, char *query)
{
	int8 *tagName[] = { "status0", "status1", "status2", "status3", "status4", "status5" };
	char *str;
	uint32 port, startVid, subVlan[6] = { 0 }, i;

	if (pRomeCfgParam->vlanCfgParam[0].vid > pRomeCfgParam->vlanCfgParam[1].vid)
		startVid = pRomeCfgParam->vlanCfgParam[0].vid+1;
	else startVid = pRomeCfgParam->vlanCfgParam[1].vid+1;

	str = websGetVar(wp,"isEnable","");
	if (strcmp(str, "1") == 0) {
		pRomeCfgParam->pseudoVlanCfgParam.enable = TRUE;
		for(port=0; port<RTL8651_PORT_NUMBER; port++) {
			if (pRomeCfgParam->pseudoVlanCfgParam.portVid[port] != 0)
				rtl8651_delSubVlan(pRomeCfgParam->pseudoVlanCfgParam.portVid[port]);
		}
		for(port=0; port<RTL8651_PORT_NUMBER; port++) {
			str = websGetVar(wp,T(tagName[port])," ");
			if (strcmp(str, "subVlan1") == 0) {
				pRomeCfgParam->pseudoVlanCfgParam.portVid[port] = startVid;
				subVlan[0] |= (1<<port);
			} 
			else if (strcmp(str, "subVlan2") == 0) {
				pRomeCfgParam->pseudoVlanCfgParam.portVid[port] = startVid + 1;
				subVlan[1] |= (1<<port);
			}
			else if (strcmp(str, "subVlan3") == 0) {
				pRomeCfgParam->pseudoVlanCfgParam.portVid[port] = startVid + 2;
				subVlan[2] |= (1<<port);
			}
			else if (strcmp(str, "subVlan4") == 0) {
				pRomeCfgParam->pseudoVlanCfgParam.portVid[port] = startVid + 3;
				subVlan[3] |= (1<<port);
			}
			else if (strcmp(str, "subVlan5") == 0) {
				pRomeCfgParam->pseudoVlanCfgParam.portVid[port] = startVid + 4;
				subVlan[4] |= (1<<port);
			}
			else if (strcmp(str, "subVlan6") == 0) {
				pRomeCfgParam->pseudoVlanCfgParam.portVid[port] = startVid + 5;
				subVlan[5] |= (1<<port);
			}
			else pRomeCfgParam->pseudoVlanCfgParam.portVid[port] = 0;
		}
		for(i=0; i<6; i++) {
			if (subVlan[i] != 0)
				rtl8651_addSubVlan(pRomeCfgParam->vlanCfgParam[1].vid, i+startVid, subVlan[i]);
		}
	}
	else {
		pRomeCfgParam->pseudoVlanCfgParam.enable = FALSE;
		for(port=0; port<RTL8651_PORT_NUMBER; port++) {
			if (pRomeCfgParam->pseudoVlanCfgParam.portVid[port] != 0)
				rtl8651_delSubVlan(pRomeCfgParam->pseudoVlanCfgParam.portVid[port]);
		}
	}

	cfgmgr_write(CFGMGR_TABID_PSEUDOVLAN,(void*)&pRomeCfgParam->pseudoVlanCfgParam, sizeof(struct pseudoVlanCfgParam_s));
	cfgmgr_task();
	websRedirect(wp, "/pseudovlan.asp");
}




int asp_ratio_qos(request * wp, int argc, char **argv)
{
	int i;

	if (strcmp(argv[0], "enable") == 0)
	{
		if (pRomeCfgParam->ratioQosCfgParam.enable)
			websWrite(wp, " checked ");
	} else if (strcmp(argv[0], "algQos") == 0)
	{

		char *algQosStr[]={"FTP","SIP","NetMeeting"};
		int i,j;
		for(i=0;i<ALG_QOS_TYPES;i++)
		{
			websWrite(wp,"<tr bgColor=#ddeeff>\n");
			websWrite(wp,"<td>%s</td><td><input type=text name=algQueueId%d size=4 maxlength=4 value=%d></td>\n",algQosStr[i],i,pRomeCfgParam->ratioQosCfgParam.upInfo.algQosEntry[i].queueID);
			websWrite(wp,"<td><select name=\"algIsHigh%d\"><option value=1>Guaranteed<option value=0%s>Spare</select></td>\n",i,(pRomeCfgParam->ratioQosCfgParam.upInfo.algQosEntry[i].isHigh==0)?" selected":"");
			websWrite(wp,"<td><select name=algRatio%d>",i);
			for(j=1;j<=100;j++)
			{
				websWrite(wp,"<option value=%d%s>%d",j,(pRomeCfgParam->ratioQosCfgParam.upInfo.algQosEntry[i].ratio==j)?" selected":"",j);
			}
			websWrite(wp,"</select></td><td><input type=checkbox name=\"algEnable%d\" value=1 %s></td></tr>\n",i,(pRomeCfgParam->ratioQosCfgParam.upInfo.algQosEntry[i].enable==1)?" checked":"");
		}

	} else if (strcmp(argv[0], "ALG_QoS_on") == 0)
	{
		for(i=0;i<ALG_QOS_TYPES;i++)
		{
			websWrite(wp,"ratio_qos.algQueueId%d.disabled = true;\n",i);
			websWrite(wp,"ratio_qos.algIsHigh%d.disabled = true;\n",i);
			websWrite(wp,"ratio_qos.algRatio%d.disabled = true;\n",i);
			websWrite(wp,"ratio_qos.algEnable%d.disabled = true;\n",i);	
		}	
	} else if (strcmp(argv[0], "ALG_QoS_off") == 0)
	{
		for(i=0;i<ALG_QOS_TYPES;i++)
		{
			websWrite(wp,"ratio_qos.algQueueId%d.disabled = false;\n",i);
			websWrite(wp,"ratio_qos.algIsHigh%d.disabled = false;\n",i);
			websWrite(wp,"ratio_qos.algRatio%d.disabled = false;\n",i);
			websWrite(wp,"ratio_qos.algEnable%d.disabled = false;\n",i);	
		}

	} else if (strcmp(argv[0], "upRate") == 0)
	{
		websWrite(wp, "%d", pRomeCfgParam->ratioQosCfgParam.upInfo.maxRate);
	} else if (strcmp(argv[0], "upRateM") == 0)
	{
		if (pRomeCfgParam->ratioQosCfgParam.upInfo.maxRateUnit == 0)
			websWrite(wp, " selected ");
	} else if (strcmp(argv[0], "upRateK") == 0)
	{
		if (pRomeCfgParam->ratioQosCfgParam.upInfo.maxRateUnit == 1)
			websWrite(wp, " selected ");
	} else if (strcmp(argv[0],"list") == 0)
	{	

		if (pRomeCfgParam->ratioQosCfgParam.enable)
		{
			int r,i,j;
			for(j=0;j<ALG_QOS_TYPES;j++)
			{
				i=0;
				while(1)
				{
					rtl8651_tblDrvAclRule_t acl;					
					
					r=rtl8651_getMNQueueEntry(&acl,pRomeCfgParam->ratioQosCfgParam.upInfo.algQosEntry[j].queueID,i);
					if(r) break;
//					printf("acl port=[%d~%d]\n",acl.udpSrcPortLB_, acl.udpSrcPortUB_);
					
					websWrite(wp, "<tr bgColor=#ddeeff>");
					switch(j)
					{
						case 0:
							websWrite(wp, "<td>FTP</td>");
							break;
						case 1:
							websWrite(wp, "<td>SIP</td>");
							break;
						case 2:
							websWrite(wp, "<td>NetMeeting</td>");
							break;
						default:
							websWrite(wp,"<td>Unknow ALG</td>");
							break;						
					}
					websWrite(wp, "<td>%u</td>", pRomeCfgParam->ratioQosCfgParam.upInfo.algQosEntry[j].queueID);
					if((acl.dstIpAddr_==0)&&(acl.dstIpAddrMask_==0)&&(((acl.tcpDstPortLB_==0)&&(acl.tcpDstPortUB_==65535))||((acl.udpDstPortLB_==0)&&(acl.udpDstPortUB_==65535)))) 
					{
						websWrite(wp,"<td>Src</td>");						
						websWrite(wp, "<td>%u.%u.%u.%u</td>", NIPQUAD(acl.srcIpAddr_));
						websWrite(wp, "<td>%u.%u.%u.%u</td>", NIPQUAD(acl.srcIpAddrMask_));
						switch (acl.ruleType_)
						{
							case RTL8651_ACL_TCP:
								websWrite(wp, "<td>TCP</td>");
								websWrite(wp, "<td>%d</td>",acl.tcpSrcPortLB_);
								websWrite(wp, "<td>%d</td>", acl.tcpSrcPortUB_);							
								break;
							case RTL8651_ACL_UDP:
								websWrite(wp, "<td>UDP</td>");
								websWrite(wp, "<td>%d</td>",acl.udpSrcPortLB_ );
								websWrite(wp, "<td>%d</td>", acl.udpSrcPortUB_);	
								break;
							default:							
								websWrite(wp, "<td>IP</td>");
						}						
					}
					else if((acl.srcIpAddr_==0)&&(acl.srcIpAddrMask_==0)&&(((acl.tcpSrcPortLB_==0)&&(acl.tcpSrcPortUB_==65535))||((acl.udpSrcPortLB_==0)&&(acl.udpSrcPortUB_==65535)))) 
					{
						websWrite(wp,"<td>Dst</td>");						
						websWrite(wp, "<td>%u.%u.%u.%u</td>", NIPQUAD(acl.dstIpAddr_));
						websWrite(wp, "<td>%u.%u.%u.%u</td>", NIPQUAD(acl.dstIpAddrMask_));
						switch (acl.ruleType_)
						{
							case RTL8651_ACL_TCP:
								websWrite(wp, "<td>TCP</td>");
								websWrite(wp, "<td>%d</td>",acl.tcpDstPortLB_);
								websWrite(wp, "<td>%d</td>", acl.tcpDstPortUB_);							
								break;
							case RTL8651_ACL_UDP:
								websWrite(wp, "<td>UDP</td>");
								websWrite(wp, "<td>%d</td>",acl.udpDstPortLB_ );
								websWrite(wp, "<td>%d</td>", acl.udpDstPortUB_);	
								break;
							default:							
								websWrite(wp, "<td>IP</td>");
						}	
					}

					else
					{
					
						websWrite(wp, "<td>Src/Dst</td>");
						websWrite(wp, "<td>SIP:%u.%u.%u.%u<BR>DIP:%u.%u.%u.%u</td>", NIPQUAD(acl.srcIpAddr_), NIPQUAD(acl.dstIpAddr_));
						websWrite(wp, "<td>SMASK:%u.%u.%u.%u<BR>DMASK:%u.%u.%u.%u</td>", NIPQUAD(acl.srcIpAddrMask_), NIPQUAD(acl.dstIpAddrMask_));
						switch (acl.ruleType_)
						{
							case RTL8651_ACL_TCP:
								websWrite(wp, "<td>TCP</td>");
								websWrite(wp, "<td>Src:%d<BR>Dst:%d</td>",acl.tcpSrcPortLB_ ,acl.tcpDstPortLB_ );
								websWrite(wp, "<td>Src:%d<BR>Dst:%d</td>", acl.tcpSrcPortUB_,acl.tcpDstPortUB_ );							
								break;
							case RTL8651_ACL_UDP:
								websWrite(wp, "<td>UDP</td>");
								websWrite(wp, "<td>Src:%d<BR>Dst:%d</td>",acl.udpSrcPortLB_ ,acl.udpDstPortLB_ );
								websWrite(wp, "<td>Src:%d<BR>Dst:%d</td>", acl.udpSrcPortUB_,acl.udpDstPortUB_ );	
								break;
							default:							
								websWrite(wp, "<td>IP</td>");
						}
					}
					websWrite(wp, "<td>%s</td>", (pRomeCfgParam->ratioQosCfgParam.upInfo.algQosEntry[j].isHigh?"Guaranteed":"Spare"));
					websWrite(wp, "<td>%d</td>", pRomeCfgParam->ratioQosCfgParam.upInfo.algQosEntry[j].ratio);
					websWrite(wp, "<td>&nbsp;</td>");
					websWrite(wp, "</tr>");					
				
					i++;
				}
			}
		}



		/* list the exist setting of ratio-based qos */
		for (i = 0 ; i < MAX_RATIO_QOS ; i ++)
		{
			if (pRomeCfgParam->ratioQosCfgParam.entry[i].enable)
			{
				int displayPort;
			
				websWrite(wp, "<tr bgColor=#ddeeff>");
				websWrite(wp, "<td>%d</td>", (i+1));
				websWrite(wp, "<td>%u</td>", pRomeCfgParam->ratioQosCfgParam.entry[i].queueID);
				websWrite(wp, "<td>%s</td>", (pRomeCfgParam->ratioQosCfgParam.entry[i].isSrc?"Src":"Dst"));
				websWrite(wp, "<td>%u.%u.%u.%u</td>", NIPQUAD(pRomeCfgParam->ratioQosCfgParam.entry[i].ip));
				websWrite(wp, "<td>%u.%u.%u.%u</td>", NIPQUAD(pRomeCfgParam->ratioQosCfgParam.entry[i].ipMask));
				switch (pRomeCfgParam->ratioQosCfgParam.entry[i].protoType)
				{
					case 0:
						displayPort = TRUE;
						websWrite(wp, "<td>TCP</td>");
						break;
					case 1:
						displayPort = TRUE;
						websWrite(wp, "<td>UDP</td>");
						break;
					default:
						displayPort = FALSE;
						websWrite(wp, "<td>IP</td>");
				}
				if (displayPort == TRUE)
				{
					websWrite(wp, "<td>%d</td>", pRomeCfgParam->ratioQosCfgParam.entry[i].s_port);
					websWrite(wp, "<td>%d</td>", pRomeCfgParam->ratioQosCfgParam.entry[i].e_port);
				}else
				{
					websWrite(wp, "<td></td>");
					websWrite(wp, "<td></td>");
				}
				websWrite(wp, "<td>%s</td>", (pRomeCfgParam->ratioQosCfgParam.entry[i].isHigh?"Guaranteed":"Spare"));
				websWrite(wp, "<td>%d</td>", pRomeCfgParam->ratioQosCfgParam.entry[i].ratio);

				/* Mark */
				websWrite(wp, "<td>%s</td>", (pRomeCfgParam->ratioQosCfgParam.entry[i].mark?"Enabled":"Disabled"));

				/* DSCP */
				websWrite(wp, "<td>%d</td>", pRomeCfgParam->ratioQosCfgParam.entry[i].dscp);
					
#if 0
				/* Mark */
				if (pRomeCfgParam->ratioQosCfgParam.entry[i].mark)


				/* Priority */
				switch (pRomeCfgParam->ratioQosCfgParam.entry[i].priority)
				{
 					case 0:
						websWrite(wp, "<td>Low</td>");
						break;
					case 1:
						websWrite(wp, "<td>Low-Medium</td>");
						break;
					case 2:
						websWrite(wp, "<td>Medium</td>");
						break;
					case 3:
						websWrite(wp, "<td>High-Medium</td>");
						break;
					case 4:
						websWrite(wp, "<td>High</td>");
						break;
					case 5:
						websWrite(wp, "<td>Highest</td>");
						break;
					case 255: default:
						websWrite(wp, "<td>None</td>");
						break;
				}
#endif				
				websWrite(wp, "<td><input type=\"checkbox\" name=\"disable_%d\" value=1></td>", i);
				websWrite(wp, "</tr>");
			}
		}
	}else if (strcmp(argv[0],"list_disab") == 0)
	{
		if (argc < 2)
			return 1;
		for (i = 0 ; i < MAX_RATIO_QOS ; i ++)
		{
			if (pRomeCfgParam->ratioQosCfgParam.entry[i].enable)
				websWrite(wp, "%s.disable_%d.disabled = true\n", argv[1],  i);
		}
	}else if (strcmp(argv[0],"list_enab") == 0)
	{
		if (argc < 2)
			return 1;
		for (i = 0 ; i < MAX_RATIO_QOS ; i ++)
		{
			if (pRomeCfgParam->ratioQosCfgParam.entry[i].enable)
				websWrite(wp, "%s.disable_%d.disabled = false\n", argv[1], i);
		}
	} else if (strcmp(argv[0], "check_new_add_s") == 0)
	{
		if (pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_h ||
			pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_l)
		{
			for ( i = 0 ; i < MAX_RATIO_QOS ; i ++)
			{
				if (!pRomeCfgParam->ratioQosCfgParam.entry[i].enable)
					goto out;/* empty entry found, don't comment new-entry-add html code */
			}
		}
		/* table full, we can not add entry */
		websWrite(wp, "<!--\n");
	} else if (strcmp(argv[0], "check_new_add_e") == 0)
	{
		if (pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_h ||
			pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_l)
		{
			for ( i = 0 ; i < MAX_RATIO_QOS ; i ++)
			{
				if (!pRomeCfgParam->ratioQosCfgParam.entry[i].enable)
					goto out;/* empty entry found, don't comment new-entry-add html code */
			}
		}
		/* table full, we can not add entry */
		websWrite(wp, "-->\n");
	} else if (strcmp(argv[0], "js_check_new_add_s") == 0)
	{
		if (pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_h ||
			pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_l)
		{
			for ( i = 0 ; i < MAX_RATIO_QOS ; i ++)
			{
				if (!pRomeCfgParam->ratioQosCfgParam.entry[i].enable)
					goto out;/* empty entry found, don't comment new-entry-add html code */
			}
		}
		/* table full, we can not add entry */
		websWrite(wp, "/*\n");
	} else if (strcmp(argv[0], "js_check_new_add_e") == 0)
	{
		if (pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_h ||
			pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_l)
		{
			for ( i = 0 ; i < MAX_RATIO_QOS ; i ++)
			{
				if (!pRomeCfgParam->ratioQosCfgParam.entry[i].enable)
					goto out;/* empty entry found, don't comment new-entry-add html code */
			}
		}
		/* table full, we can not add entry */
		websWrite(wp, "*/\n");
	} else if (strcmp(argv[0], "get_ratio_high") == 0)
	{
		websWrite(wp, "%d", pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_h);
	} else if (strcmp(argv[0], "get_ratio_low") == 0)
	{
		websWrite(wp, "%d", pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_l);
	} else if (strcmp(argv[0], "queue_select") == 0)
	{
		if (argc < 2)
			goto out;
		if (pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_h &&
			pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_l)
		{
			websWrite(wp, "<select name=\"queue\" onchange=\"%s();\">", argv[1]);
			websWrite(wp, "<option value=1 selected>Guaranteed");
			websWrite(wp, "<option value=0>Spare");
			websWrite(wp, "</select>");
		}else if (pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_h)
		{
			websWrite(wp, "Guaranteed");
		}else if (pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_l)
		{
			websWrite(wp, "Spare");
		}
	} else if (strcmp(argv[0], "check_queue_s") == 0)
	{
		for ( i = 0 ; i < MAX_RATIO_QOS ; i ++)
		{
			if (!pRomeCfgParam->ratioQosCfgParam.entry[i].enable)
				break;
		}
		if (	(i == MAX_RATIO_QOS) ||
			(!pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_h) ||
			(!pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_l))
		{
			websWrite(wp, "<!--\n");
		}
	} else if (strcmp(argv[0], "check_queue_e") == 0)
	{
		for ( i = 0 ; i < MAX_RATIO_QOS ; i ++)
		{
			if (!pRomeCfgParam->ratioQosCfgParam.entry[i].enable)
				break;
		}
		if (	(i == MAX_RATIO_QOS) ||
			(!pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_h) ||
			(!pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_l))
		{
			websWrite(wp, "-->\n");
		}
	} else if (strcmp(argv[0], "js_check_queue_s") == 0)
	{
		for ( i = 0 ; i < MAX_RATIO_QOS ; i ++)
		{
			if (!pRomeCfgParam->ratioQosCfgParam.entry[i].enable)
				break;
		}
		if (	(i == MAX_RATIO_QOS) ||
			(!pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_h) ||
			(!pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_l))
		{
			websWrite(wp, "/*\n");
		}
	} else if (strcmp(argv[0], "js_check_queue_e") == 0)
	{
		for ( i = 0 ; i < MAX_RATIO_QOS ; i ++)
		{
			if (!pRomeCfgParam->ratioQosCfgParam.entry[i].enable)
				break;
		}
		if (	(i == MAX_RATIO_QOS) ||
			(!pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_h) ||
			(!pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_l))
		{
			websWrite(wp, "*/\n");
		}
	}
out:
	return 0;
}


void delUserDefineRatioQos(void)
{
	int i;
	
	/* set all entries */
	for (i = 0 ; i < MAX_RATIO_QOS ; i ++)
	{
		ratioQosEntry_t* entry;
		entry = &(pRomeCfgParam->ratioQosCfgParam.entry[i]);
		if (entry->enable)
		{
			rtl8651_tblDrvAclRule_t rule;
			memset(&rule, 0, sizeof(rtl8651_tblDrvAclRule_t));
			rule.actionType_ = RTL8651_ACL_DROP;
			switch(entry->protoType) {

			case 0: /* TCP */
				rule.ruleType_	= RTL8651_ACL_TCP;
				if (entry->isSrc == TRUE) {
					rule.tcpSrcPortUB_		= entry->e_port;
					rule.tcpSrcPortLB_		= entry->s_port;
					rule.tcpDstPortUB_		= 65535;
					rule.tcpDstPortLB_		= 0;
				}
				else {
					rule.tcpDstPortUB_		= entry->e_port;
					rule.tcpDstPortLB_		= entry->s_port;
					rule.tcpSrcPortUB_		= 65535;
					rule.tcpSrcPortLB_		= 0;
				}
				goto comm_L3;

			case 1: /* UDP */
				rule.ruleType_	= RTL8651_ACL_UDP;
				if (entry->isSrc == TRUE) {
					rule.udpSrcPortUB_	= entry->e_port;
					rule.udpSrcPortLB_		= entry->s_port;
					rule.udpDstPortUB_	= 65535;
					rule.udpDstPortLB_		= 0;
				}
				else {
					rule.udpDstPortUB_	= entry->e_port;
					rule.udpDstPortLB_		= entry->s_port;
					rule.udpSrcPortUB_	= 65535;
					rule.udpSrcPortLB_		= 0;
				}
				goto comm_L3;

			default: /* IP */
				rule.ruleType_ = RTL8651_ACL_IP;
comm_L3:								

				if (entry->isSrc == TRUE) {
					rule.srcIpAddr_		= entry->ip;
					rule.srcIpAddrMask_	= entry->ipMask;
				}
				else {
					rule.dstIpAddr_		= entry->ip;
					rule.dstIpAddrMask_	= entry->ipMask;
				}
			}


//			rtl8651_delRateLimitRule(&rule, entry->queueID);
			rtl8651_delFlowFromMNQueue(&rule, entry->queueID);

		}
	}

}


void rearrange_Ratio_Qos(void)
{
	int i;

	/* Inite ratio QoS */
	//rtl8651_setUpstreamBandwidth("eth0", 0);
	
	/* set upstream bw */
	if (pRomeCfgParam->ratioQosCfgParam.enable == TRUE) {
		rtl8651_setUpstreamBandwidth("eth0",
			(pRomeCfgParam->ratioQosCfgParam.upInfo.maxRateUnit == 0)?
				(pRomeCfgParam->ratioQosCfgParam.upInfo.maxRate * 1000 * 1000):
				(pRomeCfgParam->ratioQosCfgParam.upInfo.maxRate * 1000));
	}
	
	/* set all entries */
	for (i = 0 ; i < MAX_RATIO_QOS ; i ++)
	{
		ratioQosEntry_t* entry;

		entry = &(pRomeCfgParam->ratioQosCfgParam.entry[i]);
		if (entry->enable)
		{
			rtl8651_tblDrvAclRule_t rule;

			memset(&rule, 0, sizeof(rtl8651_tblDrvAclRule_t));
			rule.actionType_ = RTL8651_ACL_DROP;
			switch(entry->protoType) {

			case 0: /* TCP */
				rule.ruleType_	= RTL8651_ACL_TCP;
				if (entry->isSrc == TRUE) {
					rule.tcpSrcPortUB_		= entry->e_port;
					rule.tcpSrcPortLB_		= entry->s_port;
					rule.tcpDstPortUB_		= 65535;
					rule.tcpDstPortLB_		= 0;
				}
				else {
					rule.tcpDstPortUB_		= entry->e_port;
					rule.tcpDstPortLB_		= entry->s_port;
					rule.tcpSrcPortUB_		= 65535;
					rule.tcpSrcPortLB_		= 0;
				}
				goto comm_L3;

			case 1: /* UDP */
				rule.ruleType_	= RTL8651_ACL_UDP;
				if (entry->isSrc == TRUE) {
					rule.udpSrcPortUB_	= entry->e_port;
					rule.udpSrcPortLB_		= entry->s_port;
					rule.udpDstPortUB_	= 65535;
					rule.udpDstPortLB_		= 0;
				}
				else {
					rule.udpDstPortUB_	= entry->e_port;
					rule.udpDstPortLB_		= entry->s_port;
					rule.udpSrcPortUB_	= 65535;
					rule.udpSrcPortLB_		= 0;
				}
				goto comm_L3;

			default: /* IP */
				rule.ruleType_ = RTL8651_ACL_IP;
comm_L3:
				if (entry->isSrc == TRUE) {
					rule.srcIpAddr_		= entry->ip;
					rule.srcIpAddrMask_	= entry->ipMask;
				}
				else {
					rule.dstIpAddr_		= entry->ip;
					rule.dstIpAddrMask_	= entry->ipMask;
				}
			}

			if (entry->isHigh)
			{			
				rtl8651_addFlowToUnlimitedQueue("eth1", &rule, entry->ratio, entry->queueID);

				if (entry->mark == 1)
				{
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) entry->dscp);
				}
#if 0
				switch(entry->priority)
				{
 				case 0:	/* BE */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0x00);
					break;
				case 1:	/* AF4 */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0x28);
					break;
				case 2:	/* AF3 */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0x48);
					break;
				case 3:	/* AF2 */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0x68);
					break;
				case 4:	/* AF1 */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0x88);
					break;
				case 5:	/* EF */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0xB8);
					break;
				default:
					break;
				}
#endif
			}else
			{
				rtl8651_addFlowToLimitedQueue("eth1", &rule, entry->ratio, entry->queueID);

				if (entry->mark == 1)
				{
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) entry->dscp);
				}
#if 0
				switch(entry->priority)
				{
				case 0:	/* BE */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0x00);
					break;
				case 1:	/* AF4 */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0x28);
					break;
				case 2:	/* AF3 */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0x48);
					break;
				case 3:	/* AF2 */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0x68);
					break;
				case 4:	/* AF1 */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0x88);
					break;
				case 5:	/* EF */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0xB8);
					break;
				default:
					break;
				}
#endif
			}
		}
	}
}







void asp_setRatio_qos(request * wp, char *path, char *query)
{
	char buff[100];
	int i;
	int reArrange;

	pRomeCfgParam->ratioQosCfgParam.enable = atoi(websGetVar(wp,"enable",""));

	delUserDefineRatioQos();

	/* modify pRomeCfgParam */
	reArrange = FALSE;
	if (strcmp(websGetVar(wp,"deleteSelected", ""),"Delete Selected") == 0)
	{
		delUserDefineRatioQos();
		for (i = 0 ; i < MAX_RATIO_QOS ; i ++ )
		{
			if (pRomeCfgParam->ratioQosCfgParam.entry[i].enable)
			{
				sprintf(buff, "disable_%d", i);
				/* check if this entry been deleted or not */
				if (atoi(websGetVar(wp, buff, "")))
				{	/* this entry is deleted */
					reArrange = TRUE;	/* we need to rearrange data */
					if (pRomeCfgParam->ratioQosCfgParam.entry[i].isHigh)
					{
						pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_h += pRomeCfgParam->ratioQosCfgParam.entry[i].ratio;
					}else
					{
						pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_l += pRomeCfgParam->ratioQosCfgParam.entry[i].ratio;
					}
					pRomeCfgParam->ratioQosCfgParam.entry[i].enable = 0;
				}
			}
		}
	}
	else if (strcmp(websGetVar(wp,"deleteAll", ""), "Delete All") == 0)
	{
		delUserDefineRatioQos();	
		for (i = 0 ; i < MAX_RATIO_QOS ; i ++)
		{
			if (pRomeCfgParam->ratioQosCfgParam.entry[i].enable)
			{
				if (pRomeCfgParam->ratioQosCfgParam.entry[i].isHigh)
					pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_h += pRomeCfgParam->ratioQosCfgParam.entry[i].ratio;
				else
					pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_l += pRomeCfgParam->ratioQosCfgParam.entry[i].ratio;
			}
		}
		memset(pRomeCfgParam->ratioQosCfgParam.entry, 0 , (sizeof(ratioQosEntry_t) * MAX_RATIO_QOS));
	}
	else if (strcmp(websGetVar(wp,"update", ""),"Apply") == 0)
	{

		//if you want to add a new ALG type, please modify board.c:ratioQos_init() ,too.
		int i;		
		pRomeCfgParam->ratioQosCfgParam.upInfo.maxRate = atoi(websGetVar(wp, "uprate", ""));
		pRomeCfgParam->ratioQosCfgParam.upInfo.maxRateUnit = atoi(websGetVar(wp, "uprateUnit", ""));

		if(pRomeCfgParam->ratioQosCfgParam.enable)
		{
			for(i=0;i<ALG_QOS_TYPES;i++)
			{
				char tmpStr[16];
				uint32 queueId=0;
				uint32 isHigh,enable;

				sprintf(tmpStr,"algQueueId%d",i);	
				if((pRomeCfgParam->ratioQosCfgParam.upInfo.algQosEntry[i].enable==1)
					&&(pRomeCfgParam->ratioQosCfgParam.upInfo.algQosEntry[i].queueID!=atoi(websGetVar(wp,tmpStr,""))))
					
				{
					rtl8651_delRateLimitGroup(pRomeCfgParam->ratioQosCfgParam.upInfo.algQosEntry[i].queueID);
				}
				pRomeCfgParam->ratioQosCfgParam.upInfo.algQosEntry[i].queueID=atoi(websGetVar(wp,tmpStr,""));
				
				sprintf(tmpStr,"algEnable%d",i);

				if((pRomeCfgParam->ratioQosCfgParam.upInfo.algQosEntry[i].enable==1)&&(atoi(websGetVar(wp,tmpStr,""))==0))
				{
					rtl8651_delRateLimitGroup(pRomeCfgParam->ratioQosCfgParam.upInfo.algQosEntry[i].queueID);
				}			
				enable=atoi(websGetVar(wp,tmpStr,""));
				
				pRomeCfgParam->ratioQosCfgParam.upInfo.algQosEntry[i].enable=enable;
				
				if(enable==1) 
					queueId=pRomeCfgParam->ratioQosCfgParam.upInfo.algQosEntry[i].queueID;

				
				sprintf(tmpStr,"algIsHigh%d",i);
				isHigh=atoi(websGetVar(wp,tmpStr,""));
				pRomeCfgParam->ratioQosCfgParam.upInfo.algQosEntry[i].isHigh=isHigh;
				
				
				sprintf(tmpStr,"algRatio%d",i);
				pRomeCfgParam->ratioQosCfgParam.upInfo.algQosEntry[i].ratio=atoi(websGetVar(wp,tmpStr,""));

				if(enable==1)
				{
/* Following configuration is invalid due to NULL rule return SUCCESS directly */
					if(isHigh==1)
					{
						rtl8651_addFlowToUnlimitedQueue("eth0",NULL,pRomeCfgParam->ratioQosCfgParam.upInfo.algQosEntry[i].ratio,queueId);
					}
					else
					{
						rtl8651_addFlowToLimitedQueue("eth0",NULL,pRomeCfgParam->ratioQosCfgParam.upInfo.algQosEntry[i].ratio,queueId);
					}
				}
				switch(i)
				{
					case 0:
						rtl8651_setAlgQosQueueId(RTL8651_ALG_FTP_IDX,queueId,isHigh, pRomeCfgParam->ratioQosCfgParam.upInfo.algQosEntry[i].ratio);
						break;
					case 1:
						rtl8651_setAlgQosQueueId(RTL8651_ALG_SIP_IDX,queueId,isHigh, pRomeCfgParam->ratioQosCfgParam.upInfo.algQosEntry[i].ratio);
						break;
					case 2:
						rtl8651_setAlgQosQueueId(RTL8651_ALG_NETMEETING_IDX,queueId,isHigh, pRomeCfgParam->ratioQosCfgParam.upInfo.algQosEntry[i].ratio);
						break;
				}
					
			}
		}

		if (pRomeCfgParam->ratioQosCfgParam.upInfo.maxRate == 0)
		{
			pRomeCfgParam->ratioQosCfgParam.upInfo.maxRate = 100;
			pRomeCfgParam->ratioQosCfgParam.upInfo.maxRateUnit = 0;
		}else if ((pRomeCfgParam->ratioQosCfgParam.upInfo.maxRateUnit == 1) &&
					(pRomeCfgParam->ratioQosCfgParam.upInfo.maxRate < 64))
		{	/* min check */
			pRomeCfgParam->ratioQosCfgParam.upInfo.maxRate = 64;
		}else if ((pRomeCfgParam->ratioQosCfgParam.upInfo.maxRateUnit == 0) &&
					(pRomeCfgParam->ratioQosCfgParam.upInfo.maxRate > 100))
		{	/* max check */
			pRomeCfgParam->ratioQosCfgParam.upInfo.maxRate = 100;
		}
	}
	else if (pRomeCfgParam->ratioQosCfgParam.enable)
	{	/* add new */
		ratioQosEntry_t *ptr;
		uint8 IPoct[4];
		uint8 Mskoct[4];
		uint32 ip;
		uint32 mask;
		uint8 qSel, ratio;

		delUserDefineRatioQos();
		/* check input */
		for (i = 0 ; i < 4 ; i ++)
		{
			sprintf(buff, "ip%d", i);
			IPoct[i] = atoi(websGetVar(wp, buff, ""));
			sprintf(buff, "mask%d", i);
			Mskoct[i] = atoi(websGetVar(wp, buff, ""));

			if ((IPoct[i] > 255 || Mskoct[i] > 255))
				goto out;
		}
		ip = (IPoct[0] * (256 * 256 * 256)) + (IPoct[1] * (256 * 256)) + (IPoct[2] * 256) + IPoct[3];
		mask = (Mskoct[0] * (256 * 256 * 256)) + (Mskoct[1] * (256 * 256)) + (Mskoct[2] * 256) + Mskoct[3];

		ratio = atoi(websGetVar(wp, "ratio", ""));	/* ratio */

		if (ratio == 0)
			goto out;

		if (pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_l &&
			pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_h)
		{
			qSel = atoi(websGetVar(wp,"queue", ""));	/* queue select */
		}else if (pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_h)
		{	/* high only */
			qSel = 1;
		}else
		{	/* low only */
			qSel = 0;
		}
		
		if (qSel)
		{	/* high */
			if (pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_h < ratio)
				goto out;				
		}else
		{	/* low */
			if (pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_l < ratio)
				goto out;	
		}

		ptr = pRomeCfgParam->ratioQosCfgParam.entry;
		for (i = 0 ; i < MAX_RATIO_QOS ; i ++ )
		{
			if (!ptr[i].enable)
			{	/* empty entry found : set entry */
				if (qSel)
				{	/* high */
					ptr[i].isHigh = TRUE;
					ptr[i].ratio = ratio;
					pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_h -= ratio;
				} else
				{	/* low */
					ptr[i].isHigh = FALSE;
					ptr[i].ratio = ratio;
					pRomeCfgParam->ratioQosCfgParam.upInfo.remainingRatio_l -= ratio;
				}

				ptr[i].queueID		= atoi(websGetVar(wp, "queueID", ""));				
				ptr[i].isSrc		= atoi(websGetVar(wp, "isSrc", ""));
				ptr[i].ip			= ip;
				ptr[i].ipMask		= mask;
				ptr[i].protoType	= atoi(websGetVar(wp, "protoType", ""));
				ptr[i].s_port		= atoi(websGetVar(wp, "s_port", ""));
				ptr[i].e_port		= atoi(websGetVar(wp, "e_port", ""));
				ptr[i].mark		= atoi(websGetVar(wp, "mark", ""));
				ptr[i].enable		= TRUE;

				if (ptr[i].mark == 1)
					ptr[i].dscp = atoi(websGetVar(wp, "dscp", ""));
				else
					ptr[i].dscp = 0;					

				reArrange = TRUE;		/* we need to rearrange data */

				goto startReArrange;
			}
		}
	}
startReArrange:
	/* rearrange data if we need */
	if (reArrange == TRUE)
	{
		ratioQosEntry_t *ptr;
		ptr = pRomeCfgParam->ratioQosCfgParam.entry;

		for ( i = 0 ; i < MAX_RATIO_QOS ; i ++ )
		{
			if (!ptr[i].enable)
			{	/* this entry is empty, check non-empty entry behind it and move to this entry */
				int j = i + 1;
				while ((j < MAX_RATIO_QOS) && (!ptr[j].enable))
					j ++;
				if (j == MAX_RATIO_QOS)
					goto ArrangeDone;
				/* non-empty entry found */
				if (!ptr[j].enable)
					printf("Error: ratio QoS reArrange error!\n");
				else
				{	/* mv entry from j to i */
					memcpy(&(ptr[i]), &(ptr[j]), sizeof(ratioQosEntry_t));
					/* clear entry j */
					memset(&(ptr[j]), 0, sizeof(ratioQosEntry_t));
				}
			}
		}
	ArrangeDone:
	}


out:
	/* update tblDrv */
	if (pRomeCfgParam->ratioQosCfgParam.enable == 0)
	{	/* disable Ratio based QoS System */
		//rearrange_Ratio_Qos(TRUE);
		rtl8651_setUpstreamBandwidth("eth0", 0);
	}else
	{		
		rearrange_Ratio_Qos();
	}

	cfgmgr_write(CFGMGR_TABID_RATIOQOS,(void*)&pRomeCfgParam->ratioQosCfgParam, sizeof(ratioQosCfgParam_t));
	cfgmgr_task();
	websRedirect(wp, "/ratio_qos.asp");

}

int asp_rateLimit(request * wp, int argc, char **argv)
{
	uint32 entry;

	websWrite(wp, "<SCRIPT LANGUAGE=\"JavaScript\">\n");
	websWrite(wp, "function rateLimit_FormSwitch() {\n");
	websWrite(wp, "	if (rateLimit_Form.ab_switch.checked == false) { \n");
	for(entry=0; entry<16; entry++) {
		websWrite(wp,
				"rateLimit_Form.srcDst%d.disabled=true;\n"\
				"rateLimit_Form.ip%d.disabled=true;\n"\
				"rateLimit_Form.ipMask%d.disabled=true;\n"\
				"rateLimit_Form.proto%d.disabled=true;\n"\
				"rateLimit_Form.sport%d.disabled=true;\n"\
				"rateLimit_Form.eport%d.disabled=true;\n"\
				"rateLimit_Form.rate%d.disabled= true;\n"\
				"rateLimit_Form.isByteCount%d.disabled=true;\n"\
				"rateLimit_Form.maxRate%d.disabled=true;\n"\
				"rateLimit_Form.ruleAction%d.disabled=true;\n"\
				"rateLimit_Form.apply_entry%d.disabled=true;\n",
				entry, entry, entry, entry, entry, entry, entry, entry, entry, entry, entry
		);
	}
	websWrite(wp, "} else { \n");
	for(entry=0; entry<16; entry++) {
		websWrite(wp,
				"rateLimit_Form.srcDst%d.disabled=false;\n"\
				"rateLimit_Form.ip%d.disabled=false;\n"\
				"rateLimit_Form.ipMask%d.disabled=false;\n"\
				"rateLimit_Form.proto%d.disabled=false;\n"\
				"rateLimit_Form.sport%d.disabled=false;\n"\
				"rateLimit_Form.eport%d.disabled=false;\n"\
				"rateLimit_Form.rate%d.disabled=false;\n"\
				"rateLimit_Form.isByteCount%d.disabled=false;\n"\
				"rateLimit_Form.maxRate%d.disabled=false;\n"\
				"rateLimit_Form.ruleAction%d.disabled=false;\n"\
				"rateLimit_Form.apply_entry%d.disabled=false; \n",
				entry, entry, entry, entry, entry, entry, entry, entry, entry, entry, entry
		);
	}
	websWrite(wp, "}\n\n}function onload_func() { rateLimit_FormSwitch(); }\n");
	websWrite(wp, "</SCRIPT>\n"\
				 "</head>\n"\
				 "<body bgcolor=\"#ffffff\" text=\"#000000\" onload=\"onload_func()\">\n"
	);

	
	websWrite(wp,
		"<form method=\"post\" action=\"/goform/asp_setRateLimit\" name=rateLimit_Form>\n"\
		"<tr><td><b>Hardware Rate Policing QoS</b><td bgColor=#ddeeff><input type=checkbox name=ab_switch %s value=1 onClick=\"rateLimit_FormSwitch();\">Enable</td></td></tr>\n"\
		"<br>\n"\
		"<table cellSpacing=1 cellPadding=2 border=0>\n"\
		"<tr><td><b>LAN</b></td></tr>"\
		"<tr><td bgColor=#aaddff>Priority</td>\n"\
		"	<td bgColor=#aaddff>src/dst</td>\n"\
		"	<td bgColor=#aaddff>IP Address</td>\n"\
		"	<td bgColor=#aaddff>IP Mask</td>\n"\
		"	<td bgColor=#aaddff>Protocol</td>\n"\
		"	<td bgColor=#aaddff>Start Port</td>\n"\
		"	<td bgColor=#aaddff>End Port</td>\n"\
		"	<td bgColor=#aaddff>Rate</td>\n"\
		"	<td bgColor=#aaddff>Unit</td>\n"\
		"	<td bgColor=#aaddff>isByteCount</td>\n"\
		"	<td bgColor=#aaddff>Max Rate</td>\n"\
		"	<td bgColor=#aaddff>Unit</td>\n"\
		"	<td bgColor=#aaddff>Drop Log</td>\n"\
		"	<td bgColor=#aaddff>Enable</td>\n"\
		"</tr>\n",
		((pRomeCfgParam->rateLimitCfgParam.enable)? "checked": "")
	);

	for(entry=0; entry<16; entry++) {
		websWrite(wp,
			"<tr><td bgColor=#aaddff>%u</td>\n"\
			"	<td bgColor=#ddeeff align=center><select name=srcDst%d><option %s>src IP<option %s>dst IP</selected></td>\n"\
			"	<td bgColor=#ddeeff align=center><input type=text name=ip%d size=15 value=\"%u.%u.%u.%u\"></td>\n"\
			"	<td bgColor=#ddeeff align=center><input type=text name=ipMask%d size=15 value=\"%u.%u.%u.%u\"></td>\n"\
			"	<td bgColor=#ddeeff align=center><select name=proto%d><option %s>TCP<option %s>UDP<option %s>IP</selected></td>\n"\
			"	<td bgColor=#ddeeff align=center><input type=text name=sport%d size=5 value=%u></td>\n"\
			"	<td bgColor=#ddeeff align=center><input type=text name=eport%d size=5 value=%u></td>\n",
			entry%8, 
			entry, ((pRomeCfgParam->rateLimitCfgParam.entry[entry].isSrcIp==TRUE)? "selected": ""), ((pRomeCfgParam->rateLimitCfgParam.entry[entry].isSrcIp==FALSE)? "selected": ""),
			entry, NIPQUAD(pRomeCfgParam->rateLimitCfgParam.entry[entry].ip) ,
			entry, NIPQUAD(pRomeCfgParam->rateLimitCfgParam.entry[entry].ipMask) ,
			entry, ((pRomeCfgParam->rateLimitCfgParam.entry[entry].protoType==0)? "selected": ""), ((pRomeCfgParam->rateLimitCfgParam.entry[entry].protoType==1)? "selected": ""), ((pRomeCfgParam->rateLimitCfgParam.entry[entry].protoType==2)? "selected": ""),
			entry, pRomeCfgParam->rateLimitCfgParam.entry[entry].s_port,
			entry, pRomeCfgParam->rateLimitCfgParam.entry[entry].e_port
		);
		websWrite(wp, 
			"	<td bgColor=#ddeeff align=center><input type=text name=rate%d size=6 value=%u></td>\n"\
			"	<td bgColor=#ddeeff align=center><select name=rateUnit%d><option %s>Kbps<option %s>Mbps</selected></td>\n"\
			"	<td bgColor=#ddeeff align=center><select name=isByteCount%d><option %s>byteCount<option %s>pktCount</selected></td>\n"\
			"	<td bgColor=#ddeeff align=center><input type=text name=maxRate%d size=6 value=%u></td>\n"\
			"	<td bgColor=#ddeeff align=center><select name=maxRateUnit%d><option %s> Kbps<option %s>Mbps</selected></td>\n"\
			"	<td bgColor=#ddeeff align=center><select name=ruleAction%d><option %s>DropLog<option %s>Drop</selected></td>\n"\
			"	<td bgColor=#ddeeff align=center><input type=checkbox name=apply_entry%d value=1 %s></td>\n"\
			"</tr>\n", 
			entry, pRomeCfgParam->rateLimitCfgParam.entry[entry].rate,
			entry, ((pRomeCfgParam->rateLimitCfgParam.entry[entry].rateUnit==0)? "selected": ""), ((pRomeCfgParam->rateLimitCfgParam.entry[entry].rateUnit==1)? "selected": ""),
			entry, ((pRomeCfgParam->rateLimitCfgParam.entry[entry].isByteCount==TRUE)? "selected": ""), ((pRomeCfgParam->rateLimitCfgParam.entry[entry].isByteCount==FALSE)? "selected": ""),
			entry, pRomeCfgParam->rateLimitCfgParam.entry[entry].maxRate,
			entry, ((pRomeCfgParam->rateLimitCfgParam.entry[entry].maxRateUnit==0)? "selected": ""), ((pRomeCfgParam->rateLimitCfgParam.entry[entry].maxRateUnit==1)? "selected": ""),
			entry, ((pRomeCfgParam->rateLimitCfgParam.entry[entry].isDropLog==TRUE)? "selected": ""), ((pRomeCfgParam->rateLimitCfgParam.entry[entry].isDropLog==FALSE)? "selected": ""),
			entry, ((pRomeCfgParam->rateLimitCfgParam.entry[entry].enable==TRUE)? "checked": "")
		);

		if (entry== 7) {
			websWrite(wp, 
				"<tr><td><b>WAN</b></td></tr>\n"\
				"<tr><td bgColor=#aaddff>Priority</td>\n"\
				"	<td bgColor=#aaddff>src/dst</td>\n"\
				"	<td bgColor=#aaddff>IP Address</td>\n"\
				"	<td bgColor=#aaddff>IP Mask</td>\n"\
				"	<td bgColor=#aaddff>Protocol</td>\n"\
				"	<td bgColor=#aaddff>Start Port</td>\n"\
				"	<td bgColor=#aaddff>End Port</td>\n"\
				"	<td bgColor=#aaddff>Rate</td>\n"\
				"	<td bgColor=#aaddff>Unit</td>\n"\
				"	<td bgColor=#aaddff>isByteCount</td>\n"\
				"	<td bgColor=#aaddff>Max Rate</td>\n"\
				"	<td bgColor=#aaddff>Unit</td>\n"\
				"	<td bgColor=#aaddff>Drop Log</td>\n"\
				"	<td bgColor=#aaddff>Enable</td></tr>\n"
			);		
		}
	}
	
	websWrite(wp,
			"<tr>\n"\
			"<td colspan=2 align=center>\n"\
			"<input type=submit value=Apply>\n"\
			"<input type=reset value=Reset>\n"\
			"</td>\n"\
		   	"</tr>\n"\
			"</table>\n"\
			"</form>\n"
	);
	return 0;
}


int asp_addRateLimitRule(rateLimitEntry_t *rlrule_t, uint32 entry)
{
	int8 *ifName[] = { "eth1", "eth0" };
	rtl8651_tblDrvAclRule_t rule;
	uint32 ifIndex, rate, maxRate;
	

	/* Add a rule to Rome Driver */
	if (rlrule_t->rateUnit == 0)
		rate = (1000 * rlrule_t->rate) >> 3;
	else rate = (1000 * 1000 * rlrule_t->rate) >> 3;
	if (rlrule_t->maxRateUnit == 0)
		maxRate = (1000 * rlrule_t->maxRate) >> 3;
	else maxRate = (1000 * 1000 *rlrule_t->maxRate) >> 3;
	
	ifIndex = entry >> 3;
	rtl8651_addRateLimitGroup(1000+entry, ifName[ifIndex], rate, maxRate, rlrule_t->isByteCount);
	bzero(&rule, sizeof(rtl8651_tblDrvAclRule_t));

	/* Action Type */
	if (rlrule_t->isDropLog == TRUE)
		rule.actionType_ = RTL8651_ACL_DROP_LOG;
	else rule.actionType_ = RTL8651_ACL_DROP;
	
	/* rule Type */
	switch (rlrule_t->protoType) {

	case 0: /* TCP */
		rule.ruleType_	= RTL8651_ACL_TCP;
		if (rlrule_t->isSrcIp == TRUE) {
			rule.tcpSrcPortUB_	= rlrule_t->e_port;
			rule.tcpSrcPortLB_	= rlrule_t->s_port;
			rule.tcpDstPortUB_	= 65535;
			rule.tcpDstPortLB_	= 0;
		}
		else {
			rule.tcpDstPortUB_	= rlrule_t->e_port;
			rule.tcpDstPortLB_	= rlrule_t->s_port;
			rule.tcpSrcPortUB_	= 65535;
			rule.tcpSrcPortLB_	= 0;
		}
		goto comm_L3;

	case 1: /* UDP */
		rule.ruleType_	= RTL8651_ACL_UDP;
		if (rlrule_t->isSrcIp == TRUE) {
			rule.udpSrcPortUB_		= rlrule_t->e_port;
			rule.udpSrcPortLB_		= rlrule_t->s_port;
			rule.udpDstPortUB_		= 65535;
			rule.udpDstPortLB_		= 0;
		}
		else {
			rule.udpDstPortUB_		= rlrule_t->e_port;
			rule.udpDstPortLB_		= rlrule_t->s_port;
			rule.udpSrcPortUB_		= 65535;
			rule.udpSrcPortLB_		= 0;
		}
		goto comm_L3;

	case 2: /* IP */
		rule.ruleType_ = RTL8651_ACL_IP;
comm_L3:
		if (rlrule_t->isSrcIp == TRUE) {
			rule.srcIpAddr_		= rlrule_t->ip;
			rule.srcIpAddrMask_	= rlrule_t->ipMask;
		}
		else {
			rule.dstIpAddr_		= rlrule_t->ip;
			rule.dstIpAddrMask_	= rlrule_t->ipMask;
		}
		break;
	
	default: return 1;
	}
	rtl8651_addRateLimitRule(&rule, 1000+entry);
	return 0;
}



void asp_setRateLimit(request * wp, char *path, char *query)
{
	uint8 buf[20];
	uint32 entry, iph1, iph2, iph3, iph4;
	int8 *str;

	str = websGetVar(wp,"ab_switch","");
	if (strcmp(str, "1") == 0) 
		pRomeCfgParam->rateLimitCfgParam.enable = TRUE;
	else pRomeCfgParam->rateLimitCfgParam.enable = FALSE;
	
	rtl8651_flushRateLimitGroup("eth0");
	rtl8651_flushRateLimitGroup("eth1");

	for(entry=0; entry<16&&pRomeCfgParam->rateLimitCfgParam.enable ==TRUE; entry++) {	
		sprintf(buf, "apply_entry%d", entry);
		pRomeCfgParam->rateLimitCfgParam.entry[entry].enable = atoi(websGetVar(wp, buf," "));
		
		/* Get Destion/Source IP */
		sprintf(buf, "srcDst%d", entry);
		str = websGetVar(wp,T(buf)," ");
		if (strcmp(str, "src IP") == 0)
			pRomeCfgParam->rateLimitCfgParam.entry[entry].isSrcIp = TRUE;
		else pRomeCfgParam->rateLimitCfgParam.entry[entry].isSrcIp = FALSE;

		/* Get IP Address */
		sprintf(buf, "ip%d", entry);
		str = websGetVar(wp,T(buf)," ");
		sscanf(str, "%u.%u.%u.%u", 	&iph1, &iph2, &iph3, &iph4);
 		pRomeCfgParam->rateLimitCfgParam.entry[entry].ip = ((iph1<<24) | iph2<<16 | iph3<<8 | iph4);

 		/* Get IP Mask */
 		sprintf(buf, "ipMask%d", entry);
 		str = websGetVar(wp,T(buf)," ");
		sscanf(str, "%u.%u.%u.%u", 	&iph1, &iph2, &iph3, &iph4);
 		pRomeCfgParam->rateLimitCfgParam.entry[entry].ipMask = ((iph1<<24) | iph2<<16 | iph3<<8 | iph4);

		/* Get Protocol */
		sprintf(buf, "proto%d", entry);
		str = websGetVar(wp,T(buf)," ");
		if (strcmp(str, "TCP") == 0)
			pRomeCfgParam->rateLimitCfgParam.entry[entry].protoType = 0;
		else if (strcmp(str, "UDP") == 0)
			pRomeCfgParam->rateLimitCfgParam.entry[entry].protoType = 1;
		else pRomeCfgParam->rateLimitCfgParam.entry[entry].protoType = 2;
		
		/* Get start Port */
		sprintf(buf, "sport%d", entry);
		pRomeCfgParam->rateLimitCfgParam.entry[entry].s_port = atoi(websGetVar(wp, T(buf), " "));
		/* Get Ending Port */
		sprintf(buf, "eport%d", entry);
		pRomeCfgParam->rateLimitCfgParam.entry[entry].e_port = atoi(websGetVar(wp, T(buf), " "));

		/* Get rate */
		sprintf(buf, "rate%d", entry);
		pRomeCfgParam->rateLimitCfgParam.entry[entry].rate = atoi(websGetVar(wp, T(buf), " "));

		/* Get rate unit */
		sprintf(buf, "rateUnit%d", entry);
		str = websGetVar(wp,T(buf)," ");
		if (strcmp(str, "Kbps") == 0)
			pRomeCfgParam->rateLimitCfgParam.entry[entry].rateUnit = 0;
		else pRomeCfgParam->rateLimitCfgParam.entry[entry].rateUnit = 1;
		

		/* Get ByteCount */
		sprintf(buf, "isByteCount%d", entry);
		str = websGetVar(wp,T(buf)," ");
		if (strcmp(str, "byteCount") == 0)
			pRomeCfgParam->rateLimitCfgParam.entry[entry].isByteCount = TRUE;
		else pRomeCfgParam->rateLimitCfgParam.entry[entry].isByteCount = FALSE;

		/* Get Max Rate */
		sprintf(buf, "maxRate%d", entry);
		pRomeCfgParam->rateLimitCfgParam.entry[entry].maxRate = atoi(websGetVar(wp, T(buf), " "));

		/* Get Max rate unit */
		sprintf(buf, "maxRateUnit%d", entry);
		str = websGetVar(wp,T(buf)," ");
		if (strcmp(str, "Kbps") == 0)
			pRomeCfgParam->rateLimitCfgParam.entry[entry].maxRateUnit= 0;
		else pRomeCfgParam->rateLimitCfgParam.entry[entry].maxRateUnit= 1;

		/* Get Action */
		sprintf(buf, "ruleAction%d", entry);
		str = websGetVar(wp,T(buf)," ");
		if (strcmp(str, "Drop") == 0)
			pRomeCfgParam->rateLimitCfgParam.entry[entry].isDropLog = FALSE;
		else pRomeCfgParam->rateLimitCfgParam.entry[entry].isDropLog = TRUE;

		if (pRomeCfgParam->rateLimitCfgParam.entry[entry].enable == TRUE &&
		    pRomeCfgParam->rateLimitCfgParam.enable == TRUE)
			asp_addRateLimitRule(&pRomeCfgParam->rateLimitCfgParam.entry[entry], entry);		
	}

	cfgmgr_write(CFGMGR_TABID_RATELIMIT,(void*)&pRomeCfgParam->rateLimitCfgParam, sizeof(struct rateLimitCfgParam_s));
	cfgmgr_task();
	websRedirect(wp, "/ratelimit.asp");
//	return 0;
}








int asp_port(request * wp, int argc, char **argv)
{
	int i, type, enable;
	websWrite(wp,
	"<tr><td bgColor=#aaddff>Port <br>Number</td><td bgColor=#aaddff>Routing<br>Interface</td><td bgColor=#aaddff>On/Off</td></tr>\n");

	for(i=0;i<6;i++)
	{
		type=-1;//Unknown
		enable=0;
		if(pRomeCfgParam->vlanCfgParam[0].enablePorts & (1<<i))
			enable=1; //This port is open
		else if(pRomeCfgParam->vlanCfgParam[1].enablePorts & (1<<i))
			enable=1; //This port is closed
		if(enable){
			if(pRomeCfgParam->vlanCfgParam[0].memberPort & (1<<i))
				type=1; //This port is config as WAN
			else if(pRomeCfgParam->vlanCfgParam[1].memberPort & (1<<i))
				type=0; //This port is config as LAN
		}
		websWrite(wp,
		"<tr>\n" \
		"<td bgColor=#ddeeff>\n" \
		"		%d%s\n" \
		"	</td>\n" \
		"<td bgColor=#ddeeff><select name=interface%d %s onChange=\"selectSwitch();\"><option value=0 %s>LAN<option value=1 %s>WAN</select></td>\n" \
		"<td bgColor=#ddeeff><select name=enable%d  onChange=\"selectSwitch();\"><option value=0 %s>Off<option value=1 %s>ON</select></td>\n" \
		"</td>\n" \
		"</tr>\n" ,i,i==5?"(MII)":"",i,enable?"":"disabled",type==0?"selected":""
				,type==1?"selected":"", i,enable==0?"selected":"",enable==1?"selected":"");
	}

	return 0;
}

void asp_setPort(request * wp, char *path, char *query)
{
	int i,ret;
	char	 tmpstr[32]={0};
	for(i=0;i<6;i++)
	{
		sprintf(tmpstr,"enable%d",i);

		if(atoi(websGetVar(wp,tmpstr,""))==0){
			pRomeCfgParam->vlanCfgParam[0].memberPort &=~(1<<i);//clear it
			pRomeCfgParam->vlanCfgParam[1].memberPort &=~(1<<i);//clear it
			pRomeCfgParam->vlanCfgParam[0].enablePorts &=~(1<<i);//clear it
			pRomeCfgParam->vlanCfgParam[1].enablePorts &=~(1<<i);//clear it
		}else{

			pRomeCfgParam->vlanCfgParam[0].enablePorts |=(1<<i);
			pRomeCfgParam->vlanCfgParam[1].enablePorts |=(1<<i);
			sprintf(tmpstr,"interface%d",i);			
			if(atoi(websGetVar(wp,tmpstr,""))){

				//set this port as WAN
				if(pRomeCfgParam->vlanCfgParam[1].memberPort & (1<<i)) //was a LAN port
					pRomeCfgParam->vlanCfgParam[1].memberPort &=~(1<<i);//clear it
				pRomeCfgParam->vlanCfgParam[0].memberPort |=(1<<i);//now config as WAN
			}else{
				//set this port as LAN

				if(pRomeCfgParam->vlanCfgParam[0].memberPort & (1<<i)) //was a WAN port
					pRomeCfgParam->vlanCfgParam[0].memberPort &=~(1<<i);//clear it
				pRomeCfgParam->vlanCfgParam[1].memberPort |=(1<<i);//now config as LAN
			}
		}
	}
	websRedirect(wp, T("/lan.asp"));
}


int asp_getLanPortStatus(request * wp, int argc, char **argv){
	int i;
	int up, speed, duplex, range;
	unsigned long counters[6];
	for(i=0;i<6;i++)
	{
		if(pRomeCfgParam->vlanCfgParam[1].enablePorts & (1<<i)){
			if(pRomeCfgParam->vlanCfgParam[1].memberPort & (1<<i)){
				if(i==5){
					websWrite(wp,
					"<tr><td bgColor=#aaddff align=center>Port 5(MII)</td><td bgColor=#ddeeff>"\
					"Link is Up</td></tr>"
					);
					continue;
				}
				rtl8651_checkEthernetPortStatus(i,&up, &speed, &duplex, &range);
				if(up){
					websWrite(wp,
					"<tr><td bgColor=#aaddff align=center>Port %d</td><td bgColor=#ddeeff>"\
					"Link is Up. %sMbps, %s duplex"\
					"</td></tr>",  i, speed? "100":"10", duplex?"full-":"half-"
					);
				}else{
					char str[80];
					if(range&0x400){
						range&=0x1ff;
						if(range)
							sprintf(str,"<font color=red>Cable short at %d.%d meters away</font>",range>>1, range&1?5:0);
						else
							sprintf(str, "No cable detected");
					}else if(range&0x200){
						range&=0x1ff;
						if(range)
							sprintf(str,"<font color=red>Cable open %d.%d meters away</font>",range>>1, range&1?5:0);
						else
							sprintf(str, "No cable detected");
					}else
						sprintf(str, "No cable detected");
					websWrite(wp,
					"<tr><td bgColor=#aaddff align=center>Port %d</td><td bgColor=#ddeeff>"\
					"Link is down. %s</td></tr>",  i, str);
				}
			}
		}
	}

	rtl8651_getIntfCounters(0x2, &counters);
	websWrite(wp,"<tr><td bgColor=#aaddff>Received</td><td bgColor=#ddeeff>%ld packets, %ld bytes</td></tr>",
		counters[1],counters[0]);
	websWrite(wp,"<tr><td bgColor=#aaddff>Transmitted</td><td bgColor=#ddeeff>%ld packets, %ld bytes</td></tr>",
		counters[3],counters[2]);
	websWrite(wp,"<tr><td bgColor=#aaddff>Dropped</td><td bgColor=#ddeeff>%ld packets</td></tr>",
		counters[5]);

	return 0;
}


int asp_getWanPortStatus(request * wp, int argc, char **argv){
	int i;
	int up, speed, duplex, range;
	unsigned long counters[6];	
	for(i=0;i<6;i++)
	{
		if(pRomeCfgParam->vlanCfgParam[0].enablePorts & (1<<i)){
			if(pRomeCfgParam->vlanCfgParam[0].memberPort & (1<<i)){
				if(i==5){
					websWrite(wp,
					"<tr><td bgColor=#aaddff align=center>Port 5(MII)</td><td bgColor=#ddeeff>"\
					"Link is Up</td></tr>"
					);
					continue;
				}
				rtl8651_checkEthernetPortStatus(i,&up, &speed, &duplex, &range);
				if(up){
					websWrite(wp,
					"<tr><td bgColor=#aaddff align=center>Port %d</td><td bgColor=#ddeeff>"\
					"Link is Up. %sMbps, %s duplex"\
					"</td></tr>",  i, speed? "100":"10", duplex?"full-":"half-"
					);
				}else{
					char str[32];
					if(range&0x400){
						range&=0x1ff;
						if(range)
							sprintf(str,"Cable short at %d.%d meters away",range>>1, range&1?5:0);
						else
							sprintf(str, "No cable detected");
					}else if(range&0x200){
						range&=0x1ff;
						if(range)
							sprintf(str,"Cable short at %d.%d meters away",range>>1, range&1?5:0);
						else
							sprintf(str, "No cable detected");
					}
					websWrite(wp,
					"<tr><td bgColor=#aaddff align=center>Port %d</td><td bgColor=#ddeeff>"\
					"Link is down. %s</td></tr>",  i, str);
				}
			}
		}
	}
	rtl8651_getIntfCounters(0x1, &counters);

	if(!((pRomeCfgParam->ifCfgParam[0].connType==IFCFGPARAM_CONNTYPE_USB_ETHERNET)||
	(pRomeCfgParam->ifCfgParam[0].connType==IFCFGPARAM_CONNTYPE_3G)))
	{
		websWrite(wp,"<tr><td bgColor=#aaddff>Received</td><td bgColor=#ddeeff>%ld packets, %ld bytes</td></tr>",
			counters[1],counters[0]);
		websWrite(wp,"<tr><td bgColor=#aaddff>Transmitted</td><td bgColor=#ddeeff>%ld packets, %ld bytes</td></tr>",
			counters[3],counters[2]);
		websWrite(wp,"<tr><td bgColor=#aaddff>Dropped</td><td bgColor=#ddeeff>%ld packets</td></tr>",
			counters[5]);
	}

	return 0;
}


/************************************************************
 *	
 *	Free-style flash editor
 *	
 ************************************************************/ 
int asp_flash(request * wp, int argc, char **argv)
{
	/* null output */
	websWrite(wp,"" );

	return 0;
}

int lengthAfterUrldecode( const char* pstr )
{
	int i, numOfPercent, orgLen;

	orgLen = strlen( pstr );
	numOfPercent = 0;
	for( i = 0; i < orgLen; i++ )
	{
		if ( pstr[i] == '%' ) 
		{
			numOfPercent++;
			i += 2;
		}
	}

	return orgLen - numOfPercent*2;
}

int hex2dec( char ch )
{
	if ( ch >= '0' && ch <= '9' ) return ch - '0';
	if ( ch >= 'a' && ch <= 'f' ) return ch - 'a' + 10;
	if ( ch >= 'A' && ch <= 'F' ) return ch - 'A' + 10;
	return 0;
}

void urldecode( char *dst, char *src, int nSize )  // nSize is the size of *dst.
{
	
	int i, j, orgLen;

	orgLen = strlen( src );
	for( i = 0, j = 0; j < nSize; i++, j++ )
	{
		if ( src[i] == '\0' )
		{
			break;
		}
		else if ( src[i] == '%' )
		{
			dst[j] = hex2dec( src[i+1] ) * 16 + hex2dec( src[i+2] );
			i += 2;
		}
		else
		{
			dst[j] = src[i];
		}
	}
}

void asp_setFlash(request * wp, char *path, char *query)
{
	int startOffset, endOffset;
	int firstBlockOffset, lastBlockOffset;
	unsigned char *pStartOffset = NULL;
	unsigned char *pContent = NULL;
	unsigned char *pContentOrg = NULL;
	unsigned char *pBuffer = NULL;
	int length = 0;
	uint32 lastBlockSize, totalBlockSize;
	int	i;

	pStartOffset = websGetVar(wp,"so","");
	if ( pStartOffset == NULL )
	{
		websWrite( wp, "pStartOffset is NULL" );
		goto out;
	}
	websWrite( wp, "pStartOffset=[%s]<BR>\n", pStartOffset );
	if ( !strncmp( pStartOffset, "0x", 2 ) )
	{
		// Heximal
		char* p = pStartOffset + 2;
		startOffset = 0;

		for( ; *p; p++ )
		{
			startOffset = startOffset * 16 + hex2dec( *p );
		}
	}
	else
	{
		startOffset = atoi( pStartOffset );
	}
	// websWrite( wp, "startOffset=0x%08x<BR>\n", startOffset );

	pContentOrg = websGetVar(wp,"co","");
	if ( pContentOrg == NULL )
	{
		websWrite( wp, "pContentOrg is NULL" );
		goto out;
	}
	// websWrite( wp, "pContentOrg=[%s]<BR>\n", pContentOrg );
	length = lengthAfterUrldecode( pContentOrg );
	endOffset = startOffset + length - 1;
	// websWrite( wp, "length=%d<BR>\n", length );

	pContent = malloc( length );
	if ( pContent == NULL )
	{
		websWrite( wp, "pContent is NULL" );
		goto out;
	}
	
	urldecode( pContent, pContentOrg, length );


#ifndef CONFIG_MTD

	//
	// Content may be across several blocks, so we must find out the first and the last block.
	//

	if ( flashdrv_getBlockSizeAndBlockOffset( startOffset, 0, NULL, &firstBlockOffset, NULL ) != 0 )
	{
		websWrite(wp,"<BR>\nflashdrv_getBlockSizeAndOffsetBase( startOffset=0x%08x ) returns FAILED.\n");
		goto out;
	}
	if ( flashdrv_getBlockSizeAndBlockOffset( endOffset, 0, NULL, &lastBlockOffset, &lastBlockSize ) != 0 )
	{
		websWrite(wp,"<BR>\nflashdrv_getBlockSizeAndOffsetBase( startOffset=0x%08x ) returns FAILED.\n");
		goto out;
	}

	// calculate buffer size
	totalBlockSize = ( lastBlockOffset + lastBlockSize ) - firstBlockOffset;

	{
		// OK
		pBuffer = malloc( totalBlockSize );
		
		// read into buffer
		flashdrv_read( pBuffer, flashdrv_getBlockBase(0)+firstBlockOffset, totalBlockSize );

		// modify buffer
		memcpy( pBuffer + ( startOffset - firstBlockOffset ), pContent, length );

		websWrite( wp, "asp_setFlash(): so=0x%08x co=", flashdrv_getBlockBase(0)+startOffset );
		if ( pContent ) for( i = 0; i < length; i++ ) websWrite( wp, "%02x-", pContent[i] );

		// websWrite( wp, "<BR>\n----------------------------------------------<BR>\n" );
		websWrite( wp, "<BR>\nflashdrv_updateImg(src=0x%08x,dst=0x%08x,size=0x%08x)<BR>\n",(uint32)pBuffer,(uint32)(flashdrv_getBlockBase(0)+firstBlockOffset), totalBlockSize );
		// if ( pBuffer ) for( i = 0; i < totalBlockSize; i++ ) websWrite( wp, "%02x-", pBuffer[i] );
		// websWrite( wp, "<BR>\n----------------------------------------------<BR>\n" );

#ifdef _SUPPORT_LARGE_FLASH_
		/* Load bdinfo first */
		flashdrv_read((void*)&bdinfo,(void*)FLASH_MAP_BOARD_INFO_ADDR,sizeof(bdinfo));
#endif/*_SUPPORT_LARGE_FLASH_*/

#if 0 /* for debug */
		if ( flashdrv_isLoaderOverwritten( flashdrv_getBlockBase(0)+firstBlockOffset, totalBlockSize ) == TRUE )
		{
			websWrite(wp,"<BR>\nLoader will damange." );
		}
		else
		{
			websWrite(wp,"<BR>\nLoader is safe.\n" );
		}
#endif   //end of #if 0
		// flush buffer to flash
		if ( flashdrv_updateImg( pBuffer, flashdrv_getBlockBase(0)+firstBlockOffset, totalBlockSize ) == 0 )
		{
			websWrite(wp,"<BR>\nUpdate OK" );
		}
		else
		{
			websWrite(wp,"<BR>\nUpdate failed. flashdrv_updateImg() return FAILED.\n" );
		}
	}
	
#else //ifdef CONFIG_MTD
      if( flashdrv_updateImg(pContent, mtd_dev.chipbase+startOffset, length)==0)
	{
		websWrite(wp,"<BR>\nUpdate OK" );
	}
	else
	{
		websWrite(wp,"<BR>\nUpdate failed. flashdrv_updateImg() return FAILED.\n" );
	}
	

#endif //end of #ifndef CONFIG_MTD


out:
	if ( pContent ) free( pContent );
	if ( pBuffer ) free( pBuffer );
}

int asp_webcam(request * wp, int argc, char **argv)
{

	int tp6800=0;
	if(strcmp(argv[0],"exist")==0)
 	{
		FILE *f;
	    f = fopen("/bin/quickcam", "rb");    
	    if(f==NULL)
	    {	
	    	websWrite(wp,"0");
	    }
	    else
	    {
	    	fclose(f);
			websWrite(wp,"1");	    	
	    }
	}
	else if(strcmp(argv[0],"start_server")==0)
 	{
		FILE *f;
		f = fopen("/etc/webcam_tp6800.o", "rb");
		if(f!=NULL) { tp6800=1; fclose(f); }
		
		websWrite(wp,"<html><head><title>Web Cam</title>%s</head><body>\n",(tp6800)?"<META HTTP-EQUIV=Refresh CONTENT=\"1; URL=webcam.asp\">":"");

		if(tp6800) // topro TP6800
		{
			system("/bin/tp6800");
			websWrite(wp,"<img src=\"tp6800.jpg\">");
		}
		else //logitech quickcam
		{
			f = fopen("/var/run/quickcam.pid", "r");    
			if(f==NULL)
			{	
				system("/bin/quickcam &");
				sleep(1);
			}
			else
			{
				fclose(f);
			}
			websWrite(wp,"<applet code=\"webcam.class\" width=\"352\" height=\"292\" codebase=\".\"></applet>");
		}		
		
		websWrite(wp,"</body></html>\n");
	}

	return 0;
}


/************************************************************
 *	
 *	Passthru
 *	
 ************************************************************/ 
int asp_passthru(request * wp, int argc, char **argv)
{
	websWrite(wp,"<B>Passthru Configuration</B><BR><BR>\n\
<form method=\"get\" action=\"/goform/asp_setPassthru\">\n\
<table cellSpacing=1 cellPadding=2 border=0>\n\
<tr><td bgColor=#aaddff>Passthru</td><td bgColor=#aaddff>Enabled</td></tr>\n" );

	websWrite(wp,"<tr><td bgColor=#ddeeff>PPPoE Passthru</td><td bgColor=#ddeeff><input type=checkbox name=pppoe value=1 %s></td></tr>\n", pRomeCfgParam->passthruCfgParam.enabledPppoe?"checked":"" );
	websWrite(wp,"<tr><td bgColor=#ddeeff>&nbsp;&nbsp;Drop Unknown PPPoE PADT</td><td bgColor=#ddeeff><input type=checkbox name=dropunknown value=1 %s></td></tr>\n", pRomeCfgParam->passthruCfgParam.enabledDropUnknownPppoePADT?"checked":"" );
	websWrite(wp,"<tr><td bgColor=#ddeeff>IPv6 Passthru</td><td bgColor=#ddeeff><input type=checkbox name=ipv6 value=1 %s></td></tr>\n", pRomeCfgParam->passthruCfgParam.enabledIpv6?"checked":"" );
	websWrite(wp,"<tr><td bgColor=#ddeeff>IPX Passthru</td><td bgColor=#ddeeff><input type=checkbox name=ipx value=1 %s></td></tr>\n", pRomeCfgParam->passthruCfgParam.enabledIpx?"checked":"" );
	websWrite(wp,"<tr><td bgColor=#ddeeff>NETBIOS Passthru</td><td bgColor=#ddeeff><input type=checkbox name=netbios value=1 %s></td></tr>\n", pRomeCfgParam->passthruCfgParam.enabledNetbios?"checked":"" );
	websWrite(wp,"<tr><td bgColor=#ddeeff>&nbsp;</td><td bgColor=#ddeeff><input type=submit value='Apply'></td></tr>\n" );

	websWrite(wp,"</table></form>\n" );

	return 0;
}

void asp_setPassthru(request * wp, char *path, char *query)
{
	uint32 *pInt;
	uint32 EnabledPppoe;
	uint32 DropUnknwon;
	uint32 EnabledIpv6;
	uint32 EnabledIpx;
	uint32 EnabledNetbios;
	
	pInt = websGetVar(wp,"pppoe","");
	EnabledPppoe = atoi( pInt );

	pInt = websGetVar(wp,"dropunknown","");
	DropUnknwon = atoi( pInt );

	pInt = websGetVar(wp,"ipv6","");
	EnabledIpv6 = atoi( pInt );

	pInt = websGetVar(wp,"ipx","");
	EnabledIpx = atoi( pInt );

	pInt = websGetVar(wp,"netbios","");
	EnabledNetbios = atoi( pInt );

	pRomeCfgParam->passthruCfgParam.enabledPppoe = EnabledPppoe;
	pRomeCfgParam->passthruCfgParam.enabledDropUnknownPppoePADT = DropUnknwon;
	pRomeCfgParam->passthruCfgParam.enabledIpv6 = EnabledIpv6;
	pRomeCfgParam->passthruCfgParam.enabledIpx = EnabledIpx;
	pRomeCfgParam->passthruCfgParam.enabledNetbios = EnabledNetbios;

	rtl8651_EnablePppoePassthru( EnabledPppoe );
	rtl8651_enableDropUnknownPppoePADT( DropUnknwon );
	rtl8651_EnableIpv6Passthru( EnabledIpv6 );
	rtl8651_EnableIpxPassthru( EnabledIpx );
	rtl8651_EnableNetbiosPassthru( EnabledNetbios );

	cfgmgr_write(CFGMGR_TABID_PASSTHRU,(void*)&pRomeCfgParam->passthruCfgParam, sizeof(struct passthruCfgParam_s));
	cfgmgr_task();
	websRedirect(wp, "/passthru.asp");
	
	return 0;
}

/************************************************************
 *	
 *	Ip Multicast
 *	
 ************************************************************/ 
int asp_mcast(request * wp, int argc, char **argv)
{
	websWrite(wp,"<B>IP Multicast Configuration</B><BR><BR>\n\
			<form method=\"get\" action=\"/goform/asp_setMcast\">\n\
			<table cellSpacing=1 cellPadding=2 border=0>\n" );

	websWrite(wp,"<td bgColor=#aaddff>IP Multicast</td><td bgColor=#ddeeff><input type=checkbox name=enable value=1 %s>Enable</td></tr>\n", pRomeCfgParam->ipMulticastCfgParam.enabledIpMulticast?"checked":"" );
	websWrite(wp,"<tr><td colspan=2 align=center><input type=submit name=smt value='Apply'></td></tr>");

	websWrite(wp,"</table></form>\n" );

	return 0;
}

void asp_setMcast(request * wp, char *path, char *query)
{
	uint32 EnabledMulticast;

	EnabledMulticast = atoi( websGetVar(wp,"enable","") );

	pRomeCfgParam->ipMulticastCfgParam.enabledIpMulticast = (EnabledMulticast)?TRUE:FALSE;

	rtl8651_EnablIpMulticast( pRomeCfgParam->ipMulticastCfgParam.enabledIpMulticast );

	cfgmgr_write(CFGMGR_TABID_IPMULTICAST, (void*)&pRomeCfgParam->ipMulticastCfgParam, sizeof(struct ipMulticastCfgParam_s));
	cfgmgr_task();
	websRedirect(wp, "/mcast.asp");
	
	return ;
}

int asp_IpsecExist(request * wp, int argc, char **argv)
{
#ifdef CONFIG_KLIPS
	websWrite(wp,"1");	    	
#else
	websWrite(wp,"0");	    	
#endif
	return 0;
}

#define SET_IPFIELD(outerTag , tagOption, name, u32value, ipIdx, startIdx) \
	do { \
		int __idx; \
		for ( __idx = startIdx ; __idx < (startIdx+4) ; __idx ++ ) \
		{ \
			websWrite(wp, "<%s %s> <input type=text size=3 maxlength=3 name=%s-%d-%d value=%d>", \
							outerTag, tagOption, name, ipIdx, __idx, ((u32value) >> ((4-__idx)*8)) & 0xff); \
			if (__idx < (startIdx + 3)) \
			{ \
				websWrite(wp, "."); \
			} \
			websWrite(wp, "</%s>", outerTag); \
		} \
	} while (0);
#define GET_IPFIELD(name, u32value, ipIdx, startIdx) \
	do { \
		int __idx; \
		char __tmp[64]; \
		u32value = 0; \
		for ( __idx = startIdx ; __idx < (startIdx+4) ; __idx ++ ) \
		{ \
			sprintf(__tmp, "%s-%d-%d\0", name, ipIdx, __idx); \
			u32value = (u32value << 8) + atoi( websGetVar(wp, __tmp, "") ); \
		} \
	} while (0);


int asp_domainBlock(request * wp, int argc, char **argv)
{
	int idx, i;
	int ms = asp_multiSession(wp, argc, argv);

	if (argc == 0)
	{
		websWrite(wp, "<form method=\"post\" action=\"/goform/asp_setDomainBlock\">");
		websWrite(wp, "<table cellSpacing=1 cellPadding=2 border=0 >\n");

		{
			websWrite(wp, "<input type=hidden name=ms value=%d>", ms);
			websWrite(wp, "	<tr> \
								<td bgColor=#aaddff>Blocked domain keyword</td> \
								<td bgColor=#aaddff>Source ip</td> \
								<td bgColor=#aaddff>Source mask</td> \
								<td bgColor=#aaddff>Enable</td> \
							</tr>");

			for ( idx = 0 ; idx < MAX_DOMAIN_BLOCKING ; idx ++ )
			{
				websWrite(wp, "<tr>");
				websWrite(wp, "	<td bgColor=#ddeeff> <input type=text size=%d maxlength=%d name=string%d value=\"%s\"></td>",
								(MAX_ALLOW_DOMAINNAME_LEN-1), (MAX_ALLOW_DOMAINNAME_LEN-1), idx, pRomeCfgParam->domainBlockCfgParam[idx].domain);


				websWrite(wp, "<td bgColor=#ddeeff><table><tr>");

				SET_IPFIELD("td", "bgColor=#ddeeff align=center", "sip", pRomeCfgParam->domainBlockCfgParam[idx].sip, idx, 1);

				websWrite(wp, "</tr></table></td>");

				websWrite(wp, "<td bgColor=#ddeeff><table><tr>");

				SET_IPFIELD("td", "bgColor=#ddeeff align=center", "smask", pRomeCfgParam->domainBlockCfgParam[idx].smask, idx, 1);

				websWrite(wp, "</tr></table></td>");

				websWrite(wp, "	<td bgColor=#ddeeff align=center> <input type=checkbox value=1 name=enabled%d %s></td>",
								idx, (pRomeCfgParam->domainBlockCfgParam[idx].enable == TRUE)?"checked":"");
				websWrite(wp, "</tr>");
			}

			websWrite(wp, "<tr><td colspan=2 align=center ><input type=submit value=\"Apply\"></td></tr>\n");
		}

		websWrite(wp, "</table>\n");
	}
}

void asp_setDomainBlock(request * wp, char *path, char *query)
{
	int idx;

	rtl8651_flushDomainBlockingEntry();

	for ( idx = 0 ; idx < MAX_DOMAIN_BLOCKING ; idx ++ )
	{
		char tmp[64];
		uint8 enable;

		/* enable */
		sprintf(tmp, "enabled%d\0", idx);
		enable = atoi( websGetVar(wp, tmp, "") );
		pRomeCfgParam->domainBlockCfgParam[idx].enable = enable?TRUE:FALSE;

		/* domain */
		sprintf(tmp, "string%d\0", idx);
		strncpy(pRomeCfgParam->domainBlockCfgParam[idx].domain, websGetVar(wp, tmp, ""), sizeof(pRomeCfgParam->domainBlockCfgParam[idx].domain));

		/* sip */
		GET_IPFIELD("sip", pRomeCfgParam->domainBlockCfgParam[idx].sip, idx, 1);
		/* smask */
		GET_IPFIELD("smask", pRomeCfgParam->domainBlockCfgParam[idx].smask, idx, 1);
		if (pRomeCfgParam->domainBlockCfgParam[idx].enable == TRUE)
		{
			if (rtl8651_addDomainBlockingEntry(	pRomeCfgParam->domainBlockCfgParam[idx].domain,
												pRomeCfgParam->domainBlockCfgParam[idx].sip,
												pRomeCfgParam->domainBlockCfgParam[idx].smask) != SUCCESS)
			{
				printf("Enable Add failed\n");
				pRomeCfgParam->domainBlockCfgParam[idx].enable = FALSE;
			}
		}
	}

	cfgmgr_write(CFGMGR_TABID_DOMAINBLOCK, (void*)pRomeCfgParam->domainBlockCfgParam, (sizeof(domainBlockCfgParam_t) * MAX_DOMAIN_BLOCKING));
	cfgmgr_task();
	websRedirect(wp, "/dblock.asp");
	
}

int asp_PptpExist(request * wp, int argc, char **argv)
{
#ifdef CONFIG_RTL865XB_PPTPSERVER
	websWrite(wp,"1");	    	
#else
	websWrite(wp,"0");	    	
#endif
	return 0;
}

#ifdef CONFIG_RTL865XB_PPTPSERVER
/************************************************************
 *	
 *	PPTP Server
 *	
 ************************************************************/
int asp_pptpServer(request * wp, int argc, char **argv)
{
	if(strcmp(argv[0],"range")==0)	
	{
		websWrite(wp,"%u.%u.%u.",pRomeCfgParam->ifCfgParam[1].ipAddr[0]
			,pRomeCfgParam->ifCfgParam[1].ipAddr[1]+1
			,pRomeCfgParam->ifCfgParam[1].ipAddr[2]);
	}

	else if(strcmp(argv[0],"range1")==0)	
	{
		websWrite(wp,"%u",pRomeCfgParam->pptpServerCfgParam.range1);
	}	

	else if(strcmp(argv[0],"range2")==0)	
	{
		websWrite(wp,"%u",pRomeCfgParam->pptpServerCfgParam.range2);
	}	

	else if(strcmp(argv[0],"username")==0)	
	{
		websWrite(wp,"%s",pRomeCfgParam->pptpServerCfgParam.username);
	}	

	else if(strcmp(argv[0],"password")==0)	
	{
		websWrite(wp,"%s",pRomeCfgParam->pptpServerCfgParam.password);
	}	

	else if(strcmp(argv[0],"dialStatus0")==0)	
	{
		if(pRomeCfgParam->pptpServerCfgParam.status==0) websWrite(wp,"checked");
	}	

	else if(strcmp(argv[0],"dialStatus0")==1)	
	{
		if(pRomeCfgParam->pptpServerCfgParam.status==1) websWrite(wp,"checked");
	}	

	
	return 0;
}

void asp_setPptpServer(request * wp, char *path, char *query)
{

	pRomeCfgParam->pptpServerCfgParam.range1=atoi(websGetVar(wp,"range1",""));
	pRomeCfgParam->pptpServerCfgParam.range2=atoi(websGetVar(wp,"range2",""));
	sprintf(pRomeCfgParam->pptpServerCfgParam.username,"%s",websGetVar(wp,"username",""));
	sprintf(pRomeCfgParam->pptpServerCfgParam.password,"%s",websGetVar(wp,"password",""));	
	pRomeCfgParam->pptpServerCfgParam.status=atoi(websGetVar(wp,"dialStatus",""));
	pptpServer_start();
	
	cfgmgr_write(CFGMGR_TABID_PPTPSERVER, (void*)&pRomeCfgParam->pptpServerCfgParam, sizeof(struct pptpServerCfgParam_s));
	cfgmgr_task();
	websRedirect(wp, "/pptp_basic.asp");
}
#endif

#ifdef CONFIG_KLIPS
void showIpsecBasic(request * wp,int tunnelno)
{
	char string1[10],string2[10];;

	websWrite(wp,"<html> <head> <meta http-equiv=\"Content-Type\" content=\"text/html\">\n");
	websWrite(wp,"<META HTTP-EQUIV=\"Pragma\" CONTENT=\"no-cache\">\n");
	websWrite(wp," <META HTTP-EQUIV=\"Cache-Control\" CONTENT=\"no-cache\">\n");
	websWrite(wp," <script language=\"javascript\">\n");
	websWrite(wp,"function TunnelChange(a)\n{formVPNBasic.TunnelName.value=a;\nformVPNBasic.submit();}\n");

	websWrite(wp,"function IpsecConnect(a)\n{frmIpsecConnect.startup.value=a;frmIpsecConnect.submit();}\n");
	websWrite(wp," </script> \n");
	websWrite(wp,"<title>VPN </title> </head> <body bgcolor=#ffffff text=#000000>\n");
	websWrite(wp,"<table cellSpacing=1 cellPadding=2 border=0>\n");
	websWrite(wp,"<form action=\"vpn_basic.asp\" name=formVPNBasic><input type=hidden value=1 name=TunnelName></form>");

	websWrite(wp,"\n<form method=\"get\" action=\"/goform/asp_IpsecConnect\" name=frmIpsecConnect><input type=hidden value=1 name=startup> </form>\n");
	websWrite(wp,"\n<form method=\"get\" action=\"/goform/asp_setIpsecBasic\" name=\"frm1\">");

	if (pRomeCfgParam->ipsecGlobalCfgParam.enableNatTraversal==1)
	{
		strcpy(string1,"checked");
		strcpy(string2,"unchecked");

	}
	else
	{
		strcpy(string1,"unchecked");
		strcpy(string2,"checked");

	}


	websWrite(wp,"<tr> <B>NAT Traversal</B>");
	websWrite(wp,"<input type=\"radio\" name=\"nattraversal\"  value=1 %s >Enable",string1);
	websWrite(wp,"<input type=\"radio\" name=\"nattraversal\"  value=0 %s >Disable</tr> ",string2);



	websWrite(wp,"<tr><td bgColor=#aaddff><B>Tunnel Name:</b> <select name=\"TunnelName\""); 
	websWrite(wp," onchange=\"TunnelChange(frm1.TunnelName.value);\">");
	switch(tunnelno)
	{
		case 0:
			websWrite(wp,"\n <option value=0 selected>Tunnel A</option>");
   		 	websWrite(wp," \n<option value=1 >Tunnel B</option>");
			websWrite(wp," \n<option value=2 >Tunnel C</option> </select>");
			break;

		case 1:

			websWrite(wp,"\n <option value=0 >Tunnel A</option>");
   		 	websWrite(wp," \n<option value=1 selected >Tunnel B</option>");
			websWrite(wp," \n<option value=2 >Tunnel C</option> </select>");
			break;
		case 2:
			websWrite(wp,"\n <option value=0 >Tunnel A</option>");
   		 	websWrite(wp,"\n<option value=1 >Tunnel B</option>");
			websWrite(wp,"\n<option value=2 selected>Tunnel C</option> </select></tr></td>");
			break;	


	}


	websWrite(wp,"\n<tr><td bgColor=#aaddff>This Tunnel</td> <td bgColor=#ddeeff>\n");
	websWrite(wp,"\n<input type=\"radio\" name=\"tunnel_enable\"  value=1 %s  >Enable\n",
	pRomeCfgParam->ipsecConfigCfgParam[tunnelno].enable?"checked":"uncheck");
	websWrite(wp," \n<input type=\"radio\" name=\"tunnel_enable\"  value=0 %s >Disable  </td> </tr>",  pRomeCfgParam->ipsecConfigCfgParam[tunnelno].enable?"unchecked":"checked");

	websWrite(wp,"  <tr><td bgColor=#aaddff>Local Security Group</td>\n");
	websWrite(wp,"  <td bgColor=#ddeeff> \n");
	websWrite(wp,"<input type=text name=localnet_1 size=3 maxlength=3 value=%u>.\n",
	(pRomeCfgParam->ipsecConfigCfgParam[tunnelno].localnet>>24)&0xff);
	websWrite(wp,"<input type=text name=localnet_2 size=3 maxlength=3 value=%u>.\n",
	(pRomeCfgParam->ipsecConfigCfgParam[tunnelno].localnet>>16)&0xff);
	websWrite(wp,"<input type=text name=localnet_3 size=3 maxlength=3 value=%u>.\n",
	(pRomeCfgParam->ipsecConfigCfgParam[tunnelno].localnet>>8)&0xff);
	websWrite(wp,"<input type=text name=localnet_4 size=3 maxlength=3 value=%u\n",
	(pRomeCfgParam->ipsecConfigCfgParam[tunnelno].localnet)&0xff);
	
	websWrite(wp,"	</td> \n</tr>\n\n\n");
	
	websWrite(wp," <tr><td bgColor=#aaddff>Remote Security Group</td>\n");
	websWrite(wp," <td bgColor=#ddeeff> \n");
	websWrite(wp,"<input type=text name=remotenet_1 size=3 maxlength=3 value=%u>.\n",
	(pRomeCfgParam->ipsecConfigCfgParam[tunnelno].remotenet>>24)&0xff);
	websWrite(wp,"<input type=text name=remotenet_2 size=3 maxlength=3 value=%u>.\n",
	(pRomeCfgParam->ipsecConfigCfgParam[tunnelno].remotenet>>16)&0xff);
	websWrite(wp,"<input type=text name=remotenet_3 size=3 maxlength=3 value=%u>.\n",
	(pRomeCfgParam->ipsecConfigCfgParam[tunnelno].remotenet>>8)&0xff);
	websWrite(wp,"<input type=text name=remotenet_4 size=3 maxlength=3 value=%u>\n",
	(pRomeCfgParam->ipsecConfigCfgParam[tunnelno].remotenet)&0xff);
	websWrite(wp,"</td> </tr>\n\n\n");

	websWrite(wp,"<tr><td bgColor=#aaddff>Remote Security Gateway</td>\n");
	websWrite(wp,"<td bgColor=#ddeeff>\n");
	websWrite(wp,"<input type=text name=remotegw_1 size=3 maxlength=3 value=%u>.\n",
	(pRomeCfgParam->ipsecConfigCfgParam[tunnelno].remotegw>>24)&0xff);
	websWrite(wp,"<input type=text name=remotegw_2 size=3 maxlength=3 value=%u>.\n",
	(pRomeCfgParam->ipsecConfigCfgParam[tunnelno].remotegw>>16)&0xff);
	websWrite(wp,"<input type=text name=remotegw_3 size=3 maxlength=3 value=%u>.\n",
	(pRomeCfgParam->ipsecConfigCfgParam[tunnelno].remotegw>>8)&0xff);
	websWrite(wp,"<input type=text name=remotegw_4 size=3 maxlength=3 value=%u>\n",
	(pRomeCfgParam->ipsecConfigCfgParam[tunnelno].remotegw)&0xff);
	websWrite(wp," 		</td> \n</tr>\n\n\n");


	
	if (pRomeCfgParam->ipsecConfigCfgParam[tunnelno].encryption==1)
	{
		strcpy(string1,"checked");
		strcpy(string2,"unchecked");

	}
	else
	{
		strcpy(string1,"unchecked");
		strcpy(string2,"checked");

	}

	websWrite(wp,"<tr><td bgColor=#aaddff>Encryption</td>\n");
	websWrite(wp,"<td bgColor=#ddeeff>\n");
	websWrite(wp,"<input type=\"radio\" name=\"ipsec_enc\"  value=1  %s>  3DES \n",string1);
	websWrite(wp," <input type=\"radio\" name=\"ipsec_enc\"  value=2 %s> AES\n",string2);
	websWrite(wp,"\n		 </td> \n</tr>\n\n\n\n");

	if (pRomeCfgParam->ipsecConfigCfgParam[tunnelno].authentication==1)
	{
		strcpy(string1,"checked");
		strcpy(string2,"unchecked");

	}
	else
	{
		strcpy(string1,"unchecked");
		strcpy(string2,"checked");

	}
  	websWrite(wp,"\n<tr><td bgColor=#aaddff>Authentication</td>\n");
	websWrite(wp," <td bgColor=#ddeeff>\n");
	websWrite(wp," <input type=\"radio\" name=\"ipsec_auth\"  value=1 %s > MD5\n",string1);
      	websWrite(wp," <input type=\"radio\" name=\"ipsec_auth\"  value=2 %s> SHA1\n",string2);
	websWrite(wp," </td> </tr>\n\n");

	websWrite(wp," <tr><td bgColor=#aaddff>Key Management</td>");
	websWrite(wp,"<td bgColor=#ddeeff>\n");
	websWrite(wp," </td> </tr>\n\n\n");

	websWrite(wp," <tr><td bgColor=#aaddff>Pre-shared Key</td>\n");
	websWrite(wp," <td bgColor=#ddeeff>\n");
	websWrite(wp,"<input type=text name=ipsec_secretkey size=30 maxlength=30 value=%s>\n",
	pRomeCfgParam->ipsecConfigCfgParam[tunnelno].secrets);
	websWrite(wp,"\n</td>\n");
	websWrite(wp,"</tr>\n\n\n");

	if (pRomeCfgParam->ipsecConfigCfgParam[tunnelno].pfs==1)
	{
		strcpy(string1,"checked");
		strcpy(string2,"unchecked");

	}
	else
	{
		strcpy(string1,"unchecked");
		strcpy(string2,"checked");

	}
	websWrite(wp,"\n<tr><td bgColor=#aaddff>Perfect Forward Secrecy</td> <td bgColor=#ddeeff>\n");
	websWrite(wp,"\n<input type=\"radio\" name=\"ipsec_pfs\"  value=1 %s >Enable\n",string1);
	websWrite(wp," \n<input type=\"radio\" name=\"ipsec_pfs\"  value=0 %s >Disable\n</td> \n</tr>",string2);




	
	websWrite(wp,"<tr><td bgColor=#aaddff>IPSEC Key Lifetime</td>\n");
	websWrite(wp," <td bgColor=#ddeeff>\n");
	websWrite(wp,"<input type=text name=ipsec_keylife size=8 maxlength=8 value=%u >Secs\n",
		pRomeCfgParam->ipsecConfigCfgParam[tunnelno].ipsec_keylife);
	websWrite(wp,"\n	 </td>\n </tr>\n\n\n");

	websWrite(wp,"<tr><td bgColor=#aaddff>ISAKMP  Key Lifetime</td>\n");
	websWrite(wp," <td bgColor=#ddeeff>\n");
	websWrite(wp,"<input type=text name=isakmp_keylife size=8 maxlength=8 value=%u >Secs\n",
		pRomeCfgParam->ipsecConfigCfgParam[tunnelno].isakmp_keylife);
	websWrite(wp,"\n	 </td>\n </tr>\n\n\n");


	websWrite(wp," \n<tr><td  align=center><input type=submit name=\"submitBtn\"");
	websWrite(wp," \nvalue=\"Save\"> &nbsp;&nbsp</td><td>");
	websWrite(wp,"");
	websWrite(wp," <input type=reset value=\"Cancel\"></td></tr>");

	websWrite(wp," \n<tr> <td  align=center>  <input type=button value=\"Connect\" name=submitBtn onClick=\"javascript:IpsecConnect(1);\"</td>\n");
	websWrite(wp,"\n<td aligen=center>  <input type=button value='Disconnect' name=submitBtn onClick='javascript:IpsecConnect(2);'</td> </tr>\n");
	websWrite(wp,"\n</form>\n </table>\n </body> \n</html>");


}
int asp_flashGetIpsec(request * wp, int argc, char **argv)
{

	int TunnelNo=atoi(websGetVar(wp,"TunnelName",""));
	showIpsecBasic(wp,TunnelNo);
	return 0;

}
int asp_GetIpsecStatus(request * wp, int argc, char **argv)
{

	FILE *fp;
	char linebuf[150];
	
	system("/usr/local/sbin/ipsec whack --status > /tmp/status.txt");
	fp=fopen("/tmp/status.txt","r");

	websWrite(wp,"<html><head><meta http-equiv=\"Content-Type\" content=\"text/html\">\n");
	websWrite(wp,"<title>Tuneel Status </title> </head> <body bgcolor=#ffffff text=#000000>\n");
	websWrite(wp,"<META HTTP-EQUIV=\"Pragma\" CONTENT=\"no-cache\">\n");
	websWrite(wp,"<META HTTP-EQUIV=\"Cache-Control\" CONTENT=\"no-cache\">\n");
	websWrite(wp,"<table cellSpacing=1 cellPadding=2 border=0>\n");
	 while(!feof(fp))	
	{	
		fgets(linebuf,sizeof(linebuf),fp);
		if (strstr(linebuf,"Tunnel")) websWrite(wp,"  <tr><td bgColor=#aaddff>%s</td></tr>",linebuf);
		
	}
	fclose(fp);
	websWrite(wp,"\n \n </table></html>");
	return 0;

}


void asp_setIpsecBasic(request * wp, char *path, char *query)
{	
	int i=0;
	char str[8];
	char temp1[40];
	unsigned char ip1,ip2,ip3,ip4,val;
	uint32 ip,val32;
	int tunnelno=atoi(websGetVar(wp,"TunnelName",""));

	val=atoi(websGetVar(wp,"tunnel_enable",""));
	if (val)
		pRomeCfgParam->ipsecConfigCfgParam[tunnelno].enable=1;
	else
		pRomeCfgParam->ipsecConfigCfgParam[tunnelno].enable=0;
 	val32=atol(websGetVar(wp,"ipsec_keylife",""));
	pRomeCfgParam->ipsecConfigCfgParam[tunnelno].ipsec_keylife=val32;
 	val32=atol(websGetVar(wp,"isakmp_keylife",""));
	pRomeCfgParam->ipsecConfigCfgParam[tunnelno].isakmp_keylife=val32;
	val=atoi(websGetVar(wp,"ipsec_enc",""));
	pRomeCfgParam->ipsecConfigCfgParam[tunnelno].encryption=val;
	val=atoi(websGetVar(wp,"ipsec_auth",""));
	pRomeCfgParam->ipsecConfigCfgParam[tunnelno].authentication=val;
	val=atoi(websGetVar(wp,"ipsec_pfs",""));
	pRomeCfgParam->ipsecConfigCfgParam[tunnelno].pfs=val;
	val=atoi(websGetVar(wp,"nattraversal",""));
	pRomeCfgParam->ipsecGlobalCfgParam.enableNatTraversal=val;
	ip1=atoi(websGetVar(wp,"localnet_1",""));
	ip2=atoi(websGetVar(wp,"localnet_2",""));
	ip3=atoi(websGetVar(wp,"localnet_3",""));
	ip4=atoi(websGetVar(wp,"localnet_4",""));
	ip=ip1<<24|ip2<<16|ip3<<8|ip4;
	pRomeCfgParam->ipsecConfigCfgParam[tunnelno].localnet=ip;
	ip1=atoi(websGetVar(wp,"remotenet_1",""));
	ip2=atoi(websGetVar(wp,"remotenet_2",""));
	ip3=atoi(websGetVar(wp,"remotenet_3",""));
	ip4=atoi(websGetVar(wp,"remotenet_4",""));
	ip=ip1<<24|ip2<<16|ip3<<8|ip4;
	pRomeCfgParam->ipsecConfigCfgParam[tunnelno].remotenet=ip;
	ip1=atoi(websGetVar(wp,"remotegw_1",""));
	ip2=atoi(websGetVar(wp,"remotegw_2",""));
	ip3=atoi(websGetVar(wp,"remotegw_3",""));
	ip4=atoi(websGetVar(wp,"remotegw_4",""));
	ip=ip1<<24|ip2<<16|ip3<<8|ip4;
	pRomeCfgParam->ipsecConfigCfgParam[tunnelno].remotegw=ip;
	strcpy(pRomeCfgParam->ipsecConfigCfgParam[tunnelno].secrets,
		websGetVar(wp,"ipsec_secretkey",""));
	cfgmgr_write(CFGMGR_TABID_IPSECCONFIG, (void*)&pRomeCfgParam->ipsecConfigCfgParam, sizeof(struct ipsecConfigCfgParam_s)*3);
	cfgmgr_write(CFGMGR_TABID_IPSECGLOBALCONFIG, (void*)&pRomeCfgParam->ipsecGlobalCfgParam, sizeof(struct ipsecGlobalCfgParam_s));
	cfgmgr_task();


	sprintf(temp1,"/vpn_basic.asp?TunnelName=%d",tunnelno);
	websRedirect(wp,temp1);
}

void asp_IpsecConnect(request * wp, char *path, char *query)
{
	char cmd[100];
	int startup=0;
	int tunnelno=0;

	tunnelno=atoi(websGetVar(wp,"TunnelName",""));
	startup = atoi(websGetVar(wp,"startup",""));
	if (startup==1)
		vpnIpsec_start(pRomeCfgParam->ifCfgParam[0].connType);
	else
	{
		sprintf(cmd,"/usr/local/sbin/ipsec whack --delete --name Tunnel%c",'A'+tunnelno);
		system(cmd);
	}
	
	sprintf(cmd,"/vpn_basic.asp?TunnelName=%d",tunnelno);
	websRedirect(wp,cmd);
}
#endif

/************************************************************
 *	
 *	BitTorrent
 *	
 ************************************************************/
int asp_bt(request * wp, int argc, char **argv)
{
#if 0
	DIR *dir;
	struct dirent *dire;
	
	if(strcmp(websGetVar(wp,"choise",""),"")!=0) //choise download files page
	{
		filelist_t *filelist;
		int shmid=-1,shmid1=-1;
		int i=0;
		bittorrent_t *bt;

		websWrite(wp,"<html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=big5\">\n" \
		"<title>BitTorrent</title>" \
		"</head>" \
		"<body bgcolor=\"#ffffff\" text=\"#000000\">" \
		"<B>BitTorrent Download</B><BR><BR>" );
		
		shmid1=shmget((key_t)SHM_BITTORRENT,sizeof(struct bittorrent_s),0666|IPC_CREAT);
		if(shmid1==-1) websRedirect(wp, "/bittorrent.asp");		
		bt=shmat(shmid1,(void*)0,0);
		if(bt->total_files==0) websRedirect(wp, "/bittorrent.asp");		
		
		shmid=shmget((key_t)SHM_BITTORRENT_FILELIST,bt->total_files*sizeof(struct filelist_s),0666|IPC_CREAT);
		if(shmid==-1) websRedirect(wp, "/bittorrent.asp");	
		filelist=shmat(shmid,(void*)0,0);

		websWrite(wp,"<form action=\"/goform/asp_setBt\"><table width=\"90%%\"><tr><td bgcolor=#aaddff>Index</td><td bgcolor=#aaddff>File name</td><td bgcolor=#aaddff>File Size</td><td bgcolor=#aaddff>Download</td></tr>\n");
		
		for(i=0;i<bt->total_files;i++)
		{
			if(filelist[i].filename==NULL) break;
			websWrite(wp,"<tr><td bgcolor=#ddeeff align=center>%d</td>" \
				"<td bgcolor=#ddeeff width=\"75%%\">%s</td>" \
				"<td bgcolor=#ddeeff align=right>%u</td>" \
				"<td bgcolor=#ddeeff align=center><input type=checkbox value=1 name='file%d'></td></tr>",i,filelist[i].filename,filelist[i].totalsize,i);
		}

		websWrite(wp,"</table><br><input type=submit value='Download' name='send'></form>\n");

		shmdt(bt);
		shmdt(filelist);
		return 0;
	}
	else if(strcmp(websGetVar(wp,"tPath",""),"")!=0) //choise torrent file page
	{

		websWrite(wp,"<html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=big5\">\n" \
		"<title>BitTorrent</title>" \
		"</head>" \
		"<body bgcolor=\"#ffffff\" text=\"#000000\">" \
		"<B>BitTorrent Download</B><BR><BR>" );
		
		dir=opendir(websGetVar(wp,"tPath",""));
		if(dir!=NULL)
		{		
			while(1)
			{
				dire=readdir(dir);
				if(dire==NULL) 
				{
					closedir(dir);
					websWrite(wp,"Sorry! Can't find any torrent files in '%s'. <a href='javascript:history.back();'>Back</a>",websGetVar(wp,"tPath",""));
					return 0;
				}
				if(strcmp(dire->d_name,".")==0) continue ;
				if(strcmp(dire->d_name,"..")==0) continue ;
				if(strlen(dire->d_name)<=8) continue;
				if(memcmp(&dire->d_name[strlen(dire->d_name)-8],".torrent",8)!=0) continue ;
				else break;
			}

			websWrite(wp,"<form action=\"/goform/asp_setBt\"><table><tr><td bgColor=#aaddff>Torrent File</td><td bgColor=#aaddff>Download</td></tr>\n");

			while(dire!=NULL)
			{
				
				if(strlen(dire->d_name)<=8) { dire=readdir(dir); continue;}
				if(memcmp(&dire->d_name[strlen(dire->d_name)-8],".torrent",8)!=0) { dire=readdir(dir); continue;	}
				websWrite(wp,"<tr><td bgColor=#ddeeff>%s</td><td align=center bgColor=#ddeeff><input type=radio name=\"torrent\" value=\"%s\"></td></tr>\n",dire->d_name,dire->d_name);
				dire=readdir(dir);			
			}

			closedir(dir);
			websWrite(wp,"</table><BR><table>\n");
			websWrite(wp,"<tr><td bgColor=#aaddff>Download path</td><td bgColor=#ddeeff><input value='/mnt' name='dlPath'></td></tr>\n");
			websWrite(wp,"<tr><td colspan=2>&nbsp;</td></tr>\n");			
			
			websWrite(wp,"</table><BR><input type=hidden name=tPath2 value='%s'><input type=submit value=\"Next >\"></form>",websGetVar(wp,"tPath",""));
			return 0;
			
		}
		else
		{
			websWrite(wp,"Sorry! Can't open the torrent file path!");
			return 0;
		}
	}
	else // input torrent file path page
	{
		FILE *f;
		f=fopen("/var/run/bt.pid","r");
		
		if(f==NULL)
		{		
			
			websWrite(wp,"<html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=big5\">\n" \
			"<title>BitTorrent</title>" \
			"</head>" \
			"<body bgcolor=\"#ffffff\" text=\"#000000\">" \
			"<B>BitTorrent Download</B><BR><BR>" );	
			
			websWrite(wp,"<form action=\"/goform/asp_setBt\"><table>" \
				"<tr><td  bgColor=#aaddff>Torrent File Path:</td>" \
				"<td  bgColor=#ddeeff><input value=\"/mnt\" name=\"torrentPath\"></td>" \
				"</tr><tr><td colspan=2 align=center><input type=submit name='send' value=\"Next >\">&nbsp;&nbsp;<input type=submit name='send' value='Mount Disk'>&nbsp;<input type=submit name='send' value='Unmount Disk'></td></tr>" \
				"</tr></table></form>");
		}
		else
		{
			filelist_t *filelist;
			int shmid=-1,shmid1=-1;
			int i=0;
			bittorrent_t *bt;

			websWrite(wp,"<html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=big5\">\n" \
			"<META HTTP-EQUIV=Refresh CONTENT=\"3; URL=bittorrent.asp\">" \
			"<title>BitTorrent</title>" \
			"</head>" \
			"<body bgcolor=\"#ffffff\" text=\"#000000\">" \
			"<B>BitTorrent Download</B><BR><BR>" );
			
			shmid1=shmget((key_t)SHM_BITTORRENT,sizeof(struct bittorrent_s),0666|IPC_CREAT);
			if(shmid1==-1) websRedirect(wp, "/bittorrent.asp");		
			bt=shmat(shmid1,(void*)0,0);
			if(bt->total_files==0) websRedirect(wp, "/bittorrent.asp");		
			
			shmid=shmget((key_t)SHM_BITTORRENT_FILELIST,bt->total_files*sizeof(struct filelist_s),0666|IPC_CREAT);
			if(shmid==-1) websRedirect(wp, "/bittorrent.asp");	
			filelist=shmat(shmid,(void*)0,0);
			
			websWrite(wp,"<form action=\"/goform/asp_setBt\"><table width=\"95%%\"><tr><td bgcolor=#aaddff>Index</td><td bgcolor=#aaddff>File name</td><td bgcolor=#aaddff>Finished</td><td bgcolor=#aaddff>Downloaded Size</td><td bgcolor=#aaddff>File Size</td></tr>\n");
			
			for(i=0;i<bt->total_files;i++)
			{
				char temp[32];
				if(filelist[i].filename==NULL) break;
				if(filelist[i].interested==0) continue;
				sprintf(temp,"%3.3f",(double)filelist[i].downloaded/(double)filelist[i].totalsize*100);
				
				websWrite(wp,"<tr><td bgcolor=#ddeeff align=center>%d</td>" \
					"<td bgcolor=#ddeeff width=\"72%%\">%s</td>" \
					"<td bgcolor=#ddeeff align=right width=\"8%%\">%s%%</td>" \
					"<td bgcolor=#ddeeff align=right width=\"8%%\">%u</td>" \
					"<td bgcolor=#ddeeff align=right width=\"8%%\">%u</td></tr>",i,filelist[i].filename,temp,filelist[i].downloaded,filelist[i].totalsize);
			}
			websWrite(wp,"</table><br><input type=submit value='Stop' name='send'></form>\n");

			shmdt(bt);
			shmdt(filelist);
		}
	}
#endif
	return 0;
}
void asp_setBt(request * wp, char *path, char *query)
{
#if 0
	if(strcmp(websGetVar(wp,"send",""),"Stop")==0)
	{		
		send_signal("/var/run/bt.pid",SIGUSR2);
		sleep(1);
	}	
	else if(strcmp(websGetVar(wp,"send",""),"Download")==0)
	{
		filelist_t *filelist;
		int shmid=-1,shmid1=-1;
		int i=0;
		bittorrent_t *bt;
		char temp[10];

		
		shmid1=shmget((key_t)SHM_BITTORRENT,sizeof(struct bittorrent_s),0666|IPC_CREAT);
		if(shmid1==-1) websRedirect(wp, "/bittorrent.asp");		
		bt=shmat(shmid1,(void*)0,0);
		if(bt->total_files==0) websRedirect(wp, "/bittorrent.asp");		
		
		shmid=shmget((key_t)SHM_BITTORRENT_FILELIST,bt->total_files*sizeof(struct filelist_s),0666|IPC_CREAT);
		if(shmid==-1) websRedirect(wp, "/bittorrent.asp");
		filelist=shmat(shmid,(void*)0,0);		

		for(i=0;i<bt->total_files;i++)
		{
			sprintf(temp,"file%d",i);
			if(strcmp(websGetVar(wp,temp,""),"")!=0)
			{
				filelist[i].interested=1;
				printf("interested %d\n",i);
			}
		}
		send_signal("/var/run/bt.pid",SIGUSR1);
		
	}
	else if(strcmp(websGetVar(wp,"send",""),"Mount Disk")==0)
	{
		system("mount -t vfat /dev/sda1 /mnt");
	}
	else if(strcmp(websGetVar(wp,"send",""),"Unmount Disk")==0)
	{
		system("umount /mnt");
	}
	else if(strcmp(websGetVar(wp,"torrent",""),"")!=0)
	{
		char temp[320];
		char path[160]={0};
		memcpy(path,websGetVar(wp,"tPath2",""),strlen(websGetVar(wp,"tPath2","")));
		if(path[strlen(path)-1]!='/') path[strlen(path)]='/';		
		sprintf(temp,"/bin/bt %s%s %s &",path,websGetVar(wp,"torrent",""),websGetVar(wp,"dlPath",""));
		printf("run: %s\n",temp);
		system(temp);
		sleep(2);
		websRedirect(wp, "/bittorrent.asp?choise=1");
		return;
	}
	else if(strcmp(websGetVar(wp,"torrentPath",""),"")!=0)
	{
		char temp[128];
		sprintf(temp,"/bittorrent.asp?tPath=%s\n",websGetVar(wp,"torrentPath",""));
		websRedirect(wp, temp);
		return;
	}

	websWrite(wp,"</body></html>");
#endif
	websRedirect(wp, "/bittorrent.asp");
	return;
}

/* ===================================================================================
		APIs for system verification
    =================================================================================== */
#ifdef CONFIG_SYSTEM_VERIFICATION

void asp_romeDrvCtrl(request * wp, char * path, char * query)
{
	char *function = NULL;

	#define STRING_EQUAL(s1, s2)	((strlen(s1) == strlen(s2)) && (strcmp(s1, s2) == 0))

	/* Function name */
	function = websGetVar(wp, "function", "");

	printf("[%s -- %d] Function: %s\n", __FUNCTION__, __LINE__, function);

	if (STRING_EQUAL(function, "pure-sw"))
	{
		int enable;

		/* enable or disable */
		enable = atoi( websGetVar(wp, "enable", "") );

		printf("[%s -- %d] %s %s.\n", __FUNCTION__, __LINE__, enable?"Enable":"Disable", function);

		switch (enable)
		{
			case 0:
				rtl8651_pureSoftwareFwd(FALSE);
				break;
			case 1:
				rtl8651_pureSoftwareFwd(TRUE);
				break;
		}
	}

	websRedirect(wp, "/status.asp");

}


#endif /* CONFIG_SYSTEM_VERIFICATION */


#else	/* #if !defined(DNI) */



struct circ_buf {
	int size;			
	int head;			
	int tail;			
	char data[1];		
};

struct circ_buf *getCircBufPtrByModuleId(int moduleId)
{
		int tmp_moduleId = moduleId;
		int idx = 0,i;
		uint32 ptr;
		int shmid;
		FILE *f;
		struct circ_buf *buf;
		
		while (tmp_moduleId>1)
		{
			idx ++;
			tmp_moduleId = tmp_moduleId >> 1;
		}
		
		switch(moduleId)
		{
			case RTL8651_LOGMODULE_SYS:
				if ((shmid = shmget(0x414e4547, 16000+sizeof(struct circ_buf), IPC_CREAT | 0666)) == -1) {
					return -1;
				}
				if ((buf = shmat(shmid, NULL, 0)) == NULL) {
					return -1;
                }				
				break;
			case RTL8651_LOGMODULE_ACL:
			case RTL8651_LOGMODULE_DOS:
			case RTL8651_LOGMODULE_URL:
			case RTL8651_LOGMODULE_NEWFLOW:
				f = fopen("/proc/log_module","r");
				if(f==NULL) return -1;
				for(i=0;i<idx;i++)
					fscanf(f,"%x",&ptr);
				fscanf(f,"%x",&ptr);
				fclose(f);
				if(ptr==0) return -1;
#ifdef __uClinux__
				buf=ptr;	
#else		
				buf=rtl865x_kmmap(ptr-0x80000000,sizeof(struct circ_buf)+16000);
#endif					
				break;	
		}
		return buf;
}

int asp_addRateLimitRule(rateLimitEntry_t *rlrule_t, uint32 entry)
{
	int8 *ifName[] = { "eth1", "eth0" };
	rtl8651_tblDrvAclRule_t rule;
	uint32 ifIndex, rate, maxRate;
	

	/* Add a rule to Rome Driver */
	if (rlrule_t->rateUnit == 0)
		rate = (1000 * rlrule_t->rate) >> 3;
	else rate = (1000 * 1000 * rlrule_t->rate) >> 3;
	if (rlrule_t->maxRateUnit == 0)
		maxRate = (1000 * rlrule_t->maxRate) >> 3;
	else maxRate = (1000 * 1000 *rlrule_t->maxRate) >> 3;
	
	ifIndex = entry >> 3;
	rtl8651_addRateLimitGroup(1000+entry, ifName[ifIndex], rate, maxRate, rlrule_t->isByteCount);
	bzero(&rule, sizeof(rtl8651_tblDrvAclRule_t));

	/* Action Type */
	if (rlrule_t->isDropLog == TRUE)
		rule.actionType_ = RTL8651_ACL_DROP_LOG;
	else rule.actionType_ = RTL8651_ACL_DROP;
	
	/* rule Type */
	switch (rlrule_t->protoType) {

	case 0: /* TCP */
		rule.ruleType_	= RTL8651_ACL_TCP;
		if (rlrule_t->isSrcIp == TRUE) {
			rule.tcpSrcPortUB_	= rlrule_t->e_port;
			rule.tcpSrcPortLB_	= rlrule_t->s_port;
			rule.tcpDstPortUB_	= 65535;
			rule.tcpDstPortLB_	= 0;
		}
		else {
			rule.tcpDstPortUB_	= rlrule_t->e_port;
			rule.tcpDstPortLB_	= rlrule_t->s_port;
			rule.tcpSrcPortUB_	= 65535;
			rule.tcpSrcPortLB_	= 0;
		}
		goto comm_L3;

	case 1: /* UDP */
		rule.ruleType_	= RTL8651_ACL_UDP;
		if (rlrule_t->isSrcIp == TRUE) {
			rule.udpSrcPortUB_		= rlrule_t->e_port;
			rule.udpSrcPortLB_		= rlrule_t->s_port;
			rule.udpDstPortUB_		= 65535;
			rule.udpDstPortLB_		= 0;
		}
		else {
			rule.udpDstPortUB_		= rlrule_t->e_port;
			rule.udpDstPortLB_		= rlrule_t->s_port;
			rule.udpSrcPortUB_		= 65535;
			rule.udpSrcPortLB_		= 0;
		}
		goto comm_L3;

	case 2: /* IP */
		rule.ruleType_ = RTL8651_ACL_IP;
comm_L3:
		if (rlrule_t->isSrcIp == TRUE) {
			rule.srcIpAddr_		= rlrule_t->ip;
			rule.srcIpAddrMask_	= rlrule_t->ipMask;
		}
		else {
			rule.dstIpAddr_		= rlrule_t->ip;
			rule.dstIpAddrMask_	= rlrule_t->ipMask;
		}
		break;
	
	default: return 1;
	}
	rtl8651_addRateLimitRule(&rule, 1000+entry);
	return 0;
}

void rearrange_Ratio_Qos(void)
{
	int i;

	/* Inite ratio QoS */
	//rtl8651_setUpstreamBandwidth("eth0", 0);
	
	/* set upstream bw */
	if (pRomeCfgParam->ratioQosCfgParam.enable == TRUE) {
		rtl8651_setUpstreamBandwidth("eth0",
			(pRomeCfgParam->ratioQosCfgParam.upInfo.maxRateUnit == 0)?
				(pRomeCfgParam->ratioQosCfgParam.upInfo.maxRate * 1000 * 1000):
				(pRomeCfgParam->ratioQosCfgParam.upInfo.maxRate * 1000));
	}
	
	/* set all entries */
	for (i = 0 ; i < MAX_RATIO_QOS ; i ++)
	{
		ratioQosEntry_t* entry;

		entry = &(pRomeCfgParam->ratioQosCfgParam.entry[i]);
		if (entry->enable)
		{
			rtl8651_tblDrvAclRule_t rule;

			memset(&rule, 0, sizeof(rtl8651_tblDrvAclRule_t));
			rule.actionType_ = RTL8651_ACL_DROP;
			switch(entry->protoType) {

			case 0: /* TCP */
				rule.ruleType_	= RTL8651_ACL_TCP;
				if (entry->isSrc == TRUE) {
					rule.tcpSrcPortUB_		= entry->e_port;
					rule.tcpSrcPortLB_		= entry->s_port;
					rule.tcpDstPortUB_		= 65535;
					rule.tcpDstPortLB_		= 0;
				}
				else {
					rule.tcpDstPortUB_		= entry->e_port;
					rule.tcpDstPortLB_		= entry->s_port;
					rule.tcpSrcPortUB_		= 65535;
					rule.tcpSrcPortLB_		= 0;
				}
				goto comm_L3;

			case 1: /* UDP */
				rule.ruleType_	= RTL8651_ACL_UDP;
				if (entry->isSrc == TRUE) {
					rule.udpSrcPortUB_	= entry->e_port;
					rule.udpSrcPortLB_		= entry->s_port;
					rule.udpDstPortUB_	= 65535;
					rule.udpDstPortLB_		= 0;
				}
				else {
					rule.udpDstPortUB_	= entry->e_port;
					rule.udpDstPortLB_		= entry->s_port;
					rule.udpSrcPortUB_	= 65535;
					rule.udpSrcPortLB_		= 0;
				}
				goto comm_L3;

			default: /* IP */
				rule.ruleType_ = RTL8651_ACL_IP;
comm_L3:
				if (entry->isSrc == TRUE) {
					rule.srcIpAddr_		= entry->ip;
					rule.srcIpAddrMask_	= entry->ipMask;
				}
				else {
					rule.dstIpAddr_		= entry->ip;
					rule.dstIpAddrMask_	= entry->ipMask;
				}
			}

			if (entry->isHigh)
			{			
				rtl8651_addFlowToUnlimitedQueue("eth1", &rule, entry->ratio, entry->queueID);

				if (entry->mark == 1)
				{
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) entry->dscp);
				}
#if 0
				switch(entry->priority)
				{
 				case 0:	/* BE */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0x00);
					break;
				case 1:	/* AF4 */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0x28);
					break;
				case 2:	/* AF3 */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0x48);
					break;
				case 3:	/* AF2 */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0x68);
					break;
				case 4:	/* AF1 */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0x88);
					break;
				case 5:	/* EF */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0xB8);
					break;
				default:
					break;
				}
#endif
			}else
			{
				rtl8651_addFlowToLimitedQueue("eth1", &rule, entry->ratio, entry->queueID);

				if (entry->mark == 1)
				{
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) entry->dscp);
				}
#if 0
				switch(entry->priority)
				{
				case 0:	/* BE */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0x00);
					break;
				case 1:	/* AF4 */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0x28);
					break;
				case 2:	/* AF3 */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0x48);
					break;
				case 3:	/* AF2 */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0x68);
					break;
				case 4:	/* AF1 */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0x88);
					break;
				case 5:	/* EF */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0xB8);
					break;
				default:
					break;
				}
#endif
			}
		}
	}
}

inline int _checkImage(FILE *fp, uint32 startPos, uint32 size)
{
	fileImageHeader_t	imghdr;
	uint8			*pdata;
	int				i;
	int				len;
	uint8			chksum;
#define CHKSUM_BUFF_SIZE			1024
	uint8			buffer[CHKSUM_BUFF_SIZE];

	printf("Check correctness of Image (size: %u)\n", size);

	/*
		check total size
	*/
	/* Load bdinfo first */
	flashdrv_read((void*)&bdinfo,(void*)FLASH_MAP_BOARD_INFO_ADDR,sizeof(bdinfo));

	printf("startPos=%u size=%u bdinfo.rootMaxSize=%u\n",startPos,size,bdinfo.rootMaxSize);
	
	if (size > bdinfo.rootMaxSize)
	{
		printf("Total Size (%u) exceeds Flash Size (%u)\n", size, bdinfo.rootMaxSize);
		goto check_fail;
	}

	fseek(fp, startPos, SEEK_SET);



	/*
		get image header
	*/
	if (size < sizeof(fileImageHeader_t))
	{
		printf("Image size(%d) is too small!\n", size);
		goto check_fail;
	}

	if (fread((void *)&imghdr, 1, sizeof(fileImageHeader_t), fp) == NULL)
	{
		printf("Image header (size : %d) parse fail!\n", size);
		goto check_fail;
	}

	{
		uint16 tmp16_d;
		printf("Get Image Header Success :\n");
		tmp16_d = imghdr.date >> 16;
		printf("================================================\n");
		printf("\tVersion: %d\n", imghdr.imageHdrVer);
		printf("\tTime: %u/%u/%u %u:%u:%u\n", ntohs(tmp16_d), ((imghdr.date>>8)&0xff), imghdr.date&0xff,
											(imghdr.time >> 16)&0xff, (imghdr.time >> 8)&0xff, imghdr.time&0xff);
		printf("\tMagic Number: %x\n", imghdr.productMagic);
		printf("\tHeader checksum: %x\n", imghdr.imageHdrCksm);
		printf("\tBody checksum: %x\n", imghdr.imageBdyCksm);
		printf("\tImage Type: %x\n", imghdr.imageType);
		printf("\tImage Length: %d\n", imghdr.imageLen);
		printf("================================================\n");
	}

	/* Check image length */
	if (imghdr.imageLen != (size - sizeof(fileImageHeader_t)))
	{
		printf("Image size mismatch (%d : %d) !\n", size - sizeof(fileImageHeader_t), imghdr.imageLen);
		goto check_fail;
	}

	/* Check product magic number */
	if (imghdr.productMagic != RTL_PRODUCT_MAGIC)
	{
		printf("Image product magic number(%x) error!\n", imghdr.productMagic);
		goto check_fail;
	}

	/* Check image type (For ROMFS, CRAMFS, and SQUASHFS) */
	if ((imghdr.imageType != RTL_IMAGE_TYPE_RUN)&&
	    (imghdr.imageType != RTL_IMAGE_TYPE_KFS))
	{
		printf("Image type(%x) error!\n", imghdr.imageType);
		goto check_fail;
	}

	/* Check image header checksum */
	pdata = (uint8 *)&imghdr;
	len = sizeof(fileImageHeader_t) - 1;
	chksum = 0;

	for (i=0; i<len; i++)
		chksum ^= *pdata++;

	if ( chksum != imghdr.imageHdrCksm )
	{
		printf("Image header checksum mismatch (%x : %x)!\n", chksum, imghdr.imageHdrCksm);
		goto check_fail;
	}
    
	/* Check body checksum */
	len = (size - sizeof(fileImageHeader_t));
	chksum = 0;

	/* get Image from file */
	while (len > 0)
	{
		int buflen;

		/**/
		if (len > CHKSUM_BUFF_SIZE)
		{
			buflen = CHKSUM_BUFF_SIZE;
			len -= CHKSUM_BUFF_SIZE;
		}else
		{
			buflen = len;
			len = 0;
		}

		if (fread((void *)&buffer, 1, buflen, fp) == NULL)
		{
			printf("Image body (size : %d) parse fail!\n", size);
			goto check_fail;
		}

		pdata = buffer;
		for ( i=0 ; i<buflen ; i++ )
		{
			chksum ^= *pdata++;
		}
	}

#undef CHKSUM_BUFF_SIZE

	if ( chksum != imghdr.imageBdyCksm )
	{
		printf("Image checksum mismatch (%x : %x)!\n", chksum, imghdr.imageBdyCksm);
		goto check_fail;
	}

	printf("Image Correctness Check OK !\n");
	
	return 0;

check_fail:
	printf("Image Correctness Check FAILED !\n");
	return -1;
}

#endif		/* #if defined(DNI) */

