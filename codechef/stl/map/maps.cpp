// map is basically set of pairs and tuples
//maps store key-value pairs. each key in the map is unique
//and the map automatically manages the order of keys and values.
//map<string, int> m;
//this creates an empty map that associates strings with integers.
//you can choose the data types for both the keys and values in the map.
// int sz=m.size();
// m.insert(make_pair(key, value)); //if key is already present it updates the corresponding value.
// m.erase(key) : removes the key-value pair, if it exists.
// auto it = m.find(key);  if key not found the iterator points to the end of the map.
// if(m.count(key)) : checks if an key exists in the map. returns 1 if found, 0 otherwise.
// for(auto it= m.begin(); it!=m.end(); ++it)
// for(auto &it: m)
// insertion deletion and finding: o(logn) : maps are implemented as balanced binary search trees.
//maps maintain an order based on the keys. each key in the map is unique.
// map<int, string>m; : m[2]="g";
// finding frequency of each string in an array of string : map<string, int>m;
#include "bits/stdc++.h"

//get characters frequency

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
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<char,int>m;
        string s;
        cin>>s;
        for(int i=0;i<n;i++){
            char c= s[i];
            m[c]++;      //i just love this
        }
        cout<<m.size()<<endl;
        for(auto it: m){
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
    return 0;
}