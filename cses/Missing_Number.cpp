//can also be done by calculating the sum of n numbers.
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
    vi v(n-1);
    for(auto it= v.begin(); it!=v.end(); ++it){
        cin>>*it;
    }
    vsort(v);
    int a=1;
    for(auto it= v.begin(); it!=v.end(); ++it){
        if(*it!=a){
            cout<<a;
            return 0;
        }
        a++;
    }
    cout<<n;   //border case when the missing nummber is the last number.
    return 0;
}