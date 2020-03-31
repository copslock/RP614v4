#include "rtl865x/rtl_types.h"
#include <linux/config.h>
#include "rtl865x/asicRegs.h"

#ifdef __linux__
#include <linux/autoconf.h>
#include <linux/netdevice.h>
#include <linux/interrupt.h>
#include <linux/skbuff.h>
#endif
#include "rtl865x/rtl8651_tblDrv.h"

/*command line engine supported*/
#include "cle/rtl_cle.h"
#include "swNic2.h"
#ifdef CONFIG_RTL865X_MULTILAYER_BSP
//CLE commands for Multilayer BSP
#include "rtl865x/rtl8651_tblDrv_cmd.h"
#include "rtl865x/rtl8651_tblDrvFwd_cmd.h"
#include "rtl865x/rtl8651_tblAsicDrv_cmd.h"
#endif
#if defined(CONFIG_SMI)
#include "smi_cmd.h"
#endif
#ifdef CONFIG_RTL8305S
#include "rtl865x/rtl8305s_cmd.h"
#endif

#ifdef CONFIG_RTL8185
#include "flashdrv.h"
#endif

#ifdef CONFIG_RTL865x_SWPUBKEY
#include "crypto/rtl_crypt_cmd.h"
#endif

#ifdef CONFIG_RTL865XB_EXP_CRYPTOENGINE
//CLE commands for Crypto engine
#include "crypto/865xb/cryptoCmd.h"
#endif

#ifdef CONFIG_RTL865X_PCM
#include "../rtl8186/pcm.h"
#endif

#ifdef CONFIG_RTL865X_BENCHMARK
#include "benchmark/benchmark.h"
#endif

#ifdef CONFIG_RTL865X_ROMEPERF
#include "romeperf.h"
#endif

#ifdef CONFIG_RTL865X_VOIP
#include "voip/voip_cmd.h"
#endif

#if defined(RTL865X_MODEL_USER)||defined(RTL865X_MODEL_KERNEL)
#include "model/model_cmd.h"
#include "cle/cle_userglue.h"
#endif

#ifdef CONFIG_RTL865XB_EXP_PERFORMANCE_EVALUATION
#include "cle_cmdRoot.h"
#endif

#ifdef CONFIG_RTL865XB_EXP_CRYPTOENGINE
extern unsigned long volatile jiffies;
static int8 *cryptKey, *cryptIv;
int8 destBuffer[8192];
static int8 srcBuffer[8192];
int32 maxPoll=0;
int32 cryptoMemcpyInit=0;

static int32 cmdCrymemcpy(uint32 userId,  int32 argc,int8 **saved){
	int8 *nextToken;
	int32 size;
	uint32 start, length,cryptCopyBytes,iteration;
	int32 emulate=0, mode=7, pollFreq=0;
	int32 i;
	#define UNCACHED_MALLOC(x)  (void *) (0xa0000000 | (uint32) rtlglue_malloc(x))
	if(cryptoMemcpyInit==0){
		rtl8651b_cryptoEngine_init(4,FALSE );
		cryptKey = (int8 *) UNCACHED_MALLOC(24);
		cryptIv = (int8 *) UNCACHED_MALLOC(8);
		for(i=0; i<24; i++)
			cryptKey[i] = 0x01;
		for(i=0; i<8; i++)
			cryptIv[i] = 0x01;
		cryptoMemcpyInit=1;
		memset(destBuffer, 1, sizeof(destBuffer));
		memset(srcBuffer, 1, sizeof(srcBuffer));		
	}
	printk("(Each 8K)Src: %08x, Dst: %08x\n", (uint32)srcBuffer, (uint32)destBuffer);
	cle_getNextCmdToken(&nextToken,&size,saved); 
	if(!size){
		if(strcmp("emulate", nextToken)!=0)
			return SUCCESS;
		emulate=1;
		cle_getNextCmdToken(&nextToken,&size,saved); 
	}
	length = U32_value(nextToken);
	if(length>sizeof(destBuffer))
		length=sizeof(destBuffer);
	cle_getNextCmdToken(&nextToken,&size,saved); 
	cryptCopyBytes = U32_value(nextToken);
	cle_getNextCmdToken(&nextToken,&size,saved); 
	if(!size){
		mode |= 0x8; //polling		
		cle_getNextCmdToken(&nextToken,&size,saved); 
		pollFreq = U32_value(nextToken); //polling frequency
		cle_getNextCmdToken(&nextToken,&size,saved); 
	}
	iteration = U32_value(nextToken);
	maxPoll=0;
	start = jiffies;
	for(i=0;i<iteration;i++){
		int32 poll;		
		if(cryptCopyBytes&7){
			cryptCopyBytes&=~7;
			cryptCopyBytes+=8;
		}
		if(cryptCopyBytes>0){
			rtl8651b_cryptoMemcpy(destBuffer); //specify destination address
		//rtl8651b_cryptoMemcpy(srcBuffer); //specify destination address
		if(emulate==1)
			mode&=~0x10;
		else
			mode |= 0x10;			
		if(FAILED==rtl8651b_cryptoEngine_des(mode, (void *)(0x20000000|((uint32)&srcBuffer[0])),cryptCopyBytes, cryptKey, cryptIv))
			printk("%s:cryptCopyBytes:%uB  crypto:%u, memcpy:%u FAILED\n", 
				(mode&8)?"Nonblock":"Blocking",(uint32)length, (uint32)cryptCopyBytes,(uint32) length- cryptCopyBytes);
		}
	
		if(length-cryptCopyBytes>0){
			//always copy to uncached.
			memcpy((void *)(0x20000000|((uint32)&destBuffer[cryptCopyBytes])), (void *)((0x20000000|(uint32)&srcBuffer[cryptCopyBytes])),length-cryptCopyBytes);
		}

		if(cryptCopyBytes>0 && (mode&8)){
			poll=rtl8651b_cryptoEngine_des_poll(pollFreq);
			if(poll<0){
				if(-poll>maxPoll){
					printk("Poll: %d, max:%d\n", -poll, maxPoll);					
					maxPoll=-poll;
				}
			}
		}
	}
	printk("Mode %x: Copy %d * %d times. Total %d bytes, %d ms.  %u KBps\n",mode, length, iteration, (uint32)(length*iteration),(uint32)((jiffies-start)*10), (uint32)((length*iteration))/(10*((uint32)(jiffies-start))));
	return SUCCESS;
}
#endif/*#ifdef CONFIG_RTL865XB_EXP_CRYPTOENGINE	*/


#ifdef CONFIG_RTL865XB_EXP_PERFORMANCE_EVALUATION

void startCOP3Counters(int32 countInst){
	/* counter control modes:
		0x10	cycles
		0x11	new inst fetches
		0x12	inst fetch cache misses
		0x13	inst fetch miss busy cycles
		0x14	data store inst
		0x15	data load inst
		0x16	load or store inst
		0x1a	load or store cache misses
		0x1b	load or store miss busy cycles
		*/
	uint32 cntmode;

	if(countInst == TRUE)
		cntmode = 0x13121110;
	else
		cntmode = 0x1b1a1610;
	
	__asm__ __volatile__ (
		/* update status register CU[3] usable */
		"mfc0 $9,$12\n\t"
		"nop\n\t"
		"la $10,0x80000000\n\t"
		"or $9,$10\n\t"
		"mtc0 $9,$12\n\t"
		"nop\n\t"
		"nop\n\t"
		/* stop counters */
		"ctc3 $0,$0\n\t"
		/* clear counters */
		"mtc3 $0,$8\n\t"
		"mtc3 $0,$9\n\t"
		"mtc3 $0,$10\n\t"
		"mtc3 $0,$11\n\t"
		"mtc3 $0,$12\n\t"
		"mtc3 $0,$13\n\t"
		"mtc3 $0,$14\n\t"
		"mtc3 $0,$15\n\t"
		/* set counter controls */
		"ctc3 %0,$0"
		: /* no output */
		: "r" (cntmode)
		);
}


