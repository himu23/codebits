//learned about set precision
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
    cin>>t;
    cout << std::fixed<<std::setprecision(0);
    while(t--){
        int y,x;
        cin>>y>>x;
        int a=max(y,x);
        int b=a*a-(a-1);
        int sign=(a%2==0) ? 1 : -1;
        cout<<b+(y-x)*sign<<endl;
    }
    return 0;
}