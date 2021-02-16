#include <stdio.h>

int itBinSearch (char key, char* set, int setSize);

int main () {
    // Binary searches work by constantly dividing the search set by 2 until either the needed element
    // is found OR it is determined that the information being searched for is not present in the set
    
    // An algorithm is considered to be iterative if it iterates through an array using a loop; in the
    // case of an iterative binary search, there is a loop that continually divides the size of the set
    // being searched by 2
    
    // A binary search algorithm (or any search algorithm) needs a set of data to sift through to find
    // the needed information; a unique thing about binary searches is that the data MUST BE SORTED
    // before being searched
    char mySet [] = {'A', 'C', 'F', 'G', 'M', 'P', 'R', 'S', 'T', 'W', 'Z'};   // mySet is sorted alphabetically
    
    char searchFor = 'G';   // <- Change this  value to any character for testing
    int atIndex = itBinSearch (searchFor, mySet, 10);    // 10 is the largest index number within the set of 11 elements
    
    // Determine what to print based on the return value in atIndex
    if (atIndex == -1)  // -1: Indicates that the information could not be found
        printf("\nThe key '%c' could not be found in the set.\n\n", searchFor);
    else    // Any value that is not -1 indicates the index at which the searched value is found
        printf("\nThe key '%c' was found at index %d.\n\n", searchFor, atIndex);
    
    return 0;
}

// itBinSearch (Iterative Binary Search)
// Performs an iterative binary search
// Returns either the index at which the data can be found OR -1 if the data was not in the set
int itBinSearch (char key, char* set, int setSize) {
    // An iterative binary search must keep track of an upper and lower bounds for the data being search by
    // maintaining a top and bottom index
    int top, bottom, mid;
    bottom = 0;         // bottom is always initialized to 0 at the start
    top = setSize;      // top is always initialized to the size of the data set at the start
    
    // The iterative search is in a loop with the loop condition checking if top and bottom overlap; if top were
    // to become less than bottom (or bottom to become greater than top, it's the same thing), then the data
    // being searched for was not found in the set, which causes the search loop to terminate
    while (top >= bottom) {
        //  The middle index (the one being checked) is always calculated at the start of the loop based on 
        // the average of top and bottom
        mid = (top + bottom) / 2;
        
        // After mid has been calculated, a series of comparisons are made to determine how the algorithm
        // should progress
        if (key == set[mid])        // Key has been found within the set at the current index equal to mid
            return mid;
        else if (key < set[mid])    // Key's value is less than the mid element within the set
            top = mid-1;                // Set top equal to mid-1
        else                        // Key's value is greater than the mid element within the set
            bottom = mid+1;             // Set bottom equal to mid+1
            
        // IMPORTANT: The reason for top or bottom being set to mid +/- 1 instead of just mid is because the value
        // at the mid element has already been taken into account during the comparisions, so it can be excluded
        // from all future comparisons to save compute time
            
    }
    
    // In the event that the data being searched for was not in the current set, -1 is returned to indicate this
    return -1;
}
