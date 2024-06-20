/*
Pointer to pointer (double pointer) is an advanced concept in C++ that provides a way to work with pointers dynamically.
Just like a regular pointer stores the memory address of a data variable, a pointer to pointer stores the memory address of another pointer.

The main benefit of using pointer to pointer is its ability to add an additional level of indirection.
This can be helpful in scenarios like dynamic memory allocation, creating dynamic arrays, managing arrays of pointers, and modifying pointers inside functions.
*/
#include <iostream>
using namespace std;

int main() {
    int num = 42;
    int *ptr1 = &num;  // Regular pointer

    int **ptr2 = &ptr1;  // Pointer to pointer

    cout << "Value of num: "<< **ptr2;  // Output: 42

    return 0;
}
