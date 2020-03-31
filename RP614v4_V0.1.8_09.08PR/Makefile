	
############################################################################

#
# Makefile -- Top level uClinux makefile.
#
# Copyright (c) 2001-2004, SnapGear (www.snapgear.com)
# Copyright (c) 2001, Lineo
#
PKG_VERSION=0.6.6-3-DNI
ROMEDRIVER_VERSION=3.6-3
WLANDRVPKG_VERSION=1.10
RTL8185_SRC=n
SDK_PACKAGE=n

VERSIONPKG = 3.4.0
VERSIONSTR = $(CONFIG_VENDOR)/$(CONFIG_PRODUCT) Version $(VERSIONPKG)

############################################################################
#
# Get the core stuff worked out
#

LINUXDIR = $(CONFIG_LINUXDIR)
LOADERDIR = $(ROOTDIR)/loader_srcroot
LIBCDIR  = $(CONFIG_LIBCDIR)
ROOTDIR  = $(shell pwd)
PATH	 := $(PATH):$(ROOTDIR)/tools
HOSTCC   = cc
IMAGEDIR = $(ROOTDIR)/images
RELDIR   = $(ROOTDIR)/release
ROMFSDIR = $(ROOTDIR)/romfs
ROMFSINST= romfs-inst.sh
SCRIPTSDIR = $(ROOTDIR)/config/scripts
TFTPDIR    = /tftpboot


LINUX_CONFIG  = $(ROOTDIR)/$(LINUXDIR)/.config
CONFIG_CONFIG = $(ROOTDIR)/config/.config
MODULES_CONFIG = $(ROOTDIR)/modules/.config
LOADER_BIN = $(LOADERDIR)/ldr.bin


############################################################################
#
# Check if linux-2.4.x/.config exist (for packer)
#
ifeq ($(LINUX_CONFIG),$(wildcard $(LINUX_CONFIG)))
else
all: kernel_config_error
endif


############################################################################
#
# Lets work out what the user wants, and if they have configured us yet
#

ifeq (.config,$(wildcard .config))
include .config 
include $(LINUX_CONFIG)

all: subdirs romfs modules modules_install image 
else
all: config_error
endif

CONFIG_SHELL := $(shell if [ -x "$$BASH" ]; then echo $$BASH; \
	  else if [ -x /bin/bash ]; then echo /bin/bash; \
	  else echo sh; fi ; fi)

ifeq (config.arch,$(wildcard config.arch))
include config.arch
ARCH_CONFIG = $(ROOTDIR)/config.arch
export ARCH_CONFIG
endif

ifneq ($(SUBARCH),)
# Using UML, so make the kernel and non-kernel with different ARCHs
MAKEARCH = $(MAKE) ARCH=$(SUBARCH) CROSS_COMPILE=$(CROSS_COMPILE)
MAKEARCH_KERNEL = $(MAKE)  ARCH=$(ARCH) SUBARCH=$(SUBARCH) CROSS_COMPILE=$(CROSS_KERNEL_COMPILE)
else
MAKEARCH = $(MAKE) V=1 ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE)
MAKEARCH_KERNEL =$(MAKE) V=1 ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_KERNEL_COMPILE)
endif

DIRS    = $(VENDOR_TOPDIRS) lib user
VENDDIR = $(ROOTDIR)/vendors/$(CONFIG_VENDOR)/$(CONFIG_PRODUCT)/.
RE865xNICDRVDIR=$(ROOTDIR)/$(LINUXDIR)/drivers/net/re865x/rtl865x/
CFGMGRDIR=$(ROOTDIR)/user/boa/src/rtl865x
BUSYBOXDIR=$(ROOTDIR)/user/busybox


export VENDOR PRODUCT ROOTDIR LINUXDIR HOSTCC CONFIG_SHELL
export CONFIG_CONFIG LINUX_CONFIG ROMFSDIR SCRIPTSDIR
export VERSIONPKG VERSIONSTR ROMFSINST PATH IMAGEDIR RELDIR RELFILES TFTPDIR

############################################################################

#
# Config stuff,  we recall ourselves to load the new config.arch before
# running the kernel and other config scripts
#

.PHONY: config.tk config.in
config.in:
	config/mkconfig > config.in

