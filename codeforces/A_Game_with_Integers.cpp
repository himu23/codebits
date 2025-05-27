#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int testcases; testcases=1;
    cin>>testcases;
    while(testcases--){
        int n; cin>>n;
        if(n%3==1 || n%3==2) cout<<"First";
        else cout<<"Second";
        cout<<endl;
    }
    return 0;
}