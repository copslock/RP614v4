/*
* --------------------------------------------------------------------
* Copyright c                  Realtek Semiconductor Corporation, 2003  
* All rights reserved.
* 
* Program : 8651B authentication engine driver code
* Abstract : 
* $Id: rtl865xc_authEngine.c,v 1.1 2005/11/01 03:22:38 yjlou Exp $
* --------------------------------------------------------------------
*/

#include "rtl865xc_authEngine.h"
#include <linux/autoconf.h>
#include <asicRegs.h>
#include "md5.h"
#include "sha1.h"
#include "hmac.h"
#include <assert.h>

static uint8 * rtl8651b_authEngineInputPad, * rtl8651b_authEngineOutputPad;
static uint8 * rtl8651b_authEngineMd5TempKey, *rtl8651b_authEngineSha1TempKey;
static uint32 authDoneIntCounter, authAllDoneIntCounter;

/* Louis note: if you want to use __DRAM, remember to initial this variable in init(). */
__DRAM_CRYPTO static uint8 rtl8651b_authEngine_paddat[RTL8651B_MAX_MD_CBLOCK];

int32 rtl8651b_authEngine_init(uint32 descNum, int8 mode32Bytes)
{
	int i;
	
	/*
	 * Louis note:
	 * Once you enable __DRAM for rtl8651b_authEngine_paddat[],
	 *   you MUST re-initialize rtl8651b_authEngine_paddat[] again.
	 */
	rtl8651b_authEngine_paddat[0] = 0x80;
	for( i = 1; i < RTL8651B_MAX_MD_CBLOCK; i++ )
	{
		rtl8651b_authEngine_paddat[i] = 0x0;
	}

	/* To be compelete */

	return SUCCESS;
}


/*
@func int32	| rtl8651b_authEngine	| Provide authentication function
@parm uint32	| HASH_MD5/HASH_SHA1/HMAC_MD5/HMAC_SHA1, and bit-wised IOPAD_READY when ipad/opad are pre-computed.
@parm uint8* 	| data	| data to be authenticated.
@parm uint32	| dataLen	| data length
@parm uint8* 	| key		| key (when IOPAD_READY is set, key is pointed to ipad and opad)
@parm uint32	| keyLen	| key length
@parm uint8 * 	| digest	| output digest data
@rvalue SUCCESS	| A pair of <p extIp> and <p extPort> selected. 
@rvalue FAILED 	| Failed to select either <p extIp> or <p extPort>.
@comm 
@devnote
 */
int32 rtl8651b_authEngine(uint32 mode, uint8 * data, uint32 dataLen, uint8 * key, uint32 keyLen, uint8 * digest) 
{
	MD5_CTX md5Context;
	SHA1_CTX sha1Context;
	uint32 i, dmaLen;
	uint64 len64;
	uint8 *uint8Ptr = (uint8 *)&len64;
	uint8 *ipad, *opad;

	assert(data && digest);//Either Hashing or key must exist
	//Calculating ipad and opad
	if(mode&0x2) {//HMAC
		assert(key);
		if(keyLen > HMAC_MAX_MD_CBLOCK) {
			if(mode&0x1) {
				SHA1Init(&sha1Context);
				SHA1Update(&sha1Context, key, keyLen);
				SHA1Final(rtl8651b_authEngineSha1TempKey, &sha1Context);
				key = rtl8651b_authEngineSha1TempKey;
				keyLen = SHA_DIGEST_LENGTH;
			}
			else {
				MD5Init(&md5Context);
				MD5Update(&md5Context, key, keyLen);
				MD5Final(rtl8651b_authEngineMd5TempKey, &md5Context);
				key = rtl8651b_authEngineMd5TempKey;
				keyLen = MD5_DIGEST_LENGTH;
			}
		}
		
		if ( mode & RTL8651_AUTH_IOPAD_READY )
		{
			/* ipad and opad is pre-computed. */
			ipad = key;
			opad = key + RTL8651B_MAX_MD_CBLOCK;
		}
		else
		{
			memset(rtl8651b_authEngineInputPad, 0x36, RTL8651B_MAX_MD_CBLOCK);
			memset(rtl8651b_authEngineOutputPad, 0x5c, RTL8651B_MAX_MD_CBLOCK);
			for(i=0; i<keyLen; i++) {
				rtl8651b_authEngineInputPad[i] ^= key[i];
				rtl8651b_authEngineOutputPad[i] ^= key[i];
			}
			ipad = rtl8651b_authEngineInputPad;
			opad = rtl8651b_authEngineOutputPad;
		}
	}
	//Do padding for MD5 and SHA-1
	i = RTL8651B_MAX_MD_CBLOCK - (dataLen&0x3F);
	if(i>8) {
		memcpy((void *)(data + dataLen), (void *)rtl8651b_authEngine_paddat, i-8);
		dmaLen = (dataLen+64)&0xFFFFFFC0;
	}
	else {
		memcpy((void *)(data + dataLen), (void *)rtl8651b_authEngine_paddat, i+56);
		dmaLen = (dataLen+72)&0xFFFFFFC0;
	}
	if(dmaLen & 0xFFFFF000)
		return FAILED;//DMA length larger than 8651b can support
	if(mode&0x2) //HMAC
		len64 = (dataLen+64)<<3;//First padding length is
	else
		len64 = dataLen<<3;//First padding length is
	for(i=0; i<8; i++) {
		if(mode&0x1) //SHA-1
			data[dmaLen-8+i] = uint8Ptr[i];
		else
			data[dmaLen-i-1] = uint8Ptr[i];
	}

	/* To be completed */

	if(mode&0x1)
		memcpy(digest, rtl8651b_authEngineSha1TempKey, RTL8651B_SHA1_DIGEST_LENGTH);//Avoid 4-byte alignment limitation
	else
		memcpy(digest, rtl8651b_authEngineMd5TempKey, RTL8651B_MD5_DIGEST_LENGTH);//Avoid 4-byte alignment limitation
	
	return SUCCESS;
}


void rtl8651b_authEngineGetIntCounter(uint32 * doneCounter, uint32 * allDoneCounter) {
	*doneCounter = authDoneIntCounter;
	*allDoneCounter = authAllDoneIntCounter;
}

