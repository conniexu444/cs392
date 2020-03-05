#include<stdio.h>
#include "cs392_printf.h"

int main(int argc, char ** argv){


	//test 1	
	printf("Test 1 Hello CS 392 Assignment 2\n");
	cs392_printf("Test 1 Hello CS 392 Assignment 2\n");

	//test 2
	printf("Test 2 with integer %d\n", 0);
	cs392_printf("Test 2 with integer %d\n", 0);

	//test 3
	printf("Test 3 with hex %d\n", 255);
	cs392_printf("Test 3 with hex %d\n", 255);

	//test 4
	printf("Test 4 with string %s\n", "this is a string");
	cs392_printf("Test 4 with string %s\n", "this is a string");

	//test 5
	printf("Test 5 with char %c\n", 'A');
	cs392_printf("Test 5 with char %c\n", 'A');

	//test 6	
	printf("Test 6 with mixed specifiers %d %c\n", 255, 255);
	cs392_printf("Test 6 with mixed specifiers %d %c\n", 255, 255);

	//test 7
	printf("Test 7 with mixed specifiers %d %s\n", 255, "string after integer");
	cs392_printf("Test 7 with mixed specifiers %d %s\n", 255, "string after integer");

	//test 8
	printf("Test 8 with mixed specifiers %d %c\n", 255, '@');
	cs392_printf("Test 8 with mixed specifiers %d %c\n", 255, '@');

	//test 9
	printf("Test 9 with mixed specifiers %c %s\n", 255, "string after hex");
	cs392_printf("Test 9 with mixed specifiers %c %s\n", 255, "string after hex");

	//test 10
	printf("Test 10 with mixed specifiers %d, %c, %s\n", 255, 'A', "Everything Here");
	cs392_printf("Test 10 with mixed specifiers %d, %c, %s\n", 255,'A', "Everything Here");

	return 0;
}

