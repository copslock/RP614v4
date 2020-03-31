/*
 * Copyright c                Realtek Semiconductor Corporation, 2003
 * All rights reserved.
 * 
 * $Header: /home/cvsroot/uClinux-dist/user/boa/src/rtl865x/rtl_cfgmgr.h,v 1.5 2005/06/30 07:28:53 chenyl Exp $
 *
 * $Author: chenyl $
 *
 * Abstract: rtl_cfgmgr.h -- configuration manager module external header file
 *
 * $Log: rtl_cfgmgr.h,v $
 * Revision 1.5  2005/06/30 07:28:53  chenyl
 * *: commit some unnacessary code
 *
 * Revision 1.4  2005/06/29 12:13:46  chenyl
 * *: modify CFGMGR version.
 * *: still check entry if version is different (because version difference means that new configuration is added)
 *
 * Revision 1.3  2005/06/29 05:22:19  chenyl
 * +: TLV based configuration setting.
 *
 * Revision 1.2  2005/05/04 02:35:01  shliu
 * *: add CFGMGR_TABID_MODE
 *
 * Revision 1.1  2005/04/19 04:58:15  tony
 * +: BOA web server initial version.
 *
 * Revision 1.32  2004/12/28 09:50:48  rupert
 * +: Add IPSEC Support
 *
 * Revision 1.31  2004/11/16 02:30:30  shliu
 * *** empty log message ***
 *
 * Revision 1.30  2004/10/05 09:20:42  chenyl
 * +: web page to turn ON/OFF ip-multicast system
 *
 * Revision 1.29  2004/10/01 07:52:55  yjlou
 * +: add enable/disable PPPoE Passthru and IPv6 Passthru
 *
 * Revision 1.28  2004/09/03 03:00:10  chhuang
 * +: add new feature: pseudo VLAN
 *
 * Revision 1.27  2004/08/18 05:39:59  chenyl
 * +: napt special option web-based setting
 *
 * Revision 1.26  2004/08/13 06:03:19  cfliu
 * -: Remove WLAN2 cfg table
 *
 * Revision 1.25  2004/07/14 13:55:59  chenyl
 * +: web page for MN queue
 *
 * Revision 1.24  2004/07/07 05:56:39  tony
 * *: fix tabid bug.
 *
 * Revision 1.23  2004/07/07 05:12:36  chhuang
 * +: add a new WAN type (DHCP+L2TP). But not complete yet!!
 *
 * Revision 1.22  2004/07/06 06:20:58  chhuang
 * +: add rate limit
 *
 * Revision 1.21  2004/06/08 10:57:57  cfliu
 * +: Add WLAN dual mode support. Not yet completed...
 *
 * Revision 1.20  2004/05/28 09:49:16  yjlou
 * +: support Protocol-Based NAT
 *
 * Revision 1.19  2004/05/20 08:43:55  chhuang
 * add Web Page for QoS
 *
 * Revision 1.18  2004/05/19 08:40:50  orlando
 * checkin init button,diag led,bicolor led related code
 *
 * Revision 1.17  2004/05/12 05:15:05  tony
 * support PPTP/L2TP in RTL865XB.
 *
 * Revision 1.16  2004/04/08 13:18:12  tony
 * add PPTP/L2TP routine for MII lookback port.
 *
 * Revision 1.15  2004/03/31 01:59:36  tony
 * add L2TP wan type UI pages.
 *
 * Revision 1.14  2004/03/03 03:43:32  tony
 * add static routing table in turnkey.
 *
 * Revision 1.13  2004/02/03 08:14:34  tony
 * add UDP Blocking web UI configuration.
 *
 * Revision 1.12  2004/01/07 09:10:04  tony
 * add PPTP Client UI in Config Wizard.
 *
 * Revision 1.11  2003/12/19 04:33:01  tony
 * add Wireless Lan config pages: Basic Setting, Advance Setting, Security, Access Control, WDS
 *
 * Revision 1.10  2003/12/01 12:35:52  tony
 * make ALG is able to be configured by users(Web GUI).
 *
 * Revision 1.9  2003/10/24 10:25:58  tony
 * add DoS attack interactive webpage,
 * FwdEngine is able to get WAN status by rtl8651_wanStatus(0:disconnect,1:connect)
 *
 * Revision 1.8  2003/10/03 12:27:35  tony
 * add NTP time sync routine in management web page.
 *
 * Revision 1.7  2003/10/01 05:57:31  tony
 * add URL Filter routine
 *
 * Revision 1.6  2003/09/23 03:47:29  tony
 * add ddnsCfgParam,ddnsDefaultFactory,ddns_init
 *
 * Revision 1.5  2003/09/22 08:01:45  tony
 * add UPnP Web Configuration Function Routine
 *
 * Revision 1.4  2003/09/22 06:33:37  tony
 * add syslogd process start/stop by CGI.
 * add eventlog download/clear routine.
 *
 * Revision 1.3  2003/09/19 06:06:51  tony
 * *** empty log message ***
 *
 * Revision 1.2  2003/09/19 01:43:50  tony
 * add dmz routine
 *
 * Revision 1.1.1.1  2003/08/27 06:20:15  rupert
 * uclinux initial
 *
 * Revision 1.1.1.1  2003/08/27 03:08:53  rupert
 *  initial version 
 *
 * Revision 1.13  2003/07/21 05:02:34  orlando
 * check-in for v0.3.1.
 *
 * Revision 1.12  2003/07/01 03:08:25  tony
 * add aclGlobalCfgParam factory default.
 *
 * Revision 1.11  2003/06/30 07:46:40  tony
 * add ACL and Server_Port structure
 *
 * Revision 1.10  2003/06/23 11:03:30  elvis
 * change include path of  rtl_types.h
 *
 * Revision 1.9  2003/06/20 13:00:28  tony
 * add dhcp client
 *
 * Revision 1.8  2003/06/16 08:08:43  tony
 * add dhcps & dns function
 *
 * Revision 1.7  2003/06/06 11:57:41  orlando
 * add pppoe cfg.
 *
 * Revision 1.6  2003/06/06 06:30:26  idayang
 * add mgmt table in cfgmgr.
 *
 * Revision 1.5  2003/06/03 10:57:17  orlando
 * add nat table in cfgmgr.
 *
 * Revision 1.4  2003/05/20 08:45:21  elvis
 * change the include path of "rtl_types.h"
 *
 * Revision 1.3  2003/05/09 15:34:09  orlando
 * patch due to sysHwInit() cannot start the cfgmgr maintenance task.
 *
 * Revision 1.2  2003/05/02 09:21:00  orlando
 * make cfgmgr_init() called implicitly by 1st cfgmgr_read()
 * or cfgmgr_write() access.
 *
 * Revision 1.1  2003/04/29 14:18:10  orlando
 * cfgmgr module initial check-in.
 *
 */

