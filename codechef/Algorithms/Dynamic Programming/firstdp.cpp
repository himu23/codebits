//smart brute force
//maximum subset sum
//number of subsets of a set such that no subset contains adjecant elements of the set
//if a[n] is not included s(n-1), if a[n] is included s(n-2) so total s(n)=s(n-1)+s(n-2);
#include <bits/stdc++.h>
using namespace std;

int main() {
	int k;
	cin>>k;
	while(k--){
	    int n;
	    cin>>n;
	    int a[n+1];
	    a[0]=0;
	    for(int i=1;i<=n;i++){
	        cin>>a[i];
	    }
	    int dp[n+1];
	    dp[0]=0;
	    dp[1]=max(a[1],0);
	    for(int i=2;i<=n;i++){
	        dp[i]=max(a[i]+dp[i-2],dp[i-1]);
	    }
	    cout<<dp[n]<<endl;
	}

}
