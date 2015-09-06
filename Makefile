CC=gcc
prefix=/usr/local

idiotshell: tdk.c
	$(CC) $(CFLAGS) $(LFLAGS) tdk.c -o TDK8GB

install:
	install -m 0755 TDK8GB $(prefix)/bin
	install -m 0755 roll.sh $(prefix)/bin
	mkdir -p /etc/jaja_z_tdk
	touch /etc/jaja_z_tdk/log.txt
	cp /var/log/dmesg /etc/jaja_z_tdk/dmesg.txt

clean:
	rm -f TDK8GB

.PHONY: idiotshell install clean
