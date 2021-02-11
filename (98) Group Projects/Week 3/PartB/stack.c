/* File: stack.c
 * Author: amwheeler1
 * Description: Contains the function definitions for the stack program
 */
#include <stdio.h>
#include "stack.h"
#include "stackItem.h"


/* initStack: initializes stack by setting top index to -1
 * Parameter s pointer to the stack
 * Returns nothing 
 */ 
void initStack( Stack *s ) { 
	// Set top variable to EMPTY_INDEX = -1
	s->top = EMPTY_INDEX;
}

/* push: pushes an item on the stack if it isn't full
 * Parameters:
 *    s pointer to the stack
 *    i the item to push
 * Returns nothing
 */
void push( Stack *s, StackItem i ){
	// Push value onto stack if stack is not full
	(s->top)++;
	s->array[s->top] = i;
}

/* pop: pops an item off the stack if it isn't empty
 * Parameters 
 *    s pointer to the stack
 *    i the item to be returned, a pointer
 * Postcondition: i will have the item popped if the stack wasn't empty
 * Returns true if an item was popped 
 */
int pop( Stack *s, StackItem* i ) {
	// Pop value off of stack if stack is not empty
	*i = s->array[s->top];
	(s->top)--;
	return *i;
}

/* isEmpty: returns true if stack is empty
 * Parameter s the stack
 * Returns: true if stack is empty
 */
int isEmpty( Stack s ) {
	// If stack's top index is -1, stack is empty
	if (s.top == EMPTY_INDEX)
		return 1;

	// Otherwise it has values in it
	else
		return 0;
}

/* printStack: prints the stack
 * Parameter s the stack
 * Returns nothing
 */
void printStack( Stack s ) {
   int i;
   printf("STACK\n------\n");
   for( i = s.top; i >= 0; i-- ) {
      printf ("| %4d |\n", s.array[i] );
      printf("------\n");
   }
   if ( s.top <= EMPTY_INDEX) printf("------\n");
}

