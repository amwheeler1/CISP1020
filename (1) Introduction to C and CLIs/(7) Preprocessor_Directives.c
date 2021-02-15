// Preprocessor directives aren't actually part of the programming language, but rather are something
// that tells the compiler how to behave

#include <stdio.h>      // Tells the compiler to look in stdio.h for any functions or keywords used in this file


#ifndef LABEL_VALUE     // If [LABEL_VALUE] has not been defined
#ifdef  LABEL_VALUE     // If [LABEL_VALUE] has been defined
#define LABEL_VALUE     // Define [LABEL_VALUE]

// . . .                // Code goes here to be compiled

#endif                  // End of block of conditional code
