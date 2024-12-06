#include "bits/stdc++.h"
//#define int long long
#define uint unsigned long long
#define vi vector<int>
using namespace std;
bool ispalandrome(int n){
    int original=n;
    int reversed=0;
    while(n>0){
        reversed=reversed*10+n%10;
        n=n/10;
    }
    return original==reversed;
}
int32_t main() {
    int n;
    cin>>n;
    int a=pow(10,n)-1;
    int b=pow(10,n-1);
    int largest=0;
    for(int i=a;i>=b;i--){
        for(int j=i;i>=b;j--){
            int product=i*j;
            if(product<=largest){
                break;
            }
            else if(ispalandrome(product)){
                largest=product;
            }
        }
    }
    cout<<largest<<endl;
    return 0;
}