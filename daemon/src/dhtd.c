#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "dht22.h"

int main() {
    pid_t pid, sid;

    if (geteuid()) {
        //must be root to write to necessary files
        //in the future we should find a way to run the daemon as non-root
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
    int num_sense = 1;
    int gpio_pin[1];
    gpio_pin[0] = 7;
    float humidity[1];
    float temperature[1];
    int i;
    while(1) {
        curr_time = (long int)time(NULL);
        for (i = 0; i < num_sense; i++) {
            if (read_dht_data(gpio_pin[i], &humidity[i], &temperature[i]))
                fprintf(log, "%d, %d, %3.3f, %3.3f\n", 
                              curr_time, i, humidity[i], temperature[i]);
        }
        fflush(log);
        sleep(60);
    }
    fclose(log);
    exit(EXIT_SUCCESS);
}
