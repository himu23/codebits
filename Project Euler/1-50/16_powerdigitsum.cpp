#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    //cin>>k;
    while(k--){
        int n; cin>>n;
        vector<int>ans(310,0);
        ans[0]=1;
        for(int i=1;i<=n;i++){
            int carry=0;
            for(int j=0;j<ans.size();j++){
                int product=ans[j]*2+carry;
                ans[j]=product%10;
                carry=product/10;
            }
        }      
        int sum=0;
        for(int i=0;i<ans.size();i++){
            sum+=ans[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}