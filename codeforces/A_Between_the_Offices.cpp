#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    //cin>>k;
    while(k--){
        int n; cin>>n;
        string s;
        cin>>s;
        int a=0,b=0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='F' && s[i+1]=='S') a++;
            else if(s[i]=='S' && s[i+1]=='F') b++;
        }
        //cout<<a<<b;
        if(b>a) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
    return 0;
}