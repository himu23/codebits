//next_permutation() : rearranges the elements in a range into the next lexicographically greater permutation.
// If the current permutation is the largest possible, it rearranges the elements to the smallest possible permutation 
//and returns false, otherwise returns true. o(n)
// prev_permutation : oppositie of next_permutation. o(n);
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
    next_permutation(v.begin(), v.end());
    for(auto it= v.begin(); it!=v.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;
    prev_permutation(v.begin(), v.end());
    prev_permutation(v.begin(), v.end());
    for(auto it= v.begin(); it!=v.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}