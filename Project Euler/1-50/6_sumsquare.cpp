#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define pb push_back
using namespace std;
int sq(int n){
    return n*n;
}
int32_t main() {
    int n;
    cin>>n;
    int a=0;
    int b=0;
    for(int i=1;i<=n;i++){
        a=a+sq(i);
        b=b+i;
    }
    b=sq(b);
    cout<<b-a<<endl;
    return 0;
}