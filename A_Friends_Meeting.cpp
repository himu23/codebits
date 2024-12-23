#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int q=1e5;
int a[q];
int givesteps(int n){
    if(n==0) return 0;
    if(n==1){
        a[n]=1;
        return a[n];
    }
    if(a[n]!=0) return a[n];
    else return n+givesteps(n-1);
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    //cin>>k;
    while(k--){
        int n,m; cin>>n>>m;
        int p= abs(n-m);
        if(p%2==0){
            n=p/2,m=p/2;
        }
        else{
            n=p/2,m=p/2+1;
        }
        cout<<givesteps(n)+givesteps(m);
    }
    return 0;
}