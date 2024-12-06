//could not find the formula of attacking positions by myself
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
    cout << std::fixed<<std::setprecision(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a=i*i*(i*i-1)/2;
        cout<<a-4*(i-1)*(i-2)<<endl;
    }
    return 0;
}