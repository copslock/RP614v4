#CC		= gcc
#COPT		= -O1
#CDEF		= -D_REENTRANT
#CWARN		= -Wall 
#CDBG		= -ggdb
CFLAGS		+= -DRTL_PATCHED -DENABLE_PIDFILE -DDNI
#CFLAGS		= ${CWARN} ${COPT} ${CDEF} ${CDBG} -DEMBED -DRTL_PATCHED
#LDFLAGS		+= -Wl,-elf2flt="-s 0x2000"
#LDFLAGS		+= -pthread
#LIBS            += -lpthread
LIBS		+=$(LDLIBS)
#INSTDIR		= /usr/local/sbin
#MANDIR		= /usr/local/man/man8
SHELL		= /bin/sh

all:	dnrd

clean:
	rm -f dnrd core tags ID *.o *.d *~ *.bak *.gdb

#install: dnrd
#	strip dnrd
#	install -m 0751 -o root -g root -s dnrd ${INSTDIR}
#	install -m 0644 -o root -g root -s ../doc/dnrd.8 ${MANDIR}

sources = args.c check.c dns.c lib.c master.c query.c relay.c srvnode.c udp.c \
	  cache.c common.c domnode.c main.c qid.c rand.c sig.c tcp.c

	  

#include $(sources:.c=.d)

dnrd:	$(sources:.c=.o)
	$(CC) $(LDFLAGS)  $^ -o $@ $(LIBS)

%.d: %.c
	@$(SHELL) -ec '$(CC) -MM $(CFLAGS) $< \
		      | sed '\''s/\($*\)\.o[ :]*/\1.o $@ : /g'\'' > $@; \
		      [ -s $@ ] || rm -f $@'
