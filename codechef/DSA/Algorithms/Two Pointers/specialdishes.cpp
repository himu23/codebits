//1760
//proud...really proud of myself
//this thing took a while...my longest dsa code till now i guess
#include <bits/stdc++.h>
using namespace std;

bool isspecial(string s){
    int n=s.length();
    if(n%2==1){
        return false;
    }
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n/2 +i]){
            return false;
        }
    }
    return true;
}
bool spsub(string s,string t){
    int n=s.length(),m=t.length();
    if(m<n){
        string temp=s;
        s=t;
        t=temp;
    }
    n=s.length(),m=t.length();
    int i=0,j=0;
    int count=0;
    while(i<n && j<m){
        if(s[i]==t[j]){
            i++,j++;
        }
        if(s[i]!=t[j]){
            j++;
            count++;
        }
    }
    if(count>1){
        return false;
    }
    else{
        return true;
    }
}
int main() {
    int k;
    cin >> k;
    while (k--) {
        string s;
        cin>>s;
        int n=s.length();
        if(n==1){
            cout<<"NO"<<endl;
            continue;
        }
        if(n%2==0){
            if(isspecial(s)){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else{
            int m=n/2;
            string so=s.substr(0,n/2),sc=s.substr(n/2,(n/2)+1);
            string st=s.substr(0,(n/2)+1),sf=s.substr((n/2)+1,n/2);
            if(spsub(so,sc) || spsub(st,sf)){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}