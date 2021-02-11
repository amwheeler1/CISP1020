# Compiler
CC=gcc

# Compiler Options
CFLAGS=-c -Wall

all: salary

salary: example.o main.o
	$(CC) main.o example.o -o salary

example: example.h example.c
	$(CC) $(CFLAGS) example.c

main: example.h main.c
	$(CC) $(CFLAGS) main.c

clean:
	rm -rf *.o *.gch salary
