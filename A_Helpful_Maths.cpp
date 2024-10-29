#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    string s;
    cin>>s;
    vector<int> v;
    for(int i=0;i<s.length();i++){
        if(s[i]!='+'){
            v.push_back(s[i]-'0');
        }
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        if(i!=v.size()-1) cout<<v[i]<<'+';
        else cout<<v[i];
    }
    cout<<endl;
    return 0;
}