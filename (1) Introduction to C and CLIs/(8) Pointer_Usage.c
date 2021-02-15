#include <stdio.h>

int main () {

//========================================================================================================================
// Pointer Arithmetic
    int a[10];
    int* myPtr = a;     // Since arrays are just memory addresses, pointers can be assigned to them; myPtr = a[0]
    
    myPtr++;            // Increments the address of myPtr by the size of it's type (an integer); now myPtr = a[1]
    myPtr = 10;         // myPtr = a[1] = 10
    
//========================================================================================================================
// Arrays of Pointers
    char* myArray[10];  // Pointers are just another data type, which means that an array can be created that contains
                        // only pointers
    
    return 0;
}
