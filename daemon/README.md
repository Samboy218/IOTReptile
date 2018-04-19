# dht22d
daemon which reads data from dht22 sensors and logs it  

## Installation
Simply build using the included makefile  
`make install`  
This will compile the binary and put everything in their proper places.
this will also register dhtd to start on boot.  

#### File locations
* binary location:  
    * `/usr/sbin/dhtd`
* log location:  
    * `/var/log/dhtd.log`
* start up script:  
    * `/etc/init.d/dhtd`
* pid location:  
    * `/var/run/dhtd.pid`
