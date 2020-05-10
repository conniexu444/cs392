# CS392
## Taken at Stevens Institute of Technology
This course is taught in C and Bash is taught in this course as well. This repository is sorted as the following:
### Practices 
  - [Basic C](practices/practice2.c)
  - [Writing into a specific byte at a file](practices/task3.c)
  - [Creating a dynamic library practice](practices/cs392_sum)
  - [Making a fork process in C](practices/cs392_fork): I don't know how to explain this
### Homework
  - [hw1](hw/hw1): Creating your own printf function in c
  - [hw2](hw/hw2): 
    - [Task 1](hw/hw2/cat.c): Implement a simplified version of the “cat” shell command, which reads all contents from the input file and prints the data to the standard output. 
    - [Task 2](hw/hw2/sort.c): You are given a file with a sequence of unsorted integers. These integers are saved in the format of strings (strings of digits) and each line represents one integer (maximal value 4294967296). After reading those strings, your program needs to transform them into integers (transfer each string into an integer which can be saved in a variable of type “int”), sort those integers, and save them to another file as strings. Each integer string should take one line in the output file. 
-[hw3](hw/hw3):
  -[Created a shell](hw/hw3/cs392_shell.c): Create your own interactive shell that will be able to execute commands.
  -[Created a log](hw/hw3/cs392_log.c): Creates a new file/log that pairs with the interactive shell so you know what commands are being executed and when.
  -[Executed the shell with multiple commands](hw/hw3/cs392_exec.c): Executes the commands given to the interactive shell and uses piping so that multiple commands can be taken in one line. 
  -[Define handlers for the shell](hw/hw3/cs392_signal.c): This defined the handlers such as SIGINT and SIGTSTP for the shell.
### Midterm
- [Reverse a string in place in C](midterm/task1.c): reverse a string in place in C.
- [Sort a string array Using Your Own String Compare](midterm/task2.c): sort a string array without using APIs and create your own version of string compare. 
- [Utilizing a Class Structure](midterm/task3.c): read from a file and use the data structure given to put the appropriate data in the appropriate fields. 
