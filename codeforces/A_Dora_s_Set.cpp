#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    cin>>k;
    while(k--){
        int n,m; cin>>n>>m;
        int temp;
        if(n%2==0){
            if(m%2==0){
                temp=(m-n)/2;
            }
            else{
                temp=(m-n+1)/2;
            }
        }
        else{
            if(m%2==0){
                temp=(m-n+1)/2;
            }
            else{
                temp=(m-n)/2+1;
            }
        }
        cout<<temp/2<<endl;
    }
    return 0;
}