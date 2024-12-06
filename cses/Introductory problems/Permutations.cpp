//
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
    if(n==1){
        cout<<1;
        return 0;
    }
    if(n<=3){
        cout<<"NO SOLUTION";
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(i%2==0){
            cout<<i<<" ";
        }
    }
    for(int i=1;i<=n;i++){
        if(i%2!=0){
            cout<<i<<" ";
        }
    }
    cout<<endl;
    return 0;
}