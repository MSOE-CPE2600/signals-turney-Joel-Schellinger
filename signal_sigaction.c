/**
 * @file signal_sigaction.c
 * @brief Demonstrates the use of sigaction to handle SIGUSR1 signals and print sender PID. * 
 * @author Joel Schellinger
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigusr1_handler(int sig, siginfo_t *info, void *context) {
    if (sig == SIGUSR1) {
        printf("Received SIGUSR1 from process with PID: %d\n", info->si_pid);
    }
}

int main() {
    struct sigaction sa;

    // Clear the sigaction structure
    sa.sa_flags = SA_SIGINFO;   // Use SA_SIGINFO to get additional signal information
    sa.sa_sigaction = sigusr1_handler; // Set the signal handler

    // Register the signal handler for SIGUSR1
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction failed");
        exit(EXIT_FAILURE);
    }

    printf("Process ID: %d\n", getpid());
    printf("Waiting for SIGUSR1...\n");

    // Infinite loop to keep the program running
    while (1) {
        pause(); // Wait for signals
    }

    return 0;
}
