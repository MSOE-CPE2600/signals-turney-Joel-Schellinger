/**
 * @file signal_alarm.c
 * @brief Sets an alarm for 5 seconds and notifies user
 * @author Joel Schellinger
 */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
void handle_alarm();

int main() {
    signal(SIGALRM, handle_alarm); // Handler for SIGALRM
    alarm(5); // Set alarm

    printf("Set an alarm for 5 seconds.\n");
    while(1) { // Wait for alarm
        pause();
    } 
    return 0;

}

void handle_alarm() {
    // Notify user that alarm signal was received
    printf("Program received SIGALRM\n"); 
    exit(0);
}
