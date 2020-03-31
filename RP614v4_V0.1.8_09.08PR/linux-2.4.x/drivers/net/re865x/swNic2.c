/*
* ----------------------------------------------------------------
* Copyright c                  Realtek Semiconductor Corporation, 2002  
* All rights reserved.
* 
* $Header: /home/cvsroot/uClinux-dist/linux-2.4.x/drivers/net/re865x/swNic2.c,v 1.84 2005/11/29 03:11:51 yjlou Exp $
*
* Abstract: Switch core NIC driver source code version 2.
*
* $Author: yjlou $
*
* $Log: swNic2.c,v $
* Revision 1.84  2005/11/29 03:11:51  yjlou
* *: fixed for L2 BSP compile error.
*
* Revision 1.83  2005/09/26 13:47:31  yjlou
* *: fixed for enabling switch core and onchip NIC.
*
* Revision 1.82  2005/09/16 11:34:48  tony
* *: bug fixed: support kernel space swNic model code for RTL865XC.
*
* Revision 1.81  2005/09/15 07:30:14  yjlou
* *: fixed error compile for kernel-space model code (due to new ASIC register definition).
*
* Revision 1.80  2005/09/14 12:31:39  tony
* *: bug fixed: swNic_isrReclaim recycle by descriptRing not QueueID.
*
* Revision 1.79  2005/09/13 08:22:55  tony
* *: update swNic_rxRunoutTxPending function.
*
* Revision 1.78  2005/09/12 13:24:16  rupert
* +: Add 865xC Support
*
* Revision 1.77  2005/09/12 09:28:14  tony
* *: remove debug message
*
* Revision 1.76  2005/09/12 06:40:19  tony
* +: add RTL865XC NIC driver initial version.
*
* Revision 1.75  2005/08/23 14:38:26  chenyl
* +: apply prioirty IRAM/DRAM usage
*
* Revision 1.74  2005/08/11 07:22:09  tony
* +: add RTL865XB model code.
*
* Revision 1.73  2005/07/01 09:34:41  yjlou
* *: porting swNic2.c into model code.
*
* Revision 1.72  2005/06/24 11:00:43  yjlou
* *: fixed the bug of swNic_linkChgIntHandler(). This function should NEVER touch GPIO pin unless BICOLOR_LED_VENDOR_BXXX is defined.
*
* Revision 1.71  2005/06/09 12:10:36  chenyl
* *: modify airgo's fast path code
*
* Revision 1.70  2005/06/06 06:25:00  chenyl
* *: bug fix: we modify the property of pending packet only when we can find a new one to replace it.
*
* Revision 1.69  2005/06/06 06:01:17  chenyl
* *: bug fix :
* 	In swNic_rxRunoutTxPending(), we put a new pkt-mbuf-cluster into RxRing
* 	to replace the pending Pkt. So we must set its rxdesc according to the
* 	RxRing index.
*
* Revision 1.68  2005/06/03 11:18:42  chenyl
* *: modify swNic_rxRunoutTxPending's mechanism
*
* Revision 1.67  2005/05/23 12:53:41  yjlou
* *: rename rtl8651_timeUpdate() to rtl8651_realtimeSchedule().
* +: ROME driver supports realtime PCM and tick interrupt for VoIP.
*
* Revision 1.66  2005/04/24 04:58:35  yjlou
* *: We shall check Timer1 per packet to guarantee VoIP realtime process.
*
* Revision 1.65  2005/04/07 10:35:09  cfliu
* +: Add swnic pkt dump feature support
*
* Revision 1.64  2005/04/06 07:28:11  cfliu
* +: Add Airgo fast path code with AIRGO_FAST_PATH compile flag
*
* Revision 1.63  2005/03/22 11:06:49  tony
* *: support Software LSO and Protocol-Stack fast path(tunning for USB->SAMBA performance)
*
* Revision 1.62  2005/03/18 12:25:35  tony
* fix bug: get cache value in TxPkthdrRing, cause the value nerver change in a loop.
*
* Revision 1.61  2005/01/26 08:38:33  cfliu
* *: Remove MBUF_DESC_RUNOUT_IE from Intr mask since we always allocate one
* mbuf for a pkthdr in code so when pkthdr's runout event is solved, mbuf
* runout is naturally solved.
*
* Revision 1.60  2005/01/26 02:42:08  cfliu
* *** empty log message ***
*
* Revision 1.59  2005/01/11 16:16:06  cfliu
* +:Add mBuf_setNICRxRingSize to tell mbuf module the size of NIC Rx ring
*
* Revision 1.58  2005/01/10 03:17:44  danwu
* * add CONFIG_RTL865XB_EXP_PERFORMANCE_EVALUATION for DMA throughput measurement
*
* Revision 1.57  2005/01/09 08:38:55  cfliu
* -:Undefine SWNIC_EARLYSTOP,
* +:Always put to IRAM: swNic_intHandler, _swNic_recvLoop, swNic_rxThread, swNic_isrReclaim, swNic_isrTxRecycle, swNic_write
* +:Move rtl8651_timeUpdate() from per pkt based to per intr based to save time
* +:Add link change Intr statistics counter.
*
* Revision 1.56  2004/12/27 01:53:16  yjlou
* +: add ROMEPERF code to measure performance.
*
* Revision 1.55  2004/12/20 12:57:21  yjlou
* +: add romeperf point to measure performance.
*
* Revision 1.54  2004/11/29 13:40:32  yjlou
* +: support ROMEperf
*
* Revision 1.53  2004/11/22 04:36:09  chenyl
* *: move TX-alignment code from layer2fwd to swNic2
*
* Revision 1.52  2004/11/19 09:56:39  cfliu
* *: Add nic cmd group, add 5 cmds: counter, ring, loopback, hub and cmd
* 	counter: dump counter value or reset counters
* 	ring: dump Tx/Rx rings or cleanup and reallocate whole ring
* 	loopback: Dummy port A in, port B out diagnostics mode
* 	hub: Make RTL865x as a Hub
* 	cmd: Let user resume/stop Tx/Rx or specify max pkts processed in
* each ISR
* *: Fix Tx pending pkt stops Rx recv bug.
*
* Revision 1.51  2004/11/12 10:55:10  chhuang
* *: bug fixed: when init switch nic, enable Tx/Rx after setting CPUICR to shift 2 bytes
*
* Revision 1.50  2004/11/10 05:13:52  cfliu
* -: remove call to rtl8651_getChipVersion, use GetChipVersion in setup.c instead
*
* Revision 1.49  2004/10/22 11:42:24  cfliu
* *: Fix CPU Rx overrun to pkts on Tx ring problem. Each pkt rcvd from/sent to
* NIC is now labeled. Rx loop checks this bit to prevent overrun.
*
* Revision 1.48  2004/10/21 06:12:59  chenyl
* *: bug fix: free L2-broadcasted Mcast packet when we send it fail.
*
* Revision 1.47  2004/10/08 09:05:29  chenyl
* *: remove debugging message with potential-risks
*
* Revision 1.46  2004/09/30 08:29:45  danwu
* * reset m_data in swNic_isrReclaim (for either CONFIG_RTL865X_MBUF_HEADROOM or CONFIG_RTL865X_MULTILAYER_BSP is undefined)
*
* Revision 1.45  2004/09/27 12:49:16  yjlou
* +: support ROMEreal function (CONFIG_RTL865X_ROMEREAL)
*
* Revision 1.44  2004/09/16 04:25:17  cfliu
* Add SwNic early Rx stop function
*
* Revision 1.43  2004/08/05 06:39:11  chenyl
* +: fragment shortest path forwarding
* *: UDPBomb don't aware ignore Type Checking result
*
* Revision 1.42  2004/07/28 10:48:20  chenyl
* *: bug fix : [re_core.c]
* 		- rtl865x_fastRx: queue-packets to Protocol Stack and failed, free Mbuf ERROR
* *: bug fix : [swNic2.c]
* 		- swNic_write: process ERROR when mbuf padding failed
* *: bug fix : [rtl8651_tblDrvFwd.c]
* 		- _rtl8651_l34ActExec: process _RTL8651_NAT_IGNORE in _RTL8651_NPT case
* *: bug fix : [rtl8651_tblDrvFwd.c]
* 		- rtl8651_fwdEngineInput: when process result is FWDENG_ACL_DROP_NOTIFY,
* 				we must either generate ICMP Error message with newly allocated packet and trap
* 				the original packet, or generate ICMP Error message using original packet and return
* 				SUCCESS.
* 				we can not send ICMP Error message with the original packet and trap it to Procotol Stack.
*
* Revision 1.41  2004/07/27 10:39:02  cfliu
* *: Fix all compile warnings
*
* Revision 1.40  2004/07/13 07:08:45  cfliu
* +: Update NIC descriptor ring dump command
*
* Revision 1.39  2004/07/09 12:19:39  cfliu
* no message
*
* Revision 1.38  2004/07/08 14:30:48  cfliu
* +:  Reserve 128 byte headroom for any pkt get from mbuf pool
*
* Revision 1.37  2004/07/06 14:08:37  cfliu
* +: Flush D-cache when pkt send to protocol stack. Don't copy packet if on 8650B and NIC enabled iphdr aligned feature.
*
* Revision 1.36  2004/07/06 01:15:13  cfliu
* +: Add CONFIG_RTL865X_NETWORK_IO flag
*
* Revision 1.35  2004/07/04 14:53:01  cfliu
* +: Change NIC Rx align to 2 byte aligned. change recv loop prototype so NIC can be forced stop by fwd engine.
*
* Revision 1.34  2004/06/29 07:11:46  cfliu
* no message
*
* Revision 1.33  2004/06/25 13:53:53  chhuang
* regular update
*
* Revision 1.32  2004/06/21 07:18:16  chhuang
* *:  modify pPkthdr->ph_rxdesc = -1; to
*       pPkthdr->ph_rxdesc = totalRxPkthdr;
*
* Revision 1.31  2004/06/08 10:26:24  cfliu
* *: Fix runout lost interrupt problem
*
* Revision 1.30  2004/06/08 08:10:56  tony
* *: fix PPTP broadcast problem for Windows 2000 Server.
*
* Revision 1.29  2004/05/20 03:41:58  cfliu
* Bugfix: Fix losing Rx runout interrupt problem.
*
* Revision 1.28  2004/05/19 08:45:09  orlando
* add code for bi color led gpio control
*
* Revision 1.27  2004/05/13 05:47:32  tony
* new features: support PPTP/L2TP with WLAN on RTL865XB.
*
* Revision 1.26  2004/05/12 05:15:04  tony
* support PPTP/L2TP in RTL865XB.
*
* Revision 1.25  2004/05/03 15:11:44  cfliu
* no message
*
* Revision 1.24  2004/05/03 14:36:35  cfliu
* add extension port support on WLAN acceleration
*
* Revision 1.23  2004/05/03 02:53:03  chenyl
* *: swNic_getRingSize -> rtlglue_getRingSize and move it from swNic2.c to rtl_glue.c
* *: set default upstream ip to 0 if we config interface to dhcp
*
* Revision 1.22  2004/04/30 12:59:00  chenyl
* *: bug fix in swNic2.c, isrReclaim()
*
* Revision 1.21  2004/04/30 08:58:08  chenyl
* +: ip multicast/igmp proxy
*
* Revision 1.20  2004/04/21 07:05:25  danwu
* swNic_write: do not clear extension port settings while verification package included
*
* Revision 1.19  2004/04/19 13:48:17  tony
* make m_data offset 128 bytes, and make it can run well with WLAN mode.
*
* Revision 1.18  2004/04/16 06:24:50  cfliu
* Turn off m_data+128 code temporarily. Must revise it...
*
* Revision 1.17  2004/04/12 05:59:13  tony
* make mbuf->m_data = mbuf->m_extbuf + 128
*
* Revision 1.16  2004/04/08 12:07:40  cfliu
* no message
*
* Revision 1.15  2004/04/08 02:21:41  chhuang
* turn off PKTHDR_BRIDGING and PKTHDR_HWLOOKUP flags
*
* Revision 1.14  2004/04/01 03:31:28  jzchen
* Reserved field need configured to zero for 8650B able to work
*
* Revision 1.13  2004/03/30 11:48:49  cfliu
* Add link change interrupt
*
* Revision 1.12  2004/03/26 11:21:55  cfliu
* swNic_intHandler handles most Rx ISR jobs now...
*
* Revision 1.11  2004/03/24 08:40:02  cfliu
* Fix intr lost problem.
*
* Revision 1.10  2004/03/24 01:10:07  cfliu
* Rewrite NIC recv loop.
*
* Revision 1.9  2004/03/23 09:31:03  cfliu
* Fix NIC overrun problemEnlarge mbuf & NIC init buffer size.
*
* Revision 1.8  2004/03/19 12:07:18  cfliu
* Bug fix to handle runout stuck and Rx intr lost risk..
*
* Revision 1.7  2004/03/10 11:27:46  cfliu
* separate layer2 functions to separate C src file
*
* Revision 1.6  2004/03/04 09:29:02  yjlou
* *: change directory of include file: from rtl86xx_tbl/ to rtl865x/
*
* Revision 1.5  2004/02/27 09:42:40  cfliu
* Move away linux dependent definition
*
* Revision 1.4  2004/02/24 04:08:02  cfliu
* Add WLAN HW acceleration
*
* Revision 1.3  2003/12/22 12:30:59  orlando
* mark enableLbcTimeout()
*
* Revision 1.2  2003/12/18 12:47:42  rupert
* fix new nic driver
*
* Revision 1.1  2003/12/09 15:35:31  cfliu
* new NIC driver. To enable it, use CONFIG_RTL865X_NICDRV2. Performance gain is 2.5X
*
* Revision 1.1  2003/11/26 00:06:05  cfliu
* switch NIC driver version 2 initial version.
*
*/
#ifdef RTL865X_MODEL_USER
	#include <errno.h>
	#include "rtl_glue.h"
	#include "rtl_utils.h"
#else
	#ifdef __linux__
		#include <linux/config.h>
		#include <linux/mm.h>
		#include <linux/interrupt.h>
	#endif
	#include <asm/rtl865x/interrupt.h>
#endif
#include "rtl865x/rtl_types.h"
#include "rtl865x/rtl_glue.h"
#include "rtl865x/mbuf.h"
#include "swNic2.h"
#include "rtl865x/assert.h"
#include "rtl865x/asicRegs.h"
#include "rtl865x/rtl8651_layer2.h"
#ifdef CONFIG_RTL865XC
#include "rtl865x/rtl865xC_tblAsicDrv.h"
#else
#include "rtl865x/rtl8651_tblAsicDrv.h"
#endif

#ifdef CONFIG_RTL865X_ROMEPERF
	//Turn on CPU profiling code.
	#include "romeperf.h"
	#define PROFILING_START rtl8651_romeperfEnterPoint
	#define PROFILING_END	rtl8651_romeperfExitPoint
#else
	#define PROFILING_START(x)  do{}while(0)	
	#define PROFILING_END(x) do{}while(0)	
#endif


#ifdef CONFIG_RTL865X_ROMEREAL
	//Turn on In-memory "ethereal" like pkt sniffing code.
	#define START_SNIFFING rtl8651_romerealRecord
#else
	#define START_SNIFFING(x,y) do{}while(0)	
#endif


#ifdef AIRGO_FAST_PATH
	//For all WLAN router projects based on Airgo MIMO cards.
	//turn on this flag in Makefile
	#define AIRGO_MAGIC 0x3478
	typedef unsigned int (*fast_free_fn)(void * pkt);
	extern fast_free_fn airgo_free;
#endif


int8 swNic_Id[] = "$Id: swNic2.c,v 1.84 2005/11/29 03:11:51 yjlou Exp $";
/* descriptor ring related variables */
static proc_input_pkt_funcptr_t installedProcessInputPacket;

#ifdef CONFIG_RTL865XC 

uint32	totalRxPkthdr0, totalRxMbuf0,totalTxPkthdr0, totalTxPkthdrShift0;  /*total desc count on each ring */
uint32	totalRxPkthdr1, totalTxPkthdr1, totalTxPkthdrShift1;  /*total desc count on each ring */
uint32	totalRxPkthdr2;  /*total desc count on each ring */
uint32	totalRxPkthdr3;  /*total desc count on each ring */
uint32	totalRxPkthdr4;  /*total desc count on each ring */
uint32	totalRxPkthdr5;  /*total desc count on each ring */

uint32 	rxMbufIndex0, rxPhdrIndex0, txDoneIndex0, txFreeIndex0,lastTxIndex0; /* current desc index */
uint32 	rxPhdrIndex1, txDoneIndex1, txFreeIndex1,lastTxIndex1; /* current desc index */
uint32 	rxPhdrIndex2; /* current desc index */
uint32 	rxPhdrIndex3; /* current desc index */
uint32 	rxPhdrIndex4; /* current desc index */
uint32 	rxPhdrIndex5; /* current desc index */

volatile uint32 	*RxPkthdrRing0,*RxMbufRing0, *TxPkthdrRing0; /* descriptor ring, should be volatile */
volatile uint32 	*RxPkthdrRing1, *TxPkthdrRing1; /* descriptor ring, should be volatile */
volatile uint32 	*RxPkthdrRing2; /* descriptor ring, should be volatile */
volatile uint32 	*RxPkthdrRing3; /* descriptor ring, should be volatile */
volatile uint32 	*RxPkthdrRing4; /* descriptor ring, should be volatile */
volatile uint32 	*RxPkthdrRing5; /* descriptor ring, should be volatile */

static int32	rxRunoutIdx0, lastIntRxDescIdx0,lastReclaim0;
static int32	rxRunoutIdx1, lastIntRxDescIdx1,lastReclaim1;
static int32	rxRunoutIdx2, lastIntRxDescIdx2,lastReclaim2;
static int32	rxRunoutIdx3, lastIntRxDescIdx3,lastReclaim3;
static int32	rxRunoutIdx4, lastIntRxDescIdx4,lastReclaim4;
static int32	rxRunoutIdx5, lastIntRxDescIdx5,lastReclaim5;

#else

uint32	totalRxPkthdr, totalRxMbuf,totalTxPkthdr, totalTxPkthdrShift;  /*total desc count on each ring */
uint32 	rxMbufIndex, rxPhdrIndex, txDoneIndex, txFreeIndex,lastTxIndex; /* current desc index */
volatile uint32 	*RxPkthdrRing,*RxMbufRing, *TxPkthdrRing; /* descriptor ring, should be volatile */
static int32	rxRunoutIdx, lastReclaim, lastIntRxDescIdx;

#endif


static int32 nicTxAlignFix;

#ifdef SWNIC_DEBUG 
	int32 nicDbgMesg;
#endif
 int32  rxEnable, txEnable;

#undef SWNIC_EARLYSTOP 
#ifdef SWNIC_EARLYSTOP
static int32 nicRxEarlyStop;
static int32 nicRxAbort;
#endif

/* swnic debug counters */
static int32   rxIntNum;
static int32 linkChanged;
static int32   txIntNum;
static int32   rxMbufRunoutNum;
static int32   rxPktErrorNum;
static int32   txPktErrorNum;
static int32   rxPktCounter;
static int32   txPktCounter;
 int32 rxPkthdrRunoutNum,rxPkthdrRunoutSolved;
 int32 rxPkthdr_runout;

void swNic_rxThread(unsigned long);

#ifdef CONFIG_RTL865XC 
void swNic_isrTxRecycle(int32,int8);
#else
void swNic_isrTxRecycle(int32);
#endif

#ifdef CONFIG_RTL865X_CLE
static int32 swNic_resetCounters(void);
#endif

 int32 swNic_write(void*);

#ifdef CONFIG_RTL865XB_EXP_PERFORMANCE_EVALUATION
static int32 _pernicStart = FALSE;
static int32 _pernicInst = TRUE;
static uint32 _pernicPktLimit = 10000;
static uint32 _pernicPktCount = 0;
static uint32 _pernicByteCount = 0;

void swNic_pernicrxStart(int32 instMode, uint32 totalPkt){
	_pernicPktCount = _pernicByteCount = 0;
	_pernicInst = instMode;
	_pernicPktLimit = totalPkt;
	_pernicStart = TRUE;
}

void swNic_pernicrxEnd(uint32 *pktCount, uint32 *byteCount){
	*pktCount = _pernicPktCount;
	*byteCount = _pernicByteCount;
	_pernicStart = FALSE;
}
#endif


//For 865xB A&B cut only. 
static void _nicTxAlignFix(struct rtl_pktHdr *pPkt, struct rtl_mBuf *pMbuf){
	uint16 pLen;
	pLen = pPkt->ph_len + 4;	/* CRC is included */
	if (((pLen&0x1c) == 0) && ((pLen&0x03) != 0))
	{
		assert(pPkt->ph_len == pMbuf->m_len);
		pPkt->ph_len = (pPkt->ph_len&0xFFFC) + 0x4;	/* let it become 4-byte alignment */
		pMbuf->m_len = pPkt->ph_len;
	}
}



int32 swNic_linkChgIntHandler(void){
//	REG32(CPUIISR) = (uint32)LINK_CHANG_IP;
	WRITE_MEM32(CPUIISR,(uint32)LINK_CHANG_IP);
	//rtlglue_printf("interrupt link change %x\n",(uint32)jiffies);
	rtl8651_updateLinkChangePendingCount();
	if(SUCCESS==rtl8651_updateLinkStatus()){
		#if defined(CONFIG_RTL865X_BICOLOR_LED)
		#ifdef BICOLOR_LED_VENDOR_BXXX
		int32 i;
		for(i=0; i<5; i++) {  
			//while(!(REG32(PHY_BASE+(i<<5)+0x4) & 0x20));
			if(READ_MEM32((PHY_BASE+(i<<5)+0x4)) & 0x4) { //link is up
				//printf("port %d phyControlRegister 0[%08x] 4[%08x]\n",i,REG32(PHY_BASE+(i<<5)),REG32(PHY_BASE+(i<<5)+4));
				//printf("Port %d Link Change!\n",i);
					if(READ_MEM32((PHY_BASE+(i<<5))) & 0x2000){
					/* link up speed 100Mbps */
					/* set gpio port  with high */
					//printf("port %d speed 100M %08x\n",i,REG32(PHY_BASE+(i<<5)));
//					REG32(PABDAT) |= (1<<(16+i));
					WRITE_MEM32(PABDAT, READ_MEM32(PABDAT) | (1<<(16+i)));
				}else{
					/* link up speed 10Mbps */
					//rtlglue_printf("linkSpeed10M\n");
					/* set gpio port  with high */
					//printf("port %d speed 10M %08x\n",i,REG32(PHY_BASE+(i<<5)));
					//REG32(PABDAT) &= ~(1<<(16+i));
					WRITE_MEM32(PABDAT, READ_MEM32(PABDAT) & ~(1<<(16+i)));
				} /* end if  100M */
			}/* end if  link up */
		}/* end for */
		#endif /* BICOLOR_LED_VENDOR_BXXX */
		#endif /* CONFIG_RTL865X_BICOLOR_LED */
		return SUCCESS;
	}else
		rtlglue_printf("Link chg int handle error!\n");
	//rtlglue_printf("interrupt link change %x\n",jiffies);	
	return FAILED;
}

