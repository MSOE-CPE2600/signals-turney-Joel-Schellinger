/**
 * @file recv_signal.c
 * @brief Receives SIGUSR and process data sent along with it
 * @author Joel Schellinger
 */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stddef.h>

void handler(int sig, siginfo_t *info, void *context);

int main() {
    pid_t pid = getpid();
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;
    printf("PID: %d\n", pid);
    sigaction(SIGUSR1, &sa, NULL);

    while(1) {
        pause();
    }
}


void handler(int sig, siginfo_t *info, void *context) {
    if (sig == SIGUSR1) {
        printf("Received %d from %d\n", info->si_value.sival_int, info->si_pid);
    }
}