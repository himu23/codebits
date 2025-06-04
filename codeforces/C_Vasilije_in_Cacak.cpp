#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int testcases; testcases=1;
    cin>>testcases;
    while(testcases--){
        ll n,k,x; cin>>n>>k>>x;
        ll a=0, b=0;
        a=(k*(k+1))/2;
        b=((2*n-k+1)*k)/2;
        if(x>=a && x<=b) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
    return 0;
}