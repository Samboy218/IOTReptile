#include "dht22.h"
#define MAX_TIMINGS 85

void read_dht_data(int gpio_pin, float* humidity, float* temp) {
    uint8_t laststate = HIGH;
    uint8_t counter = 0;
    uint8_t curr_bit = 0;
    uint8_t i;
    int data[5];
    data[0] = 0;
    data[1] = 0;
    data[2] = 0;
    data[3] = 0;
    data[4] = 0;
    *humidity = 0;
    *temp = 0;

    //pull pin down for 18ms
    pinMode(gpio_pin, OUTPUT);
    digitalWrite(gpio_pin, LOW);
    delay(18);

    //now we can read the data
    pinMode(gpio_pin, INPUT);

    for (i = 0; i < MAX_TIMINGS; i++) {
        counter = 0;
        while(digitalRead(gpio_pin) == laststate) {
            counter++;
            delayMicroseconds(1);
            if (counter == 255)
                break;
        }
        laststate = digitalRead(gpio_pin);
        if (counter == 255)
            break;
        //ignore first 3 changes
        if ((i >= 4) && (i % 2 == 0)) {
            data[curr_bit/8] <<= 1;
            if (counter > 16)
                data[curr_bit/8] |= 1;
            curr_bit++;
        }
    }
    //verify data
    if ( (curr_bit >= 40) && 
            (data[4] == ((data[0]+data[1]+data[2]+data[3]) & 0xFF))) {
        *humidity = (float)((data[0] << 8) + data[1]) / 10;
        *temp = (float)(((data[2] & 0x7F)  << 8) + data[3]) / 10;
        return true;
    }
    else {
        *humidity = 0;
        *temp = 0;
        return false;
    }
}
