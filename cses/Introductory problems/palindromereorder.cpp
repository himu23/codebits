#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string revstr(string s){
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.length();
    unordered_map<char, int> um;
    for (int i = 0; i < n; i++) {
        um[s[i]]++;
    }
    int count_odd = 0;
    for (auto it = um.begin(); it != um.end(); ++it) {
        int x = it->second;
        if (x % 2 != 0) count_odd++;
    }
    if (count_odd > 1) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    string half = "", oddc = "";
    for (auto it = um.begin(); it != um.end(); ++it) {
        int x = it->second;
        if (x % 2 != 0) oddc = it->first;
        for (int j = 0; j < x / 2; ++j) {
            half += it->first;
        }
    }
    
    string ans = half;
    if (!oddc.empty()) {
        ans += oddc;
    }
    ans += revstr(half);
    
    cout << ans << endl;
    return 0;
}