config.tk: config.in
	$(MAKE) -C $(SCRIPTSDIR) tkparse
	ARCH=dummy $(SCRIPTSDIR)/tkparse < config.in > config.tmp
	@if [ -f /usr/local/bin/wish ];	then \
		echo '#!'"/usr/local/bin/wish -f" > config.tk; \
	else \
		echo '#!'"/usr/bin/wish -f" > config.tk; \
	fi
	cat $(SCRIPTSDIR)/header.tk >> ./config.tk
	cat config.tmp >> config.tk
	rm -f config.tmp
	echo "set defaults \"/dev/null\"" >> config.tk
	echo "set help_file \"config/Configure.help\"" >> config.tk
	cat $(SCRIPTSDIR)/tail.tk >> config.tk
	chmod 755 config.tk

.PHONY: xconfig
xconfig: config.tk
	@wish -f config.tk
	@if [ ! -f .config ]; then \
		echo; \
		echo "You have not saved your config, please re-run make config"; \
		echo; \
		exit 1; \
	 fi
	@config/setconfig defaults
	@if egrep "^CONFIG_DEFAULTS_KERNEL=y" .config > /dev/null; then \
		$(MAKE) linux_xconfig; \
	 fi
	@if egrep "^CONFIG_DEFAULTS_MODULES=y" .config > /dev/null; then \
		$(MAKE) modules_xconfig; \
	 fi
	@if egrep "^CONFIG_DEFAULTS_VENDOR=y" .config > /dev/null; then \
		$(MAKE) config_xconfig; \
	 fi
	@config/setconfig final

.PHONY: config
config: config.in
	@HELP_FILE=config/Configure.help \
		$(CONFIG_SHELL) $(SCRIPTSDIR)/Configure config.in
	@config/setconfig defaults
	@if egrep "^CONFIG_DEFAULTS_KERNEL=y" .config > /dev/null; then \
		$(MAKE) linux_config; \
	 fi
	@if egrep "^CONFIG_DEFAULTS_MODULES=y" .config > /dev/null; then \
		$(MAKE) modules_config; \
	 fi
	@if egrep "^CONFIG_DEFAULTS_VENDOR=y" .config > /dev/null; then \
		$(MAKE) config_config; \
	 fi
	@config/setconfig final

.PHONY: menuconfig
menuconfig: config.in $(LINUX_CONFIG)
	$(MAKE) -C $(SCRIPTSDIR)/lxdialog all
	@HELP_FILE=config/Configure.help \
		$(CONFIG_SHELL) $(SCRIPTSDIR)/Menuconfig config.in
	@if [ ! -f .config ]; then \
		echo; \
		echo "You have not saved your config, please re-run make config"; \
		echo; \
		exit 1; \
	 fi
	@config/setconfig defaults
	@if egrep "^CONFIG_DEFAULTS_KERNEL=y" .config > /dev/null; then \
		$(MAKE) linux_menuconfig; \
	 fi
	@if egrep "^CONFIG_DEFAULTS_MODULES=y" .config > /dev/null; then \
		$(MAKE) modules_menuconfig; \
	 fi
	@if egrep "^CONFIG_DEFAULTS_VENDOR=y" .config > /dev/null; then \
		$(MAKE) config_menuconfig; \
	 fi
	@config/setconfig final
	@ln -fs ../../libc/sysdeps/linux/mips/bits/endian.h uClibc/include/bits/endian.h
	@rm -Rf include/*.h
	@for i in $(shell ls user/dniutil/include/*.h) ; do ln -fs ../$$i include/. ; done
	cp -f user/busybox/defconfig-rtl865x user/busybox/.config 	
	


$(LINUX_CONFIG):
	cp $(LINUXDIR)/arch/mips/defconfig-rtl865x $@ 


.PHONY: oldconfig
oldconfig:
	@$(MAKE) oldconfig_linux
	@$(MAKE) oldconfig_modules
	@$(MAKE) oldconfig_config
	@$(MAKE) oldconfig_uClibc
	@config/setconfig final

.PHONY: modules
modules:
	. $(LINUXDIR)/.config; if [ "$$CONFIG_MODULES" = "y" ]; then \
		[ -d $(LINUXDIR)/modules ] || mkdir $(LINUXDIR)/modules; \
		$(MAKEARCH_KERNEL) -C $(LINUXDIR) modules; \
	fi
.PHONY: rtl865x

.PHONY: modules_install
modules_install:
	. $(LINUXDIR)/.config; if [ "$$CONFIG_MODULES" = "y" ]; then \
		[ -d $(ROMFSDIR)/lib/modules ] || mkdir -p $(ROMFSDIR)/lib/modules; \
		$(MAKEARCH_KERNEL) -C $(LINUXDIR) INSTALL_MOD_PATH=$(ROMFSDIR) DEPMOD=true modules_install; \
		rm -f $(ROMFSDIR)/lib/modules/*/build; \
		find $(ROMFSDIR)/lib/modules -type f | xargs -r $(STRIP) -g; \
	fi

