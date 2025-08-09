#include <bits/stdc++.h>
using namespace std;
vector<int> solve(string s){
    vector<int> ans;
    stringstream ss(s);
    string numStr;
    while(getline(ss,numStr,',')){
        int num=stoi(numStr);
        ans.push_back(num);
    }
    return ans;
}
int main() {
    string s; cin>>s;
    //
    return 0;
}