/* binarySearch.h
 * Author: amwheeler1
 * Contains function prototypes and constant definitions for the program
*/

#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#define ARRAY_LENGTH 25 
#define NOT_FOUND -1

int linearSearch( double[], int, double, int*, int* );
int iterativeBSearch( double[], int, double, int*, int* );
int recursiveBSearch( double[], int, int, int, double, int*, int* );

#endif
