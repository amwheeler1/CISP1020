// C and C++ programs can take in command-line arguments and react accordingly if programmed to do so.

// main function with no arguments passed in
int main () {
    ...
}

// main function able to read in arguments
int main (int argc, char* argv[]) {
    ...
}

// argc contains the number of parameters passed. It will always be at least 1, since the command to execute is passed in (i.e. ./a.out).
// argv[] is an array of C-strings containing the actual arguments passed in. As with argc, it will always contain at least the command to execute.


// Argument Usage Examples:
// CLI: ./a.out
int main (int argc, char* argv[]) {
    for (int i = 0; i < argc; i++)
        cout << '\n' << argv[i];
    }
    return 0;
}

// Output:
//    ./a.out


// CLI: ./a.out user.config
int main (int argc, char* argv[]) {
    for (int i = 0; i < argc; i++)
        cout << '\n' << argv[i];
    }
    return 0;
}

// Output:
//    ./a.out
//    user.config


// CLI: ./a.out user.config
int main () {
    for (int i = 0; i < argc; i++)
        cout << '\n' << argv[i];
    }
    return 0;
}

// Output:
//    Compilation error that argc and argv have not be declared

// An important thing to note about argc and argv is that they do not have to be named as such. Their names can be 
// anything as long as the data types are correct. However, argc and argv are the typical names of the variables and
// are almost immediately recognizable in a program as oppossed to a custom variable name. These names are also
// indicative of their purpose within the program (argc = argument count, argv = argument vector).
