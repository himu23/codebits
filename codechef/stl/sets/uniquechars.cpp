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
    set<char>s;
    string a;
    cin>>a;
    for(int i=0;i<n;i++){
        s.insert(a[i]);
    }
    int b=s.size();
    cout<<b<<endl;
    return 0;
}