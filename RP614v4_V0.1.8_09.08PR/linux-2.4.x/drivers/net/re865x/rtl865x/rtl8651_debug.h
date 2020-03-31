/*
* Copyright c                  Realtek Semiconductor Corporation, 2005
* All rights reserved.
* 
* Program : Rome Driver header file rtl8651_debug.h to store all debugging related MACROs / UTILITIEs
* Abstract : 
* Creator : Yi-Lun Chen (chenyl@realtek.com.tw)
* Author :  
*
*/

#ifndef RTL8651_DEBUG_H
#define RTL8651_DEBUG_H

#define RTL_DEBUG_MSG

#ifdef RTL_DEBUG_MSG

#ifdef RTL865X_TEST
#define RTL_MSG_MASK			0xfffffff8
#else
#define RTL_MSG_MASK			0xfffffff8
#endif
#define RTL_MSG_DEBUG			(1<<0)
#define RTL_MSG_INFO			(1<<1)
#define RTL_MSG_NOTICE			(1<<2)
#define RTL_MSG_WARN			(1<<3)
#define RTL_MSG_ERR				(1<<4)
#define RTL_MSG_CRIT			(1<<5)
#define RTL_MSG_ALERT			(1<<6)
#define RTL_MSG_EMERG			(1<<7)

#define RTL_MSG_SESSION_HANGUP		(1<<0)
#define RTL_MSG_POLICYRT				(1<<1)
#define RTL_MSG_MCAST					(1<<2)
#define RTL_MSG_FWD					(1<<3)
#define RTL_MSG_TYPE_MASK				0xffffffff

#endif	/* RTL_DEBUG_MSG */

#if (RTL_MSG_MASK & RTL_MSG_DEBUG)
#define RTL_DEBUG(type, fmt, args...) \
	do {if (type & RTL_MSG_TYPE_MASK) rtlglue_printf("(%x)[%s-%d]-debug-: " fmt "\n", type, __FUNCTION__, __LINE__, ## args);} while (0);
#else
#define RTL_DEBUG(type, fmt, args...)
#endif

#if (RTL_MSG_MASK & RTL_MSG_INFO)
#define RTL_INFO(type, fmt, args...) \
	do {if (type & RTL_MSG_TYPE_MASK) rtlglue_printf("(%x)[%s-%d]-info-: " fmt "\n", type, __FUNCTION__, __LINE__, ## args);} while (0);
#else
#define RTL_INFO(type, fmt, args...)
#endif

#if (RTL_MSG_MASK & RTL_MSG_NOTICE)
#define RTL_NOTICE(type, fmt, args...) \
	do {if (type & RTL_MSG_TYPE_MASK) rtlglue_printf("(%x)[%s-%d]-notice-: " fmt "\n", type, __FUNCTION__, __LINE__, ## args);} while (0);
#else
#define RTL_NOTICE(type, fmt, args...)
#endif

#if (RTL_MSG_MASK & RTL_MSG_WARN)
#define RTL_WARN(type, fmt, args...) \
	do {if (type & RTL_MSG_TYPE_MASK) rtlglue_printf("(%x)[%s-%d]-warning-: " fmt "\n", type, __FUNCTION__, __LINE__, ## args);} while (0);
#else
#define RTL_WARN(type, fmt, args...)
#endif

#if (RTL_MSG_MASK & RTL_MSG_ERR)
#define RTL_ERR(type, fmt, args...) \
	do {if (type & RTL_MSG_TYPE_MASK) rtlglue_printf("[=!!Error !!=] =>\n\t(%x)[%s-%d]: " fmt "\n", type, __FUNCTION__, __LINE__, ## args);} while (0);
#else
#define RTL_ERR(type, fmt, args...)
#endif

#if (RTL_MSG_MASK & RTL_MSG_CRIT)
#define RTL_CRIT(type, fmt, args...) \
	do {if (type & RTL_MSG_TYPE_MASK) rtlglue_printf("[=!!Critical !!=] =>\n\t(%x)[%s-%d]: " fmt "\n", type, __FUNCTION__, __LINE__, ## args);} while (0);
#else
#define RTL_CRIT(type, fmt, args...)
#endif

#if (RTL_MSG_MASK & RTL_MSG_ALERT)
#define RTL_ALERT(type, fmt, args...) \
	do {if (type & RTL_MSG_TYPE_MASK) rtlglue_printf("[=!!Alert !!=] =>\n\t(%x)[%s-%d]: " fmt "\n", type, __FUNCTION__, __LINE__, ## args);} while (0);
#else
#define RTL_ALERT(type, fmt, args...)
#endif

#if (RTL_MSG_MASK & RTL_MSG_EMERG)
#define RTL_EMERG(type, fmt, args...) \
	do {if (type & RTL_MSG_TYPE_MASK) rtlglue_printf("[=!!Emergency !!=] =>\n\t(%x)[%s-%d]: " fmt "\n", type, __FUNCTION__, __LINE__, ## args);} while (0);
#else
#define RTL_EMERG(type, fmt, args...)
#endif

#define RTL_BUG(cause) \
	do {rtlglue_printf(" [= !! BUG !! =] at %s line %d\n\t=> Cause: %s\n\t=>-- system Halt\n", __FUNCTION__, __LINE__, cause); while(1);} while (0);

#endif /* RTL8651_DEBUG_H */


