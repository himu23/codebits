#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    cin>>k;
    while(k--){
        double a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
        double x,y;
        x=ceil(a/c);
        y=ceil(b/d);
        if(x+y>e){
            cout<<"-1"<<endl;
            continue;
        }
        else{
            cout<<x<<" "<<y<<endl;
        }

        
    }
    return 0;
}