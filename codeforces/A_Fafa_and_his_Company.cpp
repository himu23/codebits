#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int solve(int n){
    int ans=1;
    //int m=n;
    int temp=0;
    while(n%2==0){
        temp++;
        n/=2;
    }
    ans=ans*(temp+1);
    for(int i=3;i<=sqrt(n);i+=2){
        temp=0;
        while(n%i==0){
            temp++;
            n/=i;
        }
        ans*=(temp+1);
    }
    if(n>1){
        ans*=2;
    }
    return ans-1;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    //cin>>k;
    while(k--){
        int n; cin>>n;
        cout<<solve(n);
    }
    return 0;
}