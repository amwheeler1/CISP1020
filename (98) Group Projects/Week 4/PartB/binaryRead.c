/* File: binaryRead.c
 * Author: amwheeler1
 * Description: Reads in binary data structures using fread()
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 30

typedef struct employee {
   char firstName[MAX_NAME_LENGTH];
   char lastName[MAX_NAME_LENGTH];
   int age;
   double salary;
} Employee;

int main() {
   Employee e[100];
   FILE* in;
   int i = 0;

   // Attempt to open file
   in = fopen("binary.out", "rb");
	
   // If file open has failed
   if (in == NULL) printf("Error opening file.\n" );
  
   // if FILE in != NULL
   else { // if in != NULL 

    // Read in Employee information
	for (i = 0; i < 100; i++) {
		fread(&e[i], sizeof(Employee), 1, in);
		if (feof(in))
			break;
	} 

	// Close file either after EOF is reached or i = 99
	fclose( in );
   } 

   // print data read from binary file in array
   for( i--; i >=0; i-- ) { 
      printf("%s %s %d %lf\n", e[i].firstName, e[i].lastName, 
         e[i].age, e[i].salary ); 
   }

   return 0;
}
