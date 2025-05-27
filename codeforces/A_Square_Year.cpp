#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    cin>>k;
    while(k--){
        double n; cin>>n;
        if(floor(sqrt(n))!=ceil(sqrt(n))){
            cout<<-1<<endl;
        }
        else{
            int m=sqrt(n);
            cout<<0<<" "<<m<<endl;
        }
    }
    return 0;
}