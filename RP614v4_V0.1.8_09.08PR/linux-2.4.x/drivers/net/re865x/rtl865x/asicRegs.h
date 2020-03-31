/*
* ----------------------------------------------------------------
* Copyright c                  Realtek Semiconductor Corporation, 2002  
* All rights reserved.
* 
* $Header: /home/cvsroot/uClinux-dist/linux-2.4.x/drivers/net/re865x/rtl865x/asicRegs.h,v 1.33 2005/11/03 01:46:04 yjlou Exp $
*
* Abstract: ASIC specific definitions -- common part.
*
* $Author: yjlou $
*
* -----------------------------------------------------------------
*	The following definitions are shared by 865xB/865xC series IC.
* -----------------------------------------------------------------
*/

#include "rtl_types.h"

/*********************************************************************
 **                                                                 **
 **    Common Parts -- Add Common Definitions Here !                **
 **                                                                 **
 *********************************************************************/
#define UNCACHED_ADDRESS(x) ((void *)(0x20000000 | (uint32)x ))
#define CACHED_ADDRESS(x) ((void*)(~0x20000000 & (uint32)x ))
#define PHYSICAL_ADDRESS(x) (((uint32)x) & 0x1fffffff)
#define KSEG0_ADDRESS(x) (((uint32)x) | 0x80000000)
#define KSEG1_ADDRESS(x) (((uint32)x) | 0xA0000000)


/*********************************************************************
 **                                                                 **
 ** IC-Dependent Part --Add in the Specific Definitions in its file **
 **                                                                 **
 *********************************************************************/
#ifdef CONFIG_RTL865XC
#include "rtl865xc_asicregs.h"
#else
#include "rtl865xb_asicregs.h"
#endif
