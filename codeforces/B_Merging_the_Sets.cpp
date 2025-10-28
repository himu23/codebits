//author: himu23
#include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;
// template<typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

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
#define pb push_back
#define umap unordered_map
#define f first
#define s second
#define pai pair<int,int>

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

// Custom hash for unordered_map/set
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    template<typename T, typename U>
    size_t operator()(const pair<T, U>& p) const {
        uint64_t h1 = operator()(static_cast<uint64_t>(p.first));
        uint64_t h2 = operator()(static_cast<uint64_t>(p.second));
        return h1 ^ (h2 << 1);
    }
};
struct hash_pair{
    size_t operator()(const std::pair<int, int>& p) const {
        return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
    }
};
template<typename K, typename V>
using safe_umap = unordered_map<K, V, custom_hash>;
template<typename T>
using safe_uset = unordered_set<T, custom_hash>;
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}
void add_self(int& a,int b){
    a+=b;
    if(a>=MOD) a-=MOD;
}
bool isinbounds(int x,int y,int rows,int cols){
    return x>=0 && y>=0 && x<rows && y<cols;
}
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};

void solve() {
    // int n,m; cin>>n>>m;
    // vector<vector<int>> temp (m+1);
    // vector<vector<int>> sets(n+1);
    // for(int i=1;i<=n;i++){
    //     int l; cin>>l;
    //     for(int j=0;j<l;j++){
    //         int x; cin>>x;
    //         temp[x].pb(i);
    //         sets[i].pb(x);
    //     }
    // }
    
    // for(int i=1;i<=m;i++){
    //     if(temp[i].size()==0){
    //         cout<<"NO"<<endl;
    //         return;
    //     }
    // }
    // vector<vector<int>> temp2;
    // for(int i=1;i<=m;i++){
    //     if(temp[i].size()>=3){
    //         cout<<"YES"<<endl;
    //         return;
    //     }
    //     if(temp[i].size()==2) temp2.pb(temp[i]);
    // }
    // sort(temp2.begin(),temp2.end());
    // for(int i=1;i<temp2.size();i++){
    //     if(temp2[i-1]!=temp2[i]){
    //         cout<<"YES"<<endl;
    //         return;
    //     }
    // } 
    // if(m==1 && n>=2){
    //     cout<<"YES"<<endl;
    //     return;
    // }
    // cout<<"NO"<<endl;
    // // something wrong
    int n,m; cin>>n>>m;
    vector<vector<int>> s(n);
    vector<int> temp(m+1,0);
    for(int i=0;i<n;i++){
        int l; cin>>l;
        s[i].resize(l); //important
        for(int j=0;j<l;j++){
            cin>>s[i][j];
            temp[s[i][j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        if(temp[i]==0){
            cout<<"NO"<<endl;
            return;
        }
    }
    bool flag1=false,flag2=false;
    for(int i=0;i<n;i++){
        bool flag3=false;
        int l=s[i].size();
        for(int j=0;j<l;j++){
            if(temp[s[i][j]]==1){
                flag3=true;
                break;
            }
        }
        if(flag3) continue;
        if(!flag1){
            flag1=true;
        }
        else{
            flag2=true;
            break;
        }
    }
    if(flag2){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
        //cout<<fixed<<setprecision(12)<<
    }
}