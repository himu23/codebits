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
    string s,t; cin>>s>>t;
    int n,m;
    n=s.length(), m=t.length();
    unordered_map<char,vector<int>> sf;
    unordered_map<char,int> tf;
    for(int i=0;i<n;i++){
        sf[s[i]].push_back(i);
    }
    for(int i=0;i<m;i++){
        auto it=sf.find(t[i]);
        if(it==sf.end()){
            cout<<"NO"<<endl;
            return;
        }
        tf[t[i]]++;
    }
    vector<int> temp;
    for(int i=0;i<m;i++){
        if(sf[t[i]].size()<tf[t[i]]){
            cout<<"NO"<<endl;
            return;
        }
        if(tf[t[i]]>=0){
            temp.push_back(sf[t[i]][sf[t[i]].size()-tf[t[i]]]);
            tf[t[i]]--;
        }

    }
    bool flag=true;
    for(int i=0;i<temp.size()-1;i++){
        if(temp[i]>temp[i+1]){
            flag=false;
            break;
        }
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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