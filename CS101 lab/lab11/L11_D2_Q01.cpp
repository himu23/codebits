#include <simplecpp>
// Defined a structure called myVector.
// It has three member variables: x, y, z
struct myVector {
double x;
double y;
double z;
};
// This function, setValue returns the result which is of type structure
// i.e. in other words, this function returns a structure
// The function takes three arguments
myVector setValue( int a , int b , int c ) {
myVector ans; // creates an ans object of type myVector
ans . x = a; // sets member variables of structure for ans object
ans . y = b;
ans . z = c;
return ans; // return the object, ans of type myVector to the main
}
// Accepts an argument a that is of type myVector
// and prints it’s member variables
void printVector ( myVector a ) {
cout << "(" << a . x << ", " << a . y << ", " << a . z << ")" << endl;
}
// Returns addition of two vectors a and b passed as arguments
myVector add ( myVector a , myVector b ) {
myVector ans;
ans . x = a . x + b . x ;
ans . y = a . y + b . y ;
ans . z = a . z + b . z ;
return ans;
}
myVector scale ( myVector a , int factor ) {
// Fill your code here to scale the vector by the factor given
// and return the result (a vector) to the main
myVector ans;
ans.x = factor*a.x;
ans.y = factor*a.y;
ans.z = factor*a.z;
return ans;
}
int dotProduct ( myVector a , myVector b ) {
// Fill your code here to perform dotProduct on two vectors
// and return the result (an integer) to the main
int dot;
dot = a.x*b.x + a.y*b.y + a.z*b.z;
return dot;
}
myVector crossProduct ( myVector a , myVector b ) {
// Fill your code here to perform crossProduct on two vectors
// and return the result (a vector) to the main
myVector ans;
ans.x = a.y * b.z - a.z * b.y;
ans.y = a.z * b.x - a.x * b.z;
ans.z = a.x * b.y - a.y * b.x;
return ans;
}
bool isColPlanar( myVector a , myVector b, myVector c, myVector d ) {
// Fill your code here to perform crossProduct on two vectors
// and return the result (a vector) to the main
myVector AB = add(b,(scale(a, -1)));
myVector AC = add(c,(scale(a, -1)));
myVector AD = add(d,(scale(a, -1)));
myVector cross = crossProduct (AC, AD);
int volume = dotProduct (AB, cross);
if(volume == 0){
    return true;
}
else{
    return false;
}
}
main_program {
myVector a, b,c,d; // a,b,c,d are objects of structure myVector
int x, y, z;
//TAKING INPUTS FROM USER------------------------------------
cin >> x >> y >> z;
a = setValue (x, y, z); //set value of vector a
cin >> b . x >> b . y >> b . z ; //take vector b from main itself
cin >> c . x >> c . y >> c . z ; // take vector c from main itself
cin >> d . x >> d . y >> d . z ; // take vector d from main itself
int factor;
cin >> factor; //factor to scale the vector
//---------------------------------------------------------------
myVector ans1 = add (a, b);
myVector ans2 = scale (a, factor);
int ans3 = dotProduct (a, b);
myVector ans4 = crossProduct (a, b);
bool ans5 = isColPlanar (a, b, c, d);
//PRINTING THE RESULTS
printVector (ans1);
printVector (ans2);
cout << ans3 << endl;
printVector (ans4);
cout << ans5;
}