int32 swNic_rxRunoutTxPending(struct rtl_pktHdr *pPkthdr){
	//exception handling
	struct rtl_pktHdr *freePkthdrListHead, *freePkthdrListTail;
	struct rtl_mBuf *freeMbufListHead, *freeMbufListTail;
	uint32  wrap=0;
#ifdef SWNIC_DEBUG

	if(nicDbgMesg)
	{
#ifdef CONFIG_RTL865XC 
		rtlglue_printf("(ph: %08x): Rx runout by pending Tx\n",(uint32)pPkthdr );
#else
		rtlglue_printf("Desc %d (ph: %08x): Rx runout by pending Tx\n", rxPhdrIndex,(uint32)pPkthdr );
#endif
	}
#endif

	/*
		Allocate and init a new packet to to put into Rx Ring to replace the pending one.
	*/
	if ((mBuf_driverGetPkthdr(1, &freePkthdrListHead, &freePkthdrListTail))!=1)
	{
		rtlglue_printf("Fatal. No more pkthdr. runout NOT solved!!\n");
		return FAILED;
	}

	if(1!=mBuf_driverGet(1, &freeMbufListHead, &freeMbufListTail)){
		rtlglue_printf("Fatal. No more mbuf. runout NOT solved!!\n");
		mBuf_driverFreePkthdr(freePkthdrListHead, 1, 0);
		return FAILED;
	}

#ifdef RTL865X_MODEL_USER
	freeMbufListHead->m_extbuf=(uint8 *)(freeMbufListHead->m_extbuf);
	freeMbufListHead->m_data=(uint8 *)(freeMbufListHead->m_data);
#else
	freeMbufListHead->m_extbuf=(uint8 *)UNCACHE(freeMbufListHead->m_extbuf);
	freeMbufListHead->m_data=(uint8 *)UNCACHE(freeMbufListHead->m_data);
#endif	

	#if defined(CONFIG_RTL865X_MBUF_HEADROOM)&&defined(CONFIG_RTL865X_MULTILAYER_BSP)
	if(mBuf_reserve(freeMbufListHead, CONFIG_RTL865X_MBUF_HEADROOM))
	{
		rtlglue_printf("Failed when init Rx %d\n", rxPhdrIndex);
	}
	#endif

#ifdef CONFIG_RTL865XC 

	freePkthdrListHead->ph_flags&=~PKTHDR_DRIVERHOLD;	/* pkthdr put to RxRing, we remove this flag */		
	freePkthdrListHead->ph_rxmbufdesc = rxMbufIndex0;				
	RxMbufRing0[rxMbufIndex0] = (uint32) freeMbufListHead | DESC_SWCORE_OWNED | wrap;		
	pPkthdr->ph_rxmbufdesc = totalRxMbuf0;
	
	switch((pPkthdr->ph_flags>>11)&0x7)
	{
		case 0:
			if (rxPhdrIndex0==totalRxPkthdr0-1)
			{
				wrap = DESC_WRAP;
			}

			freePkthdrListHead->ph_rxdesc = rxPhdrIndex0;		/* pkthdr put tx RxRing, we set its rxdesc */
			RxPkthdrRing0[rxPhdrIndex0] = (uint32) freePkthdrListHead | DESC_SWCORE_OWNED | wrap;
			/*
				Original pending packet: we modify its rxdesc to indicate
				this packet is no longer being the Rx Ring packet.
			*/
			pPkthdr->ph_rxdesc = totalRxPkthdr0;
			break;
		case 1:
			if (rxPhdrIndex1==totalRxPkthdr1-1)
			{
				wrap = DESC_WRAP;
			}

			freePkthdrListHead->ph_rxdesc = rxPhdrIndex1;		/* pkthdr put tx RxRing, we set its rxdesc */
			RxPkthdrRing1[rxPhdrIndex1] = (uint32) freePkthdrListHead | DESC_SWCORE_OWNED | wrap; 
			/*
				Original pending packet: we modify its rxdesc to indicate
				this packet is no longer being the Rx Ring packet.
			*/
			pPkthdr->ph_rxdesc = totalRxPkthdr1;
			break;
		case 2:
			if (rxPhdrIndex2==totalRxPkthdr2-1)
			{
				wrap = DESC_WRAP;
			}

			freePkthdrListHead->ph_rxdesc = rxPhdrIndex2;		/* pkthdr put tx RxRing, we set its rxdesc */
			RxPkthdrRing2[rxPhdrIndex2] = (uint32) freePkthdrListHead | DESC_SWCORE_OWNED | wrap; 
			/*
				Original pending packet: we modify its rxdesc to indicate
				this packet is no longer being the Rx Ring packet.
			*/
			pPkthdr->ph_rxdesc = totalRxPkthdr2;
			break;
			
		case 3:
			if (rxPhdrIndex3==totalRxPkthdr3-1)
			{
				wrap = DESC_WRAP;
			}

			freePkthdrListHead->ph_rxdesc = rxPhdrIndex3;		/* pkthdr put tx RxRing, we set its rxdesc */
			RxPkthdrRing3[rxPhdrIndex3] = (uint32) freePkthdrListHead | DESC_SWCORE_OWNED | wrap; 
			/*
				Original pending packet: we modify its rxdesc to indicate
				this packet is no longer being the Rx Ring packet.
			*/
			pPkthdr->ph_rxdesc = totalRxPkthdr3;
			break;
		case 4:
			if (rxPhdrIndex4==totalRxPkthdr4-1)
			{
				wrap = DESC_WRAP;
			}

			freePkthdrListHead->ph_rxdesc = rxPhdrIndex4;		/* pkthdr put tx RxRing, we set its rxdesc */
			RxPkthdrRing4[rxPhdrIndex4] = (uint32) freePkthdrListHead | DESC_SWCORE_OWNED | wrap; 
			/*
				Original pending packet: we modify its rxdesc to indicate
				this packet is no longer being the Rx Ring packet.
			*/
			pPkthdr->ph_rxdesc = totalRxPkthdr4;
			break;
		case 5:
			if (rxPhdrIndex5==totalRxPkthdr5-1)
			{
				wrap = DESC_WRAP;
			}

			freePkthdrListHead->ph_rxdesc = rxPhdrIndex5;		/* pkthdr put tx RxRing, we set its rxdesc */
			RxPkthdrRing5[rxPhdrIndex5] = (uint32) freePkthdrListHead | DESC_SWCORE_OWNED | wrap; 
			/*
				Original pending packet: we modify its rxdesc to indicate
				this packet is no longer being the Rx Ring packet.
			*/
			pPkthdr->ph_rxdesc = totalRxPkthdr5;
			break;
			
	}
#else

	if (rxPhdrIndex==totalRxPkthdr-1)
	{
		wrap = DESC_WRAP;
	}

	freePkthdrListHead->ph_rxdesc = rxPhdrIndex;		/* pkthdr put tx RxRing, we set its rxdesc */
	freePkthdrListHead->ph_flags&=~PKTHDR_DRIVERHOLD;	/* pkthdr put to RxRing, we remove this flag */		
	RxMbufRing[rxPhdrIndex] = (uint32) freeMbufListHead | DESC_SWCORE_OWNED | wrap;
	RxPkthdrRing[rxPhdrIndex] = (uint32) freePkthdrListHead | DESC_SWCORE_OWNED | wrap;
	/*
		Original pending packet: we modify its rxdesc to indicate
		this packet is no longer being the Rx Ring packet.
	*/
	pPkthdr->ph_rxdesc = totalRxPkthdr;
	
#endif


#ifdef AIRGO_FAST_PATH
	{
		//airgo
		freeMbufListHead->m_pkthdr = freePkthdrListHead;
		freePkthdrListHead->ph_mbuf = freeMbufListHead;
		freeMbufListHead->m_next = 0;
		freePkthdrListHead->ph_reserved = 0;
		pPkthdr->ph_reserved = AIRGO_MAGIC;
	}
#endif
	
	return SUCCESS;
}




//#pragma ghs section text=".iram"
__IRAM_FWD int32 swNic_intHandler(int32 *param)
{

#ifdef CONFIG_RTL865XC 
	int32 curDesc[6]={-1,-1,-1,-1,-1,-1};
	int32 sched=0;
	uint32  cpuiisr,intPending;
	spin_lock(rtl865xSpinlock);
	while(1){

		
		/* Read the interrupt status register */
	    	cpuiisr=intPending = READ_MEM32(CPUIISR);
		
		// filter those intr we don't care. only those intrs with its IIMR bit set would trigger ISR.
	
		// clear mask interrupts
		intPending &= READ_MEM32(CPUIIMR); 
		//rtlglue_printf("mask:%x, iisr:%x, iimr:%x\n", INTPENDING_NIC_MASK,cpuiisr,REG32(CPUIIMR));

		/* Check and handle NIC interrupts */
		if (intPending & INTPENDING_NIC_MASK){
			WRITE_MEM32(CPUIISR,intPending); //clear all pending interrupts
			// let new RX_RUNOUT interrupts not be triggered.			
			if(intPending & PKTHDR_DESC_RUNOUT_IP_ALL){
//				REG32(CPUIIMR)&=~PKTHDR_DESC_RUNOUT_IE;
				WRITE_MEM32(CPUIIMR,READ_MEM32(CPUIIMR)&(~PKTHDR_DESC_RUNOUT_IE_ALL));
				sched=1;
			}

			// let new RX_DONE  interrupts not be triggered.
			if ( intPending &RX_DONE_IP_ALL){
//				REG32(CPUIIMR)&=~RX_DONE_IE;

				WRITE_MEM32(CPUIIMR,READ_MEM32(CPUIIMR)&~RX_DONE_IE_ALL);

				sched=1;
			}
			
			if (sched){

				if(intPending & RX_DONE_IP5)
				{
					curDesc[5]=(uint32 *)READ_MEM32(CPURPDCR5)-RxPkthdrRing5;

					if (intPending & PKTHDR_DESC_RUNOUT_IP5){
						rxPkthdrRunoutNum++;
						rxRunoutIdx0=curDesc[5];
						rxPkthdr_runout=1;
					}
					if(curDesc[5]-1<0)
						curDesc[5]=totalRxPkthdr5-1;
					else
						curDesc[5]-=1;
					lastIntRxDescIdx5=curDesc[5]; //Last pkt of this run. ASIC won't run cross it before we consume this last pkt.
					rxIntNum++;
				}	

				if(intPending & RX_DONE_IP4)
				{
					curDesc[4]=(uint32 *)READ_MEM32(CPURPDCR4)-RxPkthdrRing4;

					if (intPending & PKTHDR_DESC_RUNOUT_IP4){
						rxPkthdrRunoutNum++;
						rxRunoutIdx0=curDesc[4];
						rxPkthdr_runout=1;
					}
					if(curDesc[4]-1<0)
						curDesc[4]=totalRxPkthdr4-1;
					else
						curDesc[4]-=1;
					lastIntRxDescIdx4=curDesc[4]; //Last pkt of this run. ASIC won't run cross it before we consume this last pkt.
					rxIntNum++;
				}				

				if(intPending & RX_DONE_IP3)
				{
					curDesc[3]=(uint32 *)READ_MEM32(CPURPDCR3)-RxPkthdrRing3;

					if (intPending & PKTHDR_DESC_RUNOUT_IP3){
						rxPkthdrRunoutNum++;
						rxRunoutIdx0=curDesc[3];
						rxPkthdr_runout=1;
					}
					if(curDesc[3]-1<0)
						curDesc[3]=totalRxPkthdr3-1;
					else
						curDesc[3]-=1;
					lastIntRxDescIdx3=curDesc[3]; //Last pkt of this run. ASIC won't run cross it before we consume this last pkt.
					rxIntNum++;
				}	

				if(intPending & RX_DONE_IP2)
				{
					curDesc[2]=(uint32 *)READ_MEM32(CPURPDCR2)-RxPkthdrRing2;

					if (intPending & PKTHDR_DESC_RUNOUT_IP2){
						rxPkthdrRunoutNum++;
						rxRunoutIdx0=curDesc[2];
						rxPkthdr_runout=1;
					}
					if(curDesc[2]-1<0)
						curDesc[2]=totalRxPkthdr2-1;
					else
						curDesc[2]-=1;
					lastIntRxDescIdx2=curDesc[2]; //Last pkt of this run. ASIC won't run cross it before we consume this last pkt.
					rxIntNum++;
				}	

				if(intPending & RX_DONE_IP1)
				{
					curDesc[1]=(uint32 *)READ_MEM32(CPURPDCR1)-RxPkthdrRing1;

					if (intPending & PKTHDR_DESC_RUNOUT_IP1){
						rxPkthdrRunoutNum++;
						rxRunoutIdx0=curDesc[1];
						rxPkthdr_runout=1;
					}
					if(curDesc[1]-1<0)
						curDesc[1]=totalRxPkthdr1-1;
					else
						curDesc[1]-=1;
					lastIntRxDescIdx1=curDesc[1]; //Last pkt of this run. ASIC won't run cross it before we consume this last pkt.
					rxIntNum++;
				}	

				if(intPending & RX_DONE_IP0)
				{
					curDesc[0]=(uint32 *)READ_MEM32(CPURPDCR0)-RxPkthdrRing0;

					if (intPending & PKTHDR_DESC_RUNOUT_IP0){
						rxPkthdrRunoutNum++;
						rxRunoutIdx0=curDesc[0];
						rxPkthdr_runout=1;
					}
					if(curDesc[0]-1<0)
						curDesc[0]=totalRxPkthdr0-1;
					else
						curDesc[0]-=1;
					lastIntRxDescIdx0=curDesc[0]; //Last pkt of this run. ASIC won't run cross it before we consume this last pkt.
					rxIntNum++;
				}
			
			}

			if ( intPending & (RX_ERR_IP_ALL|TX_ERR_IP_ALL)){
				
				if ( intPending& TX_ERR_IP0) 	txPktErrorNum++;
				if ( intPending& TX_ERR_IP1) 	txPktErrorNum++;
				if ( intPending& RX_ERR_IP0) 	rxPktErrorNum++;
				if ( intPending& RX_ERR_IP1) 	rxPktErrorNum++;
				if ( intPending& RX_ERR_IP2) 	rxPktErrorNum++;
				if ( intPending& RX_ERR_IP3) 	rxPktErrorNum++;
				if ( intPending& RX_ERR_IP4) 	rxPktErrorNum++;
				if ( intPending& RX_ERR_IP5) 	rxPktErrorNum++;
			}
		}
		
		/* Check and handle link change interrupt */
		if (intPending & LINK_CHANG_IP) 
			swNic_linkChgIntHandler();

		if ((intPending & (INTPENDING_NIC_MASK|LINK_CHANG_IP)) == 0){
//			REG32(CPUIISR) = cpuiisr & ~(INTPENDING_NIC_MASK|LINK_CHANG_IP); //clear all uninterested intrs 

			WRITE_MEM32(CPUIISR , cpuiisr & ~(INTPENDING_NIC_MASK|LINK_CHANG_IP)); //clear all uninterested intrs 
		
			break;
		}
	}
	spin_unlock(rtl865xSpinlock);	
	return sched;

#else // FOR RTL865XB

	int32 curDesc=-1;
	int32 sched=0;
	uint32  cpuiisr,intPending;
	spin_lock(rtl865xSpinlock);
	while(1){
		/* Read the interrupt status register */
//	    	cpuiisr=intPending = REG32(CPUIISR);
	    	cpuiisr=intPending = READ_MEM32(CPUIISR);
		// filter those intr we don't care. only those intrs with its IIMR bit set would trigger ISR.
//		intPending &= REG32(CPUIIMR);
		intPending &= READ_MEM32(CPUIIMR);
		//rtlglue_printf("mask:%x, iisr:%x, iimr:%x\n", INTPENDING_NIC_MASK,cpuiisr,REG32(CPUIIMR));
		/* Check and handle NIC interrupts */
		if (intPending & INTPENDING_NIC_MASK){
//			REG32(CPUIISR) = intPending;
			WRITE_MEM32(CPUIISR,intPending);
			if(intPending & PKTHDR_DESC_RUNOUT_IP){
//				REG32(CPUIIMR)&=~PKTHDR_DESC_RUNOUT_IE;
				WRITE_MEM32(CPUIIMR,READ_MEM32(CPUIIMR)&(~PKTHDR_DESC_RUNOUT_IE));
				sched=1;
			}
			if ( intPending &RX_DONE_IP){
//				REG32(CPUIIMR)&=~RX_DONE_IE;
				WRITE_MEM32(CPUIIMR,READ_MEM32(CPUIIMR)&~RX_DONE_IE);
				sched=1;
			}
			if (sched){
//				curDesc=(uint32 *)REG32(CPURPDCR)-RxPkthdrRing;
				curDesc=(uint32 *)READ_MEM32(CPURPDCR)-RxPkthdrRing;

				if (intPending & PKTHDR_DESC_RUNOUT_IP){
					rxPkthdrRunoutNum++;
					rxRunoutIdx=curDesc;
					rxPkthdr_runout=1;
				}

				if(curDesc-1<0)
					curDesc=totalRxPkthdr-1;
				else
					curDesc-=1;
				lastIntRxDescIdx=curDesc; //Last pkt of this run. ASIC won't run cross it before we consume this last pkt.

				if(intPending & RX_DONE_IP)
					rxIntNum++;

			}

			if ( intPending & (RX_ERR_IP|TX_ERR_IP)){
				if ( intPending& TX_ERR_IP)
					txPktErrorNum++;
				else
					rxPktErrorNum++;
			}

		}
		/* Check and handle link change interrupt */
		if (intPending & LINK_CHANG_IP) 
			swNic_linkChgIntHandler();
		if ((intPending & (INTPENDING_NIC_MASK|LINK_CHANG_IP)) == 0){
//			REG32(CPUIISR) = cpuiisr & ~(INTPENDING_NIC_MASK|LINK_CHANG_IP); //clear all uninterested intrs 
			WRITE_MEM32(CPUIISR , cpuiisr & ~(INTPENDING_NIC_MASK|LINK_CHANG_IP)); //clear all uninterested intrs 
			break;
		}
	}
	spin_unlock(rtl865xSpinlock);	
	return sched;
#endif
}


