###########################################################################
# Makefile for BPALogin v2.0
##

##
# Install locations as determined by configure
#prefix=/usr/local
#exec_prefix=${prefix}
#SBINPATH=${exec_prefix}/sbin
#ETCPATH=${prefix}/etc

##
# Locations of system utilities as determined by configure
#CC=mipsel-linux-gcc
#CHKCONFIG=/sbin/chkconfig
#INSTALL=/usr/bin/install -c
#SED=/bin/sed

##
#
#CFLAGS=-g -O2 -Wall -I$(TOP)/shared
CFLAGS += -I. -I../../include

ifeq ($(RELEASE_CODE),y)
	CFLAGS	+= -DRELEASE_CODE
endif

#LIBS=-lnsl 
#LDFLAGS=-L$(TOP)/nvram -L$(INSTALLDIR)/nvram/usr/lib -lnvram -L$(TOP)/shared -L$(INSTALLDIR)/shared/usr/lib -lshared
EXTRA_LIB = -L../dniutil -ldniutil

OBJS = bpalogin.o protocol.o transaction.o gen_md5.o unixmain.o

bpalogin: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) $(EXTRA_LIB)
	
all : bpalogin

#.c.o:
#	$(CC) $(CFLAGS) -c $<

clean:
	rm -fr *.o

distclean: clean
	rm -f bpalogin config.log config.cache config.status Makefile bpalogin.h

bpalogin.h: bpalogin.h.in
	$(SED) 's#@@BPALOGIN_CONF@@#$(ETCPATH)/bpalogin.conf#' < bpalogin.h.in > bpalogin.h

$(OBJS): bpalogin.h

install: bpalogin
#	install -D bpalogin $(INSTALLDIR)/usr/sbin/bpalogin
#	$(STRIP) $(INSTALLDIR)/usr/sbin/bpalogin
	$(CP) bpalogin $(DESTSBIN)
	
romfs:
	$(ROMFSINST) /bin/bpalogin	
