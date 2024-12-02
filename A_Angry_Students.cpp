#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    cin>>k;
    while(k--){
        int n; cin>>n;
        string s;
        cin>>s;
        int ans=0;
        int temp=0;
        bool flag=false;
        for(int i=0;i<n;i++){
            // if(i==n-1){
            //     if(s[i]=='P'){
            //         temp++;
            //     }
            //     ans=max(ans,temp);
            //     continue;
            // }
            if(s[i]=='A'){
                flag=true;
                temp=0;
            }
            else if(flag && s[i]=='P'){
                temp++;
            }
            ans=max(temp,ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}