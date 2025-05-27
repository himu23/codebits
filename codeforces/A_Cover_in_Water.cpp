#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int testcases; testcases=1;
    cin>>testcases;
    while(testcases--){
        int n; cin>>n;
        string s; cin>>s;
        int ans=0;
        int temp=0;
        int countot=0;
        bool flag=false;
        for(int i=0;i<n;i++){
            if(s[i]=='.' && i!=n-1){
                temp++;
            }
            else if(s[i]=='#' || i==n-1){
                if(i==n-1 && s[i]=='.') temp++;
                if(temp==2 || temp==1){
                    countot+=temp;
                    temp=0;
                }
                else if(temp>=3){
                    flag=true;
                    temp=0;
                }
            }
        }
        if(flag) ans+=2;
        else ans+= countot;
        cout<<ans<<endl;
    }
    return 0;
}