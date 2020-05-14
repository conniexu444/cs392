/** Constance Xu
 * I pledge my honor that I have abided by the Stevens Honor System. 
 * In this task, you are required to implement a two-directional inter-process communication with two pipes. 

	In the "main" function, we have defined two pipes --- "p2c_pipe" for sending data from the parent to child and "c2p_piep" for sending data from the child to the parent.
	
	In the "main" function, we have prepared the parent and child process. You have to finish the code for both of them. 

	For the parent process, you need to send the string carried by the "msg" array to the child process through "p2c_pipe"; Then you need to read data back from the child process via "c2p_pipe".
	 Noe that you have to save the data from the child to an array called "buffer" (which is defined in the "main" function).


	For the child process, you need to read data from the parent process through "p2c_pipe", REVERSE the string, 
	and then send the REVERSED string back to the child via "c2p_pipe".

	In both the parent and the child process, you will have to close the unneeded ends of the two pipes.

	You can assume the data is a string and it always has less than 50 bytes.

**/

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>

char msg[] = "Second task in CS392 final exam";

char revmsg[] = "maxe lanif 293SC ni ksat dnoceS";

int main() {

    //pipe to pass data from parent to child
    int p2c_pipe[2];

    //pipe to pass data from child to parent
    int c2p_pipe[2];

    char buffer[50];

    if(pipe(p2c_pipe) || pipe(c2p_pipe)) {
        perror("Cannot create pipes\n");
        exit(1);
    }

    int pid = fork();
    if (pid == -1) {
        perror("Cannot fork child\n");
        exit(1);
    }

    if (pid == 0) {
	/*This is the child process*/
	
	/* ========== Your code part 1 ends here ========== 
		
		You need to read a string from the p2c_pipe, reverse the string you received, and then send the reversed string back through c2p_pipe;
		You can assume the data has less than 50 bytes;
		Do not forget to close the ends that you do not need;
	*/
	close(c2p_pipe[0]); //close reading end of c2p
	close(p2c_pipe[1]); //close writing end of p2c

	int integer = read(p2c_pipe[0], buffer, 50);
	if (integer < 0){
		perror("p2c pipe error");
		return -1;
	}

	
	int index = strlen(msg) - 1;
	for (int i = 0; i < strlen(msg); i++) { //reverse the string
		buffer[index] = msg[i];
		index--;
	}
	 int integer2 = write(c2p_pipe[1], buffer, 50);
	 if (integer2 < 0) {
		 perror("c2p pipe error");
		 return -1;
	 }

	

	/* ========== Your code part 1 ends here ========== */

   }else {
	/* This is the parent process */

	
	/* ========== Your code part 2 begins here ========== 
	
		You need to send a string indicated by the "msg" buffer (defined above) to the child process through the p2c_piep, and then read the string returned back through the c2p_pipe. Make sure you save the data to the array called "buffer", which is also defined above. 
	*/

	
	close(c2p_pipe[1]); //close  end of child to parent?
	close(p2c_pipe[0]); //close  end of parent to child?

	int integer;
	integer = write(p2c_pipe[1], msg, strlen(msg));
	if (integer < 0) {
		perror("error: could not write to p2c pipe");
		return -1;
	}
	integer = read(c2p_pipe[0], buffer, strlen(msg));
	if (integer < 0) {
		perror("error: could not read c2p pipe");
		return -1;
	}
	close(c2p_pipe[0]);
	close(p2c_pipe[1]);


	/* ========== Your code part 2 ends here ========== */


	if(strcmp(buffer, revmsg) == 0)
		printf("============ Congrats! You passed the second assignment\n");
	else
		printf("============ Sorry! You failed the second assignment; The expected message is \"%s\", but the message the parent received is \"%s\"\n", revmsg, buffer);


    }
    return 0;
}
