#CC = /opt/toolchain_mips/bin/mips-linux-gcc
COPTS	= -O2 -g  -mips1 -msoft-float  -fPIC -I../../../../include -nostdinc -I../../../../lib/uClibc/include -I../../../../lib/libcrypt -I../../../../lib/zlib -I../../../.. -idirafter /opt/toolchain_mips_nofpu/usr/bin/../lib/gcc-lib/mips-linux-uclibc/3.3.3//include -I../../../../linux-2.4.x/include 
CFLAGS	+=  -I.. -I../../include 
LDFLAGS	= -shared
INSTALL	= install
DIRS = rp-pppoe-3.7

DESTDIR = /usr/local
BINDIR = $(DESTDIR)/sbin
MANDIR = $(DESTDIR)/share/man/man8
LIBDIR = $(DESTDIR)/lib/pppd/$(VERSION)

SUBDIRS := rp-pppoe-3.7 pppoatm radius
# Uncomment the next line to include the radius authentication plugin
# SUBDIRS += radius
PLUGINS := minconn.so passprompt.so passwordfd.so winbind.so

# include dependencies if present
ifeq (.depend,$(wildcard .depend))
include .depend
endif

all:	$(PLUGINS)
	for d in $(SUBDIRS); do $(MAKE) $(MFLAGS) -C $$d all || exit $? ; done

%.so: %.c
	$(CC) -o $@ $(LDFLAGS) $(CFLAGS) $^

VERSION = $(shell awk -F '"' '/VERSION/ { print $$2; }' ../patchlevel.h)

install: $(PLUGINS)
	$(INSTALL) -d $(LIBDIR)
	$(INSTALL) $? $(LIBDIR)
	for d in $(SUBDIRS); do $(MAKE) $(MFLAGS) -C $$d install; done

clean:
	rm -f *.o *.so *.a
	for d in $(SUBDIRS); do $(MAKE) $(MFLAGS) -C $$d clean; done

depend:
	$(CPP) -M $(CFLAGS) *.c >.depend
	for d in $(SUBDIRS); do $(MAKE) $(MFLAGS) -C $$d depend; done

romfs:
	for i in $(DIRS) ; do make -C $$i romfs || exit $? ; done	