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
#define sza(x) ((ll)x.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define umap unordered_map
#define fi first
#define se second
#define pai pair<ll,ll>
#define cntbit(x) __builtin_popcount(x)

const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
const ll INF = 1e9;
const ld EPS = 1e-9;

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
    size_t operator()(const std::pair<ll, ll>& p) const {
        return std::hash<ll>()(p.first) ^ (std::hash<ll>()(p.second) << 1);
    }
};
template<typename K, typename V>
using safe_umap = unordered_map<K, V, custom_hash>;
template<typename T>
using safe_uset = unordered_set<T, custom_hash>;
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res=(res*a)%MOD;
        a =(a*a)%MOD;
        b >>= 1;
    }
    return res;
}
void add_self(ll& a,ll b){
    a+=b;
    if(a>=MOD) a-=MOD;
}
bool isinbounds(ll x,ll y,ll rows,ll cols){
    return x>=0 && y>=0 && x<rows && y<cols;
}
const ll dx[4]={0,1,0,-1};
const ll dy[4]={1,0,-1,0};
ll modinverse(ll n){
    return binpow(n,MOD-2);
}

const ll MAXN = 2004;
//i hate dfs
vector<vector<int>> adj(MAXN);
vector<int> c(MAXN),p(MAXN);
bool flag=true;
vector<int> ans(MAXN);
// vector<pair<int,int>> dfs(int i,int par){
//     vector<pair<int,int>> nodes;
//     for(int j:adj[i]){
//         if(j!=par){
//             vector<pair<int,int>> chi=dfs(j,i);
//             nodes.insert(nodes.end(),chi.begin(),chi.end());
//         }
//     }
//     sort(nodes.begin(),nodes.end());
//     if(c[i]>nodes.size()){
//         flag=false;
//         nodes.emplace_back(i,i);
//         return nodes;
//     }
//     if(c[i]==0){
//         if(nodes.empty()){
//             nodes.emplace_back(i,i);
//         }
//         else{
//             nodes.emplace_back(nodes.front().fi-1,i);
//         }
//     }
//     else{
//         int newval=nodes[c[i]-1].fi+1;
//         for(int i=c[i];i<nodes.size();i++){
//             nodes[i].fi+=2;
//         }
//         nodes.emplace_back(newval,i);
//     }
//     sort(nodes.begin(),nodes.end());
//     return nodes;
// }
vector<int> dfs(int i){
    vector<int> nodes;
    for(int j:adj[i]){
        vector<int> childnodes=dfs(j);
        nodes.insert(nodes.end(),childnodes.begin(),childnodes.end());
    }
    if(c[i]>nodes.size()){
        flag=false;
        return {};
    }
    nodes.insert(nodes.begin()+c[i],i);
    return nodes;
}
void solve() {
    int n; cin>>n;
    for(int i=0;i<=n;i++) adj[i].clear();
    flag=true;
    // vector<int> p(n),c(n);
    // vector<vector<int>> tree(n);
    int root=-1;
    for(int i=1;i<=n;i++){
        cin>>p[i]>>c[i];
        adj[p[i]].pb(i);
        if(p[i]==0) root=i;
        // adj[i].pb(p[i]);
    }
    vector<int> result=dfs(root);
    if(!flag){
        cout<<"NO"<<endl;
        return;
    }
    // vector<int> nodeorder(n+1);
    // int minval=0;
    // for(auto [value,node]:result){
    //     nodeorder[node]=value;
    //     minval=min(minval,value);
    // }
    cout<<"YES"<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<nodeorder[i]-minval+1<<" ";
    // }
    for(int i=0;i<n;i++){
        ans[result[i]]=i+1;
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
        //cout<<fixed<<setprecision(12)<<
    }
}