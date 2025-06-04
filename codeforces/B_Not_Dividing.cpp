#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int testcases; testcases=1;
    cin>>testcases;
    while(testcases--){
        int n; cin>>n;
        vector<ll> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]==1) a[i]++;
        }
        for(int i=0;i<n-1;i++){
            if(a[i+1]%a[i]==0){
                a[i+1]++;
            }
        }
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        //cout<<temp<<" ";
        cout<<endl;
    }
    return 0;
}