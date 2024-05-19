// gcd(a,b) is in the <numeric> header. o(log(min(a,b)));
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
    //directly use yhe gcd function from stl
    int ans=accumulate(v.begin()+1, v.end(),v[0], [](int a, int b){return gcd(a,b);});
    cout<<ans<<endl;
    return 0;
}