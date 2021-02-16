# makefile for queue program

# Compiler
CC=gcc

# Compiler flags
CFLAGS=-c -Wall

queue: queue.o main.o
	$(CC) main.o queue.o -o queue

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) queue.c -o queue.o

main.o: mainQueue.c queue.h
	$(CC) $(CFLAGS) mainQueue.c -o main.o

clean:
	rm -rd *.gch *.o queue
