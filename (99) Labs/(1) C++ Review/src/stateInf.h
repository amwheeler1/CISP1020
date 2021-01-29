// File: ioHandle.h
// Author: awheeler1
// Date: 210120-1117 (January 20, 2021 @ 11:17am)
// Contains structure definition for ATState, which contains trail and shelter
// 	data for a named state.

#ifndef STATEINF_H
#define STATEINF_H

#define MAX_NAME_LENGTH 15	// Longest state name (in this case North Carolina [14])
#define STRUCT_COUNT 14		// Maximum number of structures can be read from file

// Data structure for state's information
struct ATState {
	char name[MAX_NAME_LENGTH];
	double miles = 0.0;
	int shelters = 0;
};

#endif
