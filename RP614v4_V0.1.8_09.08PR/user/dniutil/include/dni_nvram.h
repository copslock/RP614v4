/*
 * NVRAM variable manipulation
 *
 * Copyright 2004, Broadcom Corporation
 * All Rights Reserved.
 * 
 * THIS SOFTWARE IS OFFERED "AS IS", AND BROADCOM GRANTS NO WARRANTIES OF ANY
 * KIND, EXPRESS OR IMPLIED, BY STATUTE, COMMUNICATION OR OTHERWISE. BROADCOM
 * SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A SPECIFIC PURPOSE OR NONINFRINGEMENT CONCERNING THIS SOFTWARE.
 *
 * $Id: dni_bcmnvram.h,v 1.2 2005/05/26 05:52:50 dvdchen Exp $
 */

#ifndef _bcmnvram_h_
#define _bcmnvram_h_

#ifndef _LANGUAGE_ASSEMBLY
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <semaphore.h>
//#include <typedefs.h>
#include <dni_typedefs.h>

struct nvram_header {
	uint32 magic;
	uint32 len;
	uint32 crc_ver_init;	/* 0:7 crc, 8:15 ver, 16:27 init, mem. test 28, 29-31 reserved */
	uint32 config_refresh;	/* 0:15 config, 16:31 refresh */
	uint32 config_ncdl;	/* ncdl values for memc */
};

struct nvram_tuple {
	char *name;
	char *value;
	struct nvram_tuple *next;
};

#define VTABSIZE 127

struct varinit {
	int name_offset;		/*offset of name string : ex. wan_proto=*/
	int text_offset;		/*offset of value string : ex. pppoe*/
	int next_offset;		/*offset of next varinit struct*/
};

#define INTOFF sem_up(sem_id)		/*set semaphore*/
#define INTON sem_down(sem_id)		/*unset semaphore*/

/*share memory identifier (note. must greater than share memory size)*/
#define NVRAMKEY 655350
/*share memory size*/
#define SHARESIZE 65536
#define MAGIC_ID "NVRAM"
#define DEVICE_PATH "../../../../../../flash/nvram" //move to dummy.h
//#define TMP_FILE_PATH "flash/tmp"
#define ERR_NO_MEM -1


//void *xmalloc(size_t sz);
void dump_mem(void*,int);
int nvram_init();
void attach_share_memory(void);
void nvram_clean(void);
void re_alloc(void);
void detach_shm(void);

//extern int nvram_commit(void);
//extern char *nvram_get(const char *name);
//extern int nvram_set(const char *name, const char *val);
//extern int nvram_unset(const char *s);

/*
 * Initialize NVRAM access. May be unnecessary or undefined on certain
 * platforms.
 */
#if 0
extern int BCMINIT(nvram_init)(void *sbh);
#endif

/*
 * Disable NVRAM access. May be unnecessary or undefined on certain
 * platforms.
 */
extern void BCMINIT(nvram_exit)(void);

/*
 * Get the value of an NVRAM variable. The pointer returned may be
 * invalid after a set.
 * @param	name	name of variable to get
 * @return	value of variable or NULL if undefined
 */
extern char * BCMINIT(nvram_get)(const char *name);

/* 
 * Get the value of an NVRAM variable.
 * @param	name	name of variable to get
 * @return	value of variable or NUL if undefined
 */
#define nvram_safe_get(name) (BCMINIT(nvram_get)(name) ? : "")

/*
 * Match an NVRAM variable.
 * @param	name	name of variable to match
 * @param	match	value to compare against value of variable
 * @return	TRUE if variable is defined and its value is string equal
 *		to match or FALSE otherwise
 */
static INLINE int
nvram_match(char *name, char *match) {
	const char *value = BCMINIT(nvram_get)(name);
	return (value && !strcmp(value, match));
}

/*
 * Inversely match an NVRAM variable.
 * @param	name	name of variable to match
 * @param	match	value to compare against value of variable
 * @return	TRUE if variable is defined and its value is not string
 *		equal to invmatch or FALSE otherwise
 */
static INLINE int
nvram_invmatch(char *name, char *invmatch) {
	const char *value = BCMINIT(nvram_get)(name);
	return (value && strcmp(value, invmatch));
}

/*
 * Set the value of an NVRAM variable. The name and value strings are
 * copied into private storage. Pointers to previously set values
 * may become invalid. The new value may be immediately
 * retrieved but will not be permanently stored until a commit.
 * @param	name	name of variable to set
 * @param	value	value of variable
 * @return	0 on success and errno on failure
 */
extern int BCMINIT(nvram_set)(const char *name, const char *value);

/*
 * Unset an NVRAM variable. Pointers to previously set values
 * remain valid until a set.
 * @param	name	name of variable to unset
 * @return	0 on success and errno on failure
 * NOTE: use nvram_commit to commit this change to flash.
 */
extern int BCMINIT(nvram_unset)(const char *name);

/*
 * Commit NVRAM variables to permanent storage. All pointers to values
 * may be invalid after a commit.
 * NVRAM values are undefined after a commit.
 * @return	0 on success and errno on failure
 */
extern int BCMINIT(nvram_commit)(void);

/*
 * Get all NVRAM variables (format name=value\0 ... \0\0).
 * @param	buf	buffer to store variables
 * @param	count	size of buffer in bytes
 * @return	0 on success and errno on failure
 */
extern int BCMINIT(nvram_getall)(char *buf, int count);

#endif /* _LANGUAGE_ASSEMBLY */

#define NVRAM_MAGIC		0x48534C46	/* 'FLSH' */
#define NVRAM_VERSION		1
#define NVRAM_HEADER_SIZE	20
#define NVRAM_SPACE		0x8000

#endif /* _bcmnvram_h_ */