uint32 stopCOP3Counters(void){
	uint32 cntmode;
	uint32 cnt0h, cnt0l, cnt1h, cnt1l, cnt2h, cnt2l, cnt3h, cnt3l;
	__asm__ __volatile__ (
		/* update status register CU[3] usable */
		"mfc0 $9,$12\n\t"
		"nop\n\t"
		"la $10,0x80000000\n\t"
		"or $9,$10\n\t"
		"mtc0 $9,$12\n\t"
		"nop\n\t"
		"nop\n\t"
		/* get counter controls */
		"cfc3 %0,$0\n\t"
		/* stop counters */
		"ctc3 $0,$0\n\t"
		/* save counter contents */
		"mfc3 %1,$9\n\t"
		"mfc3 %2,$8\n\t"
		"mfc3 %3,$11\n\t"
		"mfc3 %4,$10\n\t"
		"mfc3 %5,$13\n\t"
		"mfc3 %6,$12\n\t"
		"mfc3 %7,$15\n\t"
		"mfc3 %8,$14\n\t"
		"nop\n\t"
		"nop\n\t"
		: "=r" (cntmode), "=r" (cnt0h), "=r" (cnt0l), "=r" (cnt1h), "=r" (cnt1l), "=r" (cnt2h), "=r" (cnt2l), "=r" (cnt3h), "=r" (cnt3l)
		: /* no input */
		);
	if(cntmode == 0x13121110){
		printk("COP3 counter for instruction access\n");
		printk("%10d cycles\n", cnt0l);
		printk("%10d new inst fetches\n", cnt1l);
		printk("%10d inst fetch cache misses\n", cnt2l);
		printk("%10d inst fetch miss busy cycles\n", cnt3l);
		}
	else{
		printk("COP3 counter for data access\n");
		printk("%10d cycles\n", cnt0l);
		printk("%10d load or store inst\n", cnt1l);
		printk("%10d load or store cache misses\n", cnt2l);
		printk("%10d load or store miss busy cycles\n", cnt3l);
		}
	return cnt0l;
}

static int8 cop3InstMode;
static uint64 cop3Cycles, cop3InstFetches, cop3InstCacheMisses, cop3InstcacheMissBusyCycles;
static uint64 cop3DataInst, cop3DataCacheMisses, cop3DataCacheMissCycles;

void clearCOP3Counters(void){
	cop3InstMode = 0;
	cop3Cycles = 0;
	cop3InstFetches = 0;
	cop3InstCacheMisses = 0;
	cop3InstcacheMissBusyCycles = 0;
	cop3DataInst = 0;
	cop3DataCacheMisses = 0;
	cop3DataCacheMissCycles = 0;
}

void pauseCOP3Counters(void){
	uint32 cntmode;
	uint32 cnt0h, cnt0l, cnt1h, cnt1l, cnt2h, cnt2l, cnt3h, cnt3l;
	__asm__ __volatile__ (
		/* update status register CU[3] usable */
		"mfc0 $9,$12\n\t"
		"nop\n\t"
		"la $10,0x80000000\n\t"
		"or $9,$10\n\t"
		"mtc0 $9,$12\n\t"
		"nop\n\t"
		"nop\n\t"
		/* get counter controls */
		"cfc3 %0,$0\n\t"
		/* stop counters */
		"ctc3 $0,$0\n\t"
		/* save counter contents */
		"mfc3 %1,$9\n\t"
		"mfc3 %2,$8\n\t"
		"mfc3 %3,$11\n\t"
		"mfc3 %4,$10\n\t"
		"mfc3 %5,$13\n\t"
		"mfc3 %6,$12\n\t"
		"mfc3 %7,$15\n\t"
		"mfc3 %8,$14\n\t"
		"nop\n\t"
		"nop\n\t"
		: "=r" (cntmode), "=r" (cnt0h), "=r" (cnt0l), "=r" (cnt1h), "=r" (cnt1l), "=r" (cnt2h), "=r" (cnt2l), "=r" (cnt3h), "=r" (cnt3l)
		: /* no input */
		);
	if(cntmode == 0x13121110){
		cop3InstMode = 1;
		cop3Cycles += cnt0l;
		cop3InstFetches += cnt1l;
		cop3InstCacheMisses = cnt2l;
		cop3InstcacheMissBusyCycles = cnt3l;
		}
	else{
		cop3InstMode = 0;
		cop3Cycles += cnt0l;
		cop3DataInst += cnt1l;
		cop3DataCacheMisses += cnt2l;
		cop3DataCacheMissCycles += cnt3l;
		}
}

void DisplayCOP3Counters(void){
#define _displayy(val, str) if(val > 0xffffffffUL)\
	printk("0x%x%08x %s\n", (uint32) (val >> 32), (uint32) (val & 0xffffffffUL), str);\
else\
	printk("%10d %s\n", (uint32) val, str);

	if(cop3InstMode == 1){
		printk("COP3 counter for instruction access\n");
		_displayy(cop3Cycles, "cycles");
		_displayy(cop3InstFetches, "new instruction fetches");
		_displayy(cop3InstCacheMisses,"instruction fetch cache misses");
		_displayy(cop3InstcacheMissBusyCycles, "instruction fetch miss busy cycles");
		}
	else{
		printk("COP3 counter for data access\n");
		_displayy(cop3Cycles, "cycles");
		_displayy(cop3DataInst, "load or store instruction");
		_displayy(cop3DataCacheMisses,"load or store cache misses");
		_displayy(cop3DataCacheMissCycles, "load or store miss busy cycles");
		}
}
#endif

