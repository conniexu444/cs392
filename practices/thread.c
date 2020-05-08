/* Constance Xu
 * I pledge my honor that I have abided by the Stevens Honor System.
 * thread.c
 * */

#include <stdio.h>
#include <pthread.h>

int counter = 0; //declare a global variable counter with initial value of 0.

/**
 * Start two child threads with pthread_create().
 * 
 * */
void* run_thread (void* noarg) { //this code is given from JXu
	int i = 0;
	for (i = 0; i < 100000; i++) {
		counter++;
	}
	pthread_exit(NULL);
	return NULL;
}

int main() {
	pthread_t thread1;
    pthread_t thread2;
	pthread_create(&thread1, NULL, run_thread, NULL);
	pthread_create(&thread2, NULL, run_thread, NULL);
	pthread_join(thread1, NULL); //use pthread_join() to wait for the two threads to finish
	pthread_join(thread2, NULL);
	printf("The final counter is %d\n", counter);
    
	return 0;
}
