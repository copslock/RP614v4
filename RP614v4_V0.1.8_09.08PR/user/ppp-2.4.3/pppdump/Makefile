DESTDIR = /usr/local
BINDIR = $(DESTDIR)/sbin
MANDIR = $(DESTDIR)/share/man/man8
#CC = /opt/toolchain_mips/bin/mips-linux-gcc

#CFLAGS= -O -I../include/net  -mips1 -msoft-float  -fPIC -I../../../include -nostdinc -I../../../lib/uClibc/include -I../../../lib/libcrypt -I../../../lib/zlib -I../../.. -idirafter /opt/toolchain_mips_nofpu/usr/bin/../lib/gcc-lib/mips-linux-uclibc/3.3.3//include -I../../../linux-2.4.x/include -I../include/net -I../include/linux
OBJS = pppdump.o bsd-comp.o deflate.o zlib.o

CFLAGS+=  -I../include/net  -I../../../include  -I../../..  -I../include/net -I../include/linux
INSTALL= install

all:	pppdump

pppdump: $(OBJS)
	$(CC) -o pppdump $(OBJS)

clean:
	rm -f pppdump $(OBJS) *~

install:
	mkdir -p $(BINDIR) $(MANDIR)
	$(INSTALL) -s -c pppdump $(BINDIR)
	$(INSTALL) -c -m 444 pppdump.8 $(MANDIR)
