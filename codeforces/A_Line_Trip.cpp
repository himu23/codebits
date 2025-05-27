#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int testcases; testcases=1;
    cin>>testcases;
    while(testcases--){
        int n,x; cin>>n>>x;
        vector<int> a(n);
        int ans=0;
        for(int i=0;i<n;i++) cin>>a[i];
        for (int i=1;i<n;i++){
            ans=max(ans,a[i]-a[i-1]);
        }
        ans=max(ans, 2*(x-a[n-1]));
        ans=max(ans,a[0]);
        cout<<ans<<endl;
    }
    return 0;
}