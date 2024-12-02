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
        int cone=0,czero=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') cone++;
            else czero++;
        }
        //cout<<cone<<" "<<czero<<endl;
        if(cone!=czero){
            cout<<1<<endl<<s;
        }
        else{
            cout<<2<<endl;
            cout<<s[0]<<" ";
            for(int i=1;i<n;i++) cout<<s[i];
        }
    }
    return 0;
}