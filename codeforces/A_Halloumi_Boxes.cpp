#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int testcases; testcases=1;
    cin>>testcases;
    while(testcases--){
        int n,k; cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        vector<int> b=a;
        sort(b.begin(),b.end());
        if(b!=a && k==1){
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
        
    }
    return 0;
}