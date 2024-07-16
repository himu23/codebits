//DP[i][j] = A[i][j] + max(DP[i-1][j], DP[i][j-1]);
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
	int k; k=1;
	cin>>k;
	while(k--){
	    int n; cin>>n;
	    int a[n][n];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            cin>>a[i][j];
	        }
	    }
	    int dp[n][n];
	    dp[0][0]=0;
	    for(int i=1;i<n;i++){
	        dp[0][i]=a[0][i]+dp[0][i-1];
	        dp[i][0]=a[i][0]+dp[i-1][0];
	    }
	    for(int i=1;i<n;i++){
	        for(int j=1;j<n;j++){
	            dp[i][j]=a[i][j]+max(dp[i-1][j],dp[i][j-1]);
	        }
	    }
	    double ans=static_cast<double>(dp[n-1][n-1]);
	    if(ans<0){
	        cout<<"Bad Judges"<<endl;
	        continue;
	    }
	    double temp=2*n-3;
	    cout<< fixed << setprecision(6)<<ans/temp<<endl;
	}
    return 0;
}
