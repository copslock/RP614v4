
CFLAGS	+= -I. -Wall
#CFLAGS	+= -Wall
CFLAGS	+= -s -O2
LDFLAGS += -L.

SRCOBJ = smtpclient_main.o smtpclient_errno.o md5c.o base64.o hmac_md5.o

EXTRA_LIB = -L../dniutil -ldniutil

SBINPGM = smtpclient

all: $(SBINPGM)


$(SBINPGM): $(SRCOBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(SRCOBJ) $(EXTRA_LIB)
	
clean:
	rm -f *.o smtpclient

romfs:
	$(ROMFSINST) /bin/smtpclient
#	$(ROMFSINST) /bin/log_list.txt
