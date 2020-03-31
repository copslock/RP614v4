/* crypto/des/ecb_enc.c */
/* Copyright (C) 1995-1997 Eric Young (eay@cryptsoft.com)
 * All rights reserved.
 *
 * This package is an SSL implementation written
 * by Eric Young (eay@cryptsoft.com).
 * The implementation was written so as to conform with Netscapes SSL.
 * 
 * This library is free for commercial and non-commercial use as long as
 * the following conditions are aheared to.  The following conditions
 * apply to all code found in this distribution, be it the RC4, RSA,
 * lhash, DES, etc., code; not just the SSL code.  The SSL documentation
 * included with this distribution is covered by the same copyright terms
 * except that the holder is Tim Hudson (tjh@cryptsoft.com).
 * 
 * Copyright remains Eric Young's, and as such any Copyright notices in
 * the code are not to be removed.
 * If this package is used in a product, Eric Young should be given attribution
 * as the author of the parts of the library used.
 * This can be in the form of a textual message at program startup or
 * in documentation (online or textual) provided with the package.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    "This product includes cryptographic software written by
 *     Eric Young (eay@cryptsoft.com)"
 *    The word 'cryptographic' can be left out if the rouines from the library
 *    being used are not cryptographic related :-).
 * 4. If you include any Windows specific code (or a derivative thereof) from 
 *    the apps directory (application code) you must include an acknowledgement:
 *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"
 * 
 * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * 
 * The licence and distribution terms for any publically available version or
 * derivative of this code cannot be changed.  i.e. this code cannot simply be
 * copied and put under another distribution licence
 * [including the GNU Public Licence.]
 */

#include "des_locl.h"
#include "spr.h"

#define int8 char
#define uint8 unsigned char
#define int16 short int
#define uint16 unsigned short int
#define int32 int
#define uint32 unsigned int

char *libdes_version="libdes v 3.24 - 20-Apr-1996 - eay";
char *DES_version="DES part of SSLeay 0.8.2b 08-Jan-1998";

/* RCSID $Id: ecb_enc.c,v 1.2 2005/09/08 14:07:00 yjlou Exp $ */
/* This function ifdef'ed out for FreeS/WAN project. */
#ifdef notdef
char *des_options()
	{
	static int init=1;
	static char buf[32];

	if (init)
		{
		char *ptr,*unroll,*risc,*size;

		init=0;
#ifdef DES_PTR
		ptr="ptr";
#else
		ptr="idx";
#endif
#if defined(DES_RISC1) || defined(DES_RISC2)
#ifdef DES_RISC1
		risc="risc1";
#endif
#ifdef DES_RISC2
		risc="risc2";
#endif
#else
		risc="cisc";
#endif
#ifdef DES_UNROLL
		unroll="16";
#else
		unroll="4";
#endif
		if (sizeof(DES_LONG) != sizeof(long))
			size="int";
		else
			size="long";
		sprintf(buf,"des(%s,%s,%s,%s)",ptr,risc,unroll,size);
		}
	return(buf);
	}
#endif
		

void des_ecb_encrypt(input, output, ks, enc)
des_cblock (*input);
des_cblock (*output);
des_key_schedule ks;
int enc;
	{
	register DES_LONG l;
	register unsigned char *in,*out;
	DES_LONG ll[2];

	in=(unsigned char *)input;
	out=(unsigned char *)output;
	c2l(in,l); ll[0]=l;
	c2l(in,l); ll[1]=l;
	des_encrypt(ll,ks,enc);
	l=ll[0]; l2c(l,out);
	l=ll[1]; l2c(l,out);
	l=ll[0]=ll[1]=0;
	}

void DES_encrypt3(DES_LONG *data, des_key_schedule ks1,
		  des_key_schedule ks2, des_key_schedule ks3)
	{
	register DES_LONG l,r;

	l=data[0];
	r=data[1];
	IP(l,r);
	data[0]=l;
	data[1]=r;
	des_encrypt2((DES_LONG *)data,ks1,DES_ENCRYPT);
	des_encrypt2((DES_LONG *)data,ks2,DES_DECRYPT);
	des_encrypt2((DES_LONG *)data,ks3,DES_ENCRYPT);
	l=data[0];
	r=data[1];
	FP(r,l);
	data[0]=l;
	data[1]=r;
}

