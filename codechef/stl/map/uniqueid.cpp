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
    /* //using sets
    set<int>s;
    int sum=0;
    for(auto it= v.begin(); it!=v.end(); ++it){
        cin>>*it;
        sum+=*it;
        s.insert(*it);
    }
    int ans=0;
    for(auto it= s.begin(); it!=s.end(); ++it){
        ans+=*it;
    }
    cout<<sum-ans<<endl;
    */
    //using maps
    map<int,int> m;
    for(auto it= v.begin(); it!=v.end(); ++it){
        cin>>*it;
        m[*it]++;
    }
    for(auto it= m.begin(); it!=m.end(); ++it){
        if(it->second==2){
            cout<<it->first<<endl;
            break;
        }
    }
    return 0;
}