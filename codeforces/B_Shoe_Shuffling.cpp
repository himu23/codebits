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
    int n; cin>>n;
    vector<int> a(n);
    unordered_map<int,int> um;
    unordered_map<int,vector<int>> temp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        um[a[i]]++;
        temp[a[i]].push_back(i+1);
    }
    for(const auto& pair : um){
        if(pair.second<2){
            cout<<-1<<endl;
            return;
        }
    }
    for(auto& pair : temp){
        int temp3=pair.second[0];
        for(int i=0;i<pair.second.size()-1;i++){
            pair.second[i]=pair.second[i+1];
        }
        pair.second[pair.second.size()-1]=temp3;
    }
    for(int i=0;i<n;i++){
        cout<<temp[a[i]][0]<<" ";
        temp[a[i]].erase(temp[a[i]].begin());
    }
    cout<<endl;
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