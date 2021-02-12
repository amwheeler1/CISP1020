#include <stdio.h>  // Definitions for file I/O are found in stdio.h

//========================================================================================================================
// FILE*
// To interact with a file, a file pointer must be declared and tied to the file

int main() {
  FILE* readF;  // Declares a file pointer
  int myInt = 0;  // Integer to be used later
  
  readF = fopen("myFile.txt", "r"); // Assigns the file pointer to the file myFile.txt in read mode
  
  fscanf(readF, "%d", &myInt); // Read data from the file into a variable
  
  fclose(readF);  // readF no longer points to myFile.txt
}


//========================================================================================================================
// fprintf() and fscanf()
// File interaction uses functions that are named very similarly to those used for std I/O interaction
// Official Syntax: int fprintf (FILE* stream, const char* format, ...);
//                  int fscanf (FILE* stream, const char* format, ...);
// fprintf writes data to a file or stream using the same syntax as printf
// fscanf reads data from a file or stream using the same syntax as scanf

int main () {
  FILE* readInfo, * writeInfo;
  int dataStuff = 0, fileAccess = 152;
  
  readInfo = fopen("myData.dat", "r");
  fscanf(readInfo, "%d", dataStuff);
  
  writeInfo = fopen("access.log", "w");
  fprintf(writeInfo, "Times Accessed: %d", fileAccess);
  
  fclose(readInfo);
  fclose(writeInfo);
}
