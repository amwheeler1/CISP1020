// Entire lines of text can be sent to and from stdin and stdout

#include <stdio.h>

//========================================================================================================================
// puts()
// puts will write an entire line, including whitespace, to stdout
// Official Syntax: int puts (const char* str);
//      const char* str: A C-string to be written to stdout, appended by a newline ('\n'); is not delimited by whitespace
//      Returns: Non-negative number upon successful write, EOF if writing results in an error
int main () {
    char myString [100];
    scanf("%s", myString);
    
    puts(myString);
    
    return 0;
}

// Input:
//      > Hello!
//
// Output:
//      Hello!

//========================================================================================================================
// fgets()
// Gets an entire line of text from a file OR stdin, up to and including a newline character
// Official Syntax: char* fgets (char* str, int num, FILE* stream);
//     char* str: The C-string to hold the information brought in from stdin
//     int num: The quantity of characters to be read in from a file OR stdin
//     FILE* stream: Pointer to a file, alternatively, can be stdin
//     Returns: The value read into char* str if successful, NULL* if a read error occurs

#include <string.h> // Needed to use the strlen() function

int main () {
     char myString [15];
     
     fgets(myString, 15, stdin);
     myString[strlen(myString)-1] = '\0';   // Sets the last character of the C-string to NULL, otherwise a newline
                                            // character ('\n') would be printed to stdout as fgets will get whitespace
     puts(myString);
     
     return 0;
}

// Input:
//      > I Wanna Be a Cowboy!
//
// Output:
//     I Wanna Be a Cowboy!\n

//========================================================================================================================
// fputs()
// fputs is intended to act in a simlar manner to puts, but is instead intended to be used with files
// Official Syntax: int fputs (const char* str, FILE* stream);
//     const char* str: The C-string to be written out
//     FILE* stream: A pointer to a file stream, can also be substituted with stdout
//     Returns: A non-negative number is write is successful, EOF if an error has occurred

int main () {
    char myString [15];
    
     fgets(myString, 15, stdin);
     myString[strlen(myString)-1] = '\0';
    
    fputs(myString, stdout);    // In this instance, fputs works exactly the same as puts, writing a C-string to stdout
    
    return 0;
}

// Input:
//     > Potato Salad
//
// Output:
//     Potato Salad
