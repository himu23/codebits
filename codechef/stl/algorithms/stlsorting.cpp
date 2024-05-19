//stl sort is typically an implementation of the introsort algorithm, which is ahybrid sorting algorithm that combines three different algorithms: quicksort, heapsort, and insertion sort.
//sort(start_iterator, end_iterator, comparison_function);
//comparision_function: optional function or lambda to specify cust. e.g std::greated<int>()
//stable_sort : similar to sort, but it ensures that the relative order of equal elements remains unchanged after sorting.o(nlogn)
//partial_sort : smallest k elements are sorted in ascending order: o(nlogk)
//partial_sort(start_iterator, middle_iterator, end_iterator, comparison_function);
//e.g partial_sort(vec.begin(), vec.begin() + 3, vec.end());  // Sorts the smallest 3 elements
//nth_element() : rearenges the elements such that the element at the nth position is in its correct sorted position,
//and all elements before it are less than or equal to it, while all elements after it are greater than or equal to it. 
//nth_element(vec.begin(), vec.begin() + 2, vec.end());
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
    vsort(v);
    for(auto it= v.begin(); it!=v.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}