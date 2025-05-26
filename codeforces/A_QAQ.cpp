#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    //cin>>k;
    while(k--){
        string s;
        cin>>s;
        vector<int> a;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='Q'){
                a.push_back(i);
            }
        }
        int ans=0;
        int m=a.size();
        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){
                for(int k=a[i];k<=a[j];k++){
                    if(s[k]=='A') ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}