#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int testcases; testcases=1;
    cin>>testcases;
    while(testcases--){
        ll a,b,n; cin>>a>>b>>n;
        vector<ll> x(n);
        ll total=b;
        for(int i=0;i<n;i++){
            cin>>x[i];
            total+=min(x[i],a-1);
        }
        cout<<total<<endl;
    }
    return 0;
}