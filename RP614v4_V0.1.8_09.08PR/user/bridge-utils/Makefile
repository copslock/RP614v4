
NO_SHARED_LIBS = 1
FLTFLAGS += -s 8192

KERNEL_DIR=$(ROOTDIR)/$(LINUXDIR)


DESTDIR=
KERNEL_HEADERS=-I$(KERNEL_DIR)/include

INSTALL=install -s

prefix=/usr/local
exec_prefix=${prefix}
bindir=${exec_prefix}/bin
sbindir=${exec_prefix}/sbin
mandir=${prefix}/man

SUBDIRS=libbridge brctl doc

all:
	for x in $(SUBDIRS); do (cd $$x && $(MAKE) ); done

clean:
	for x in $(SUBDIRS); do (cd $$x && $(MAKE) clean ); done

romfs:
	$(ROMFSINST)   brctl/brctl /bin/brctl
	$(ROMFSINST)   brctl/brctld /bin/brctld

distclean:	clean
	rm -f config.log
	rm -f config.cache
	rm -f config.status

maintainer-clean: distclean
	rm -f Makefile
	rm -f brctl/Makefile
	rm -f libbridge/Makefile
	rm -f doc/Makefile

install:
	for x in $(SUBDIRS); do (cd $$x && $(MAKE) install ); done