#ifndef _rtl_cfgmgr_h_
#define _rtl_cfgmgr_h_

#include "rtl_types.h"
#include <linux/config.h>

/**********************************************************************************

	System pre-defined value/MACRO declarations

  **********************************************************************************/

/* <---- Constant Decalarations ----> */
#define CFGMGR_SIGNATURE_LENGTH	8
#define CFGMGR_SIGNATURE			"rome" /* length should be < CFGMGR_SIGNATURE_LENGTH -1 */
#define CFGMGR_VERSION				1

#define CFGMGR_TABLEID_NULL		0		/* invalid table ID */

/* <---- flash interface ----> */
#define FLASH_BDINFO	(FLASH_MAP_BOARD_INFO_ADDR)
#define FLASH_CCFG		(FLASH_MAP_CCFG_IMAGE_ADDR)
#define FLASH_ALIGN		4								/* 4 bytes alignment */

/* <---- debug message ----> */
#define CFGMGR_DEBUG
#define CFGMGR_MSG_MASK			0xfffffffe	/* Tune ON all debug messages besides INFO */
#define CFGMGR_MSG_INFO			(1<<0)
#define CFGMGR_MSG_WARN			(1<<1)
#define CFGMGR_MSG_ERR				(1<<2)

#ifdef CFGMGR_DEBUG

