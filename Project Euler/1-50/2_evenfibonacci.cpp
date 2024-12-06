#include <iostream>
using namespace std;

int main() {
    int a=0;
    int b=1;
    int c=a+b;
    int sum=0;
    while(c<=4000000){
        a=b;
        b=c;
        c=a+b;
        if(c%2==0){
            sum=sum+c;
        }
    }
    cout<<sum<<endl;
    return 0;
}