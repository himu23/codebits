#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    //cin>>k;
    while(k--){
        int n; cin>>n;
        int m=n/10;
        if(n%10>5){
            cout<<m*10+10;
        }
        else{
            cout<<m*10;
        }
    }
    return 0;
}