linux_xconfig:
	$(MAKEARCH_KERNEL) -C $(LINUXDIR) xconfig
linux_menuconfig:
	$(MAKEARCH_KERNEL) -C $(LINUXDIR) menuconfig
linux_config:
	$(MAKEARCH_KERNEL) -C $(LINUXDIR) config
modules_xconfig:
	[ ! -d modules ] || $(MAKEARCH) -C modules xconfig
modules_menuconfig:
	[ ! -d modules ] || $(MAKEARCH) -C modules menuconfig
modules_config:
	[ ! -d modules ] || $(MAKEARCH) -C modules config
modules_clean:
	-[ ! -d modules ] || $(MAKEARCH) -C modules clean
config_xconfig:
	$(MAKEARCH) -C config xconfig
config_menuconfig:
	$(MAKEARCH) -C config menuconfig
config_config:
	$(MAKEARCH) -C config config
oldconfig_config:
	$(MAKEARCH) -C config oldconfig
oldconfig_modules:
	[ ! -d modules ] || $(MAKEARCH) -C modules oldconfig
oldconfig_linux:
	$(MAKEARCH_KERNEL) -C $(LINUXDIR) oldconfig
oldconfig_uClibc:
	[ -z "$(findstring uClibc,$(LIBCDIR))" ] || $(MAKEARCH) -C $(LIBCDIR) oldconfig

############################################################################
#
# normal make targets
#

.PHONY: romfs
romfs:
	-rm -rf romfs
	for dir in $(DIRS) ; do [ ! -d $$dir ] || $(MAKEARCH) -C $$dir romfs || exit 1 ; done
	-find $(ROMFSDIR)/. -name CVS | xargs -r rm -rf

.PHONY: image
image:
	[ -d $(IMAGEDIR) ] || mkdir $(IMAGEDIR)
	@if egrep "^CONFIG_BLK_DEV_BLKMEM=y" $(LINUXDIR)/.config > /dev/null; then \
	$(MAKEARCH) -C $(VENDDIR) image_romfs;\
	fi
	@if egrep "^CONFIG_MTD=y" $(LINUXDIR)/.config > /dev/null; then \
	$(MAKEARCH) -C $(VENDDIR) kernel_image;\
	$(MAKEARCH) -C $(VENDDIR) rootfs_image;\
	fi

.PHONY: netflash
netflash netflash_only:
	make -C prop/mstools CONFIG_PROP_MSTOOLS_NETFLASH_NETFLASH=y

.PHONY: release
release:
	make -C release release

%_fullrelease:
	make -C release $@
#
# fancy target that allows a vendor to have other top level
# make targets,  for example "make vendor_flash" will run the
# vendor_flash target in the vendors directory
#

vendor_%:
	$(MAKEARCH) -C $(VENDDIR) $@

.PHONY: linux
linux linux%_only:
	@if [ $(LINUXDIR) != linux-2.5.x -a $(LINUXDIR) != linux-2.6.x -a ! -f $(LINUXDIR)/.depend ] ; then \
		echo "ERROR: you need to do a 'make dep' first" ; \
		exit 1 ; \
	fi
	$(MAKEARCH_KERNEL) -C $(LINUXDIR) $(LINUXTARGET) || exit 1
	if [ -f $(LINUXDIR)/vmlinux ]; then \
		ln -f $(LINUXDIR)/vmlinux $(LINUXDIR)/linux ; \
	fi

.PHONY: subdirs
subdirs: linux
	for dir in $(DIRS) ; do [ ! -d $$dir ] || $(MAKEARCH) -C $$dir || exit 1 ; done

