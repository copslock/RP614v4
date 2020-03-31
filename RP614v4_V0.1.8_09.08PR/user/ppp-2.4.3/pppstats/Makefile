#
# pppstats makefile
# $Id: Makefile,v 1.2 2005/11/02 08:26:15 rupert Exp $
#
DESTDIR = /usr/local
BINDIR = $(DESTDIR)/sbin
MANDIR = $(DESTDIR)/share/man/man8

PPPSTATSRCS = pppstats.c
PPPSTATOBJS = pppstats.o

#CC = /opt/toolchain_mips/bin/mips-linux-gcc
#COPTS = -O -mips1 -msoft-float  -fPIC -I../../../include -nostdinc -I../../../lib/uClibc/include -I../../../lib/libcrypt -I../../../lib/zlib -I../../.. -idirafter /opt/toolchain_mips_nofpu/usr/bin/../lib/gcc-lib/mips-linux-uclibc/3.3.3//include -I../../../linux-2.4.x/include -I../include/net -I../include/linux
COPTS =  -I../../../include  -I../../..  -I../include/net -I../include/linux
COMPILE_FLAGS = -I../include
LIBS =

INSTALL= install

CFLAGS += $(COPTS) $(COMPILE_FLAGS)

all: pppstats

install: pppstats
	-mkdir -p $(MANDIR)
	$(INSTALL) -s -c pppstats $(BINDIR)
	$(INSTALL) -c -m 444 pppstats.8 $(MANDIR)

pppstats: $(PPPSTATSRCS)
	$(CC) $(CFLAGS) -o pppstats pppstats.c $(LIBS)

clean:
	rm -f pppstats *~ #* core

depend:
	cpp -M $(CFLAGS) $(PPPSTATSRCS) >.depend
#	makedepend $(CFLAGS) $(PPPSTATSRCS)
