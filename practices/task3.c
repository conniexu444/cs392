#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/**
 * Constance Xu
 * I pledge my honor that I have abided by the Stevens Honor System.
*/
int cs392_file_insert(char * path, int index, char * str){

	/* Please write down your code here
	 *
	 * You can use whatever API you want to use
	 * You can allocate whatever memory you want 
	 * Please do error handling checks 
	 * 
	 * Please write down your pledge of honor system as comment 
	 *
	 * */

	//read all the data and then copy the prefix
	FILE* fp;
	int size;
	fp = fopen(path,"r+");
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	char* ptr = malloc(size);
	fseek(fp,0,SEEK_SET);
	fread(ptr, 1, size, fp);
	fclose(fp);
	fp = fopen(path, "w");
	fwrite(ptr, 1, index, fp);
	fwrite(str, 1, strlen(str), fp);
	fwrite(ptr+index, 1, size-index, fp);
	fclose(fp);
	return 0;
}


int main(int argc, char ** argv){

	cs392_file_insert("cs392_task3_tmp.txt", 10, "@cs392 data inserted@");

	return 0;
}


