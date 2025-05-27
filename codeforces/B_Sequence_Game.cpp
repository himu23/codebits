#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int testcases; testcases=1;
    cin>>testcases;
    while(testcases--){
        int n; cin>>n;
        vector<int> b(n);
        vector<int> ans;
        int count=0;
        for(int i=0;i<n;i++){
            cin>>b[i];
            if(b[i]==1){
                count++;
                ans.push_back(b[i]);
            }
            else{
                count+=2;
                ans.push_back(b[i]);
                ans.push_back(1);
            }
        }
        cout<<count<<endl;
        for(int i=0;i<count;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}