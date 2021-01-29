// File: ioHandle.cpp
// Author: amwheeler1
// Date: 210120-1115 (January 20, 2021 @ 11:15am)
// Contains function code for I/O handling and character formatting.

#include "ioHandle.h" // ioHandle.h contains function definitions and include directives


// printWelcome
// Returns: Nothing
// Parameters: None
// Prints a basic welcome message
void printWelcome () {
	cout << "\nWelcome to the Appalachian Trail (AT)"
	     << "\nInformation System.";
}


// printExit
// Returns: Nothing
// Parameters: None
// Prints a basic exit message to the user, typically before program termination
void printExit() {
	cout << "\nThank you for using the AT Data Information"
	     << "\nSystem."
	     << "\n\n";
}


// getFileInfo
// Returns: bool, which is if the input file exists and has content
// Parameters:
//     stateList []: Pointer to an array of ATState structures whose data is loaded in by the function
//     & entryCounter: Counter passed by reference that keeps track of how many entries are loaded in
// Precondition : stateList and entryCounter variables declared
// Postcondition: Data loaded in stateList and entryCounter set to number of entries in stateList
// Gets data from file and counts the number of entries; returns whether read was successful or not
bool getFileInfo(ATState stateList [], int& entryCounter) {
    // Prompt user for input file
    cout << "\nEnter AT file name: ";

	// Get input file from user
	char fName [100];
	cin.getline(fName, 100, '\n');

	// Open file and check if exists	
	ifstream readDat;
	readDat.open(fName);
	if(!(readDat.is_open())) {
		cerr << "Input file " << fName << " does not exist.";
		return false;
	}
	
	// Check to see if opened file is empty using "peek"
	int peekChar = 0;
	peekChar = readDat.peek();
	if (peekChar == EOF) {
		readDat.close();
		cerr << "Input file " << fName << " is empty.";
		return false;
	}

	ATState temp; // Temporary ATState structure for reading in data from file

	// Get information from file until EOF or max of STRUCT_COUNT is reached
	for (int i = 0; i < STRUCT_COUNT; i++) {
		// Get state name as whole line from file
		readDat.getline(temp.name, MAX_NAME_LENGTH, '\n');
		if(readDat.eof())	// Determine if EOF has occurred after read
			break;

		// Read numerical data
		readDat >> temp.miles;
		readDat >> temp.shelters;
	
		// Set next element in struct array to values in temp; increment count
		stateList[i] = temp;
		entryCounter++;

		// Prepare readDat for next reading by discarding everything after
		// the 'shelters' field that was just read in
		readDat.clear();
		readDat.ignore(255, '\n');
	}

	readDat.close();
	return true;
}


// printStateList
// Returns: void
// Parameters:
//     stateList []: List of states read in from file
//     entryNum: Number of entries held in stateList
// Precondition : stateList and entryNum must be initialized correctly
// Postcondition: None
// Prints the information contained in stateList in a formatted manner
void printStateList(ATState stateList [], int entryNum) {
	// Print information header and set decimal precision to 1 place
	cout << "     State           Miles Shelters"
	     << "\n     ------------------------------"
	     << fixed << setprecision(1);

	int nameSize = 0, totShelters = 0;
	double totMiles = 0.0;

	// Print information in formatted manner
	for (int i = 0; i < entryNum; i++) {
		cout << "\n     " << stateList[i].name;
		nameSize = 0;

		// Determine the size of the state name by look for the '\0' escape char
		for (int j = 0; stateList[i].name[j] != '\0' && j < MAX_NAME_LENGTH; j++)
			nameSize++;
		for (int j = nameSize; j < 16; j++)
			cout << ' ';

		// Format output fields for numeric data based on how large 'miles' is
		if ((stateList[i].miles < 100) && (stateList[i].miles >= 10))
			cout <<  " ";
		else if (stateList[i].miles < 10)
			cout <<  "  ";

		cout << stateList[i].miles << "     ";
		
		if (stateList[i].shelters < 10)
			cout << ' ';
		cout << stateList[i].shelters;
		
		// Add values for current state to total tally
		totMiles += stateList[i].miles;
		totShelters += stateList[i].shelters;
	}
	
	// Print totals for all states
	cout << "\n     ------------------------------"
	     << "\n     TOTALS         ";

	// Print leading spaces based on number size for total miles
	if ((totMiles <= 1000) && (totMiles >= 100))
		cout << ' ';
	else if ((totMiles <= 100) && (totMiles >= 10))
		cout << "  ";
	else if (totMiles < 10)
		cout << "   ";
	cout << totMiles << "   ";

	// Print leading spaces based on number size for total shelters
	if ((totShelters >= 100) && (totShelters < 1000))
		cout << ' ';
	else if ((totShelters <= 100) && (totShelters >= 10))
		cout << "  ";
	else if (totShelters < 10)
		cout << "   ";
	cout << totShelters;
}


// formatStateName
// Returns: void
// Parameters:
// 	* name: Character pointer (implicitly a character array/C-string)
// 	size: Size of the character array being input
// Precondition : * name and size must be initialized correctly
// Postcondition: Input state name is correctly formatted
// Formats name field of name C-string pointed to using proper grammar
void formatStateName(char* name) {
    // Size of the C-string passed in, to be calculated next
    int size;

    for (size = 0; (size < MAX_NAME_LENGTH) && (name[size] != '\0'); size++) {
        // Loop calculates size of C-string passed in
    }

	// Ensure size of state name is greater than 0
	if (size > 0) {
		// Set first character in name to capital letter if lower case letter
		if ((name[0] >= 97) && (name[0] <= 122))
			name[0] -= 32;
		
		// Process subsequent characters after first character
		for (int i = 1; i < size; i++) {

			// Capitalize character if previous character was a space
			if (name[i-1] == 32) {
				if ((name[i] >= 97) && (name[i] <= 122))
					name[i] -= 32;
			}
			// Lowercase character if capital and not adjacent to space char
			else if ((name[i] <= 90) && (name[i] >= 65))
				name[i] += 32;
		}
	}
}


// sortEntries
// Returns: void
// Parameters:
//     stateList []: Array of ATState structures to be sorted
//     entryNum: Size of array to be sorted
// Precondition : stateList and entryNum contain valid data
// Postcondition: stateList is sorted alphabetically based on name fields of structs
// Sorts the entries of stateList into alphabetical order using selection sort algorith 
void sortEntries(ATState stateList [], int entryNum) {
	int minIndex = 0;

	// Selection sort for entries based on state name
	for (int i = 0; i < entryNum-1; i++) {
		minIndex = i;
		// Determine is swap needs to occur
		for (int j = i+1; j < entryNum; j++) {
			if (strcmp(stateList[j].name, stateList[minIndex].name) < 0) {
				minIndex = j;
			}
		}
		// Swap
		swap(stateList[minIndex], stateList[i]);
	}
}
