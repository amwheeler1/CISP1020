/* File: exampleStart.c 
   Author: amwheeler1
   Description: Contains function definitions for program
*/
#include <stdio.h>
#include "example.h"

/* readData: reads data into array of Employee structures from stdin
 * Parameters
 *    a the array
 * Returns: number of elements read in
 */
int readData( employee_t e[] ) {
   int count = 0;
   while( count < ARRAY_LENGTH && 
      scanf( "%s%lf", e[count].name, &e[count].salary ) != EOF ) {
      count++;
   }
   return count;
}

/* printData prints array of Employee structures to stdout in a formatted
 *    table
 * Parameters
 *    e array of Employee structures
 *    n number of valid elements in array
 * Returns nothing
 */
void printData( employee_t e[], int n ) {
   int i;
 
   // print table heading
   printf("Name                      Salary\n");
   printf("---------------------------------\n");
   for( i = 0; i < n; i++ ) {
      printf("%-20s  $%10.2lf\n", e[i].name, e[i].salary );
   }
}
