
dhtd: ./src/dhtd.c ./src/dht22.c ./src/dht22.h
	gcc -o ./bin/dhtd ./src/dhtd.c ./src/dht22.c -lwiringPi

.PHONY: install
install: dhtd
	sudo cp ./bin/dhtd /usr/sbin/dhtd
	sudo cp ./init/dhtd /etc/init.d/dhtd
	sudo insserv dhtd
