#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int testcases; testcases=1;
    cin>>testcases;
    while(testcases--){
        int n; cin>>n;
        vector<ll> a(n);
        int countzero=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]==0) countzero++;
        }
        int count=0;
        int temp=0;
        for(int i=0;i<n;i++){
            if(a[i]!=0) temp++;
            else if(a[i]==0){
                if(temp!=0) count++;
                temp=0;
            }
        }
        if(temp!=0) count++;
        if(countzero==n){
            cout<<0<<endl;
            continue;
        }
        if(count==1){
            cout<<1<<endl;
            continue;
        }
        if(n>2){
            cout<<2<<endl;
            continue;
        }
        else cout<<1<<endl;
    }

    return 0;
}