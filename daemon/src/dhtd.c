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

    //placeholder values, need to properly set this up
    long int curr_time;
    int i;
    int num_sense = argc - 1;
    float humidity;
    float temperature;
    //because there aren't more than 40 pins
    char log_name[30];
    FILE* logs[40];
    int gpio_pin[40];
    //set up pins and log files
    for (i=0; i < num_sense; i++) {
        gpio_pin[i] = atoi(argv[i+1]);
        snprintf(log_name, 30, "dhtd%d.log", i);
        logs[i] = fopen(log_name, "a");
    }

    while(1) {
        curr_time = (long int)time(NULL);
        for (i = 0; i < num_sense; i++) {
            //try 20 times
            int num_tries = 20;
            while (num_tries > 0) {
                if (read_dht_data(gpio_pin[i], &humidity, &temperature)) {
                    fprintf(logs[i], "%d,%3.3f,%3.3f\n", 
                              curr_time, humidity, temperature);
                    fflush(logs[i]);
                    break;
                }
                num_tries--;
            }
        }
        sleep(60);
    }
    for (i=0; i < num_sense; i++) {
        fclose(logs[i]);
    }
    exit(EXIT_SUCCESS);
}
