#ifndef DHT_22_H
#define DHT_22_H

#include <wiringPi.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

bool read_dht_data(int gpio_pin, float* humidity, float* temperature);

#endif
