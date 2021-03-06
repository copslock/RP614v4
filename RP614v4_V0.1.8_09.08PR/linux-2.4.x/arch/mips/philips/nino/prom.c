/*
 *  arch/mips/philips/nino/prom.c
 *
 *  Copyright (C) 2001 Steven J. Hill (sjhill@realitydiluted.com)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *  
 *  Early initialization code for the Philips Nino
 */
#include <linux/config.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/string.h>
#include <asm/bootinfo.h>
#include <asm/addrspace.h>
#include <asm/page.h>

char arcs_cmdline[CL_SIZE];

#ifdef CONFIG_FB_TX3912
extern unsigned long tx3912fb_paddr;
extern unsigned long tx3912fb_vaddr;
extern unsigned long tx3912fb_size;
#endif

const char *get_system_type(void)
{
	return "Philips Nino";
}

/* Do basic initialization */
void __init prom_init(int argc, char **argv, unsigned long magic, int *prom_vec)
{
	unsigned long mem_size;

	//strcpy(arcs_cmdline, "console=tty0 console=ttyS0,115200");
//	strcat(arcs_cmdline,
  //  "root=/dev/ram console=0 ramdisk_start=0 single");
	mips_machgroup = MACH_GROUP_PHILIPS;
	mips_machtype = MACH_PHILIPS_NINO;

#ifdef CONFIG_NINO_4MB
	mem_size = 4 << 20;
#elif CONFIG_NINO_8MB
	mem_size = 8 << 20;
#elif CONFIG_NINO_16MB
	mem_size = 16 << 20;
#elif CONFIG_NINO_32MB
	mem_size = 32 << 20;
#endif

	//mem_size = 8 << 20;
	mem_size = 16 << 20;
	add_memory_region(0, mem_size, BOOT_MEM_RAM); 
}

void __init prom_free_prom_memory (void)
{
}
