#include <iostream>
using namespace std;

class User{
private:
    string name="Alice";
    string password="Wonderland";

public:
    void set(string name,string password){
        this->name = name;
        this->password = password;
    }
    void get(){
        cout<<name<<" "<<password<<endl;
    }
};

int main() {
    User obj;
    obj.get();
    obj.set("Tom","Jerry");
    obj.get();
    return 0;
}
//"this" is used within a class member function to refer to the object on which the member function is called.
//Remember that structures in C++ can also have member functions, but they are limited in functionality compared to classes.
//It's generally recommended to use classes for more complex data structures that require inheritance, encapsulation and abstraction, while using structs for simpler data containers.
////The main difference between a class and a struct in C++ is that members of a class are private.
// definations of both ends with semocolon.
