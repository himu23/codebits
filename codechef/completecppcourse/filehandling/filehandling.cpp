#include <iostream>
#include <fstream>
using namespace std;

void userFunction() {

     /* Show file */
    system("ls -l /mnt/himu23");
//It helps you see all the files in your directory at the location - /mnt/himu23
    system("cat /mnt/himu23/input.txt");
//shows file comtents
    string filename = "/sample_file.txt";
    ofstream myFile(filename);
    int number;
    
    // Read and display the numbers from the file
    while (myFile >> number) {
        cout << number << "\n";
    }
    // Close the file
    MyFile.close();
}
/*
string filename = "/sample_file.txt";: This line declares a string filename and initializes it with the path to the input text file
ifstream myFile(filename);: This line uses the ifstream operator to make a input stream to the file specified by the filename. \
ifstream is used to read from a file and ofstream is used to write to a file. \
int number;: Declares an integer variable number that will be used to store the integers read from the file.
The while loop reads integers from the file using the myFile stream:

    myFile >> number: This reads an integer from the file.
    The loop continues as long as myFile successfully reads an integer and returns a value that is not NULL.
    Inside the loop, the program prints each read integer using cout << number << "\n";.

After reading and displaying all the integers, the myFile.close(); statement closes the file.
*/