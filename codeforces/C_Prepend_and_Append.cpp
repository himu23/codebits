#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int testcases; testcases=1;
    cin>>testcases;
    while(testcases--){
        int n; cin>>n;
        string s;
        cin>>s;
        int l=0, r=n-1;
        while(((int(s[l]) ^ int(s[r])) ==1) && l<r){
            l++,r--;
            //cout<<l<<" "<<r<<" "<<endl;
        }
        //error was coming due to operator precedence
        //== comes before ^
        cout<<r-l+1<<endl;
    }
    return 0;
}