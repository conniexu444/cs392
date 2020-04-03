#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct cs392_struct{
	int course;
	int student;
	char  semester;
	char string[24];
};


void cs392_read_datastructure(struct cs392_struct * cs_ds, char * fpath){

	/* Please write down your code here  */
	FILE* fp;
	fp = fopen(fpath,"r+");
	if (fp == NULL) { //error check
		printf("Error: cannot read file");
		exit(1);
	}
	int course;
	int student;
	char semester;
	char string[24];
	
	fscanf(fp, "%d %d %c %s", &course, &student, &semester, string);
	
	cs_ds->course = course;
	cs_ds->student = student;
	cs_ds->semester = semester;
	strcpy(cs_ds->string, string);
	
	// while (fgets(str, sizeof(str), fp)){
	// 	int str_length = strlen(str);
	// 	int counter = 0;
	// 	char temp[24];
	// 	while (counter != 3){
	// 		int temp2 = str[counter];
	// 		printf("%d", temp2);
	// 		counter++;
	// 	}
		// strcpy(temp, "");
		// while (str[counter] != " "){
		// 	strcat(temp, str[counter]);
		// }
		// printf("%s", temp);

	fclose(fp);
	return;
}


int main(int argc, char ** argv){


	int index = 0; 

	struct cs392_struct test, res; 

	int course[5] = {123, 345, 456, 789, 868};
	int student[5] = {987,675, 234, 432, 656};
	char semester[5] = {'A', 'B', 'C', 'D', 'E'};
	char string[5][24]= {"This", "Is", "The", "Mid", "Term"};


	for(index = 0; index < 5; index++){
		
		FILE * fp = fopen("/tmp/ds", "w");

		fprintf(fp, "%d %d %c %s",  course[index], student[index], semester[index],string[index]);
		
		fclose(fp);

		memset(&test, 0, sizeof(struct cs392_struct));
		memset(&res, 0, sizeof(struct cs392_struct));
		
		res.course = course[index];
		res.student = student[index]; 
		res.semester = semester[index];
		strcpy(res.string, string[index]);
		
		cs392_read_datastructure(&test, "/tmp/ds");		

		printf("	Test case %d:\n", index);

		if ( memcmp(&res, &test, sizeof(struct cs392_struct)) == 0)
			printf("	=== Result: PASSED === \n\n");
		else
			printf("	=== Result: FAILED === \n\n");	
	
	}


	return 0;
}


