CC = gcc
main: main.c fun.c 
	$(CC) $? -o $@.o

clean:
	rm *.o
wish:
	@echo You are awesome