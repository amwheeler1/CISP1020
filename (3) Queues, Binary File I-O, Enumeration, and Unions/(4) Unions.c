#include <stdio.h>

// Unions are used to allow for the creation of data types that can be accessed as different types

// A union's true size is dependent on the size of its largest data member
typedef union {
    char myChar;    // Size: 1 byte
    int myInt;      // Size: 2 or 4 bytes (implementation dependent)
    double myDub;   // Size: 8 bytes
} data_t;
// In this instance, assuming the size of the types are correct, the size of the data_t union would be 8 bytes as that
// is the size of the largest data member (double myDub)

// Structures can be used in conjunction with unions to create more complex data types
typedef union {
    struct {
        unsigned char b1;
        unsigned char b2;
        unsigned char b3;
        unsigned char b4;
    } bytes;
    unsigned int dword;
} doubleword_t;



int main () {
    // Declaring and using a union is very similar to how a structure is used
    data_t myData;
    myData.myInt  = 6562;       // Union data members accessed the same as structure members
    myData.myDub  = 100.001;    // Data in myData (int 6562) is replaced (double 100.001)
    myData.myChar = 'c';        // Data in myData (double 100.001) is replaced (char 'c')

    doubleword_t checksumData;
    // Accessing data memembers of structures in unions requries using multiple dot operators
    // Set data to be stored in checksumData to be 0x4449434b*
    checksumData.bytes.b1 = 0x44;
    checksumData.bytes.b2 = 0x49;
    checksumData.bytes.b3 = 0x43;
    checksumData.bytes.b4 = 0x4b;

    checksumData.dword = 0x9b6baa18;    // Data in checksumData (0x4449434b) is replaced (0x9b6baa18)

    // * An important thing to note is that the endianess of the system might affect whether or not setting the
    // individual bytes as done above is equivalent to setting the whole data as 0x4449434b

    return 0;
}
