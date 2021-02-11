# Makefile for searches 

# Compiler:
CC=gcc

#  compiler options
CFLAGS=-c -Wall

all: search

search: mainSearch.o binarySearch.o
	$(CC) mainSearch.c binarySearch.c -o search
    
main: mainSearch.c binarySearch.h
	$(CC) $(CFLAGS) mainSearch.c
     
binarySearch: binarySearch.c binarySearch.h
	$(CC) $(CFLAGS) binarySearch.c

clean:
	rm -rf *.o search *.gch
