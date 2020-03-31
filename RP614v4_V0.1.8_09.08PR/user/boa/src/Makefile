# Generated automatically from Makefile.in by configure.

#KERNEL_HEADERS=-I$(ROOTDIR)/linux-2.4.x

GCC_FLAGS = -Wstrict-prototypes -Wpointer-arith -Wcast-align -Wcast-qual\
  -Wtraditional\
  -Wshadow\
  -Wconversion\
  -Waggregate-return\
  -Wmissing-prototypes\
  -Wnested-externs\
  -Wall

# Add -DNO_DAEMON if you do not want the server to fork upon launch
#LDFLAGS = -lnsl 
#CFLAGS = -O -DLINUX -I$(ROOTDIR)/lib/include -I$(ROOTDIR)/lib/include/sys -I$(ROOTDIR)/$(LINUXDIR)/include -I$(ROOTDIR)/$(LINUXDIR)/include/asm-mips -I$(ROOTDIR)/include -I. -I./rtl865x 

# You must uncomment these four line to enable SSL.
#CFLAGS += -DSERVER_SSL -I$(ROOTDIR)/lib/libssl/include
#SSLLIB = -L$(ROOTDIR)/lib/libssl/libssl.a -L$(ROOTDIR)/lib/libssl/libcrypto.a
#LDFLAGS+= $(SSLLIB) $(IFMODLIB)
#LIBCRYPT += -lssl -lcrypto 
MANDIR = /usr/local/man
BINDIR = /usr/local/sbin

CFLAGS += -DDNI -DNEW_WEB_PAGES -DNVRAM_SHARED_LIB


LIBS_DNI = -L../../dniutil -ldniutil 

# FreeBSD's make doesn't like `ifdef`, but likes `.ifdef`
ifdef INET6
LDFLAGS += -L/usr/inet6/lib -linet6
CFLAGS += -DINET6 -I/usr/inet6/include
endif

# Change these if necessary

YACC = bison -y 
LEX = flex 
LIBHTTP=rtl865x/libhttp.a
LIBHTTP_DNI=dni/libhttp_dni.a


SOURCES = alias.c boa.c cgi.c config.c get.c hash.c log.c \
    queue.c read.c request.c response.c signals.c util.c \
    cgi_header.c pipe.c nls.c auth.c globals.c \
    asp_page.c \
  
    
   
	
//OBJS = y.tab.o lex.yy.o ${SOURCES:.c=.o} timestamp.o
OBJS = ${SOURCES:.c=.o} timestamp.o

OBJS1 = ${SOURCES1:.c=.o}

.PHONY: clean mrclean depend all $(LIBHTTP) $(LIBHTTP_DNI)

 
all:	 boa
$(LIBHTTP):
	make -C rtl865x
	
	
boa:	${OBJS} $(LIBHTTP) $(LIBHTTP_DNI)
	${CC} $(LDFLAGS) -o $@ ${OBJS} $(LIBHTTP) $(LIBHTTP_DNI)  $(LIBCRYPT) $(LDLIBS$(LDLIBS-$(@))) $(LIBS_DNI)  
	
	
clean:
	rm -f ${OBJS} ${OBJS1} boa core lex.yy.c y.tab.c y.tab.h rtl865x/*.o rtl865x/*.a rtl865x/.depend .depend
	
mrclean:	clean
	rm -f config.status config.cache config.h Makefile config.log

# parser dependencies

y.tab.c y.tab.h:	boa_grammar.y
	${YACC} -d boa_grammar.y

lex.yy.c:	boa_lexer.l
	${LEX} boa_lexer.l

#escape.h:	escape.pl
#	perl escape.pl >escape.h

%.d: %.c
	$(CC) -E $(CFLAGS) $(EXTRACFLAGS) -Wp,-MD,$*.d $< >/dev/null
	
depend:
	$(MAKE) -C rtl865x depend
	${CC} $(CFLAGS) -E -MM ${SOURCES} > .depend
	
-include .depend

timestamp.c:	${SOURCES} boa_grammar.y boa_lexer.l
	touch timestamp.c

install:	boa
	install -c -m 755 boa ${BINDIR} 
	install -c -m 755 ../utils/boa_indexer ${BINDIR}
	install -c -m 644 ../docs/boa.1 ${MANDIR}/man1

SOCKET = socket localhost 80
ECHO = /bin/echo

.PHONY: test dne cgi_bin dir normal

test:	dne cgi_bin dir normal

dne:
	${ECHO} 'GET /file_that_does_not_exit HTTP/1.0\n\n' | ${SOCKET}
	${ECHO} 'GET /file_that_does_not_exit\n' | ${SOCKET}
	${ECHO} 'HEAD /file_that_does_not_exit HTTP/1.0\n\n' | ${SOCKET}
	${ECHO} 'HEAD /file_that_does_not_exit\n' | ${SOCKET}

cgi_bin:
	${ECHO} 'GET /cgi-bin/cgi-test.cgi HTTP/1.0\n\n' | ${SOCKET}
	${ECHO} 'GET /cgi-bin/cgi-test.cgi\n' | ${SOCKET}
	${ECHO} 'HEAD /cgi-bin/cgi-test.cgi HTTP/1.0\n\n' | ${SOCKET}
	${ECHO} 'HEAD /cgi-bin/cgi-test.cgi\n' | ${SOCKET}

DIR = /doc/

dir:
	${ECHO} 'GET ${DIR} HTTP/1.0\n\n' | ${SOCKET}
	${ECHO} 'GET ${DIR}\n' | ${SOCKET}
	${ECHO} 'HEAD ${DIR} HTTP/1.0\n\n' | ${SOCKET}
	${ECHO} 'HEAD ${DIR}\n' | ${SOCKET}

NORMAL = /test_file.gz

normal:
	${ECHO} 'GET ${NORMAL} HTTP/1.0\n\n' | ${SOCKET} | wc -c
	${ECHO} 'GET ${NORMAL}\n' | ${SOCKET} | wc -c
	${ECHO} 'HEAD ${NORMAL} HTTP/1.0\n\n' | ${SOCKET}
	${ECHO} 'HEAD ${NORMAL}' | ${SOCKET}

GZ = /test_file

# Note: to test automatic gunzipping a file named "test_file.gz" must be in
# the document root.

gz:	
	${ECHO} 'GET ${GZ} HTTP/1.0\n\n' | ${SOCKET} | wc -c
	${ECHO} 'GET ${GZ}\n' | ${SOCKET} | wc -c
	${ECHO} 'HEAD ${GZ} HTTP/1.0\n\n' | ${SOCKET}
	${ECHO} 'HEAD ${GZ}\n' | ${SOCKET}


romfs:
	$(ROMFSINST) /bin/boa
	$(ROMFSINST) ${WWW_PATH}   /www

