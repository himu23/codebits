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
            if(s[i]=='n') cone++;
        }
        czero=(n-cone*3)/4;
        //cout<<cone<<czero;
        for(int i=0;i<cone;i++){
            cout<<'1'<<" ";
        }
        for(int i=0;i<czero;i++){
            cout<<'0'<<" ";
        }
        cout<<endl;
    }
    return 0;
}