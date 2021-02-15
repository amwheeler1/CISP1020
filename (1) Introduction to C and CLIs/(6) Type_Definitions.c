#include <stdio.h>

//========================================================================================================================

// The typedef keyword allows for the creation of what is essentially an alias for data tpes

typedef unsigned char byte;     // The type "byte" is now associated as an unsigned character (8 bits)

typedef struct {                // The type "Employee" is now associated with a structure containing an integer called
    int age;                    // "age" and a double called "salary"
    double salary;
} Employee;

typedef int* intPtr;            // A pointer to an integer can now be specified using intPtr

//========================================================================================================================

void initEmployee (Employee* newHire);  // Function prototype for passing a pointer to an Employee for modification

//========================================================================================================================

int main () {
    byte checksum = 0xF5;
    
    Employee e;
    initEmployee (&e);  // C has no way of passing by reference; if a variable needs to be modified within a function, it
                        // must be passed in as a pointer; this is first done by passing in the address of the variable
    // at the initial function call, then treating the variable as a pointer in the actual function
    
    return 0;
}

//========================================================================================================================

void initEmployee (Empolyee* newHire) {
    newHire->age = 36;              // Here, the -> operator acts a combination of the dot operator for specifying member
    newHire->salary = 78000.00;     // data and the dereference operator for dereferencing a pointer; in this case, it is
                                    // the same as *(newHire).age [THIS IS NOT VALID SYNTAX! IT MUST BE newHire->age]
}
