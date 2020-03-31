#LIBHTTP=rtl865x/libhttp.a


EXEC1 = getdeviceinfo
OBJS1 = getdeviceinfo.o

LIBS_DNI = -L../dniutil -ldniutil 

ifdef CONFIG_UCLINUX
BINDIR = /bin
else
BINDIR = /sbin
endif
ifdef CONSOLE_BAUD_RATE
CFLAGS += -DCONSOLE_BAUD_RATE=$(CONSOLE_BAUD_RATE)
endif

ifdef CONFIG_LIB_UC_LIBC_TIMEZONE
CFLAGS += -DINCLUDE_TIMEZONE
endif

all: $(EXEC1) 

#$(LIBHTTP):
#	make -C rtl865x

$(EXEC1): $(OBJS1)
	$(CC) $(LDFLAGS) -o $@ $(OBJS1) $(LIBCRYPT) $(LDLIBS$(LDLIBS-$(@)))  $(LIBS_DNI)


	

romfs:
	$(ROMFSINST)  /bin/$(EXEC1)

clean:
	rm -f simpleinit $(EXEC1) *.elf *.gdb *.o

