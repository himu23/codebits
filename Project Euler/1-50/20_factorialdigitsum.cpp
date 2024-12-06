#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    //cin>>k;
    while(k--){
        int n; cin>>n;
        vector<int>ans(500,0);
        ans[0]=1;
        int ans_size=1;
        for(int i=2;i<=n;i++){
            int carry=0;
            for(int j=0;j<ans_size;j++){
                int product=ans[j]*i+carry;
                ans[j]=product%10;
                carry=product/10;
            }
            while(carry){
                ans[ans_size]=carry%10;
                carry/=10;
                ans_size++;
            }
        }
        int sum=0;
        for(int i=0;i<=200;i++){
            sum+=ans[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}