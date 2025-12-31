#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> stack;
    for(int i=0;i<n;i++){
        while(!stack.empty() && a[i]>stack.back()) stack.pop_back();
        if(stack.empty()) {cout<<-1<<endl;stack.push_back(a[i]); continue;}
        cout<<stack.back()<<" ";
        stack.push_back(a[i]);
    }
    cout<<endl;
    return 0;
}