#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int testcases; testcases=1;
    cin>>testcases;
    while(testcases--){
        int x,k; cin>>x>>k;
        if(x%k!=0){
            cout<<1<<endl<<x<<endl;
        }
        else{
            cout<<2<<endl<<1<<" "<<x-1<<endl;
        }
    }
    return 0;
}