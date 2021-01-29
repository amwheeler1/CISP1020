// File: stateInf.h
// Author: amwheeler1
// Date: 210120-1116 (January 20, 2021 @ 11:16am)
// Contains function definitions and include directives for the program.

#ifndef IOHANDLE_H
#define IOHANDLE_H

#include <cstring>    // Manipulation functions for C-string data
#include <iomanip>    // Manipulation functions for console I/O
#include <iostream>   // Console I/O
#include <fstream>    // File I/O
#include "stateInf.h" // Contains structure definition

using namespace std;

void printWelcome();
void printExit();
bool getFileInfo(ATState stateList [], int& entryCounter);
void printStateList(ATState stateList [], int entryNum);
void formatStateName(char* name);
void sortEntries (ATState stateList [], int entryNum);

#endif
