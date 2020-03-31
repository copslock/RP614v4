
KERNEL_HEADERS=-I$(KERNEL_DIR)/include

AR=mips-linux-ar
RANLIB=mips-linux-ranlib

CC=mips-linux-gcc
CFLAGS += -DNO_SHARED_LIBS=1

prefix=/usr/local
exec_prefix=${prefix}
includedir=${prefix}/include
libdir=${exec_prefix}/lib

ifndef HAVE_IF_INDEX
COMPAT_SOURCES=  \
	libbridge_compat.c 
else
COMPAT_SOURCES=  
endif

libbridge_SOURCES= \
	$(COMPAT_SOURCES) \
	libbridge_devif.c \
	libbridge_if.c \
	libbridge_init.c \
	libbridge_misc.c 

libbridge_OBJECTS=$(libbridge_SOURCES:.c=.o)

all:	libbridge.a

install: libbridge.a
	mkdir -p $(DESTDIR)$(includedir)
	install -m 644 libbridge.h $(DESTDIR)$(includedir)
	mkdir -p $(DESTDIR)$(libdir)
	install -m 644 libbridge.a $(DESTDIR)$(libdir)


clean:
	rcsclean *
	rm -f *~
	rm -f *.o
	rm -f libbridge.a

libbridge.a:	$(libbridge_OBJECTS)
	$(AR) rcvs $@ $(libbridge_OBJECTS)
	$(RANLIB) $@

%.o: %.c libbridge.h libbridge_private.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

libbridge_compat.o:	libbridge_compat.c if_index.c
	$(CC) $(CFLAGS) -c libbridge_compat.c

