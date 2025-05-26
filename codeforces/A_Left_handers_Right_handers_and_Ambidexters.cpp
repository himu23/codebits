#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    //cin>>k;
    while(k--){
        int b,c,a; cin>>b>>c>>a;
        int l=min(b,c), r=max(b,c);
        int n=0;
        n+=l, r-=l;
        if(r>=a) n+=a;
        else{
            n+=r, a-=r;
            n+=a/2;
        }
        cout<<2*n<<endl;
    }
    return 0;
}