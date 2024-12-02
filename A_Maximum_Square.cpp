#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    cin>>k;
    while(k--){
        int n; cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if(n==1){
            cout<<1<<endl;
            continue;
        }
        sort(a,a+n,greater<int>());
        int i=0;
        while(i<n && a[i]>=i+1){
            ++i;
            //cout<<i<<" ";
        }
        cout<<i<<endl;
    }
    return 0;
}