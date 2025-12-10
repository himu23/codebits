#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
    int n; cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    ll ans=0, cur=0;
    int l=0, r=n-1;
    while(l<=r){
        if(l==r){
            if(a[r]==0) break;
            if(cur>=a[r]) ans++;
            else{
                ll diff = a[r]-cur;
                ll cnt = (diff+1)/2;
                ans+=cnt;
                if(a[r]-cnt > 0) ans++;
            }
            break;
        }
        ll need = a[r]-cur;
        if(a[l]>=need){
            a[l]-=need;
            ans+=need+1;
            cur=0;
            r--;
            if(a[l]==0) l++;
        }
        else{
            cur+=a[l];
            ans+=a[l];
            a[l]=0;
            l++;
        }
    }
    cout<<ans<<endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}