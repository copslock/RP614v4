/*
 * Copyright c                Realtek Semiconductor Corporation, 2003
 * All rights reserved. 
 * 
 * $Header: /home/cvsroot/uClinux-dist/user/boa/src/rtl865x/cfgmgr.c,v 1.8 2005/10/21 10:20:27 chenyl Exp $
 *
 * $Author: chenyl $
 *
 * Abstract: cfgmgr.c -- configuration manager main source file
 * Module assumption:
 *   1. Fixed size for each module configuration table
 *   2. nv-ram area should match exactly 1 flash memory block
 *   3. array index in this module is from 1 to max. this means
 *      any array size has to be declared to be real size plus 1.
 *      and array[0] is always not used.
 * $Log: cfgmgr.c,v $
 * Revision 1.8  2005/10/21 10:20:27  chenyl
 * *: disable cache in CFGMGR
 *
 * Revision 1.7  2005/06/30 07:28:53  chenyl
 * *: commit some unnacessary code
 *
 * Revision 1.6  2005/06/30 03:40:03  chenyl
 * *: reduce unnecessary FLASH write.
 *
 * Revision 1.5  2005/06/30 02:56:39  chenyl
 * *: bug fix: check total length first in integrity-Verification.
 *
 * Revision 1.4  2005/06/29 12:13:46  chenyl
 * *: modify CFGMGR version.
 * *: still check entry if version is different (because version difference means that new configuration is added)
 *
 * Revision 1.3  2005/06/29 05:22:19  chenyl
 * +: TLV based configuration setting.
 *
 * Revision 1.2  2005/05/04 02:32:38  shliu
 * *: add modeCfgFactoryDefaultFunction
 *
 * Revision 1.1  2005/04/19 04:58:15  tony
 * +: BOA web server initial version.
 *
 * Revision 1.63  2005/02/23 14:36:22  yjlou
 * +: add flashdrv_isLoaderOverwritten() to avoid loader crash.
 *
 * Revision 1.62  2004/12/28 09:55:21  rupert
 * *: Add CONFIG_KLIPS flag
 *
 * Revision 1.61  2004/12/28 09:50:48  rupert
 * +: Add IPSEC Support
 *
 * Revision 1.60  2004/11/16 02:30:30  shliu
 * *** empty log message ***
 *
 * Revision 1.59  2004/11/10 12:53:25  yjlou
 * *: CFGMGR_SIZE can be selected by menuconfig.
 *
 * Revision 1.58  2004/10/05 09:20:42  chenyl
 * +: web page to turn ON/OFF ip-multicast system
 *
 * Revision 1.57  2004/10/01 07:52:55  yjlou
 * +: add enable/disable PPPoE Passthru and IPv6 Passthru
 *
 * Revision 1.56  2004/09/03 03:00:09  chhuang
 * +: add new feature: pseudo VLAN
 *
 * Revision 1.55  2004/08/18 05:39:59  chenyl
 * +: napt special option web-based setting
 *
 * Revision 1.54  2004/08/13 06:02:02  cfliu
 * -: Remove WLAN card 2 factory default function
 *
 * Revision 1.53  2004/08/11 04:00:17  yjlou
 * *: _flash_init() is renamed to flashdrv_init()
 *
 * Revision 1.52  2004/08/04 14:51:18  yjlou
 * +: support booting from single 8MB/16MB flash (_SUPPORT_LARGE_FLASH_)
 *
 * Revision 1.51  2004/07/14 13:55:59  chenyl
 * +: web page for MN queue
 *
 * Revision 1.50  2004/07/13 07:13:01  cfliu
 * no message
 *
 * Revision 1.49  2004/07/06 06:19:39  chhuang
 * +: add rate limit
 *
 * Revision 1.48  2004/07/01 09:38:02  yjlou
 * *: fixed the bug taht MMU user-mode program CANNOT soft-reboot.
 *
 * Revision 1.47  2004/06/14 13:48:17  rupert
 * +: Add work properly with MMU kernel
 *
 * Revision 1.46  2004/06/11 09:20:18  tony
 * +: using share memory instead of direct access for pRomeCfgParam.
 *
 * Revision 1.45  2004/06/08 10:54:42  cfliu
 * +: Add WLAN dual mode webpages. Not yet completed...
 *
 * Revision 1.44  2004/05/28 09:49:16  yjlou
 * +: support Protocol-Based NAT
 *
 *
 * Revision 1.42  2004/05/20 08:43:55  chhuang
 * add Web Page for QoS
 *
 * Revision 1.41  2004/05/19 08:40:14  orlando
 * checkin init button,diag led,bicolor led related code
 *
 * Revision 1.40  2004/05/13 13:27:01  yjlou
 * +: loader version is migrated to "00.00.07".
 * +: new architecture for INTEL flash (code is NOT verified).
 * *: FLASH_BASE is decided by IS_REV_A()
 * -: remove flash_map.h (content moved to flashdrv.h)
 * -: remove un-necessary calling setIlev()
 *
 * Revision 1.39  2004/05/12 05:15:05  tony
 * support PPTP/L2TP in RTL865XB.
 *
 * Revision 1.38  2004/05/11 10:40:34  yjlou
 * +: runtime code supports auto-detect BDINFO and CCFG address.
 *
 * Revision 1.37  2004/04/08 13:18:12  tony
 * add PPTP/L2TP routine for MII lookback port.
 *
 * Revision 1.36  2004/03/31 01:59:36  tony
 * add L2TP wan type UI pages.
 *
 * Revision 1.35  2004/03/03 03:43:31  tony
 * add static routing table in turnkey.
 *
 * Revision 1.34  2004/02/03 08:14:34  tony
 * add UDP Blocking web UI configuration.
 *
 * Revision 1.33  2004/01/07 09:10:04  tony
 * add PPTP Client UI in Config Wizard.
 *
 * Revision 1.32  2003/12/19 04:33:01  tony
 * add Wireless Lan config pages: Basic Setting, Advance Setting, Security, Access Control, WDS
 *
 * Revision 1.30  2003/12/01 12:35:52  tony
 * make ALG is able to be configured by users(Web GUI).
 *
 * Revision 1.29  2003/10/24 10:25:58  tony
 * add DoS attack interactive webpage,
 * FwdEngine is able to get WAN status by rtl8651_wanStatus(0:disconnect,1:connect)
 *
 * Revision 1.28  2003/10/14 08:38:14  tony
 * add RomeDriver version information
 *
 * Revision 1.27  2003/10/08 10:41:43  tony
 * update Board_info address
 *
 * Revision 1.26  2003/10/03 12:27:35  tony
 * add NTP time sync routine in management web page.
 *
 * Revision 1.25  2003/10/01 13:33:10  tony
 * solve all the compiler warning message in cfgmgr.c
 *
 * Revision 1.24  2003/10/01 09:12:03  tony
 * move all the extern declare of factory deafult function to rtl_board.h
 *
 * Revision 1.23  2003/10/01 05:57:31  tony
 * add URL Filter routine
 *
 * Revision 1.22  2003/09/30 08:56:29  tony
 * remove newServerpCfgParam[] from flash, rename ram PPPoeCfg to ramPppoeCfgParam
 *
 * Revision 1.21  2003/09/25 05:54:01  tony
 * support from loader 0.0.3
 *
 * Revision 1.20  2003/09/25 03:48:35  orlando
 * add romecfg.txt file to pass romeCfgParam structure pointer for other user space application
 *
 * Revision 1.19  2003/09/25 02:15:32  orlando
 * Big Change
 *
 * Revision 1.18  2003/09/24 07:10:30  rupert
 * rearrange init sequence
 *
 * Revision 1.16  2003/09/24 05:24:34  rupert
 * remove cfgmgr_main
 *
 * Revision 1.15  2003/09/23 11:44:33  tony
 * add UPNP daemon start/stop routine.
 *
 * Revision 1.14  2003/09/23 03:47:29  tony
 * add ddnsCfgParam,ddnsDefaultFactory,ddns_init
 *
 * Revision 1.13  2003/09/22 08:01:45  tony
 * add UPnP Web Configuration Function Routine
 *
 * Revision 1.12  2003/09/22 06:33:37  tony
 * add syslogd process start/stop by CGI.
 * add eventlog download/clear routine.
 *
 * Revision 1.11  2003/09/19 06:06:51  tony
 * *** empty log message ***
 *
 * Revision 1.10  2003/09/19 01:43:50  tony
 * add dmz routine
 *
 * Revision 1.9  2003/09/18 05:12:00  hiwu
 * vfork()'s child should use _exit()
 *
 * Revision 1.8  2003/09/18 02:27:10  rupert
 * add ip-up-down.c for ppp
 *
 * Revision 1.7  2003/09/18 02:05:45  tony
 * modify pppoeCfgParam to array
 *
 * Revision 1.6  2003/09/17 12:28:04  rupert
 * Add PPPoE Advance Page and redefinition some function
 *
 * Revision 1.5  2003/09/12 02:25:58  rupert
 * pppd for auto reconnection
 *
 * Revision 1.4  2003/09/04 09:33:40  rupert
 * Move Versoin To Top Makefile
 *
 * Revision 1.3  2003/09/04 07:38:46  rupert
 * Add PPPoE Initialization
 *
 * Revision 1.2  2003/08/29 06:32:54  rupert
 *
 *
 * 		remove unecesarry file
 *
 * Revision 1.1.1.1  2003/08/27 06:20:15  rupert
 * uclinux initial
 *
 * Revision 1.1.1.1  2003/08/27 03:08:53  rupert
 *  initial version 
 *
 * Revision 1.24  2003/07/21 05:06:51  orlando
 * check-in for v0.3.1.
 *
 * Revision 1.23  2003/07/09 05:22:13  orlando
 * reset to factory default if new firmware's table size is
 * different from existing size. this occurs when new module
 * or new table structure is being designed.
 * after a factory default during read, system restart is done
 * automatically. these will make new firmware boot smoothly over
 * old firmare on the flashmemory.
 *
 * Revision 1.22  2003/07/08 12:41:51  orlando
 * previous (1.21) version cvs log error.
 * 1.21 log: change cfgmgr task priority from 200 to 50, which
 * is equal to netTask priority.
 *
 * Revision 1.21  2003/07/08 12:38:49  orlando
 * tune "if_init"'s static wan and dhcp client wan init code.
 *
 * Revision 1.20  2003/07/01 10:26:55  orlando
 * remove #pragma pack(1) and #pragma pack(), which might
 * cause problem in vxwork gnu compiler.
 *
 * Revision 1.19  2003/07/01 03:08:18  tony
 * add aclGlobalCfgParam factory default.
 *
 * Revision 1.18  2003/06/30 07:46:27  tony
 * add ACL and Server_Port structure
 *
 * Revision 1.17  2003/06/24 13:59:15  orlando
 * modify CFGMGR_BASE_ADDR definition from hard-coded
 * to FLASH_MAP_CCFG_IMAGE_ADDR.
 *
 * Revision 1.16  2003/06/23 11:11:48  elvis
 * change include path of  rtl_types.h
 *
 * Revision 1.15  2003/06/20 13:02:49  tony
 * add dhcp client
 *
 * Revision 1.14  2003/06/17 07:00:01  orlando
 * trying to avoid word aligned load/store.
 *
 * Revision 1.13  2003/06/16 08:09:19  tony
 * add dhcps & dns function
 *
 * Revision 1.12  2003/06/06 11:58:04  orlando
 * add pppoe cfg.
 *
 * Revision 1.11  2003/06/06 06:16:43  idayang
 * add mgmt table in cfgmgr.
 *
 * Revision 1.10  2003/06/03 10:58:14  orlando
 * add nat table in cfgmgr.
 *
 * Revision 1.9  2003/05/23 06:10:27  elvis
 * avoid multiple definition for macros max() and min()
 *
 * Revision 1.8  2003/05/20 08:52:03  elvis
 * change the include path of "rtl_types.h"
 *
 * Revision 1.7  2003/05/19 07:34:45  orlando
 * remove cfgmgr_factoryDefault()'s message.
 *
 * Revision 1.6  2003/05/09 15:34:37  orlando
 * patch due to sysHwInit() cannot start the cfgmgr maintenance task.
 *
 * Revision 1.5  2003/05/06 12:30:44  orlando
 * modify to work with new boot/loader.
 *
 * Revision 1.4  2003/05/06 07:32:08  orlando
 * remove cfgmgr_integrityCheck() message during
 * normal case.
 *
 * Revision 1.3  2003/05/02 09:20:48  orlando
 * make cfgmgr_init() called implicitly by 1st cfgmgr_read()
 * or cfgmgr_write() access.
 *
 * Revision 1.2  2003/04/30 01:44:24  orlando
 * adjust helpful message.
 *
 * Revision 1.1  2003/04/29 14:15:30  orlando
 * cfgmgr module initial check-in.
 *
 */

