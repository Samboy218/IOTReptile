
#include <wiringPi.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

void read_dht_data(int gpio_pin, float* humidity, float* temperature);
