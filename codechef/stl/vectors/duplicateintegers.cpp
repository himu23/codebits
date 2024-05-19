//can be done by unordered set for o(n) instead of two nested loops
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
    int t;
    cin>>t; //declaring a vector outside the while loop and clearing it everytime inside testcase and can be more efficient
    while(t--){
        int n;
        cin>>n;
        vi v(n);
        for(auto it= v.begin(); it!=v.end(); ++it){
            cin>>*it;
        }
        bool has_duplicate = false;
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(v[i] == v[j])
                  has_duplicate = true;
            }
        }
        if(has_duplicate){
        cout << "YES";
        }
        else{
        cout << "NO";
        }
        cout<<endl;
    }
    return 0;
}