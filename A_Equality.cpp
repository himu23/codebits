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
        int ans=n;
        int temp=0;
        for(int i=0;i<m;i++){
            char c=i+'A';
            for(int j=0;j<n;j++){
                if(s[j]==c) temp++;
            }
            ans=min(ans,temp);
            temp=0;
        }
        cout<<ans*m<<endl;
    }
    return 0;
}