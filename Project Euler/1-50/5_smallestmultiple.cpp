//learned about lcm of n numbers
#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define pb push_back
using namespace std;
int gcd(int n,int m){
    int d=max(n,m);
    int c=min(n,m);
    while(c!=0){
        int temp=c;
        c=d%c;
        d=temp;
    }
    return d;
}
int32_t main() {
    int n;
    cin>>n;
    vi v;
    int i=1;
    while(i<=n){
        v.pb(i);
        i++;
    }
    int lcm=v[0];
    for(int i=1;i<n;i++){
        lcm=(lcm*v[i])/(gcd(lcm,v[i]));
    }
    cout<<lcm<<endl;
    return 0;
}