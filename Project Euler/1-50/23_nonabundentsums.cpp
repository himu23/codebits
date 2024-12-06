#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isabundant(int n){
    int sum=1;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            sum+=i+n/i;
            if(i*i==n) sum-=i;
        }
    }
    if(sum>n) return true;
    else return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n=28123;
    vector<int>abun;
    for(int i=10;i<=28123;i++){
        if(isabundant(i)){
            abun.push_back(i);
        }
    }
    set<int>abunsums;
    for(int i=0;i<abun.size()-1;i++){
        for(int j=i;j<abun.size();j++){
            int sum=abun[i]+abun[j];
            if(sum<=28123){
                abunsums.insert(sum);
            }
        }
    }
    int abunsum=0;
    for(auto it= abunsums.begin(); it!=abunsums.end(); ++it){
        abunsum+=*it;
    }
    int ans=28123*28124/2;
    cout<<ans-abunsum<<endl;

    return 0;
}