void DES_decrypt3(DES_LONG *data, des_key_schedule ks1,
		  des_key_schedule ks2, des_key_schedule ks3)
	{
	register DES_LONG l,r;

	l=data[0];
	r=data[1];
	IP(l,r);
	data[0]=l;
	data[1]=r;
	des_encrypt2((DES_LONG *)data,ks3,DES_DECRYPT);
	des_encrypt2((DES_LONG *)data,ks2,DES_ENCRYPT);
	des_encrypt2((DES_LONG *)data,ks1,DES_DECRYPT);
	l=data[0];
	r=data[1];
	FP(r,l);
	data[0]=l;
	data[1]=r;
}

void des_ecb3_encrypt( des_cblock *input, des_cblock *output,
		      des_key_schedule ks1, des_key_schedule ks2,
		      des_key_schedule ks3,
	     int enc)
	{
	register DES_LONG l0,l1;
	DES_LONG ll[2];
	const unsigned char *in = &(*input)[0];
	unsigned char *out = &(*output)[0];

	c2l(in,l0);
	c2l(in,l1);
	ll[0]=l0;
	ll[1]=l1;
	if (enc)
		DES_encrypt3(ll,ks1,ks2,ks3);
	else
		DES_decrypt3(ll,ks1,ks2,ks3);
	l0=ll[0];
	l1=ll[1];
	l2c(l0,out);
	l2c(l1,out);
}

/* RSA's DESX */

static unsigned char desx_white_in2out[256]={
0xBD,0x56,0xEA,0xF2,0xA2,0xF1,0xAC,0x2A,0xB0,0x93,0xD1,0x9C,0x1B,0x33,0xFD,0xD0,
0x30,0x04,0xB6,0xDC,0x7D,0xDF,0x32,0x4B,0xF7,0xCB,0x45,0x9B,0x31,0xBB,0x21,0x5A,
0x41,0x9F,0xE1,0xD9,0x4A,0x4D,0x9E,0xDA,0xA0,0x68,0x2C,0xC3,0x27,0x5F,0x80,0x36,
0x3E,0xEE,0xFB,0x95,0x1A,0xFE,0xCE,0xA8,0x34,0xA9,0x13,0xF0,0xA6,0x3F,0xD8,0x0C,
0x78,0x24,0xAF,0x23,0x52,0xC1,0x67,0x17,0xF5,0x66,0x90,0xE7,0xE8,0x07,0xB8,0x60,
0x48,0xE6,0x1E,0x53,0xF3,0x92,0xA4,0x72,0x8C,0x08,0x15,0x6E,0x86,0x00,0x84,0xFA,
0xF4,0x7F,0x8A,0x42,0x19,0xF6,0xDB,0xCD,0x14,0x8D,0x50,0x12,0xBA,0x3C,0x06,0x4E,
0xEC,0xB3,0x35,0x11,0xA1,0x88,0x8E,0x2B,0x94,0x99,0xB7,0x71,0x74,0xD3,0xE4,0xBF,
0x3A,0xDE,0x96,0x0E,0xBC,0x0A,0xED,0x77,0xFC,0x37,0x6B,0x03,0x79,0x89,0x62,0xC6,
0xD7,0xC0,0xD2,0x7C,0x6A,0x8B,0x22,0xA3,0x5B,0x05,0x5D,0x02,0x75,0xD5,0x61,0xE3,
0x18,0x8F,0x55,0x51,0xAD,0x1F,0x0B,0x5E,0x85,0xE5,0xC2,0x57,0x63,0xCA,0x3D,0x6C,
0xB4,0xC5,0xCC,0x70,0xB2,0x91,0x59,0x0D,0x47,0x20,0xC8,0x4F,0x58,0xE0,0x01,0xE2,
0x16,0x38,0xC4,0x6F,0x3B,0x0F,0x65,0x46,0xBE,0x7E,0x2D,0x7B,0x82,0xF9,0x40,0xB5,
0x1D,0x73,0xF8,0xEB,0x26,0xC7,0x87,0x97,0x25,0x54,0xB1,0x28,0xAA,0x98,0x9D,0xA5,
0x64,0x6D,0x7A,0xD4,0x10,0x81,0x44,0xEF,0x49,0xD6,0xAE,0x2E,0xDD,0x76,0x5C,0x2F,
0xA7,0x1C,0xC9,0x09,0x69,0x9A,0x83,0xCF,0x29,0x39,0xB9,0xE9,0x4C,0xFF,0x43,0xAB,
	};

