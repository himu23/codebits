#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define pb push_back
#define sc static_cast
#define srt(v)  sort(v.begin(),v.end())
#define mxe(v)  *max_element(v.begin(),v.end())
#define mne(v)  *min_element(v.begin(),v.end())
using namespace std;
uint mul(int x, int y){
        return x*y;
    }
int32_t main() {
    int t;
    cin>>t;
    while(t--){
        uint n;
        cin>>n;
        vi v (n);
        for(auto it= v.begin(); it!=v.end(); ++it){
            cin>>*it;
        }
        vi vec (v.size());
        partial_sum(v.begin(), v.end(), vec.begin());
        uint prod=1;               //had to initialize 1 as uint because directly using it was causing overflows
        uint product = accumulate(vec.begin(), vec.end(), prod, mul);
        string ans;
        uint a=mxe(v), b=mne(v);
        if(product%a==0 &&  product%b==0){
            ans="YES";
        }
        else{
            ans="NO";
        }
        cout<<product<<" "<<ans<<endl;

    }
    return 0;
}