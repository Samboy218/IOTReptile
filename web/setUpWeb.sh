#! /bin/bash
i=0
for pin in ${1}
do
    sudo mkdir /var/www/html/sens${i}
    sudo ln -s /var/log/dhtd${i}.log /var/www/html/sens${i}/dhtd.log
    sudo cp template.html /var/www/html/sens${i}/index.html
    ((i++))
done
#now make the index page
./makeInd ${i} > index.html
