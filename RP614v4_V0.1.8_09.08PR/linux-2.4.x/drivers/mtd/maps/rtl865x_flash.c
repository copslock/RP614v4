#include <linux/module.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <asm/io.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/map.h>
#include <linux/mtd/partitions.h>
#include <linux/config.h>
#include <linux/autoconf.h>

#define WINDOW_ADDR 0xbe000000
#ifdef  CONFIG_RTL865X_FLASH_2MB
#define WINDOW_SIZE 0x200000
#endif
#ifdef  CONFIG_RTL865X_FLASH_4MB
#define WINDOW_SIZE 0x400000
#endif
#ifdef  CONFIG_RTL865X_FLASH_8MB
#define WINDOW_SIZE 0x800000
#endif
#ifdef  CONFIG_RTL865X_FLASH_16MB
#define WINDOW_SIZE 0x1000000
#endif

#ifndef WINDOW_SIZE
#error "FLASH size  Not Support"
#endif

#define BUSWIDTH 2

static struct mtd_info *rtl865x_mtd;

__u8 rtl865x_map_read8(struct map_info *map, unsigned long ofs)
{
	__u8 tmp;
	
	flashdrv_read( &tmp, map->map_priv_1 + ofs, sizeof(tmp) );
	return tmp;
}

__u16 rtl865x_map_read16(struct map_info *map, unsigned long ofs)
{
	__u16 tmp;
	
	flashdrv_read( &tmp, map->map_priv_1 + ofs, sizeof(tmp) );
	return tmp;
}

__u32 rtl865x_map_read32(struct map_info *map, unsigned long ofs)
{
	__u32 tmp;
	
	flashdrv_read( &tmp, map->map_priv_1 + ofs, sizeof(tmp) );
	return tmp;
}

void rtl865x_map_copy_from(struct map_info *map, void *to, unsigned long from, ssize_t len)
{
	flashdrv_read( to, map->map_priv_1 + from, len );
}

void rtl865x_map_write8(struct map_info *map, __u8 d, unsigned long adr)
{
	__raw_writeb(d, map->map_priv_1 + adr);
	mb();
}

void rtl865x_map_write16(struct map_info *map, __u16 d, unsigned long adr)
{
	__raw_writew(d, map->map_priv_1 + adr);
	mb();
}

void rtl865x_map_write32(struct map_info *map, __u32 d, unsigned long adr)
{
	__raw_writel(d, map->map_priv_1 + adr);
	mb();
}

void rtl865x_map_copy_to(struct map_info *map, unsigned long to, const void *from, ssize_t len)
{
	memcpy_toio(map->map_priv_1 + to, from, len);
}

struct map_info rtl865x_map = {
	name: "Physically mapped flash",
	size: WINDOW_SIZE,
	buswidth: BUSWIDTH,
	read8: rtl865x_map_read8,
	read16: rtl865x_map_read16,
	read32: rtl865x_map_read32,
	copy_from: rtl865x_map_copy_from,
	write8: rtl865x_map_write8,
	write16: rtl865x_map_write16,
	write32: rtl865x_map_write32,
	copy_to: rtl865x_map_copy_to
};
static struct mtd_partition rtl865x_parts[] = {
	{ name: "boot1", offset: CONFIG_RTL865X_CUSTOM_LOADER_SEG1_ADDRESS, size: CONFIG_RTL865X_CUSTOM_LOADER_SEG1_SIZE, mask_flags: MTD_WRITEABLE },
	{ name: "boot2", offset: CONFIG_RTL865X_CUSTOM_LOADER_SEG2_ADDRESS, size: CONFIG_RTL865X_CUSTOM_LOADER_SEG2_SIZE, mask_flags: MTD_WRITEABLE },
	{ name: "boot3", offset: CONFIG_RTL865X_CUSTOM_LOADER_SEG3_ADDRESS, size: CONFIG_RTL865X_CUSTOM_LOADER_SEG3_SIZE, mask_flags: MTD_WRITEABLE },
	{ name: "kernel", offset: CONFIG_RTL865X_CUSTOM_RUNTIME_ADDRESS, size: CONFIG_FLASH_SIZE_OF_KERNEL, mask_flags:MTD_WRITEABLE },
	{ name: "rootfs", offset: CONFIG_RTL865X_CUSTOM_RUNTIME_ADDRESS+CONFIG_FLASH_SIZE_OF_KERNEL, size: WINDOW_SIZE-CONFIG_FLASH_SIZE_OF_KERNEL, mask_flags:MTD_WRITEABLE },
#ifdef CONFIG_MTD
       { name: "bdinfo", offset: CONFIG_RTL865X_CUSTOM_LOADER_SEG1_ADDRESS+CONFIG_RTL865X_CUSTOM_LOADER_SEG1_SIZE, size: CONFIG_RTL865X_CUSTOM_LOADER_SEG2_ADDRESS - CONFIG_RTL865X_CUSTOM_LOADER_SEG1_ADDRESS - CONFIG_RTL865X_CUSTOM_LOADER_SEG1_SIZE, mask_flags: MTD_WRITEABLE },
#endif //end of #ifdef CONFIG_MTD
};

#if LINUX_VERSION_CODE < 0x20212 && defined(MODULE)
#define init_rtl865x_map init_module
#define cleanup_rtl865x_map cleanup_module
#endif

mod_init_t init_rtl865x_map(void)
{
       	printk(KERN_NOTICE "flash device: %x at %x\n", WINDOW_SIZE, WINDOW_ADDR);
	rtl865x_map.map_priv_1 =WINDOW_ADDR;

	if (!rtl865x_map.map_priv_1) {
		printk("Failed to ioremap\n");
		return -EIO;
	}

	/* read bdinfo for large flash */
	flashdrv_init();

#if 0 /* for DEBUG */
	unsigned int buf[2]; /* buf[] should be the same as bdinfo.BackupInst[]. */
	flashdrv_read( buf, 0xbe400000, sizeof(buf) );
	printk( "\n*** read 0xbe400000:\n0x%08x\n0x%08x\n\n", buf[0], buf[1] );
#endif

	rtl865x_mtd = do_map_probe("cfi_probe", &rtl865x_map);
	if (rtl865x_mtd) {
		rtl865x_mtd->module = THIS_MODULE;
		add_mtd_partitions(rtl865x_mtd, rtl865x_parts, sizeof(rtl865x_parts)/sizeof(rtl865x_parts[0]));
		return 0;
	}

	iounmap((void *)rtl865x_map.map_priv_1);
	return -ENXIO;
}

mod_exit_t cleanup_rtl865x_map(void)
{
	if (rtl865x_mtd) {
		del_mtd_partitions(rtl865x_mtd);
		map_destroy(rtl865x_mtd);
	}
	if (rtl865x_map.map_priv_1) {
		iounmap((void *)rtl865x_map.map_priv_1);
		rtl865x_map.map_priv_1 = 0;
	}
}

MODULE_LICENSE("GPL");
module_init(init_rtl865x_map);
module_exit(cleanup_rtl865x_map);
