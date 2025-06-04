#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {
    string temp; cin>>temp;
    int ops1=0;
    string s=temp;
    while(!s.empty() && s.back()!='5'){
        s.pop_back();
        ops1++;
    }
    if(!s.empty()) s.pop_back();
    while(!s.empty() && !(s.back()=='2')){
        s.pop_back();
        ops1++;
    }
    s=temp;
    int ops2=0;
    while(!s.empty() && s.back()!='5'){
        s.pop_back();
        ops2++;
    }
    if(!s.empty()) s.pop_back();
    while(!s.empty() && !(s.back()=='7')){
        s.pop_back();
        ops2++;
    }
    s=temp;
    int ops3=0;
    while(!s.empty() && s.back()!='0'){
        s.pop_back();
        ops3++;
    }
    if(!s.empty()) s.pop_back();
    while(!s.empty() && !(s.back()=='0')){
        s.pop_back();
        ops3++;
    }
    s=temp;
    int ops4=0;
    while(!s.empty() && s.back()!='0'){
        s.pop_back();
        ops4++;
    }
    if(!s.empty()) s.pop_back();
    while(!s.empty() && !(s.back()=='5')){
        s.pop_back();
        ops4++;
    }
    vector<int> ans;
    ans.push_back(ops1);
    ans.push_back(ops2);
    ans.push_back(ops3);
    ans.push_back(ops4);
    int ans2=INT_MAX;
    for(int i=0;i<ans.size();i++){
        ans2=min(ans2,ans[i]);
    }
    cout<<ans2<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}