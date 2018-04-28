#! /bin/bash

#this pretty much just echoes the proper HTML
echo "<!DOCTYPE html>"
echo "<html>"
echo "<head><title>Temperature Sensor Console</title></head>"
echo "<body>"
(($1--))
for i in `seq 0 $1`;
do
    echo "<a href=/sens${i}/>Sensor ${i}</a><br />"
done
echo "</body>"
echo "</html>"
