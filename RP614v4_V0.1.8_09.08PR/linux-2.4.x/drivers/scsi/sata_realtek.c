/*
   sata_realtek.c - Realtek Serial ATA controllers
   Copyright 2005-2005 Tony Su
   
 */
#define REG32(reg)	(*(volatile unsigned int *)(reg))
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/pci.h>
#include <linux/init.h>
#include <linux/blkdev.h>
#include <linux/delay.h>
#include "scsi.h"
#include "hosts.h"
#include <linux/libata.h>
#include <asm/io.h>

#define DRV_NAME	"sata_realtek"
#define DRV_VERSION	"0.10"
//#define MM_IO
//#define X86_PLATEFORM

enum {
	realtek_sata		= 0,

	SATA_CHAN_ENAB		= 0x40, /* SATA channel enable */
	SATA_INT_GATE		= 0x41, /* SATA interrupt gating */
	SATA_NATIVE_MODE	= 0x42, /* Native mode enable */
	SATA_PATA_SHARING	= 0x49, /* PATA/SATA sharing func ctrl */

	PORT0			= (1 << 1),
	PORT1			= (1 << 0),

	ENAB_ALL		= PORT0 | PORT1,

	INT_GATE_ALL		= PORT0 | PORT1,

	NATIVE_MODE_ALL		= (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4),

	SATA_EXT_PHY		= (1 << 6), /* 0==use PATA, 1==ext phy */
	SATA_2DEV		= (1 << 5), /* SATA is master/slave */
};

static int realtek_init_one (struct pci_dev *pdev, const struct pci_device_id *ent);
static u32 realtek_scr_read (struct ata_port *ap, unsigned int sc_reg);
static void realtek_scr_write (struct ata_port *ap, unsigned int sc_reg, u32 val);

static struct pci_device_id realtek_pci_tbl[] = {
	{ 0x10ec, 0x0015, PCI_ANY_ID, PCI_ANY_ID, 0, 0, realtek_sata },

	{ }	/* terminate list */
};

static struct pci_driver realtek_pci_driver = {
	.name			= DRV_NAME,
	.id_table		= realtek_pci_tbl,
	.probe			= realtek_init_one,
	.remove			= ata_pci_remove_one,
};

static Scsi_Host_Template realtek_sht = {
	.module			= THIS_MODULE,
	.name			= DRV_NAME,
	.detect			= ata_scsi_detect,
	.release		= ata_scsi_release,
	.queuecommand		= ata_scsi_queuecmd,
	.eh_strategy_handler	= ata_scsi_error,
	.can_queue		= ATA_DEF_QUEUE,
	.this_id		= ATA_SHT_THIS_ID,
	.sg_tablesize		= LIBATA_MAX_PRD,
	.max_sectors		= ATA_MAX_SECTORS,
	.cmd_per_lun		= ATA_SHT_CMD_PER_LUN,
	.use_new_eh_code	= ATA_SHT_NEW_EH_CODE,
	.emulated		= ATA_SHT_EMULATED,
	.use_clustering		= ATA_SHT_USE_CLUSTERING,
	.proc_name		= DRV_NAME,
	.bios_param		= ata_std_bios_param,
};

static struct ata_port_operations realtek_sata_ops = {
	.port_disable		= ata_port_disable,

#ifdef MM_IO
	.tf_load		= ata_tf_load_mmio,
	.tf_read		= ata_tf_read_mmio,
	.check_status		= ata_check_status_mmio,
	.exec_command		= ata_exec_command_mmio,
#else
	.tf_load		= ata_tf_load_pio,
	.tf_read		= ata_tf_read_pio,
	.check_status		= ata_check_status_pio,
	.exec_command		= ata_exec_command_pio,
#endif


	.phy_reset		= sata_phy_reset,

#ifdef MM_IO
	.bmdma_start            = ata_bmdma_start_mmio,
#else
	.bmdma_start            = ata_bmdma_start_pio,
#endif

	.fill_sg		= ata_fill_sg,
	.eng_timeout		= ata_eng_timeout,

	.irq_handler		= ata_interrupt,

