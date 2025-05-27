#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int testcases; testcases=1;
    cin>>testcases;
    while(testcases--){
        int n,k,x; cin>>n>>k>>x;
        if(x!=1){
            cout<<"YES"<<endl;
            cout<<n<<endl;
            for(int i=0;i<n;i++){
                cout<<1<<" ";
            }
            cout<<endl;
        }
        else{
            if(k==1) cout<<"NO"<<endl;
            else if(k==2){
                if(n%2!=0) cout<<"NO"<<endl;
                else{
                cout<<"YES"<<endl;
                cout<<n/2<<endl;
                for(int i=0;i<n/2;i++) cout<<2<<" ";
                cout<<endl;
                }
            }
            else{
                if(n==1) cout<<"NO"<<endl;
                else{
                    cout<<"YES"<<endl;
                    if(n%2==0){
                        cout<<n/2<<endl;
                        for(int i=0;i<n/2;i++) cout<<2<<" ";
                        cout<<endl;
                    }
                    else{
                        cout<<(n-3)/2+1<<endl;
                        cout<<3<<" ";
                        for(int i=0;i<(n-3)/2;i++) cout<<2<<" ";
                        cout<<endl;
                    }
                }
            }
        }
    }
    return 0;
}