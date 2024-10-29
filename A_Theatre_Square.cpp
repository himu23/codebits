#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    //cin>>k;
    while(k--){
        ll n,m,p; cin>>n>>m>>p;
        ll a=(n+p-1)/p;
        ll b=(m+p-1)/p;
        cout<<a*b;
    }
    return 0;
}