/* File: bookSort.c
 * Author: amwheeler1
 * Description: Use an array of pointers to read in book data from an input file
 */
#include <stdio.h>
#include <string.h>

#define MAX_CHARS 81
#define MAX_BOOKS 10 

typedef struct  {
   char title[MAX_CHARS];
   char author[MAX_CHARS];
   char publisher[MAX_CHARS];
   int edition;
} book_t;

// ADD CODE HERE: prototypes for the following functions:
// readBooks that has 1 parameter: the array of book_t books
//   it reads book data from a file called books.in and
//   returns the number of books it read in
int readBooks(book_t books[]);

// initSortingArray has 3 parameters: the array of book_t books,
//    the bookPtrs array and the number of valid elements in 
//    the array of book_t books. This function initializes
//    the bookPtrs array so that each element points to 
//    an element of teh books array. Returns nothing
void initSortingArray(book_t books[], book_t* bookPtrs[], int bookQuant);

// printBooks has two parameters: the bookPtrs array and
//    the number of valid pointers in it. Prints out a table
//    of book info
void printBooks (book_t* bookPtrs[], int bookQuant);

// sortBooks has two parameters: the bookPtrs array and the
//    number of valid elements in it. It sorts pointers by
//    book title. Returns nothing.
void sortBooks(book_t* bookPtrs[], int bookQuant);

// swap has two parameters: pointers to elements of bookPtrs
//    array. It swaps their actual values. Returns nothing
void swap (book_t** bookA, book_t** bookB);
// Takes in the pointer to a pointer (a pointer to an address essentially)

int main() {
   book_t books[MAX_BOOKS];  
   book_t* bookPtrs[MAX_BOOKS];
   int numBooks;
  
   // ADD ONE LINE TO CALL readBooks 
   numBooks = readBooks(books); 
   
   // ADD ONE LINE TO CALL initSortingArray
   initSortingArray(books, bookPtrs, numBooks);
   
   // ADD ONE LINE TO CALL sortBooks
   sortBooks(bookPtrs, numBooks);
   
   // ADD ONE LINE TO CALL printBooks (so, they should print
   // sorted by title since you need to pass the bookPtrs
   // array)
   printBooks(bookPtrs, numBooks);
   
   return 0;
}

/* readBooks: fills book_t array with at most MAX_BOOKS
 *    book info from file books.in
 * Parameters: a array of book structure
 * Returns: number of books
 */
int readBooks(book_t books[]) {
   FILE* in;
   int i = 0;
   char junk;
   in = fopen( "books.in", "r" );
   if ( in != NULL ) {
      while ( i < MAX_BOOKS &&
      fgets( books[i].title, MAX_CHARS, in ) != NULL ) {
         fgets( books[i].author, MAX_CHARS, in );
         fgets( books[i].publisher, MAX_CHARS, in );
         fscanf(in, "%d", &books[i].edition );
         fscanf(in, "%c", &junk );
         i++;
      }
   }
   return i;
}

/* initSortingArray: sets all pointers in array to point to 
 *    books array
 * Parameters: 
 *    a books array
 *    t pointers to elements in books array
 *    n number of books in array a
 * Postcondition: t contains n valid pointers to n elements in a
 * Returns: nothing
 */
void initSortingArray(book_t books [], book_t* bookPtrs[], int bookQuant) {
	// Set bookPtrs equal to address of books entries
	int i = 0;
	for (i = 0; i < bookQuant; i++)
		bookPtrs[i] = &books[i];
} 

/* printBooks: prints book info to stdout
 * Parameters:
 *    aPtr: array of pointers to book_t structures
 *    n: number of valid element in aPtr
 * Returns: nothing
 */
void printBooks(book_t* bookPtrs[], int bookQuant) {
	int i = 0;
	// Print book information to terminal
	for (i = 0; i < bookQuant; i++) {
		printf("%s  %s  %s  %d\n", bookPtrs[i]->title, bookPtrs[i]->author, bookPtrs[i]->publisher, bookPtrs[i]->edition);
	}
   
}

/* sortBooks: uses a selection sort to sort book info 
 * Parameters:
 *    aPtr: array of pointers to book_t structures
 *    n: number of valid elements in aPtr
 * Returns: nothing
 */
void sortBooks(book_t* bookPtrs[], int bookQuant) {
	int minIndex = 0;
	int i = 0, j = 0;

	// Sort book entries using selection sort
	for (i = 0; i < bookQuant; i++) {
		minIndex = i;
		for (j = i+1; j < bookQuant; j++) {
			// Determine if swap needs to occur
			if (strcmp(bookPtrs[j]->title, bookPtrs[minIndex]->title) < 0)
				minIndex = j;
		}
		swap(&bookPtrs[minIndex], &bookPtrs[i]);
	}
}

/* swap: swaps pointers to book_t array elements
 * Parameters:
 *    b1, b2: references to pointers to book_t elements
 * Postcondition: actual parameter pointer values swapped
 * Returns: nothing
 */
void swap(book_t** bookA, book_t** bookB) {
	// Initialize book_t temp
	book_t* temp;

	// Set temp equal to whatever bookA points to
	temp = *bookA;

	// Set what bookA points to to what bookB points to
	*bookA = *bookB;

	// Set what bookB points to equal to temp
	*bookB = temp;
}
