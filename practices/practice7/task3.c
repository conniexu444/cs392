/*
Constance Xu
I pledge my honor that I have abided by the Stevens Honor System.
	In the piece of code below, two pipes "fd1[2]" and "fd2[2]" are created between the parent and child process
	The code for the parent process has been implemented. The parent will write an integer to pipe fd1 and read a string from pipe fd2
	
	You need to implement the code for the child. The child will read from fd1 and write to fd2. 
	Specifically, the child will need to first read an integer from fd1, and then write an answer to fd2 based on the value of the integer:
		if the integer is "1", then you need to write "str1" back ("str1" has been defined below)
		if the integer is "2", then you need to write "str2" back ("str2" has been defined below)
		if the integer is "3", then you need to write "str3" back ("str3" has been defined below)
		if the integer is "4", then you need to write "str4" back ("str4" has been defined below)
		if the integer is "5", then you need to write "str5" back ("str5" has been defined below)
		for all other values, you need to write "strunknown" back ("strunknown" has been defined below)
	
	Note: please be careful regarding which end of a pipe is for write, and which end is for read 
	Note: before you operating on the two pipes, please close the end of each pipe that is not used (i.e., the write end of fd1 and the read end of fd2 in the child process)
	
*/


#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 

char *str1 = "Received cmd one";
char *str2 = "Received cmd two";
char *str3 = "Received cmd three";
char *str4 = "Received cmd four";
char *str5 = "Received cmd five";
char *strunknown = "Received unknown cmd";

int main(int argc, char ** argv) 
{ 

	int input; 
	int fd1[2];  
	int fd2[2];  
	pid_t p; 

	if (pipe(fd1)==-1) 
	{ 
		fprintf(stderr, "Cannot create pipe 1"); 
		return 1; 
	} 
	if (pipe(fd2)==-1) 
	{ 
		fprintf(stderr, "Cannot create pipe 2"); 
		return 1; 
	} 

	scanf("%d", &input);

	p = fork(); 

	if (p < 0) { 
		fprintf(stderr, "Cannot fork"); 
		return 1; 
	} 

	// Parent process 
	else if (p > 0) 
	{ 
		char str[256];
		close(fd1[0]);  // Close reading end of first pipe 
		close(fd2[1]); // Close writing end of second pipe 

		// pipe. 
		write(fd1[1], &input, 4); 

		// Wait for child to send a string 
		wait(NULL); 

		// Read string from child, print it and close 
		// reading end.
		//
		memset(str, 0, 256); 
		read(fd2[0], str, 256);


		switch(input){
			case 1: 
				if(strcmp(str1, str) == 0)
					printf("==== Result: passed\n");
				else
					printf("==== Result: failed\n");
				break;

			case 2: 
				if(strcmp(str2, str) == 0)
					printf("==== Result: passed\n");
				else
					printf("==== Result: failed\n");
				break;

			case 3: 
				if(strcmp(str3, str) == 0)
					printf("==== Result: passed\n");
				else
					printf("==== Result: failed\n");
				break;

			case 4: 
				if(strcmp(str4, str) == 0)
                                        printf("==== Result: passed\n");
                                else
                                        printf("==== Result: failed\n");
				break;

			case 5: 
				if(strcmp(str5, str) == 0)
                                        printf("==== Result: passed\n");
                                else
                                        printf("==== Result: failed\n");
				break;
			default:
				if(strcmp(strunknown, str) == 0)
                                        printf("==== Result: passed\n");
                                else
                                        printf("==== Result: failed\n");
				break;

		}

		close(fd1[1]); 
		close(fd2[0]); 
	} 

	// child process
	// Please implement your code here 
	else{ 
		int x;
		int xnew;
		close(fd2[0]);
		close(fd1[1]);

		xnew = read(fd1[0], &x, sizeof(int)); //read in

		if (x == 1) {
			xnew = write(fd2[1], str1, 17);
		} else if (x == 2) {
			xnew = write(fd2[1], str2, 17);
		} else if (x == 3) {
			xnew = write(fd2[1], str3, 19);
		} else if (x == 4) {
			xnew = write(fd2[1], str4, 18);
		} else if (x == 5) {
			xnew = write(fd2[1], str5, 18);
		} else {
			xnew = write(fd2[1], strunknown, 21);
		}

		//some code is missing here

		exit(0); 
	} 
} 
