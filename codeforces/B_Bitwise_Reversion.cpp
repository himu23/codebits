#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll x,y,z; 
    cin>>x>>y>>z;
    if((x&y&~z) | (x & z & ~y) | (y & z & ~x)){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; 
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
