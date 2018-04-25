
.PHONY: install
install:
	sudo cp index.html /var/www/html/index.html
	sudo cp -r ./includes/ /var/www/html/includes/
	i=0; \
	for pin in ${PINS}; do \
        sudo ln -s /var/log/dhtd${i}.log /var/www/html/dhtd${i}.log; \
	    i++; \
    done
