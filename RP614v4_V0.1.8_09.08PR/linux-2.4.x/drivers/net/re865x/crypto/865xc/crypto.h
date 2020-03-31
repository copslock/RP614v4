/*
* --------------------------------------------------------------------
* Copyright c                  Realtek Semiconductor Corporation, 2003
* All rights reserved.
*
* Program : Header file for all crypto sources
* Abstract : This file includes all common definitions of crypto engine.
* $Id: crypto.h,v 1.1 2005/11/01 03:22:38 yjlou Exp $
* $Log: crypto.h,v $
* Revision 1.1  2005/11/01 03:22:38  yjlou
* *** empty log message ***
*
* Revision 1.3  2005/09/08 14:07:00  yjlou
* *: fixed the porting bugS of software DES in re865x/crypto: We always use Linux kernel's DES library.
*
* Revision 1.2  2004/12/22 08:48:08  yjlou
* +: add 16 NOPs when polling AuthEngine
*
* Revision 1.1  2004/06/23 09:18:57  yjlou
* +: support 865xB CRYPTO Engine
*   +: CONFIG_RTL865XB_EXP_CRYPTOENGINE
*   +: basic encry/decry functions (DES/3DES/SHA1/MAC)
*   +: old-fashion API (should be removed in next version)
*   +: batch functions (should be removed in next version)
*
*
*
* --------------------------------------------------------------------
*/

#ifndef __CRYPTO_H__
#define __CRYPTO_H__

#include <rtl_glue.h>

#endif// __CRYPTO_H__
