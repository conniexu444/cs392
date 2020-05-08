/**
 * Constance Xu
 * I pledge my honor that I have abided by the Stevens Honor System.
 * 
 * The “cs392_signal.c” should define handlers 
 * for the SIGINT and SIGTSTP signals and define 
 * a function to register those handlers. The 
 * “cs392_signal.h” should provide a prototype 
 * for that registration function.
You need to use the “sigaction” interface to set up 
the handlers.
You are free to design the handlers.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include "cs392_signal.h"
/**
 * Checks to make sure a signal is received.
 */
static void handler(int sig, siginfo_t *siginfo, void *context) {
    if (sig == SIGINT) {
        printf("\nSIGINT received.\n");
    } else if (sig == SIGTSTP) {
        printf("\nSIGTSTP received.\n");
    }
}

/**
 * This registers the handlers for SIGINT and SIGTSTP.
*/
void reg_handler() {
    struct sigaction act;
    memset(&act, '\0', sizeof(act));
    act.sa_sigaction = &handler;
    act.sa_flags = SA_SIGINFO;

    if (sigaction(SIGINT, &act, NULL) < 0) {
        perror("Error: Sigaction.");
        exit(1);
    }

    if (sigaction(SIGTSTP, &act, NULL) < 0) {
        perror("Error: Sigaction.");
        exit(1);
    }
}