#include "rtl_types.h"
#include "rtl_flashdrv.h"
#include "flashdrv.h"
#include "rtl_cfgmgr.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <re865x.h>

/* For IOCTL usage */
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>



/* global control variables */
static uint8 cfgmgr_state = CFGMGR_STATE_PREINIT;				/* store the state of CFGMGR */
#define SET_STATE(state)		do {cfgmgr_state = state;} while (0);
#define IS_STATE(state)		(cfgmgr_state == state)
#define LEAST_STATE(state)	(cfgmgr_state >= state)

static cfgmgr_initParam_t cfgmgrParam;				/* store the initial parameters of ccfg */

/* store all entry's related information here */
static _cfgmgr_entryCtrl_t *cfgmgr_entryTbl = NULL;	/* container to store all entry's related information */

/* buffer */
static uint8 *CCFG_sdram	= NULL;
static uint8 *shadow 		= NULL;
static uint8 *Flash_buff	= NULL;	/* used by flash control interface */
#define CCFG_PTR 	((_cfgmgr_ctrl_t *)(CCFG_sdram))	/* store the pointer of Configurations mapped in SDRAM */
#define ENTRY_PTR	(_cfgmgr_entry_t*)(((uint32)CCFG_PTR) + sizeof(_cfgmgr_ctrl_t))

#define CFGMGR_DECLARATIONs
static int32 _cfgmgr_integrityCheck(void);
static int32 _cfgmgr_updateCCFG(uint8 factoryDefault);
static int32 _cfgmgr_readCcfgFlash(void *sdramCfg, uint32 size);
static int32 _cfgmgr_writeCcfgFlash(void *sdramCfg, uint32 size);
static int32 _cfgmgr_865xIoctl(char *name, uint32 arg0, uint32 arg1, uint32 arg2, uint32 arg3);
static void *_cfgmgr_memcpy(void *out, const void *in, const uint32 n);

#define CFGMGR_EXTERNAL_APIs

/*
@func	int32				| cfgmgr_init	|	API to process CFGMGR system initiation.
@parm	cfgmgr_initParam_t*	| param		|	Information to init system.
@comm
Init function to allocate memory space and set variables to default value,
we MUST call this API before all of CFGMGR process.
Note that this API must be called least once and only once.
@xref  <p cfgmgr_reinit>
*/

