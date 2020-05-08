/**
 * Constance Xu
 * I pledge my honor that I have abided by the Stevens Honor System.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cs392_log.h"

/**
 * The “cs392_log.c” should define a function which logs 
 * each command (and the options) to “cs392_shell.log” 
 * in an appending mode. If “cs392_shell.log” does
 *  not exist, this function should create that file 
 * in the current working directory. The “cs392_log.h” 
 * should provide a prototype for that function.
 */
void log_command(char * input) {
    FILE * fp = fopen("cs392_shell.log", "a"); //create or open file
   
    if (fp == NULL) { //Error checking
        printf("Error: Cannot create or open log file.\n");
        exit(1);
    }

    fwrite(input, strlen(input), 1, fp); //write to file
    fwrite("\n", 1, 1, fp);
    fclose(fp); //close file
}