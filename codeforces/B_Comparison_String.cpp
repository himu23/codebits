#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int testcases; testcases=1;
    cin>>testcases;
    while(testcases--){
        int n; cin>>n;
        unordered_map<int,int> um;
        string s; cin>>s;
        int ans=0;
        int temp=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]) temp++;
            else{
                ans=max(ans,temp);
                temp=1;
            }
        }
        ans=max(ans,temp);
        cout<<ans+1<<endl;

    }
    return 0;
}