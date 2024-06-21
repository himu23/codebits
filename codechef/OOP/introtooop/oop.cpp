#include<bits/stdc++.h>
using namespace std;

// Step 1: Define the class
class MyClass {
    // Step 2: Declare private members (data and functions)
    private:
        int privateValue;

    // Step 3: Declare public members (data and functions)
    public:
        int publicValue;

        void publicFunction() {
            
        }
};

int main() {
    // Step 4: Create an object of the class
    MyClass obj;

    // Step 5: accessing and changing the object's public data
    obj.publicValue = 10;

    // Step 6: Use the object's public functions
    obj.publicFunction();

    return 0;
}
/*

    Define the class: Use the class keyword to define your class. The class definition should contain the declaration of its members (variables and functions).

    Declare private members: Declare private members inside the private: section. These members are only accessible within the class.

    Declare public members: Declare public members inside the public: section. These members are accessible outside the class and are used to interact with objects of the class.

    Create an object: Instantiate an object of the class using the class name.

    Use public member functions: Access and use the public member functions of the object to perform actions or retrieve information.

    Use public member data: Access and use the public member data of the object to perform actions or retrieve information.

*/
//In C++, if you do not specify an access modifier when declaring members inside a class, the default access modifier will be private.
//the sizeof object is the sum of all individual data members.
//Dot operator is used to access methods and attributes of a object
//The size of object of empty class is 1.
//p = {3, 7}; can also be used to initialize a structure variable in C++.