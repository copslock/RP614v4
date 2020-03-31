#
# Linux upnp Makefile
#
#

CROSS_COMPILE=mips-linux-

UPNP	:= igd/linux
SRCBASE :=$(CWD)
#CFLAGS	+= -s -O2
#DEBUG	:= 1

ifeq ($(RELEASE_CODE),y)
	CFLAGS	+= -DRELEASE_CODE
endif

all: upnp

install: all
#	install -d $(INSTALLDIR)/usr/sbin
#	install -m 755 upnp $(INSTALLDIR)/usr/sbin
#	$(STRIP) $(INSTALLDIR)/usr/sbin/upnp
#	${CP} $(CWD)/upnp/igd/linux/upnp $(DESTSBIN)
	$(MAKE) -C $(UPNP) install

clean:
	#$(MAKE) -C $(UPNP) clean
	#rm -f upnp

upnp: FORCE
	$(MAKE) -C $(UPNP) DEBUG=$(DEBUG) SRCBASE=$(SRCBASE) TARGET_PREFIX=$(CROSS_COMPILE)
	#$(CP) $(UPNP)/upnp $(DESTSBIN)
	#$(CP) upnp $(DESTSBIN)

FORCE:


romfs:
	$(MAKE) -C $(UPNP) romfs