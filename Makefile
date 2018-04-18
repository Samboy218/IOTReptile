
all: dhtRead

dhtRead: dht22.c dht22.h main.c
	gcc -o dhtRead main.c dht22.c -lwiringPi

daemon: dhtDaemon.c dht22.c dht22.h
	gcc -o dhtDaemon dhtDaemon.c dht22.c -lwiringPi
