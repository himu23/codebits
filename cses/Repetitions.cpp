//
#include "bits/stdc++.h"
//#define int long long
#define uint unsigned long long
#define vi vector<int>
#define pb push_back
#define sc static_cast
#define vsort(v)  sort(v.begin(),v.end())
#define mxe(v)  *max_element(v.begin(),v.end())
#define mne(v)  *min_element(v.begin(),v.end())
using namespace std;
int32_t main() {
    string s;
    cin>>s;
    char c=s[0];
    int count=1;
    int ans=0;
    for(int i=1;i<s.length();i++){
        if(c==s[i]){
            count++;
        }
        else{
            c=s[i];
            ans=max(ans,count);
            count=1;
        }
    }
    ans = max(ans, count);
    cout<<ans<<endl;
    return 0;
}