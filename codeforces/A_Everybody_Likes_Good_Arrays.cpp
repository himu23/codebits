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
        }
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        int temp=1;
        int ans=0;
        for(int i=1;i<n;i++){
            if((a[i]%2)==(a[i-1]%2)){
                temp++;
            }
            else{
                ans+=temp-1;
                temp=1;
            }
            //cout<<ans<<" ";
        }
        ans+=temp-1;
        cout<<ans<<endl;

    }
    return 0;
}