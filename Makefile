
all: dhtRead

dhtRead: dht22.c dht22.h main.c
	gcc -o dhtRead main.c dht22.c -lwiringPi
