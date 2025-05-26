#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    //cin>>k;
    while(k--){
        int n; cin>>n;
        if(n%3==0){
            cout<<1<<" "<<1<<" "<<n-2;
        }
        else if(n%3==1){
            cout<<1<<" "<<1<<" "<<n-2;
        }
        else{
            cout<<1<<" "<<2<<" "<<n-3;
        }
    }
    return 0;
}