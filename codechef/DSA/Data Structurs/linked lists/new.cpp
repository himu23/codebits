#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int countcost(string s){
    int n=s.length();
    int cost=0;
    vector<int>temp;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            temp.push_back(i);
        }
        else{
            cost+=(i-temp.back());
            temp.pop_back();
        }
    }
    return cost;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    cin>>k;
    while(k--){
        int n; cin>>n;
        string s;
        cin>>s;
        int b=0,c=0;
        for(int i=0;i<n;i++){
            if(s[i]==')') b++;
            else if(s[i]=='(') c++;
        }
        cout<<countcost(s)<<endl;
    }
    return 0;
}