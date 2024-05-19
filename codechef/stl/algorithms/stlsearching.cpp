//find() : iterator to the first occurance of the value if found, or the end iterator if the value is not found
//auto it = find(vec.begin(), vec.end(), 4); o(n)
//for binary_search vector must be sorted. o(logn)
//bool found = binary_search(vec.begin(), vec.end(), 4);
//lower_bound returns an iterator to the first element that is not less than(greater than or equal to) the given value.
//auto it = lower_bound(vec.begin(), vec.end(), 2); o(logn)
//upper_bound : iterator to the first element that is greater than the given value
//auto it = upper_bound(vec.begin(), vec.end(), 2); o(logn)

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
    int n, s, l ,u;
    cin>>n>>s>>l>>u;
    vi v(n);
    for(auto it= v.begin(); it!=v.end(); ++it){
        cin>>*it;
    }
    vsort(v);
    if(binary_search(v.begin(), v.end(), s)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    cout<<" ";
    auto it= lower_bound(v.begin(), v.end(), l);
    cout<<*it<<" ";
    auto i=upper_bound(v.begin(), v.end(), u);
    cout<<*i<<" ";
    return 0;
}