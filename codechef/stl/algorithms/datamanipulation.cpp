//copy() is used to copy elements from one range to another.
//copy(source.begin(), source.end(), destination.begin()); o(n)
//reverse() is used to reverse the order of elements in a range.
//reverse(vec.begin(), vec.end());
//fill() assigns a specified value to all elements in a range.
//fill(vec.begin(), vec.end(), 42);
// iota() : assigns increasing values to a range starting from a specified value
//iota(vec.begin(), vec.end(), 1);  // Assigns values 1, 2, 3, 4, 5 to vec
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
    int n,x;
    cin>>n>>x;
    vi v(n);
    iota(v.begin(), v.end(), x);
    reverse(v.begin(), v.end());
    for(auto it= v.begin(); it!=v.end(); ++it){
        cout<<*it<<" ";
    }
    
    return 0;
}