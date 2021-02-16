#include <stdio.h>

int recBinSearch (char key, char set [], int bottom, int top);

int main () {
    // Recursive binary searches follow the same general algorithm as iterative binary
    // searches, but utilize repeated (recursive) function calls instead of a repeating
    // loop
    
    // For a recursive binary search to work, the function call needs the key, the set
    // being searched, and the current bottom and top element
    
    char searchFor = 'W';       //<- Change this value to change the key
    char dataSet [] = {'A', 'D', 'F', 'G', 'K', 'N', 'Q', 'R', 'U', 'W', 'Z'};  // The data set
    int highestIndex = 10;      // The highest index found within dataSet
    int indexAt = recBinSearch (searchFor, dataSet, 0, highestIndex);   // Initial call of binary search
    
    if (indexAt == -1)
        printf ("\nThe key '%c' could not be found within the data set.\n\n", searchFor);
    else
        printf ("\nThe key '%c' was found at element '%d'.\n\n", searchFor, indexAt);
        
    return 0;
}

// Perform a recursive binary search on the data set
// Return either the index the data is found at or -1 if the data was not found
int recBinSearch (char key, char set [], int bottom, int top) {
    int mid = (top + bottom) / 2;
    
    // Recursive binary searches take advantage of how values can be returned retroactively through
    // function calls; think of every function call as a point on a line, where the oldest function
    // call is on the left and the newest is on the right, the return value of each function call is
    // dependent on the return value of the function to the right of it, which allows functions to be
    // daisy-chained together
    
    // Determine how the algorithm should progress based on the relation between the key and
    // the mid element of set
    if (key == set[mid])    // If the key is found
        return mid;             // Return the element within set it is found at
    else if (bottom > top)  // If bottom is larger than top
        return -1;              // Return -1 as the value being searched for cannot be found
    else if (key < set[mid]) {  // If the key is smaller than the value within the mid element of set
        top = mid-1;                // Set top equal to mid-1
        return (recBinSearch (key, set, bottom, top));  // Recursively call the function to continue the search
    }
    else {                      // If the key is larger than the value within the mid element of set
        bottom = mid+1;             // Set bottom equal to mid+1
        return (recBinSearch (key, set, bottom, top));  // Recursively call the function to continue the search
    }
    
    // An important thing to note about recursive binary searches versus iterative binary searches is that even
    // though, on paper, they look to have the same efficiency in terms of the number of steps they take to
    // complete, computationally an iterative binary search is going to be the better option as each function
    // call for a recursive search requires space to be allocated for local variables, which takes time and space
    // in memory to complete
}
