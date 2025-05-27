#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int testcases; testcases=1;
    cin>>testcases;
    while(testcases--){
        int n; cin>>n;
        int total=0;
        for(int i=0;i<n-1;i++){
            int a;
            cin>>a;
            total+=a;
        }
        cout<<0-total<<endl;
    }
    return 0;
}