int32 cfgmgr_init(cfgmgr_initParam_t *param)
{
	int32 retval = FAILED;

	/* We always reset cfgmgr state before config it */
	SET_STATE(CFGMGR_STATE_PREINIT);


	/* <---------- Parameter check ----------> */

	if (param == NULL)
	{
		CFGMGR_ERR("parameter is NULL.");
		retval = CFGMGR_ERR_INVALIDPARA;
		goto err;
	}

	CFGMGR_INFO("CFGMGR init (%d) (%d).", param->maxCfgSize, param->maxEntryCount);

	_cfgmgr_memcpy(&cfgmgrParam, param, sizeof(cfgmgr_initParam_t));

	if (cfgmgrParam.maxEntryCount == 0)
	{
		CFGMGR_ERR("Max allow entry count of cfgmgr is set to 0.");
		retval = CFGMGR_ERR_INVALIDPARA;
		goto err;
		
	}

	if (cfgmgrParam.maxCfgSize == 0)
	{
		CFGMGR_ERR("configuration size of CCFG is set to 0.");
		retval = CFGMGR_ERR_INVALIDPARA;
		goto err;
	}

	/* <---------- Set environment according to configuration parameter ----------> */
	cfgmgr_entryTbl = malloc(sizeof(_cfgmgr_entryCtrl_t) * cfgmgrParam.maxEntryCount);
	if (cfgmgr_entryTbl == NULL)
	{
		CFGMGR_ERR("memory allocation fail.");
		retval = CFGMGR_ERR_MALLOCFAIL;
		goto err;
	}

	CCFG_sdram = malloc(cfgmgrParam.maxCfgSize);
	if (CCFG_sdram == NULL)
	{
		CFGMGR_ERR("memory allocation fail.");
		retval = CFGMGR_ERR_MALLOCFAIL;
		goto err;
	}

	shadow = malloc(cfgmgrParam.maxCfgSize);
	if (shadow == NULL)
	{
		CFGMGR_ERR("memory allocation fail.");
		retval = CFGMGR_ERR_MALLOCFAIL;
		goto err;
	}

	Flash_buff = malloc(cfgmgrParam.maxCfgSize);
	if (Flash_buff == NULL)
	{
		CFGMGR_ERR("memory allocation fail.");
		retval = CFGMGR_ERR_MALLOCFAIL;
		goto err;
	}

	SET_STATE(CFGMGR_STATE_INITOK);

	/* init flashdrv */
	flashdrv_init();

	/* call reinit function to reset structure */
	cfgmgr_reinit(TRUE /* system would reset entry Control table */);
	return SUCCESS;

err:

	/* when error occurs in cfgmgr initial phase, it is really FATAL and need to stop all processes. */
	CFGMGR_HALT();
	return retval;
}


/*
@func	int32		| cfgmgr_reinit	|	API to process CFGMGR system reset.
@parm	uint8		| resetRegistry	|	Indicate system would reset Registry or not.
@comm
ReInit function to reset all variables and database to default value.
If <p resetRegistry> is set to TRUE: system would NOT reset Registration informations.
@xref  <p cfgmgr_init>
*/
void cfgmgr_reinit(uint8 resetRegistry)
{

	/* ===============================================================
		If user call reinit function, this system MUST be initiated before (for memory allocations)
		and the state MUST > CFGMGR_STATE_INITOK
	    =============================================================== */
	if (!LEAST_STATE(CFGMGR_STATE_INITOK))
	{
		CFGMGR_ERR("configuration flow fail: %d\n", cfgmgr_state);
		goto err;
	}
	if (cfgmgr_entryTbl == NULL || shadow == NULL || Flash_buff == NULL)
	{
		CFGMGR_ERR("Data Structure failed");
		goto err;
	}

	/* ===============================================================
		Reset variables
	    =============================================================== */

	/* <--- other variables ---> */
	memset(shadow, 0, cfgmgrParam.maxCfgSize);
	memset(Flash_buff, 0, cfgmgrParam.maxCfgSize);

	if (resetRegistry == FALSE)
	{
		/* registration procedure is completed */
		if (LEAST_STATE(CFGMGR_STATE_REGISTEROK))
		{
			/* reset state back to REGISTEROK and system don't reset Registry */
			SET_STATE(CFGMGR_STATE_REGISTEROK);
		} else
		{
			CFGMGR_WARN("Indicate DontResetRegistry but registration is not completed yet.");
			/* Its state must be CFGMGR_STATE_INITOK, keep it. */
			if (!IS_STATE(CFGMGR_STATE_INITOK))
			{
				CFGMGR_ERR("CFGMGR State (%d) is confused.", cfgmgr_state);
				goto err;
			}
		}

		/* ===============================================================
			Read Flash to set CCFG_sdram

			==> Data in Flash and SDRAM would be synchronized
		    =============================================================== */
		if (_cfgmgr_readCcfgFlash(CCFG_sdram, cfgmgrParam.maxCfgSize) != SUCCESS)
		{
			CFGMGR_ERR("Flash read fail.");
			goto err;
		}

		/* ===============================================================
			Check and sync CCFG

			==> Data in Flash and SDRAM's integrity would be checked.
		    =============================================================== */
		if (_cfgmgr_updateCCFG(FALSE) != SUCCESS)
		{
			CFGMGR_ERR("CCFG integrity sync fail");
			goto err;
		}

		/* ===============================================================
			Call integrity Check to save SDRAM configuration's information into CFGMGR control block
		    =============================================================== */
		if (_cfgmgr_integrityCheck() != CFGMGR_INFO_INTEGRITYOK)
		{
			CFGMGR_ERR("CCFG integrity is still fail after sync.");
			goto err;
		}

	} else
	{
		memset(cfgmgr_entryTbl, 0, sizeof(_cfgmgr_entryCtrl_t) * cfgmgrParam.maxEntryCount);
		/* reset state back to INITOK */
		SET_STATE(CFGMGR_STATE_INITOK);
	}

	/* successfully return */
	return;

err:
	/* when error occurs in cfgmgr re-initial phase, it is really FATAL and need to stop all processes. */
	CFGMGR_HALT();
	return;
}

/*
@func	int32					| cfgmgr_registerEntry	|	API to register configuration entries into CFGMGR system.
@parm	uint16					| tableId				|	Table ID for registration.
@parm	cfgmgr_callBackFunction_t	| callBackFunction		|	Callback function for registered configuration entry.
@comm
Function to register configuration entry.
In the function, 2 parameters are needed:
	<p tableId>:
			This ID must be UNIQUE in CFGMGR system, we allow user to set this because
			we assume there is only one user would use CFGMGR in whole system.
	<p callBackFunction>:
			This callBackFunction MUST provide some functions for CFGMGR system:
				1. Integrity Check:
					INPUT:
						flag				:	CFGMGR_CALLBACK_CHECKINTEGRITY
						argument count	:	3
						argument array[0]	:	TableID
						argument array[1]	:	input data length
						argument array[2]	:	input data pointer
					OUTPUT:
						return value		:	SUCCESS		:	Integrity check ok
											non-SUCCESS	:	Integirty check failed
				2. Factory Default:
					INPUT:
						flag				:	CFGMGR_CALLBACK_FACTORYDEFAULT
						argument count	:	5
						argument array[0]	:	TableID
						argument array[1]	:	original data pointer, NULL to indicate there is no any default data.
						argument array[2]	:	original data size.
						argument array[3]	:	pointer to new buffer.
						argument array[4]	:	pointer to unsigned int32 to indicate the max length of new buffer
											pointed by array[1].
					OUTPUT:
						return value		:	SUCCESS		: Factory default ok
											non-SUCCESS	: Factory default failed

						* If factory default is successful, new data would be written in buffer pointed by array[1] and
						  real length of data is stored in memory pointed by array[2].

After register configuration entries, the API <p cfgmgr_registerOk> must be called to indicate registration state is OK.
After registration OK, all other functions can be called by user.

@xref  <p cfgmgr_registerOk>
*/
int32 cfgmgr_registerEntry(uint16 tableId, cfgmgr_callBackFunction_t callBackFunction)
{
	int32 retval = FAILED;
	int32 idx, empty = -1;

	if (!IS_STATE(CFGMGR_STATE_INITOK))
	{
		CFGMGR_ERR("register cfgmgr entry in wrong state.");
		retval = CFGMGR_ERR_CFGFLOWFAIL;
		goto err;
	}

	/* check input */
	if (tableId == 0 || callBackFunction.pCallBackFunction == NULL)
	{
		CFGMGR_ERR("invalid parameter when register cfgmgr entry: (%d):(%p)", tableId, callBackFunction);
		retval = CFGMGR_ERR_INVALIDPARA;
		goto err;
	}

	/* check the redundancy of entryId */
	for (idx = 0 ; idx < cfgmgrParam.maxEntryCount ; idx ++)
	{
		/* we get the empty entry when trace data structure for entry Add */
		if ((empty < 0) && (cfgmgr_entryTbl[idx].tableId == CFGMGR_TABLEID_NULL))
		{
			empty = idx;
		}
		if (cfgmgr_entryTbl[idx].tableId == tableId)
		{
			CFGMGR_ERR("redundant entryId found: %d", tableId);
			retval = CFGMGR_ERR_INVALIDPARA;
			goto err;
		}
	}

	/* start to add this entry */
	if (empty < 0)
	{	/* no any empty entry found when trace data structure above: Table FULL */
		CFGMGR_ERR("data structure full.");
		retval = CFGMGR_ERR_MALLOCFAIL;
		goto err;
	}
	/* fill data structure */
	memset(&(cfgmgr_entryTbl[empty]), 0, sizeof(_cfgmgr_entryCtrl_t));
	cfgmgr_entryTbl[empty].tableId = tableId;
	cfgmgr_entryTbl[empty].callBackFunction = callBackFunction;

	/* registration OK */
	return SUCCESS;

err:
	/* when error occurs in cfgmgr registeration phase, it is really FATAL and need to stop all processes. */
	CFGMGR_HALT();
	return retval;
}

