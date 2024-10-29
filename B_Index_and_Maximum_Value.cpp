#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    cin>>k;
    while(k--){
        int n,m; cin>>n>>m;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        while(m--){
            char c; cin>>c;
            int l,r; cin>>l>>r;
            int ans=0;
            for(int i=0;i<n;i++){
                if(a[i]>=l && a[i]<=r){
                    if(c=='+') a[i]++;
                    else a[i]--;
                }
                ans=max(ans,a[i]);
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
}