#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int a=0, b=0;
        char c='A';
        for(int i=0; i<n; i++){
            if(c=='A'){
            if(s[i]==c){
                a++;
            }
            else{
                c='B';
            }
            }
            else if(c=='B'){
               if(s[i]==c){
                b++;
            }
            else{
                c='A';
            } 
            }
        }
        cout<<a<<" "<<b<<endl;
    }

}
