CC=gcc

CFLAGS=-c -Wall

all: stack

stack: mainStack stackFile
	$(CC) main.o stack.o -o stack

mainStack: mainStack.c stack.h stackItem.h
	$(CC) $(CFLAGS) mainStack.c -o main.o

stackFile: stack.c stack.h stackItem.h
	$(CC) $(CFLAGS) stack.c -o stack.o

clean:
	rm -rf *.o *.gch stack
