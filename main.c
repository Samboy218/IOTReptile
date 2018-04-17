
#include "dht22.h"
#include <stdio.h>

int main() {
    if (wiringPiSetup() == -1)
        exit(1);
    float humidity;
    float temp;
    int gpio_pin = 7;
    while(1) {
        read_dht_data(gpio_pin, &humidity, &temp);
        if (humidity < 0)
            printf("BAD READING\n");
        else
            printf("Humidiy: %f%, Temperature: %fc\n", humidity, temp);
        delay(2000);
    }
    return 0;
}
