// pair<int, int> p= make_apir(1,2); //pair<double, string>p;
//pair<int, int> p={1,2};
//int x=p.first, y=p.second;
//compairing pairs p1<p2. o(1);
// vector of pairs: vector<pair<int,int>>v;
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
    int t;
    cin>>t;
    while(t--){
        vector<pair<int,string>>v(3);
        for(int i=0;i<3;i++){
            cin>>v[i].first;
        }
        v[0].second="ALICE";
        v[1].second="BOB";
        v[2].second="CHARLIE";
        vsort(v);
        cout<<v[0].second <<endl;
    }
    return 0;
}