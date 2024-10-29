#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    //cin>>k;
    while(k--){
        int n; cin>>n;
        if(n%4==1) cout<<'0'<<" "<<'A';
        else if(n%4==2) cout<<'1'<<" "<<'B';
        else if(n%4==3) cout<<'2'<<" "<<'A';
        else cout<<'1'<<" "<<'A';
    }
    return 0;
}