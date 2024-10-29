#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    //cin>>k;
    while(k--){
        int n,m; cin>>n>>m;
        string s;
        cin>>s;
        while(m--){
            int a,b; cin>>a>>b;
            char c,d; cin>>c>>d;
            for(int i=a-1;i<b;i++){
                if(s[i]==c) s[i]=d;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}