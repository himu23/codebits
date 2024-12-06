#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod = 1e9 + 7;
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n; cin>>n;
    int ans=1%mod;
    while(n--){
        ans=(ans*2)%mod;
    }
    cout<<ans<<endl;
    return 0;
}