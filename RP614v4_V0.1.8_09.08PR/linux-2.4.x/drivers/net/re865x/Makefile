#
# Makefile for the 865x High Performance
#
# Note! Dependencies are done automagically by 'make dep', which also
# removes any old dependencies. DON'T put your own dependencies here
# unless it's something special (ie not a .c file).
#
# Note 2! The CFLAGS definitions are now in the main makefile...

O_TARGET := re865x.o

obj-y := rtl_glue.o mmap.o flashdrv.o
export-objs += rtl_glue.o


#obj-$(CONFIG_RTL865X_BENCHMARK) += benchmark/dhry.o
#subdir-$(CONFIG_RTL865X_BENCHMARK) += benchmark

ifeq ($(CONFIG_RE865X),y)
	ifeq ($(CONFIG_RTL865XB),y)
		#
		#	The following configuration is for 865xB ROME driver.
		#
		obj-$(CONFIG_RE865X) += rtl865x/rtl865x.o swNic2.o
		subdir-$(CONFIG_RE865X) := rtl865x 
		ifeq ($(CONFIG_RTL865X_MULTILAYER_BSP),y)
			obj-y += re_core.o rtl865x_proc.o rtl865x_log.o rtl865x_callBack.o
			obj-y += rtl865x_mpt.o 
		else
			obj-y += re865x_nic.o
		endif

	else
	ifeq ($(CONFIG_RTL865XC),y)
		#
		#	The following configuration is used for 865xC model code only.
		#	In fact, we will port more and more driver files from 865xB to 865xC.
		#
		EXTRA_CFLAGS += 
		subdir-y := rtl865x
		obj-y += rtl865x/rtl865x.o swNic2.o

	endif
	endif
endif

obj-$(CONFIG_RTL865X_CLE) += cle/cle.o cle_cmdRoot.o
subdir-$(CONFIG_RTL865X_CLE) += cle 
ifeq ($(CONFIG_RTL865X_CLE),y)
   export-objs += cle_cmdRoot.o
endif

obj-$(CONFIG_RTL865X_ROMEREAL) += romereal.o
obj-$(CONFIG_RTL865X_ROMEPERF) += romeperf.o
obj-$(CONFIG_RTL865XB_EXP_CRYPTOENGINE) += crypto/re865x_crypto.o
#obj-$(CONFIG_RTL865X_PCM) += pcm.o

# support SMI(Serial Management Interface), RTL8369/RTL8366s
obj-$(CONFIG_SMI) += smi.o
ifeq ($(CONFIG_RTL865X_CLE),y)
	ifeq ($(CONFIG_SMI),y)
		obj-$(CONFIG_SMI) += smi_cmd.o
	endif
endif

subdir-$(CONFIG_RTL865XB_EXP_CRYPTOENGINE) += crypto

# model code
ifeq ($(CONFIG_RTL865X_MODEL_KERNEL),y)
	subdir-y += gdma
	subdir-y += model
	subdir-y += model/865xC
	subdir-y += rtl865x/tblDrvTest/PktProc
	obj-y += model/model.o
	obj-y += model/865xC/865xC.o
	obj-y += gdma/gdma.o
	obj-y += rtl865x/tblDrvTest/PktProc/PktProc.o
	EXTRA_CFLAGS += -DRTL865X_MODEL_KERNEL
	EXTRA_CFLAGS += -Icle
endif




EXTRA_CFLAGS += -DRTL865X_OVER_KERNEL -DRTL865X_OVER_LINUX -D__KERNEL__ -Wno-implicit -Werror
ifeq ($(CONFIG_AIRGO103BB),y)
EXTRA_CFLAGS += -DAIRGO_FAST_PATH
#EXTRA_CFLAGS += -DAIRGO_NEW
endif
#EXTRA_CFLAGS += -DRTL865X_DEBUG



#obj-m   := $(O_TARGET)


include $(TOPDIR)/Rules.make
