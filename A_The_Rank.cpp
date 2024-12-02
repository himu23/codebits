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
        vector<pair<int,int>> scores;
        while(m--){
            //cout<<m<<" ";
            int temp=0;
            int b=4;
            while(b--){
                int a;
                cin>>a;
                temp+=a;
            }
            // cout<<n-m<<" ";
            // cout<<temp<<endl;
            scores.push_back(make_pair(temp,m));
        }
        sort(scores.begin(),scores.end());
        for(int i=0;i<n;i++){
            if(scores[i].second==n-1){
                // ++i;
                // cout<<i<<" ";
                cout<<n-i<<endl;
                break;
            }
        }
    }
    return 0;
}