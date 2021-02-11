/* File: mainStack.c
 * Author: amwheeler1
 * Description: Contains the main function for the stack program
 */
#include <stdio.h>
#include "stack.h"
#include "stackItem.h"

int main( int argc, char *argv[] ) {
   Stack stack;
   StackItem item;
   int response;

   // initialize stack and print
   initStack( &stack );
   printStack( stack );

   // print menu to manipulate stack
   printf("1 push an integer on the stack\n" ); 
   printf("2 pop an integer off the stack\n" ); 
   printf("3 quit\n" ); 
   scanf("%d", &response );
   while( response != 3 ) {
      switch( response ) {
         // push on stack if it isn't full
         case 1: 
            if ( stack.top < MAX_STACK_SIZE-1 ) {
               printf("Enter integer to push: " );
               scanf("%d", &item );
               push( &stack, item );
            }
            else {
               printf( "Error. Stack is full.\n" );
            }
            break;
         // pop from stack if it isn't empty
         case 2: 
            if ( !isEmpty( stack ) ) {
               pop( &stack, &item );
               printf( "%d popped.\n", item );
            }
            else {
               printf( "Error. Stack is empty.\n" );
            }
            break;
         default:
            printf("Invalid option.\n" );
            break; 
      }
      // print the stack then do it all again
      printStack( stack );
      printf("1 push an integer on the stack\n" ); 
      printf("2 pop an integer off the stack\n" ); 
      printf("3 quit\n" ); 
      scanf("%d", &response );
   } 

   return 0;
}
