#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20, c = 30;
    int *ptrArr[3];

    ptrArr[0] = &a;
    ptrArr[1] = &b;
    ptrArr[2] = &c;

    // Bug: The doublePtr is uninitialized and pointing to a random memory location.
    // It needs to be properly initialized to point to the array of pointers.
    int **doublePtr = ptrArr;

    cout << "Value at doublePtr[0]: " << **doublePtr << "\n";
    cout << "Value at doublePtr[1]: " << **(doublePtr + 1) << "\n";
    cout << "Value at doublePtr[1]: " << **(doublePtr + 2) << "\n";

    return 0;
}
/*
Value at doublePtr[0]: 10
Value at doublePtr[1]: 20
Value at doublePtr[2]: 30
*/

//IMP NOTES
/*
//Pointer Arithmetic: When you perform doublePtr + 1, you are moving the pointer to the next element in the array of pointers. 
    Since doublePtr points to an array of int*, adding 1 moves it to the next int* in the array.

//Dereferencing: **doublePtr first dereferences doublePtr to get ptrArr[0], which is &a, and then dereferences &a to get the value of a
*/