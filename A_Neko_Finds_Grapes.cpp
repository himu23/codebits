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
        int oa=0,ea=0;
        int ob=0,eb=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]%2==0) ea++;
            else oa++;
        }
        for(int i=0;i<m;i++){
            cin>>b[i];
            if(b[i]%2==0) eb++;
            else ob++;
        }
        cout<<min(oa,eb)+min(ea,ob)<<endl;
        
    }
    return 0;
}