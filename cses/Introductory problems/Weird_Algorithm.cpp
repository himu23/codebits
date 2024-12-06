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
    bool flag=true;
    while(flag){
        cout<<n<<" ";
        if(n==1){
            break;
        }
        if(n%2==0){
            n/=2;
        }
        else{
            n=n*3+1;
        }
    }
    return 0;
}