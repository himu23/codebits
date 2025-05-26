#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    cin>>k;
    while(k--){
        int a,b,c; cin>>a>>b>>c;
        int ans=0;
        while(b>0 && c>1){
            b--; ans++;
            c=c-2;
            ans+=2;
        }
        while(a>0 && b>1){
            a--; ans++;
            b=b-2;
            ans+=2;
        }
        cout<<ans<<endl;
    }
    return 0;
}