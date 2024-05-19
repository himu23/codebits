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
int dis(int a,int b){
    return a*a+b*b;
}
int32_t main() {
    int n;
    cin>>n;
    vector<pair<int,pair<int,int>>>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].second.first>>v[i].second.second;
        v[i].first=dis(v[i].second.first, v[i].second.second);
    }
    vsort(v);
    for(int i=0;i<n;i++){
        cout<<v[i].second.first<<" "<<v[i].second.second<<endl;
    }
    return 0;
}