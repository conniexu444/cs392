
/* 
Constance Xu
I pledge my honor that I have abided by the Stevens Honor System.
 * This program implements a signal-handling program:
 * Functionality Description:

	This program will register a signal handler for sigint (SIGINT), using the sigaction interface (with the sa_sigaction field in the second argument to sigaction). When a sigint signal is received (by pressing ctrl + c), the handler will increase a "global variable" called "sigcount" by 1
	
	After the program starts, it will run an infinite loop, where each iteration will print a message and then sleep for 1 second. 

	You can press ctrl + c to trigger the sigint signal. After you do it for 3 times, the the loop will be broken and the program will terminate. 


 * Testing points:
 You are required to find out 10 errors in the following piece of code. You need to find at least 8 errors to get full score. 

 
HINT:

 Note that all the errors are marked with hints

 Please find syntax and grammar errors that prevent the building
 	Pay attention to compiler warnings (if all syntax and grammar errors are fixed, you will not see any compiler warnings)

 Please find the errors that mismatch the above functionality descriptions

 Please find the missing of error checking 

 Please find other errors based on the hints (you may need to change the locations of some code)


 To test this case, run "make -s task1"

 	After fixing all the errors, the program will run an infinite loop and after you press ctrl + c for 3 times, the program will terminate.
 
	In case you do not find all the errors and you cannot kill your program by ctrl + c, try ctrl + d and then run "pkill task1"

 *
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h> //Hint 1: something missing? SIGNAL.H IS MISSING
#include <stdlib.h>

//Hint 3: is this variable at the correct location? Check the description to understand its scope
int sigcount; //needs to be a global variable 


//Hint 2: does this handler have a correct prototype? You can google the requirement of the sigaction interface
static void hdl (int sig, siginfo_t *siginfo, void *context){ //add void *context to it

	sigcount++;

	printf ("Received Signal, PID: %ld, UID: %ld\n", (long)siginfo->si_pid, (long)siginfo->si_uid);

}
 
int main (int argc, char **argv){
	
	struct sigaction act;
 
	//Hint 4: Missing any initialization?
	memset(&act, '\0', sizeof(act));
	//Some code here? 


	/* Use the sa_sigaction field */
	act.sa_sigaction = hdl;
 
	/* Setup the flag to tell sigaction() to use the sa_sigaction field */
	//Hint 5: is it setting the correct flag? 
	act.sa_flags = SA_SIGINFO; //change from 0 to SA_SIGINFO


	//Hint 6+7: Are all arguments correctly passed to the following function? 
	//There are two errors related to the first two arguments. 
	//Please check both the above functionality description and the prototype of the "sigaction" interface 
	int sigret = sigaction(SIGINT, &act, NULL); //pass &act to modify the address.
 	
	//Hint 8: missing something after a system level interface? 
	if (sigret < 0) { //missing an error check
		perror("Error: sigaction does not work");
		return 1;
	}
	

	while(1){
		//Hint 9: will this condition check work correctly?
		if(sigcount == 3){ //not just 1 = sign, it is ==
			//Hint 10: any problem in the following format string? Think about types
			printf("You have hit ctrl+c for %d times. Program terminated\n", sigcount); //change %s to %d
			exit(0);	
		}
		printf("Hello, please presse ctrl+c\n");
		sleep(1);
	}
		
	return 0;
}


