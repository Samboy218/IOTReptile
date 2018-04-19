
dhtd: ./src/dhtd.c ./src/dht22.c ./src/dht22.h
	gcc -o dhtd ./src/dhtd.c ./src/dht22.c -lwiringPi

.PHONY: install
install: dhtd
	sudo cp dhtd /usr/sbin/dhtd
	sudo cp ./init/dhtd /etc/init.d/dhtd
	sudo cp ./cfg/dhtd.cfg /etc/dhtd.cfg
	sudo insserv dhtd
