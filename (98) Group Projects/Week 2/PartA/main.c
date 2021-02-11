/* File: exampleStart.c 
   Author: amwheeler1
   Description: Contains the main function of the program
*/
#include <stdio.h>
#include "example.h"

int main()
{
   employee_t e[ARRAY_LENGTH];
   int count;

   count = readData( e );   
   printData( e, count );
   
   return( 0 );
}
