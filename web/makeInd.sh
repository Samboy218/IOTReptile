#! /bin/bash

#this pretty much just echoes the proper HTML
echo "<!DOCTYPE html>\n<html>\n<head><title>Temperature Sensor Console</title>"
echo "</head>\n<body>"
for i in `seq 0 $1`;
do
    echo "<a href=/sens${i}/>Sensor ${i}</a>"
done
echo "</body>\n</html>\n"
