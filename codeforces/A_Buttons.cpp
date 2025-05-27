#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int testcases; testcases=1;
    cin>>testcases;
    while(testcases--){
        int a,b,c; cin>>a>>b>>c;
        if(c%2==0){
            a--,b--;
        }
        else b--;
        if(a>b) cout<<"First"<<endl;
        else cout<<"Second"<<endl;
        
    }
    return 0;
}