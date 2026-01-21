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

const ll MAXN = 1e6 + 5;

void solve() {
    int n; cin>>n;
    vector<vector<int>> tree(n);
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        u--,v--;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    //iterating back from the max dist that is the diameter if a vertix gets disconnected
    //it never connects back
    vector<int> temp(n,0);
    vector<int> dist0(n,-1);
    dist0[0]=0;
    queue<int> q;
    q.push(0);
    int maxx=0,v1=0;
    while(!q.empty()){
        int cur=q.front();q.pop();
        for(int i=0;i<tree[cur].size();i++){
            if(dist0[tree[cur][i]]==-1){
                dist0[tree[cur][i]]=dist0[cur]+1;
                q.push(tree[cur][i]);
                if(dist0[tree[cur][i]]>maxx){
                    maxx=dist0[tree[cur][i]];
                    v1=tree[cur][i];
                }
            }
        }
    }
    vector<int> dist1(n,-1);
    dist1[v1]=0;
    queue<int> q1;
    q1.push(v1);
    int maxx1=0,v2=0;
    while(!q1.empty()){
        int cur=q1.front();q1.pop();
        for(int i=0;i<tree[cur].size();i++){
            if(dist1[tree[cur][i]]==-1){
                dist1[tree[cur][i]]=dist1[cur]+1;
                q1.push(tree[cur][i]);
                if(dist1[tree[cur][i]]>maxx1){
                    maxx1=dist1[tree[cur][i]];
                    v2=tree[cur][i];
                }
            }
        }
    }
    vector<int> dist2(n,-1);
    dist2[v2]=0;
    queue<int> q2;
    q2.push(v2);
    // int maxx2=0,v1=0;
    while(!q2.empty()){
        int cur=q2.front();q2.pop();
        for(int i=0;i<tree[cur].size();i++){
            if(dist2[tree[cur][i]]==-1){
                dist2[tree[cur][i]]=dist2[cur]+1;
                q2.push(tree[cur][i]);
                // if(dist0[tree[cur][i]]>maxx){
                //     maxx=dist2[tree[cur][i]];
                //     v1=tree[cur][i];
                // }
            }
        }
    }
    vector<int> dist(n);
    vector<int> freq(n,0);
    for(int i=0;i<n;i++){
        dist[i]=max(dist1[i],dist2[i]);
        freq[dist[i]]++;
    }
    // cout<<dist<<endl;
    vector<int> ans(n+1);
    ans[1]=1;
    for(int i=2;i<=n;i++){
        ans[i]=ans[i-1]+freq[i-1];
        ans[i]=min(ans[i],n);
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
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