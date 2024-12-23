#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    //cin>>k;
    while(k--){
        int n,m,p; cin>>n>>m>>p;
        if(p<=n){
            if(p<=m) cout<<p;
            else cout<<m;
        }
        else{
            int a=n+m-p;
            if(a<0) cout<<0;
            else cout<<a;
        }
    }
    return 0;
}