dep:

	echo '#define PKG_VERSION "$(PKG_VERSION)"' > linux-2.4.x/drivers/net/re865x/version.h
	echo '#define ROMEDRIVER_VERSION "$(ROMEDRIVER_VERSION)"' >> linux-2.4.x/drivers/net/re865x/version.h
	echo '#define WLANDRVPKG_VERSION "$(WLANDRVPKG_VERSION)"' >> linux-2.4.x/drivers/net/re865x/version.h

	ln  -fs $(ROOTDIR)/linux-2.4.x/drivers/net/re865x/version.h include/;\

	if [ ! -f include/re865x.h ] ; then \
		ln  -s $(ROOTDIR)/linux-2.4.x/include/asm/rtl865x/re865x.h include/re865x.h;\
	fi

	if [ ! -f include/rtl8651_tblDrvProto.h ] ; then\
		ln -s $(RE865xNICDRVDIR)/rtl8651_tblDrvProto.h include/;\
	fi

	if [ ! -f include/rtl8651_tblDrv.h ] ; then\
		ln -s $(RE865xNICDRVDIR)/rtl8651_tblDrv.h include/;\
	fi

	if [ ! -f include/rtl8651_tblDrvFwd.h ] ; then\
                ln -s $(RE865xNICDRVDIR)/rtl8651_tblDrvFwd.h include/;\
    fi

	if [ ! -f include/rtl8651_tblAsicDrv.h ] ; then\
		ln -s $(RE865xNICDRVDIR)/rtl8651_tblAsicDrv.h include/;\
	fi

	if [ ! -f include/rtl_types.h ] ; then\
		ln -s $(RE865xNICDRVDIR)/rtl_types.h include/;\
	fi
	
	if [ ! -f include/types.h ] ; then\
		ln -s $(RE865xNICDRVDIR)/types.h include/;\
	fi

	if [ ! -f include/rtl8651_dos.h ] ; then\
		ln -s $(RE865xNICDRVDIR)/rtl8651_dos.h include/;\
	fi

	if [ ! -f include/rtl8651_multicast.h ] ; then\
		ln -s $(RE865xNICDRVDIR)/rtl8651_multicast.h include/;\
	fi

	if [ ! -f include/rtl8651_alg_init.h ] ; then\
		ln -s $(RE865xNICDRVDIR)/rtl8651_alg_init.h include/;\
	fi

	if [ ! -f include/board.h ] ; then\
		ln -sf $(CFGMGRDIR)/board.h include/;\
	fi

	if [ ! -f include/asicRegs.h ] ; then\
		ln -sf $(RE865xNICDRVDIR)/asicRegs.h include/;\
	fi

	if [ ! -f include/rtl865xb_asicregs.h ] ; then\
		ln -sf $(RE865xNICDRVDIR)/rtl865xb_asicregs.h include/;\
	fi

	if [ ! -f include/rtl865xc_asicregs.h ] ; then\
		ln -sf $(RE865xNICDRVDIR)/rtl865xc_asicregs.h include/;\
	fi

	if [ ! -f include/hsRegs.h ] ; then\
		ln -s $(RE865xNICDRVDIR)/hsRegs.h include/;\
	fi

	if [ ! -f include/mbuf.h ] ; then\
		ln -s $(RE865xNICDRVDIR)/mbuf.h include/;\
	fi

	if [ ! -f include/rtl_errno.h ] ; then\
		ln -s $(RE865xNICDRVDIR)/rtl_errno.h include/;\
	fi

	if [ ! -f include/rtl8651_layer2.h ] ; then\
		ln -s $(RE865xNICDRVDIR)/rtl8651_layer2.h include/;\
	fi

	if [ ! -f include/rtl8651_tblDrvLocal.h ] ; then\
		ln -s $(RE865xNICDRVDIR)/rtl8651_tblDrvLocal.h include/;\
	fi

	if [ ! -f include/rtl8651_aclLocal.h ] ; then\
		ln -s $(RE865xNICDRVDIR)/rtl8651_aclLocal.h include/;\
	fi

	if [ ! -f include/rtl_queue.h ] ; then\
		ln -s $(RE865xNICDRVDIR)/rtl_queue.h include/;\
	fi

	if [ ! -f include/rtl8651_layer2local.h ] ; then\
		ln -s $(RE865xNICDRVDIR)/rtl8651_layer2local.h include/;\
	fi

	if [ ! -f include/rtl8651_layer3local.h ] ; then\
		ln -s $(RE865xNICDRVDIR)/rtl8651_layer3local.h include/;\
	fi

	if [ ! -f include/rtl8651_layer4local.h ] ; then\
		ln -s $(RE865xNICDRVDIR)/rtl8651_layer4local.h include/;\
	fi

	if [ ! -f include/rtl8651_debug.h ] ; then\
		ln -s $(RE865xNICDRVDIR)/rtl8651_debug.h include/;\
	fi

	# symlink rtl_utils for CLE
	ln -sf ../rtl865x/rtl_utils.c linux-2.4.x/drivers/net/re865x/cle/
	ln -sf ../rtl865x/rtl_utils.h linux-2.4.x/drivers/net/re865x/cle/

	# symlink flashdrv for linux kernel
	ln -sf ../../../../user/boa/src/rtl865x/flashdrv.c $(RE865xNICDRVDIR)/../
	ln -sf ../../../../user/boa/src/rtl865x/flashdrv.h $(RE865xNICDRVDIR)/../
	ln -sf ../../../../user/boa/src/rtl865x/board.h $(RE865xNICDRVDIR)/../
	ln -sf ../../../../user/boa/src/rtl865x/rtl_flashdrv.h $(RE865xNICDRVDIR)/../

	ln -sf ../re865x/cle linux-2.4.x/drivers/net/rtl8186/cle;\

	if [ ! -f $(ROOTDIR)/user/busybox/.config ] ; then \
		cp  ./vendors/$(CONFIG_VENDOR)/$(CONFIG_PRODUCT)/busybox.config ./user/busybox/.config;\
	fi

	@if egrep "^CONFIG_KU_IPSEC=y" $(ROOTDIR)/$(LINUXDIR)/.config > /dev/null;then\
		if [ ! -f $(BUSYBOXDIR)/.moreflag ];then\
			 cat $(VENDDIR)/busybox_more.config  >> $(BUSYBOXDIR)/.config;\
		touch $(BUSYBOXDIR)/.moreflag;\
		make -C user/busybox oldconfig;\
		fi;\
	fi


	$(MAKEARCH_KERNEL) -C $(LINUXDIR) dep

