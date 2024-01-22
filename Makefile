CC = gcc
main: main.c fun.c counter.c
	$(CC) $? -o $@.o

clean:
	rm *.o
wish:
	@echo You are awesome