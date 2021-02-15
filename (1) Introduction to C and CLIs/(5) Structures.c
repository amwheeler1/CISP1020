#include <stdio.h>

//========================================================================================================================

// Structures exist in C as they do in C++ but require different syntax
struct MyStruct {           // Structures require a struct declaration, followed by a structure name
    string name;            // Data contained in the structure goes between the brackets
    double salary;
} optionalInitialization;   // Optionally, a structure can be initialized at the end of the structure declaration; this
                            // structure is global in scope

//========================================================================================================================

int printUser (struct MyStruct newUser);

int main () {
    struct MyStruct testUser;
    
    // Member data of a structure is accessed using a dot between the structure and the data member
    testUser.name = "Test_Name";
    testUser.salary = 48652.61;
    printUser (testUser);
    
    // The initialization at the end of the structure declaration is accessed the same way as any structure
    optionalInitialization.name = "Jimmy";
    optionalInitialization.salary = 436.78;
    printUser (optinalInitialization);
    
    return 0;
}

//========================================================================================================================

// To use a structure in a function header, it must not only have the structure name and local variable used
// to access the data passed in, but also the keyword "struct" before the structure name
void printUser (struct MyUser newUser) {
    // Member data of the structure is accessed in a function the same way it is accessed in main using a dot
    printf("\nUser: %s \nSalary: %.2fl", newUser.string, newUser.salary);
}
