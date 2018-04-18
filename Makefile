
all: dhtRead

dhtRead: dht22.c dht22.h main.c
	gcc -o dhtRead main.c dht22.c -lwiringPi

dhtDaemon: dhtDaemon.c dht22.c dht22.h
	gcc -o dhtDaemon dhtDaemon.c dht22.c -lwiringPi

.PHONY: install
install: dhtDaemon
	sudo cp dhtDaemon /usr/sbin/dhtDaemon
	sudo cp init/dhtDaemon /etc/init.d/dhtDaemon
	sudo insserv dhtDaemon
