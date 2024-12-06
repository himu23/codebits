#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int coinsum(int n, vector<int>& coins){
    vector<int>dp(n+1,0);
    dp[0]=1;
    for(int coin:coins){
        for(int i=coin;i<=n;i++){
            dp[i]+=dp[i-coin];
        }
    }
    return dp[n];
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n; cin>>n;
    vector<int>coins={1,2,5,10,20,50,100,200};
    cout<<coinsum(n,coins)<<endl;
    return 0;
}