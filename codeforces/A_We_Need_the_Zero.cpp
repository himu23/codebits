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
            temp^=a[i];
        }
        if(n%2==0){
            if(temp==0) cout<<1<<endl;
            else cout<<-1<<endl;
        }
        else{
            cout<<temp<<endl;
        }
    }
    return 0;
}