/*
    Similar to structures, unions provide a way to create a composite data type, but unlike structures, all members of a union share the same memory space.
This means that a union can hold only one value at a time, and the memory occupied by a union is equal to the size of its largest member.

//
The break statement is used in the switch statement to terminate a particular case and exit the switch block.
*/
// Solution as follows

#include <iostream>
using namespace std;

struct Struct {
    int a;
    int b;
};

union Union {
    int a;
    int b;
};

union Temperature {
    float celsius;
    float fahrenheit;
    float kelvin;
};

int main() {
    union Temperature temp;
    float inputTemp;
    char inputUnit;

    cin >> inputTemp;  
    cin >> inputUnit;  // Read character input

    switch (inputUnit) {
        case 'C':
            temp.fahrenheit = (inputTemp * 9/5) + 32;
            cout << temp.fahrenheit << "\n";
            temp.kelvin = inputTemp + 273.15;
            cout << temp.kelvin << "\n";
            break;

        case 'F':
            temp.celsius = (inputTemp - 32) * 5/9;
            cout << temp.celsius << "\n";
            temp.kelvin = (inputTemp - 32) * 5/9 + 273.15;
            cout << temp.kelvin << "\n";
            break;

        case 'K':
            temp.celsius = inputTemp - 273.15;
            cout << temp.celsius << "\n";
            temp.fahrenheit = (inputTemp - 273.15) * 9/5 + 32;
            cout << temp.fahrenheit << "\n";
            break;

    }
    cout << sizeof(Struct) << " " << sizeof(Union) << "\n";
    //output  8 4
    return 0;
}
