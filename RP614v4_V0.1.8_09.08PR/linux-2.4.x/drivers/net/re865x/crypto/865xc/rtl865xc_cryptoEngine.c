/*
* --------------------------------------------------------------------
* Copyright c                  Realtek Semiconductor Corporation, 2003  
* All rights reserved.
* 
* Program : 8651B crypto engine driver code
* Abstract : 
* $Id: rtl865xc_cryptoEngine.c,v 1.1 2005/11/01 03:22:38 yjlou Exp $
*
* --------------------------------------------------------------------
*/

#include "rtl865xc_cryptoEngine.h"
#include "crypto.h"
#ifdef CONFIG_RTL865X_MODEL_KERNEL
#include "modelTrace.h"
#include "icExport.h"
#endif
#include <linux/autoconf.h>
#include <asicRegs.h>
#include <rtl_glue.h>
#include <rtl_utils.h>
#include <assert.h>


static uint32 numSrc, numDst; /* the number of source & destination descriptor */
static uint32 idxCpuSrc, idxAsicSrc;
static uint32 idxCpuDst, idxAsicDst;

/*
Assumption:
1. rtlglue_malloc() can get 4-byte aligned memory block
*/
rtl865xc_crypto_source_t *ipssdar;
rtl865xc_crypto_dest_t *ipsddar;
/*Counters for interrupt*/
static uint32 cryptoDoneIntCounter, cryptoAllDoneIntCounter;


int32 rtl8651b_cryptoEngine_init(uint32 descNum, int8 mode32Bytes) 
{
	uint32 burstSize;
	void *p; /* for memory allocate */

	/* mode32Bytes==0 or 1 is backward-compatible */
	if ( mode32Bytes==0 ) burstSize = IPS_DMBS_16|IPS_SMBS_16;
	else if ( mode32Bytes==1 ) burstSize = IPS_DMBS_32|IPS_SMBS_32;
	else if ( mode32Bytes==2 ) burstSize = IPS_DMBS_64|IPS_SMBS_64;
	else if ( mode32Bytes==3 ) burstSize = IPS_DMBS_128|IPS_SMBS_128;
	else return FAILED;

	if ( descNum == 0 ) return FAILED;
	if ( descNum < 3 ) return FAILED; /* key+iv+data */
	
	/* Software Reset */
	WRITE_MEM32( IPSCSR, IPS_SRST );

	/* Allocate descriptor ring */
	p = rtlglue_malloc( descNum * sizeof( rtl865xc_crypto_source_t ) );
	if ( p == NULL ) { rtlglue_printf("%s():%d memory allocate failed.\n", __FUNCTION__, __LINE__ ); return FAILED; }
	ipssdar = UNCACHED_ADDRESS(p);
	memset( ipssdar, 0, descNum * sizeof( rtl865xc_crypto_source_t ) );
	WRITE_MEM32( IPSSDAR, PHYSICAL_ADDRESS((uint32)ipssdar) );
	ipssdar[descNum-1].eor = 1;

	/* Allocate descriptor ring */
	p = rtlglue_malloc( descNum * sizeof( rtl865xc_crypto_dest_t ) );
	if ( p == NULL ) { rtlglue_printf("%s():%d memory allocate failed.\n", __FUNCTION__, __LINE__ ); return FAILED; }
	ipsddar = UNCACHED_ADDRESS(p);
	memset( ipsddar, 0, descNum * sizeof( rtl865xc_crypto_dest_t ) );
	WRITE_MEM32( IPSDDAR, PHYSICAL_ADDRESS((uint32)ipsddar) );
	ipsddar[descNum-1].eor = 1;

	/* save source & destination descriptor number */
	numSrc = numDst = descNum;
	idxCpuSrc = idxAsicSrc = 0;
	idxCpuDst = idxAsicDst = 0;

	/* We must delay a while after software reset. */
	WRITE_MEM32( IPSCTR, IPS_SDUEIP|IPS_SDLEIP|IPS_DDUEIP|IPS_DDOKIP|0/*IPS_SWAB*/|IPS_CKE|burstSize );

	return SUCCESS;
}


int32 rtl8651b_cryptoMemcpy(void *dest)
{
	return FAILED;
}

