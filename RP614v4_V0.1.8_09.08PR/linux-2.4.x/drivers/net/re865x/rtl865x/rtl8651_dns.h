/*
* Copyright c                  Realtek Semiconductor Corporation, 2005
* All rights reserved.
* 
* Program :	rtl8651_dns.h
* Abstract :	External Header file for DNS related process in ROMEDRV
* Creator :	Yi-Lun Chen (chenyl@realtek.com.tw)
* Author :	Yi-Lun Chen (chenyl@realtek.com.tw)
*
*/

#ifndef _RTL8651_DNS_H
#define _RTL8651_DNS_H

/* =============================================================
	External variable for all other MODULEs
    ============================================================= */
#define ENABLE_TCP_DNS				/* TCP DNS check */

/* <------------------------------------ entry property ------------------------------------> */
/* bit 0 : exactly match? */
#define RTL8651_DNSDB_PROPERTY_EXACTLYMATCH		(1<<0)	/* exactly match: 'abc' is NOT belong to 'abc.com' */
#define RTL8651_DNSDB_PROPERTY_KEYWORDMATCH	(0<<0)	/* keyword match : 'abc' is belong to 'abc.com' */

/* =============================================================
	External Funtions for all other MODULEs
    ============================================================= */
void rtl8651_dns_dnsProc_dump(void);
void rtl8651_dns_dataBase_dump(void);

int32 rtl8651_dns_setDnsTtlSuppression(uint8 enable, uint32 suppressedTtl);

int32 rtl8651_dns_registerProcess(	uint8 * process,
										uint32 property,
										int32 (*init)(void *para),
										void (*reinit)(void),
										int32 (*proc)(char *orig_domain, char *domain, ipaddr_t ip, void *data),
										void (*timeUpdate)(uint32 secpassed),
										int32 (*destructor)(void *data));
int32 rtl8651_dns_addProcessEntry(uint8 process, char *domain, void *procData, void **entryPtr);
int32 rtl8651_dns_delProcessEntry(uint8 process, uint8 byDbPtr, void *db_p, char *domain, void *procData);
int32 rtl8651_dns_findProcessEntry(uint8 process, char *domain, void *procData, char **returnedDomain, void **returnedProcData, void **start);
char *rtl8651_dns_getProcessEntryDomainInfo(void *db_p);

/* ================================================================================
		Utility
    ================================================================================ */
#define MEM_ALLOC(p,s,e) \
	do { \
		(p) = rtlglue_malloc((s)); \
		if ((p) == NULL) \
		{ \
			RTL_DNS_ERR("malloc memory (size: %d) FAILED, return %d.\n", (s), (e)); \
			return (e); \
		} \
		memset((p), 0, (s)); \
	} while (0);

#define DNS_LIST_INIT(hdr, type, cnt, next) \
	do { \
		type *__tmp; \
		int __idx; \
		__tmp = (type *)(hdr); \
		for (__idx = 0 ; __idx < ((cnt) - 1) ; __idx ++, __tmp ++) \
		{ \
			(__tmp)->next = __tmp + 1; \
		} \
		(__tmp)->next = NULL; \
	} while (0);



#endif /* _RTL8651_DNS_H */
