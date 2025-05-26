#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    //cin>>k;
    while(k--){
        int a,b,c; cin>>a>>b>>c;
        a/=1, b/=2, c/=4;
        cout<<min(min(a,b),c)*7;
    }
    return 0;
}