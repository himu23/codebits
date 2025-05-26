#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    cin>>k;
    while(k--){
        int n,m; cin>>n>>m;
        int a=n-m;
        int ans=0;
        if(a<0) a*=-1;
        ans+=a/5;
        a=a-(a/5)*5;
        ans+=a/2;
        a=a-(a/2)*2;
        ans+=a;
        cout<<ans<<endl;
    }
    return 0;
}