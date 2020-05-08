/**
 * Constance Xu
 * I pledge my honor that I have abided by the Stevens Honor System.
 * The “cs392_exec.c” should define a function which
 *  forks one/multiple child process(es) to run the 
 * command (or commands concatenated via pipe) from 
 * the user. The “cs392_exec.h” should provide a 
 * prototype for that function.
Hint 1: combine a “fork” and an exec-family function 
Use the parent process to continue 
working as “cs392_shell”
Use exec-family functions in the 
child process to run the received command
When PIPE is used to concatenate two commands, 
create a pipe in the parent process and 
fork two child processes (with each for a separate command). 
In the first child for the first command, close the read end of the pipe, a
nd duplicate the write end to standard out; in the second child for the second command, 
close the write end of the pipe, and duplicate the read end to the standard input. 
You need to fork both child processes in the parent. 
Hint 2: the execlp(), execvp(), and execvpe() functions automatically search shell 
command programs in system directories (for more details, please refer to https://linux.die.net/man/3/execlp). 
Hint 3: use “wait” in the parent to wait for termination of the child process.s
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include "cs392_exec.h"

/*
 *	Given a command, it will execute it. Otherwise, it will quit out.
 */
void run_command(char * input) {
	char ** commands = malloc(256 * sizeof(char*));
	char ** pipesec = malloc(256 * sizeof(char*));

	//Checking to see if one or two commands are given. 
	int i = 0;
	int count = 1;
	int has_pipe = 0;

	while (input[i] != '\0') { //Ensuring that you get to the end of the input
		if (input[i] == ' ') { //If there is another word, then the count will go up.
			count++;
		}
		if (input[i] == '|') { //This checks to see if there is a pipe. 
			has_pipe = 1;
		}
		i++;
	}

	//Create an array 
	for (i = 0; i < count; i++) { 
		commands[i] = malloc(count * sizeof(char));
	}
	if (has_pipe == 1) { //Create a second array if necessary
		pipesec[0] = malloc(count * sizeof(char));
	}

	if (has_pipe == 0){ //If there is only one command
		char * input1 = strtok(input, " ");
		i = 0;
		while (input1 != NULL){ //placing the input in the commands array
			strcpy(commands[i], input1);
			input1 = strtok(NULL, " ");
			i++;
		}
		commands[i] = NULL;

	} else { //If there are two commands
		char * part = strtok(input, "|"); //First command
		char *array[2]; //Second command
		i = 0;
		while(part != NULL) {
			array[i++] = part;
			part = strtok(NULL, "|");
		}
		char * input1 = strtok(array[0], " "); //Grabs the first word in the string
		i = 0;
		while (input1 != NULL) {
			if (strcmp(input1, "") == 0) { 
				continue; 
			}
			strcpy(commands[i], input1); // Put the command in the array at specified index
			input1 = strtok(NULL, " ");
			i++;
		}
		commands[i] = NULL;
		// Remove the initial space
		int len = strlen(array[1]);
		for (i = 0; i < len; i++) {
			array[1][i] = array[1][i+1];
		}

		// Push them onto the second command array
		char * input2 = strtok(array[1], " ");
		i = 0;
		while (input2 != NULL) {
			strcpy(pipesec[i], input2);
			input2 = strtok(NULL, " ");
			i++;
		}

		pipesec[i] = NULL;

	}


	if (has_pipe == 0){
		int pid1;

		if (strncmp(commands[0], "exit", 4) == 0) { //Go to exit
			exit(0); 
		} 
		pid1 = fork();
		if (pid1 < 0) { //Error checking
			printf("Error: Could not properly fork.\n");
			exit(1);
		}
		
		if (pid1 == 0) { //Child
			if (execvp(commands[0], commands) < 0) { // Not a valid command
				printf("Command not found: %s.\n", commands[0]);
				exit(1); // quit with error
			}
		} else { //Parent
			wait(NULL);
		}

	} else{
		int pid, status;
		int fd[2];

		pipe(fd);

		pid = fork();
		
		if (pid < 0) { //Error checking
			printf("Could not fork");
			exit(1);
		}
		if (pid == 0) { //This is the child process.
			dup2(fd[1], 1);	
		 	close(fd[0]); 		
			execvp(commands[0], commands);
		}

		pid = fork();
		if (pid < 0) { //Error checking
			printf("Could not fork");
			exit(1);
		}
		if (pid == 0) { //This is the child process.
			dup2(fd[0], 0);
			close(fd[1]);
			execvp(pipesec[0], pipesec);
		}

		close(fd[0]);
		close(fd[1]);

		int b;
		while ((pid = wait(&status)) != -1)
			b = 0; 
		free(pipesec);
	}
	//free up the memory allocated to the 2D array
	for (int j = 0; j < count; j++) {
		free(commands[j]);
	}
	free(commands);
}