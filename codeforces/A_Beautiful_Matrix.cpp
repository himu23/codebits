#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int a[5][5];
    int n,m;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int b;
            cin>>b;
            if(b==1){
                n=i+1;
                m=j+1;
            }
        }
    }
    int ans=0;
    if(n<3) ans+=3-n;
    else ans+=n-3;
    if(m<3) ans+=3-m;
    else ans+=m-3;
    cout<<ans<<endl;
    return 0;
}