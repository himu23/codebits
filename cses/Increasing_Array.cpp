//
#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define pb push_back
#define sc static_cast
#define vsort(v)  sort(v.begin(),v.end())
#define mxe(v)  *max_element(v.begin(),v.end())
#define mne(v)  *min_element(v.begin(),v.end())
using namespace std;
int32_t main() {
    int n;
    cin>>n;
    vi v(n);
    for(auto it= v.begin(); it!=v.end(); ++it){
        cin>>*it;
    }
    int ans=0;
    for(int i=1;i<n;i++){
        if(v[i]<v[i-1]){
            ans+=v[i-1]-v[i];
            v[i]=v[i-1];
        }
    }
    cout<<ans<<endl;
    return 0;
}