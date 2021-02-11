/* File: binarySearch.c
 * Author: amwheeler1
 * Description: Linear, binary iterative, and binary recursive search algorithm function definitions
 */
#include <stdio.h>
#include <math.h>
#include "binarySearch.h"

/* linearSearch linearly searches for key and returns index where found or -1
 * Parameters
 *    a array to search
 *    n number elements in array
 *    k key to find
 *    iPtr number of iterations made
 *    cPtr number of comparisons made
 * Precondition: *iPtr and cPtr have been initialized to 0
 * Postcondition: *iPtr contain number of iterations for the search
 *    and cPtr number of comparisons
 * Returns: index where key found or -1
 */
int linearSearch( double a[], int n, double k, int *iPtr, int *cPtr ) {

	while (*iPtr < n) {
		if (++(*cPtr) && (a[*iPtr] == k)) {
			++(*iPtr);
			return (*iPtr-1);
		}
		++(*iPtr);
	}

   return NOT_FOUND; 
} 

/* iterativeBSearch uses an iterative binary search to find key and 
 *    returns index where found or -1
 * Parameters
 *    a array to search
 *    n number elements in array
 *    k key to find
 *    iPtr pointer to number of iterations made
 *    cPtr pointer to number of comparisons made
 * Precondition: * iPtr and *cPtr has been initialized to 0
 * Postcondition: *cPtr contain number of comparisons for the search
 *    and iPtr the number of iterations
 * Returns: index where key found or -1
 */
int iterativeBSearch( double a[], int n, double k, int *iPtr, int *cPtr ) {

	// Variable declaration and initialization
	int b, t, m;
	b = 0;
	t = n-1;

	// Loop through array until value is found or bottom is greater than top
	while (b <= t) {
		++(*iPtr);
		m = (b+t)/2;
		if (++(*cPtr) && k == a[m])
			return m;
		else if (++(*cPtr) && k < a[m])
			t = m-1;
		else
			b = m+1;
	}

   return NOT_FOUND;
}

/* recursiveBSearch uses a recursive binary search to find key and 
 *    returns index where found or -1
 * Parameters
 *    a array to search
 *    b bottom index of subarray to search
 *    m middle index of subarray
 *    t top index of subarray 
 *    k key to find
 *    iPtr pointer to number of recursive calls made
 *    cPtr pointer to number of comparisons made
 * Precondition: * iPtr and *cPtr has been initialized to 0
 * Postcondition: *cPtr contain number of comparisons for the search
 *    and iPtr the number of recursive calls
 * Returns: index where key found or -1
 */
int recursiveBSearch( double a[], int b, int m, int t,  double k, int *iPtr, int *cPtr )  {

	// Calculate middle value
	m = (t+b)/2;

	++(*iPtr);

	// Determine how the search should branch based on value of k
	
	// If key has been found
	if (++(*cPtr) && k == a[m]) {
		return m;
	}

	// If bottom is greater than top
	else if (++(*cPtr) && b > t) {
		return NOT_FOUND;
	}

	// If key is greater than element
	else if (++(*cPtr) && k > a[m]) {
		b = m+1;
		return (recursiveBSearch(a, b, m, t, k, iPtr, cPtr));
	}

	// If key is less than element
	else {
		t = m-1;
		return (recursiveBSearch(a, b, m, t, k, iPtr, cPtr));
	}

	return NOT_FOUND;

}
