// //author: himu23
// #include <bits/stdc++.h>
// // #include<ext/pb_ds/assoc_container.hpp>
// // #include<ext/pb_ds/tree_policy.hpp>

// using namespace std;
// // using namespace __gnu_pbds;
// // template<typename T>
// // using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

// template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
// template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// void dbg_out() { cerr << endl; }
// template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
// #ifdef LOCAL
// #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
// #else
// #define dbg(...)
// #endif

// #define ar array
// #define ll long long
// #define ld long double
// #define sza(x) ((ll)x.size())
// #define all(a) (a).begin(), (a).end()
// #define pb push_back
// #define umap unordered_map
// #define fi first
// #define se second
// #define pai pair<ll,ll>

// const ll MAX_N = 1e6 + 5;
// const ll MOD = 998244353;
// const ll INF = 1e9;
// const ld EPS = 1e-9;

// // Custom hash for unordered_map/set
// struct custom_hash {
//     static uint64_t splitmix64(uint64_t x) {
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }
//     size_t operator()(uint64_t x) const {
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
//     template<typename T, typename U>
//     size_t operator()(const pair<T, U>& p) const {
//         uint64_t h1 = operator()(static_cast<uint64_t>(p.first));
//         uint64_t h2 = operator()(static_cast<uint64_t>(p.second));
//         return h1 ^ (h2 << 1);
//     }
// };
// struct hash_pair{
//     size_t operator()(const std::pair<ll, ll>& p) const {
//         return std::hash<ll>()(p.first) ^ (std::hash<ll>()(p.second) << 1);
//     }
// };
// template<typename K, typename V>
// using safe_umap = unordered_map<K, V, custom_hash>;
// template<typename T>
// using safe_uset = unordered_set<T, custom_hash>;
// ll binpow(ll a, ll b) {
//     ll res = 1;
//     while (b > 0) {
//         if (b & 1) res=(res*a)%MOD;
//         a =(a*a)%MOD;
//         b >>= 1;
//     }
//     return res;
// }
// void add_self(ll& a,ll b){
//     a+=b;
//     if(a>=MOD) a-=MOD;
// }
// bool isinbounds(ll x,ll y,ll rows,ll cols){
//     return x>=0 && y>=0 && x<rows && y<cols;
// }
// const ll dx[4]={0,1,0,-1};
// const ll dy[4]={1,0,-1,0};
// int dfs(int i,safe_umap<int,vector<int>>& um, vector<int>& dp,vector<int>& dis,vector<int>& parent){
//     if(dp[i]!=-1) return dp[i];
//     if(um[dis[i]+1].size()==0){
//         dp[i]=0;
//         return dp[i];
//     }
//     int cur=0;
//     // for(int j=0;j<distree[i].size();j++){
//     //     cur=(cur+dfs(distree[i][j],distree,dp)+1)%MOD;
//     // }
//     if(i==0){
//         for(int j=0;j<um[dis[i]+1].size();j++){
//             cur=(cur+dfs(um[dis[i]+1][j],um,dp,dis,parent)+1)%MOD;
//         }
//     }
//     else{
//         for(int j=0;j<um[dis[i]+1].size();j++){
//             if(parent[um[dis[i]+1][j]]!=i){
//                 cur=(cur+dfs(um[dis[i]+1][j],um,dp,dis,parent)+1)%MOD;
//             }
//         }
//     }
//     dp[i]=cur;
//     return dp[i];
// }
// void solve() {
//     int n; cin>>n;
//     vector<vector<int>> tree(n);
//     vector<int> parent(n);
//     parent[0]=-1;
//     for(int i=1;i<n;i++){
//         int a; cin>>a; a--;
//         parent[i]=a;
//         tree[a].pb(i);
//         tree[i].pb(a);
//     }
//     vector<int> dis(n);
//     vector<bool> visi(n,false);
//     dis[0]=0; visi[0]=true;
//     queue<int> q;
//     q.push(0);
//     while(!q.empty()){
//         int cur=q.front(); q.pop();
//         int curdis=dis[cur];
//         for(int i=0;i<tree[cur].size();i++){
//             if(!visi[tree[cur][i]]){
//                 visi[tree[cur][i]]=true;
//                 dis[tree[cur][i]]=curdis+1;
//                 q.push(tree[cur][i]);
//             }
//         }
//     }
//     // cout<<dis<<endl;
//     safe_umap<int,vector<int>> um;
//     for(int i=0;i<dis.size();i++){
//         um[dis[i]].pb(i);
//     }
//     // vector<vector<int>> distree(n);
//     // for(int i=0;i<n;i++){
//     //     if(i==0){
//     //         distree[i]=tree[i];
//     //         continue;
//     //     }
//     //     int curdis=dis[i];
//     //     vector<int> curvec=um[curdis+1];
//     //     for(int j=0;j<curvec.size();j++){
//     //         if(parent[curvec[j]]!=i) distree[i].pb(curvec[j]);
//     //     }
//     // }
//     // cout<<distree<<endl;
//     vector<int> dp(n,-1);
//     cout<<dfs(0,um,dp,dis,parent)+1<<endl;
// }

