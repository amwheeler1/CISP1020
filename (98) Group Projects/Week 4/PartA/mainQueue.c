/* File: mainQueue.c
 * Author: amwheeler1
 * Description: uses an array as a circular queue  
 */
#include <stdio.h>
#include "queue.h"
#include "queueItem.h"

int main( int argc, char *argv[] ) {
   Queue queue;
   QueueItem item;
   int response;

   // initialize stack and print
   initQueue( &queue );
   printQueue( queue );

   // print menu to manipulate queue
   printf("1 enqueue an integer on the queue\n" ); 
   printf("2 dequeue an integer off the queue\n" ); 
   printf("3 quit\n" ); 
   scanf("%d", &response );
   while( response != 3 ) {
      switch( response ) {
         // enqueue on queue if it isn't full
         case 1: 
            if ( queue.count < QUEUE_SIZE ) {
               printf("Enter integer to enqueue: " );
               scanf("%d", &item );
               enqueue( &queue, item );
            }
            else {
               printf( "Error. Queue is full.\n" );
            }
            break;
         // dequeue from queeu if it isn't empty
         case 2: 
            if ( !isEmpty( queue ) ) {
               dequeue( &queue, &item );
               printf( "%d dequeued.\n", item );
            }
            else {
               printf( "Error. Queue is empty.\n" );
            }
            break;
         default:
            printf("Invalid option.\n" );
            break; 
      }
      // print the stack then do it all again
      printQueue( queue );
      printf("1 enqueue an integer on the queue\n" ); 
      printf("2 dequeue an integer off the queue\n" ); 
      printf("3 quit\n" ); 
      scanf("%d", &response );
   } 

   return 0;
}
