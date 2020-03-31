#
# Makefile for the 865x software big number operation
#
# Note! Dependencies are done automagically by 'make dep', which also
# removes any old dependencies. DON'T put your own dependencies here
# unless it's something special (ie not a .c file).
#
# Note 2! The CFLAGS definitions are now in the main makefile...

O_TARGET := 865xc_cryptoengine.o
obj-y    := \
			rtl865xc_authEngine.o \
			rtl865xc_cryptoEngine.o \
			authSim.o \
			authTest.o \
			desSim.o \
			destest.o \
			hmactest.o \
			md5test.o \
			sha1test.o \
			aes_core.o \
			aes_block.o \
			md5.o \
			sha1.o \
			hmac.o \


obj-$(CONFIG_RTL865X_CLE) += cryptoCmd.o

EXTRA_CFLAGS += -I. -I../../rtl865x -I../../cle -Wall -Werror -Wuninitialized -O -Wstrict-prototypes
EXTRA_CFLAGS += -I../../model -I../../model/865xC
EXTRA_CFLAGS += -DRTL865X_OVER_KERNEL -DRTL865X_OVER_LINUX


include $(TOPDIR)/Rules.make
