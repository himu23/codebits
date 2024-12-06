#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool coinpiles(int n ,int m){
    if((n+m)%3!=0) return false;
    if(2*n>=m && 2*m>=n) return true;
    else return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    cin>>k;
    while(k--){
        int n,m; cin>>n>>m;
        if(coinpiles(n,m)){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
        cout<<endl;
    }
    return 0;
}