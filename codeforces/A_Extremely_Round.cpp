#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int testcases; testcases=1;
    cin>>testcases;
    while(testcases--){
        int n; cin>>n;
        int a=0;
        int m=n;
        while(m>0){
            m/=10;
            a++;
        }
        m=n/pow(10,a-1);
        //cout<<a<<" "<<m<<endl;
        int ans=0;
        ans+=9*(a-1);
        ans+=m;
        cout<<ans<<endl;
    }
    return 0;
}