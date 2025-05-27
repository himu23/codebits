#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    //cin>>k;
    while(k--){
        string s,t,w;
        cin>>s>>t>>w;
        int n=s.length();
        int m=w.length();
        unordered_map<char,char> um;
        for(int i=0;i<n;i++){
            um[s[i]]=t[i];
            um[static_cast<char>(s[i]-32)]=static_cast<char>(t[i]-32);
        }

        for(int i=0;i<m;i++){
            if(um.count(w[i])){
                cout<<um[w[i]];
            }
            else cout<<w[i];
        }
    }
    return 0;
}