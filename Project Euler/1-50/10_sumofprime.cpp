//all primes are of the form 6+-1;
//at max one prime factor greater than sqrt(n) 
//similar to problem 7
#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define pb push_back
using namespace std;
bool isprime(int n){
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=5;i*i<=n;i+=6){
        if(n%i==0 || n%(i+2)==0) return false;
    }
    return true;
}
int32_t main() {
    int n;
    cin>>n;
    int sum =0;
    int a=1;
    while(a<n){
        if(isprime(a)){
            sum+=a;
        }
        a++;
    }
    cout<<sum<<endl;
    return 0;
}