#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int testcases; testcases=1;
    cin>>testcases;
    while(testcases--){
        int n,a,b; cin>>n>>a>>b;
        if(n==1){
            cout<<"Yes"<<endl;
            continue;
        }
        else{
            if(a==b && a==n) cout<<"Yes";
            else if(a+b<n-1) cout<<"Yes";
            else cout<<"No";
        }
        cout<<endl;
    }
    return 0;
}