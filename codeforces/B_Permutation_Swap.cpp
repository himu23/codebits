#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int testcases; testcases=1;
    cin>>testcases;
    while(testcases--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int ans=abs(a[0]-1);
        for(int i=1;i<n;i++){
            ans=__gcd(ans,abs(a[i]-i-1));
        }
        cout<<ans<<endl;

    }
    return 0;
}