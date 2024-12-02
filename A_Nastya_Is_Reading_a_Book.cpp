#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    //cin>>k;
    while(k--){
        int n; cin>>n;
        int m=n;
        int com=0;
        vector<pair<int,int>> pages;
        while(m--){
            int a,b;
            cin>>a>>b;
            pages.push_back(make_pair(a,b));
        }
        int c; cin>>c;
        for(int i=0;i<n;i++){
            if(pages[i].second<c){
                com++;
            }
        }
        cout<<n-com;
    }
    return 0;
}