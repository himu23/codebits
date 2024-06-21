/*
In C++, a constructor is a special member function within a class that is automatically called when an instance (object) of the class is created.
Constructors have the same name as the class and do not have a return type, not even void. Constructors can be overloaded, which means you can define multiple constructors with different parameter lists.
*/
#include <iostream>
using namespace std;

class MyClass {
public:
    int value;
    
    // Default constructor (no parameters)
    MyClass() {
        cout << "Default constructor called." << std::endl;
        value = 0;
    }

    // Parameterized constructor
    MyClass(int val) {
        cout << "Parameterized constructor called." << std::endl;
        value = val;
    }

    void displayValue() {
        cout << "Value: " << value << std::endl;
    }

};

int main() {
    MyClass obj1;         // Calls the default constructor
    MyClass obj2(42);     // Calls the parameterized constructor

    obj1.displayValue();
    obj2.displayValue();

    return 0;
}


//Yes, a parameterized constructor is a type of user-defined constructor. When a class has a parameterized constructor but does not have a default constructor, attempting to create an object of that class without providing arguments will result in a compilation error. This is because the compiler will not generate a default constructor if any user-defined constructors are present.

//-------//
/*
If you provide a class with a user-defined parameterized constructor but do not provide a default constructor, attempting to create an object without arguments will result in a compilation error.
This is because the compiler does not generate a default constructor if any user-defined constructors are present.
*/
//e.g
/*
#include <iostream>
using namespace std;

class BankAccount {
public:
    int id;
    double balance;

    // User-defined constructor
    BankAccount(int i, double b) : id(i), balance(b) {}
};

int main() {
    BankAccount account1;  // Attempt to create an object without arguments
    cout << "Account ID: " << account1.id << ", Balance: " << account1.balance << endl;
    return 0;
}
*/

