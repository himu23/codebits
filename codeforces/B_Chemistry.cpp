#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int testcases; testcases=1;
    cin>>testcases;
    while(testcases--){
        int n,k; cin>>n>>k;
        string s; cin>>s;
        unordered_map<char,int> um;
        for(int i=0;i<n;i++){
            um[s[i]]++;
        }
        int count=0;
        for(auto it=um.begin();it!=um.end();it++){
            if((it->second)%2!=0){
                count++;
            }
        }
        //cout<<count-k<<" ";
        if(count-k==1 || count-k<=0){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
        cout<<endl;
    }
    return 0;
}