#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    cin>>k;
    while(k--){
        string s; cin>>s;
        int n=s.length();
        if(n<=10){
            for(int i=0;i<n;i++){
                cout<<s[i];
            }
            cout<<endl;
            continue;
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(i==0 || i==n-1){
                if(i==n-1) cout<<count;
                cout<<s[i];
            }
            else{
                count++;
            }
        }
        cout<<endl;
    }
    return 0;
}