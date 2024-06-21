/*
    Static Data Members: Static data members belong to the class itself, rather than to individual objects created from the class. They are shared among all instances of the class and are initialized only once, typically at the beginning of the program.
    Static Member Functions: Static member functions are associated with the class rather than with instances of the class. They can only access static data members and other static member functions of the class.
*/
/*
    In C++, the scope resolution operator :: is used to access elements (variables, functions, classes, etc.) that belong to a particular scope, such as a namespace or a class.
    You can use the scope resolution operator to access static data members and static member functions of a class. Refer to the code to know how to use scope resolution operator.
*/
#include <iostream>
using namespace std;

class MyClass {
public:
    static int staticCounter; // Static data member

    MyClass() {
        staticCounter++; // Incremented each time an object is created
    }

    static void displayCounter() {
        cout << "Static Counter: " << staticCounter << endl;
    }
};

int MyClass::staticCounter = 0; // Initialize the static data member

int main() {
    MyClass obj1;
    MyClass obj2;
    MyClass::displayCounter(); // Accessing the static member function

    return 0;
}


//e.g
/*
#include <iostream>
using namespace std;

class BankAccount {
public:
    static int totalBalance;
    int balance;
    
    BankAccount(int amount) {
        totalBalance += amount;
    }
};

int BankAccount::totalBalance = 0.0;

int main() {
    int amount; 
    cin>>amount;
    BankAccount account1(amount);
    cin>>amount;
    BankAccount account2(amount);


    cout << BankAccount::totalBalance << endl;

    return 0;
}
*/
//the size of BankAccount instances does not include the size of static int totalBalance.
//because Static members are not stored within each individual instance of the class. Instead, they are shared across all instances and stored separately.