/*
@func	int32		| cfgmgr_registerOk	|	API to indicate the registration phase done.
@comm
Call by user to tell CFGMGR system there the registration phase is done and
CFGMGR system would allow user to call further APIs to access entries.
@xref  <p cfgmgr_registerEntry>
*/
int32 cfgmgr_registerOk(void)
{
	int32 retval = FAILED;

	if (LEAST_STATE(CFGMGR_STATE_REGISTEROK))
	{	/* after RegistrationOK state, nothing need to be done */
		return SUCCESS;
	}

	if (!IS_STATE(CFGMGR_STATE_INITOK))
	{
		CFGMGR_ERR("set cfgmgr state to OK before enable system.");
		retval = CFGMGR_ERR_CFGFLOWFAIL;
		goto err;
	}

	SET_STATE(CFGMGR_STATE_REGISTEROK);

	/* state transition OK */
	return SUCCESS;
err:
	/* when error occurs in cfgmgr registeration phase, it is really FATAL and need to stop all processes. */
	CFGMGR_HALT();
	return retval;
}

/*
@func	int32		| cfgmgr_read	|	Read configuration from CFGMGR system
@parm	uint16		| tableId			|	Indicate the Table ID which user want to get its configuration.
@parm	void*		| pBuff			|	Buffer to store configuration.
@parm	uint32		| BuffSize		|	Max buffer size
@comm
Read entry 'tableId' 's configuration from CCFG system,
and CCFG system would set the configuration to <pBuff> with the size being <p buffSize>.
@xref  <p cfgmgr_write>
*/
int32 cfgmgr_read(uint16 tableId, void *pBuff, uint32  BuffSize)
{
	int32 retval, idx;

	/* check CFGMGR state */
	if (!LEAST_STATE(CFGMGR_STATE_REGISTEROK))
	{
		CFGMGR_ERR("configuration flow fail: %d\n", cfgmgr_state);
		retval = CFGMGR_ERR_CFGFLOWFAIL;
		goto fatal;
	}

	if (	(pBuff == NULL) || (BuffSize == 0))
	{
		CFGMGR_ERR("Invalid parameter: pBuff (%p) BuffSize (%d)", pBuff, BuffSize);
		retval = CFGMGR_ERR_INVALIDPARA;
		goto err;
	}

	/*

		chenyl (2005/10/21):

			In some implementations, user-level BOA server might be forked to several processes.
			If we store a cache in CFGMGR module of each BOA process, it might cause some
			synchronous problems between different BOAs and process might read out-of-date data
			and some errors will occur.
			(ex. Data in flash is modified by process A, but process B still use the original data stored in its cache.)

			Therefore, before reading data, we ALWAYS call reinit function to fetch data from FLASH driver.
			(In other word, we disable the cache mechanism in CFGMGR system.)
			=>	Function would be correct, but flash would be accessed frequently and the memory space of shadow in SDRAM
				would be wasted.

	*/
	cfgmgr_reinit(FALSE);

	for (idx = 0 ; idx < cfgmgrParam.maxEntryCount ; idx ++)
	{
		/* corresponding entry found */
		if (cfgmgr_entryTbl[idx].tableId == tableId)
		{
			_cfgmgr_entry_t *entry_t;
			uint32 length;
			/*
				In all cases, CFGMGR control structure and SDRAM data MUST be sync, so we can get CCFG information from
				CFGMGR control structure.
			*/
			if (	(cfgmgr_entryTbl[idx].integrity != (CFGMGR_ENTRY_CHECKED|CFGMGR_ENTRY_INTEGRITY)) ||
				(cfgmgr_entryTbl[idx].ccfgPtr == NULL))
			{
				CFGMGR_ERR("CCFG SDRAM data and CFGMGR control structure is not sync.");
				retval = CFGMGR_ERR_CFGFLOWFAIL;
				goto fatal;
			}

			entry_t = (_cfgmgr_entry_t*)(cfgmgr_entryTbl[idx].ccfgPtr);

			{	/* for alignment issue */
				_cfgmgr_entry_t dummy;
				_cfgmgr_memcpy(&dummy, entry_t, CFGENTRY_HEADER_SIZE);
				length = (uint32)(dummy.length);
			}

			if (length != BuffSize)
			{
				CFGMGR_WARN("TableID [%d]: Size of buff (%d) is not equal to the size of config (%d).", tableId, BuffSize, length);
			}

			if (length > BuffSize)
			{
				CFGMGR_ERR("Entry (%d) size (%d) is larger then max write buffer size (%d) given by user.",
								tableId,
								length,
								BuffSize);
				retval = CFGMGR_ERR_INVALIDPARA;
				goto err;
			}

			/* Copy configuration to buffer */
			memcpy(pBuff, (void*)(&(entry_t->data)), length);

			return SUCCESS;

		}
	}
	/* entry not found */

	CFGMGR_ERR("Unknown tableID (%d).", tableId);
	retval = CFGMGR_ERR_INVALIDPARA;
	goto err;


fatal:
	CFGMGR_HALT();
err:
	return retval;

}


/*
@func	int32		| cfgmgr_write	|	Write configuration from CFGMGR system
@parm	uint16		| tableId			|	Indicate the Table ID which user want to write its configuration.
@parm	void*		| pBuff			|	Buffer of data to write.
@parm	uint32		| buffSize		|	Total size of pBuff to write.
@comm
Write entry 'tableId' 's configuration to CCFG system.
@xref  <p cfgmgr_read>
*/
int32 cfgmgr_write(uint16 tableId, void *pBuff, uint32 buffSize)
{
	int32 retval, idx;

	/* check CFGMGR state */
	if (!LEAST_STATE(CFGMGR_STATE_REGISTEROK))
	{
		CFGMGR_ERR("configuration flow fail: %d\n", cfgmgr_state);
		retval = CFGMGR_ERR_CFGFLOWFAIL;
		goto fatal;
	}

	if (	(pBuff == NULL) || (buffSize == 0))
	{
		CFGMGR_ERR("Invalid parameter: pBuff (%p) buffSize (%p)", pBuff, buffSize);
		retval = CFGMGR_ERR_INVALIDPARA;
		goto err;
	}

	for (idx = 0 ; idx < cfgmgrParam.maxEntryCount ; idx ++)
	{
		/* corresponding entry found */
		if (cfgmgr_entryTbl[idx].tableId == tableId)
		{
			_cfgmgr_entry_t *entry_t;
			uint32 callBackArray[3];
			uint32 length;

			/*
				In all cases, CFGMGR control structure and SDRAM data MUST be sync, so we can get CCFG information from
				CFGMGR control structure.
			*/
			if (	(cfgmgr_entryTbl[idx].integrity != (CFGMGR_ENTRY_CHECKED|CFGMGR_ENTRY_INTEGRITY)) ||
				(cfgmgr_entryTbl[idx].ccfgPtr == NULL))
			{
				CFGMGR_ERR("CCFG SDRAM data and CFGMGR control structure is not sync.");
				retval = CFGMGR_ERR_CFGFLOWFAIL;
				goto fatal;
			}

			entry_t = (_cfgmgr_entry_t*)(cfgmgr_entryTbl[idx].ccfgPtr);

			{	/* for alignment issue */
				_cfgmgr_entry_t dummy;
				_cfgmgr_memcpy(&dummy, entry_t, CFGENTRY_HEADER_SIZE);
				length = (uint32)(dummy.length);
			}

			/* check length of data */
			if (length != buffSize)
			{
				CFGMGR_ERR("TableID [%d]'s CCFG SDRAM data length is not equal (%d != %d) !", tableId, length, buffSize);
				retval = CFGMGR_ERR_INVALIDPARA;
				goto err;
			}

			/* check the integrity of input data */
			callBackArray[0] = (uint32)(cfgmgr_entryTbl[idx].tableId);
			callBackArray[1] = (uint32)buffSize;
			callBackArray[2] = (uint32)pBuff;
			if (	(*(cfgmgr_entryTbl[idx].callBackFunction.pCallBackFunction))(	CFGMGR_CALLBACK_CHECKINTEGRITY,
																		sizeof(callBackArray)/sizeof(callBackArray[0]),
																		callBackArray)
				!= SUCCESS )
			{
				CFGMGR_ERR("TableID [%d]'s CCFG data integrity check fail.", tableId);
				retval = CFGMGR_ERR_INVALIDPARA;
				goto err;
			}

			/* write datat to SDRam CCFG */
			_cfgmgr_memcpy((void *)(&(entry_t->data)), pBuff, buffSize);

			/* sync to CCFG Flash */
			if (	(retval = _cfgmgr_writeCcfgFlash(	CCFG_PTR,
												(CCFG_PTR->length + sizeof(_cfgmgr_ctrl_t))))
					!= SUCCESS )
			{
				CFGMGR_ERR("Flash access fail");
				goto err;
			}

			return SUCCESS;

		}
	}

	/* entry not found */

	CFGMGR_ERR("Unknown tableID (%d).", tableId);
	retval = CFGMGR_ERR_INVALIDPARA;
	goto err;


fatal:
	CFGMGR_HALT();
err:
	return retval;

}

