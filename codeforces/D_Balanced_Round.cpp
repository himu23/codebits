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
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        int ans=0;
        int temp=1;
        for(int i=1;i<n;i++){
            if(a[i]-a[i-1]<=k) temp++;
            else{
                ans=max(ans,temp);
                temp=1;
            }
        }
        ans=max(ans,temp);
        cout<<n-ans<<endl;
    }
    return 0;
}