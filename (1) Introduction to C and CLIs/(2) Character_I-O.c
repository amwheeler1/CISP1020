#include <stdio.h>

// C has special functions that allow for just a single character to be read in from stdin or written to stdout

//========================================================================================================================
// getchar()
// getchar will get any character (including whitespace) from stdin and use it as the return value of the function; it is
//     important to note that the char is technically returned as an integer
// Official Syntax: int getchar (void);
//     void: Takes no parameters
//     Returns: The character read in as an integer

int main () {
    char myChar;
    myChar = getchar();
    
    return 0;
}

//========================================================================================================================
// putchar()
// putchar will write any single character to stdout
// Official Syntax: int putchar (int character);
//     character: The character to be written to stdout, as either an integer or char
//     Returns: Either the character written to stdout or EOF if writing was unsuccessful

int main () {
    char myChar = 'a', sentChar;
    
    sentChar = putChar(myChar);
    
    return 0;
}

// A note on the return value of putchar:
//     An int is sized as a single byte (8 bits) while EOF is sized 4 bytes (32 bits); if EOF were to be returned, then
//     it would not be wise to store it in a char, as the data type would not have enough space to accomidate it
