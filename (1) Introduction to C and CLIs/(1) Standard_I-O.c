// Inclusion directives for C headers are almost exactly the same as C++:

#include <stdio.h>  // stdio (standard IO) is the basic header required by C to send and receive information
// on the terminal; it defines, among other things, stdin (standard in) and stdout (standard out)

//========================================================================================================================
// printf()
#include <stdio.h>

int main () {
    // Information can be sent to the terminal using the printf() command
    printf("\nHello, World!\n");

    // printf has the ability to print both C-string literals as well as variables and non-constants to standard out
    int age;
    age = 23;
    printf("\nYour age is: %d\n", age);
    // The syntax of printf() is very similar to a function call (because it is a function)
    // Official Syntax: int printf(const char* format, ...);
    //     const char* format: A C-string; variables can be delimted using % followed by a character to indicate data type
    //     ...: The variables indicated in [const char* format] in the order they appear
    //     Returns: int, total number of characters written to stdout

    return 0;
}

// Output:
//  \nHello, World!\n
//  \nYour age is: 23\n


int main () {
    // printf can be used to print multiple variables to the terminal within the same function call
    char name [] = {'T', 'E', 'R', 'R', 'Y'};
    int age = 50;
    
    printf("\nName: %s \nAge: %d \n", name, age);
}

// Output:
//  \nName: TERRY
//  \nAge: 50\n


int main () {
    // printf has the capability of left- or right-justifying variables in text and setting the precision for a field
    
    // By default, the text will be left-justified, but it can be right-justified by setting the field width
    // Right-justification is set by placing an integer after the % delimiter of a variable; this integer sets how many
    //     characters the variable has the capability of taking up in stdout
    char name [] = {'B', 'O', 'B'};
    printf("\nName: %10s", name);
    
    // Decimal precision for floats and long floats (doubles) is done similarly to setting right-justification, except a
    //     decimal point precedes the integer value; the integer value will specify how many places AFTER the decimal point
    //     will be printed to stdout
    float piFive = 3.1415;
    printf("\nThree Digits of PI: %.2f", piFive);
    printf("\n Five Digits of PI: %.4f", piFive);
    printf("\nSeven Digits of PI: %.6f", piFive);
    
    // These two formatting options can be used in conjunction with each other to create complex formatting rules
    printf("\n%10.3f", piFive);
}

// Output:
//   \nName:       BOB
//   \nThree Digits of PI: 3.14
//   \n Five Digits of PI: 3.1415
//   \nSeven Digits of PI: 3.141500
//   \n     3.141

//========================================================================================================================
// scanf()
#include <stdio.h>

int main () {
    // prinft has a counterpart called scanf that reads data in from stdin
    // For scanf to work, a data type and a destination must be specified
    // Official Syntax: int scanf (const char* format, ...);
    //     const char* format: The data types to be read
    //     ...: The destination variables that correspond to the data types in [const char* format]
    //     Returns: int, the number of variables successfully filled by the read from stdin
    int myInt = 0;
    char myString [10];
    double myDouble = 0.0;
    scanf("%d%s%lf", &myInt, myString, &myDouble);
    // A caveat of scanf is that the variable to which the data is being stored must be specified as the address of the
    //     variable instead of its label
    // This is also a good example of how arrays do not need the address of (&) operator beacause they are essentially a
    //     series of address; myString is a C-string, which is an array of characters, and does not need & in scanf
}
