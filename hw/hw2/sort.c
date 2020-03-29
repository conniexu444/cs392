/**
 * Constance Xu
 * I pledge my honor that I have abided by the Stevens Honor System. 
 * Task 2: sort numbers from input file and put them in an output file
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sort.h"
/**
 * Sort will sort the integers using insertion sort.
*/
void sort(int numbers_count, int *nums){
    int outer = 1;
    while (outer < numbers_count){
        int current = nums[outer];
        int inner = outer-1;
        while (nums[inner] > current && inner >= 0){
            nums[inner + 1] = nums[inner];
            inner--;
        }
        int index = inner + 1;
        nums[index] = current;
        outer++; //next iteration
    }
}
/**
 * This is the main driver of the program.
*/
int main(int argc, char ** argv){

    if (argc != 3){ //error checking
        printf("Error:Not enough arguments");
        exit(1);
    }
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL){ //error checking
        printf("Cannot open file!");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    const int fs = ftell(fp); //gets the size in bytes of the file
    fseek(fp, 0, SEEK_SET);
    char *c = malloc(fs); //allocate memory
    if (c == NULL){ //error checking
        printf("Cannot allocate memory");
        exit(1);
    }

    fread(c,1,fs,fp); //reads what is in the file
    fclose(fp); //closes the file

    int index = 0;
    int num_count = 0;
    char *curr = malloc(10);//this is the maximal integer as stated by JXu
    int curr_num_count = 0;
    int *nums = malloc(fs);

    while (index < fs){ //conversion to an integer array
        char current = c[index];
        if (current == '\n' && curr_num_count > 0){
            num_count++; 
            nums[num_count-1] = atoi(curr);
            curr_num_count = 0;
            curr = malloc(10);
        } else if (current != '\n') {
            curr[curr_num_count] = current;
            curr_num_count++; //increase the pointer
        }
        index++; //next iteration
    }


    free(c); //freeing the memory
    free(curr);

    sort(num_count, nums); //sort the array

    FILE * fp_out = fopen(argv[2], "w");
    if (fp_out == NULL) { //error checking
        printf("Error! No file");
        exit(1);
    }
    
    static char number_list[] = "0123456789";
    char* stringA;
    static char buffer[50];
    for (int i = 0; i < num_count; i++) { //writes the numbers to the file
        int current = nums[i];
        if (current != 0) {
            stringA = &buffer[49];
            *stringA = '\n';
             while (current != 0) {
                *--stringA = number_list[current % 10];
                current = current / 10;
            }
            fputs(stringA, fp_out);
        } else { //if it is a 0
            fputc('0', fp_out);
            fputc('\n', fp_out);
        }
    }

    
    free(nums); //freeing the memory
    fclose(fp_out); //close new created file

    return 0;
}