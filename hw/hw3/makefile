# Eric Altenburg
# I pledge my honor that I have abided by the Stevens Honor System.

C = gcc
OBJS = cs392_exec.o cs392_log.o cs392_signal.o cs392_shell.o

cs392_shell: $(OBJS)
	$(C) -o cs392_shell $(OBJS)

cs392_shell.o: cs392_shell.c
	$(C) -o cs392_shell.o -c cs392_shell.c

cs392_exec.o: cs392_exec.c
	$(C) -o cs392_exec.o -c cs392_exec.c

cs392_log.o: cs392_log.c
	$(C) -o cs392_log.o -c cs392_log.c

cs392_signal.o: cs392_signal.c
	$(C) -o cs392_signal.o -c cs392_signal.c

clean:
	$ rm *.o cs392_shell cs392_shell.log

