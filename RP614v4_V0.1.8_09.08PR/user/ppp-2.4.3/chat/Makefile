#	$Id: Makefile,v 1.2 2005/11/02 08:26:15 rupert Exp $

DESTDIR = /usr/local
BINDIR = $(DESTDIR)/sbin
MANDIR = $(DESTDIR)/share/man/man8
#CC = /opt/toolchain_mips/bin/mips-linux-gcc


CDEF1=	-DTERMIOS			# Use the termios structure
CDEF2=	-DSIGTYPE=void			# Standard definition
CDEF3=	-UNO_SLEEP			# Use the usleep function
CDEF4=	-DFNDELAY=O_NDELAY		# Old name value
CDEFS=	$(CDEF1) $(CDEF2) $(CDEF3) $(CDEF4)

COPTS=	-O2 -g -pipe
#CFLAGS=	$(COPTS) $(CDEFS)  -mips1 -msoft-float  -fPIC -nostdinc -I../../../lib/uClibc/include -I../../../lib/libcrypt -I../../../lib/zlib -I../../.. -idirafter /opt/toolchain_mips_nofpu/usr/bin/../lib/gcc-lib/mips-linux-uclibc/3.3.3//include -I../../../linux-2.4.x/include 

INSTALL= install

all:	chat

chat:	chat.o
	$(CC) -o chat chat.o

chat.o:	chat.c
	$(CC) -c $(CFLAGS) -o chat.o chat.c

install: chat
	mkdir -p $(BINDIR)
	$(INSTALL) -s -c chat $(BINDIR)
	$(INSTALL) -c -m 644 chat.8 $(MANDIR)

clean:
	rm -f chat.o chat *~

romfs:
	$(ROMFSINST) /bin/chat
