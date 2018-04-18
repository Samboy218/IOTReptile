# IOT Reptile

Project for an IOT reptile habitat.

Using DHT22 for temperature/humidity. 

raspberry pi collects the data and hosts it via apache.

paths touched:
    binary location:
        /usr/sbin/dhtDaemon
    log location:
        /var/log/dhtDaemon/dhtDaemon.log
    start up script:
        /etc/init.d/dhtDaemon
    pid location:
        /var/run/dhtDaemon.pid