/*
	Dummy function now.
*/
void cfgmgr_task(void)
{
	/* check CFGMGR state */
	if (!LEAST_STATE(CFGMGR_STATE_REGISTEROK))
	{
		CFGMGR_ERR("configuration flow fail: %d\n", cfgmgr_state);
		CFGMGR_HALT();
	}
}

/*
@func	int32		| cfgmgr_factoryDefault		|	Factory-Default function of CFGMGR stored configurations
@parm	uint32		| callerId					|	Indicate who call the factory default function: 0: called by Normal function, 1: called by push the Init-button.
@comm
Set all of the configurations back to factory default value. The parameter <p callerId> indicates the caller of this function.
When it is 0, this means this function is called by normal function call in gateway.
When it is 1, this means this function is called by push INIT button.
@xref  <p cfgmgr_read>
@xref  <p cfgmgr_write>
*/
int32 cfgmgr_factoryDefault(uint32 callerId)
{
	int32 retval = FAILED;

	CFGMGR_INFO("Start user-called FACTORY DEFAULT procedure.");

	if ((retval = _cfgmgr_updateCCFG(TRUE)) != SUCCESS)
	{
		CFGMGR_ERR("Do factory default failed: %d.", retval);
	} else
	{
		/* Factory default success */
		#if defined(CONFIG_RTL865X_INIT_BUTTON)
		/*
			Whe this API is called by push INIT-Button,
			we would use GPIO to touch DIAG LED to indicate this.
		*/
		if (callerId == 1)
		{
			sys_reboot();	
			//_cfgmgr_865xIoctl("eth0", RTL8651_IOCTL_DIAG_LED, 100, 0, 0);
		}
		#endif /* CONFIG_RTL865X_INIT_BUTTON */
	}
	
	sys_restart();

	return retval;
}

/*
@func	int32		| cfgmgr_syncAll	|	Sync FLASH's configurations and current run-time image.
@comm
Try to synchronize CFGMGR's configurations in FLASH. We check their integirty and set factory default if some of their integrity
check are not pass.
*/
int32 cfgmgr_syncAll(void)
{
	int32 retval = FAILED;

	CFGMGR_INFO("Start user-called CFGMGR SYNC procedure.");

	/* ===============================================================
		Read Flash to set CCFG_sdram

		==> Data in Flash and SDRAM would be synchronized
	    =============================================================== */
	CFGMGR_INFO("==> Sync Flash to SDRAM.");

	if (_cfgmgr_readCcfgFlash(CCFG_sdram, cfgmgrParam.maxCfgSize) != SUCCESS)
	{
		CFGMGR_ERR("Flash read fail.");
		goto err;
	}

	CFGMGR_INFO("==> Sync SDRAM to system.");
	/* ===============================================================
		Sync CCFG_sdram and system's configuration definition,
		if they are different we would sync system's back to SDRAM and Flash.
	    =============================================================== */
	if ((retval = _cfgmgr_updateCCFG(FALSE)) == SUCCESS)
	{
		CFGMGR_INFO("SYN complete.");
		return SUCCESS;
	}

	CFGMGR_INFO("==> return %d\n", retval);

err:	
	CFGMGR_HALT();
	return retval;
}



#define CFGMGR_INTERNAL_APIs