	.scr_read		= realtek_scr_read,
	.scr_write		= realtek_scr_write,

	.port_start		= ata_port_start,
	.port_stop		= ata_port_stop,
};

MODULE_AUTHOR("Tony Su");
MODULE_DESCRIPTION("SCSI low-level driver for Realtek SATA controllers");
MODULE_LICENSE("GPL");
MODULE_DEVICE_TABLE(pci, realtek_pci_tbl);

static u32 realtek_scr_read (struct ata_port *ap, unsigned int sc_reg)
{
	if (sc_reg > SCR_CONTROL)
		return 0xffffffffU;
	if (ap->flags & ATA_FLAG_MMIO)
		return readl(ap->ioaddr.scr_addr + (4 * sc_reg));
	else
		return inl(ap->ioaddr.scr_addr + (4 * sc_reg));
}

static void realtek_scr_write (struct ata_port *ap, unsigned int sc_reg, u32 val)
{
	if (sc_reg > SCR_CONTROL)
		return;

	if (ap->flags & ATA_FLAG_MMIO)
		writel(val, ap->ioaddr.scr_addr + (4 * sc_reg));		
	else
		outl(val, ap->ioaddr.scr_addr + (4 * sc_reg));
}

static const unsigned int realtek_bar_sizes[] = {
	0xff
};


/**
 *	realtek_init_one -
 *	@pdev:
 *	@ent:
 *
 *	LOCKING:
 *
 *	RETURNS:
 *
 */

void ata_realtek_ports(struct ata_ioports *ioaddr)
{
	ioaddr->data_addr = ioaddr->cmd_addr + (ATA_REG_DATA<<2);
	ioaddr->error_addr = ioaddr->cmd_addr +( ATA_REG_ERR<<2);
	ioaddr->feature_addr = ioaddr->cmd_addr + (ATA_REG_FEATURE<<2);
	ioaddr->nsect_addr = ioaddr->cmd_addr + (ATA_REG_NSECT<<2);
	ioaddr->lbal_addr = ioaddr->cmd_addr + (ATA_REG_LBAL<<2);
	ioaddr->lbam_addr = ioaddr->cmd_addr + (ATA_REG_LBAM<<2);
	ioaddr->lbah_addr = ioaddr->cmd_addr + (ATA_REG_LBAH<<2);
	ioaddr->device_addr = ioaddr->cmd_addr + (ATA_REG_DEVICE<<2);
	ioaddr->status_addr = ioaddr->cmd_addr + (ATA_REG_STATUS<<2);
	ioaddr->command_addr = ioaddr->cmd_addr + (ATA_REG_CMD<<2);
}

