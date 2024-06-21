#include <iostream>
using namespace std;

#ifdef _WIN32   // Predefined macro for Windows
#define PATH_SEPARATOR '\\'
#else
#define PATH_SEPARATOR '/'
#endif

int main() {
    string filename= "data.txt";
    string directory = "files";

    // Create a platform-independent file path
    cout << directory << PATH_SEPARATOR << filename;

    return 0;
}
/*
Suppose you're writing a program that needs to work on both Windows and Unix-like systems,
and you need to handle file paths differently due to the differences in file path separators (\ for Windows, / for Unix-like systems).
*/