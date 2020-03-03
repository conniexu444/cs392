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

int main() {
    int integer = 10;
    printf("%d", integer);
    int* points_to_integer = &integer;
    *points_to_integer = 12;
    printf("%d",integer);
    return 0;
}
