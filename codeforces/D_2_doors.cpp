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
const ll INF = 1e18;
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
bool isinbounds(ll x,ll y,ll rows,ll cols){
    return x>=0 && y>=0 && x<rows && y<cols;
}
const ll dx[4]={0,1,0,-1};
const ll dy[4]={1,0,-1,0};
ll modinverse(ll n){
    return binpow(n,MOD-2);
}

const ll MAXN = 1e6+5;

// void solve() {
//     ll n,q; cin>>n>>q;
//     vector<vector<pair<ll,ll>>> adj(n);
//     vector<vector<ll>> temp(n,vector<ll>(31,3));
//     while(q--){
//         ll i,j,x; cin>>i>>j>>x;
//         i--,j--;
//         // adj[i].pb(j);
//         // adj[j].pb(i);
//         for(ll k=0;k<31;k++){
//             if(i==j && (x&(1LL<<k))) {temp[i][k]=1;continue;}
//             if((x&(1LL<<k))==0){
//                 temp[i][k]=0;
//                 temp[j][k]=0;
//             }
//             else{
//                 if(temp[i][k]!=0 && temp[i][k]!=1) {temp[i][k]=2;adj[i].pb({j,k});}
//                 if(temp[j][k]!=0 && temp[j][k]!=1) {temp[j][k]=2;adj[j].pb({i,k});}
//             }
//         }
//     }
//     for(ll i=0;i<n;i++){
//         for(ll j=0;j<31;j++){
//             if(temp[i][j]==0 || temp[i][j]==1) continue;
//             if(temp[i][j]==2){
//                 bool flag=false;
//                 for(auto [x,k]:adj[i]){
//                     if(k!=j) continue;
//                     if(temp[x][j]==0){
//                         flag=true;break;
//                     }
//                 }
//                 if(!flag) temp[i][j]=0;
//                 else temp[i][j]=1;
//             }
//         }
//     }
//     for(ll i=0;i<n;i++){
//         for(ll j=0;j<31;j++){
//             if(temp[i][j]==3) temp[i][j]=0;
//         }
//     }
//     for(ll i=0;i<n;i++){
//         ll cur=0;
//         for(ll j=0;j<31;j++){
//             cur+=(1LL<<j)*temp[i][j];
//         }
//         cout<<cur<<" ";
//     }
//     cout<<endl;
// }
//mle
//do the entire steps for each bit dont store to reduce memory
struct query{
    ll uu,vv,xx;
};
void solve(){
    ll n,q; cin>>n>>q;
    vector<query> queries(q);
    for(ll i=0;i<q;i++){
        cin>>queries[i].uu>>queries[i].vv>>queries[i].xx;
        queries[i].uu--;queries[i].vv--;
    }
    vector<ll> ans(n,0);
    vector<vector<ll>> adj(n);
    vector<ll> temp(n,3);
    //build ans[i] for each query
    for(ll b=0;b<31;b++){
        for(int i=0;i<n;i++){
            adj[i].clear();
            temp[i]=3;
        }
        for(ll i=0;i<q;i++){
            auto [u,v,x]=queries[i];
            if(u==v && (x&(1LL<<b))) {temp[u]=1;continue;}
            if((x&(1LL<<b))==0){
                temp[u]=0;
                temp[v]=0;
            }
            else{
                if(temp[u]!=0 && temp[u]!=1) {temp[u]=2;adj[u].pb(v);}
                if(temp[v]!=0 && temp[v]!=1) {temp[v]=2;adj[v].pb(u);}
            }
        }
        for(ll u=0;u<n;u++){
            if(temp[u]==0 || temp[u]==1) continue;
            if(temp[u]==2){
                bool flag=false;
                for(auto v:adj[u]){
                    // if(k!=j) continue;
                    if(temp[v]==0){
                        flag=true;break;
                    }
                }
                if(!flag) temp[u]=0;
                else temp[u]=1;
            }
        }
        for(ll i=0;i<n;i++){
            if(temp[i]==3) temp[i]=0;
        }
        for(ll i=0;i<n;i++){
            if(temp[i]==1) ans[i]^=(1LL<<b);
        }
    }
    //
    for(ll i=0;i<n;i++){
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