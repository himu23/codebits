#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int testcases; testcases=1;
    cin>>testcases;
    while(testcases--){
        int a,b; cin>>a>>b;
        int xk,yk; cin>>xk>>yk;
        int xq,yq; cin>>xq>>yq;
        set<vector<int>> king, queen;
        king.insert({xk+a,yk+b});
        king.insert({xk-a,yk+b});
        king.insert({xk+a,yk-b});
        king.insert({xk-a,yk-b});
        king.insert({xk+b,yk+a});
        king.insert({xk-b,yk+a});
        king.insert({xk+b,yk-a});
        king.insert({xk-b,yk-a});
        //
        queen.insert({xq+a,yq+b});
        queen.insert({xq-a,yq+b});
        queen.insert({xq+a,yq-b});
        queen.insert({xq-a,yq-b});
        queen.insert({xq+b,yq+a});
        queen.insert({xq-b,yq+a});
        queen.insert({xq+b,yq-a});
        queen.insert({xq-b,yq-a});
        //
        vector<vector<int>> common;
        std::set_intersection(
            king.begin(), king.end(),
            queen.begin(), queen.end(),
            std::back_inserter(common)
        );
        cout<<common.size()<<endl;
    }
    return 0;
}