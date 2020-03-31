
DEFS = -DHAVE_CONFIG_H -I.
#CFLAGS = -g -O2
#CFLAGS += -g -DDEBUG -DDNI
CFLAGS += -g -DDNI

COMPILE = $(CC) $(DEFS) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(AM_CFLAGS) $(CFLAGS)
LINK = $(CCLD) $(AM_CFLAGS) $(CFLAGS) $(LDFLAGS) -o $@
PACKAGE = ez-ipupdate
VERSION = 3.0.11b7

EXEC1 = ez-ipupdate
OBJS1 = ez-ipupdate.o


FLTFLAGS += -s 16384

all:  $(EXEC1)

.c.o:
	$(COMPILE) -c $<

.s.o:
	$(COMPILE) -c $<

.S.o:
	$(COMPILE) -c $<


cache_file.o: cache_file.c config.h cache_file.h

conf_file.o: conf_file.c config.h conf_file.h

ez-ipupdate.o: ez-ipupdate.c config.h error.h md5.h dprintf.h conf_file.h cache_file.h pid_file.h

md5.o: md5.c config.h md5.h

pid_file.o: pid_file.c config.h error.h dprintf.h


$(EXEC1): $(OBJS1) conf_file.o md5.o cache_file.o pid_file.o

romfs:
	$(ROMFSINST) /bin/ez-ipupdate

clean:
	rm -f $(EXEC1) *.elf *.gdb *.o *.d
