#! /bin/bash
i=0
for pin in ${1}
do
    sudo ln -s /var/log/dhtd${i}.log /var/www/html/dhtd${i}.log
    ((i++))
done
