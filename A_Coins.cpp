#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    //cin>>k;
    while(k--){
        int n,m; cin>>n>>m;
        int ans=0;
        int i=n;
        while(m>0){
            ans+=m/i;
            m=m%i;
            i--;
        }
        cout<<ans<<endl;
    }
    return 0;
}