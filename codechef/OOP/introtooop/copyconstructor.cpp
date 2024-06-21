/*
The Car class has two constructors: one to set the car's name and another called the copy constructor.
The copy constructor is called when we create a new car object (copiedCar) and initialize it using an existing car object (originalCar).
The copy constructor copies the car's name from the existing car to the new car, creating a new car that's a copy of the original one.
*/
#include <iostream>
using namespace std;

class Car {
public:
    string carName;

    // Parameterized constructor
    Car(string carName){
      this->carName = carName;
    }

    // Copy Constructor
    Car(Car &c){
      carName = c.carName;
    }
};

int main() {
    Car originalCar("Beat"); // Parameterized constructor called here
    cout<<originalCar.carName<<endl;

    Car copiedCar(originalCar); // Copy constructor called here
    cout<<copiedCar.carName<<endl;

    return 0;
}
/*
Beat
Beat
*/