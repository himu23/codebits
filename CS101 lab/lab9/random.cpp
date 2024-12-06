#include<iostream>
using namespace std;
double randuv(double u, double v){
    return u + (rand() / (1.0 + RAND_MAX)) * (v - u);
}
int main(){
    
}