#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    //cin>>k;
    while(k--){
        ll n,m; cin>>n>>m;
        if((n/m)%2==1){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
    }
    return 0;
}