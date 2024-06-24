#include <bits/stdc++.h>
using namespace std;

const int N = 100002;
const int MOD = 1e9 + 7;
long long DP[N];

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, l;
        cin>>n>>l;
 
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            dp[i] = 0;
            for(int j=i-1; j>=1 && i-j+1<=l; j-=2)
                dp[i] = (dp[i]+dp[j-1])%MOD;
        }
 
        cout<<DP[n]<<endl;
    }
    return 0;
}