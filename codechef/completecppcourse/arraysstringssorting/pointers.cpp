//void functions primary purpose is to generate and rint a list of numbers and it dossent need to return any value.
// setprecision : used to set the ios library floating point precision based on the specified as the parameter to this method.
//new: allocates memory dynamically.
// delete: deallocates memory.
//file handling: fopen(), fclose(), fread(), fwrite()

////pointers
//pointer arithmetics to perform arithmetic operations on pointers.
// in pointer arithmetic the size of the data type being pointed to matters.
// increment(pt++) it moves forward in memory by the size of the data type it points to.
// decrement(--) moves it backwards
//adding an interger value to a pointer (pt + n) moves it forward by n times the size of the data type.
// (pt-n) moves it backward
#include <iostream>
using namespace std;

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int *ptr = numbers; // Pointer to the first element

    for (int i = 0; i < 5; i++) {
        cout << *ptr << " ";
        ptr++; // Move the pointer to the next element
//ptr++ actually advances the pointer by sizeof(int) bytes to the next integer in the array.
    }

    return 0;
}
void swap(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
