#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void binaryform(vector<int>& v,int a,int n){
    n=pow(2,n);
    while(n>0){
        v.push_back(a/n);
        a=a%n;
        n/=2;
    }
}
int main() {
    int n;
    cin>>n;
    ll m=1;
    int a[n];
    for(int i=0;i<n;i++){
        m*=2;
        cin>>a[i];
    }
    vector<int> v;
    vector<int> vi;
    vector<vector<int>> ans;
    for(ll i=0;i<=m;i++){
        v.clear();
        vi.clear();
        binaryform(v,i,n);
        for(int j=n;j>0;j--){
            if(v[j]==1){
                vi.push_back(a[n-j]);
            }
        }
        ans.push_back(vi);
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}