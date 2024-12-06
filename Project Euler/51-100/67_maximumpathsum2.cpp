//DP[i][j] = A[i][j] + max(DP[i-1][j-1], DP[i-1][j]);
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
	int k; k=1;
	//cin>>k;
	while(k--){
	    int n; cin>>n;
	    if(n==1){
	        int x; cin>>x; cout<<x<<endl;
	        continue;
	    }
	    vector<vector<int>>a(n),dp(n);
	    for(int i=0;i<n;i++){
	        for(int j=0;j<=i;j++){
	            int x; cin>>x;
	            a[i].push_back(x);
	            dp[i].push_back(0);
	        }
	    }
	    int ans=INT_MIN;
	    dp[0][0]=a[0][0];
	    for(int i=1;i<n;i++){
	        for(int j=0;j<=i;j++){
	            int temp1,temp2;
	            if(j-1<0) temp1=INT_MIN;
	            else temp1=dp[i-1][j-1];
	            if(j==i) temp2=INT_MIN;
	            else temp2=dp[i-1][j];
	            dp[i][j]=a[i][j]+max(temp1,temp2);
	            ans=max(ans,dp[i][j]);
	        }
	    }
	    cout<<ans<<endl;
	    
	    
	}
    return 0;
}
