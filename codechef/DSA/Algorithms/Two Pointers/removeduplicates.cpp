//can be easily done by sets
//remove duplicates
#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin>>k;
    while(k--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<int> vi;
        int i=1,j=0;
        vi.push_back(a[0]);
        int ans=1;
        while(i<n){
            if(a[i]!=a[j]){
                vi.push_back(a[i]);
                j=i;
                ans++;
            }
            i++;
        }
        cout<<ans<<endl;
        for(auto &i:vi){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
