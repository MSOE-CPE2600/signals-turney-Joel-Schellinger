/**
 * @file send_signal.c
 * @brief Sends SIGUSR1 to a pid along with a random integer
 * @author Joel Schellinger
 */

#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <stdio.h>
int main(int argc, char* argv[]) {

    if (argc != 2) {
        errno = EINVAL;
        perror("Error! Invalid amount of arguments");
    }
    union sigval value;
    // Used clock for sending a more time granular seed
    srand(clock()); 
    value.sival_int = rand();
    pid_t pid = atoi(argv[1]);
    sigqueue(pid, SIGUSR1, value);
}