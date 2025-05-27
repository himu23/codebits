#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int testcases; testcases=1;
    cin>>testcases;
    while(testcases--){
        int n; cin>>n;
        vector<int> a(n);
        unordered_map<int,int> um;
        for(int i=0;i<n;i++){
            cin>>a[i];
            um[a[i]]++;
        }
        if(um.size()==1){
            cout<<"yes"<<endl;
            continue;
        }
        if(um.size()>=3){
            cout<<"no"<<endl;
            continue;
        }
        else if(um.size()==2){
            auto it=um.begin();
            int p=it->second;
            it++;
            int q=it->second;
            if(n%2==0){
                if(p==n/2 && q==n/2){
                    cout<<"yes"<<endl;
                }
                else cout<<"no"<<endl;
            }
            else{
                if(max(p,q)==n/2+1 && min(p,q)==n/2){
                    cout<<"yes"<<endl;
                }
                else cout<<"no"<<endl;
            }
        }
    }
    return 0;
}