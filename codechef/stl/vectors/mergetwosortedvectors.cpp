//learned about is_sorted function and merging of two sorted vectors
/*// Read 'n' elements into the vector 'a'
    for (int &x : a) {
        cin >> x;
    }

    // Print the elements to verify
    for (const int &x : a) {
        cout << x << " ";
    }*/
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
    vi a(n), b(m);
    for(auto it= a.begin(); it!=a.end(); it++){
        cin>>*it;
    }
    for(auto it= b.begin(); it!=b.end(); it++){
        cin>>*it;
    }
    if(is_sorted(a.begin(),a.end()) && is_sorted(b.begin(), b.end())){
        vi v(n+m);
        merge(a.begin(),a.end(), b.begin(), b.end(), v.begin());
        for(auto it= v.begin(); it!=v.end(); it++){
            cout<<*it<<" ";
        }
    }
    else{
        if(n>m){
            reverse(a.begin(),a.end());
            for(auto it= a.begin(); it!=a.end(); it++){
                cout<<*it<<" ";
            }
        }
        else{
            reverse(b.begin(),b.end());
            for(auto it= b.begin(); it!=b.end(); it++){
                cout<<*it<<" ";
            }
        }
    }
    return 0;
}