#ifdef CONFIG_RTL865XC 
__IRAM_FWD static int32 _swNic_recvLoop(int32 last0,int32 last1,int32 last2,int32 last3,int32 last4,int32 last5){
#else
__IRAM_FWD static int32 _swNic_recvLoop(int32 last){
#endif

#ifdef CONFIG_RTL865XC 
	volatile struct rtl_pktHdr * pPkthdr=NULL; //don't optimize
	volatile struct rtl_mBuf * pMbuf;	//don't optimize
	int32 count=0;
	do{
		uint32 flag=0;

#ifdef CONFIG_RTL865X_MULTILAYER_BSP
		/* Louis: We shall check per packet to guarantee VoIP realtime process. */
		rtl8651_realtimeSchedule();  //cfliu: check once per interrupt, not per pkt.
#endif

		PROFILING_START(ROMEPERF_INDEX_RECVLOOP);
		/* Increment counter */
		if((RxPkthdrRing0[rxPhdrIndex0]&DESC_OWNED_BIT)==1) 	flag|=1;
		if((RxPkthdrRing1[rxPhdrIndex1]&DESC_OWNED_BIT)==1) 	flag|=2;
		if((RxPkthdrRing2[rxPhdrIndex2]&DESC_OWNED_BIT)==1) 	flag|=4;
		if((RxPkthdrRing3[rxPhdrIndex3]&DESC_OWNED_BIT)==1) 	flag|=8;
		if((RxPkthdrRing4[rxPhdrIndex4]&DESC_OWNED_BIT)==1) 	flag|=16;
		if((RxPkthdrRing5[rxPhdrIndex5]&DESC_OWNED_BIT)==1) 	flag|=32;		

		if(flag==0x3f) goto out; // all switch own, software do nothing.

		
#ifdef SWNIC_EARLYSTOP		
		if(nicRxEarlyStop && ((count & nicRxEarlyStop)==nicRxEarlyStop)){//check global interrupt status
//			uint32 gisrNow = REG32(GISR);
			uint32 gisrNow = READ_MEM32(GISR);
			if(gisrNow & 0x65000000){ //Bit 30: USB, Bit 29:PCMCIA, Bit 26: PCI, Bit 24:GPIO
				nicRxAbort=1;
				goto out;						
			}
		}
#endif		

		if((flag&32)==0)
			pPkthdr = (struct rtl_pktHdr *) (RxPkthdrRing5[rxPhdrIndex5] & (~(DESC_OWNED_BIT | DESC_WRAP)));
		else if((flag&16)==0)
			pPkthdr = (struct rtl_pktHdr *) (RxPkthdrRing4[rxPhdrIndex4] & (~(DESC_OWNED_BIT | DESC_WRAP)));
		else if((flag&8)==0)
			pPkthdr = (struct rtl_pktHdr *) (RxPkthdrRing3[rxPhdrIndex3] & (~(DESC_OWNED_BIT | DESC_WRAP)));
		else if((flag&4)==0)
			pPkthdr = (struct rtl_pktHdr *) (RxPkthdrRing2[rxPhdrIndex2] & (~(DESC_OWNED_BIT | DESC_WRAP)));
		else if((flag&2)==0)
			pPkthdr = (struct rtl_pktHdr *) (RxPkthdrRing1[rxPhdrIndex1] & (~(DESC_OWNED_BIT | DESC_WRAP)));
		else if((flag&1)==0)
			pPkthdr = (struct rtl_pktHdr *) (RxPkthdrRing0[rxPhdrIndex0] & (~(DESC_OWNED_BIT | DESC_WRAP)));

		pMbuf = pPkthdr->ph_mbuf;

#ifdef CONFIG_RTL865XB_EXP_PERFORMANCE_EVALUATION
		if(_pernicStart == TRUE){
			static uint32 start, end;
			if(!_pernicPktCount){
				startCOP3Counters(_pernicInst);
				start = jiffies;
				}
			else if(_pernicPktCount == _pernicPktLimit){
				end = jiffies;
				stopCOP3Counters();
				rtlglue_printf("%d pkts. Total %d bytes, %d ms.  %u KBps\n", _pernicPktCount, _pernicByteCount, (uint32)((end-start)*10), (uint32)(_pernicByteCount/((end-start)*10)));
				_pernicStart = FALSE;
				}
			_pernicPktCount++;
			_pernicByteCount += pPkthdr->ph_len + 4;
pritnf("%s %d\n",__FUNCTION__,__LINE__);
#ifdef CONFIG_RTL865XC 			
			swNic_isrReclaim(rxPhdrIndex,rxMbufIndex, pPkthdr, pMbuf);
#else	
			swNic_isrReclaim(rxPhdrIndex, pPkthdr, pMbuf);
#endif				
			/* Increment index */
			if ( ++rxPhdrIndex == totalRxPkthdr )
				rxPhdrIndex = 0;
			if ( ++rxMbufIndex == totalRxMbuf )
				rxMbufIndex = 0;
			continue;
			}
#endif

		assert(pPkthdr->ph_len>0);
		/*
			(pPkthdr->ph_flags&PKTHDR_DRIVERHOLD) != 0 means :
			
				This packet is held by ROME Driver (ex. it's queued in Driver)
				or held by Tx Ring (ex. Can not be sent immediately due to CPU port were flow controlled.) instead of RxRing.
				And Rx is blocked by this pending packet.

				So we allocate another packet and put it into Rx Ring to solve this problem (done in swNic_rxRunoutTxPending()).
		*/

		if((pPkthdr->ph_flags&PKTHDR_DRIVERHOLD) != 0)
		{
			//exception handling
			swNic_rxRunoutTxPending((struct rtl_pktHdr *)pPkthdr);

			goto out;
		}
		count++;
		//SETBITS(pPkthdr->ph_flags, PKT_INCOMING); //packet from physical port
		assert(pPkthdr->ph_rxdesc == rxPhdrIndex);
		/* pPkthdr->ph_rxdesc=rxPhdrIndex; */
		pPkthdr->ph_flags|=PKTHDR_DRIVERHOLD;	/* this packet is received/processed by Rome Driver or TxRing */


		//Transform extension port numbers to continuous number for fwd engine.

#ifdef CONFIG_RTL865X_MULTILAYER_BSP //Default run this except L2 BSP.
		//must call this API after rxPhdrIndex is assigned...
		if(rtl8651_rxPktPreprocess(pPkthdr)){
			rtlglue_printf("Drop rxDesc=%d\n",rxPhdrIndex );
			//memDump(pPkthdr->ph_mbuf->m_data,  pPkthdr->ph_len,"Loopback Pkt");
#ifdef CONFIG_RTL865XC			
			swNic_isrReclaim(rxPhdrIndex,rxMbufIndex, pPkthdr, pMbuf);
#else			
			swNic_isrReclaim(rxPhdrIndex, pPkthdr, pMbuf);
#endif				
		}else
#endif
		{

#ifdef SWNIC_DEBUG
			//must put after rtl8651_rxPktPreprocess()
			if(nicDbgMesg){
				if((nicDbgMesg==NIC_RX_PKTDUMP)||
					((nicDbgMesg&NIC_PHY_RX_PKTDUMP)&&(pPkthdr->ph_portlist<6))||
					((nicDbgMesg&NIC_EXT_RX_PKTDUMP)&&(pPkthdr->ph_portlist>5))
				){
					rtlglue_printf("NIC Rx [%d] L:%d P%04x s%d e%04x\n", pPkthdr->ph_rxdesc, pPkthdr->ph_len, pPkthdr->ph_portlist, pPkthdr->ph_srcExtPortNum, pPkthdr->ph_extPortList);
					memDump(pMbuf->m_data,pMbuf->m_len>64?64:pMbuf->m_len,"");
				}
			}
#endif
			START_SNIFFING( pPkthdr, 0x00000001 );
			/* Invoked installed function pointer to handle packet */
			(*installedProcessInputPacket)((struct rtl_pktHdr*)pPkthdr);
		}

		//assert(rxPhdrIndex==rxMbufIndex);
		/* Increment index */

		if((flag&32)==0)
		{
			if ( ++rxPhdrIndex5 == totalRxPkthdr5 )
				rxPhdrIndex5 = 0;
		}
		else if((flag&16)==0)
		{

			if ( ++rxPhdrIndex4 == totalRxPkthdr4 )
				rxPhdrIndex4 = 0;
		}
		else if((flag&8)==0)
		{

			if ( ++rxPhdrIndex3 == totalRxPkthdr3 )
				rxPhdrIndex3 = 0;
		}
		else if((flag&4)==0)
		{

			if ( ++rxPhdrIndex2 == totalRxPkthdr2 )
				rxPhdrIndex2 = 0;
		}
		else if((flag&2)==0)
		{

			if ( ++rxPhdrIndex1 == totalRxPkthdr1 )
				rxPhdrIndex1 = 0;
		}
		else if((flag&1)==0)
		{
			if ( ++rxPhdrIndex0 == totalRxPkthdr0 )
				rxPhdrIndex0 = 0;
		}
		
		if ( ++rxMbufIndex0 == totalRxMbuf0 )
			rxMbufIndex0 = 0;

	}while((last0>=0&&rxPhdrIndex0!=last0)||(last1>=0&&rxPhdrIndex1!=last1)||(last2>=0&&rxPhdrIndex2!=last2)||
	(last3>=0&&rxPhdrIndex3!=last3)||(last4>=0&&rxPhdrIndex4!=last4)||(last5>=0&&rxPhdrIndex5!=last5));
out:

	return count;  
#else // for RTL865XB ======================================================================

	volatile struct rtl_pktHdr * pPkthdr; //don't optimize
	volatile struct rtl_mBuf * pMbuf;	//don't optimize
	int32 count=0;
	do{

#ifdef CONFIG_RTL865X_MULTILAYER_BSP
		/* Louis: We shall check per packet to guarantee VoIP realtime process. */
		rtl8651_realtimeSchedule();  //cfliu: check once per interrupt, not per pkt.
#endif

		PROFILING_START(ROMEPERF_INDEX_RECVLOOP);
		/* Increment counter */
		if((RxPkthdrRing[rxPhdrIndex]&DESC_OWNED_BIT)==1){ 
			goto out;
		}
#ifdef SWNIC_EARLYSTOP		
		if(nicRxEarlyStop && ((count & nicRxEarlyStop)==nicRxEarlyStop)){//check global interrupt status
//			uint32 gisrNow = REG32(GISR);
			uint32 gisrNow = READ_MEM32(GISR);
			if(gisrNow & 0x65000000){ //Bit 30: USB, Bit 29:PCMCIA, Bit 26: PCI, Bit 24:GPIO
				nicRxAbort=1;
				goto out;						
			}
		}
#endif		


		pPkthdr = (struct rtl_pktHdr *) (RxPkthdrRing[rxPhdrIndex] & (~(DESC_OWNED_BIT | DESC_WRAP)));
		pMbuf = pPkthdr->ph_mbuf;

#ifdef CONFIG_RTL865XB_EXP_PERFORMANCE_EVALUATION
		if(_pernicStart == TRUE){
			static uint32 start, end;
			if(!_pernicPktCount){
				startCOP3Counters(_pernicInst);
				start = jiffies;
				}
			else if(_pernicPktCount == _pernicPktLimit){
				end = jiffies;
				stopCOP3Counters();
				rtlglue_printf("%d pkts. Total %d bytes, %d ms.  %u KBps\n", _pernicPktCount, _pernicByteCount, (uint32)((end-start)*10), (uint32)(_pernicByteCount/((end-start)*10)));
				_pernicStart = FALSE;
				}
			_pernicPktCount++;
			_pernicByteCount += pPkthdr->ph_len + 4;
#ifdef CONFIG_RTL865XC			
			swNic_isrReclaim(rxPhdrIndex,rxMbufIndex, pPkthdr, pMbuf);
#else			
			swNic_isrReclaim(rxPhdrIndex, pPkthdr, pMbuf);
#endif				
			/* Increment index */
			if ( ++rxPhdrIndex == totalRxPkthdr )
				rxPhdrIndex = 0;
			if ( ++rxMbufIndex == totalRxMbuf )
				rxMbufIndex = 0;
			continue;
			}
#endif

		assert(pPkthdr->ph_len>0);
		/*
			(pPkthdr->ph_flags&PKTHDR_DRIVERHOLD) != 0 means :
			
				This packet is held by ROME Driver (ex. it's queued in Driver)
				or held by Tx Ring (ex. Can not be sent immediately due to CPU port were flow controlled.) instead of RxRing.
				And Rx is blocked by this pending packet.

				So we allocate another packet and put it into Rx Ring to solve this problem (done in swNic_rxRunoutTxPending()).
		*/
		if((pPkthdr->ph_flags&PKTHDR_DRIVERHOLD) != 0)
		{
			//exception handling
			swNic_rxRunoutTxPending((struct rtl_pktHdr *)pPkthdr);
			goto out;
		}
		count++;
		//SETBITS(pPkthdr->ph_flags, PKT_INCOMING); //packet from physical port
		assert(pPkthdr->ph_rxdesc == rxPhdrIndex);
		/* pPkthdr->ph_rxdesc=rxPhdrIndex; */
		pPkthdr->ph_flags|=PKTHDR_DRIVERHOLD;	/* this packet is received/processed by Rome Driver or TxRing */


		//Transform extension port numbers to continuous number for fwd engine.

#ifdef CONFIG_RTL865X_MULTILAYER_BSP //Default run this except L2 BSP.
		//must call this API after rxPhdrIndex is assigned...
		if(rtl8651_rxPktPreprocess(pPkthdr)){
			rtlglue_printf("Drop rxDesc=%d\n",rxPhdrIndex );
			//memDump(pPkthdr->ph_mbuf->m_data,  pPkthdr->ph_len,"Loopback Pkt");
#ifdef CONFIG_RTL865XC			
			swNic_isrReclaim(rxPhdrIndex,rxMbufIndex, pPkthdr, pMbuf);
#else			
			swNic_isrReclaim(rxPhdrIndex, pPkthdr, pMbuf);
#endif	
		}else
#endif
		{

#ifdef SWNIC_DEBUG
			//must put after rtl8651_rxPktPreprocess()
			if(nicDbgMesg){
				if((nicDbgMesg==NIC_RX_PKTDUMP)||
					((nicDbgMesg&NIC_PHY_RX_PKTDUMP)&&(pPkthdr->ph_portlist<6))||
					((nicDbgMesg&NIC_EXT_RX_PKTDUMP)&&(pPkthdr->ph_portlist>5))
				){
					rtlglue_printf("NIC Rx [%d] L:%d P%04x s%d e%04x\n", pPkthdr->ph_rxdesc, pPkthdr->ph_len, pPkthdr->ph_portlist, pPkthdr->ph_srcExtPortNum, pPkthdr->ph_extPortList);
					memDump(pMbuf->m_data,pMbuf->m_len>64?64:pMbuf->m_len,"");
				}
			}
#endif
			START_SNIFFING( pPkthdr, 0x00000001 );
			/* Invoked installed function pointer to handle packet */
			(*installedProcessInputPacket)((struct rtl_pktHdr*)pPkthdr);
		}

		//assert(rxPhdrIndex==rxMbufIndex);
		/* Increment index */
		if ( ++rxPhdrIndex == totalRxPkthdr )
			rxPhdrIndex = 0;
		if ( ++rxMbufIndex == totalRxMbuf )
			rxMbufIndex = 0;
	}while(last>=0&&rxPhdrIndex!=last);
out:
	return count;
#endif	
}

__IRAM_FWD void swNic_rxThread(unsigned long param)
{

#ifdef CONFIG_RTL865XC 

	int32 rxDescIdx0=lastIntRxDescIdx0;
	int32 rxDescIdx1=lastIntRxDescIdx1;
	int32 rxDescIdx2=lastIntRxDescIdx2;
	int32 rxDescIdx3=lastIntRxDescIdx3;
	int32 rxDescIdx4=lastIntRxDescIdx4;
	int32 rxDescIdx5=lastIntRxDescIdx5;	
	int32 latestIdx0,latestIdx1,latestIdx2,latestIdx3,latestIdx4,latestIdx5;
	int32 s;
	uint8 flag=0;
	uint8 goto_next_round=0;
	
	spin_lock_irqsave(rtl865xSpinlock,s);
	

#if 0 /* Louis: We shall check per packet to guarantee VoIP realtime process. */
	rtl8651_timeUpdate(0);  //cfliu: check once per interrupt, not per pkt.
#endif

next_round:

	PROFILING_END(ROMEPERF_INDEX_UNTIL_RXTHREAD);/* start at irq.c:irq_dispatch() */

#ifdef SWNIC_EARLYSTOP	
	nicRxAbort=0;
#endif
	if(rxPhdrIndex0!=rxDescIdx0) flag|=1;
	if(rxPhdrIndex1!=rxDescIdx1) flag|=2;
	if(rxPhdrIndex2!=rxDescIdx2) flag|=4;
	if(rxPhdrIndex3!=rxDescIdx3) flag|=8;
	if(rxPhdrIndex4!=rxDescIdx4) flag|=16;
	if(rxPhdrIndex5!=rxDescIdx5) flag|=32;

	if(flag!=0)
	{
		rxPktCounter+=_swNic_recvLoop(rxDescIdx0,rxDescIdx1,rxDescIdx2,rxDescIdx3,rxDescIdx4,rxDescIdx5);
	}	

	if(rxPhdrIndex5!=rxDescIdx5){
		
#ifdef SWNIC_EARLYSTOP	
		if(!nicRxAbort)
#endif
		{
//			REG32(CPUIIMR)|= RX_DONE_IE;
			WRITE_MEM32(CPUIIMR ,READ_MEM32(CPUIIMR)|RX_DONE_IE5);
			goto out;
		}
	}
	if(rxPhdrIndex4!=rxDescIdx4){
		
#ifdef SWNIC_EARLYSTOP	
		if(!nicRxAbort)
#endif
		{
//			REG32(CPUIIMR)|= RX_DONE_IE;
			WRITE_MEM32(CPUIIMR ,READ_MEM32(CPUIIMR)|RX_DONE_IE4);
			goto out;
		}
	}
	if(rxPhdrIndex3!=rxDescIdx3){
		
#ifdef SWNIC_EARLYSTOP	
		if(!nicRxAbort)
#endif
		{
//			REG32(CPUIIMR)|= RX_DONE_IE;
			WRITE_MEM32(CPUIIMR ,READ_MEM32(CPUIIMR)|RX_DONE_IE3);
			goto out;
		}
	}
	if(rxPhdrIndex2!=rxDescIdx2){
		
#ifdef SWNIC_EARLYSTOP	
		if(!nicRxAbort)
#endif
		{
//			REG32(CPUIIMR)|= RX_DONE_IE;
			WRITE_MEM32(CPUIIMR ,READ_MEM32(CPUIIMR)|RX_DONE_IE2);
			goto out;
		}
	}	
	if(rxPhdrIndex1!=rxDescIdx1){
		
#ifdef SWNIC_EARLYSTOP	
		if(!nicRxAbort)
#endif
		{
//			REG32(CPUIIMR)|= RX_DONE_IE;
			WRITE_MEM32(CPUIIMR ,READ_MEM32(CPUIIMR)|RX_DONE_IE1);
			goto out;
		}
	}	
	if(rxPhdrIndex0!=rxDescIdx0){
#ifdef SWNIC_EARLYSTOP	
		if(!nicRxAbort)
#endif
		{
//			REG32(CPUIIMR)|= RX_DONE_IE;
			WRITE_MEM32(CPUIIMR ,READ_MEM32(CPUIIMR)|RX_DONE_IE0);
			goto out;
		}
	}

//==========================================================================================  	

if((RxPkthdrRing5[rxPhdrIndex5]&DESC_OWNED_BIT)==0) 
{
	//Last one to recv, but see if we can receive again first
//	latestIdx=(uint32 *)REG32(CPURPDCR)-RxPkthdrRing;
	latestIdx5=(uint32 *)READ_MEM32(CPURPDCR5)-RxPkthdrRing5;
	if(latestIdx5-1<0)
		latestIdx5 = totalRxPkthdr5-1;
	else
		latestIdx5-=1;
	
	//Did ASIC recv more pkt since we last see it?
	if(rxDescIdx5!=latestIdx5){
#ifdef SWNIC_EARLYSTOP	
		if(!nicRxAbort)
#endif
		{
			//yes, keep intr closed. we still have more job to do.
			rxDescIdx5=latestIdx5;
			goto_next_round=1;
		}
	}else{
		//No, this is the last to recv.
//		REG32(CPUIIMR)|= RX_DONE_IE;	//enable rx intr before we recv last pkt, in case intr lost.
		WRITE_MEM32(CPUIIMR,READ_MEM32(CPUIIMR)|RX_DONE_IE5);	//enable rx intr before we recv last pkt, in case intr lost.
		rxPktCounter+=_swNic_recvLoop(rxDescIdx0,rxDescIdx1,rxDescIdx2,rxDescIdx3,rxDescIdx4,-1);//just recv one pkt.
	}
}
//==========================================================================================  	
if((RxPkthdrRing4[rxPhdrIndex4]&DESC_OWNED_BIT)==0) 
{
	//Last one to recv, but see if we can receive again first
//	latestIdx=(uint32 *)REG32(CPURPDCR)-RxPkthdrRing;
	latestIdx4=(uint32 *)READ_MEM32(CPURPDCR4)-RxPkthdrRing4;
	if(latestIdx4-1<0)
		latestIdx4 = totalRxPkthdr4-1;
	else
		latestIdx4-=1;
	
	//Did ASIC recv more pkt since we last see it?
	if(rxDescIdx4!=latestIdx4){
#ifdef SWNIC_EARLYSTOP	
		if(!nicRxAbort)
#endif
		{
			//yes, keep intr closed. we still have more job to do.
			rxDescIdx4=latestIdx4;
			goto_next_round=1;
		}
	}else{
		//No, this is the last to recv.
//		REG32(CPUIIMR)|= RX_DONE_IE;	//enable rx intr before we recv last pkt, in case intr lost.
		WRITE_MEM32(CPUIIMR,READ_MEM32(CPUIIMR)|RX_DONE_IE4);	//enable rx intr before we recv last pkt, in case intr lost.
		rxPktCounter+=_swNic_recvLoop(rxDescIdx0,rxDescIdx1,rxDescIdx2,rxDescIdx3,-1,-1);//just recv one pkt.
	}	
}
//==========================================================================================  	
if((RxPkthdrRing3[rxPhdrIndex3]&DESC_OWNED_BIT)==0) 
{

	//Last one to recv, but see if we can receive again first
//	latestIdx=(uint32 *)REG32(CPURPDCR)-RxPkthdrRing;
	latestIdx3=(uint32 *)READ_MEM32(CPURPDCR3)-RxPkthdrRing3;
	if(latestIdx3-1<0)
		latestIdx3 = totalRxPkthdr3-1;
	else
		latestIdx3-=1;
	
	//Did ASIC recv more pkt since we last see it?
	if(rxDescIdx3!=latestIdx3){
#ifdef SWNIC_EARLYSTOP	
		if(!nicRxAbort)
#endif
		{
			//yes, keep intr closed. we still have more job to do.
			rxDescIdx3=latestIdx3;
			goto_next_round=1;
		}
	}else{
		//No, this is the last to recv.
//		REG32(CPUIIMR)|= RX_DONE_IE;	//enable rx intr before we recv last pkt, in case intr lost.
		WRITE_MEM32(CPUIIMR,READ_MEM32(CPUIIMR)|RX_DONE_IE3);	//enable rx intr before we recv last pkt, in case intr lost.
		rxPktCounter+=_swNic_recvLoop(rxDescIdx0,rxDescIdx1,rxDescIdx2,-1,-1,-1);//just recv one pkt.
	}	
}
//==========================================================================================  	

if((RxPkthdrRing2[rxPhdrIndex2]&DESC_OWNED_BIT)==0) 
{
	//Last one to recv, but see if we can receive again first
//	latestIdx=(uint32 *)REG32(CPURPDCR)-RxPkthdrRing;
	latestIdx2=(uint32 *)READ_MEM32(CPURPDCR2)-RxPkthdrRing2;
	if(latestIdx2-1<0)
		latestIdx2 = totalRxPkthdr2-1;
	else
		latestIdx2-=1;
	
	//Did ASIC recv more pkt since we last see it?
	if(rxDescIdx2!=latestIdx2){
#ifdef SWNIC_EARLYSTOP	
		if(!nicRxAbort)
#endif
		{
			//yes, keep intr closed. we still have more job to do.
			rxDescIdx2=latestIdx2;
			goto_next_round=1;
		}
	}else{
		//No, this is the last to recv.
//		REG22(CPUIIMR)|= RX_DONE_IE;	//enable rx intr before we recv last pkt, in case intr lost.
		WRITE_MEM32(CPUIIMR,READ_MEM32(CPUIIMR)|RX_DONE_IE2);	//enable rx intr before we recv last pkt, in case intr lost.
		rxPktCounter+=_swNic_recvLoop(rxDescIdx0,rxDescIdx1,-1,-1,-1,-1);//just recv one pkt.
	}		
}

//==========================================================================================  	

if((RxPkthdrRing1[rxPhdrIndex1]&DESC_OWNED_BIT)==0) 
{
	//Last one to recv, but see if we can receive again first
//	latestIdx=(uint32 *)REG32(CPURPDCR)-RxPkthdrRing;
	latestIdx1=(uint32 *)READ_MEM32(CPURPDCR1)-RxPkthdrRing1;
	if(latestIdx1-1<0)
		latestIdx1 = totalRxPkthdr1-1;
	else
		latestIdx1-=1;
	
	//Did ASIC recv more pkt since we last see it?
	if(rxDescIdx1!=latestIdx1){
#ifdef SWNIC_EARLYSTOP	
		if(!nicRxAbort)
#endif
		{
			//yes, keep intr closed. we still have more job to do.
			rxDescIdx1=latestIdx1;
			goto_next_round=1;
		}
	}else{
		//No, this is the last to recv.
//		REG32(CPUIIMR)|= RX_DONE_IE;	//enable rx intr before we recv last pkt, in case intr lost.
		WRITE_MEM32(CPUIIMR,READ_MEM32(CPUIIMR)|RX_DONE_IE1);	//enable rx intr before we recv last pkt, in case intr lost.
		rxPktCounter+=_swNic_recvLoop(rxDescIdx0,-1,-1,-1,-1,-1);//just recv one pkt.
	}	
}
//==========================================================================================  	
//if((flag&1)==0)
if((RxPkthdrRing0[rxPhdrIndex0]&DESC_OWNED_BIT)==0) 
{
	//Last one to recv, but see if we can receive again first
//	latestIdx=(uint32 *)REG32(CPURPDCR)-RxPkthdrRing;
	latestIdx0=(uint32 *)READ_MEM32(CPURPDCR0)-RxPkthdrRing0;
	if(latestIdx0-1<0)
		latestIdx0 = totalRxPkthdr0-1;
	else
		latestIdx0-=1;
	
	//Did ASIC recv more pkt since we last see it?
	if(rxDescIdx0!=latestIdx0){
#ifdef SWNIC_EARLYSTOP	
		if(!nicRxAbort)
#endif
		{
			//yes, keep intr closed. we still have more job to do.
			rxDescIdx0=latestIdx0;
			goto_next_round=1;
		}
	}else{
		//No, this is the last to recv.
//		REG32(CPUIIMR)|= RX_DONE_IE;	//enable rx intr before we recv last pkt, in case intr lost.
		WRITE_MEM32(CPUIIMR,READ_MEM32(CPUIIMR)|RX_DONE_IE0);	//enable rx intr before we recv last pkt, in case intr lost.
		rxPktCounter+=_swNic_recvLoop(-1,-1,-1,-1,-1,-1);//just recv one pkt.
	}	
	//No more pkts in this run.
}

if(goto_next_round==1) goto next_round;
out:
	
//	if(rxPkthdr_runout==0 &&(REG32(CPUIISR) & PKTHDR_DESC_RUNOUT_IP)){
	if(rxPkthdr_runout==0 &&(READ_MEM32(CPUIISR) & PKTHDR_DESC_RUNOUT_IP_ALL)){
		//Runout occurred during this run. 
//		rxRunoutIdx=(uint32 *)REG32(CPURPDCR)-RxPkthdrRing;

		if(READ_MEM32(CPUIISR) & PKTHDR_DESC_RUNOUT_IP0)
			rxRunoutIdx0=(uint32 *)READ_MEM32(CPURPDCR0)-RxPkthdrRing0;
		else if(READ_MEM32(CPUIISR) & PKTHDR_DESC_RUNOUT_IP1)
			rxRunoutIdx1=(uint32 *)READ_MEM32(CPURPDCR1)-RxPkthdrRing1;
		else if(READ_MEM32(CPUIISR) & PKTHDR_DESC_RUNOUT_IP2)
			rxRunoutIdx2=(uint32 *)READ_MEM32(CPURPDCR2)-RxPkthdrRing2;		
		else if(READ_MEM32(CPUIISR) & PKTHDR_DESC_RUNOUT_IP3)
			rxRunoutIdx3=(uint32 *)READ_MEM32(CPURPDCR3)-RxPkthdrRing3;		
		else if(READ_MEM32(CPUIISR) & PKTHDR_DESC_RUNOUT_IP4)
			rxRunoutIdx4=(uint32 *)READ_MEM32(CPURPDCR4)-RxPkthdrRing4;		
		else if(READ_MEM32(CPUIISR) & PKTHDR_DESC_RUNOUT_IP5)
			rxRunoutIdx5=(uint32 *)READ_MEM32(CPURPDCR5)-RxPkthdrRing5;		
		
		rxPkthdr_runout=1;
		rxPkthdrRunoutNum++;
	}
	if(rxPkthdr_runout==1){		
		//Before we leave, handle runout event again.
		if(txEnable)
			swNic_isrTxRecycle(1,0); //must modify
		if((rxRunoutIdx0<0)||(rxRunoutIdx1<0)||(rxRunoutIdx2<0)||(rxRunoutIdx3<0)||(rxRunoutIdx4<0)||(rxRunoutIdx5<0))
			rxPkthdr_runout=0;
		//reenable runout intr.
//		REG32(CPUIIMR)|=PKTHDR_DESC_RUNOUT_IE;
		WRITE_MEM32(CPUIIMR, READ_MEM32(CPUIIMR) |PKTHDR_DESC_RUNOUT_IE_ALL);
	}

	spin_unlock_irqrestore(rtl865xSpinlock,s);



#else //for RTL865XB =================================================================================================

	int32 rxDescIdx=lastIntRxDescIdx;
	int32 latestIdx;
	int32 s;
	spin_lock_irqsave(rtl865xSpinlock,s);

#if 0 /* Louis: We shall check per packet to guarantee VoIP realtime process. */
	rtl8651_timeUpdate(0);  //cfliu: check once per interrupt, not per pkt.
#endif

next_round:

	PROFILING_END(ROMEPERF_INDEX_UNTIL_RXTHREAD);/* start at irq.c:irq_dispatch() */

#ifdef SWNIC_EARLYSTOP	
	nicRxAbort=0;
#endif
	if(rxPhdrIndex!=rxDescIdx){

		rxPktCounter+=_swNic_recvLoop(rxDescIdx);
	}	

	if(rxPhdrIndex!=rxDescIdx){
		
#ifdef SWNIC_EARLYSTOP	
		if(!nicRxAbort)
#endif
		{
//			REG32(CPUIIMR)|= RX_DONE_IE;
			WRITE_MEM32(CPUIIMR ,READ_MEM32(CPUIIMR)|RX_DONE_IE);
			goto out; //abort in _swNic_recvLoop(). 
		}
	}
	//Last one to recv, but see if we can receive again first
//	latestIdx=(uint32 *)REG32(CPURPDCR)-RxPkthdrRing;
	latestIdx=(uint32 *)READ_MEM32(CPURPDCR)-RxPkthdrRing;
	if(latestIdx-1<0)
		latestIdx = totalRxPkthdr-1;
	else
		latestIdx-=1;
	
	//Did ASIC recv more pkt since we last see it?
	if(rxDescIdx!=latestIdx){
#ifdef SWNIC_EARLYSTOP	
		if(!nicRxAbort)
#endif
		{
			//yes, keep intr closed. we still have more job to do.
			rxDescIdx=latestIdx;
			goto next_round;
		}
	}else{
		//No, this is the last to recv.
//		REG32(CPUIIMR)|= RX_DONE_IE;	//enable rx intr before we recv last pkt, in case intr lost.
		WRITE_MEM32(CPUIIMR,READ_MEM32(CPUIIMR)|RX_DONE_IE);	//enable rx intr before we recv last pkt, in case intr lost.

		rxPktCounter+=_swNic_recvLoop(-1);//just recv one pkt.
	}	
	//No more pkts in this run.

out:
	
//	if(rxPkthdr_runout==0 &&(REG32(CPUIISR) & PKTHDR_DESC_RUNOUT_IP)){
	if(rxPkthdr_runout==0 &&(READ_MEM32(CPUIISR) & PKTHDR_DESC_RUNOUT_IP)){
		//Runout occurred during this run. 
//		rxRunoutIdx=(uint32 *)REG32(CPURPDCR)-RxPkthdrRing;
		rxRunoutIdx=(uint32 *)READ_MEM32(CPURPDCR)-RxPkthdrRing;
		rxPkthdr_runout=1;
		rxPkthdrRunoutNum++;
	}
	if(rxPkthdr_runout==1){
		//Before we leave, handle runout event again.
		if(txEnable)
			swNic_isrTxRecycle(1);
		if(rxRunoutIdx<0)
			rxPkthdr_runout=0;
		//reenable runout intr.
//		REG32(CPUIIMR)|=PKTHDR_DESC_RUNOUT_IE;
		WRITE_MEM32(CPUIIMR, READ_MEM32(CPUIIMR) |PKTHDR_DESC_RUNOUT_IE);
	}
	spin_unlock_irqrestore(rtl865xSpinlock,s);

#endif
}
	


#ifdef CONFIG_RTL865XC 
__IRAM_FWD int32 swNic_isrReclaim(uint32 rxDescIdx,uint32 mbufDescIdx, struct rtl_pktHdr*pPkthdr,struct rtl_mBuf *pMbuf){

	int32 retval=FAILED;
	uint8 QueueID,descriptRing=0;

	QueueID=(pPkthdr->ph_flags & PKTHDR_QUEUE_ID)>>11;

	if(pPkthdr->ph_srcExtPortNum==0) //to CPU
		descriptRing=(READ_MEM16(CPUQDM0+QueueID*2)>>12)&0x7;
	else if(pPkthdr->ph_srcExtPortNum==1) //to Ext1
		descriptRing=(READ_MEM16(CPUQDM0+QueueID*2)>>8)&0x7;
	else if(pPkthdr->ph_srcExtPortNum==2) //to Ext2
		descriptRing=(READ_MEM16(CPUQDM0+QueueID*2)>>4)&0x7;
	else if(pPkthdr->ph_srcExtPortNum==3) //to Ext3
		descriptRing=READ_MEM16(CPUQDM0+QueueID*2)&0x7;	

	pPkthdr->ph_len = pMbuf->m_len =0;	//reset pkt length.
	pPkthdr->ph_srcExtPortNum=pPkthdr->ph_extPortList=pPkthdr->ph_portlist=0;

//	assert(!(RxMbufRing0[mbufDescIdx] & DESC_SWCORE_OWNED)); 

	if(descriptRing==5)
	{
		if(rxDescIdx<totalRxPkthdr5){

			pPkthdr->ph_flags&=~PKTHDR_DRIVERHOLD;	/* we put this packet back to RxRing, so we clear the flag to indicate it */

			assert(!(RxPkthdrRing5[rxDescIdx] & DESC_SWCORE_OWNED));

			
#if defined(CONFIG_RTL865X_MBUF_HEADROOM)&&defined(CONFIG_RTL865X_MULTILAYER_BSP)
			//reset data pointer and reserve header room.
			pMbuf->m_data=pMbuf->m_extbuf +CONFIG_RTL865X_MBUF_HEADROOM;
#else
			pPkthdr->ph_mbuf->m_data = pPkthdr->ph_mbuf->m_extbuf;	//recover buffer pointer
#endif
			/* Reclaim packet header and mbuf descriptors. reset OWN bit */
			RxMbufRing0[mbufDescIdx] |= DESC_SWCORE_OWNED;

			wmb();
			RxPkthdrRing5[rxDescIdx] |= DESC_SWCORE_OWNED;
			wmb();
			lastReclaim5=rxDescIdx;
			retval=SUCCESS;
		}else{
			//cfliu: All pkthdrs index is by default "totalRxPkthdr", not -1 anymore
#ifdef AIRGO_FAST_PATH
			  if (pPkthdr->ph_reserved == AIRGO_MAGIC)
			  {
				pPkthdr->ph_reserved = 0;
				pPkthdr->ph_mbuf->m_next = 0;
				mBuf_freeOne(pPkthdr->ph_mbuf);
			  }else
#endif
			{
				pPkthdr->ph_flags|=PKTHDR_DRIVERHOLD;
				pPkthdr->ph_rxdesc = totalRxPkthdr5;
				pPkthdr->ph_rxmbufdesc = totalRxMbuf0;
			}
		}
	}

	else if(descriptRing==4)
	{
		if(rxDescIdx<totalRxPkthdr4){

			pPkthdr->ph_flags&=~PKTHDR_DRIVERHOLD;	/* we put this packet back to RxRing, so we clear the flag to indicate it */

			assert(!(RxPkthdrRing4[rxDescIdx] & DESC_SWCORE_OWNED));

			
#if defined(CONFIG_RTL865X_MBUF_HEADROOM)&&defined(CONFIG_RTL865X_MULTILAYER_BSP)
			//reset data pointer and reserve header room.
			pMbuf->m_data=pMbuf->m_extbuf +CONFIG_RTL865X_MBUF_HEADROOM;
#else
			pPkthdr->ph_mbuf->m_data = pPkthdr->ph_mbuf->m_extbuf;	//recover buffer pointer
#endif
			/* Reclaim packet header and mbuf descriptors. reset OWN bit */
			RxMbufRing0[mbufDescIdx] |= DESC_SWCORE_OWNED;
			wmb();
			RxPkthdrRing4[rxDescIdx] |= DESC_SWCORE_OWNED;
			wmb();
			lastReclaim4=rxDescIdx;
			retval=SUCCESS;
		}else{
			//cfliu: All pkthdrs index is by default "totalRxPkthdr", not -1 anymore
#ifdef AIRGO_FAST_PATH
			  if (pPkthdr->ph_reserved == AIRGO_MAGIC)
			  {
				pPkthdr->ph_reserved = 0;
				pPkthdr->ph_mbuf->m_next = 0;
				mBuf_freeOne(pPkthdr->ph_mbuf);
			  }else
#endif
			{
				pPkthdr->ph_flags|=PKTHDR_DRIVERHOLD;
				pPkthdr->ph_rxdesc = totalRxPkthdr4;
				pPkthdr->ph_rxmbufdesc = totalRxMbuf0;				
			}
		}
	}

	else if(descriptRing==3)
	{
		if(rxDescIdx<totalRxPkthdr3){

			pPkthdr->ph_flags&=~PKTHDR_DRIVERHOLD;	/* we put this packet back to RxRing, so we clear the flag to indicate it */

			assert(!(RxPkthdrRing3[rxDescIdx] & DESC_SWCORE_OWNED));
			
#if defined(CONFIG_RTL865X_MBUF_HEADROOM)&&defined(CONFIG_RTL865X_MULTILAYER_BSP)
			//reset data pointer and reserve header room.
			pMbuf->m_data=pMbuf->m_extbuf +CONFIG_RTL865X_MBUF_HEADROOM;
#else
			pPkthdr->ph_mbuf->m_data = pPkthdr->ph_mbuf->m_extbuf;	//recover buffer pointer
#endif
			/* Reclaim packet header and mbuf descriptors. reset OWN bit */
			RxMbufRing0[mbufDescIdx] |= DESC_SWCORE_OWNED;
			wmb();
			RxPkthdrRing3[rxDescIdx] |= DESC_SWCORE_OWNED;
			wmb();
			lastReclaim3=rxDescIdx;
			retval=SUCCESS;
		}else{
			//cfliu: All pkthdrs index is by default "totalRxPkthdr", not -1 anymore
#ifdef AIRGO_FAST_PATH
			  if (pPkthdr->ph_reserved == AIRGO_MAGIC)
			  {
				pPkthdr->ph_reserved = 0;
				pPkthdr->ph_mbuf->m_next = 0;
				mBuf_freeOne(pPkthdr->ph_mbuf);
			  }else
#endif
			{
				pPkthdr->ph_flags|=PKTHDR_DRIVERHOLD;
				pPkthdr->ph_rxdesc = totalRxPkthdr3;
				pPkthdr->ph_rxmbufdesc = totalRxMbuf0;				
			}
		}
	}
	
	else if(descriptRing==2)
	{
		if(rxDescIdx<totalRxPkthdr2){

			pPkthdr->ph_flags&=~PKTHDR_DRIVERHOLD;	/* we put this packet back to RxRing, so we clear the flag to indicate it */

			assert(!(RxPkthdrRing2[rxDescIdx] & DESC_SWCORE_OWNED));

			
#if defined(CONFIG_RTL865X_MBUF_HEADROOM)&&defined(CONFIG_RTL865X_MULTILAYER_BSP)
			//reset data pointer and reserve header room.
			pMbuf->m_data=pMbuf->m_extbuf +CONFIG_RTL865X_MBUF_HEADROOM;
#else
			pPkthdr->ph_mbuf->m_data = pPkthdr->ph_mbuf->m_extbuf;	//recover buffer pointer
#endif
			/* Reclaim packet header and mbuf descriptors. reset OWN bit */
			RxMbufRing0[mbufDescIdx] |= DESC_SWCORE_OWNED;
			wmb();
			RxPkthdrRing2[rxDescIdx] |= DESC_SWCORE_OWNED;
			wmb();
			lastReclaim2=rxDescIdx;
			retval=SUCCESS;
		}else{
			//cfliu: All pkthdrs index is by default "totalRxPkthdr", not -1 anymore
#ifdef AIRGO_FAST_PATH
			  if (pPkthdr->ph_reserved == AIRGO_MAGIC)
			  {
				pPkthdr->ph_reserved = 0;
				pPkthdr->ph_mbuf->m_next = 0;
				mBuf_freeOne(pPkthdr->ph_mbuf);
			  }else
#endif
			{
				pPkthdr->ph_flags|=PKTHDR_DRIVERHOLD;
				pPkthdr->ph_rxdesc = totalRxPkthdr2;
				pPkthdr->ph_rxmbufdesc = totalRxMbuf0;				
			}
		}
	}

	else if(descriptRing==1)
	{
		if(rxDescIdx<totalRxPkthdr1){

			pPkthdr->ph_flags&=~PKTHDR_DRIVERHOLD;	/* we put this packet back to RxRing, so we clear the flag to indicate it */

			assert(!(RxPkthdrRing1[rxDescIdx] & DESC_SWCORE_OWNED));

			
#if defined(CONFIG_RTL865X_MBUF_HEADROOM)&&defined(CONFIG_RTL865X_MULTILAYER_BSP)
			//reset data pointer and reserve header room.
			pMbuf->m_data=pMbuf->m_extbuf +CONFIG_RTL865X_MBUF_HEADROOM;
#else
			pPkthdr->ph_mbuf->m_data = pPkthdr->ph_mbuf->m_extbuf;	//recover buffer pointer
#endif
			/* Reclaim packet header and mbuf descriptors. reset OWN bit */
			RxMbufRing0[mbufDescIdx] |= DESC_SWCORE_OWNED;
			wmb();
			RxPkthdrRing1[rxDescIdx] |= DESC_SWCORE_OWNED;
			wmb();
			lastReclaim1=rxDescIdx;
			retval=SUCCESS;
		}else{
			//cfliu: All pkthdrs index is by default "totalRxPkthdr", not -1 anymore
#ifdef AIRGO_FAST_PATH
			  if (pPkthdr->ph_reserved == AIRGO_MAGIC)
			  {
				pPkthdr->ph_reserved = 0;
				pPkthdr->ph_mbuf->m_next = 0;
				mBuf_freeOne(pPkthdr->ph_mbuf);
			  }else
#endif
			{
				pPkthdr->ph_flags|=PKTHDR_DRIVERHOLD;
				pPkthdr->ph_rxdesc = totalRxPkthdr1;
				pPkthdr->ph_rxmbufdesc = totalRxMbuf0;				
			}
		}
	}	

	else if(descriptRing==0)
	{
		if(rxDescIdx<totalRxPkthdr0){

			pPkthdr->ph_flags&=~PKTHDR_DRIVERHOLD;	/* we put this packet back to RxRing, so we clear the flag to indicate it */

			assert(!(RxPkthdrRing0[rxDescIdx] & DESC_SWCORE_OWNED));

			
#if defined(CONFIG_RTL865X_MBUF_HEADROOM)&&defined(CONFIG_RTL865X_MULTILAYER_BSP)
			//reset data pointer and reserve header room.
			pMbuf->m_data=pMbuf->m_extbuf +CONFIG_RTL865X_MBUF_HEADROOM;
#else
			pPkthdr->ph_mbuf->m_data = pPkthdr->ph_mbuf->m_extbuf;	//recover buffer pointer
#endif
			/* Reclaim packet header and mbuf descriptors. reset OWN bit */
			RxMbufRing0[mbufDescIdx] |= DESC_SWCORE_OWNED;
			wmb();
			RxPkthdrRing0[rxDescIdx] |= DESC_SWCORE_OWNED;
			wmb();
			lastReclaim0=rxDescIdx;
			retval=SUCCESS;
		}else{
			//cfliu: All pkthdrs index is by default "totalRxPkthdr", not -1 anymore
#ifdef AIRGO_FAST_PATH
			  if (pPkthdr->ph_reserved == AIRGO_MAGIC)
			  {
				pPkthdr->ph_reserved = 0;
				pPkthdr->ph_mbuf->m_next = 0;
				mBuf_freeOne(pPkthdr->ph_mbuf);
			  }else
#endif
			{
				pPkthdr->ph_flags|=PKTHDR_DRIVERHOLD;
				pPkthdr->ph_rxdesc = totalRxPkthdr0;
				pPkthdr->ph_rxmbufdesc = totalRxMbuf0;				
			}
		}
	}

	
	return retval;
	//rtlglue_printf("%d ",rxDescIdx);
}
#else //for RTL865XB ===============================================================================================
__IRAM_FWD int32 swNic_isrReclaim(uint32 rxDescIdx, struct rtl_pktHdr*pPkthdr,struct rtl_mBuf *pMbuf){
	int32 retval=FAILED;


	pPkthdr->ph_len = pMbuf->m_len =0;	//reset pkt length.
	pPkthdr->ph_srcExtPortNum=pPkthdr->ph_extPortList=pPkthdr->ph_portlist=0;

	if(rxDescIdx<totalRxPkthdr){

		pPkthdr->ph_flags&=~PKTHDR_DRIVERHOLD;	/* we put this packet back to RxRing, so we clear the flag to indicate it */

		assert(!(RxPkthdrRing[rxDescIdx] & DESC_SWCORE_OWNED));
		assert(!(RxMbufRing[rxDescIdx] & DESC_SWCORE_OWNED));
		
#if defined(CONFIG_RTL865X_MBUF_HEADROOM)&&defined(CONFIG_RTL865X_MULTILAYER_BSP)
		//reset data pointer and reserve header room.
		pMbuf->m_data=pMbuf->m_extbuf +CONFIG_RTL865X_MBUF_HEADROOM;
#else
		pPkthdr->ph_mbuf->m_data = pPkthdr->ph_mbuf->m_extbuf;	//recover buffer pointer
#endif
		/* Reclaim packet header and mbuf descriptors. reset OWN bit */
		RxMbufRing[rxDescIdx] |= DESC_SWCORE_OWNED;
		wmb();
		RxPkthdrRing[rxDescIdx] |= DESC_SWCORE_OWNED;
		wmb();
		lastReclaim=rxDescIdx;
		retval=SUCCESS;
	}else{
		//cfliu: All pkthdrs index is by default "totalRxPkthdr", not -1 anymore
#ifdef AIRGO_FAST_PATH
		  if (pPkthdr->ph_reserved == AIRGO_MAGIC)
		  {
			pPkthdr->ph_reserved = 0;
			pPkthdr->ph_mbuf->m_next = 0;
			mBuf_freeOne(pPkthdr->ph_mbuf);
		  }else
#endif
		{
			pPkthdr->ph_flags|=PKTHDR_DRIVERHOLD;
			pPkthdr->ph_rxdesc = totalRxPkthdr;
		}
	}
	
	return retval;
	//rtlglue_printf("%d ",rxDescIdx);
}
#endif
#ifdef CONFIG_RTL865XC 
void swNic_isrTxRecycle(int32 flag,int8 whichDesc)
{
	struct rtl_pktHdr *     pPkthdr;
	int32 rxDescIdx,rxMbufIdx=0;
	struct rtl_mBuf *pMbuf;
	
	/* Continuously check OWN bit of descriptors */

	if(whichDesc==1)
	{
		while ( ((TxPkthdrRing1[txDoneIndex1] & DESC_OWNED_BIT) == DESC_RISC_OWNED)&&txDoneIndex1!=txFreeIndex1){
			/* Fetch pkthdr */
			pPkthdr = (struct rtl_pktHdr *) (TxPkthdrRing1[txDoneIndex1] & ~(DESC_OWNED_BIT | DESC_WRAP));
			pMbuf = pPkthdr->ph_mbuf;
			rxDescIdx = pPkthdr->ph_rxdesc;
			rxMbufIdx = pPkthdr->ph_rxmbufdesc; 

#ifdef AIRGO_FAST_PATH

#ifdef AIRGO_NEW
			if (pMbuf->m_unused1 == 0x66)
			{
				pMbuf->m_unused1 = 0;
				if (airgo_free)
				{
					(*airgo_free)(pPkthdr);
				}
			} else
#else
			if ((pMbuf->m_unused1==0x66)&&(airgo_free))
			{
				//was from Airgo driver. Reclaim the buffer back to Airgo driver's internal pool
				(*airgo_free)(pPkthdr);
			} 
			else 
#endif

#endif

			if((rxDescIdx<0)||(rxDescIdx>=totalRxPkthdr1)){
				int32 retval;
				pPkthdr->ph_rxdesc=-1;
				pPkthdr->ph_rxmbufdesc = -1;
				//was sent directly from protocol stack.

			       retval= mBuf_driverFreeMbufChain(pPkthdr->ph_mbuf);
			}else {

				//otherwise, recycle buffer to Rx ring.
#ifdef CONFIG_RTL865XC				
				swNic_isrReclaim(rxDescIdx, rxMbufIdx, pPkthdr,pMbuf);
#else
				swNic_isrReclaim(rxDescIdx, pPkthdr,pMbuf);
#endif				
			}		
			TxPkthdrRing1[txDoneIndex1]&=DESC_WRAP; //this clears Tx desc but keeps WRAP bit if any.
			wmb();		
			txPktCounter++;

			/* Increment index */
			if ( ++txDoneIndex1 == totalTxPkthdr1 )
				txDoneIndex1 = 0;
		}
		
		
	}
	else //whichDesc==0
	{
		while ( ((TxPkthdrRing0[txDoneIndex0] & DESC_OWNED_BIT) == DESC_RISC_OWNED)&&txDoneIndex0!=txFreeIndex0){
			/* Fetch pkthdr */
			pPkthdr = (struct rtl_pktHdr *) (TxPkthdrRing0[txDoneIndex0] & ~(DESC_OWNED_BIT | DESC_WRAP));
			pMbuf = pPkthdr->ph_mbuf;
			rxDescIdx = pPkthdr->ph_rxdesc;
			rxMbufIdx = pPkthdr->ph_rxmbufdesc; 

#ifdef AIRGO_FAST_PATH

#ifdef AIRGO_NEW
			if (pMbuf->m_unused1 == 0x66)
			{
				pMbuf->m_unused1 = 0;
				if (airgo_free)
				{
					(*airgo_free)(pPkthdr);
				}
			} else
#else
			if ((pMbuf->m_unused1==0x66)&&(airgo_free))
			{
				//was from Airgo driver. Reclaim the buffer back to Airgo driver's internal pool
				(*airgo_free)(pPkthdr);
			} 
			else 
#endif

#endif

			if((rxDescIdx<0)||(rxDescIdx>=totalRxPkthdr0)){
				int32 retval;
				pPkthdr->ph_rxdesc=-1;
				pPkthdr->ph_rxmbufdesc =-1;
				//was sent directly from protocol stack.
			       retval= mBuf_driverFreeMbufChain(pPkthdr->ph_mbuf);
			}else {
				//otherwise, recycle buffer to Rx ring.
#ifdef CONFIG_RTL865XC				
				swNic_isrReclaim(rxDescIdx, rxMbufIdx, pPkthdr,pMbuf);
#else
				swNic_isrReclaim(rxDescIdx, pPkthdr,pMbuf);
#endif				
			}		
			TxPkthdrRing0[txDoneIndex0]&=DESC_WRAP; //this clears Tx desc but keeps WRAP bit if any.
			wmb();		
			txPktCounter++;

			/* Increment index */
			if ( ++txDoneIndex0== totalTxPkthdr0 )
				txDoneIndex0 = 0;
		}
		

	}

	if(rxRunoutIdx5>=0&&(RxPkthdrRing5[rxRunoutIdx5] & DESC_OWNED_BIT) != DESC_RISC_OWNED){
		rxPkthdrRunoutSolved++;
		rxRunoutIdx5=-1;
	}
	if(rxRunoutIdx4>=0&&(RxPkthdrRing4[rxRunoutIdx4] & DESC_OWNED_BIT) != DESC_RISC_OWNED){
		rxPkthdrRunoutSolved++;
		rxRunoutIdx4=-1;
	}
	if(rxRunoutIdx3>=0&&(RxPkthdrRing3[rxRunoutIdx3] & DESC_OWNED_BIT) != DESC_RISC_OWNED){
		rxPkthdrRunoutSolved++;
		rxRunoutIdx3=-1;
	}
	if(rxRunoutIdx2>=0&&(RxPkthdrRing2[rxRunoutIdx2] & DESC_OWNED_BIT) != DESC_RISC_OWNED){
		rxPkthdrRunoutSolved++;
		rxRunoutIdx2=-1;
	}
	if(rxRunoutIdx1>=0&&(RxPkthdrRing1[rxRunoutIdx1] & DESC_OWNED_BIT) != DESC_RISC_OWNED){
		rxPkthdrRunoutSolved++;
		rxRunoutIdx1=-1;
	}
	if(rxRunoutIdx0>=0&&(RxPkthdrRing0[rxRunoutIdx0] & DESC_OWNED_BIT) != DESC_RISC_OWNED){
		rxPkthdrRunoutSolved++;
		rxRunoutIdx0=-1;
	}
}

#else // For RTL865XB  ==========================================================================================
void swNic_isrTxRecycle(int32 flag)
{


	struct rtl_pktHdr *     pPkthdr;
	int32 rxDescIdx;
	struct rtl_mBuf *pMbuf;
	/* Continuously check OWN bit of descriptors */
	while ( ((TxPkthdrRing[txDoneIndex] & DESC_OWNED_BIT) == DESC_RISC_OWNED)&&txDoneIndex!=txFreeIndex){
		/* Fetch pkthdr */
		pPkthdr = (struct rtl_pktHdr *) (TxPkthdrRing[txDoneIndex] & ~(DESC_OWNED_BIT | DESC_WRAP));
		pMbuf = pPkthdr->ph_mbuf;
		rxDescIdx = pPkthdr->ph_rxdesc;
#ifdef AIRGO_FAST_PATH

#ifdef AIRGO_NEW
		if (pMbuf->m_unused1 == 0x66)
		{
			pMbuf->m_unused1 = 0;
			if (airgo_free)
			{
				(*airgo_free)(pPkthdr);
			}
		} else
#else
		if ((pMbuf->m_unused1==0x66)&&(airgo_free))
		{
			//was from Airgo driver. Reclaim the buffer back to Airgo driver's internal pool
			(*airgo_free)(pPkthdr);
		} 
		else 
#endif

#endif
		if((rxDescIdx<0)||(rxDescIdx>=totalRxPkthdr)){
			int32 retval;
			pPkthdr->ph_rxdesc=-1;
			//was sent directly from protocol stack.
		       retval= mBuf_driverFreeMbufChain(pPkthdr->ph_mbuf);
		}else {
			//otherwise, recycle buffer to Rx ring.
			swNic_isrReclaim(rxDescIdx, pPkthdr,pMbuf);
		}		
		TxPkthdrRing[txDoneIndex]&=DESC_WRAP; //this clears Tx desc but keeps WRAP bit if any.
		wmb();		
		txPktCounter++;

		/* Increment index */
		if ( ++txDoneIndex == totalTxPkthdr )
			txDoneIndex = 0;
	}
	if(rxRunoutIdx>=0&&(RxPkthdrRing[rxRunoutIdx] & DESC_OWNED_BIT) != DESC_RISC_OWNED){
		rxPkthdrRunoutSolved++;
		rxRunoutIdx=-1;
	}

}
#endif


#ifdef CONFIG_RTL865XC
__IRAM_FWD int32 swNic_write(void * output)

{
    	struct rtl_pktHdr * pPkt = (struct rtl_pktHdr *) output;
	struct rtl_mBuf	*pMbuf=pPkt->ph_mbuf;
	uint32 len=pPkt->ph_len;
//	int32 rxDescIdx;
	int32 s;

	PROFILING_START(ROMEPERF_INDEX_12);
	spin_lock_irqsave(rtl865xSpinlock,s);
	if(!txEnable){ //Tx is not enabled now
		spin_unlock_irqrestore(rtl865xSpinlock,s);

#ifdef AIRGO_FAST_PATH
#ifdef AIRGO_NEW
		if (pMbuf->m_unused1==0x66)
		{
			pMbuf->m_unused1 = 0;
			if (airgo_free)
			{
				(*airgo_free)(pPkt);
				return SUCCESS;
			}
		}
#else
		if ((pMbuf->m_unused1==0x66)&&(airgo_free)) {
			(*airgo_free)(pPkt);
			//rtlglue_printf("tx disable\n");
			return SUCCESS;
		}
#endif
#endif
		return FAILED;
	}

	PROFILING_END(ROMEPERF_INDEX_12);

#ifdef CONFIG_RTL865X_MULTILAYER_BSP
	PROFILING_START(ROMEPERF_INDEX_13);

	rtl8651_txPktPostProcessing(pPkt);
	PROFILING_END(ROMEPERF_INDEX_13);
#endif

	PROFILING_START(ROMEPERF_INDEX_14);

	if(len <60 && mBuf_padding(pMbuf, 60-len, MBUF_DONTWAIT)==NULL)
	{		
		spin_unlock_irqrestore(rtl865xSpinlock,s);

#ifdef AIRGO_FAST_PATH
#ifdef AIRGO_NEW
		if (pMbuf->m_unused1 == 0x66)
		{
			pMbuf->m_unused1 = 0;
			if (airgo_free)
			{
				(*airgo_free)(pPkt);
				return SUCCESS;
			}
		}
#else
		if ((pMbuf->m_unused1==0x66)&&(airgo_free)) {
			(*airgo_free)(pPkt);
			//rtlglue_printf("tx disabletoo short\n");

			return SUCCESS;
		}
#endif
#endif

		return FAILED;
	}
   	assert(pPkt->ph_len>=60);

	PROFILING_END(ROMEPERF_INDEX_14);
	PROFILING_START(ROMEPERF_INDEX_15);

	if(nicTxAlignFix)
		_nicTxAlignFix(pPkt,pMbuf);

	//rtlglue_printf("len[%d] rx[%d] plist[%x] sepn[%d] espl[%x]\n", pPkt->ph_len, pPkt->ph_rxdesc, pPkt->ph_portlist, pPkt->ph_srcExtPortNum, pPkt->ph_extPortList);

	pPkt->ph_nextHdr = (struct rtl_pktHdr *) NULL;
//	rxDescIdx=pPkt->ph_rxdesc;


	if((pPkt->ph_flags&PKTHDR_QUEUE_ID)==0x800)
	{

		if(TxPkthdrDescFull1){
			PROFILING_START(ROMEPERF_INDEX_16);

			swNic_isrTxRecycle(0,1);//force reclaim Tx descriptors if any.

			PROFILING_END(ROMEPERF_INDEX_16);

			if(TxPkthdrDescFull1){//check again, if still full, drop the pkt.
	//			if((rxDescIdx>=0)&&(rxDescIdx<totalRxPkthdr))
	//				swNic_isrReclaim(rxDescIdx,  pPkt, pMbuf);//pkt was rcvd from network. free it..

				spin_unlock_irqrestore(rtl865xSpinlock,s);

#ifdef AIRGO_FAST_PATH
#ifdef AIRGO_NEW
			if (pMbuf->m_unused1 == 0x66)
			{
				pMbuf->m_unused1 = 0;
				if (airgo_free)
				{
					(*airgo_free)(pPkt);
					return SUCCESS;
				}
			}
#else
			if ((pMbuf->m_unused1==0x66)&&(airgo_free)) {
				(*airgo_free)(pPkt);
				//rtlglue_printf("tx disabletoo short\n");
				return SUCCESS;
			}
#endif
#endif
				return FAILED;
			}
		}

	}
	else
	{
		if(TxPkthdrDescFull0){
			PROFILING_START(ROMEPERF_INDEX_16);
			swNic_isrTxRecycle(0,0);//force reclaim Tx descriptors if any.
			PROFILING_END(ROMEPERF_INDEX_16);

			if(TxPkthdrDescFull0){//check again, if still full, drop the pkt.
	//			if((rxDescIdx>=0)&&(rxDescIdx<totalRxPkthdr))
	//				swNic_isrReclaim(rxDescIdx,  pPkt, pMbuf);//pkt was rcvd from network. free it..

				spin_unlock_irqrestore(rtl865xSpinlock,s);

#ifdef AIRGO_FAST_PATH
#ifdef AIRGO_NEW
			if (pMbuf->m_unused1 == 0x66)
			{
				pMbuf->m_unused1 = 0;
				if (airgo_free)
				{
					(*airgo_free)(pPkt);
					return SUCCESS;
				}
			}
#else
			if ((pMbuf->m_unused1==0x66)&&(airgo_free)) {
				(*airgo_free)(pPkt);
				//rtlglue_printf("tx disabletoo short\n");
				return SUCCESS;
			}
#endif
#endif
				return FAILED;
			}
		}
	}
	START_SNIFFING( pPkt, 0x00000002 );

	//yes, we have a Tx desc fro sending this pkt.
	//mark desc as swcore own to send the packet...
	//printfByPolling("T%d ,",txFreeIndex);	

	if((pPkt->ph_flags&PKTHDR_QUEUE_ID)==0x800)
	{
	      TxPkthdrRing1[txFreeIndex1]|=((uint32)pPkt|DESC_OWNED_BIT);
		wmb();
		lastTxIndex1=txFreeIndex1;
		txFreeIndex1++;
		txFreeIndex1&=(1<<totalTxPkthdrShift1)-1;		  
	}
	else
	{
	      TxPkthdrRing0[txFreeIndex0]|=((uint32)pPkt|DESC_OWNED_BIT);
		wmb();
		lastTxIndex0=txFreeIndex0;
		txFreeIndex0++;
		txFreeIndex0&=(1<<totalTxPkthdrShift0)-1;		  
	}
	spin_unlock_irqrestore(rtl865xSpinlock,s);

#ifdef SWNIC_DEBUG
	if(nicDbgMesg){
		if((nicDbgMesg==NIC_TX_PKTDUMP)||
			((nicDbgMesg&NIC_PHY_TX_PKTDUMP)&&(pPkt->ph_srcExtPortNum==0))||
			((nicDbgMesg&NIC_EXT_TX_PKTDUMP)&&(pPkt->ph_srcExtPortNum))
		){
			rtlglue_printf("NIC Tx [%d] L:%d P%04x s%d e%04x\n", pPkt->ph_rxdesc, pPkt->ph_len, pPkt->ph_portlist, pPkt->ph_srcExtPortNum, pPkt->ph_extPortList);
			memDump(pMbuf->m_data,pMbuf->m_len>64?64:pMbuf->m_len,"");
		}
	}
#endif
//printk("%s %d portlist=%x srcextportnum=%x extPortlist=%x vlanidx=%x vlanTagged=%x flags=%x\n\n",__FUNCTION__,__LINE__,pPkt->ph_portlist,pPkt->ph_srcExtPortNum,pPkt->ph_extPortList,pPkt->ph_vlanIdx,pPkt->ph_vlanTagged,pPkt->ph_flags);	

//	REG32(CPUICR) |= TXFD;
#ifdef RTL865X_MODEL_USER
#else
	WRITE_MEM32(CPUICR , READ_MEM32(CPUICR) | TXFD );
#endif

	PROFILING_END(ROMEPERF_INDEX_15);
	return SUCCESS;
}
#else // RTL865XB =================================================================================================
__IRAM_FWD int32 swNic_write(void * output)
{
    	struct rtl_pktHdr * pPkt = (struct rtl_pktHdr *) output;
	struct rtl_mBuf	*pMbuf=pPkt->ph_mbuf;
	uint32 len=pPkt->ph_len;
	int32 rxDescIdx;
	int32 s;

	PROFILING_START(ROMEPERF_INDEX_12);
	spin_lock_irqsave(rtl865xSpinlock,s);
	if(!txEnable){ //Tx is not enabled now
		spin_unlock_irqrestore(rtl865xSpinlock,s);

#ifdef AIRGO_FAST_PATH
#ifdef AIRGO_NEW
		if (pMbuf->m_unused1==0x66)
		{
			pMbuf->m_unused1 = 0;
			if (airgo_free)
			{
				(*airgo_free)(pPkt);
				return SUCCESS;
			}
		}
#else
		if ((pMbuf->m_unused1==0x66)&&(airgo_free)) {
			(*airgo_free)(pPkt);
			//rtlglue_printf("tx disable\n");
			return SUCCESS;
		}
#endif
#endif
		return FAILED;
	}

	PROFILING_END(ROMEPERF_INDEX_12);

#ifdef CONFIG_RTL865X_MULTILAYER_BSP
	PROFILING_START(ROMEPERF_INDEX_13);

	rtl8651_txPktPostProcessing(pPkt);
	PROFILING_END(ROMEPERF_INDEX_13);
#endif

	PROFILING_START(ROMEPERF_INDEX_14);

	if(len <60 && mBuf_padding(pMbuf, 60-len, MBUF_DONTWAIT)==NULL)
	{		
		spin_unlock_irqrestore(rtl865xSpinlock,s);

#ifdef AIRGO_FAST_PATH

#ifdef AIRGO_NEW
		if (pMbuf->m_unused1 == 0x66)
		{
			pMbuf->m_unused1 = 0;
			if (airgo_free)
			{
				(*airgo_free)(pPkt);
				return SUCCESS;
			}
		}
#else
		if ((pMbuf->m_unused1==0x66)&&(airgo_free)) {
			(*airgo_free)(pPkt);
			//rtlglue_printf("tx disabletoo short\n");

			return SUCCESS;
		}
#endif

#endif
		return FAILED;
	}
   	assert(pPkt->ph_len>=60);

	PROFILING_END(ROMEPERF_INDEX_14);
	PROFILING_START(ROMEPERF_INDEX_15);

	if(nicTxAlignFix)
		_nicTxAlignFix(pPkt,pMbuf);

	//rtlglue_printf("len[%d] rx[%d] plist[%x] sepn[%d] espl[%x]\n", pPkt->ph_len, pPkt->ph_rxdesc, pPkt->ph_portlist, pPkt->ph_srcExtPortNum, pPkt->ph_extPortList);

	pPkt->ph_nextHdr = (struct rtl_pktHdr *) NULL;
	rxDescIdx=pPkt->ph_rxdesc;

	if(TxPkthdrDescFull){
		PROFILING_START(ROMEPERF_INDEX_16);
		swNic_isrTxRecycle(0);//force reclaim Tx descriptors if any.
		PROFILING_END(ROMEPERF_INDEX_16);

		if(TxPkthdrDescFull){//check again, if still full, drop the pkt.
//			if((rxDescIdx>=0)&&(rxDescIdx<totalRxPkthdr))
//				swNic_isrReclaim(rxDescIdx,  pPkt, pMbuf);//pkt was rcvd from network. free it..

			spin_unlock_irqrestore(rtl865xSpinlock,s);

#ifdef AIRGO_FAST_PATH
#ifdef AIRGO_NEW
		if (pMbuf->m_unused1 == 0x66)
		{
			pMbuf->m_unused1 = 0;
			if (airgo_free)
			{
				(*airgo_free)(pPkt);
				return SUCCESS;
			}
		}
#else
		if ((pMbuf->m_unused1==0x66)&&(airgo_free)) {
			(*airgo_free)(pPkt);
			//rtlglue_printf("tx disabletoo short\n");
			return SUCCESS;
		}
#endif
#endif
			return FAILED;
		}
	}

	START_SNIFFING( pPkt, 0x00000002 );

	//yes, we have a Tx desc fro sending this pkt.
	//mark desc as swcore own to send the packet...
	//printfByPolling("T%d ,",txFreeIndex);	
      TxPkthdrRing[txFreeIndex]|=((uint32)pPkt|DESC_OWNED_BIT);

	wmb();
	lastTxIndex=txFreeIndex;
	txFreeIndex++;
	txFreeIndex&=(1<<totalTxPkthdrShift)-1;
	spin_unlock_irqrestore(rtl865xSpinlock,s);

#ifdef SWNIC_DEBUG
	if(nicDbgMesg){
		if((nicDbgMesg==NIC_TX_PKTDUMP)||
			((nicDbgMesg&NIC_PHY_TX_PKTDUMP)&&(pPkt->ph_srcExtPortNum==0))||
			((nicDbgMesg&NIC_EXT_TX_PKTDUMP)&&(pPkt->ph_srcExtPortNum))
		){
			rtlglue_printf("NIC Tx [%d] L:%d P%04x s%d e%04x\n", pPkt->ph_rxdesc, pPkt->ph_len, pPkt->ph_portlist, pPkt->ph_srcExtPortNum, pPkt->ph_extPortList);
			memDump(pMbuf->m_data,pMbuf->m_len>64?64:pMbuf->m_len,"");
		}
	}
#endif
//printk("%s %d portlist=%x srcextportnum=%x extPortlist=%x vlanidx=%x vlanTagged=%x flags=%x\n\n",__FUNCTION__,__LINE__,pPkt->ph_portlist,pPkt->ph_srcExtPortNum,pPkt->ph_extPortList,pPkt->ph_vlanIdx,pPkt->ph_vlanTagged,pPkt->ph_flags);	

//	REG32(CPUICR) |= TXFD;
	WRITE_MEM32(CPUICR , READ_MEM32(CPUICR) | TXFD );
	
	PROFILING_END(ROMEPERF_INDEX_15);
	return SUCCESS;
}
#endif

#ifdef CONFIG_RTL865XC


int32 swNic_txRxSwitch(uint32 tx, uint32 rx){
//	uint32 icr = REG32(CPUICR), imr = REG32(CPUIIMR);
	uint32 icr = READ_MEM32(CPUICR), imr = READ_MEM32(CPUIIMR);
	if(tx==0){
		icr &= ~TXCMD;
		imr &= ~TX_ERR_IE_ALL;
	}else{
		icr |= TXCMD;
		imr |= TX_ERR_IE_ALL;
	}
	if(rx==0){
		icr&=~RXCMD;
		imr &= ~(RX_ERR_IE_ALL | PKTHDR_DESC_RUNOUT_IE_ALL |  RX_DONE_IE_ALL);
	}else{
		icr |= RXCMD;
		imr |=(RX_ERR_IE_ALL | PKTHDR_DESC_RUNOUT_IE_ALL |  RX_DONE_IE_ALL);
	}
	rxEnable=rx;
	txEnable=tx;
//	REG32(CPUICR) = icr;
	WRITE_MEM32(CPUICR,icr);
//	REG32(CPUIIMR) = imr;
	WRITE_MEM32(CPUIIMR,imr);
	return SUCCESS;
}
#else
int32 swNic_txRxSwitch(uint32 tx, uint32 rx){
	uint32 icr = REG32(CPUICR), imr = REG32(CPUIIMR);

		
	if(tx==0){
		icr &= ~TXCMD;
		imr &= ~TX_ERR_IE;
	}else{
		icr |= TXCMD;
		imr |= TX_ERR_IE;
	}
	if(rx==0){
		icr&=~RXCMD;
		imr &= ~(RX_ERR_IE | PKTHDR_DESC_RUNOUT_IE |  RX_DONE_IE);
	}else{
		icr |= RXCMD;
		imr |=(RX_ERR_IE | PKTHDR_DESC_RUNOUT_IE |  RX_DONE_IE);
	}
	rxEnable=rx;
	txEnable=tx;
	REG32(CPUICR) = icr;
	REG32(CPUIIMR) = imr;
	return SUCCESS;
}
#endif

//#pragma ghs section text=default
#ifdef CONFIG_RTL865XC

int32 swNic_setup(uint32 pkthdrs0,uint32 pkthdrs1,uint32 pkthdrs2,uint32 pkthdrs3,uint32 pkthdrs4,uint32 pkthdrs5,
	uint32 mbufs0,
	uint32 txpkthdrs0, uint32 txpkthdrs1)
{
	struct rtl_pktHdr *freePkthdrListHead0,*freePkthdrListTail0;
	struct rtl_pktHdr *freePkthdrListHead1,*freePkthdrListTail1;
	struct rtl_pktHdr *freePkthdrListHead2,*freePkthdrListTail2;
	struct rtl_pktHdr *freePkthdrListHead3,*freePkthdrListTail3;
	struct rtl_pktHdr *freePkthdrListHead4,*freePkthdrListTail4;
	struct rtl_pktHdr *freePkthdrListHead5,*freePkthdrListTail5;	
	
	struct rtl_mBuf *freeMbufListHead0, *freeMbufListTail0;

	
	int i;
	 /* Disable Rx & Tx ,bus burst size, etc */
	swNic_txRxSwitch(0,0);

#ifdef SWNIC_EARLYSTOP
	nicRxEarlyStop=0;
#endif
	/* Initialize index of Tx pkthdr descriptor */
	txDoneIndex0 = 0;
	txFreeIndex0 = 0;
	txDoneIndex1 = 0;
	txFreeIndex1 = 0;

	/* Allocate rx pkthdrs */
	if(pkthdrs0!=mBuf_driverGetPkthdr(pkthdrs0, &freePkthdrListHead0, &freePkthdrListTail0)){
		rtlglue_printf("Can't allocate all pkthdrs\n");
		return EINVAL;
	}
	assert(freePkthdrListHead0);
	assert(freePkthdrListTail0);

	/* Allocate rx pkthdrs */
	if(pkthdrs1!=mBuf_driverGetPkthdr(pkthdrs1, &freePkthdrListHead1, &freePkthdrListTail1)){
		rtlglue_printf("Can't allocate all pkthdrs\n");
		return EINVAL;
	}
	assert(freePkthdrListHead1);
	assert(freePkthdrListTail1);

	/* Allocate rx pkthdrs */
	if(pkthdrs2!=mBuf_driverGetPkthdr(pkthdrs2, &freePkthdrListHead2, &freePkthdrListTail2)){
		rtlglue_printf("Can't allocate all pkthdrs\n");
		return EINVAL;
	}
	assert(freePkthdrListHead2);
	assert(freePkthdrListTail2);

	/* Allocate rx pkthdrs */
	if(pkthdrs3!=mBuf_driverGetPkthdr(pkthdrs3, &freePkthdrListHead3, &freePkthdrListTail3)){
		rtlglue_printf("Can't allocate all pkthdrs\n");
		return EINVAL;
	}
	assert(freePkthdrListHead3);
	assert(freePkthdrListTail3);	

	/* Allocate rx pkthdrs */
	if(pkthdrs4!=mBuf_driverGetPkthdr(pkthdrs4, &freePkthdrListHead4, &freePkthdrListTail4)){
		rtlglue_printf("Can't allocate all pkthdrs\n");
		return EINVAL;
	}
	assert(freePkthdrListHead4);
	assert(freePkthdrListTail4);

	/* Allocate rx pkthdrs */
	if(pkthdrs5!=mBuf_driverGetPkthdr(pkthdrs5, &freePkthdrListHead5, &freePkthdrListTail5)){
		rtlglue_printf("Can't allocate all pkthdrs\n");
		return EINVAL;
	}
	assert(freePkthdrListHead5);
	assert(freePkthdrListTail5);

	
	
	/* Allocate rx mbufs and clusters */
	if(mbufs0!=mBuf_driverGet(mbufs0, &freeMbufListHead0, &freeMbufListTail0)){
		rtlglue_printf("Can't allocate all mbuf/clusters\n");
		return EINVAL;
	}
	assert(freeMbufListHead0);
	assert(freeMbufListTail0);


	
    /////////////////////////////////////////////////	
    /* Initialize Tx packet header descriptors */
    for (i=0; i<txpkthdrs0; i++)
        TxPkthdrRing0[i] = DESC_RISC_OWNED;

    for (i=0; i<txpkthdrs1; i++)
        TxPkthdrRing1[i] = DESC_RISC_OWNED;


    /* Set wrap bit of the last descriptor */
    TxPkthdrRing0[txpkthdrs0 - 1] |= DESC_WRAP;
    TxPkthdrRing1[txpkthdrs1 - 1] |= DESC_WRAP;

    /* Fill Tx packet header FDP */
//    REG32(CPUTPDCR) = (uint32) TxPkthdrRing;
    WRITE_MEM32(CPUTPDCR0,(uint32) TxPkthdrRing0);
    WRITE_MEM32(CPUTPDCR1,(uint32) TxPkthdrRing1);	
	
    /////////////////////////////////////////////////	
    /* Initialize index of current Rx pkthdr descriptor */
    rxPhdrIndex0 = 0;
    rxPhdrIndex1 = 0;
    rxPhdrIndex2 = 0;
    rxPhdrIndex3 = 0;
    rxPhdrIndex4 = 0;
    rxPhdrIndex5 = 0;

    /* Initialize Rx packet header descriptors */
    for (i=0; i<pkthdrs0; i++)
    {
        assert( freePkthdrListHead0 );

	/* packet in RxRing must remove the flag PKTHDR_DRIVERHOLD to indicate */
	freePkthdrListHead0->ph_flags &= ~PKTHDR_DRIVERHOLD;
	/* we set descriptor index to RxRing's pkts */
	freePkthdrListHead0->ph_rxdesc = i;
	freePkthdrListHead0->ph_rxmbufdesc = i;

        RxPkthdrRing0[i] = (uint32) freePkthdrListHead0 | DESC_SWCORE_OWNED;
        if ( (freePkthdrListHead0 = freePkthdrListHead0->ph_nextHdr) == NULL )
            freePkthdrListTail0 = NULL;
    }

    /* Initialize Rx packet header descriptors */
    for (i=0; i<pkthdrs1; i++)
    {
        assert( freePkthdrListHead1 );

	/* packet in RxRing must remove the flag PKTHDR_DRIVERHOLD to indicate */
	freePkthdrListHead1->ph_flags &= ~PKTHDR_DRIVERHOLD;
	/* we set descriptor index to RxRing's pkts */
	freePkthdrListHead1->ph_rxdesc = i;
	freePkthdrListHead1->ph_rxmbufdesc = i+pkthdrs0;

        RxPkthdrRing1[i] = (uint32) freePkthdrListHead1 | DESC_SWCORE_OWNED;
        if ( (freePkthdrListHead1 = freePkthdrListHead1->ph_nextHdr) == NULL )
            freePkthdrListTail1 = NULL;
    }	

    /* Initialize Rx packet header descriptors */
    for (i=0; i<pkthdrs2; i++)
    {
        assert( freePkthdrListHead2 );

	/* packet in RxRing must remove the flag PKTHDR_DRIVERHOLD to indicate */
	freePkthdrListHead2->ph_flags &= ~PKTHDR_DRIVERHOLD;
	/* we set descriptor index to RxRing's pkts */
	freePkthdrListHead2->ph_rxdesc = i;
	freePkthdrListHead2->ph_rxmbufdesc = i+pkthdrs0+pkthdrs1;

        RxPkthdrRing2[i] = (uint32) freePkthdrListHead2 | DESC_SWCORE_OWNED;
        if ( (freePkthdrListHead2 = freePkthdrListHead2->ph_nextHdr) == NULL )
            freePkthdrListTail2 = NULL;
    }	
	
    /* Initialize Rx packet header descriptors */
    for (i=0; i<pkthdrs3; i++)
    {
        assert( freePkthdrListHead3 );

	/* packet in RxRing must remove the flag PKTHDR_DRIVERHOLD to indicate */
	freePkthdrListHead3->ph_flags &= ~PKTHDR_DRIVERHOLD;
	/* we set descriptor index to RxRing's pkts */
	freePkthdrListHead3->ph_rxdesc = i;
	freePkthdrListHead3->ph_rxmbufdesc = i+pkthdrs0+pkthdrs1+pkthdrs2;	

        RxPkthdrRing3[i] = (uint32) freePkthdrListHead3 | DESC_SWCORE_OWNED;
        if ( (freePkthdrListHead3 = freePkthdrListHead3->ph_nextHdr) == NULL )
            freePkthdrListTail3 = NULL;
    }	

    /* Initialize Rx packet header descriptors */
    for (i=0; i<pkthdrs4; i++)
    {
        assert( freePkthdrListHead4 );

	/* packet in RxRing must remove the flag PKTHDR_DRIVERHOLD to indicate */
	freePkthdrListHead4->ph_flags &= ~PKTHDR_DRIVERHOLD;
	/* we set descriptor index to RxRing's pkts */
	freePkthdrListHead4->ph_rxdesc = i;
	freePkthdrListHead4->ph_rxmbufdesc = i+pkthdrs0+pkthdrs1+pkthdrs2+pkthdrs3;		

        RxPkthdrRing4[i] = (uint32) freePkthdrListHead4 | DESC_SWCORE_OWNED;
        if ( (freePkthdrListHead4 = freePkthdrListHead4->ph_nextHdr) == NULL )
            freePkthdrListTail4 = NULL;
    }	

    /* Initialize Rx packet header descriptors */
    for (i=0; i<pkthdrs5; i++)
    {
        assert( freePkthdrListHead5 );

	/* packet in RxRing must remove the flag PKTHDR_DRIVERHOLD to indicate */
	freePkthdrListHead5->ph_flags &= ~PKTHDR_DRIVERHOLD;
	/* we set descriptor index to RxRing's pkts */
	freePkthdrListHead5->ph_rxdesc = i;
	freePkthdrListHead5->ph_rxmbufdesc = i+pkthdrs0+pkthdrs1+pkthdrs2+pkthdrs3+pkthdrs4;			

        RxPkthdrRing5[i] = (uint32) freePkthdrListHead5 | DESC_SWCORE_OWNED;
        if ( (freePkthdrListHead5 = freePkthdrListHead5->ph_nextHdr) == NULL )
            freePkthdrListTail5 = NULL;
    }	


	
    /* Set wrap bit of the last descriptor */
    RxPkthdrRing0[pkthdrs0 - 1] |= DESC_WRAP;
    RxPkthdrRing1[pkthdrs1 - 1] |= DESC_WRAP;
    RxPkthdrRing2[pkthdrs2 - 1] |= DESC_WRAP;
    RxPkthdrRing3[pkthdrs3 - 1] |= DESC_WRAP;
    RxPkthdrRing4[pkthdrs4 - 1] |= DESC_WRAP;
    RxPkthdrRing5[pkthdrs5 - 1] |= DESC_WRAP;
	
    /* Fill Rx packet header FDP */
//    REG32(CPURPDCR) = (uint32) RxPkthdrRing;
	WRITE_MEM32(CPURPDCR0,(uint32)RxPkthdrRing0);
	WRITE_MEM32(CPURPDCR1,(uint32)RxPkthdrRing1);
	WRITE_MEM32(CPURPDCR2,(uint32)RxPkthdrRing2);
	WRITE_MEM32(CPURPDCR3,(uint32)RxPkthdrRing3);
	WRITE_MEM32(CPURPDCR4,(uint32)RxPkthdrRing4);
	WRITE_MEM32(CPURPDCR5,(uint32)RxPkthdrRing5);	
	

    /////////////////////////////////////////////////	
    /* Initialize index of current Rx pkthdr descriptor */
    rxMbufIndex0 = 0;
	
    /* Initialize Rx mbuf descriptors */
    for (i=0; i<mbufs0; i++)
    {
        assert( freeMbufListHead0 );
        RxMbufRing0[i] = (uint32) freeMbufListHead0 | DESC_SWCORE_OWNED;
	freeMbufListHead0->m_extbuf=(uint8 *)UNCACHE(freeMbufListHead0->m_extbuf);
	freeMbufListHead0->m_data=(uint8 *)UNCACHE(freeMbufListHead0->m_data);

#if defined(CONFIG_RTL865X_MBUF_HEADROOM)&&defined(CONFIG_RTL865X_MULTILAYER_BSP)
		if(mBuf_reserve(freeMbufListHead0, CONFIG_RTL865X_MBUF_HEADROOM))
			rtlglue_printf("Failed when init Rx %d\n", i);
#endif
        if ( (freeMbufListHead0 = freeMbufListHead0->m_next) == NULL )
            freeMbufListTail0 = NULL;
    }
	
    /* Set wrap bit of the last descriptor */
    RxMbufRing0[mbufs0 - 1] |= DESC_WRAP;
	
    /* Fill Rx mbuf FDP */
	//REG32(CPURMDCR) = (uint32) RxMbufRing;
	WRITE_MEM32(CPURMDCR0,(uint32) RxMbufRing0);
	//REG32(CPUICR) =0;
	WRITE_MEM32(CPUICR,0);

#ifdef CONFIG_RTL865XB
	{
		char chipVersion[16];
		uint32 align=0, rev;

//		REG32(CPUICR)|=EXCLUDE_CRC;
		WRITE_MEM32(CPUICR,READ_MEM32(CPUICR)|EXCLUDE_CRC);
		
		GetChipVersion(chipVersion, sizeof(chipVersion), &rev);
		if(chipVersion[strlen(chipVersion)-1]=='B')
		{
			//865xB chips support free Rx align from 0~256 bytes
			#ifdef SWNIC_RX_ALIGNED_IPHDR					
			align+=2;
			#endif
//			REG32(CPUICR)|=align; 
			WRITE_MEM32(CPUICR,READ_MEM32(CPUICR)|align);
			rtlglue_printf("Rx shift=%x\n",READ_MEM32(CPUICR));
			if(rev<2) //865xB  A & B cut needs to do Tx align fix for certain length of packets.
				nicTxAlignFix=1;
		}
	}
#endif

    /* Enable Rx & Tx. Config bus burst size and mbuf size. */
//    REG32(CPUICR) |= BUSBURST_32WORDS | MBUF_2048BYTES;
	WRITE_MEM32(CPUICR,READ_MEM32(CPUICR)|BUSBURST_32WORDS | MBUF_2048BYTES);
//    REG32(CPUIIMR) |= LINK_CHANG_IE;
	WRITE_MEM32(CPUIIMR,READ_MEM32(CPUIIMR)|LINK_CHANG_IE);
	swNic_txRxSwitch(1,1);
    return SUCCESS;

}






#else // for RTL865XB ===============================================================================
int32 swNic_setup(uint32 pkthdrs, uint32 mbufs, uint32 txpkthdrs)
{
	struct rtl_pktHdr *freePkthdrListHead,*freePkthdrListTail;
	struct rtl_mBuf *freeMbufListHead, *freeMbufListTail;
	int i;
	 /* Disable Rx & Tx ,bus burst size, etc */
	swNic_txRxSwitch(0,0);

#ifdef SWNIC_EARLYSTOP
	nicRxEarlyStop=0;
#endif
	/* Initialize index of Tx pkthdr descriptor */
	txDoneIndex = 0;
	txFreeIndex = 0;

	/* Allocate rx pkthdrs */
	if(pkthdrs!=mBuf_driverGetPkthdr(pkthdrs, &freePkthdrListHead, &freePkthdrListTail)){
		rtlglue_printf("Can't allocate all pkthdrs\n");
		return EINVAL;
	}
	assert(freePkthdrListHead);
	assert(freePkthdrListTail);
	/* Allocate rx mbufs and clusters */
	if(mbufs!=mBuf_driverGet(mbufs, &freeMbufListHead, &freeMbufListTail)){
		rtlglue_printf("Can't allocate all mbuf/clusters\n");
		return EINVAL;
	}
	assert(freeMbufListHead);
	assert(freeMbufListTail);
    /////////////////////////////////////////////////	
    /* Initialize Tx packet header descriptors */
    for (i=0; i<txpkthdrs; i++)
        TxPkthdrRing[i] = DESC_RISC_OWNED;

    /* Set wrap bit of the last descriptor */
    TxPkthdrRing[txpkthdrs - 1] |= DESC_WRAP;

    /* Fill Tx packet header FDP */
//    REG32(CPUTPDCR) = (uint32) TxPkthdrRing;
    WRITE_MEM32(CPUTPDCR,(uint32) TxPkthdrRing);
	
    /////////////////////////////////////////////////	
    /* Initialize index of current Rx pkthdr descriptor */
    rxPhdrIndex = 0;
    /* Initialize Rx packet header descriptors */
    for (i=0; i<pkthdrs; i++)
    {
        assert( freePkthdrListHead );

	/* packet in RxRing must remove the flag PKTHDR_DRIVERHOLD to indicate */
	freePkthdrListHead->ph_flags &= ~PKTHDR_DRIVERHOLD;
	/* we set descriptor index to RxRing's pkts */
	freePkthdrListHead->ph_rxdesc = i;


        RxPkthdrRing[i] = (uint32) freePkthdrListHead | DESC_SWCORE_OWNED;
        if ( (freePkthdrListHead = freePkthdrListHead->ph_nextHdr) == NULL )
            freePkthdrListTail = NULL;
    }
    /* Set wrap bit of the last descriptor */
    RxPkthdrRing[pkthdrs - 1] |= DESC_WRAP;
    /* Fill Rx packet header FDP */
//    REG32(CPURPDCR) = (uint32) RxPkthdrRing;
	WRITE_MEM32(CPURPDCR,(uint32)RxPkthdrRing);

    /////////////////////////////////////////////////	
    /* Initialize index of current Rx pkthdr descriptor */
    rxMbufIndex = 0;
    /* Initialize Rx mbuf descriptors */
    for (i=0; i<mbufs; i++)
    {
        assert( freeMbufListHead );
        RxMbufRing[i] = (uint32) freeMbufListHead | DESC_SWCORE_OWNED;
		freeMbufListHead->m_extbuf=(uint8 *)UNCACHE(freeMbufListHead->m_extbuf);
		freeMbufListHead->m_data=(uint8 *)UNCACHE(freeMbufListHead->m_data);

#if defined(CONFIG_RTL865X_MBUF_HEADROOM)&&defined(CONFIG_RTL865X_MULTILAYER_BSP)
		if(mBuf_reserve(freeMbufListHead, CONFIG_RTL865X_MBUF_HEADROOM))
			rtlglue_printf("Failed when init Rx %d\n", i);
#endif
        if ( (freeMbufListHead = freeMbufListHead->m_next) == NULL )
            freeMbufListTail = NULL;
    }
    /* Set wrap bit of the last descriptor */
    RxMbufRing[mbufs - 1] |= DESC_WRAP;

    /* Fill Rx mbuf FDP */
	//REG32(CPURMDCR) = (uint32) RxMbufRing;
	WRITE_MEM32(CPURMDCR,(uint32) RxMbufRing);
	//REG32(CPUICR) =0;
	WRITE_MEM32(CPUICR,0);

#ifdef CONFIG_RTL865XB
	{
		char chipVersion[16];
		uint32 align=0, rev;

//		REG32(CPUICR)|=EXCLUDE_CRC;
		WRITE_MEM32(CPUICR,READ_MEM32(CPUICR)|EXCLUDE_CRC);
		
		GetChipVersion(chipVersion, sizeof(chipVersion), &rev);
		if(chipVersion[strlen(chipVersion)-1]=='B')
		{
			//865xB chips support free Rx align from 0~256 bytes
			#ifdef SWNIC_RX_ALIGNED_IPHDR					
			align+=2;
			#endif
//			REG32(CPUICR)|=align; 
			WRITE_MEM32(CPUICR,READ_MEM32(CPUICR)|align);
			rtlglue_printf("Rx shift=%x\n",READ_MEM32(CPUICR));
			if(rev<2) //865xB  A & B cut needs to do Tx align fix for certain length of packets.
				nicTxAlignFix=1;
		}
	}
#endif

    /* Enable Rx & Tx. Config bus burst size and mbuf size. */
//    REG32(CPUICR) |= BUSBURST_32WORDS | MBUF_2048BYTES;
	WRITE_MEM32(CPUICR,READ_MEM32(CPUICR)|BUSBURST_32WORDS | MBUF_2048BYTES);
//    REG32(CPUIIMR) |= LINK_CHANG_IE;
	WRITE_MEM32(CPUIIMR,READ_MEM32(CPUIIMR)|LINK_CHANG_IE);
	swNic_txRxSwitch(1,1);
    return SUCCESS;

}
#endif


int32 swNic_descRingCleanup(void){
#ifdef CONFIG_RTL865XC 
rtlglue_printf("========swNic_descRingCleanup ... not implement ...........\n");
#else
	int i;
	swNic_txRxSwitch(0,0);
    /* cleanup Tx packet header descriptors */
    for (i=0; i<totalTxPkthdr; i++){
		struct rtl_pktHdr *ph;
		TxPkthdrRing[i]&= ~DESC_SWCORE_OWNED; //mark it own by CPU
		ph = (struct rtl_pktHdr *) (TxPkthdrRing[i] & ~ (0x3));
		if(ph){
			//has somthing send or sent...
			struct rtl_mBuf *m;
			uint32 rxDescIdx;
			rxDescIdx = ph->ph_rxdesc;
			ph->ph_rxdesc = totalRxPkthdr; 
			m=ph->ph_mbuf;
			assert(m);
			if((rxDescIdx<0 || rxDescIdx>=totalRxPkthdr)){
				//came from protocol stack or fwd engine
				SETBITS(m->m_flags, MBUF_USED);
				mBuf_freeMbufChain(m);
			}
		}
		TxPkthdrRing[i] &= 0x3;//clean desc on Rx Pkthdr ring
  }	

    /* cleanup Rx packet header descriptors */
    for (i=0; i<totalRxPkthdr; i++){
		struct rtl_pktHdr *ph;
		struct rtl_mBuf *m;
		RxPkthdrRing[i]&= ~DESC_SWCORE_OWNED; //mark it own by CPU
		RxMbufRing[i]&= ~DESC_SWCORE_OWNED;
		ph = (struct rtl_pktHdr *) (RxPkthdrRing[i] & ~ (0x3));
		m = (struct rtl_mBuf *)(RxMbufRing[i] & ~ (0x3));
		ph->ph_mbuf=m;
		m->m_pkthdr=ph;
		RxPkthdrRing[i] &= 0x3;//clean desc on Rx Pkthdr ring
		RxMbufRing[i]&=0x3;
		assert(ph);
		ph->ph_rxdesc = -1; 
		m->m_next=NULL;
		SETBITS(ph->ph_flags, PKTHDR_USED);
		SETBITS(m->m_flags, MBUF_USED|MBUF_PKTHDR);
		mBuf_freeMbufChain(ph->ph_mbuf);
    }
    	
    /////////////////////////////////////////////////	
    /* Initialize index of current Rx pkthdr descriptor */
    rxMbufIndex = rxPhdrIndex = txDoneIndex = txFreeIndex = 0;
//	REG32(CPURMDCR) = 0;
//	REG32(CPURPDCR) = 0;
//	REG32(CPUTPDCR) = 0;	
	WRITE_MEM32(CPURMDCR,0);
	WRITE_MEM32(CPURPDCR,0);
	WRITE_MEM32(CPUTPDCR,0);
#endif	
	return SUCCESS;

}


#ifdef CONFIG_RTL865XC 
int32 swNic_init(uint32 nRxPkthdrDesc0,uint32 nRxPkthdrDesc1,uint32 nRxPkthdrDesc2,
			uint32 nRxPkthdrDesc3,uint32 nRxPkthdrDesc4,uint32 nRxPkthdrDesc5,
			uint32 nRxMbufDesc0, 
			uint32 nTxPkthdrDesc0, uint32 nTxPkthdrDesc1, 
			uint32 clusterSize, 
                        proc_input_pkt_funcptr_t processInputPacket, 
                        int32 reserved(struct rtl_pktHdr *))
{
	uint32  exponent;

	//check input parameters.
	if(isPowerOf2(nRxPkthdrDesc0, &exponent)==FALSE)
		return EINVAL;
	if(isPowerOf2(nRxPkthdrDesc1, &exponent)==FALSE)
		return EINVAL;
	if(isPowerOf2(nRxPkthdrDesc2, &exponent)==FALSE)
		return EINVAL;
	if(isPowerOf2(nRxPkthdrDesc3, &exponent)==FALSE)
		return EINVAL;
	if(isPowerOf2(nRxPkthdrDesc4, &exponent)==FALSE)
		return EINVAL;
	if(isPowerOf2(nRxPkthdrDesc5, &exponent)==FALSE)
		return EINVAL;
		
	if(isPowerOf2(nRxMbufDesc0, &exponent)==FALSE)		
		return EINVAL;
		
	if(isPowerOf2(nTxPkthdrDesc0, &totalTxPkthdrShift0)==FALSE)		
		return EINVAL;

	if(isPowerOf2(nTxPkthdrDesc1, &totalTxPkthdrShift1)==FALSE)		
		return EINVAL;

	
    	if (processInputPacket == NULL)
		return EINVAL;

	//we only accept 2048 byte cluster now.
	if(clusterSize!=m_clusterSize) //mbuf should be init first and cluster size must equal to the number used in mbuf init
		return EINVAL;
	assert(m_clusterSize==2048); //mBuf should be init with 2048 as cluster value

	totalRxPkthdr0 = nRxPkthdrDesc0;
	totalRxPkthdr1 = nRxPkthdrDesc1;
	totalRxPkthdr2 = nRxPkthdrDesc2;
	totalRxPkthdr3 = nRxPkthdrDesc3;
	totalRxPkthdr4 = nRxPkthdrDesc4;
	totalRxPkthdr5 = nRxPkthdrDesc5;	
	totalRxMbuf0 = nRxMbufDesc0;
	totalTxPkthdr0 = nTxPkthdrDesc0;
	totalTxPkthdr1 = nTxPkthdrDesc1;	
	rxRunoutIdx0=-1;
	rxRunoutIdx1=-1;
	rxRunoutIdx2=-1;
	rxRunoutIdx3=-1;
	rxRunoutIdx4=-1;
	rxRunoutIdx5=-1;	
	
	installedProcessInputPacket = processInputPacket;
	rxPkthdr_runout=0;
	nicTxAlignFix=0;
	nicDbgMesg=0;
	
	/* Allocate Rx/Tx descriptor ring.*/
#ifdef RTL865X_MODEL_USER
	RxPkthdrRing0=(uint32 *)((uint32)rtlglue_malloc(totalRxPkthdr0 * sizeof(struct rtl_pktHdr *)));
	RxPkthdrRing1=(uint32 *)((uint32)rtlglue_malloc(totalRxPkthdr1 * sizeof(struct rtl_pktHdr *)));
	RxPkthdrRing2=(uint32 *)((uint32)rtlglue_malloc(totalRxPkthdr2 * sizeof(struct rtl_pktHdr *)));
	RxPkthdrRing3=(uint32 *)((uint32)rtlglue_malloc(totalRxPkthdr3 * sizeof(struct rtl_pktHdr *)));
	RxPkthdrRing4=(uint32 *)((uint32)rtlglue_malloc(totalRxPkthdr4 * sizeof(struct rtl_pktHdr *)));
	RxPkthdrRing5=(uint32 *)((uint32)rtlglue_malloc(totalRxPkthdr5 * sizeof(struct rtl_pktHdr *)));	
	
	RxMbufRing0 = (uint32 *)((uint32)rtlglue_malloc(totalRxMbuf0 * sizeof(struct rtl_mBuf *)));


	TxPkthdrRing0 = (uint32 *)((uint32)rtlglue_malloc(totalTxPkthdr0 * sizeof(struct rtl_pktHdr *)));
	TxPkthdrRing1 = (uint32 *)((uint32)rtlglue_malloc(totalTxPkthdr1 * sizeof(struct rtl_pktHdr *)));
	
#else

	RxPkthdrRing0=(uint32 *)(UNCACHE_MASK|(uint32)rtlglue_malloc(totalRxPkthdr0 * sizeof(struct rtl_pktHdr *)));
	RxPkthdrRing1=(uint32 *)(UNCACHE_MASK|(uint32)rtlglue_malloc(totalRxPkthdr1 * sizeof(struct rtl_pktHdr *)));
	RxPkthdrRing2=(uint32 *)(UNCACHE_MASK|(uint32)rtlglue_malloc(totalRxPkthdr2 * sizeof(struct rtl_pktHdr *)));
	RxPkthdrRing3=(uint32 *)(UNCACHE_MASK|(uint32)rtlglue_malloc(totalRxPkthdr3 * sizeof(struct rtl_pktHdr *)));
	RxPkthdrRing4=(uint32 *)(UNCACHE_MASK|(uint32)rtlglue_malloc(totalRxPkthdr4 * sizeof(struct rtl_pktHdr *)));
	RxPkthdrRing5=(uint32 *)(UNCACHE_MASK|(uint32)rtlglue_malloc(totalRxPkthdr5 * sizeof(struct rtl_pktHdr *)));
	RxMbufRing0 = (uint32 *)(UNCACHE_MASK|(uint32)rtlglue_malloc(totalRxMbuf0 * sizeof(struct rtl_mBuf *)));
	TxPkthdrRing0 = (uint32 *)(UNCACHE_MASK|(uint32)rtlglue_malloc(totalTxPkthdr0 * sizeof(struct rtl_pktHdr *)));
	TxPkthdrRing1 = (uint32 *)(UNCACHE_MASK|(uint32)rtlglue_malloc(totalTxPkthdr1 * sizeof(struct rtl_pktHdr *)));
#endif	

	if(!RxPkthdrRing0 ||!RxPkthdrRing1 ||!RxPkthdrRing2 ||!RxPkthdrRing3 ||!RxPkthdrRing4 ||!RxPkthdrRing5 ||
		!RxMbufRing0 || !TxPkthdrRing0 || !TxPkthdrRing1 )
		return EINVAL;

	
	mBuf_setNICRxRingSize(totalRxPkthdr0+totalRxPkthdr1+totalRxPkthdr2+totalRxPkthdr3+totalRxPkthdr4+totalRxPkthdr5);
	/* Initialize interrupt statistics counter */
	rxIntNum = rxPkthdrRunoutSolved= txIntNum = rxPkthdrRunoutNum = rxMbufRunoutNum = rxPktErrorNum = txPktErrorNum = 0;
	rxPktCounter = txPktCounter = linkChanged=0;

	//All Ring buffers allocated. Now initialize all rings and swNic itself.
	return  swNic_setup(totalRxPkthdr0,totalRxPkthdr1,totalRxPkthdr2,totalRxPkthdr3,totalRxPkthdr4,totalRxPkthdr5,
					totalRxMbuf0,
					totalTxPkthdr0,totalTxPkthdr1);
}

#else // for RTL865XB ====================================================================================

int32 swNic_init(uint32 nRxPkthdrDesc, uint32 nRxMbufDesc, uint32 nTxPkthdrDesc, 
                        uint32 clusterSize, 
                        proc_input_pkt_funcptr_t processInputPacket, 
                        int32 reserved(struct rtl_pktHdr *))
{
	uint32  exponent;

	//check input parameters.
	if(isPowerOf2(nRxPkthdrDesc, &exponent)==FALSE)
		return EINVAL;
	if(isPowerOf2(nRxMbufDesc, &exponent)==FALSE)
		return EINVAL;
	if(isPowerOf2(nTxPkthdrDesc, &totalTxPkthdrShift)==FALSE)
		return EINVAL;
    	if (processInputPacket == NULL)
		return EINVAL;

	//we only accept 2048 byte cluster now.
	if(clusterSize!=m_clusterSize) //mbuf should be init first and cluster size must equal to the number used in mbuf init
		return EINVAL;
	assert(m_clusterSize==2048); //mBuf should be init with 2048 as cluster value
	totalRxPkthdr = nRxPkthdrDesc;
	totalRxMbuf = nRxMbufDesc;
	totalTxPkthdr = nTxPkthdrDesc;
	rxRunoutIdx=-1;
	installedProcessInputPacket = processInputPacket;
	rxPkthdr_runout=0;
	nicTxAlignFix=0;
	nicDbgMesg=0;
	
	/* Allocate Rx/Tx descriptor ring.*/
#ifdef RTL865X_MODEL_USER
	RxPkthdrRing=(uint32 *)((uint32)rtlglue_malloc(totalRxPkthdr * sizeof(struct rtl_pktHdr *)));
	RxMbufRing = (uint32 *)((uint32)rtlglue_malloc(totalRxMbuf * sizeof(struct rtl_mBuf *)));
	TxPkthdrRing = (uint32 *)((uint32)rtlglue_malloc(totalTxPkthdr * sizeof(struct rtl_pktHdr *)));
#else
	RxPkthdrRing=(uint32 *)(UNCACHE_MASK|(uint32)rtlglue_malloc(totalRxPkthdr * sizeof(struct rtl_pktHdr *)));
	RxMbufRing = (uint32 *)(UNCACHE_MASK|(uint32)rtlglue_malloc(totalRxMbuf * sizeof(struct rtl_mBuf *)));
	TxPkthdrRing = (uint32 *)(UNCACHE_MASK|(uint32)rtlglue_malloc(totalTxPkthdr * sizeof(struct rtl_pktHdr *)));
#endif	

	if(!RxPkthdrRing||!RxMbufRing||!TxPkthdrRing)
		return EINVAL;
	mBuf_setNICRxRingSize(totalRxPkthdr);
	/* Initialize interrupt statistics counter */
	rxIntNum = rxPkthdrRunoutSolved= txIntNum = rxPkthdrRunoutNum = rxMbufRunoutNum = rxPktErrorNum = txPktErrorNum = 0;
	rxPktCounter = txPktCounter = linkChanged=0;

	//All Ring buffers allocated. Now initialize all rings and swNic itself.
	return  swNic_setup(totalRxPkthdr,totalRxMbuf,totalTxPkthdr);
}
#endif


/*************************************************************************
*   FUNCTION                                                              
*       swNic_installedProcessInputPacket                                         
*                                                                         
*   DESCRIPTION                                                           
*       This function installs given function as the handler of received  
*       packets.
*                                                                         
*   INPUTS                                                                
*       nRxPkthdrDesc   Number of Rx pkthdr descriptors.
*       nRxMbufDesc     Number of Tx mbuf descriptors.
*       nTxPkthdrDesc   Number of Tx pkthdr descriptors.
*       clusterSize     Size of cluster.
*                                                                         
*   OUTPUTS                                                               
*       Status.
*************************************************************************/
proc_input_pkt_funcptr_t swNic_installedProcessInputPacket(
                            proc_input_pkt_funcptr_t processInputPacket)
{
    proc_input_pkt_funcptr_t ret = installedProcessInputPacket;
    installedProcessInputPacket = processInputPacket;
    
    return ret;
}



#ifdef CONFIG_RTL865X_CLE
static int32 swNic_getCounters(swNicCounter_t * counter) {
    counter->rxIntNum = rxIntNum;
    counter->txIntNum = txIntNum;
    counter->rxPkthdrRunoutNum = rxPkthdrRunoutNum;
	counter->rxPkthdrRunoutSolved=rxPkthdrRunoutSolved;
    counter->rxMbufRunoutNum = rxMbufRunoutNum;
    counter->rxPktErrorNum = rxPktErrorNum;
    counter->txPktErrorNum = txPktErrorNum;
    counter->rxPktCounter = rxPktCounter;
    counter->txPktCounter = txPktCounter;

#ifdef CONFIG_RTL865XC 

    counter->currRxPkthdrDescIndex0 = rxPhdrIndex0;
    counter->currRxPkthdrDescIndex1 = rxPhdrIndex1;
    counter->currRxPkthdrDescIndex2 = rxPhdrIndex2;
    counter->currRxPkthdrDescIndex3 = rxPhdrIndex3;
    counter->currRxPkthdrDescIndex4 = rxPhdrIndex4;
    counter->currRxPkthdrDescIndex5 = rxPhdrIndex5;	
	
    counter->currRxMbufDescIndex0 = rxMbufIndex0;
	
    counter->currTxPkthdrDescIndex0 = txDoneIndex0;
    counter->currTxPkthdrDescIndex1 = txDoneIndex1;

    counter->freeTxPkthdrDescIndex0 = txFreeIndex0;
    counter->freeTxPkthdrDescIndex1 = txFreeIndex1;

#else
	
    counter->currRxPkthdrDescIndex = rxPhdrIndex;
    counter->currRxMbufDescIndex = rxMbufIndex;
    counter->currTxPkthdrDescIndex = txDoneIndex;
    counter->freeTxPkthdrDescIndex = txFreeIndex;
#endif
	
    counter->rxIntNum = rxIntNum;
    counter->txIntNum = txIntNum;
	counter->linkChanged = linkChanged;
    return SUCCESS;
}
static int32 swNic_resetCounters(void) {
	rxIntNum= txIntNum=rxPkthdrRunoutNum=rxPkthdrRunoutSolved=rxMbufRunoutNum=0;
	rxPktErrorNum= txPktErrorNum = rxPktCounter= txPktCounter= 0;
#ifdef CONFIG_RTL865XC 
	rxPhdrIndex0=rxPhdrIndex1=rxPhdrIndex2=rxPhdrIndex3=rxPhdrIndex4=rxPhdrIndex5=0;
	rxMbufIndex0=txDoneIndex0=txDoneIndex1=txFreeIndex0=txFreeIndex1=0;
#else
	rxPhdrIndex=rxMbufIndex=txDoneIndex=txFreeIndex=0;
#endif
	rxIntNum=txIntNum=0;
    return SUCCESS;
}

static void swNic_dumpPkthdrDescRing(void){
#ifdef CONFIG_RTL865XC 
	uint32  i,j, *temp=(uint32 *)rtlglue_malloc(sizeof(uint32)*(totalRxPkthdr0+totalRxPkthdr1+totalRxPkthdr2+totalRxPkthdr3+totalRxPkthdr4+totalRxPkthdr5));
	uint32 value,asicIdx =0;


	for(j=0;j<6;j++)
	{
		int ringSize=0,pktIndex=0,reclaim=0;
		for(i=0;i<totalRxPkthdr0;i++)
			temp[i]=RxPkthdrRing0[i];



		switch(j)
		{
			case 0:
				rtlglue_printf("\nRx phdr ring %d starts at 0x%x\n",j,(uint32)RxPkthdrRing0 );
				ringSize=totalRxPkthdr0; pktIndex=rxPhdrIndex0; reclaim=lastReclaim0;  
				asicIdx = ((uint32 *)READ_MEM32(CPURPDCR0))-RxPkthdrRing0;
				break;
			case 1:
				rtlglue_printf("\nRx phdr ring %d starts at 0x%x\n",j,(uint32)RxPkthdrRing1 );
				ringSize=totalRxPkthdr1; pktIndex=rxPhdrIndex1; reclaim=lastReclaim1;  
				asicIdx = ((uint32 *)READ_MEM32(CPURPDCR1))-RxPkthdrRing1;
				break;
			case 2:
				rtlglue_printf("\nRx phdr ring %d starts at 0x%x\n",j,(uint32)RxPkthdrRing2 );
				ringSize=totalRxPkthdr2; pktIndex=rxPhdrIndex2; reclaim=lastReclaim2;  
				asicIdx = ((uint32 *)READ_MEM32(CPURPDCR2))-RxPkthdrRing2;
				break;
			case 3:
				rtlglue_printf("\nRx phdr ring %d starts at 0x%x\n",j,(uint32)RxPkthdrRing3 );				
				ringSize=totalRxPkthdr3; pktIndex=rxPhdrIndex3; reclaim=lastReclaim3;  
				asicIdx = ((uint32 *)READ_MEM32(CPURPDCR3))-RxPkthdrRing3;				
				break;
			case 4:
				rtlglue_printf("\nRx phdr ring %d starts at 0x%x\n",j,(uint32)RxPkthdrRing4 );
				ringSize=totalRxPkthdr4; pktIndex=rxPhdrIndex4; reclaim=lastReclaim4;  
				asicIdx = ((uint32 *)READ_MEM32(CPURPDCR4))-RxPkthdrRing4;				
				break;
			case 5:
				rtlglue_printf("\nRx phdr ring %d starts at 0x%x\n",j,(uint32)RxPkthdrRing5 );
				ringSize=totalRxPkthdr5; pktIndex=rxPhdrIndex5; reclaim=lastReclaim5;  
				asicIdx = ((uint32 *)READ_MEM32(CPURPDCR5))-RxPkthdrRing5;				
				break;
		}



		for(i=0;i<ringSize;i++){
			struct rtl_pktHdr *ph;
			struct rtl_mBuf *m;
			value=temp[i];
			ph=(struct rtl_pktHdr *)(value &~0x3);
			rtlglue_printf("%03d.",(uint16)i);
			if(ph){
				rtlglue_printf("p:%08x ",value &~0x3);
				m=ph->ph_mbuf;
				if(m)
					rtlglue_printf("m:%08x c:%08x d:%08x", (uint32)m, (uint32)m->m_extbuf, (uint32)m->m_data);
				else
					rtlglue_printf("No mbuf!! ");
			}else
				rtlglue_printf("No pkthdr!! ");
			rtlglue_printf("%s ", ((value & 1)== 0)?"(CPU)":"(SWC)");
			if(asicIdx==i)
				rtlglue_printf("ASIC ");
			
			if(pktIndex==i)
				rtlglue_printf("Rx ");
			
			if(reclaim==i)
				rtlglue_printf("Reclaim ");
			
			if((value & 2)== 2){
				rtlglue_printf("WRAP!!\n");
				return;
			}else
				rtlglue_printf("\n");
		}
	}
	
	rtlglue_free(temp);

	
	
#else
	uint32  i, *temp=(uint32 *)rtlglue_malloc(sizeof(uint32)*totalRxPkthdr);
	uint32 value,asicIdx = ((uint32 *)READ_MEM32(CPURPDCR))-RxPkthdrRing;
	for(i=0;i<totalRxPkthdr;i++)
		temp[i]=RxPkthdrRing[i];

	rtlglue_printf("Rx phdr ring starts at 0x%x\n",(uint32)RxPkthdrRing );

	for(i=0;i<totalRxPkthdr;i++){
		struct rtl_pktHdr *ph;
		struct rtl_mBuf *m;
		value=temp[i];
		ph=(struct rtl_pktHdr *)(value &~0x3);
		rtlglue_printf("%03d.",(uint16)i);
		if(ph){
			rtlglue_printf("p:%08x ",value &~0x3);
			m=ph->ph_mbuf;
			if(m)
				rtlglue_printf("m:%08x c:%08x d:%08x", (uint32)m, (uint32)m->m_extbuf, (uint32)m->m_data);
			else
				rtlglue_printf("No mbuf!! ");
		}else
			rtlglue_printf("No pkthdr!! ");
		rtlglue_printf("%s ", ((value & 1)== 0)?"(CPU)":"(SWC)");
		if(asicIdx==i)
			rtlglue_printf("ASIC ");
		if(rxPhdrIndex==i)
			rtlglue_printf("Rx ");
		if(lastReclaim==i)
			rtlglue_printf("Reclaim ");
		
		if((value & 2)== 2){
			rtlglue_printf("WRAP!!\n");
			return;
		}else
			rtlglue_printf("\n");
	}
	rtlglue_free(temp);
	#endif
}


void swNic_dumpTxDescRing(void){	

#ifdef CONFIG_RTL865XC 

	int32 i,j,ringSize=0,asicIdx=0,txDoneIdx=0,txFreeIdx=0;
	uint32 value=0;

	for(j=0;j<2;j++)
	{
		switch(j)
		{
			case 0:
				ringSize=totalTxPkthdr0; txDoneIdx=txDoneIndex0; txFreeIdx=txFreeIndex0;
				 asicIdx = ((uint32 *)READ_MEM32(CPUTPDCR0))-TxPkthdrRing0;
				 rtlglue_printf("\nTx phdr ring %d starts at 0x%x\n",j,(uint32)TxPkthdrRing0 );
				 break;
			case 1:
				ringSize=totalTxPkthdr1;txDoneIdx=txDoneIndex1; txFreeIdx=txFreeIndex1;
				 asicIdx = ((uint32 *)READ_MEM32(CPUTPDCR1))-TxPkthdrRing1;
				 rtlglue_printf("\nTx phdr ring %d starts at 0x%x\n",j,(uint32)TxPkthdrRing1 );
				 break;				 
		}
		
		
		
		for(i=0; i<ringSize; i++){
			volatile struct rtl_pktHdr *ph;
			volatile struct rtl_mBuf *m;

			switch(j)
			{
				case 0:
					value=TxPkthdrRing0[i]; break;
				case 1:
					value=TxPkthdrRing1[i]; break;					
			}
			ph=(struct rtl_pktHdr *)(value &~0x3);
			if(ph){
				rtlglue_printf("%3d. p%08x ", i,(uint32)ph);
				m=ph->ph_mbuf;
				if(m)
					rtlglue_printf("m:%08x d:%08x",(uint32)m,(uint32)m->m_data);
				else
					rtlglue_printf("m=NULL");
			}else
				rtlglue_printf("%3d. p:NULL", i);
			rtlglue_printf("%s ", ((value & 1)== 0)?"(CPU)":"(SWC)");
			if(ph){
				rtlglue_printf("id:%d ", ph->ph_rxdesc);
				rtlglue_printf("s%d:e%02x:p%03x", ph->ph_srcExtPortNum, ph->ph_extPortList, ph->ph_portlist);
			}
			if(asicIdx==i)
				rtlglue_printf("ASIC ");
			if(txDoneIdx==i)
				rtlglue_printf("Done ");
			if(txFreeIdx==i)
				rtlglue_printf("Next ");
			if((value & 2)== 2){
				rtlglue_printf("WRAP!!\n");
				return;
			}else
				rtlglue_printf("\n");
		}
	}
	return;

	
#else

	int32 i;
	uint32 value, asicIdx = ((uint32 *)READ_MEM32(CPUTPDCR))-TxPkthdrRing;
	rtlglue_printf("Tx phdr ring starts at 0x%x\n",(uint32)TxPkthdrRing );
	for(i=0; i<totalTxPkthdr; i++){
		volatile struct rtl_pktHdr *ph;
		volatile struct rtl_mBuf *m;
		value=TxPkthdrRing[i];
		ph=(struct rtl_pktHdr *)(value &~0x3);
		if(ph){
			rtlglue_printf("%3d. p%08x ", i,(uint32)ph);
			m=ph->ph_mbuf;
			if(m)
				rtlglue_printf("m:%08x d:%08x",(uint32)m,(uint32)m->m_data);
			else
				rtlglue_printf("m=NULL");
		}else
			rtlglue_printf("%3d. p:NULL", i);
		rtlglue_printf("%s ", ((value & 1)== 0)?"(CPU)":"(SWC)");
		if(ph){
			rtlglue_printf("id:%d ", ph->ph_rxdesc);
			rtlglue_printf("s%d:e%02x:p%03x", ph->ph_srcExtPortNum, ph->ph_extPortList, ph->ph_portlist);
		}
		if(asicIdx==i)
			rtlglue_printf("ASIC ");
		if(txDoneIndex==i)
			rtlglue_printf("Done ");
		if(txFreeIndex==i)
			rtlglue_printf("Next ");
		if((value & 2)== 2){
			rtlglue_printf("WRAP!!\n");
			return;
		}else
			rtlglue_printf("\n");
	}
	return;
#endif	

}

static int32 loopbackPort1,loopbackPort2;
static void re865x_testL2loopback(struct rtl_pktHdr * pPkt)
{
	if(pPkt->ph_portlist ==loopbackPort1)
		pPkt->ph_portlist = 1<<loopbackPort2;
	else
		pPkt->ph_portlist = 1<<loopbackPort1;
	swNic_write((void *) pPkt);
}


static proc_input_pkt_funcptr_t old_funcptr=NULL;
static int32	swNic_loopbackCmd(uint32 userId,  int32 argc,int8 **saved){
	int8 *nextToken;
	int32 size;
	cle_getNextCmdToken(&nextToken,&size,saved); 
	if(strcmp(nextToken, "enable") == 0){
//		REG32(MSCR)&=~0x7;//disable L2~L4
		WRITE_MEM32(MSCR,READ_MEM32(MSCR)&(~0x7));
		cle_getNextCmdToken(&nextToken,&size,saved); 
		loopbackPort1=U32_value(nextToken);
		cle_getNextCmdToken(&nextToken,&size,saved); 
		loopbackPort2=U32_value(nextToken);
	     old_funcptr = swNic_installedProcessInputPacket((proc_input_pkt_funcptr_t)re865x_testL2loopback);
		rtlglue_printf("Turn off ASIC L2/3/4 functions. Enter NIC loopback mode. Bridge pkts between port %d and %d\n", loopbackPort1, loopbackPort2);
	}else if(old_funcptr){
		rtlglue_printf("Turn on ASIC L2/3/4 functions. Exit NIC loopback mode\n");
	       swNic_installedProcessInputPacket(old_funcptr);
//		REG32(MSCR)|=0x7;//enable L2~L4
		WRITE_MEM32(MSCR,READ_MEM32(MSCR)|0x7);
	}else 
		return FAILED;
	return SUCCESS;
}

static uint32 hubMbrmask;

static void swNic_hubMode(struct rtl_pktHdr * pPkt)
{
	uint16 bcastPorts = 0x1f & ~(1<<pPkt->ph_portlist);
	pPkt->ph_portlist = bcastPorts;
	swNic_write((void *) pPkt);
}


static int32	swNic_hubCmd(uint32 userId,  int32 argc,int8 **saved){
	int8 *nextToken;
	int32 size;
	cle_getNextCmdToken(&nextToken,&size,saved); 
	if(strcmp(nextToken, "enable") == 0){
		hubMbrmask=0;
//		REG32(MSCR)&=~0x7;//disable L2~L4
		WRITE_MEM32(MSCR,READ_MEM32(MSCR)&(~0x7));
		while(cle_getNextCmdToken(&nextToken,&size,saved) !=FAILED){
			uint32 thisPort;
			thisPort=U32_value(nextToken);
			if(thisPort<5)
				hubMbrmask|=(1<<thisPort);
		}
	     old_funcptr = swNic_installedProcessInputPacket((proc_input_pkt_funcptr_t)swNic_hubMode);
		rtlglue_printf("Turn off ASIC L2/3/4 functions. Enter Hub mode. Portmask:%08x\n", hubMbrmask);
	}else if(old_funcptr){
		rtlglue_printf("Turn on ASIC L2/3/4 functions. Exit Hub mode\n");
	       swNic_installedProcessInputPacket(old_funcptr);
//		REG32(MSCR)|=0x7;//enable L2~L4
		WRITE_MEM32(MSCR,READ_MEM32(MSCR)|0x7);
	}else 
		return FAILED;
	return SUCCESS;
}


static int32	swNic_counterCmd(uint32 userId,  int32 argc,int8 **saved){
	int8 *nextToken;
	int32 size;

	cle_getNextCmdToken(&nextToken,&size,saved); 
	if(strcmp(nextToken, "dump") == 0){
		swNicCounter_t counter;
		rtlglue_printf("Switch NIC statistics:\n\n");
		swNic_getCounters(&counter);
		rtlglue_printf("rxIntNum: %u, txIntNum: %u, pktRunout: %u, , rxErr: %u, txErr: %u\n",
			counter.rxIntNum, counter.txIntNum, counter.rxPkthdrRunoutNum,  counter.rxPktErrorNum, counter.txPktErrorNum);
		rtlglue_printf("Interrupt register 0x%08x interrupt mask 0x%08x\n", READ_MEM32(CPUIISR), READ_MEM32(CPUIIMR));
		rtlglue_printf("Rx Packet Counter: %d Tx Packet Counter: %d\n", counter.rxPktCounter, counter.txPktCounter);
		rtlglue_printf("Run Out: %d Rx solved: %d linkChanged: %d\n", counter.rxPkthdrRunoutNum, counter.rxPkthdrRunoutSolved, counter.linkChanged);

#ifdef CONFIG_RTL865XC 
		rtlglue_printf("currRxPkthdrDescIndex0: %d\ncurrRxPkthdrDescIndex1: %d\ncurrRxPkthdrDescIndex2: %d\ncurrRxPkthdrDescIndex3: %d\ncurrRxPkthdrDescIndex4: %d\ncurrRxPkthdrDescIndex5: %d\ncurrRxMbufDescIndex0: %d\n",
		counter.currRxPkthdrDescIndex0,
		counter.currRxPkthdrDescIndex1,
		counter.currRxPkthdrDescIndex2,
		counter.currRxPkthdrDescIndex3,
		counter.currRxPkthdrDescIndex4,
		counter.currRxPkthdrDescIndex5,
		counter.currRxMbufDescIndex0);
		rtlglue_printf("currTxPkthdrDescIndex0: %d, currTxPkthdrDescIndex1: %d\nfreeTxPkthdrDescIndex0: %d, freeTxPkthdrDescIndex1: %d\n",counter.currTxPkthdrDescIndex0,counter.currTxPkthdrDescIndex1, counter.freeTxPkthdrDescIndex0, counter.freeTxPkthdrDescIndex1);
#else
		rtlglue_printf("currRxPkthdrDescIndex: %d currRxMbufDescIndex: %d\n",counter.currRxPkthdrDescIndex,counter.currRxMbufDescIndex);
		rtlglue_printf("currTxPkthdrDescIndex: %d freeTxPkthdrDescIndex: %d\n",counter.currTxPkthdrDescIndex, counter.freeTxPkthdrDescIndex);
#endif
		rtlglue_printf("ASIC dropped %d.\n", rtl8651_returnAsicCounter(0x4));

	}else{
		rtlglue_printf("Reset all NIC internal counters\n");
		swNic_resetCounters();

	}
	return SUCCESS;
}

static int32	swNic_cmd(uint32 userId,  int32 argc,int8 **saved){
	int8 *nextToken;
	int32 size;

	cle_getNextCmdToken(&nextToken,&size,saved); 
	if(strcmp(nextToken, "burst") == 0){
		cle_getNextCmdToken(&nextToken,&size,saved); 
#ifdef SWNIC_EARLYSTOP
		nicRxEarlyStop = U32_value( nextToken );
#endif
	}else if(strcmp(nextToken, "rx") == 0){
		cle_getNextCmdToken(&nextToken,&size,saved); 
		if(strcmp(nextToken, "suspend") == 0)
			swNic_txRxSwitch(txEnable, 0);
		else
			swNic_txRxSwitch(txEnable, 1);
	}else if(strcmp(nextToken, "tx") == 0){
		cle_getNextCmdToken(&nextToken,&size,saved); 	
		if(strcmp(nextToken, "suspend") == 0)
			swNic_txRxSwitch(0, rxEnable);
		else
			swNic_txRxSwitch(1, rxEnable);
	}
	return SUCCESS;
}

#ifdef SWNIC_DEBUG
static int32	swNic_pktdumpCmd(uint32 userId,  int32 argc,int8 **saved){
	int8 *nextToken;
	int32 size;
	int rx=0;
	cle_getNextCmdToken(&nextToken,&size,saved); 

	if(strcmp(nextToken, "rx") == 0){
		rx=1;
	}else if(strcmp(nextToken, "tx") == 0){
		rx=0;
	}

	cle_getNextCmdToken(&nextToken,&size,saved); 
	if(strcmp(nextToken, "all") == 0){
		if(rx)
			nicDbgMesg=NIC_RX_PKTDUMP;			
		else
			nicDbgMesg=NIC_TX_PKTDUMP;
	}else if(strcmp(nextToken, "phy") == 0){
		if(rx)
			nicDbgMesg|=NIC_PHY_RX_PKTDUMP;			
		else
			nicDbgMesg|=NIC_PHY_TX_PKTDUMP;
	}else if(strcmp(nextToken, "ps") == 0){
		if(rx)
			nicDbgMesg|=NIC_PS_RX_PKTDUMP;			
		else
			nicDbgMesg|=NIC_PS_TX_PKTDUMP;
	}else if(strcmp(nextToken, "ext") == 0){
		if(rx)
			nicDbgMesg|=NIC_EXT_RX_PKTDUMP;			
		else
			nicDbgMesg|=NIC_EXT_TX_PKTDUMP;
	}else{
		if(rx)
			nicDbgMesg&=~NIC_RX_PKTDUMP;
		else
			nicDbgMesg&=~NIC_TX_PKTDUMP;
	}
	return SUCCESS;
}
#endif


static int32	swNic_ringCmd(uint32 userId,  int32 argc,int8 **saved){
	int8 *nextToken;
	int32 size;
	cle_getNextCmdToken(&nextToken,&size,saved); 
	if(strcmp(nextToken, "mbufRxRing") == 0) {

#ifdef CONFIG_RTL865XC	

		uint32  i, value, asicIdx = ((uint32 *)READ_MEM32(CPURMDCR0))-RxMbufRing0;
		rtlglue_printf("Rx mbuf ring starts at 0x%x\n",(uint32)RxMbufRing0 );
		for(i=0;i<totalRxMbuf0;i++){
			value=RxMbufRing0[i];
			rtlglue_printf("%3d. 0x%08x ",i, value&~0x3 );
			rtlglue_printf("%s ", ((value & 1)== 0)?"(CPU)":"(SWC)");
			if(asicIdx==i)
				rtlglue_printf("ASIC ");
			if(rxMbufIndex0==i)
				rtlglue_printf("Rx ");
			if((value & 2)== 2){
				rtlglue_printf("WRAP!!\n");
				return SUCCESS;
			}else
				rtlglue_printf("\n");
		}
#else

		uint32  i, value, asicIdx = ((uint32 *)READ_MEM32(CPURMDCR))-RxMbufRing;
		rtlglue_printf("Rx mbuf ring starts at 0x%x\n",(uint32)RxMbufRing );
		for(i=0;i<totalRxMbuf;i++){
			value=RxMbufRing[i];
			rtlglue_printf("%3d. 0x%08x ",i, value&~0x3 );
			rtlglue_printf("%s ", ((value & 1)== 0)?"(CPU)":"(SWC)");
			if(asicIdx==i)
				rtlglue_printf("ASIC ");
			if(rxMbufIndex==i)
				rtlglue_printf("Rx ");
			if((value & 2)== 2){
				rtlglue_printf("WRAP!!\n");
				return SUCCESS;
			}else
				rtlglue_printf("\n");
		}
#endif		
	}else if(strcmp(nextToken, "pkthdrRxRing") == 0) {
		swNic_dumpPkthdrDescRing();
		return SUCCESS;
	}else if(strcmp(nextToken, "txRing") == 0) {	
		swNic_dumpTxDescRing();
		return SUCCESS;
	}else{
		struct rtl_mBufStatus mbs;
		rtlglue_printf("Reset all NIC rings...\n");
		swNic_descRingCleanup();
		rtlglue_printf("  Init all NIC rings...\n");
#ifdef CONFIG_RTL865XC
		swNic_setup(totalRxPkthdr0,totalRxPkthdr1,totalRxPkthdr2,totalRxPkthdr3,totalRxPkthdr4,totalRxPkthdr5,
					totalRxMbuf0,
					totalTxPkthdr0,totalTxPkthdr1);
#else
		swNic_setup(totalRxPkthdr, totalRxMbuf, totalTxPkthdr);
#endif
		rtlglue_printf("  mbuf pool...\n");
		if(mBuf_getBufStat(&mbs)==SUCCESS){
			rtlglue_printf( "\tSizeof\tTotal\tFree\n");
			rtlglue_printf( "Cluster\t%d\t%d\t%d\n",mbs.m_mclbytes, mbs.m_totalclusters, mbs.m_freeclusters);
			rtlglue_printf( "Mbuf\t%d\t%d\t%d\n",mbs.m_msize, mbs.m_totalmbufs, mbs.m_freembufs);
			rtlglue_printf( "Pkthdr\t%d\t%d\t%d\n",mbs.m_pkthdrsize, mbs.m_totalpkthdrs, mbs.m_freepkthdrs);
		}
	
	}
	return SUCCESS;
}


cle_exec_t swNic_cmds[] = {
	{	"counter",
		"Dump NIC internal counters",
		"{ dump | clear }",
		swNic_counterCmd,
		CLE_USECISCOCMDPARSER,	
		0,
		0
	},
	{
		"loopback",		//cmdStr
		"Layer2 loopback.",	//cmdDesc
		" { enable %d'loopback port 1' %d'loopback port 2' | disable }",  //usage
		swNic_loopbackCmd,		//execution function
		CLE_USECISCOCMDPARSER,	
		0,
		NULL
	},	
#ifdef SWNIC_DEBUG	
	{	"pktdump",
		"NIC pkt dump debug message on/off",
		"{ { rx'Turn on Rx pkt dump' | tx'Turn on Tx pkt dump' }  { all'Dump all' | phy'physical port' | ps'protocol stack' | ext'extension port' | off } }",
		swNic_pktdumpCmd,
		CLE_USECISCOCMDPARSER,	
		0,
		0
	},
#endif		
	{
		"hub",		//cmdStr
		"Hub mode",	//cmdDesc
		" { enable (1~5)%d'Hub member port' | disable }",  //usage
		swNic_hubCmd,		//execution function
		CLE_USECISCOCMDPARSER,	
		0,
		NULL
	},
	{	"ring",
		"NIC internal ring cmd",
		"{ txRing'dump Tx ring' | pkthdrRxRing'dump Rx ring' | mbufRxRing'dump Rx mbuf ring' | reset'Reset all rescriptor rings and NIC.' }",
		swNic_ringCmd,
		CLE_USECISCOCMDPARSER,	
		0,
		0
	},
	{	"cmd",
		"NIC internal cmds",
		"{ burst  %d'#( 2^n-1) of continuous pkt processed in ISR, 0 for infinite' | { { tx | rx } { suspend | resume } } }",
		swNic_cmd,
		CLE_USECISCOCMDPARSER,	
		0,
		0
	},
};
#endif



