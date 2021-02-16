// This is just a bare-basic explanation for how stacks work. For a program that applies this
// information better, see the Week 3, Part B Group Project
// https://github.com/amwheeler1/CISP1020/tree/main/(98)%20Group%20Projects/Week%203/PartB


#include <stdio.h>

#define MAX_STACK_SIZE 5

typedef struct {
	int stackData [MAX_STACK_SIZE];
	int top;
}Stack;

int push (Stack* destination, int newValue);
int pop  (Stack* sourceStack, int* popValue);

int main () {
	// Stacks are last-in, first-out (LIFO) data structures where data is always read from and sent
	// to the top of the stack; sending and receiving data is done using the push and pop operation
	// respectively

	Stack myStack;

	// Push 5 onto the stack if it isn't full
	push (&myStack, 5);

	int poppedVal;
	// Pop the value at the top of the stack off
	pop (&myStack, &poppedVal);

	return 0;
}

int push (Stack* destination, int newValue) {
	// If the top index of the stack is maxed out, do not push
	if (destination->top = MAX_STACK_SIZE)
		return 0;

	// Push value onto the stack
	else {
		destination->stackData[destination->top] = newValue;
		++(destination->top);
		return 1;
	}
}


int pop (Stack* sourceStack, int* popValue) {
	// If the top index of the stack is bottomed out, do not pop
	if (sourceStack->top < 0)
		return 0;

	// Decrement the index top points to
	else {
		--(sourceStack->top);
	}
	// The data within the stack doesn't actually need to modified as it is changed when a value is
	// pushed onto the stack; only the top index of the stack needs to be decremented
}
