// File: main.cpp
// Author: amwheeler1
// Date: 210120-11:15 (January 20, 2021 @ 11:15am)
// This program takes a file name from the user, reads in the data, and prints out
// 	a relevant message.

#include "ioHandle.h"
#include "stateInf.h"

int main () {

	// Declare main informational objects used in program	
	ATState stateList [STRUCT_COUNT];
	int entryNum = 0;

	printWelcome();

	// If getFileInfo was successful, format information, sort, and print to user
	if (getFileInfo(stateList, entryNum)) {
		for (int i = 0; i < entryNum; i++)
			formatStateName(stateList[i].name); // Format
		sortEntries(stateList, entryNum);    // Sort
		printStateList(stateList, entryNum); // Print
	}

	printExit();

	return 0;
}
