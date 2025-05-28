#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int testcases; testcases=1;
    cin>>testcases;
    while(testcases--){
        int a,b,c,d; cin>>a>>b>>c>>d;
        if(c-a-d+b>0) cout<<-1<<endl;
        else{
            if(d-b<0) cout<<-1<<endl;
            else{
                cout<<abs(c-a-d+b)+d-b<<endl;
            }
        }
    }
    return 0;
}