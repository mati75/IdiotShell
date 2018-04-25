CC=gcc
prefix=/usr/local

idiotshell: idiotshell.c
	$(CC) $(CFLAGS) $(LFLAGS) idiotshell.c -o idiotshell

install:
	install -m 0755 idiotshell $(prefix)/bin
	install -m 0755 roll.sh $(prefix)/bin
	mkdir -p /etc/idiotshell
	touch /etc/idiotshell/shell.log && chmod 666 /etc/idiotshell/shell.log
	cp fake_dmesg.txt /etc/idiotshell/fake_dmesg.txt

clean:
	rm -f idiotshell

.PHONY: idiotshell install clean
