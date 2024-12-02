#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    //cin>>k;
    while(k--){
        int n; cin>>n;
        // if(n==1 || n==2 || n==3){
        //     cout<<-1<<endl;
        // }
        // else if(n%2==0){
        //     cout<<n<<" "<<n/2<<endl;
        // }
        // else{
        //     cout<<n-1<<" "<<(n-1)/2<<endl;
        // }
        bool flag=false;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i*j>n && i%j==0 && i/j<n){
                    cout<<i<<" "<<j<<endl;
                    flag=true;
                    return 0;
                }
            }
        }
        if(!flag){
            cout<<-1<<endl;
        }
        // if(n==1 || n==2 || n==3){
        //     cout<<-1<<endl;
        // }
        // else{
        //     cout<<n<<" "<<n<<endl;
        // }
    }
    return 0;
}