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
        int temp=INT_MAX;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=1;i<n;i++){
            temp=min(temp,a[i]-a[i-1]);
        }
        if(temp<0) cout<<0;
        else if(temp==0) cout<<1;
        else cout<<temp/2+1;
        cout<<endl;
    }
    return 0;
}