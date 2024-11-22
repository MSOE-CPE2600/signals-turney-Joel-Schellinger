/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then quits
 * @author Joel Schellinger
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void handle_signal() {
    printf("\nReceived a signal\n");
    kill(getpid(), SIGKILL);
}

int main() {

    // Register for the signal
    signal(SIGINT , handle_signal);
    signal(SIGQUIT , handle_signal);
    signal(SIGTSTP , handle_signal);
    // Wait until a signal is received
    while(1) {
        printf("Sleeping\n");
        sleep(1);
    }

    return 0;
}