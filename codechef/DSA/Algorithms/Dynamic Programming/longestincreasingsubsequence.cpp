//DP[i]=maxj=1j=i−1​{1+DP[j], if Aj​≤Ai​}.
//And Final Answer = max⁡{DP[1],DP[2],…,DP[N]}.
//This is an O(N2) DP solution.
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
	int k; k=1;
	cin>>k;
	while(k--){
	    int n; cin>>n;
	    int a[n],b[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    for(int i=0;i<n;i++){
	        cin>>b[i];
	    }
	    int dp[n];
	    dp[0]=1;
	    int ans=INT_MIN;
	    for(int i=0;i<n;i++){
	        int temp=1;
	        for(int j=0;j<i;j++){
	            if(a[j]<a[i] && b[j]>b[i]){
	                temp=max(temp,1+dp[j]);
	            }
	        }
	        dp[i]=temp;
	        ans=max(ans,dp[i]);
	    }
	    cout<<ans<<endl;
	}
    return 0;
}
