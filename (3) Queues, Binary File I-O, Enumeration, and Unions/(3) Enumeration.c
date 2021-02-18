#include <stdio.h>

// Enumeration is used to assign numerical values to user-defined keywords that can be used in a program

// The enumerated values of the keywords specified in the declaration start at 0 and increment up; in this case, f
// would equal 0 and t would equal 1
typedef enum {
    f, t
} boolean_t;

// Enumerated values can start anywhere; here jan equals 1, feb equals 2, mar equals 3, etc...
typedef enum {
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
} months_t;


int main () {
    // Using an enumerated value is as simple as creating a variable of the same type and assigning it one of its
    // enumerations
    boolean_t errFlag;
    errFlag = t;

    printf("\nFlag set to: %d", errFlag);

    months_t curMonth;
    curMonth = aug;

    printf("\nThe current month is %d\n\n", curMonth);

    // The purpose of enumerations is to make programming easier by simply assigning a numeric value to some keyword

    return 0;
}
