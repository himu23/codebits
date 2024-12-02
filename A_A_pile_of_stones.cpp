#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    //cin>>k;
    while(k--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int temp=0;
        int a=0;
        for(int i=0;i<n;i++){
            if(s[i]=='+'){
                temp++;
            }
            else{
                temp--;
                if(temp<0){
                    a++;
                    temp=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]=='+') a++;
            else a--;
        }
        cout<<a<<endl;
    }
    return 0;
}