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

        for(int i=0;i<n;i++){
            cin>>a[i];
            cout<<n-a[i]+1<<" ";
        }
        cout<<endl;

    }
    return 0;
}