/**
 * @file signal_segfault.c
 * @brief Starts GDB when SIGSEGV is sent to the process
 * @author Joel Schellinger
 * Compile Instructions: gcc -g -o signal_segfault signal_segfault.c
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

// Signal handler to launch GDB and pause execution
void handle_signal() {
    char pid[16];
    sprintf(pid, "%d", getpid());

    // Notify the user
    printf("Caught SIGSEGV. Launching GDB.\n");

    // Use absolute binary path and force symbol loading
    // Maybe later see if there's a way to get the current loaded symbols
    // and get to the line before the segfault...
    if(execl("/usr/bin/gdb", "gdb", "./signal_segfault", (char *)NULL) == -1){
        // If execl fails, exit the program
        perror("execl failed");
        exit(EXIT_FAILURE);
    }
}

int main(void) {
    signal(SIGSEGV, handle_signal);

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}
