//can be done directly by doing some maths
//ans=ceil((n-1+0.34949)/0.20899)
//this give the correct ans directly for large n;

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> vecsum(vector<int>& v1, vector<int>& v2){
    vector<int>ans;
    int carry=0;
    for(int i=0;i<v2.size();i++){
        int sum=v1[i]+v2[i]+carry;
        ans.push_back(sum%10);
        carry=sum/10;
    }
    for(int i=v2.size();i<v1.size();i++){
        int sum=v1[i]+carry;
        ans.push_back(sum%10);
        carry=sum/10;
    }
    while(carry>0){
        int sum=carry;
        ans.push_back(sum%10);
        carry=sum/10;
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    //int n; cin>>n;
    vector<vector<int>>fib(5001);
    fib[1]={1};
    fib[2]={1};
    for(int i=3;i<=5000;i++){
        fib[i]=vecsum(fib[i-1],fib[i-2]);
        if(fib[i].size()==1000){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}