void des_xwhite_in2out( des_cblock *des_key, des_cblock *in_white,
	     des_cblock *out_white)
	{
	int out0,out1;
	int i;
	const unsigned char *key = &(*des_key)[0];
	const unsigned char *in = &(*in_white)[0];
	unsigned char *out = &(*out_white)[0];

	out[0]=out[1]=out[2]=out[3]=out[4]=out[5]=out[6]=out[7]=0;
	out0=out1=0;
	for (i=0; i<8; i++)
		{
		out[i]=key[i]^desx_white_in2out[out0^out1];
		out0=out1;
		out1=(int)out[i&0x07];
		}

	out0=out[0];
	out1=out[i];
	for (i=0; i<8; i++)
		{
		out[i]=in[i]^desx_white_in2out[out0^out1];
		out0=out1;
		out1=(int)out[i&0x07];
		}
	}

void des_xcbc_encrypt( des_cblock *_in,des_cblock *_out,
		      long length, des_key_schedule schedule,
		      des_cblock *ivec, des_cblock *inw,
		      des_cblock *outw, int enc)
	{
	register DES_LONG tin0,tin1;
	register DES_LONG tout0,tout1,xor0,xor1;
	register DES_LONG inW0,inW1,outW0,outW1;
	register const unsigned char *in2;
	register long l=length;
	DES_LONG tin[2];
	unsigned char *iv;
	uint8 *in = (uint8*)_in;
	uint8 *out = (uint8*)_out;

	in2 = &(*inw)[0];
	c2l(in2,inW0);
	c2l(in2,inW1);
	in2 = &(*outw)[0];
	c2l(in2,outW0);
	c2l(in2,outW1);

	iv = &(*ivec)[0];

	if (enc)
		{
		c2l(iv,tout0);
		c2l(iv,tout1);
		for (l-=8; l>=0; l-=8)
			{
			c2l(in,tin0);
			c2l(in,tin1);
			tin0^=tout0^inW0; tin[0]=tin0;
			tin1^=tout1^inW1; tin[1]=tin1;
			des_encrypt(tin,schedule,DES_ENCRYPT);
			tout0=tin[0]^outW0; l2c(tout0,out);
			tout1=tin[1]^outW1; l2c(tout1,out);
			}
		if (l != -8)
			{
			c2ln(in,tin0,tin1,l+8);
			tin0^=tout0^inW0; tin[0]=tin0;
			tin1^=tout1^inW1; tin[1]=tin1;
			des_encrypt(tin,schedule,DES_ENCRYPT);
			tout0=tin[0]^outW0; l2c(tout0,out);
			tout1=tin[1]^outW1; l2c(tout1,out);
			}
		iv = &(*ivec)[0];
		l2c(tout0,iv);
		l2c(tout1,iv);
		}
	else
		{
		c2l(iv,xor0);
		c2l(iv,xor1);
		for (l-=8; l>0; l-=8)
			{
			c2l(in,tin0); tin[0]=tin0^outW0;
			c2l(in,tin1); tin[1]=tin1^outW1;
			des_encrypt(tin,schedule,DES_DECRYPT);
			tout0=tin[0]^xor0^inW0;
			tout1=tin[1]^xor1^inW1;
			l2c(tout0,out);
			l2c(tout1,out);
			xor0=tin0;
			xor1=tin1;
			}
		if (l != -8)
			{
			c2l(in,tin0); tin[0]=tin0^outW0;
			c2l(in,tin1); tin[1]=tin1^outW1;
			des_encrypt(tin,schedule,DES_DECRYPT);
			tout0=tin[0]^xor0^inW0;
			tout1=tin[1]^xor1^inW1;
			l2cn(tout0,tout1,out,l+8);
			xor0=tin0;
			xor1=tin1;
			}

		iv = &(*ivec)[0];
		l2c(xor0,iv);
		l2c(xor1,iv);
		}
	tin0=tin1=tout0=tout1=xor0=xor1=0;
	inW0=inW1=outW0=outW1=0;
	tin[0]=tin[1]=0;
	}


