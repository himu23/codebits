#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int m; m=1;
    //cin>>k;
    while(m--){
        int n,k; cin>>n>>k;
        int a[n];
        int ans=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            if(a[i]>=a[k-1] && a[i]>0) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}