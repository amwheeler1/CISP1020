#include <stdio.h>

typedef struct employee {
	char firstName [25], lastName [25];
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

	/*
	 * Assume eList has been initialized to a set list of Employees
	*/

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

	// fread uses a very similar syntax to fwrite, except an input file stream is used instead of an
	// output file stream	
	for (int i = 0; i < 100; i++)
		fread(&eList[i], sizeof(Employee), 1, binRead);

	// An important thing to note about reading and writing in binary is that structures are not
	// the same size as the sum of their parts. Data types must be read in in the same manner they
	// were written out (i.e. a structure must be read in as a structure, an integer must be read in
	// as an integer, etc.).

	fclose(binRead);
}
