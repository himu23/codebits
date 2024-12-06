//any number can have at max one prime factor which is larger then it square root
//new concept learned
#include "bits/stdc++.h"
#define int long long
using namespace std;

int32_t main() {
    int n=600851475143;
    int m=sqrt(n);
    int a=n;
    int b=2;
    for(int i=2;i<=m;i++){
        while(a%i==0){
            a=a/i;
            b=i;
        }
    }
    if(a==1){
        cout<<b;
    }
    else{
        cout<<a;
    }
    return 0;
}