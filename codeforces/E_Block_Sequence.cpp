#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
    ll n;cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    vector<ll> dp(n+1);
    dp[n]=0;
    for(ll i=n-1;i>=0;i--){
        dp[i]=dp[i+1]+1;
        ll temp=i+a[i]+1;
        if(temp<=n) dp[i]=min(dp[i],dp[temp]);
    }
    cout<<dp[0]<<endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
	int tc; tc=1;
	cin>>tc;
	while(tc--){
	    solve();
	}
    return 0;
}