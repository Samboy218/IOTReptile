
#include "dht22.h"
#include <stdio.h>

int main() {
    if (wiringPiSetup() == -1)
        exit(1);
    float humidity;
    float temp;
    int gpio_pin = 7;
    while(1) {
        
        if (read_dht_data(gpio_pin, &humidity, &temp))
            printf("Humidiy: %f%, Temperature: %fc\n", humidity, temp);
        else
            printf("BAD READING\n");
        delay(500);
    }
    return 0;
}
