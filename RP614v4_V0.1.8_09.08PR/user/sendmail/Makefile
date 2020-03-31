EXEC1 = sendmail
OBJS1 = sendmail.o


FLTFLAGS += -s 16384
all:  $(EXEC1)

$(EXEC1): $(OBJS1)
	$(CC)  $(LDFLAGS) -o $@ $(OBJS1) $(LDLIBS) 


romfs:
	$(ROMFSINST) /bin/sendmail

clean:
	rm -f $(EXEC1) *.o
