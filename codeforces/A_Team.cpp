#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    cin>>k;
    int count=0;
    while(k--){
        int a,b,c; cin>>a>>b>>c;
        if(a+b+c>=2) count++;
    }
    cout<<count<<endl;
    return 0;
}