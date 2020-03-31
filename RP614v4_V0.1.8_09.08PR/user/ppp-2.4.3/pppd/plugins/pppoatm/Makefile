#CC = /opt/toolchain_mips/bin/mips-linux-gcc
#COPTS=-O2 -g -mips1 -msoft-float  -fPIC -I../../../../../include -nostdinc -I../../../../../lib/uClibc/include -I../../../../../lib/libcrypt -I../../../../../lib/zlib -I../../../../.. -idirafter /opt/toolchain_mips_nofpu/usr/bin/../lib/gcc-lib/mips-linux-uclibc/3.3.3//include -I../../../../../linux-2.4.x/include 
CFLAGS	+=  -I../.. -I../../../include
LDFLAGS	= -shared
INSTALL	= install

#***********************************************************************

DESTDIR = /usr/local
LIBDIR = $(DESTDIR)/lib/pppd/$(VERSION)

VERSION = $(shell awk -F '"' '/VERSION/ { print $$2; }' ../../patchlevel.h)

PLUGIN := pppoatm.so
PLUGIN_OBJS := pppoatm.o 

#*******
# Do we have the ATM libraries installed? Set HAVE_LIBATM to use them,
# or leave it unset to build the few routines we actually _use_ into
# the plugin directly.
#
#HAVE_LIBATM=yes

ifdef HAVE_LIBATM
LIBS := -latm
else
CFLAGS += -I.
PLUGIN_OBJS += text2qos.o text2atm.o misc.o ans.o
LIBS := -lresolv
endif

#*********
all: $(PLUGIN)

$(PLUGIN): $(PLUGIN_OBJS)
	$(CC) $(CFLAGS) -o $@ -shared $^ $(LIBS)

install: all
	$(INSTALL) -d -m 755 $(LIBDIR)
	$(INSTALL) -c -m 4550 $(PLUGIN) $(LIBDIR)

clean:
	rm -f *.o *.so

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
