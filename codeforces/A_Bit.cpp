#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    cin>>k;
    int x=0;
    while(k--){
        string s;
        cin>>s;
        for(int i=0;i<2;i++){
            if(s[i]=='+' && s[i+1]=='+') x++;
            else if(s[i]=='-' && s[i+1]=='-') x--;
        }
    }
    cout<<x<<endl;
    return 0;
}