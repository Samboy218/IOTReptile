#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//#include "dht22.h"

int main() {
    pid_t pid, sid;

    pid = fork();
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }
    umask(0);

    //we should open a log here//
    FILE* log = fopen("/var/log/dhtLog.log", "a");

    sid = setsid();
    if (sid < 0) {
        exit(EXIT_FAILURE);
    }
    if (chdir("/") < 0) {
        exit(EXIT_FAILURE);
    }
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    while(1) {
        //main loop//
    }
    exit(EXIT_SUCCESS);
}
