.PHONY: task1 task2 task3 clean

task1:
	@echo "Compiling task 1"
	@gcc -O0 -g -o task1 task1.c -lpthread
	@echo "Running task 1"
	@./task1

task2:
	@echo "Compiling task 2"
	@gcc -O0 -g -o task2_server task2_server.c
	@gcc -O0 -g -o task2_client task2_client.c
	@echo "Running task 2"
	@./task2_server &
	@./task2_client

task3:
	@echo "Compiling task 3"
	@gcc -O0 -g -o task3 task3.c
	@echo "Test case 1"
	@echo 1 | ./task3 
	@echo "Test case 2"
	@echo 2 | ./task3
	@echo "Test case 3"
	@echo 3 | ./task3
	@echo "Test case 4"
	@echo 4 | ./task3
	@echo "Test case 5"
	@echo 5 | ./task3	
	@echo "Test case 6"
	@echo 6 | ./task3	
clean:
	rm task1 task2_client task2_server task3 *.o
