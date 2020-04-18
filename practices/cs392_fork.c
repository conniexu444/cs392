/**
 * Constance Xu
 * I pledge my honor that I have abided by the Stevens Honor System.
 * This program creates your own fork in C using a PID. 
*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	pid_t pid;
	pid = fork();
    
	if (pid < 0) { //Error checking
		perror("Could not fork!");
		return -1;
	} else if (pid == 0) { //This is the child process.
		printf("Hello from child\n");
        return 1;
	} else { //This is the parent process.
		printf("This is the PID of the child: %d\n", pid);
		while (1) {
			sleep(5);
			printf("Hello from parent\n");
		}
	}

	return 1;
}