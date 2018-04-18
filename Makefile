
dhtDaemon: ./src/dhtDaemon.c ./src/dht22.c ./src/dht22.h
	gcc -o ./bin/dhtDaemon ./src/dhtDaemon.c ./src/dht22.c -lwiringPi

.PHONY: install
install: dhtDaemon
	sudo cp ./bin/dhtDaemon /usr/sbin/dhtDaemon
	sudo cp ./init/dhtDaemon /etc/init.d/dhtDaemon
	sudo insserv dhtDaemon