/*
	Try to sync entries in Flash space and User's,
	the tableIDs are based on user given.
*/
static int32 _cfgmgr_integrityCheck(void)
{
	int32 retval = FAILED, idx, integrityOk, resetIntegrity;
	_cfgmgr_entry_t *entry_t, nullEntry;
	uint16 currTableId;
	uint32 entry_len;

	bzero(&nullEntry, sizeof(_cfgmgr_entry_t));

	/* check CFGMGR state */
	if (!LEAST_STATE(CFGMGR_STATE_REGISTEROK))
	{
		CFGMGR_ERR("configuration flow fail: %d\n", cfgmgr_state);
		retval = CFGMGR_ERR_CFGFLOWFAIL;
		goto fatal;
	}

	/* reset integrity struct in data structure */
	for (idx = 0 ; idx < cfgmgrParam.maxEntryCount ; idx ++)
	{
		cfgmgr_entryTbl[idx].integrity = 0;
		cfgmgr_entryTbl[idx].ccfgPtr = NULL;
	}

	integrityOk = TRUE;
	resetIntegrity = FALSE;

	/* -----------------------------------------------------------
		Check Global Control Structure:

			If signature mismatch, it probably means that the
			structure is WRONG. Therefore, we would ignore remaining
			entry check because we can not trust them.
	     ----------------------------------------------------------- */

	/* check signature */
	if (	memcmp(	(void *)(CCFG_PTR->signature),
					(void *)CFGMGR_SIGNATURE,
					strlen(CFGMGR_SIGNATURE)) != 0 )
	{
		char tmp[CFGMGR_SIGNATURE_LENGTH];

		memset(tmp, 0, sizeof(tmp));
		strncpy(tmp, CCFG_PTR->signature, sizeof(tmp));
		CFGMGR_WARN("Signature not match (image: [%s] flash: [%s])", CFGMGR_SIGNATURE, tmp);
		retval = CFGMGR_INFO_INTEGRITYFAIL;
		goto err;
	}

	/* check version */
	if ((uint8)(CCFG_PTR->version) != CFGMGR_VERSION)
	{
		CFGMGR_WARN("Version not match (image: [%d] flash: [%d]).", CFGMGR_VERSION, CCFG_PTR->version);
		integrityOk = FALSE;					/* version is different, integrity check must be false */
	}

	/* check length */
	if ((CCFG_PTR->length + sizeof(_cfgmgr_ctrl_t)) > cfgmgrParam.maxCfgSize)
	{
		CFGMGR_WARN("Invalid CFGMGR length (%lu).", (CCFG_PTR->length));
		retval = CFGMGR_INFO_INTEGRITYFAIL;
		goto err;
	}

	/* -----------------------------------------------------------
		Check Configuration entries:

			We check each configuration entries in CFGMGR system,
			and verity how many entry's integrity is ok.
	     ----------------------------------------------------------- */


	/* check all configuration enties */
	entry_len = CCFG_PTR->length;										/* total entry length to verity the integrity of ccfg config length and real length */
	currTableId = CCFG_PTR->firstTableId;								/* set the table ID to the first entry's ID */
	entry_t = (_cfgmgr_entry_t*)((uint32)CCFG_PTR+sizeof(_cfgmgr_ctrl_t));	/* Pointer move to the address which immediately behind CCFG global control segment (first entry) */

	/* trace all entries in Flash space to check integrity */
	while (currTableId != CFGMGR_TABLEID_NULL)
	{

		/* check global length declaration first */
		uint32 real_len;
		CFGENTRY_GET_TOTAL_SIZE(real_len, entry_t);

		if (entry_len < real_len)
		{
			CFGMGR_WARN("Global length declaration is smaller than real data.");
			integrityOk = FALSE;
			resetIntegrity = TRUE;	/* we CAN NOT trust ALL entries because it probably means structure is broken */
			entry_len = 0;
			goto post_entryCheck;
		}

		entry_len -= real_len;
	
		/* find the corresponding entry in user registered table */
		for (idx = 0 ; idx < cfgmgrParam.maxEntryCount ; idx ++)
		{
			/* entry found ! */
			if (cfgmgr_entryTbl[idx].tableId == currTableId)
			{
				uint32 callBackArray[3];

				/* if this entry was checked before ? */
				if (cfgmgr_entryTbl[idx].integrity & CFGMGR_ENTRY_CHECKED)
				{
					/*
						This entry is referenced by 2 data segments in CCFG space.
						It must be something wrong, so we ALWAYS DONT trust this entry.
					*/

					CFGMGR_WARN("Entry (%d) is redundant in integrity check, ALWASY disabl its Integrity setting.", currTableId);
					cfgmgr_entryTbl[idx].integrity &= ~CFGMGR_ENTRY_INTEGRITY;
					cfgmgr_entryTbl[idx].ccfgPtr = NULL;	/* we don't know which entry is real one */
					integrityOk = FALSE;
				} else
				{
					/*
						Redundancy check pass, check content's integrity.
					*/

					/* set bit to indicate this entry is checked now */
					cfgmgr_entryTbl[idx].integrity |= CFGMGR_ENTRY_CHECKED;
					cfgmgr_entryTbl[idx].ccfgPtr = (void*)entry_t;

					/* put payload length and pointer of entry's data to this entry's callback function to check integrity */
					callBackArray[0] = (uint32)(cfgmgr_entryTbl[idx].tableId);

					{	/* for alignment issue */
						_cfgmgr_entry_t dummy;
						_cfgmgr_memcpy(&dummy, entry_t, CFGENTRY_HEADER_SIZE);
						callBackArray[1] = (uint32)(dummy.length);		/* length */
					}

					callBackArray[2] = (uint32)&(entry_t->data);	/* data */

					if (	(*(cfgmgr_entryTbl[idx].callBackFunction.pCallBackFunction))(	CFGMGR_CALLBACK_CHECKINTEGRITY,
																				sizeof(callBackArray)/sizeof(callBackArray[0]),
																				callBackArray)
						== SUCCESS )
					{
						CFGMGR_INFO("Entry (%d) pass integrity check.", currTableId);
						cfgmgr_entryTbl[idx].integrity |= CFGMGR_ENTRY_INTEGRITY;
					} else
					{
						CFGMGR_WARN("Entry (%d) FAIL in integrity check.", currTableId);
						cfgmgr_entryTbl[idx].integrity &= ~CFGMGR_ENTRY_INTEGRITY;
						integrityOk = FALSE;
					}
				}

				/* current entry check ok, get next to check */
				goto next_entry;
			}
		}

		/*
			Eetry is not found in user registered field:

				Might due to different version of run time image.
				In this case, we 'might' can keep these unknown setting,
				so we don't set 'integrityOk = FALSE' here.
		*/
		CFGMGR_WARN("Entry (%d) not be registered by user.", currTableId);

		next_entry:

		{	/* for alignment issue */
			_cfgmgr_entry_t dummy;

			_cfgmgr_memcpy(&dummy, entry_t, CFGENTRY_HEADER_SIZE);

			currTableId = (uint32)(dummy.nextTableId);
		}

		{
			CFGENTRY_GET_TOTAL_SIZE(real_len, entry_t);

			entry_t = (_cfgmgr_entry_t*)((uint32)entry_t + real_len);
		}

	}

post_entryCheck:
	if (entry_len > 0)
	{
		CFGMGR_WARN("Global length declaration is larger than real data.");
		integrityOk = FALSE;
		resetIntegrity = TRUE;	/* we CAN NOT trust ALL entries because it probably means structure is broken */
	}

	if (resetIntegrity == TRUE)
	{
		/*
			reset all entries' integrity because we CAN NOT trust them !
		*/
		for (idx = 0 ; idx < cfgmgrParam.maxEntryCount ; idx ++)
		{
			cfgmgr_entryTbl[idx].integrity &= ~CFGMGR_ENTRY_INTEGRITY;
			cfgmgr_entryTbl[idx].ccfgPtr = NULL;
		}
	} 
	if (integrityOk == TRUE)
	{
		return CFGMGR_INFO_INTEGRITYOK;
	}

	retval = CFGMGR_INFO_INTEGRITYFAIL;
	goto err;

fatal:
	CFGMGR_HALT();
err:
	return retval;
}

//#define MAX_ENTRY_CONFIG_BUFFSIZE	4096
//#define MAX_ENTRY_CONFIG_BUFFSIZE	8192
#define MAX_ENTRY_CONFIG_BUFFSIZE	16384

