#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    //cin>>k;
    while(k--){
        int n,m; cin>>n>>m;
        int a[n],b[m];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        sort(b,b+m);
        for(int i=0;i<n;i++){
            if(binary_search(b,b+m,a[i])){
                cout<<a[i]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}