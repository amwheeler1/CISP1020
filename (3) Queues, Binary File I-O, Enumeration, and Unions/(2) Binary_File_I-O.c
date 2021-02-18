#include <stdio.h>

typedef struct employee {
	char* firstName,* lastName;
	int age;
	double salary;
} Employee;

int main () {
	// Binary files can be read and modified in C using a similar syntax to normal file I/O. The difference comes
        // with how the data is written out and read in.
	
	// First a file pointer must be declared
	FILE* binWrite;

	// Then fopen is used like when reading a normal file to open the binary file. The difference comes with using
	// the "wb" (write binary) fopen mode instead of just "w" (write).
	binWrite = fopen("data.bin", "wb");

	Employee eList [100];

    eList[0].firstName = "Bob";
    eList[0].lastName  = "Smitty";
    eList[0].age = 50;
    eList[0].salary = 63422.96;

    eList[1].firstName = "Jimmy";
    eList[1].lastName  = "BillyBob";
    eList[1].age = 36;
    eList[1].salary = 46589.24;

	// Accessing a file as binary is typically faster than using an encoding scheme, but the downfall comes with
	// having to know exactly how the file is structured.
	
	// fwrite is the function used to write data to binary files
	// fwrite (pointerToDataArray, sizeOfOutData, quantityOfOutData, FILE*)
	for (int i = 0; i < 100; i++)
		fwrite (&eList[i], sizeof(Employee), 1, binWrite);

	// As always, it is a very good idea to close a file, binary or not, when done accessing it.
	fclose (binWrite);

	FILE* binRead;
	Employee systemUsers [100];

	// To open a file in binary, the fopen function is used, but instead of "wb", "rb" (read binary)
	// is used instead
	binRead = fopen("data.bin", "rb");

    // If an error has occurred in the file stream, ferror() can be used to determine this
    // Syntax: ferror(FILE*)
    if (ferror(binRead)) {
        printf("\nAn error has occurred with the input file stream.\n\n");
        return 1;
    }

	// fread uses a very similar syntax to fwrite, except an input file stream is used instead of an
	// output file stream	
	for (int i = 0; i < 100; i++) {
		fread(&systemUsers[i], sizeof(Employee), 1, binRead);

        // feof() can be used to determine if the end of the file stream has been reached for FILE*
        // Syntax: feof(FILE*)
        if (feof(binRead))
            break;

        // ftell() can be used to determine which byte in the file the pointer is currently at
        // Syntax: ftell(FILE*)
        printf("\nCurrent Byte: %ld", ftell(binRead));
    }
    printf("\n\n");

    for (int i = 0; i < 2; i++) {
        printf("\nEmployee Name : %s %s", systemUsers[i].firstName, systemUsers[i].lastName);
        printf("\nEmployee  Age : %d"   , systemUsers[i].age);
        printf("\nCurrent Salary: $%.2lf"  , systemUsers[i].salary);
    }

    // fseek() can be used to set the byte position of a file pointer
    // Syntax: fseek(FILE*, offset, start@Byte)
    fseek(binRead, 0, 0);   // Puts FILE* at beginning of file
    printf("\n\nCurrent Byte Position is %ld\n", ftell(binRead));
    // fseek also has a number of constants associated with it that specify unique positions
    // SEEK_SET indicates the beginning of the file
    // SEEK_CUR indicates the current position of FILE*
    // SEEK_END indicates the end of the file
    fseek(binRead, 0, SEEK_END);
    printf("\nCurrent Byte Position is %ld\n\n", ftell(binRead));


	// An important thing to note about reading and writing in binary is that structures are not
	// the same size as the sum of their parts. Data types must be read in in the same manner they
	// were written out (i.e. a structure must be read in as a structure, an integer must be read in
	// as an integer, etc.).

	fclose(binRead);
}
