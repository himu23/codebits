#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    //cin>>k;
    while(k--){
        long double n; cin>>n;
        long double ans=1;
        for(long double i=0;i<n;i++){
            ans*=(2*n-i)/(n-i);
        }
        cout<<fixed<<setprecision(0)<< ans<<endl;
    }
    return 0;
}
