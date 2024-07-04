#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    long long fans = 0;
    cin>>n;
    vector<int>a(n,0);
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    map<long,long>m1;
    vector<long long>pre(n+1,0);
    int sum = 0;
    m1[0] = 1;
    for(int i = 1;i<=n;i++){
        sum += a[i-1];
        fans += m1[sum-i];
        m1[sum-i]++;
    }
    cout<<fans<<"\n";
}
int main() {
    int freq = 1;
    while(freq--){
        solve();
    }
	// your code goes here

}