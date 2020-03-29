/**
 * Constance Xu
 * I pledge my honor that I have abided by the Stevens Honor System.
 * task 1: implement a simplified version of the "cat" shell command. 
 * Reads all the contents from the input and prints the data to the output
*/
#include <stdlib.h>
#include <stdio.h>

/**
 * main function
*/
int main(int argc, char** argv){
    if (argc != 2){ //error checking
        printf("Error! Not enough arguments");
        exit(1);
    }
    //open the file
    FILE *fp = fopen(argv[1],"r"); 
    if (fp == NULL){ //error checking
        printf("Error! Can't open file");
        exit(1);
    }

    fseek(fp, 0L, SEEK_END);
    int file_size = ftell(fp); //gets the size of the file in bytes
    char *c = malloc(file_size);
    rewind(fp); //puts the input stream back to the beginning

    if (c == NULL){ //error checking
        printf("Error! Can't allocate memory");
        exit(1);
    }

    fread(c,1,file_size, fp); //reads each

    fwrite(c,1,file_size,stdout); //writes it in

    free(c); //frees up the aollocated memory

    fclose(fp); //closes the file
    return 0;
}
