#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin>>k;
    while(k--){
        int n,y;
        cin>>n>>y;
        int a[n];
        cin>>a[0];
        int ans = a[0];
        for(int i=1;i<n;i++){
            cin>>a[i];
            ans= ans | a[i];
        }
        if((ans|y)!=y){
            cout<<-1<<endl;
        }
        else{
            cout<<y-ans<<endl;
        }
        
    }

}