#	$(MAKEARCH) -C $(ROOTDIR)/user/goahead-2.1.4/LINUX  dep 
	touch     $(ROOTDIR)/user/boa/src/y.tab.h
	$(MAKEARCH) -C $(ROOTDIR)/user  depend
# This one removes all executables from the tree and forces their relinking
.PHONY: relink
relink:
	find user -name '*.gdb' | sed 's/^\(.*\)\.gdb/\1 \1.gdb/' | xargs rm -f
	find prop -name '*.gdb' | sed 's/^\(.*\)\.gdb/\1 \1.gdb/' | xargs rm -f
	find $(VENDDIR) -name '*.gdb' | sed 's/^\(.*\)\.gdb/\1 \1.gdb/' | xargs rm -f

clean: modules_clean
	for dir in $(LINUXDIR) $(DIRS); do [ ! -d $$dir ] || $(MAKEARCH) -C $$dir clean ; done
	rm -rf $(ROMFSDIR)/*
	rm -f $(IMAGEDIR)/*
	rm -f config.tk
	rm -f $(LINUXDIR)/linux
	rm -rf $(LINUXDIR)/net/ipsec/alg/libaes $(LINUXDIR)/net/ipsec/alg/perlasm
	rm -f user/dnrd-2.10/src/*.[do]

real_clean mrproper: clean
	-$(MAKEARCH) -C loader_srcroot mrproper
	-$(MAKEARCH_KERNEL) -C $(LINUXDIR) mrproper
	-$(MAKEARCH) -C config clean
	-$(MAKEARCH) -C uClibc distclean
	-$(MAKEARCH) -C $(RELDIR) clean
	-$(MAKEARCH) -C $(ROOTDIR)/user/busybox  distclean
	rm -rf romfs config.in config.arch config.tk images
	rm -f modules/config.tk
	rm -rf include/*.h
	rm -rf .config .config.old .oldconfig autoconf.h
	cp config/.defconfig .config
	cp config/.defoldconfig .oldconfig	

distclean: mrproper
	-$(MAKEARCH_KERNEL) -C $(LINUXDIR) distclean
	-$(MAKEARCH) -C $(ROOTDIR)/user/busybox  distclean
	-rm -f user/tinylogin/applet_source_list user/tinylogin/config.h

%_only:
	[ ! -d "$(@:_only=)" ] || $(MAKEARCH) -C $(@:_only=)

%_clean:
	[ ! -d "$(@:_clean=)" ] || $(MAKEARCH) -C $(@:_clean=) clean

config_error:
	@echo "*************************************************"
	@echo "You have not run make config."
	@echo "The build sequence for this source tree is:"
	@echo "1. 'make config' or 'make menuconfig'"
	@echo "2. 'make dep'"
	@echo "3. 'make'"
	@echo "*************************************************"
	@exit 1

kernel_config_error:
	@echo "*************************************************"
	@echo "ERROR: you need to do a 'make menuconfig' first"
	@echo "*************************************************"
	@exit 1

prune:
	$(MAKE) -C user prune

dist-prep:
	-find $(ROOTDIR) -name 'Makefile*.bin' | while read t; do \
		$(MAKEARCH) -C `dirname $$t` -f `basename $$t` $@; \
	 done
	 
uap-%:
	$(MAKEARCH) -C user $*-install	
	
cuap-%:
	$(MAKEARCH) -C user $*-clean		
 

############################################################################
