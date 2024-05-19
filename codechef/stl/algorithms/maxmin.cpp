//int min_value = *min_element(v.begin(), v.end());
//int max_value = *max_element(v.begin(), v.end());
//if several elements are equal to the largest it returns the iterator of first occuring
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
    vi v (n);
    for(auto it= v.begin(); it!=v.end(); ++it){
        cin>>*it;
    }
    int a=mxe(v);
    int b=mne(v);
    if(a%b==0){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    cout<<endl;
    return 0;
}