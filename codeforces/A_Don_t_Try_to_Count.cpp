#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int testcases; testcases=1;
    cin>>testcases;
    while(testcases--){
        int n,m; cin>>n>>m;
        string x,s; cin>>x>>s;
        int ans=0;
        while(x.find(s)==string::npos){
            x+=x;
            ans++;
            if(x.find(s)!=string::npos) break;
            if(x.length()>3*s.length() && ans>0){
                ans=-1;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}