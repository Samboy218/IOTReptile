
export PINS= "7 4 9"

.PHONY: daemon
daemon:
	echo "#dont touch this file before installation" > daemon/cfg/dhtd.cfg
	echo "PINS= ${PINS}" >> daemon/cfg/dhtd.cfg
	cd daemon && make install

.PHONY: web
web:
	cd web && make show
