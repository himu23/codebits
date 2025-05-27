#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int testcases; testcases=1;
    cin>>testcases;
    while(testcases--){
        int n; cin>>n;
        vector<int> a(n);
        int cp=0,cn=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]==1) cp++;
        }
        cn=n-cp;
        int total=cp-cn;
        int ans=0;
        if(total<0){
            int temp=(abs(total)+1)/2;
            ans+=temp;
            cp+=temp;
            cn-=temp;
        }
        if(cn%2!=0) ans++;
        cout<<ans<<endl;
    }
    return 0;
}