// int32_t main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     int tc = 1;
//     cin >> tc;
//     for (int t = 1; t <= tc; t++) {
//         // cout << "Case #" << t << ": ";
//         solve();
//         //cout<<fixed<<setprecision(12)<<
//     }
// }
//tle
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

const ll MAX_N = 1e6 + 5;
// const ll MOD = 1e9 + 7;
const ll MOD = 998244353;
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
ll getdis(ll i,vector<ll>&dis,vector<ll>&parent){
    if(dis[i]!=-1) return dis[i];
    return getdis(parent[i],dis,parent)+1;
}
void solve(){
    ll n; cin>>n;
    vector<vector<ll>> tree(n);
    vector<ll> parent(n);
    parent[0]=-1;
    for(ll i=1;i<n;i++){
        ll a; cin>>a; a--;
        parent[i]=a;
        tree[a].pb(i);
        tree[i].pb(a);
    }
    vector<ll> dis(n,-1);
    // vector<bool> visi(n,false);
    // dis[0]=0; visi[0]=true;
    // queue<ll> q;
    // q.push(0);
    // while(!q.empty()){
    //     ll cur=q.front(); q.pop();
    //     ll curdis=dis[cur];
    //     for(ll i=0;i<tree[cur].size();i++){
    //         if(!visi[tree[cur][i]]){
    //             visi[tree[cur][i]]=true;
    //             dis[tree[cur][i]]=curdis+1;
    //             q.push(tree[cur][i]);
    //         }
    //     }
    // }
    dis[0]=0;
    for(int i=0;i<n;i++){
        dis[i]=getdis(i,dis,parent);
    }
    // cout<<dis<<endl;
    // safe_umap<ll,vector<ll>> um;
    ll maxdepth=0;
    for(ll i=0;i<n;i++){
        maxdepth=max(maxdepth,dis[i]);
    }
    vector<vector<ll>> um(maxdepth+1);
    ll maxx=0;
    for(ll i=0;i<dis.size();i++){
        um[dis[i]].pb(i);
        maxx=max(maxx,dis[i]);
    }
    vector<ll> dp(n);
    vector<ll> layerdp(maxx+1,0);
    dp[0]=1,layerdp[0]=1;
    for(ll i=0;i<um[1].size();i++){
        dp[um[1][i]]=1;
        layerdp[1]=(layerdp[1]+dp[um[1][i]])%MOD;
    }
    for(ll i=2;i<=maxx;i++){
        for(ll j=0;j<um[i].size();j++){
            dp[um[i][j]]=((layerdp[i-1]-dp[parent[um[i][j]]]+MOD)%MOD+MOD)%MOD;//notice when subrstrction and mod
            layerdp[i]=(layerdp[i]+dp[um[i][j]])%MOD;
        }
    }
    ll ans=0;
    for(ll i=0;i<n;i++) ans=(ans+dp[i])%MOD;
    cout<<ans<<'\n';
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