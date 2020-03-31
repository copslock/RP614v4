#
# Makefile for the linux squashfs routines.
#

O_TARGET := squashfs-lzma.o

obj-y  := inode.o
obj-$(CONFIG_SQUASHFS_LZMA) += LzmaDecode.o

obj-m := $(O_TARGET)

include $(TOPDIR)/Rules.make
