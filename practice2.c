/**
Author:			Constance Xu
Date: 			2/6/2020
Description:	below 

[1] Create an integer variable 

[2] Assign a constant value to that variable (whatever value you want)

[3] Create an integer pointer

[4] Make that pointer point to the integer variable 

[5] Change that integer variable to another constant value by dereferencing the pointer created in [3] (instead of directly changing that integer variable)

[6] Print the integer variable again. 

[7] Please upload your .c file.
**/

#include <stdio.h>

int main(int argc, char ** argv) {
    int integer;
    integer = 10;
    int *points_to_integer;
    points_to_integer = &integer;
    

	unsigned long sum;
	sum = 0;	

	for (int i = 1; i <= 10000000; ++i)
		sum = sum + i;

	printf("The final value is %lu ", sum);

	return 0;
}