#ifdef CONFIG_RTL865XB_EXP_PERFORMANCE_EVALUATION
static int32 _rtl8651_startCOP3Counters(uint32 userId,  int32 argc,int8 **saved){
	int8 *nextToken;
	int32 size;
	
	cle_getNextCmdToken(&nextToken,&size,saved); 
	if(strcmp("inst", nextToken)==0){
		startCOP3Counters(TRUE);
		}
	else if(strcmp("data", nextToken)==0){
		startCOP3Counters(FALSE);
		}
	else if(strcmp("end", nextToken)==0){
		stopCOP3Counters();
		}
	else
		return FAILED;

	return SUCCESS;
}


 static int32 _rtl8651_permemcpyCmd(uint32 userId,  int32 argc,int8 **saved){
	int8 *nextToken;
	int32 size;
	int8 *pSrcBuffer;
	int8 *pDestBuffer;
	uint32 start, length, iteration;
	int32 i;
	int32 cop3i, cop3d;

	cop3i = cop3d = FALSE;
	pSrcBuffer = (int8*)((uint32)srcBuffer | 0x20000000UL);
	pDestBuffer = (int8*)((uint32)destBuffer | 0x20000000UL);
	cle_getNextCmdToken(&nextToken,&size,saved); 
	if(!size){
		if(strcmp("cached", nextToken)==0){
			pSrcBuffer = srcBuffer;
			pDestBuffer = destBuffer;
			cle_getNextCmdToken(&nextToken,&size,saved); 
			}
		if(strcmp("COP3I", nextToken)==0){
			cop3i = TRUE;
			cle_getNextCmdToken(&nextToken,&size,saved); 
			}
		else if(strcmp("COP3D", nextToken)==0){
			cop3d = TRUE;
			cle_getNextCmdToken(&nextToken,&size,saved); 
			}
	}
	length = U32_value(nextToken);
	if(length>sizeof(destBuffer))
		length=sizeof(destBuffer);
	cle_getNextCmdToken(&nextToken,&size,saved); 
	iteration = U32_value(nextToken);
	if(cop3i || cop3d)
		startCOP3Counters(cop3i);
	start = jiffies;
	for(i=0;i<iteration;i++)
		memcpy(pDestBuffer, pSrcBuffer, length);
	printk("(each 8K)Src: %08x, Dst: %08x\n", (uint32)pSrcBuffer, (uint32)pDestBuffer);
	printk("Copy %d * %d times. Total %d bytes, %d ms.  %u KBps\n", length, iteration, (uint32)(length*iteration),(uint32)((jiffies-start)*10), (uint32)((length*iteration))/(10*((uint32)(jiffies-start))));
	if(cop3i || cop3d)
		stopCOP3Counters();

	return SUCCESS;
}


 static int32 _rtl8651_pernicrxCmd(uint32 userId,  int32 argc,int8 **saved){
	int8 *nextToken;
	int32 size;
	int32 instMode;

	cle_getNextCmdToken(&nextToken,&size,saved); 
	if(strcmp("inst", nextToken)==0)
		instMode = TRUE;
	else if(strcmp("data", nextToken)==0)
		instMode = FALSE;
	else
		return FAILED;

	cle_getNextCmdToken(&nextToken,&size,saved);
	swNic_pernicrxStart(instMode, U32_value(nextToken));
	return SUCCESS;
}


 static int32 _rtl8651_perpcitxCmd(uint32 userId,  int32 argc,int8 **saved){
	int8 *nextToken;
	int32 size;
	int32 instMode;

	cle_getNextCmdToken(&nextToken,&size,saved); 
	if(strcmp("inst", nextToken)==0)
		instMode = TRUE;
	else if(strcmp("data", nextToken)==0)
		instMode = FALSE;
	else if(strcmp("start", nextToken)==0){
		rtlglue_perpcitxGo();
		return SUCCESS;
		}
	else
		return FAILED;

	cle_getNextCmdToken(&nextToken,&size,saved);
	rtlglue_perpcitxStart(instMode, U32_value(nextToken));
	return SUCCESS;
}
#endif


#ifdef CONFIG_RTL865X_MULTILAYER_BSP
static int32 _rtl8651_debugCmd(uint32 userId,  int32 argc,int8 **saved){
	int8 *nextToken;
	int32 size, level;
	cle_getNextCmdToken(&nextToken,&size,saved); 
	if(size){
		level = U32_value(nextToken);
	}else if(strcmp(nextToken, "on") == 0) 
		level=1;
	else
		level=0;
	wlan_acc_debug=level;
	return SUCCESS;
}

static int32	_rtl8651_resetCmd(uint32 userId,  int32 argc,int8 **saved){
	return rtl8651_tblDrvReset();
}
#endif /*CONFIG_RTL865X_MULTILAYER_BSP*/

static int32	cmdPci(uint32 userId,  int32 argc,int8 **saved){
	int8 *nextToken;
	int32 size;
	uint32 *startaddr;
	uint32 value,value2;
	cle_getNextCmdToken(&nextToken,&size,saved); 
	if(strcmp(nextToken, "read") == 0) {
		cle_getNextCmdToken(&nextToken,&size,saved); //base address
		startaddr = (uint32*)U32_value(nextToken);
		cle_getNextCmdToken(&nextToken,&size,saved); //length

		value = (uint32)U32_value(nextToken);
		
		if(value==1)
		{
			u8 val;
			val=rtl865x_pci_ioread8((uint32)startaddr);
			printk("REG8(%x)=%02x\n",(uint32)startaddr,val);			
		}
		else if(value==2)
		{
			u16 val;
			val=rtl865x_pci_ioread16((uint32)startaddr);
			printk("REG16(%x)=%04x\n",(uint32)startaddr,val);			
		}
		else if(value==4)
		{
			u32 val;
			val=rtl865x_pci_ioread32((uint32)startaddr);
			printk("REG32(%x)=%08x\n",(uint32)startaddr,val);			
		}
		
		


	}else {

		cle_getNextCmdToken(&nextToken,&size,saved); //base address
		startaddr = (uint32 *)U32_value(nextToken);
		
		cle_getNextCmdToken(&nextToken,&size,saved);
		value = (uint32)U32_value(nextToken);

		cle_getNextCmdToken(&nextToken,&size,saved);
		value2 = (uint32)U32_value(nextToken);
		

		
		if(value2==1)
		{
			u8 val;
			rtl865x_pci_iowrite8((uint32)startaddr,value);
			val=rtl865x_pci_ioread8((uint32)startaddr);
			printk("REG8(%x)=%02x\n",(uint32)startaddr,val);			
		}
		else if(value2==2)
		{
			u16 val;
			rtl865x_pci_iowrite16((uint32)startaddr,value);
			val=rtl865x_pci_ioread16((uint32)startaddr);
			printk("REG16(%x)=%04x\n",(uint32)startaddr,val);			
		}
		else if(value2==4)
		{
			u32 val;
			rtl865x_pci_iowrite32((uint32)startaddr,value);
			val=rtl865x_pci_ioread32((uint32)startaddr);
			printk("REG32(%x)=%08x\n",(uint32)startaddr,val);			
		}		
		
	}

	return SUCCESS;
}
static int32	_rtl8651_memdump(uint32 userId,  int32 argc,int8 **saved){
	int8 *nextToken;
	int32 size;
	uint32 *startaddr, *addr;
	uint32 len, value;

	cle_getNextCmdToken(&nextToken,&size,saved); 
	if(strcmp(nextToken, "read") == 0) {
		cle_getNextCmdToken(&nextToken,&size,saved); //base address
		startaddr = (uint32*)U32_value(nextToken);
		cle_getNextCmdToken(&nextToken,&size,saved); //length
		len=U32_value(nextToken);

	}else {
		len=0;
		cle_getNextCmdToken(&nextToken,&size,saved); //base address
		addr=startaddr = (uint32 *)U32_value(nextToken);
		//while(
		cle_getNextCmdToken(&nextToken,&size,saved);// !=FAILED){
			value = (uint32)U32_value(nextToken);
			WRITE_MEM32( (uint32)addr, value );
			len+=4;
			addr++;
		//}
	}

#if defined(RTL865X_MODEL_USER) || defined(RTL865X_MODEL_KERNEL)
	/* According to asicRegs.h's pVirtualSWReg allocation, re-map the following area. */
	if ( ( (uint32)startaddr >= REAL_SWCORE_BASE ) && ( (uint32)startaddr < REAL_SWCORE_BASE+SWCORE_SIZE ) )
	{
		startaddr = (uint32*)(((uint32)startaddr)-REAL_SWCORE_BASE+SWCORE_BASE);
	}
#ifdef CONFIG_RTL865XB
	else if ( ( (uint32)startaddr >= REAL_BD01_BASE ) && ( (uint32)startaddr <= REAL_BD01_BASE+BD01_SIZE ) )
	{
		startaddr = (uint32*)(((uint32)startaddr)-REAL_BD01_BASE+BD01_BASE);
	}
#else /*CONFIG_RTL865XC*/
	else if ( ( (uint32)startaddr >= REAL_SYSTEM_BASE ) && ( (uint32)startaddr <= REAL_SYSTEM_BASE+SYSTEM_SIZE ) )
	{
		startaddr = (uint32*)(((uint32)startaddr)-REAL_SYSTEM_BASE+SYSTEM_BASE);
	}
#endif
	else if ( ( (uint32)startaddr >= REAL_HSB_BASE ) && ( (uint32)startaddr <= REAL_HSB_BASE+HSB_SIZE ) )
	{
		startaddr = (uint32*)(((uint32)startaddr)-REAL_HSB_BASE+HSB_BASE);
	}
	else if ( ( (uint32)startaddr >= REAL_HSA_BASE ) && ( (uint32)startaddr <= REAL_HSA_BASE+HSA_SIZE ) )
	{
		startaddr = (uint32*)(((uint32)startaddr)-REAL_HSA_BASE+HSA_BASE);
	}
#endif

	memDump(startaddr, len, "Result");
	return SUCCESS;
}