void des_ede3_cbcm_encrypt(const unsigned char *in, unsigned char *out,
	     long length, des_key_schedule ks1, des_key_schedule ks2,
	     des_key_schedule ks3, des_cblock *ivec1, des_cblock *ivec2,
	     int enc)
    {
    register DES_LONG tin0,tin1;
    register DES_LONG tout0,tout1,xor0,xor1,m0,m1;
    register long l=length;
    DES_LONG tin[2];
    unsigned char *iv1,*iv2;

    iv1 = &(*ivec1)[0];
    iv2 = &(*ivec2)[0];

    if (enc)
	{
	c2l(iv1,m0);
	c2l(iv1,m1);
	c2l(iv2,tout0);
	c2l(iv2,tout1);
	for (l-=8; l>=-7; l-=8)
	    {
	    tin[0]=m0;
	    tin[1]=m1;
	    des_encrypt(tin,ks3,1);
	    m0=tin[0];
	    m1=tin[1];

	    if(l < 0)
		{
		c2ln(in,tin0,tin1,l+8);
		}
	    else
		{
		c2l(in,tin0);
		c2l(in,tin1);
		}
	    tin0^=tout0;
	    tin1^=tout1;

	    tin[0]=tin0;
	    tin[1]=tin1;
	    des_encrypt(tin,ks1,1);
	    tin[0]^=m0;
	    tin[1]^=m1;
	    des_encrypt(tin,ks2,0);
	    tin[0]^=m0;
	    tin[1]^=m1;
	    des_encrypt(tin,ks1,1);
	    tout0=tin[0];
	    tout1=tin[1];

	    l2c(tout0,out);
	    l2c(tout1,out);
	    }
	iv1=&(*ivec1)[0];
	l2c(m0,iv1);
	l2c(m1,iv1);

	iv2=&(*ivec2)[0];
	l2c(tout0,iv2);
	l2c(tout1,iv2);
	}
    else
	{
	register DES_LONG t0,t1;

	c2l(iv1,m0);
	c2l(iv1,m1);
	c2l(iv2,xor0);
	c2l(iv2,xor1);
	for (l-=8; l>=-7; l-=8)
	    {
	    tin[0]=m0;
	    tin[1]=m1;
	    des_encrypt(tin,ks3,1);
	    m0=tin[0];
	    m1=tin[1];

	    c2l(in,tin0);
	    c2l(in,tin1);

	    t0=tin0;
	    t1=tin1;

	    tin[0]=tin0;
	    tin[1]=tin1;
	    des_encrypt(tin,ks1,0);
	    tin[0]^=m0;
	    tin[1]^=m1;
	    des_encrypt(tin,ks2,1);
	    tin[0]^=m0;
	    tin[1]^=m1;
	    des_encrypt(tin,ks1,0);
	    tout0=tin[0];
	    tout1=tin[1];

	    tout0^=xor0;
	    tout1^=xor1;
	    if(l < 0)
		{
		l2cn(tout0,tout1,out,l+8);
		}
	    else
		{
		l2c(tout0,out);
		l2c(tout1,out);
		}
	    xor0=t0;
	    xor1=t1;
	    }

	iv1=&(*ivec1)[0];
	l2c(m0,iv1);
	l2c(m1,iv1);

	iv2=&(*ivec2)[0];
	l2c(xor0,iv2);
	l2c(xor1,iv2);
	}
    tin0=tin1=tout0=tout1=xor0=xor1=0;
    tin[0]=tin[1]=0;
    }
