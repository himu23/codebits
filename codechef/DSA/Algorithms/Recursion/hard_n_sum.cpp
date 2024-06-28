#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(vector<int> &a, int b, int n, set<vector<int>> &ans,vector<int> &curr){
    if(b==0){
        ans.insert(curr);
    }
    if(b>=a[n]){
        curr.push_back(a[n]);
        solve(a,b-a[n],n,ans,curr);
        curr.pop_back();
    }
    if(n+1<a.size() && b>=a[n+1]){
        solve(a,b,n+1,ans,curr);
    }
}
int main() {
    int k;
    cin>>k;
    while(k--){
        int n,b;
        cin>>n>>b;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        vector<int> curr;
        set <vector<int>> ans;
        solve(a,b,0,ans,curr);
        cout<<ans.size()<<endl;
        for(auto i:ans){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

}