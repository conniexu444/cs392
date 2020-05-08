/**
 * Constance Xu
 * I pledge my honor that I have abided by the Stevens Honor System.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cs392_exec.h"
#include "cs392_log.h"
#include "cs392_signal.h"

/**
 * This is the main function that will create an interactive shell
*/
int main(){
    
     while (1) {
        reg_handler();
        printf("cs392_shell$: "); //initial statement that needs to be printed
        char inputstr[64];

        fgets(inputstr, sizeof(inputstr), stdin); //Sets the buffer and gets the input

        inputstr[strcspn(inputstr, "\n")] = 0; //remove trailing newline character

        if (inputstr[0] != 0){ //if it is not an empty string
            log_command(inputstr); //saves the command
        }

        if (strcmp(inputstr, "exit") == 0){ //exit call
            exit(0);
        }

        run_command(inputstr); //this will go to exec.c
    }
    return 0;

}