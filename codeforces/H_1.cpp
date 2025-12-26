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
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
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

void solve() {
    int n; cin>>n;
    vector<vector<int>> grid(n,vector<int>(3));
    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            cin>>grid[j][i];
        }
    }
    //boolean satisfiability(SAT)
    //2-sat problem
    //the standard SAT (3-SAT) is NP-complete(unsolvable efficiently).
    //but, 2-SAT(where every constraint involves at most two variables) is solvable in linear time O(N+M)
    //using graph theory

    //atleast two must be true == (xvy)^(yvz)^(zvx)
    // safe_umap<int,vector<int>> um;
    // for(int i=0;i<n;i++){
    //     vector<int> cur=grid[i];
    //     um[cur[0]].pb(cur[1]);
    //     // um[cur[1]].pb(cur[0]);
    //     // um[cur[0]].pb(cur[2]);
    //     um[cur[2]].pb(cur[0]);
    //     um[cur[1]].pb(cur[2]);
    //     // um[cur[2]].pb(cur[1]);
    // }
    // safe_umap<int,bool> visi;
    // for(int i=1;i<=n;i++){
    //     visi[i]=false;
    //     visi[-1*i]=false;
    // }
    // vector<vector<int>> compos;
    // for(int i=-n;i<=n;i++){
    //     if(i==0) continue;
    //     if(visi[i]) continue;
    //     vector<int> compo;
    //     compo.pb(i);
    //     visi[i]=true;
    //     queue<int> q;
    //     q.push(i);
    //     while(!q.empty()){
    //         int cur=q.front();q.pop();
    //         for(int j=0;j<um[cur].size();j++){
    //             if(!visi[um[cur][j]]){
    //                 visi[um[cur][j]]=true;
    //                 compo.pb(um[cur][j]);
    //                 q.push(um[cur][j]);
    //             }
    //         }
    //     }
    //     compos.pb(compo);
    // }
    // for(int i=0;i<compos.size();i++){
    //     vector<int> compo=compos[i];
    //     set<int> sett;
    //     for(int j=0;j<compo.size();j++){
    //         if(sett.find(abs(compo[j]))!=sett.end()){
    //             cout<<"NO"<<endl;
    //             return;
    //         }
    //         sett.insert(abs(compo[j]));
    //     }
    // }
    // cout<<"YES"<<endl;

    //wont work
    //for strongly connected components (scc)
    //is a maximal set of vertices such that for every pair of vertices u,v in the set
    //there is a path from u to v and a path from v to u
    //contract each scc into a single super-node; the resulting graph is always a 
    //DAG(directed acyclic graph)
    //find scc->build the dag->do dp or topological sort on the dag

    //two main algos to find SCCs

    //kosaraju's algo(two pass dfs)
    //it relies on the fact that if you transpose the graph(reverse all the edges), the SCCs 
    //remain exactly the same
    //1) first pass(DFS) perform a standard DFS. store vertices in a list/stack based on
    // their finishing time(when recursion returns)
    //2) transpose: reverse all the edges in the graph(G->G^T)
    //3) second pass(DFS): pop vertices from the stack(highest finish time first) and perform
    // DFS on G^T. each successful search yields one SCC.

    //Tarjan's Algorithm(single-pass dfs)
    //this uses the concept of discovery_time and low_link value(similar to finding bridges/articulation points)
    //1) maintain a stack of currently active nodes and track vis(on stack);
    //2) dfs: for node u, initialize low[u]=disc[u]
    //3) tree edge: if v is a child, DFS to it, then low[u]=min(low[u],disc[v]);
    //4) back edge: if v is already visited and on the stack, low[u]=min(low[u],disc[v]);
    //5) root of SCC: if low[u]==disc[u], then u is the "root" of an SCC. pop elements from the stack
    //until u is popped this will form the scc.
    
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