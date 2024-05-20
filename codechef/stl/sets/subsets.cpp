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
    int n,m;
    cin>>n>>m;
    set<int>s;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        s.insert(a);
    }
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        s.insert(a);
    }
    int a=s.size();
    if(a==n){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    cout<<endl;
    
    return 0;
}