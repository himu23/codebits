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
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int i=1;
        bool flag=false;
        while(!flag && i<=n){
            if(a[a[a[i]]]==i) flag=true;
            else i++;
        }
        if(flag) cout<<"YES";
        else cout<<"NO";
    }
    return 0;
}