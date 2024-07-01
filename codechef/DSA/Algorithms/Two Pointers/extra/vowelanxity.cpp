#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin>>k;
    while(k--){
        int n;
        cin>>n;
        vector<char>s(n);
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        vector<char>t(n);
        int l=0,r=n-1;
        bool temp=false;
        for(int i=n-1;i>=0;i--){
            if(temp){
                t[l++]=s[i];
            }
            else{
                t[r--]=s[i];
            }
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                temp=!temp;
            }
        }
        for(int i=0;i<n;i++){
            cout<<t[i];
        }
        cout<<endl;
    }

}