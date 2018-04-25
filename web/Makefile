
.PHONY: install
install:
	sudo cp index.html /var/www/html/index.html
	sudo cp -r ./includes/ /var/www/html/includes/
	for (i=0; i < $((`echo ${PINS} | wc -w`)); i++); do \
        sudo ln -s /var/log/dhtd${i}.log /var/www/html/dhtd${i}.log; \
    done
