#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int testcases; testcases=1;
    cin>>testcases;
    while(testcases--){
        int n,q; cin>>n>>q;
        vector<int> a(n);
        vector<int> b;
        int total=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            total+=a[i];
            b.push_back(total);
        }
        //cout<<total<<" ";
        bool totaliseven=true;
        if(total%2!=0) totaliseven=false;
        //cout<<totaliseven<<" ";
        while(q--){
            int l,r,k;
            cin>>l>>r>>k;
            l--,r--;
            k=k*(r-l+1);
            //cout<<l<<" "<<r<<" "<<k<<" ";
            int temp;
            if(l==0) temp=b[r];
            else temp=b[r]-b[l-1];
            //cout<<temp<<" ";
            bool kiseven=true;
            if(k%2!=0) kiseven=false;
            //cout<<kiseven<<" ";
            bool tempiseven=true;
            if(temp%2!=0) tempiseven=false;
            //cout<<tempiseven<<" ";
            bool temp2=totaliseven;
            if(tempiseven != kiseven) temp2=!temp2;
            if(temp2) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
    return 0;
}