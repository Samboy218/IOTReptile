#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "dht22.h"

int main(int argc, char** argv) {
    pid_t pid, sid;

    if (geteuid()) {
        //must be root to write to necessary files
        //in the future we should find a way to run the daemon as non-root
        exit(EXIT_FAILURE);
    }
    if (argc < 2 || argc > 41) {
        //gotta pass the pin numbers as parameters
        exit(EXIT_FAILURE);
    }
    pid = fork();
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }
    if (pid > 0) {
        FILE* pid_f = fopen("/var/run/dhtd.pid", "w");
        fprintf(pid_f, "%d", (int)pid);
        fclose(pid_f);
        exit(EXIT_SUCCESS);
    }
    umask(0);


    sid = setsid();
    if (sid < 0) {
        exit(EXIT_FAILURE);
    }
    if (chdir("/var/log/") < 0) {
        exit(EXIT_FAILURE);
    }
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    if (wiringPiSetup() == -1) {
        exit(EXIT_FAILURE);
    }

    //we should open a log here//
    FILE* log = fopen("dhtd.log", "a");
    //int log = open("dhtLog.log", O_APPEND);

    //placeholder values, need to properly set this up
    long int curr_time;
    int i;
    int num_sense = argc - 1;
    float humidity;
    float temperature;
    //because there aren't more than 40 pins
    int gpio_pin[40];
    for (i=0; i < num_sense; i++) {
        gpio_pin[i] = atoi(argv[i+1]);
    }

    while(1) {
        curr_time = (long int)time(NULL);
        for (i = 0; i < num_sense; i++) {
            //try 20 times
            int num_tries = 20;
            while (num_tries > 0) {
                if (read_dht_data(gpio_pin[i], &humidity, &temperature)) {
                    fprintf(log, "%d, %d, %3.3f, %3.3f\n", 
                              curr_time, i, humidity, temperature);
                    break;
                }
                num_tries--;
            }
        }
        fflush(log);
        sleep(60);
    }
    fclose(log);
    exit(EXIT_SUCCESS);
}
