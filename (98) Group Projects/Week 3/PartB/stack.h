/* stack.h
 * Author: amwheeler1
 * Contains function prototypes, Stack structure definitions, and constant value definitions
*/

#ifndef STACK_H
#define STACK_H

#include "stackItem.h"

#define MAX_STACK_SIZE 10
#define EMPTY_INDEX -1 

typedef struct stack {
   StackItem array[MAX_STACK_SIZE];
   int top; // index of top item on stack
} Stack;

void initStack( Stack* );
void push( Stack*, StackItem );
int pop( Stack*, StackItem* );
int isEmpty( Stack );
void printStack( Stack );

#endif
