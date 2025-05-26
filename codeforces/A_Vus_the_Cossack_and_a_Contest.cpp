#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    //cin>>k;
    while(k--){
        int n,m,k; cin>>n>>m>>k;
        int ans=0;
        if(m>=n) ans++;
        if(k>=n) ans++;
        if(ans<2) cout<<"No";
        else cout<<"Yes";
    }
    return 0;
}