/*
	factoryDefault == FALSE:	update CCFG based on currently-set-configuration
	factoryDefault == TRUE:	just do FactoryDefault, whole information are gotten from Default value
	
*/
static int32 _cfgmgr_updateCCFG(uint8 factoryDefault)
{
	int32 retval = FAILED;
	void *curr;
	uint32 len, idx;
	uint16 *tableId_p = NULL;
	_cfgmgr_ctrl_t *ctrl_t = NULL;
	_cfgmgr_entry_t *entry_t = NULL;

	/* check CFGMGR state */
	if (!LEAST_STATE(CFGMGR_STATE_REGISTEROK))
	{
		CFGMGR_ERR("configuration flow fail: %d\n", cfgmgr_state);
		retval = CFGMGR_ERR_CFGFLOWFAIL;
		goto fatal;
	}

	/**************************************************************
		(0) We must do integrity check to update integrity status before update
	  **************************************************************/
	retval = _cfgmgr_integrityCheck();	/* check the sync status of CCFG SDRam data */

	/* <--- reset buffer before doning factory default ---> */
	memset(shadow, 0, sizeof(cfgmgrParam.maxCfgSize));
	len = 0;	/* total length of CCFG (including CCFG control header) */
	curr = (_cfgmgr_ctrl_t*)shadow;

	/**************************************************************
		(1) generate CCFG global header
	  **************************************************************/

	{
		CFGMGR_INFO("--> Start Global Header generation.");

		/**************************************************************
			(1-1) Check if we can write global control header to shadow memory
		  **************************************************************/
		if (sizeof(_cfgmgr_ctrl_t) > cfgmgrParam.maxCfgSize)
		{
			CFGMGR_ERR("Shadow buffer size (%d) is not enough to store configuration.", cfgmgrParam.maxCfgSize);
			goto fatal;
		}

		/*************************************************
			(1-2) Start to generate global control header
		  *************************************************/
		ctrl_t = curr;

		/* signature */
		CFGMGR_INFO("Generate signature: %s", CFGMGR_SIGNATURE);
		_cfgmgr_memcpy((void*)(ctrl_t->signature), CFGMGR_SIGNATURE, strlen(CFGMGR_SIGNATURE));

		/* version */
		CFGMGR_INFO("Generate version: %d", CFGMGR_VERSION);
		ctrl_t->version = CFGMGR_VERSION;
		/* we can NOT decide 'length' and 'firstTableId' field yet, just init them here */
		ctrl_t->length = 0;
		ctrl_t->firstTableId = CFGMGR_TABLEID_NULL;
		tableId_p = &(ctrl_t->firstTableId);

		len += sizeof(_cfgmgr_ctrl_t);
	}

	/**************************************************************
		(2) trace entry table to generate entry info
	  **************************************************************/
	entry_t = (_cfgmgr_entry_t*)((uint32)(ctrl_t) + sizeof(_cfgmgr_ctrl_t));
	
	for (idx = 0 ; idx < cfgmgrParam.maxEntryCount ; idx ++)
	{
		uint32 dataLen = 0;			/* data length of value to update */
		void *dataPtr = NULL;			/* data pointer of value to update */
		uint8 tmpBuff[MAX_ENTRY_CONFIG_BUFFSIZE] = {0};

		if (cfgmgr_entryTbl[idx].tableId == CFGMGR_TABLEID_NULL)
		{
			continue;
		}

		CFGMGR_INFO("Try to sync Table ID [%d].", cfgmgr_entryTbl[idx].tableId);

		/*************************
			(2-1) Get information
		  *************************/
		if (	(factoryDefault == FALSE) &&
			(cfgmgr_entryTbl[idx].integrity == (CFGMGR_ENTRY_CHECKED|CFGMGR_ENTRY_INTEGRITY)))
		{
			if (cfgmgr_entryTbl[idx].ccfgPtr == NULL)
			{
				/* normal process can NOT arrive here */
				CFGMGR_ERR("integrity check pass, but entry is not found.");
				goto fatal;
			}

			/* get CCFG data successfully, get its length */

			{	/* for alignment issue */
				_cfgmgr_entry_t dummy;
				_cfgmgr_memcpy(&dummy, (void*)(cfgmgr_entryTbl[idx].ccfgPtr), CFGENTRY_HEADER_SIZE);
				dataLen = (uint32)(dummy.length);
			}
			dataPtr = (void*)&(((_cfgmgr_entry_t*)(cfgmgr_entryTbl[idx].ccfgPtr))->data);
		} else
		{
			/* We get information form Factory Default source */

			uint32 callBackArray[5];
			uint8 *orig_data = NULL;
			uint32 orig_dataSize = 0;

			/* 		Maybe there is an entry in CCFG but has no
					integrity, we need to send it to callback function.			 */
			if (cfgmgr_entryTbl[idx].ccfgPtr != NULL)
			{
				{	/* for alignment issue */
					_cfgmgr_entry_t dummy;
					_cfgmgr_memcpy(&dummy, (void*)(cfgmgr_entryTbl[idx].ccfgPtr), CFGENTRY_HEADER_SIZE);
					orig_dataSize = (uint32)(dummy.length);
				}

				orig_data = &(((_cfgmgr_entry_t*)(cfgmgr_entryTbl[idx].ccfgPtr))->data);
			}

			dataLen = MAX_ENTRY_CONFIG_BUFFSIZE;	/* total size of tmpBuff */

			callBackArray[0] = (uint32)(cfgmgr_entryTbl[idx].tableId);
			callBackArray[1] = (uint32)orig_data;		/* original data */
			callBackArray[2] = (uint32)orig_dataSize;	/* original data size */
			callBackArray[3] = (uint32)tmpBuff;		/* buffer to write information */
			callBackArray[4] = (uint32)(&dataLen);	/* size of tmpBuff: if callBack function set Factory Default successfully, this would be set to the real length of default data */

			if (	(retval = (*(cfgmgr_entryTbl[idx].callBackFunction.pCallBackFunction))(	CFGMGR_CALLBACK_FACTORYDEFAULT,
																				sizeof(callBackArray)/sizeof(callBackArray[0]),
																				callBackArray))
				!= SUCCESS )
			{
				CFGMGR_ERR("get Factory Default value from callBack function fail (%d).", retval);
				goto fatal;
			}

			/*
				We get default value successfully, so 'dataLen' has been set in CallBack function.
				And we set the 'dataPtr' to tmpBuff to indicate the data which need to be updated.
			*/
			dataPtr = tmpBuff;
		}

		/*************************************************
			(2-2) Check if we can write it to shadow memory
		  *************************************************/
		if ((len + CFGENTRY_HEADER_SIZE + dataLen) > cfgmgrParam.maxCfgSize)
		{
			CFGMGR_ERR("Shadow buffer size (%d) is not enough to store configuration.", cfgmgrParam.maxCfgSize);
			goto fatal;
		}

		/*************************************************
			(2-3) Write information into shadow memory
		  *************************************************/
		_cfgmgr_memcpy(&(entry_t->length), &dataLen, sizeof(uint32));
		_cfgmgr_memcpy(&(entry_t->data), dataPtr, dataLen);
		_cfgmgr_memcpy(tableId_p, &(cfgmgr_entryTbl[idx].tableId), sizeof(uint16));	/* for alignment issue */

		{
			uint32 entry_len;
			CFGENTRY_GET_TOTAL_SIZE(entry_len, entry_t);
			len += entry_len;
		}

		/*************************************************
			(2-4) Set pointer to next entry and init nextTableId
		  *************************************************/
		{	/* for alignment issue */
			uint16 null_id = CFGMGR_TABLEID_NULL;
			_cfgmgr_memcpy(&(entry_t->nextTableId), &null_id, sizeof(null_id));
		}
		tableId_p = &(entry_t->nextTableId);
		{
			uint32 entry_len;
			CFGENTRY_GET_TOTAL_SIZE(entry_len, entry_t);

			entry_t = (_cfgmgr_entry_t*)(entry_len + (uint32)entry_t);
		}
	
	}

	/**************************************************************
		(3) set remainding information to CCFG control header
	  **************************************************************/
	CFGMGR_INFO("Generate Global length: %d", len-sizeof(_cfgmgr_ctrl_t));
	ctrl_t->length = len - sizeof(_cfgmgr_ctrl_t);	/* 'length' field in CCFG control header does NOT include header itself. */

	/**************************************************************
		(4) Sync shadow SDRAM configuration
	  **************************************************************/
	/* (4-0) If shadow == SDRAM data, it means no any update are needed */
	if (memcmp(shadow, CCFG_PTR, len) == 0)
	{
		CFGMGR_INFO("New gerenerated configruation is same as old one, no update is needed.");
		goto okout;
	} else
	{
		char tmp[CFGMGR_SIGNATURE_LENGTH];
		CFGMGR_INFO("Actually update new generated configuration to SDRAM / FLASH.");
		CFGMGR_INFO("=========================================");
		CFGMGR_INFO("Original:");
		strncpy((void*)tmp, CCFG_PTR->signature, CFGMGR_SIGNATURE_LENGTH);;
		CFGMGR_INFO("\tSignature: %s", tmp);
		CFGMGR_INFO("\tVersion: %d", CCFG_PTR->version);
		CFGMGR_INFO("\tCfg Len: %d", CCFG_PTR->length);
		CFGMGR_INFO("New:");
		strncpy((void*)tmp, ((_cfgmgr_ctrl_t*)shadow)->signature, CFGMGR_SIGNATURE_LENGTH);
		CFGMGR_INFO("\tSignature: %s", tmp);
		CFGMGR_INFO("\tVersion: %d", ((_cfgmgr_ctrl_t*)shadow)->version);
		CFGMGR_INFO("\tCfg Len: %d", ((_cfgmgr_ctrl_t*)shadow)->length);
		CFGMGR_INFO("=========================================");
	}
	/* (4-1) Sync SDRAM data and FLASH */
	CFGMGR_INFO("Sync to FLASH");
	if (_cfgmgr_writeCcfgFlash(shadow, len) != SUCCESS)
	{
		goto err;
	}
	/* (4-2) Sync Shadow and SDRAM data */
	CFGMGR_INFO("Sync to SDRAM");
	_cfgmgr_memcpy(CCFG_PTR, shadow, len);

#if 0
#if !defined(DNI)
	/**************************************************************
		(5) Reboot
	  **************************************************************/
	CFGMGR_INFO("[ System restarting ]");
	sleep(2);
	_cfgmgr_865xIoctl("eth0", RTL8651_IOCTL_REBOOT, 0, 0, 0);
#else

	sys_reboot();
#endif
#endif	

okout:
	/* update complete, return SUCCESS */
	return SUCCESS;

fatal:
	CFGMGR_HALT();
err:
	return retval;

}

/**************************************************************************************
  *
  *	FLASH interface process
  *
  **************************************************************************************/

/*
	Flash Read
*/
static int32 _cfgmgr_readCcfgFlash(void *sdramCfg, uint32 size)
{
	if (!LEAST_STATE(CFGMGR_STATE_INITOK))
	{
		CFGMGR_ERR("configuration flow fail: %d\n", cfgmgr_state);
		CFGMGR_HALT();
		goto err;
	}

	CFGMGR_INFO("==> Read Flash (%p) (size==%d) to SDRAM (%p).", FLASH_CCFG, size, sdramCfg);

	if (size > cfgmgrParam.maxCfgSize)
	{
		CFGMGR_WARN("Read Size (%lu) is larger than max CCFG size (%lu).", size, cfgmgrParam.maxCfgSize);
	}

	_cfgmgr_memcpy(sdramCfg, (void*)FLASH_CCFG, size);
	
	CFGMGR_INFO("==> Flash read OK.");

	return SUCCESS;

err:
	CFGMGR_INFO("==> Flash read FAIL.");
	return FAILED;

}

