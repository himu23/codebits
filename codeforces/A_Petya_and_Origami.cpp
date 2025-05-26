#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    //cin>>k;
    while(k--){
        int n,m; cin>>n>>m;
        int r=2*n, g=5*n, b=8*n;
        int ans=0;
        ans+= (r+m-1)/m;
        ans+= (g+m-1)/m;
        ans+= (b+m-1)/m;
        cout<<ans<<endl;
    }
    return 0;
}