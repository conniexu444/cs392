.PHONY: task1 task2 task3 clean

task1:
	@echo "Compiling task 1"
	@gcc -O0 -g -o task1 task1.c
	@echo "Running task 1"
	@./task1

task2:
	@echo "Compiling task 2"
	@gcc -O0 -g -o task2 task2.c
	@echo "Running task 2"
	@./task2

task3:
	@echo "Compiling task 3"
	gcc -O0 -g -o task3 task3.c -lpthread
	@echo "Running task 3"
	./task3

clean:
	rm task1 task2 task3 *.o
