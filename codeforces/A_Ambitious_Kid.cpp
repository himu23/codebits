#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int testcases; testcases=1;
    //cin>>testcases;
    while(testcases--){
        int n; cin>>n;
        vector<int> a(n);
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            cin>>a[i];
            ans=min(abs(a[i]),ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}