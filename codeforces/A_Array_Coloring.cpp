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
        int temp=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            temp+=a[i];
        }
        if(temp%2==0) cout<<"yes";
        else cout<<"no";
        cout<<endl;
    }
    return 0;
}