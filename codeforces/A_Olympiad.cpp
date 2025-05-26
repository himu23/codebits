#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    //cin>>k;
    while(k--){
        int n; cin>>n;
        int a[n];
        unordered_map<int,int> um;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]!=0){
                um[a[i]]++;
            }
        }
        cout<<um.size()<<endl;
    }
    return 0;
}