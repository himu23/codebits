//call by value: the function works with a local copy of the value and the original variable in the main() function remains unchanged.
//call by reference: any changes made to the parameter within the function directly affect the original variable outside the function.
//in c, call by reference is achieved using pointers.
//When a pointer is passed to a function, changes made through the pointer affect the original value it points to.
#include <iostream>
using namespace std;

void incrementByReference(int *x) {
    (*x)++;
    cout << "New value during function: " << *x << "\n"; 
}

int main() {
    int num = 5;
    incrementByReference(&num); //the & was used for call by reference
    cout << "Num after function call: " << num; // Output: num value during function : 6<<endl<<num after function call: 6
return 0;
}
