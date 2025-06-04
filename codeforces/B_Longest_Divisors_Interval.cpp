#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int testcases; testcases=1;
    cin>>testcases;
    while(testcases--){
        ll n; cin>>n;
        bool flag= true;
        int i=1;
        while(flag){
            if(n%i==0){
                i++;
            }
            else flag = false;
        }
        cout<<--i<<endl;

    }
    return 0;
}