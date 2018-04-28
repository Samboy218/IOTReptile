
export PINS= "7 4 9"

.PHONY: daemon
daemon:
	echo "#dont touch this file before installation" > daemon/cfg/dhtd.cfg
	echo "PINS= ${PINS}" >> daemon/cfg/dhtd.cfg
	cd daemon && make install

.PHONY: web
web:
	cd ./web && make install

.PHONY: uninstall
uninstall:
	sudo rm -f /etc/init.d/dhtd
	sudo rm -f /etc/dhtd.cfg
	sudo rm -f /var/run/dhtd.pid
	sudo rm -f /usr/sbin/dhtd
	sudo rm -f /var/log/dhtd*
	sudo rm -rf /var/www/html/*
