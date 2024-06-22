#include<bits/stdc++.h>
using namespace std;


int main() { 
 // write your code here
    int n;
    cin>>n;
    vector<int> a(n);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    int ans=0;
    for(auto it:mp){
        ans=max(ans,it.second);
    }
    cout<<ans<<endl;
    return 0;
}