/*data, key and iv does not have 4-byte alignment limitatiuon
 *mode bits:
     0x20 DES  / AES
 * 0x01:  3DES   none
 * 0x02:  ECB    ECB
 * 0x04:  Enc    Enc
 * 0x08:  nBlk   nBlk
 * 0x10:  DMA    DMA
 *
 * AES_CTR:0x03
*/
int32 rtl8651b_cryptoEngine_des(uint32 mode, int8 *data, uint32 len, int8 *key, int8 *iv ) 
{
	static rtl865xc_crypto_source_t prepSrc[3]; /* MS=00: KeyArray+IvArray+Data1 */
	static rtl865xc_crypto_dest_t prepDst[1]; /* MS=00: KeyArray+IvArray+Data1 */
	uint32 prepNum = 0; /* the number of descriptor prepare to write ASIC */
	int i;

	memset( prepSrc, 0, sizeof(prepSrc) );
	memset( prepDst, 0, sizeof(prepDst) );

	if(len & 0x7)
		return FAILED;/*Unable to process not 8-byte aligned data*/

	if ( mode & 0x20 )
	{
		/* AES */
		prepSrc[0].own = 1; /* Own by crypto */
		prepSrc[0].ms = 0; /* Mode Select = AES/DES/3DES */
		prepSrc[0].aeskl = 1; /* AES Key Length = 128 bits */
		switch ( mode & 0x03 )
		{
			case 0x00:
				prepSrc[0].cbc = 1;
				break;
			case 0x02:
				prepSrc[0].cbc = 0;
				break;
			case 0x03:
				prepSrc[0].ctr = 1;
				break;
			default:
				return FAILED;
				break;
		}
		if ( mode & 0x04 )
		{
			prepSrc[0].kam = 7; /* Key Application Mechanism: Encryption */
		}
		else
		{
			prepSrc[0].kam = 0; /* Key Application Mechanism: Decryption */
		}

		/* first descriptor: Key Array */
		prepSrc[0].fs = 1;
		prepSrc[0].sbl = 128/8; /* Key Array Length */
		prepSrc[0].a2eo = 0;
		prepSrc[0].enl = len;
		prepSrc[0].apl = 0;
		prepSrc[0].sdbp = (uint32)key;
		
		/* second descriptor: IV Array */
		prepSrc[1].fs = 0;
		prepSrc[1].sbl = 128/8; /* IV Array Length */
		prepSrc[1].a2eo = 0;
		prepSrc[1].enl = len;
		prepSrc[1].apl = 0;
		prepSrc[1].sdbp = (uint32)iv;
		
		/* third descriptor: Data */
		prepSrc[2].fs = 0;
		prepSrc[2].sbl = len; /* Data Length */
		prepSrc[2].a2eo = 0;
		prepSrc[2].enl = len;
		prepSrc[2].apl = 0;
		prepSrc[2].sdbp = (uint32)data;

		prepNum = 3;
	}
	else
	{
		/* DES/3DES */
		prepSrc[0].own = 1; /* Own by crypto */
		prepSrc[0].ms = 0; /* Mode Select = AES/DES/3DES */
		prepSrc[0].aeskl = 0; /* DES/3DES */
		if ( mode & 1 )
		{
			/* 3DES */
			prepSrc[0].trides = 1;
			prepSrc[0].sbl = 24; /* Key Array Length */
			if ( mode & 4 )
				prepSrc[0].kam = 5; /* Encryption */
			else
			{
				static int8 swap[8];
				prepSrc[0].kam = 2; /* Decryption */
				/* swap K1 and K3. */
				memcpy( swap, &key[0], 8 );
				memcpy( &key[0], &key[16], 8 );
				memcpy( &key[16], swap, 8 );
			}
		}
		else
		{
			/* DES */
			prepSrc[0].trides = 0;
			prepSrc[0].sbl = 8; /* Key Array Length */
			if ( mode & 4 )
				prepSrc[0].kam = 7; /* Encryption */
			else
				prepSrc[0].kam = 0; /* Decryption */
		}
		if ( mode & 2 )
			prepSrc[0].cbc = 0; /* ECB */
		else
			prepSrc[0].cbc = 1; /* CBC */
			
		/* first descriptor: Key Array */
		prepSrc[0].fs = 1;
		prepSrc[0].a2eo = 0;
		prepSrc[0].enl = len;
		prepSrc[0].apl = 0;
		prepSrc[0].sdbp = PHYSICAL_ADDRESS( key );
		
		/* second descriptor: IV Array */
		prepSrc[1].own = 1;
		prepSrc[1].fs = 0;
		prepSrc[1].sbl = 8; /* IV Array Length */
		prepSrc[1].a2eo = 0;
		prepSrc[1].enl = len;
		prepSrc[1].apl = 0;
		prepSrc[1].sdbp = PHYSICAL_ADDRESS( iv );
		
		/* third descriptor: Data */
		prepSrc[2].own = 1;
		prepSrc[2].fs = 0;
		prepSrc[2].sbl = len; /* Data Length */
		prepSrc[2].a2eo = 0;
		prepSrc[2].enl = len;
		prepSrc[2].apl = 0;
		prepSrc[2].sdbp = PHYSICAL_ADDRESS( data );

		prepNum = 3;
	}

	/* We assume the CPU and ASIC are pointed to the same descriptor.
	 * However, in async mode, this assumption is invalid.
	 */
	if ( mode & 0x08 )
	{
		/* non-blocking mode, we cannot expect where ASIC is pointing to. */
	}
	else
	{
		/* blocking mode */
		idxAsicSrc = ((rtl865xc_crypto_source_t*)KSEG1_ADDRESS(READ_MEM32( IPSSDAR )))-ipssdar;
		assert( idxAsicSrc == idxCpuSrc );
		idxAsicDst = ((rtl865xc_crypto_dest_t*)KSEG1_ADDRESS(READ_MEM32( IPSDDAR )))-ipsddar;
		assert( idxAsicDst == idxCpuDst );
	}

	/* prepare destination descriptor. */
	prepDst[0].own = 1; /* set owned by ASIC */
	prepDst[0].eor = (idxCpuDst==(numDst-1)); /* If this is the final descriptor, set EOR bit. */
	prepDst[0].dbl = len; /* destination data length */
	prepDst[0].ddbp = PHYSICAL_ADDRESS( data ); /* destination data block pointer */

	/* write prepared descriptors into ASIC */
	/* destination first */
	memcpy( &ipsddar[idxCpuDst], &prepDst[0], sizeof(ipsddar[0]) );
	idxCpuDst = (idxCpuDst+1)%numDst;
	/* then source */
	for( i = 0; i < prepNum; i++ )
	{
		if ( ipssdar[(idxCpuSrc+i)%numSrc].own == 0 )
		{
			/* Owned by CPU, overwrite it ! */
			memcpy( ((char*)&ipssdar[(idxCpuSrc+i)%numSrc])+4, ((char*)&prepSrc[i])+4, sizeof(ipssdar[0])-4 );
			prepSrc[i].eor = (((idxCpuSrc+i)%numSrc)==(numSrc-1)); /* If this is the final descriptor, set EOR bit. */
			memcpy( &ipssdar[(idxCpuSrc+i)%numSrc], &prepSrc[i], sizeof(ipssdar[0]) );
		}
		else
		{
			/* Owned by ASIC.
			 * Currently, we do not support this situation. 
			 * This means one of following:
			 *  1. numSrc < prepNum
			 *  2. async operation is fired
			 */
			return FAILED;
		}
	}
	idxCpuSrc += prepNum;
#if 0
	memDump( (void*)IPSSDAR, 0x10, "Crypto Engine Registers" );
	memDump( &ipssdar[(idxCpuSrc+numSrc-prepNum)%numSrc], sizeof(prepSrc), "ipssdar" );
	memDump( &ipsddar[(idxCpuDst+numDst-1)%numDst], sizeof(prepDst), "ipsddar" );
#endif
#if 1/*def CONFIG_RTL865X_MODEL_KERNEL*/
	modelExportSetIcType( IC_TYPE_REAL );
	modelExportSetOutputForm( EXPORT_RTK_SIM );
	modelExportCryptoRegisters();
#endif

	/* Clear OK flag */
	WRITE_MEM32( IPSCTR, READ_MEM32( IPSCTR ) | IPS_DDOKIP );

	/* kick off crypto engine */
	WRITE_MEM32( IPSCSR, READ_MEM32(IPSCSR)|IPS_POLL );

	if ( mode & 0x08 )
	{
		/* non-blocking mode */
		return SUCCESS;
	}
	else
	{
		/* blocking mode */
		while( ( READ_MEM32( IPSCTR ) & IPS_DDOKIP ) == 0 ); /* wait until crypto engine stop */
		assert( ipsddar[idxCpuDst].own==0 ); 
	}

	return SUCCESS;
}


int32 rtl8651b_cryptoEngine_des_poll(int32 freq)
{
	return SUCCESS;
}


void rtl8651b_cryptoEngineGetIntCounter(uint32 * doneCounter, uint32 * allDoneCounter) {
	*doneCounter = cryptoDoneIntCounter;
	*allDoneCounter = cryptoAllDoneIntCounter;
}


