#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n; cin>>n;
    int a[n+2];
    a[1]=1;
    for(int i=3;i<=n;i+=2){
        //cout<<a[i]<<endl;
        a[i]=(i-2)*(i-2)*4+(i-1)*10+a[i-2];
    }
    cout<<a[n]<<endl;
    return 0;
}