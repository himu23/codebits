//Duplicate elements are not allowed. 
// s.insert() will automatically insert them in ascending order.
//If you want a container that allows multiple occurrences of the same element, you can use the multiset container.
// set<int> s;
// int sz=s.size(); //s.insert(x): inserts an elemint x into the set. if x is already present in the set, the insert operation has no efect.
//s.erase(x) // if(s.count(x)): returns 1 or 0;
//insertion, deletion, and finding elements in a set have a time complexity of O(logn)O(logn) on average. 
//This is because sets are usually implemented as balanced binary search trees.
//set <int> s1{1, 2, 3}
//elements can be accessed through iterators
//they cant be accessed by index.
#include "bits/stdc++.h"
//finding number of distinct integers
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
    set<int>s;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        s.insert(a);
    }
    cout<<s.size()<<endl;
    return 0;
}