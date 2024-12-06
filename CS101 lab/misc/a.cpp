#include<iostream>
using namespace std;
void swap(int &x, int &y){
    int z = x;
  x = y;
  y = z;}    
int main(){
    int a=8,b=7,c=11,d=10;
    if(a>b){swap(a,b);}
    if(b>c){swap(b,c);}
    if(c>d){swap(c,d);}
    if(a>b){swap(a,b);}
    if(b>c){swap(b,c);}
    if(a>b){swap(a, b);}
    cout<<a<<" "<<b<<" "<<c<<" "<<d;
    return 0;

    }