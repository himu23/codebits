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
int32_t main() {
    int n, x;
    cin>>n>>x;
    vi v(n);
    for(auto it=v.begin(); it!=v.end();++it){
        cin>>*it;
    }
    replace(v.begin(), v.end(), x, x+1);
    for(auto it=v.begin(); it!=v.end();++it){
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}