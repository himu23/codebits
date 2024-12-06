#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int recuringcycle(int n){
    unordered_map<int,int>um;
    int a=1;
    int i=1;
    while(true){
        int rem=a%n;
        if(um.count(rem)){
            return i-um[rem];
        }
        um[rem]=i;
        i++;
        a=rem*10;
    }
} 

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n; cin>>n;
    vector<int>inrec(n);
    for(int i=2;i<n;i++){
        inrec[i]=recuringcycle(i);
    }
    int ans=0,index=0;
    for(int i=2;i<1000;i++){
        if(inrec[i]>=ans){
            ans=inrec[i];
            index=i;
        }
    }
    cout<<index<<endl;
    return 0;
}