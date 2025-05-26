#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    //cin>>k;
    while(k--){
        int n,m; cin>>n>>m;
        string s[n];
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        int a=n,b=0;
        int c=m,d=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i][j]=='B'){
                    a=min(a,i+1);
                    b=max(b,i+1);
                    c=min(c,j+1);
                    d=max(d,j+1);
                }
            }
        }
        cout<<(a+b)/2<<" "<<(c+d)/2<<endl;

    }
    return 0;
}