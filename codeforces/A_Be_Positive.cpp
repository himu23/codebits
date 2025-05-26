#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    //cin>>k;
    while(k--){
        int n; cin>>n;
        int a[n];
        int l=0,r=0,s=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]<0) l++;
            else if(a[i]==0) s++;
            else r++;
        }
        int m=(n+1)/2;
        //cout<<m<<endl;
        if(l>=m){
            cout<<-1;
        }
        else if(r>=m) cout<<1;
        else{
            cout<<0;
        }
    }
    return 0;
}