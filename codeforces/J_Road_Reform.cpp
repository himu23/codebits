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

const ll MAXN = 1e6+5;

struct edge{
    ll u,v,w;
    bool operator<(const edge& other) const{
        return w<other.w;
    }
};

struct DSU {
    vector<ll> parent;
    vector<ll> size;
    ll noofcompo;
    //constructor: initialize parent as itself and size as 1
    DSU(ll n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        iota(parent.begin(), parent.end(), 0); 
        noofcompo=n;
    }

    //find function with path compression
    ll find(ll i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); 
    }

    //unite function with union by size
    //returns true if a merge happened, false if already in same set
    bool unite(ll i, ll j) {
        ll root_i = find(i);
        ll root_j = find(j);

        if (root_i != root_j) {
            // Attach smaller tree to larger tree
            if (size[root_i] < size[root_j])
                swap(root_i, root_j);
            
            parent[root_j] = root_i;
            size[root_i] += size[root_j];
            noofcompo--;
            return true;
        }
        return false;
    }
};
//how to use it
// ll main() {
//     ll n = 5;
//     DSU dsu(n);

//     dsu.unite(1, 2);
//     dsu.unite(2, 3);

//     //check if connected
//     if (dsu.find(1) == dsu.find(3)) {
//         cout << "1 and 3 are in the same component" << endl;
//     }
    
//     //check size of a component
//     cout << "size of component containing 1: " << dsu.size[dsu.find(1)] << endl;
    
//     return 0;
// }
void solve() {
    ll n,m,k; cin>>n>>m>>k;
    vector<vector<pair<ll,ll>>> adj(n);
    vector<edge> edges;
    vector<vector<ll>> adj2(n);
    vector<bool> temp(n,false);
    ll minn=INT_MAX;
    for(ll i=0;i<m;i++){
        ll x,y,s; cin>>x>>y>>s;
        x--,y--;
        edges.pb({x,y,s});
        adj[x].pb({y,s});
        adj[y].pb({x,s});
        if(s<=k){
            temp[x]=true;
            temp[y]=true;
            adj2[x].pb(y);
            adj2[y].pb(x);
        }
        minn=min(minn,abs(s-k));
    }
    bool flag=true;
    // ll compo=0;
    // for(ll i=0;i<n;i++){
    //     if(!temp[i]) continue;
    //     compo++;
    //     queue<ll> q;
    //     q.push(i);
    //     temp[i]=false;
    //     while(!q.empty()){
    //         ll cur=q.front();q.pop();
    //         for(ll x: adj2[cur]){
    //             if(temp[x]){
    //                 temp[x]=false;
    //                 q.push(x);
    //             }
    //         }
    //     }
    // }
    // if(compo>1) flag=false;
    DSU dsu1(n);
    for(edge e: edges){
        if(e.w<=k){
            dsu1.unite(e.u,e.v);
        }
    }
    if(dsu1.noofcompo!=1) flag=false;
    if(!flag){
        for(ll i=0;i<edges.size();i++){
            edges[i].w=max(0LL,edges[i].w-k);
        }
        sort(edges.begin(),edges.end());
        DSU dsu(n);
        ll mst=0;
        // ll edgecnt=0;
        for(edge e: edges){
            if(dsu.unite(e.u,e.v)){
                mst+=e.w;
                // edgecnt++;
            }
        }
        cout<<mst<<endl;
        return;
    }
    cout<<minn<<endl;
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