/*
	Flash Write

	** Note : sdramCfg must follow the alignment requirement (FLASH_ALIGN) of FLASH driver.
*/
static int32 _cfgmgr_writeCcfgFlash(void *sdramCfg, uint32 size)
{
	void *actualWrite = sdramCfg;
	uint32 actualSize = size;

	CFGMGR_INFO("==> Write Flash (%p) (size==%d) from SDRAM (%p).", FLASH_CCFG, size, sdramCfg);

	if (!LEAST_STATE(CFGMGR_STATE_INITOK))
	{
		CFGMGR_ERR("configuration flow fail: %d\n", cfgmgr_state);
		CFGMGR_HALT();
		goto err;
	}

	if (((uint32)sdramCfg) & (FLASH_ALIGN - 1))
	{
		CFGMGR_ERR("*** FATAL: address to write (%p) is not %d byte alignment.", sdramCfg, FLASH_ALIGN);
		CFGMGR_ERR("*** FATAL: Write FAIL!");
		goto err;
	}

	if (size > cfgmgrParam.maxCfgSize)
	{
		CFGMGR_WARN("Write Size (%lu) is larger than max CCFG size (%lu).", size, cfgmgrParam.maxCfgSize);
	}

	if (size == 0)
	{	/* no FLASH write is needed */
		goto okout;
	}

	/* =======================================
		In order to reduce the ERASE count of FLASH memory,
		we try to read data in FLASH and compare it with
		'sdramCfg' before actually do FLASH write.

		If whole data in FLASH is same as 'sdramCfg', we will
		stop FLASH write because this if is unnecessary.
	     ======================================= */
	if (	(Flash_buff) &&
		(size < cfgmgrParam.maxCfgSize	/* to make sure Flash_buff can store whole data with inputted size. */))
	{
		if (_cfgmgr_readCcfgFlash(Flash_buff, size) == SUCCESS /* read Flash to Flash_buff */)
		{
			if (memcmp(sdramCfg, Flash_buff, size) == 0)
			{
				CFGMGR_INFO("Data in FLASH is same as data to write, no FLASH write is needed.");
				goto okout;
			}
#if 0
			else
			{	/* compare Flash_buff and sdramCfg, find its different */
				void *headCandidate = NULL, *tailCandidate = NULL;
				char *p1, *p2;
				uint32 len;

				/* -----------------------------------------
							Find head
				    ----------------------------------------- */

				p1 = (char *)Flash_buff;
				p2 = (char *)sdramCfg;
				len = 0;

				while (len < size)
				{
					if (*p1 != *p2)
					{
						goto headFound;
					}
					p1 ++;
					p2 ++;
					len ++;
				}
				/*	(len >= size) and (all *p1/*p2 are the same) :
					It's impossible because this must be filtered in memcmp() above. */
				CFGMGR_ERR("*** ALL data are the same but not be filtered in previous code.");
				goto okout;
				
			headFound:

				headCandidate = (void *)p2;	/* we point to sdramCfg's offset */

				/* -----------------------------------------
							Find tail
				    ----------------------------------------- */
				p1 = (char *)((uint32)Flash_buff + size - 1 /* (size == 0) has be filtered */);
				p2 = (char *)((uint32)sdramCfg + size - 1 /* (size == 0) has be filtered */ );
				len = 0;

				while (len < size)
				{
					if (*p1 != *p2)
					{
						goto tailFound;
					}
					p1 --;
					p2 --;
					len ++;
				}

				/*	(len >= size) and (all *p1/*p2 are the same) :
					It's impossible because this must be filtered in memcmp() above. */
				CFGMGR_ERR("*** ALL data are the same but not be filtered in previous code.");
				goto okout;
				
			tailFound:

				tailCandidate = (void *)p2;		/* we point to sdramCfg's offset */

				/* -----------------------------------------------------------
							Check the correctness of gotten head and tail
				    ----------------------------------------------------------- */

				if ((uint32)headCandidate > (uint32)tailCandidate)
				{
					CFGMGR_ERR("*** headCandidate (%p) > tailCandidate (%p).", headCandidate, tailCandidate);
					goto flash_write;
				}

				/* -----------------------------------------------------------
							We can calculate the actual write address
							and actual write size based on head and tail.
				    ----------------------------------------------------------- */
				actualWrite = headCandidate;
				actualSize = (uint32)tailCandidate - (uint32)headCandidate + 1;

				/* For alignment issue of FLASH driver */
				if (((uint32)actualWrite) & (FLASH_ALIGN - 1))
				{
					/*
						Write address is not 'FLASH_ALIGN' byte alignment, need to modify:

							Because the input address (sdramCfg) MUST conform to the alignment issue,
							so we can claim that (actualWrite > sdramCfg) and we can find an aligned
							address between 'sdramCfg' and actualWrite.
					*/
					void *alignedWriteAddr;

					alignedWriteAddr = (void *)(((uint32)actualWrite) & ~(FLASH_ALIGN - 1));

					if ((uint32)alignedWriteAddr < (uint32)sdramCfg)
					{
						CFGMGR_ERR("*** alignedWriteAddr (%p) < sdramCfg (%p), it's IMPOSSIBLE!", alignedWriteAddr, sdramCfg);

						/* we use original data to write FLASH */
						actualWrite = sdramCfg;
						actualSize = size;
						goto flash_write;
					}

					/* update write address / size */

					actualSize += ((uint32)actualWrite - (uint32)alignedWriteAddr);
					actualWrite = alignedWriteAddr;

				}
			}
#endif
		}
		/* other cases : continue FLASH write procedure */
	}

flash_write:

	CFGMGR_INFO("==> Start Flash write (from (0x%p, size %lu)).", actualWrite, actualSize);

	#ifdef _SUPPORT_LARGE_FLASH_
	/* Load BoardInfo first */
	flashdrv_read(	(void*)&bdinfo,
					(void*)FLASH_BDINFO,
					sizeof(bdinfo));
	#endif

	if (flashdrv_isLoaderOverwritten((uint8*)FLASH_CCFG, actualSize) == TRUE)
	{
		/* Loader would be overwritten, so we stop FLASH write here! */
		CFGMGR_ERR("CFGMGR configuration would over-write Loader code.");
		goto err;
	}

	if (flashdrv_updateImg(	actualWrite,
							(void*)((uint32)FLASH_CCFG + ((uint32)actualWrite - (uint32)sdramCfg)),
							actualSize) != SUCCESS)
	{
		/* Flash update fail ! */
		CFGMGR_ERR("CFGMGR flash update fail.");
		goto err;
	}

	CFGMGR_INFO("==> Flash write OK.");

okout:
	return SUCCESS;

err:
	CFGMGR_INFO("=====> Flash write FAIL.");
	return FAILED;
}

#define CFGMGR_LIBRARY

/**************************************************************************************
  *
  *	Libraries
  *
  **************************************************************************************/
/*
	memory copy
  */
static void *_cfgmgr_memcpy(void *out, const void *in, const uint32 n)
{
	char *dst = (char *) out;
	char *src = (char *) in;
	uint32 m = n;
	void *tmp;

	tmp = out;

	while (m--)
	{
		*dst++ = *src++;
	}
	
	return tmp;
}

/*
  * re865x Ioctl (to call kernel functions including rtl8651 table driver APIs
  */
static int _cfgmgr_865xIoctl(char *name, uint32 arg0, uint32 arg1, uint32 arg2, uint32 arg3)
{
	uint32 args[4];
	struct ifreq ifr;
	int sockfd;

	args[0] = arg0;
	args[1] = arg1;
	args[2] = arg2;
	args[3] = arg3;

	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{
		CFGMGR_ERR("fatal error socket.");
		return -3;
	}

	strcpy((char*)&ifr.ifr_name, name);

	((uint32 *)(&ifr.ifr_data))[0] = (uint32)args;

	if (ioctl(sockfd, SIOCDEVPRIVATE, &ifr) < 0)
	{
		CFGMGR_ERR("device ioctl error.");
		close(sockfd);
		return -1;
	}

	close(sockfd);
	return 0;
}

/* end of cfgmgr.c */
