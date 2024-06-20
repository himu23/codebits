//int *ptrArray[5]; declares an array of pointers to integers with 5 elements.
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20, c = 30;
    int *ptrArray[3];  // Array of pointers to integers

    ptrArray[0] = &a;
    ptrArray[1] = &b;
    ptrArray[2] = &c;

    // ptrArray is an array of pointers to integers. Each element of the array holds the address of a corresponding integer variable (a, b, or c). 
    // By dereferencing the pointers, you can access the values stored in those integer variables.
    
    cout << "Value at ptrArray[0]: " << *ptrArray[0] << "\n"; // Output: 10
    cout << "Value at ptrArray[1]: " << *ptrArray[1] << "\n";  // Output: 20
    cout << "Value at ptrArray[2]: " << *ptrArray[2] << "\n";  // Output: 30

    return 0;
}
