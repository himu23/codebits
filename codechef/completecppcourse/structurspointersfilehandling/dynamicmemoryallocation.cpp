/*
Dynamic memory allocation is a technique in programming that allows you to allocate memory for variables at runtime, as opposed to compile time.
This is particularly useful when you don't know the exact memory requirements beforehand or when memory needs change dynamically during program execution.
In C++, there are 2 operators available for dynamic memory allocation: new and delete.

//new
The new operator is used to allocate a block of memory of a specified size.
It returns a pointer to the first byte of the allocated memory block.
The allocated memory will not be initialized, and its initial value will be undefined. You should avoid using uninitialized memory because it can lead to unpredictable behavior in your program.

//delete
The delete operator in C++ is used to deallocate memory that was previously allocated using the new operator
When you call delete ptr, where ptr is a pointer to the memory block that was allocated, the memory is returned to the system's memory pool and can be reused for other purposes.

*/
#include <iostream>
using namespace std;

int main() {
    int *ptr;
    int n = 5;
    
    ptr = new int[n]; // Allocating memory for 5 integers
//This line dynamically allocates memory for an array of 5 integers and assigns the address of the first element to the pointer ptr. The new keyword is used for dynamic memory allocation in C++.

    if (ptr == NULL) {
        cout << "Memory allocation failed.\n";
        return 1;
    }
//This block checks if the memory allocation failed by checking if ptr is NULL. However, in modern C++, new throws a std::bad_alloc exception if it fails to allocate memory, rather than returning NULL.
//When the main function returns 0, it generally means that the program executed successfully without any errors. This is a convention that is widely followed in programming.
//On the other hand, when the main function returns a non-zero value, such as 1, it typically indicates that the program encountered an error or some condition that prevented it from completing successfully. This non-zero return value can be used to signal to the operating system, or to other programs or scripts that might run this program, that something went wrong.

    // Access and manipulate the allocated memory
    for (int i = 0; i < n; i++) {
        ptr[i] = i * 10;
        cout << "ptr[" << i << "] = " << ptr[i] << "\n";
    }
    delete ptr;
    
    return 0;
}
