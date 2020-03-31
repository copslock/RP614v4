# Generated automatically from Makefile.in by configure.

#KERNEL_HEADERS=-I$(ROOTDIR)/linux-2.4.x

# Add -DNO_DAEMON if you do not want the server to fork upon launch
#LDFLAGS = -lnsl 
#CFLAGS = -O -DLINUX -I$(ROOTDIR)/lib/include -I$(ROOTDIR)/lib/include/sys -I$(ROOTDIR)/$(LINUXDIR)/include -I$(ROOTDIR)/$(LINUXDIR)/include/asm-mips -I$(ROOTDIR)/include -I. -I./rtl865x 

# You must uncomment these four line to enable SSL.
#CFLAGS += -DSERVER_SSL -I$(ROOTDIR)/lib/libssl/include
#SSLLIB = -L$(ROOTDIR)/lib/libssl/libssl.a -L$(ROOTDIR)/lib/libssl/libcrypto.a
#LDFLAGS+= $(SSLLIB) $(IFMODLIB)
#LIBCRYPT += -lssl -lcrypto 

#include $(ROOTDIR)/linux-2.4.x/include/linux/config.h


#SOURCES =board.c\
#	ipupdown.c \
#	tblDrv_mapping.c \
#	cfgmgr.c 

SOURCES =ipupdown.c \
	cfgmgr.c 
	
#ifdef CONFIG_MTD
#	SOURCES += flashmtd.c
#else
	SOURCES += flashdrv.c
#endif


OBJS = ${SOURCES:.c=.o} 

LIBHTTP=libhttp.a
.PHONY: clean mrclean depend all 
all: $(LIBHTTP) 
$(LIBHTTP) :	${OBJS}
	${AR} $(ARFLAGS)  $@ ${OBJS}   	

clean:
	rm -f ${OBJS}  $(LIBHTTP) 

mrclean:	clean
	rm -f config.status config.cache config.h Makefile config.log

# parser dependencies

#escape.h:	escape.pl
#	perl escape.pl >escape.h
depend:
	${CC} $(CFLAGS) -E -MM ${SOURCES} > .depend
	rm -f $(LIBHTTP) flash*.o

-include .depend
