#include <bits/stdc++.h>

using namespace std;

int main() {
    // Write your code here
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int pone =0;
    int fone=0;
    int curzero=0;
    int zero=0;
    int ans=0;
    int i=0;
    while(i<n){
        while(i<n && a[i]==0){
            curzero++;
            zero++;
            i++;
        }
        while(i<n && a[i]==1){
            fone++;
            i++;
        }
        ans=max(ans,curzero+pone+fone);
        pone=fone;
        curzero=0;
        fone=0;
    }
    if(ans==n && zero==0) cout<<ans-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
