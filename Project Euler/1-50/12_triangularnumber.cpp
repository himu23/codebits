//for divisors check upto sqrt(n)
#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define pb push_back
using namespace std;
int noofdiv(int n){
    int a=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            if(i*i==0){
                a+=1;
            }
            else{
                a+=2;
            }
        }
    }
    return a;
}
int32_t main() {
    int n;
    cin>>n;
    int i=0;
    int j=1;
    while(noofdiv(i)<=n){
        i+=j;
        j++;
    }
    cout<<i<<endl;
    return 0;
}