#ifdef CONFIG_RTL8185

bdinfo_t currentBdInfo;
char eepromData[256];
#define RTL8185_EEPROM_CHIPID_OFFSET			0
#define RTL8185_EEPROM_CHIPID_LEN				1
#define RTL8185_EEPROM_MAC_OFFSET			1
#define RTL8185_EEPROM_MAC_LEN				6
#define RTL8185_EEPROM_CCKPOWER_OFFSET		7
#define RTL8185_EEPROM_CCKPOWER_LEN			14
#define RTL8185_EEPROM_OFDMPOWER_OFFSET	21
#define RTL8185_EEPROM_OFDMPOWER_LEN		162
#define RTL8185_EEPROM_TOTAL					183

/* RF Chip */
#define RTL8185_RFCHIP_OMC8255		0x0a
#define RTL8185_RFCHIP_ZEBRA8225		0x09

static int32 _rtl8651_8185flashCfgCmd(uint32 userId,  int32 argc,int8 **saved){
	int8 *nextToken;
	int32 size, i;
	uint32 value;
	uint32 cardIndex;
	int chIndex;
	uint16 RFChipID = 0;
	struct net_device *dev;
	int eepromReadbytes = 0;
	uint8 eepromExist;
	char tmpbuf[32];

	cle_getNextCmdToken(&nextToken,&size,saved); 
	cardIndex = U32_value(nextToken);
	cle_getNextCmdToken(&nextToken,&size,saved);

	sprintf(tmpbuf, "wlan%d", cardIndex);
	dev=__dev_get_by_name(tmpbuf);

	if (dev == NULL)
	{
		printk("@ Unknown interface: wlan%d\n", cardIndex);
		return FAILED;
	}

	if (cardIndex > 2)
	{
		printk("@ Unknown wlan Index : %d\n", cardIndex);
		return FAILED;
	}

	/* ========================================================================
			Get EEPROM / BDInfo
	    ======================================================================== */

	/* get information from EEPROM */
	eepromExist = TRUE;
	memset(eepromData, 0xff, sizeof(eepromData));
	eepromReadbytes = get_eeprom_info(dev->priv, eepromData);

	/* check result */
	for ( i = 0 ; i < sizeof(eepromData); i ++ )
	{
		if (eepromData[i] != (char)(0xff))
		{
			break;
		}
	}
	if ( i == sizeof(eepromData) )
	{	/* whole eepromData are the initial value --> EEPROM access fail ! */
		printk("@ EEPROM access failed!\n");
		eepromExist = FALSE;
	}

	/* dump EEPROM infomation */
	#if 0
	if ( eepromReadbytes == RTL8185_EEPROM_TOTAL )
	{
		printk("*========================== EEPROM info ==========================*\n");
		memDump(&eepromData[RTL8185_EEPROM_CHIPID_OFFSET], RTL8185_EEPROM_CHIPID_LEN, "RFChipID");
		memDump(&eepromData[RTL8185_EEPROM_MAC_OFFSET], RTL8185_EEPROM_MAC_LEN, "MAC");
		memDump(&eepromData[RTL8185_EEPROM_CCKPOWER_OFFSET], RTL8185_EEPROM_CCKPOWER_LEN, "CCK TxPower");
		memDump(&eepromData[RTL8185_EEPROM_OFDMPOWER_OFFSET], RTL8185_EEPROM_OFDMPOWER_LEN, "OFDM TxPower");
		printk("*=============================================================*\n");
	}
	#endif

	/* get information from BDINFO */
	memset(&currentBdInfo, 0xff, sizeof(bdinfo_t));
	flashdrv_read((void *)&currentBdInfo, (void *)flashdrv_getBoardInfoAddr(), sizeof(bdinfo_t));

	/* check result */
	{
		bdinfo_t invalid;
		memset(&invalid, 0xff, sizeof(bdinfo_t));
		if (memcmp(&invalid, &currentBdInfo, sizeof(bdinfo_t)) == 0)
		{
			printk("@ FATAL: BoradInfo access failed!\n");
			return FAILED;
		}
	}

	/* ========================================================================
			Get Chip Version and ID
				1. From WLAN's EEPROM
				2. If (1) is failed, from bdInfo
	    ======================================================================== */

	if (eepromExist == TRUE)
	{
		RFChipID = (eepromData[0] & 0x000f);
	} else
	{
		RFChipID = (currentBdInfo.wlan[cardIndex].RFChipID);
	}

	printk("@ Interface: wlan%d\n", cardIndex);

	printk("@ RF ChipID: %d ", RFChipID);

	switch (RFChipID)
	{
		case RTL8185_RFCHIP_ZEBRA8225:
			printk("[Zebra - RTL8225]\n");
			break;
		case RTL8185_RFCHIP_OMC8255:
			printk("[OMC - RTL8255]\n");
			break;
		default:
			printk("[Unknown RF chip]\n");
	}

	printk("@ -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");

	/* ========================================================================
	     ********************************************************************************************

		Set factory default:

			Read configuration from EEPROM/code and store it to flash.

	    *********************************************************************************************
	    ======================================================================== */
	if(!strcmp(nextToken, "default"))
	{
		#define RTL8185_DEFAULTFROMUSER_ENABLE	/* default value use per-defined setting instead of information from EEPROM */

		#define RTL8185_DEFAULT_FROM_EEPROM		0x01
		#define RTL8185_DEFAULT_FROM_USER		0x02

		uint8 rtl8185_defaultValueSource = RTL8185_DEFAULT_FROM_EEPROM;
		uint8 updateBDInfo = FALSE;
		bdinfo_wlan_t def;

		/*=====================================================================
				TxPower Management
		   =====================================================================*/
		typedef enum{
			minTxPower = 0,
			maxTxPower,
			TxPowerRange,
		} _minMax;

		typedef enum{
			_24Gcck = 0,
			_24Gofdm,
			_5Gofdm,
			AllSpectrumNum,
		} _Spectrum;

		uint8 updateTxPower[AllSpectrumNum];	/* for TxPower update check */
		uint8 txPower[AllSpectrumNum];
		uint8 oldTxPower[AllSpectrumNum];

		#define INIT_TXPOWER(RF_ID)\
			do { \
				memset(updateTxPower, 0, sizeof(updateTxPower));\
				memset(oldTxPower, 0xff, sizeof(oldTxPower));\
				switch (RF_ID)\
				{\
					case RTL8185_RFCHIP_OMC8255:\
						memcpy(txPower, omc8255TxPowerDefault, sizeof(txPower));\
						break;\
					case RTL8185_RFCHIP_ZEBRA8225:\
						memcpy(txPower, zebra8225TxPowerDefault, sizeof(txPower));\
						break;\
				}\
			} while (0);

		#define UPDATE_TXPOWER(newTxPower, Spectrum) \
			do {	\
				if (oldTxPower[Spectrum] != 0xff)\
				{\
					updateTxPower[Spectrum] = TRUE; \
				}\
				oldTxPower[Spectrum] = txPower[Spectrum]; \
				txPower[Spectrum] = (newTxPower); \
			} while (0);

		#define TXPOWER(Spectrum) (txPower[(Spectrum)])
		#define OLD_TXPOWER(Spectrum) (oldTxPower[(Spectrum)])
		#define TXPOWER_IS_UPDATED(Spectrum) (updateTxPower[Spectrum]==TRUE)

		/* default TxPower */
		/*==================================================================*/
		/* 8225 */
		const uint8 zebra8225TxPowerDefault[AllSpectrumNum] =
		{
			0x0c,			/* 2.4G CCK		*/
			0x12,			/* 2.4G OFDM		*/
		};
		/* 8255 */
		const uint8 omc8255TxPowerDefault[AllSpectrumNum] =
		{
			0x0f,			/* 2.4G CCK		*/
			0x12,			/* 2.4G OFDM		*/
			0x12,			/* 5G OFDM		*/
		};
		/*==================================================================*/


		/* Valid TxPower Range */
		/*==================================================================*/
		/* 8225 */
		const uint8 zebra8225TxPowerRange[AllSpectrumNum][TxPowerRange] =
		{/*	MIN		MAX		*/
			{0x03,	0x2f},	/* 2.4G CCK		*/
			{0x03,	0x2f},	/* 2.4G OFDM		*/
			{0,		0}		/* 5G OFDM		*/			
		};

		/* 8255 */
		const uint8 omc8255TxPowerRange[AllSpectrumNum][TxPowerRange] =
		{/*	MIN		MAX		*/
			{0x03,	0x2f},	/* 2.4G CCK		*/
			{0x03,	0x2f},	/* 2.4G OFDM		*/
			{0x03,	0x2f}	/* 5G OFDM		*/
		};

		#define UPDATE_INVALID_TXPOWER(RF_ID, Spectrum) \
			do {\
				uint8 __minTxPower = 0;\
				uint8 __maxTxPower = 0xff;\
				uint8 __defaultTxPower = 0;\
				switch(RF_ID)\
				{\
					case RTL8185_RFCHIP_OMC8255:\
						__minTxPower = omc8255TxPowerRange[Spectrum][minTxPower];\
						__maxTxPower = omc8255TxPowerRange[Spectrum][maxTxPower];\
						__defaultTxPower = omc8255TxPowerDefault[Spectrum];\
						break;\
					case RTL8185_RFCHIP_ZEBRA8225:\
						__minTxPower = zebra8225TxPowerRange[Spectrum][minTxPower];\
						__maxTxPower = zebra8225TxPowerRange[Spectrum][maxTxPower];\
						__defaultTxPower = zebra8225TxPowerDefault[Spectrum];\
						break;\
				}\
				if (txPower[Spectrum]>__maxTxPower || txPower[Spectrum]<__minTxPower)\
				{\
					if (oldTxPower[Spectrum] != 0xff)\
					{\
						updateTxPower[Spectrum] = TRUE; \
					}\
					oldTxPower[Spectrum] = txPower[Spectrum]; \
					txPower[Spectrum] = __defaultTxPower; \
				}\
			}while(0);

		/*==================================================================*/

		memset(&def, 0, sizeof(bdinfo_wlan_t));

		/*
			check default source
		*/
		#ifdef RTL8185_DEFAULTFROMUSER_ENABLE
		nextToken = NULL;
		cle_getNextCmdToken(&nextToken, &size, saved);
		if ((nextToken == NULL) || (!strcmp(nextToken, "eeprom")))
		#endif	/* RTL8185_DEFAULTFROMUSER_ENABLE */
		{
			if ((eepromExist==TRUE) && (eepromReadbytes==RTL8185_EEPROM_TOTAL))
			{
				rtl8185_defaultValueSource = RTL8185_DEFAULT_FROM_EEPROM;
			} else
			{
				printk("@ EEPROM load fail, get default value from per-defined hard code\n");
				rtl8185_defaultValueSource = RTL8185_DEFAULT_FROM_USER;
			}
		}
		#ifdef RTL8185_DEFAULTFROMUSER_ENABLE
		else if (!strcmp(nextToken, "user"))
		{
			rtl8185_defaultValueSource = RTL8185_DEFAULT_FROM_USER;
		}
		#endif	/* RTL8185_DEFAULTFROMUSER_ENABLE */

		/*
			verify default source
		*/
		switch (rtl8185_defaultValueSource)
		{
			case RTL8185_DEFAULT_FROM_EEPROM:
			{
				printk("@ Load default cfg from EEPROM\n");
				break;
			}
			case RTL8185_DEFAULT_FROM_USER:
			{
				printk("@ Load default cfg from code default\n");
				break;
			}
			default:
				printk("[FATAL] (%s:%d) Error default value source.\n", __FUNCTION__, __LINE__);
				return 0;
		}

		/* ==================================================================
			Update Information
		    ==================================================================*/

		switch (RFChipID)
		{
			/*
				Zebra - b/g
			*/
			case RTL8185_RFCHIP_ZEBRA8225:
			{
				int32 i;
				uint8 defMac[6]={0,0xe0,0x4c,0,0x81,0x85};
				bdinfo_wlan_t def_8225 = {
					type: 0x81,
					version: 0x85,
					RFChipID: RTL8185_RFCHIP_ZEBRA8225,
					len: sizeof(bdinfo_wlan_t),
					rxChargePump:3,
					txChargePump:6,
				};

				memcpy(&def, &def_8225, sizeof(bdinfo_wlan_t));

				/*==================================
						Set RF Chip ID
				   ==================================*/
				if (RFChipID != def_8225.RFChipID)
				{
					updateBDInfo = TRUE;
				}

				/*==================================
						Set MAC Addr
				   ==================================*/
				switch (rtl8185_defaultValueSource)
				{
					case RTL8185_DEFAULT_FROM_EEPROM:
					{
						memcpy(def.mac, &eepromData[RTL8185_EEPROM_MAC_OFFSET], 6);
						break;
					}
					case RTL8185_DEFAULT_FROM_USER:
					{
						memcpy(def.mac, defMac, 6);
						def.mac[3]=cardIndex;
						break;
					}
				}

				printk("@ Set %s default MAC as ", tmpbuf);

				for(i=0;i<6;i++)
				{
					printk("%02x",(unsigned char)def.mac[i]);
					if (i<5)
					{
						printk(":");
					}
				}
				printk("\n");

				/*==================================
						Set 2.4G TxPower

						- OFDM
						- CCK
				   ==================================*/

				printk("====================== 2.4G ======================\n");
				for(i=0;i< BDINFO_24GRF_CHANNELS;i++)
				{
					INIT_TXPOWER(RFChipID);	/* we MUST re-init database before processing each entry */
					/* 802.11g */
					switch (rtl8185_defaultValueSource)
					{
						case RTL8185_DEFAULT_FROM_EEPROM:
						{
							/* CCK */
							UPDATE_TXPOWER(
								eepromData[RTL8185_EEPROM_CCKPOWER_OFFSET+i],
								_24Gcck
							);
							/*
								check the correctness of the information gotten from EEPROM,
								if it is invalid, we set the from user.
							*/
							UPDATE_INVALID_TXPOWER(RFChipID, _24Gcck);

							/* OFDM */
							UPDATE_TXPOWER(
								eepromData[RTL8185_EEPROM_OFDMPOWER_OFFSET+i],
								_24Gofdm
							);
							/*
								check the correctness of the information gotten from EEPROM,
								if it is invalid, we set the from user.
							*/
							UPDATE_INVALID_TXPOWER(RFChipID, _24Gofdm);
							break;
						}
						case RTL8185_DEFAULT_FROM_USER:
						{
							INIT_TXPOWER(RFChipID);		/* this macro would init TxPower according to RFChipID */
							break;
						}
					}

					def.txPower[i][0]=TXPOWER(_24Gofdm); /* strongest */
					def.txPower[i][1]=TXPOWER(_24Gofdm)-1;
					def.txPower[i][2]=TXPOWER(_24Gofdm)-2;
					def.txPower[i][3]=TXPOWER(_24Gofdm)-3;
					def.cckTxPower[i][0]=TXPOWER(_24Gcck); /* strongest */
					def.cckTxPower[i][1]=TXPOWER(_24Gcck);
					def.cckTxPower[i][2]=TXPOWER(_24Gcck)-1;
					def.cckTxPower[i][3]=TXPOWER(_24Gcck)-2;
					printk("[%d] 2.4G Ch %d: OFDM %d,%d,%d,%d%s  CCK %d,%d,%d,%d%s\n",
						i,	/* index */
						i+1,
						def.txPower[i][0],def.txPower[i][1],def.txPower[i][2],def.txPower[i][3],
						(TXPOWER_IS_UPDATED(_24Gofdm)?"*":""),
						def.cckTxPower[i][0],def.cckTxPower[i][1],def.cckTxPower[i][2],def.cckTxPower[i][3],
						(TXPOWER_IS_UPDATED(_24Gcck)?"*":"")
					);
				}
				printk("\n");

				updateBDInfo = TRUE;
				break;
			}

			/*
				OMC, have a or b/g
			*/
			case RTL8185_RFCHIP_OMC8255:
			{
				int32 i,j;
				uint8 defMac[6]={0,0xe0,0x4c,0,0x81,0x85};
				
				bdinfo_wlan_t def_8255 = {
					type: 0x81,
					version: 0x85,
					RFChipID: RTL8185_RFCHIP_OMC8255,
					len: sizeof(bdinfo_wlan_t),
				};

				memcpy(&def, &def_8255, sizeof(bdinfo_wlan_t));

				/*==================================
						Set RF Chip ID
				   ==================================*/
				if (RFChipID != def_8255.RFChipID)
				{
					updateBDInfo = TRUE;
				}

				/*==================================
						Set MAC Addr
				   ==================================*/
				switch (rtl8185_defaultValueSource)
				{
					case RTL8185_DEFAULT_FROM_EEPROM:
					{
						memcpy(def.mac, &eepromData[RTL8185_EEPROM_MAC_OFFSET], 6);
						break;
					}
					case RTL8185_DEFAULT_FROM_USER:
					{
						memcpy(def.mac, defMac, 6);
						def.mac[3]=cardIndex;
						break;
					}
				}

				printk("@ Set %s default MAC as ", tmpbuf);

				for(i=0;i<6;i++)
				{
					printk("%02x",(unsigned char)def.mac[i]);
					if (i<5)
					{
						printk(":");
					}
				}
				printk("\n");

				/*==================================
						Set 2.4G TxPower

						- OFDM
						- CCK
				   ==================================*/
				/*
					For 802.11 b/g 2.4G spectrum
				*/
				printk("====================== 2.4G ======================\n");
				for(i=0;i< BDINFO_24GRF_CHANNELS;i++)
				{
					INIT_TXPOWER(RFChipID);	/* we MUST re-init database before processing each entry */
					/* 802.11g */
					switch (rtl8185_defaultValueSource)
					{
						case RTL8185_DEFAULT_FROM_EEPROM:
						{
							/* CCK */
							UPDATE_TXPOWER(
								eepromData[RTL8185_EEPROM_CCKPOWER_OFFSET+i],
								_24Gcck
							);
							/*
								check the correctness of the information gotten from EEPROM,
								if it is invalid, we set the from user.
							*/
							UPDATE_INVALID_TXPOWER(RFChipID, _24Gcck);

							/* OFDM */
							UPDATE_TXPOWER(
								eepromData[RTL8185_EEPROM_OFDMPOWER_OFFSET+i],
								_24Gofdm
							);
							/*
								check the correctness of the information gotten from EEPROM,
								if it is invalid, we set the from user.
							*/
							UPDATE_INVALID_TXPOWER(RFChipID, _24Gofdm);
							break;
						}
						case RTL8185_DEFAULT_FROM_USER:
						{
							INIT_TXPOWER(RFChipID);		/* this macro would init TxPower according to RFChipID */
							break;
						}
					}

					def.txPower[i][0]=TXPOWER(_24Gofdm); /* strongest */
					def.txPower[i][1]=TXPOWER(_24Gofdm)+1;
					def.txPower[i][2]=TXPOWER(_24Gofdm)+2;
					def.txPower[i][3]=TXPOWER(_24Gofdm)+3;
					def.cckTxPower[i][0]=TXPOWER(_24Gcck); /* strongest */
					def.cckTxPower[i][1]=TXPOWER(_24Gcck);
					def.cckTxPower[i][2]=TXPOWER(_24Gcck)-1;
					def.cckTxPower[i][3]=TXPOWER(_24Gcck)-2;
					printk("[%d] 2.4G Ch %d: OFDM %d,%d,%d,%d%s  CCK %d,%d,%d,%d%s\n",
						i,	/* index */
						i+1,
						def.txPower[i][0],def.txPower[i][1],def.txPower[i][2],def.txPower[i][3],
						(TXPOWER_IS_UPDATED(_24Gofdm)?"*":""),
						def.cckTxPower[i][0],def.cckTxPower[i][1],def.cckTxPower[i][2],def.cckTxPower[i][3],
						(TXPOWER_IS_UPDATED(_24Gcck)?"*":"")
					);
				}
				printk("\n");

				/*==================================
						Set 5G TxPower

						- OFDM
				   ==================================*/
				/*
					For 802.11a 5G spectrum
				*/
				printk("======================  5G  ======================\n");

				for(i=BDINFO_24GRF_CHANNELS, j=0;i< BDINFO_24GRF_CHANNELS+BDINFO_5GRF_CHANNELS;i++,j++)
				{
					int ch = 36;

					INIT_TXPOWER(RFChipID);	/* we MUST re-init database before processing each entry */

					ch = 36 + (j * 4);
					switch (rtl8185_defaultValueSource)
					{
						case RTL8185_DEFAULT_FROM_EEPROM:
						{
							/* OFDM */
							UPDATE_TXPOWER(
								eepromData[RTL8185_EEPROM_OFDMPOWER_OFFSET+ch-1],
								_5Gofdm
							);
							/*
								check the correctness of the information gotten from EEPROM,
								if it is invalid, we set the from user.
							*/
							UPDATE_INVALID_TXPOWER(RFChipID, _5Gofdm);
							break;
						}
						case RTL8185_DEFAULT_FROM_USER:
						{
							/*
								chenyl (2005/05/14):
									Jimmy said that when TxPower of 11a OFDM is 0x12,
									the TX performance will be stable and good.
									So I would apply this value in our platform's minimum range's setting (It's the default).
							*/
							INIT_TXPOWER(RFChipID);		/* this macro would init TxPower according to RFChipID */
							break;
						}
					}

					/* set TxPower level */
					def.txPower[i][0]=TXPOWER(_5Gofdm);		/* strongest */
					def.txPower[i][1]=TXPOWER(_5Gofdm)+1;
					def.txPower[i][2]=TXPOWER(_5Gofdm)+2;
					def.txPower[i][3]=TXPOWER(_5Gofdm)+3;

					/* 5G spectrum has no CCK */

					printk("[%d] 5G Ch %d: OFDM %d,%d,%d,%d%s\n",
						i, /* index */
						ch,
						def.txPower[i][0],def.txPower[i][1],def.txPower[i][2],def.txPower[i][3],
						(TXPOWER_IS_UPDATED(_5Gofdm)?"*":"")
					);
				}
				printk("\n");
				updateBDInfo = TRUE;
				break;
			}

			default:
				printk("@ ==> Unknown chip ID, no any default value found.\n");
				updateBDInfo = FALSE;
				break;
		}

		/*
			Update BDInfo if necessary.
		*/
		if (updateBDInfo == TRUE)
		{
			printk("@ Update board info ... ");
			memcpy(&currentBdInfo.wlan[cardIndex], &def, sizeof(bdinfo_wlan_t));
			/* memcpy(&currentBdInfo.wlan[cardIndex].mac[0], &currentBdInfo.mac[0], 6); */
			flashdrv_updateBdInfo(&currentBdInfo);
			printk("DONE!\n\n");
		}
		
	}else if(!strcmp(nextToken, "get")) {
	/* ========================================================================
	     ********************************************************************************************

		Get Flash info:

			Dump flash information from BDINFO.

	    *********************************************************************************************
	    ======================================================================== */
		printk("MAC: %x:%x:%x:%x:%x:%x, ",currentBdInfo.mac[0],currentBdInfo.mac[1],currentBdInfo.mac[2],currentBdInfo.mac[3],currentBdInfo.mac[4],currentBdInfo.mac[5]);
		printk("RAM:%08x, ",  currentBdInfo.ramStartAddress);
		printk("Root:%08x\n",  currentBdInfo.rootStartOffset);
		memDump(&currentBdInfo, sizeof(bdinfo_t),"Raw data");
	} else {
	/* ========================================================================
	     ********************************************************************************************

		Write Configuration to BDINFO

	    *********************************************************************************************
	    ======================================================================== */
		do {
			if (strcmp(nextToken, "rfchip") == 0) {
				cle_getNextCmdToken(&nextToken, &size, saved);
				value = U8_value(nextToken);
				currentBdInfo.wlan[cardIndex].RFChipID = value;
			} else if (strcmp(nextToken, "mac") ==0 ) {
				cle_getNextCmdToken(&nextToken,&size,saved); 
				  *((ether_addr_t *)currentBdInfo.wlan[cardIndex].mac) = *((ether_addr_t *)nextToken);
			}else if (strcmp(nextToken, "rxcp")==0) {
				cle_getNextCmdToken(&nextToken,&size,saved); 
				value = U32_value(nextToken);
				currentBdInfo.wlan[cardIndex].rxChargePump = value;
			}else if (strcmp(nextToken, "txcp") ==0 ) {
				cle_getNextCmdToken(&nextToken,&size,saved); 
				value = U32_value(nextToken);
				currentBdInfo.wlan[cardIndex].rxChargePump = value;
			}else{
				int32 isOfdm=1;
				if (strcmp(nextToken, "cck") ==0 ||strcmp(nextToken, "B") ==0){
					isOfdm=0;
					chIndex=0;
				}else if (strcmp(nextToken, "A") ==0) {
					chIndex=14;
				}else if(strcmp(nextToken, "G") ==0){
					chIndex=0;
				}else{ 
					chIndex=0; //default is 11b/g
					isOfdm=0;
				}
				cle_getNextCmdToken(&nextToken,&size,saved); 
				value = U32_value(nextToken);
				if(isOfdm && value>=36)
					chIndex+=(value-36)/4;
				else
					chIndex=value-1;
				for(i=0;i<4;i++){
					cle_getNextCmdToken(&nextToken,&size,saved); 
					if(isOfdm==0)
						currentBdInfo.wlan[cardIndex].cckTxPower[chIndex][i] = U32_value(nextToken);
					else
					currentBdInfo.wlan[cardIndex].txPower[chIndex][i] = U32_value(nextToken);
				}
			}
		}while(cle_getNextCmdToken(&nextToken,&size,saved) !=FAILED);
		flashdrv_updateBdInfo(&currentBdInfo);
	}
	printk("@ -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
	return SUCCESS;
}
#endif


static uint32 irq_saved;
static uint32 flags;

inline void IRQ_DISABLE(void)
{
    irq_saved = (*((volatile uint32 *)(0xBD012000)));
    printk("IRQ saved: %u\n", irq_saved);

    (*((volatile uint32 *)(0xBD012000))) = 0;

    flags = read_c0_status();
    printk("Status saved: %u\n", flags);

    write_c0_status(flags&(~0xFF01));
}


inline void IRQ_ENABLE(void)
{
    (*((volatile uint32 *)(0xBD012000))) = irq_saved;

    write_c0_status(flags);
}


#ifdef CONFIG_RTL865X_BENCHMARK

static int32 _benchmarking(uint32 userId,  int32 argc,int8 **saved)
{
	int8 *nextToken;
	int32 size, round;
	
	cle_getNextCmdToken(&nextToken,&size,saved);
	if(strcmp(nextToken, "dhry21") == 0) {
		cle_getNextCmdToken(&nextToken,&size,saved);
		round = U32_value(nextToken);
		dhrystone21(round);
	}else if(strcmp(nextToken, "dhry11") == 0) {
		cle_getNextCmdToken(&nextToken,&size,saved);
		round = U32_value(nextToken); 
		dhrystone11(round);
	}else if(strcmp(nextToken, "fib") == 0) {
		fibBenchmark();
	}else if(strcmp(nextToken, "hanoi") == 0) {
		hanoiBenchmark();
	}else if(strcmp(nextToken, "heapsort") == 0) {
		heapsortBenchmark();
	}else if(strcmp(nextToken, "bogomips") == 0) {
		bogoMips();
	}
	
	return SUCCESS;
}

#endif


static cle_exec_t _initCmdList[] = {
#ifdef CONFIG_RTL8185
	{	"8185",
		"rtl8185 MP flash read/write command",
		" %d'WLAN card index' "
		"{ default'Set default RF cfg to flash' { [ user'default value from pre-defined setting'  ] [ eeprom'default value from eeprom' ] } | "
		"get'Get card config from flash' | "
		"{ [ mac'Write MAC to flash' %mac'MAC address in XX:XX:XX:XX:XX:XX format' ] "
		"[ rfchip'Write RF Chip ID to flash' %d'9 for Zebra8225, 10 for OMC8255' ] "
		"[ rxcp'Write Rx charge pump cfg to flash' %d'0~7 for 200mA~550mA' ] [ txcp'Write Tx charge pump cfg to flash' %d'0~7 for 200~550mA' ] "
		"[ { A'Select 802.11a band...' %d'select channel (36~64)...' | B'Select 802.11b band...' %d'select channel (1~14)' | G'Select 802.11g band...' %d'select channel (1~14)' | cck %d'select channel (1~14)'  } %d'tx pwr(Max)' %d'tx pwr(2)' %d'tx pwr(3)' %d'tx pwr(min)' ] } }",
		_rtl8651_8185flashCfgCmd,
		CLE_USECISCOCMDPARSER,	
		0,
		NULL
	},
#endif
	
#ifdef CONFIG_RTL865X_MULTILAYER_BSP
	{	"debug",
		"Display debug info",
		"{ on | off  | %d'Debug level' }",
		_rtl8651_debugCmd,
		CLE_USECISCOCMDPARSER,	
		0,
		NULL
	},
	{	"reset",
		"Reset to code default. Flush all tables & settings.",
		"",
		_rtl8651_resetCmd,
		CLE_USECISCOCMDPARSER,	
		0,
		NULL
	},	
#endif

	{	"memory",
		"read/write memory",
		"{ read'read memory from specified base address' %d'base address' %d'Length' | write'write memory from specified base address' %d'base address' %d'4 byte value' } ",
		_rtl8651_memdump,
		CLE_USECISCOCMDPARSER,	
		0,
		NULL
	},	
#ifdef CONFIG_RTL865XB_EXP_CRYPTOENGINE	
	{	"dmacpy",
		"Memcpy test",
		" { init | { [ emulate ] %d'Pktlen' %d'# of bytes copy by crypto engine' [ poll %d ] %d'iteration' } }",
		cmdCrymemcpy,
		CLE_USECISCOCMDPARSER,
		0,
		NULL
	},	
#endif
	{	"pci",
		"read/write io address",
		"{ read'read memory from specified base address' %d'base address' %d '1:byte,2:word,4:dword' | write'write memory from specified base address' %d'base address' %d'value' %d' 1:byte,2:word,4:dword' } ",
		cmdPci,
		CLE_USECISCOCMDPARSER,	
		0,
		NULL
	},		
#ifdef CONFIG_RTL865XB_EXP_PERFORMANCE_EVALUATION
	{	"permemcpy",
		"Memcpy performance test",
		"[ cached ] { COP3I | COP3D } %d'Pktlen' %d'iteration'",
		_rtl8651_permemcpyCmd,
		CLE_USECISCOCMDPARSER,
		0,
		NULL
	},	
	{	"pernicrx",
		"NIC Rx performance test (drop and count)",
		"{ inst | data } %d'Pkt number to test'",
		_rtl8651_pernicrxCmd,
		CLE_USECISCOCMDPARSER,
		0,
		NULL
	},	
	{	"perpcitx",
		"PCI Tx performance test (capture one packet to PCI and send it out repeatedly)",
		"{ { inst | data } %d'Pkt number to test' | start }",
		_rtl8651_perpcitxCmd,
		CLE_USECISCOCMDPARSER,
		0,
		NULL
	},	
	{	"cop3",
		"Coprocessor 3 counters",
		"{ inst | data | end }",
		_rtl8651_startCOP3Counters,
		CLE_USECISCOCMDPARSER,
		0,
		NULL
	},	
#endif

#ifdef CONFIG_RTL865X_BENCHMARK
	{	"benchmark",
		"Running benchmarking tools",
		" { dhry21 %d'Dhrystone 2.1 repeat rounds' | dhry11 %d'Dhrystone 1.1 repeat rounds' | fib | hanoi | heapsort | bogomips } ",
		_benchmarking,
		CLE_USECISCOCMDPARSER,
		0,
		NULL
	},	
#endif

};


static cle_grp_t _initCmdGrpList[] = {
#ifdef CONFIG_RTL865X_MULTILAYER_BSP	
	{
		"drv",							//cmdStr
		"Config RTL8651 high level driver",			//cmdDesc
		NULL,							//cmdPrompt
		rtl8651_tblDrv_cmds,	    			//exec array
		NULL,		        				//group array
		CMD_RTL8651_TBLDRV_CMD_NUM,		//exec number
		0,		            					//group number
		0,		            					//access level
	},
	{
		"fwd",			    			//cmdStr
		"Config RTL8651 forwarding engine",	//cmdDesc
		NULL,							//cmdPrompt
		rtl8651_tblDrvFwd_cmds,		    	//exec array
		NULL,		        				//group array
		CMD_RTL8651_TBLDRVFWD_CMD_NUM,		//exec number
		0,		            					//group number
		0,		            					//access level
	},
	{
		"asic",			    				//cmdStr
		"Config RTL8651 ASIC driver",			//cmdDesc
		NULL,							//cmdPrompt
		rtl8651_tblAsicDrv_cmds,	   			 //exec array
		NULL,		        				//group array
		CMD_RTL8651_TBLASICDRV_CMD_NUM,		//exec number
		0,		            					//group number
		0,		            					//access level
	},
	{
		"nic",			    				//cmdStr
		"RTL8651 NIC config & status",			//cmdDesc
		NULL,							//cmdPrompt
		swNic_cmds,	   			 //exec array
		NULL,		        				//group array
		CMD_RTL8651_SWNIC_CMD_NUM,		//exec number
		0,		            					//group number
		0,		            					//access level
	},	
#endif /*CONFIG_RTL865X_MULTILAYER_BSP*/
#ifdef CONFIG_RTL865x_SWPUBKEY
	{
		"pubkey",			    				//cmdStr
		"Using rtl865x software public key driver",			//cmdDesc
		NULL,							//cmdPrompt
		rtl865x_pubkey_cmds,	   			 //exec array
		NULL,		        				//group array
		CMD_RTL865x_PUBKEY_CMD_NUM,		//exec number
		0,		            					//group number
		0,		            					//access level
	},
#endif
#ifdef CONFIG_RTL865XB_EXP_CRYPTOENGINE
	{
		"crypto",			    				//cmdStr
		"Using rtl865xB hardware cryptography engine",			//cmdDesc
		NULL,							//cmdPrompt
		rtl865x_crypt_cmds,	   			 //exec array
		NULL,		        				//group array
		CMD_RTL865XB_CRYPT_CMD_NUM,		//exec number
		0,		            					//group number
		0,		            					//access level
	},
#endif
#ifdef CONFIG_RTL8305S
	{
		"8305s",			    				//cmdStr
		"Control the MII/GPIO controlled 8305SB/8305SB",			//cmdDesc
		NULL,							//cmdPrompt
		rtl8305s_cmds,	   			 //exec array
		NULL,		        				//group array
		CMD_RTL8305S_CMD_NUM,		//exec number
		0,		            					//group number
		0,		            					//access level
	},
#endif
#ifdef CONFIG_RTL865XB_EXP_VOIP
	{
		"voip",			    				//cmdStr
		"VoIP functions",					//cmdDesc
		NULL,								//cmdPrompt
		voip_cmds,	  			 			//exec array
		_voipCmdGrpList,       				//group array
		CMD_VOIP_CMD_NUM,					//exec number
		CMD_VOIP_GRP_NUM,					//group number
		0,		            				//access level
	},	
#endif
#if defined(RTL865X_MODEL_USER)||defined(RTL865X_MODEL_KERNEL)
	{
		"model",			    			//cmdStr
		"Run model test code",				//cmdDesc
		NULL,								//cmdPrompt
		model_cmds,	  			 			//exec array
		model_cmdGrpList,      				//group array
		CMD_MODEL_CMD_NUM,					//exec number
		CMD_MODEL_GRP_NUM,					//group number
		0,		            				//access level
	},	
#endif
#if defined(CONFIG_SMI)
	{
		"smi",
		"Command through SMI Interface",
		NULL,
		smi_cmds,
		NULL,
		CMD_SMI_CMD_NUM,				
		0,					
		0,		            
	},
#endif

	/* more ...... */
};


cle_grp_t cle_newCmdRoot[] = {
	{
		"rtl8651",								//cmdStr
		"RTL8651 command line interface",	//cmdDesc
		"rtl8651",								//cmdPrompt
		_initCmdList,					//List of commands in this layer
		_initCmdGrpList,						//List of child command groups
		sizeof(_initCmdList)/sizeof(cle_exec_t),		//Number of commands in this layer
		sizeof(_initCmdGrpList)/sizeof(cle_grp_t),	//Number of child command groups
		0,									//access level
	}
	/* more ...... */
};

#if defined(CONFIG_RTL8185)||defined(CONFIG_RTL8185_MODULE)
//glue function for 8185 iwpriv ioctl to call our own CLE engine.
void rtl8651_8185flashCfg(int8 *cmd, uint32 cmdLen){
	int i, ret,total=sizeof(_initCmdList)/sizeof(cle_exec_t);
	cle_exec_t *CmdFmt=NULL;
	for(i=0;i<total;i++){
		if(strcmp(_initCmdList[i].cmdStr, "8185")==0){
			CmdFmt=&_initCmdList[i];
			break;
		}
	}
	ret=cle_cmdParser(cmd, CmdFmt,"/,= ");
	if(ret<1)
		printk("Cmd failed, ret=%d\n", ret);
}
EXPORT_SYMBOL(rtl8651_8185flashCfg);
#endif

