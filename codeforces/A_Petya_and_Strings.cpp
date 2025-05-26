#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    string s,t;
    cin>>s>>t;
    int n=s.length();
    for(int i=0;i<n;i++){
        char c=s[i],d=t[i];
        int a=static_cast<int>(c);
        int b=static_cast<int>(d);
        if(a>90) a=a-32;
        if(b>90) b=b-32;
        if(a==b){
            if(i==n-1){
                cout<<0;
                break;
            }
            continue;
        }
        if(a>b){
            cout<<1;
            break;
        }
        else if(b>a){
            cout<<-1;
            break;
        }
    }
    return 0;
}