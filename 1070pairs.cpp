//found the logic after stairing the screen for one whole hour
//A post on facebook is said to be more popular if the number of likes on the post is strictly greater than the number of likes on some other post. In case the number of likes is same, the post having more comments is more popular.
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n],b[n],c[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        int q=a[0], w=b[0];
        for(int i=0; i<n; i++){
            if(a[i]>=q){
                q=a[i];
            }
        }
        for(int i=0;i<n;i++){
            if(a[i]==q){
                c[i]=b[i];
            }
            else{
                c[i]=0;
            }
        }
        int e=c[0];
        for(int i=0; i<n;i++){
            if(c[i]>e){
                e=c[i];
            }
        }
        for(int i=0; i<n;i++){
            if(c[i]==e){
                cout<<i+1<<endl;
            }
        }
        
    }

}
