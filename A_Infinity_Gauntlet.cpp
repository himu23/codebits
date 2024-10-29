#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    //cin>>k;
    while(k--){
        int n; cin>>n;
        unordered_set<string> present_colors;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            present_colors.insert(s);
        }
        unordered_map<string,string> stones={
            {"purple", "Power"},{"green", "Time"},
            {"blue", "Space"},{"orange", "Soul"},
            {"red", "Reality"},{"yellow", "Mind"}
        };
        vector<string>missing_gems;
        for(const auto& gem:stones){
            if(present_colors.find(gem.first)==present_colors.end()){
                missing_gems.push_back(gem.second);
            }
        }
        cout<<missing_gems.size()<<endl;
        for(const string& gem:missing_gems){
            cout<<gem<<endl;
        }

    }
    return 0;
}