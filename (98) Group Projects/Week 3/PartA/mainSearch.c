/* File: searchMain.c
 * Author: amwheeler1
 * Description: Main of search algorithms programs
 */
#include <stdio.h>
#include "binarySearch.h"

int main() {
   // the sorted array
   double a[ARRAY_LENGTH] = { 0.1, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8,
                              9.9, 10.1, 11.1, 12.2, 13.3, 14.4, 15.5, 
                              16.6, 17.7, 18.8, 19.9, 20.1, 21.1, 22.2, 
                              23.3, 24.4 };
   double key; // the number to look for
   int index; // the index where found or -1 if not found
   int comparisons; // number comparisons to find key 
   int iterations;  // number iterations or recursive calls to find key
   int b, m, t; // bottom, middle, top of array in recursive search
   int i;

   // print array so we can see it
   printf( "ARRAY VALUES: " );
   for( i = 0; i < ARRAY_LENGTH; i++ ) printf("%lf  ", a[i] );
   printf("\n");

   // get a number to look for from the user
   printf("Enter a number to find: " );
   scanf("%lf", &key );
   printf( "Key is: %lf\n", key );
   comparisons = 0;
   iterations = 0;
   index = linearSearch( a, ARRAY_LENGTH, key, &iterations, &comparisons );
   printf( "Linear: %d iterations, %d comparisons\n", 
      iterations, comparisons) ; 
   if ( index != NOT_FOUND ) {
      printf("\tKey %4.2lf found %4.2lf at index %d.\n", key, a[index], index );
   }
   else {
      printf("\tKey %lf not found.\n", key );
   }
   comparisons = 0;
   iterations = 0;
   index = iterativeBSearch( a, ARRAY_LENGTH, key, &iterations, &comparisons );
   printf( "Iterative binary: %d iterations, %d comparisons\n", 
      iterations, comparisons) ; 
   if ( index != NOT_FOUND ) {
      printf("\tKey %4.2lf found %4.2lf at index %d.\n", 
         key, a[index], index );
   }
   else {
      printf("\tKey %lf not found.\n", key );
   }

   comparisons = 0;
   iterations = 0;
   b = 0;
   m = ARRAY_LENGTH/2;
   t = ARRAY_LENGTH-1;
   index = recursiveBSearch( a, b, m, t, key, &iterations, &comparisons );
   printf( "Recursive binary: %d recursive calls, %d comparisons\n", 
			iterations, comparisons) ; 
   if ( index != NOT_FOUND ) {
      printf("\tKey %4.2lf found %4.2lf at index %d.\n", 
         key, a[index], index ) ; 
   }
   else {
      printf("\tKey %lf not found.\n", key );
   }

   return 0;
 
}