#define CFGMGR_INFO(fmt, args...) \
	if (CFGMGR_MSG_MASK&CFGMGR_MSG_INFO) \
		do {printf("[%s-%d]-info-: " fmt "\n", __FUNCTION__, __LINE__, ## args); fflush(stdout);} while (0);
#define CFGMGR_WARN(fmt, args...) \
	if (CFGMGR_MSG_MASK&CFGMGR_MSG_WARN) \
		do {printf("[%s-%d]-warning-: " fmt "\n", __FUNCTION__, __LINE__, ## args); fflush(stdout);} while (0);
#define CFGMGR_ERR(fmt, args...) \
	if (CFGMGR_MSG_MASK&CFGMGR_MSG_ERR) \
		do {printf("[%s-%d]-error-: " fmt "\n", __FUNCTION__, __LINE__, ## args); fflush(stdout);} while (0);

#else

#define CFGMGR_INFO(fmt, args...)
#define CFGMGR_WARN(fmt, args...)
#define CFGMGR_ERR(fmt, args...)

#endif	/* CFGMGR_DEBUG */

/* <---- Internal control ----> */
#define CFGMGR_HALT(dummy)	{printf("%s(%d).. System HALT\n", __FUNCTION__, __LINE__);while(1);}

/* configuration stage control */
/*
  *	To configure CFGMGR system, user need to follow the steps below:
  *
  *
  *	    Start -(A)->  Init CFGMGR -(B)-> Register Entries ---> Register OK -(C)-> (check integrity, factory default ....)  --
  *	                                ^                             |                                |                             ^                                           |
  *	                                 |                            |                                |                              |                                           |
  *	                                 |                            |                                |                              --(non Init/Reinit/Register)-- |
  *	                                 --- Reinit ------------------------------------------------------------------------
  *
  *	Therefore, state transitions need being handled in CFGMGR system,
  *
  *			(A)	: CFGMGR_STATE_PREINIT
  *			(B)	: CFGMGR_STATE_INITOK
  *			(C)	: CFGMGR_STATE_REGISTEROK
  *
  */
enum _cfgmgr_configurationStage_e {
	CFGMGR_STATE_PREINIT,					/* before init system */
	CFGMGR_STATE_INITOK,					/* init ok, can do register */
	CFGMGR_STATE_REGISTEROK				/* register ok, can do normal process */
};

/* <---- return value ----> */

/* 0 : Success */
#ifdef SUCCESS

#if SUCCESS != 0
#error "SUCCESS in not 0"
#endif	/* #if SUCCESS != 0 */

#else	/* #ifdef SUCCESS */
#define SUCCESS 0
#endif	/* #ifdef SUCCESS */

/* -101 ~ -1000 : error message */
#define CFGMGR_ERR_INVALIDPARA			-101		/* invalid parameter */
#define CFGMGR_ERR_MALLOCFAIL				-102		/* memory allocate fail */
#define CFGMGR_ERR_CFGFLOWFAIL			-103		/* configuration flow fail */

/* -1001 ~ -2000 : internal control message */
#define CFGMGR_INFO_INTEGRITYOK			-1001		/* integrity OK */
#define CFGMGR_INFO_INTEGRITYFAIL			-1002		/* integrity fail */


/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/

/**********************************************************************************
	Exported structure used by External APIs
  **********************************************************************************/
/* for Initialization */
typedef struct cfgmgr_initParam_s {
	uint32 maxEntryCount;				/* max cfgmgr entry count in configuration control system */
	uint32 maxCfgSize;					/* max configuration size */
} cfgmgr_initParam_t;


/* call back function for factory default */
typedef struct cfgmgr_callBackFunction_s {
	int32 (*pCallBackFunction)(uint8 flag, uint8 argc, uint32 *argv);
} cfgmgr_callBackFunction_t;

/* flags which can be sent to callBack function to indicate the function we want it to do */
enum _cfgmgr_callBackFunction_flags_e {
	CFGMGR_CALLBACK_FACTORYDEFAULT,	/* do factory default */
	CFGMGR_CALLBACK_CHECKINTEGRITY		/* check the integrity of configuration */
};


/**********************************************************************************
	Internal Control structure
  **********************************************************************************/

/* table control structure */
typedef struct _cfgmgr_entryCtrl_s {
	uint16 tableId;
	cfgmgr_callBackFunction_t callBackFunction;

	/* <-- Internal usage --> */
	uint8 integrity;
	void *ccfgPtr;
} _cfgmgr_entryCtrl_t;
/* for `integirty' in _cfgmgr_entryCtrl_t */
#define CFGMGR_ENTRY_CHECKED		(1<<0)
#define CFGMGR_ENTRY_INTEGRITY	(1<<1)


/**********************************************************************************

	Data Structure of CCFG configuration in Flash or SDRAM:

		1. Use the TLV based arrangement.
		2. One (cfgmgr control segment) and (0 or more cfgmgr entries).

			[_cfgmgr_ctrl_t] [_cfgmgr_entry_t][_cfgmgr_entry_t] .....[_cfgmgr_entry_t]

		3. The `firstTableId' of _cfgmgr_ctrl_t indicates the entry's ID which immediately
		    follows _cfgmgr_ctrl_t.
		4. The `nextTableId' of each _cfgmgr_entry_t indicates the next entry's ID of current entry.
		5. If `firstTableId' in (3) or `nextTableId' (4) is CFGMGR_TABID_NULL, it means there is no
		    more entry behind _cfgmgr_ctrl_t or _cfgmgr_entry_t.

  **********************************************************************************/
/* per-entry */
typedef struct _cfgmgr_entry_s {
	uint16 nextTableId;
	uint32 length;								/* total length of entry's data (not include header) */
	uint8 data;
} _cfgmgr_entry_t;

/*
	we need to ignore the size of 'data' of cfgmgr_entry_t because it is just a pointer to indicate the start position of entry data.
*/
#define CFGENTRY_TOTAL_SIZE(entry)		(uint32)((uint32)(sizeof(_cfgmgr_entry_t)-sizeof(uint8)+(uint32)((entry)->length)))
#define CFGENTRY_HEADER_SIZE			(uint32)(sizeof(_cfgmgr_entry_t) - sizeof(uint8))

/* for alignment issue, we suggest user to use this */
#define CFGENTRY_GET_TOTAL_SIZE(length, entry)	\
	do { \
		_cfgmgr_entry_t __dummy; \
		_cfgmgr_memcpy(&__dummy, entry, sizeof(_cfgmgr_entry_t)); \
		length = CFGENTRY_TOTAL_SIZE(&__dummy); \
	} while (0);
/* whole ccfg control */
typedef struct _cfgmgr_ctrl_s {
	char signature[CFGMGR_SIGNATURE_LENGTH];	/* signature of configuration */
	uint8 version;								/* configuration version */
	uint32 length;								/* total length of configurations (not include cfgmgr's control segment) */
	uint16 firstTableId;							/* first entry ID of configuration */
} _cfgmgr_ctrl_t;



/**********************************************************************************

	External APIs declaration

  **********************************************************************************/


/* Init function of configuration management system */
int32 cfgmgr_init(cfgmgr_initParam_t *);

/* Renit function of configuration management system */
void cfgmgr_reinit(uint8);

/* registration functions */
int32 cfgmgr_registerEntry(uint16, cfgmgr_callBackFunction_t);
int32 cfgmgr_registerOk(void);

/* Read data from configuration management system */
int32 cfgmgr_read(uint16, void *, uint32);

/* Write data to configuration management system, but data may not be written to Flash immediately */
int32 cfgmgr_write(uint16, void *, uint32);

/* sync data to Flash */
void cfgmgr_task(void);

/* do factory default */
int32 cfgmgr_factoryDefault(uint32);

/* sync all configurations */
int32 cfgmgr_syncAll(void);

#endif /* _rtl_cfgmgr_h_ */
