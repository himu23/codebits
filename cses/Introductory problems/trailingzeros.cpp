//#good

#include <bits/stdc++.h>
using namespace std;

int fivefactor(int n){
    int ans=0;
    while(n>0){
        n=n/5;
        ans+=n;
    }
    return ans;
}

int fivefactor1(int n){
    int ans=0;

    while(n>0){
        if(n%5==0){
            ans++;
            n/=5;
        }
        if(n%5!=0) return ans;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n; cin>>n;
    /*int ans=0;
    for(int i=1;i<=n;i++){
        ans+=fivefactor(i);
    }*/

    cout<<fivefactor(n)<<endl;
    //cout<<ans<<endl;
    return 0;
}