static int realtek_init_one (struct pci_dev *pdev, const struct pci_device_id *ent)
{
	static int printed_version;
	unsigned int i;
	int rc;

	struct ata_probe_ent *probe_ent;
	u8 tmp8;


	if (!printed_version++)
		printk(KERN_DEBUG DRV_NAME " version " DRV_VERSION "\n");

	rc = pci_enable_device(pdev);
	if (rc)
		return rc;

	rc = pci_request_regions(pdev, DRV_NAME);
	if (rc)
		goto err_out;

	pci_read_config_byte(pdev, SATA_PATA_SHARING, &tmp8);
	if (tmp8 & SATA_2DEV) {
		printk(KERN_ERR DRV_NAME "(%s): SATA master/slave not supported (0x%x)\n",
		       pci_name(pdev), (int) tmp8);
		rc = -EIO;
		goto err_out_regions;
	}

	for (i = 0; i < ARRAY_SIZE(realtek_bar_sizes); i++)
		if ((pci_resource_start(pdev, i) == 0) ||
		    (pci_resource_len(pdev, i) < realtek_bar_sizes[i])) {
			printk(KERN_ERR DRV_NAME "(%s): invalid PCI BAR %u (sz 0x%lx, val 0x%lx)\n",
			       pci_name(pdev), i,
			       pci_resource_start(pdev, i),
			       pci_resource_len(pdev, i));
			rc = -ENODEV;
			goto err_out_regions;
		}

	rc = pci_set_dma_mask(pdev, ATA_DMA_MASK);
	if (rc)
		goto err_out_regions;

	probe_ent = kmalloc(sizeof(*probe_ent), GFP_KERNEL);
	if (!probe_ent) {
		printk(KERN_ERR DRV_NAME "(%s): out of memory\n",
		       pci_name(pdev));
		rc = -ENOMEM;
		goto err_out_regions;
	}
	memset(probe_ent, 0, sizeof(*probe_ent));
	INIT_LIST_HEAD(&probe_ent->node);
	probe_ent->pdev = pdev;
	probe_ent->sht = &realtek_sht;
	probe_ent->host_flags = ATA_FLAG_SATA | ATA_FLAG_SRST |
				ATA_FLAG_NO_LEGACY;
	probe_ent->port_ops = &realtek_sata_ops;
	probe_ent->n_ports = 1;
	probe_ent->irq = pdev->irq;
	probe_ent->irq_flags = SA_SHIRQ;
	probe_ent->pio_mask = 0x1f;
	probe_ent->udma_mask = 0x7f;

#ifdef X86_PLATEFORM

#ifdef MM_IO
	{
		unsigned char *ptr;
		unsigned long mem_resource,mem_len;
		mem_resource = pci_resource_start(pdev, 0);
		mem_len = pci_resource_len(pdev,0);
		ptr = ioremap_nocache (mem_resource, mem_len);
		probe_ent->host_flags |= ATA_FLAG_MMIO;
		probe_ent->port[0].cmd_addr = ptr;
		ata_realtek_ports(&probe_ent->port[0]);
		probe_ent->port[0].altstatus_addr =
		probe_ent->port[0].ctl_addr =ptr+ 0x20;
		probe_ent->port[0].bmdma_addr =  ptr+0xd0;
		probe_ent->port[0].scr_addr =ptr+ 0x24;
	}
#else
	{
		probe_ent->port[0].cmd_addr = pci_resource_start(pdev, 1);
		ata_realtek_ports(&probe_ent->port[0]);
		probe_ent->port[0].altstatus_addr =
		probe_ent->port[0].ctl_addr = (pci_resource_start(pdev, 1) + 0x20);
		probe_ent->port[0].bmdma_addr =  (pci_resource_start(pdev, 1) + 0xd0);
		probe_ent->port[0].scr_addr =(pci_resource_start(pdev, 1) + 0x24);
	}
#endif	

#else //MIPS - RTL865XB

#ifdef MM_IO
	{
		probe_ent->host_flags |= ATA_FLAG_MMIO;
		probe_ent->port[0].cmd_addr = pci_resource_start(pdev, 0)|0xb0000000;
		ata_realtek_ports(&probe_ent->port[0]);
		probe_ent->port[0].altstatus_addr =
		probe_ent->port[0].ctl_addr = (pci_resource_start(pdev, 0) + 0x20)|0xb0000000;
		probe_ent->port[0].bmdma_addr =  (pci_resource_start(pdev, 0) + 0xd0)|0xb0000000;
		probe_ent->port[0].scr_addr =(pci_resource_start(pdev, 0) + 0x24)|0xb0000000;
	}
#else
	{
		probe_ent->port[0].cmd_addr = pci_resource_start(pdev, 1)|0xb0000000;
		ata_realtek_ports(&probe_ent->port[0]);
		probe_ent->port[0].altstatus_addr =
		probe_ent->port[0].ctl_addr = (pci_resource_start(pdev, 1) + 0x20)|0xb0000000;
		probe_ent->port[0].bmdma_addr =  (pci_resource_start(pdev, 1) + 0xd0)|0xb0000000;
		probe_ent->port[0].scr_addr =(pci_resource_start(pdev, 1) + 0x24)|0xb0000000;
	}
#endif	

#endif




	pci_read_config_byte(pdev, PCI_INTERRUPT_LINE, &tmp8);
	printk(KERN_INFO DRV_NAME "(%s): routed to hard irq line %d\n",
	       pci_name(pdev),
	       (int) (tmp8 & 0xf0) == 0xf0 ? 0 : tmp8 & 0x0f);



	/* make sure SATA channels are enabled */
	pci_read_config_byte(pdev, SATA_CHAN_ENAB, &tmp8);
	if ((tmp8 & ENAB_ALL) != ENAB_ALL) {
		printk(KERN_DEBUG DRV_NAME "(%s): enabling SATA channels (0x%x)\n",
		       pci_name(pdev), (int) tmp8);
		tmp8 |= ENAB_ALL;
		pci_write_config_byte(pdev, SATA_CHAN_ENAB, tmp8);
	}


	/* make sure interrupts for each channel sent to us */
	pci_read_config_byte(pdev, SATA_INT_GATE, &tmp8);
	if ((tmp8 & INT_GATE_ALL) != INT_GATE_ALL) {
		printk(KERN_DEBUG DRV_NAME "(%s): enabling SATA channel interrupts (0x%x)\n",
		       pci_name(pdev), (int) tmp8);
		tmp8 |= INT_GATE_ALL;
		pci_write_config_byte(pdev, SATA_INT_GATE, tmp8);
	}

	/* make sure native mode is enabled */
	pci_read_config_byte(pdev, SATA_NATIVE_MODE, &tmp8);
	if ((tmp8 & NATIVE_MODE_ALL) != NATIVE_MODE_ALL) {
		printk(KERN_DEBUG DRV_NAME "(%s): enabling SATA channel native mode (0x%x)\n",
		       pci_name(pdev), (int) tmp8);
		tmp8 |= NATIVE_MODE_ALL;
		pci_write_config_byte(pdev, SATA_NATIVE_MODE, tmp8);
	}

	pci_set_master(pdev);
	ata_add_to_probe_list(probe_ent);


//for test
#if 0
	{
		unsigned int i;
		for(i=0;i<10000;i++)
		{
			unsigned int tmp;			
			REG32(0xbbf000a0)=0xffffffff;
			tmp=REG32(0xbbf000a0);
			if(tmp!=0xffffffff) printk("error %x !=0xffffffff i=%d 0xbd012004=%x\n",tmp,i,REG32(0xbd012004));
			REG32(0xbbf000a0)=0;			
			tmp=REG32(0xbbf000a0);
			if(tmp!=0) printk("error %x !=0 i=%d\n",tmp,i);
			
			REG32(0xbbf000a0)=0x55555555;
			tmp=REG32(0xbbf000a0);
			if(tmp!=0x55555555) printk("error %x !=0x55555555 i=%d\n",tmp,i);
			
			REG32(0xbbf000a0)=0xaaaaaaaa;
			tmp=REG32(0xbbf000a0);
			if(tmp!=0xaaaaaaaa) printk("error %x !=0xaaaaaaaa i=%d\n",tmp,i);
			
			REG32(0xbbf000a0)=0x01234567;			
			tmp=REG32(0xbbf000a0);
			if(tmp!=0x01234567) printk("error %x !=0x01234567 i=%d\n",tmp,i);
			
			REG32(0xbbf000a0)=0x89abcdef;
			tmp=REG32(0xbbf000a0);
			if(tmp!=0x89abcdef) printk("error %x !=0x89abcdef i=%d\n",tmp,i);
		}

	}
#endif

	return 0;

err_out_regions:
	pci_release_regions(pdev);
	
err_out:
	pci_disable_device(pdev);
	return rc;
}

/**
 *	realtek_init -
 *
 *	LOCKING:
 *
 *	RETURNS:
 *
 */

static int __init realtek_init(void)
{
	int rc;
	rc = pci_module_init(&realtek_pci_driver);
	if (rc)
		return rc;
	
	rc = scsi_register_module(MODULE_SCSI_HA, &realtek_sht);
	if (rc) {
		pci_unregister_driver(&realtek_pci_driver);
		/* TODO: does scsi_register_module return errno val? */
		return -ENODEV;
	}

	return 0;
}

/**
 *	realtek_exit -
 *
 *	LOCKING:
 *
 */

static void __exit realtek_exit(void)
{
	scsi_unregister_module(MODULE_SCSI_HA, &realtek_sht);
	pci_unregister_driver(&realtek_pci_driver);
}

module_init(realtek_init);
module_exit(realtek_exit);

