/* File: exampleStart.c 
   Author: amwheeler1
   Description: Contains function prototypes and structure definitions for employee_t
*/
#ifndef EXAMPLE_H
#define EXAMPLE_H

#define MAX_NAME_LENGTH 21
#define ARRAY_LENGTH 5

typedef struct {
   char name[MAX_NAME_LENGTH];
   double salary;
} employee_t;

int readData( employee_t[] );
void printData( employee_t[], int );

#endif
