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

const ll MAXN = 3e5+5;
vector<int> primes;
int spf[MAXN];
void sieve(){
    iota(spf, spf + MAXN, 0);
    for (int i = 2; i * i < MAXN; i++) {
        if (spf[i] == i) { 
            for (int j = i * i; j < MAXN; j += i) if (spf[j] == j) spf[j] = i;
        }
    }
}
vector<int> getFactorsLogN(int n) {
    vector<int> factors;
    while (n > 1) {
        int p = spf[n];
        factors.push_back(p);
        while (n % p == 0) n /= p;
    }
    return factors;
}
vector<int> getprimestill_n(int n) {
    vector<int> primes;
    vector<bool> allnums(n + 1, true);
    allnums[0] = allnums[1] = false;

    for (int i = 2; 1LL * i * i <= n; i++) {
        if (!allnums[i]) continue;
        for (long long j = 1LL * i * i; j <= n; j += i) {
            allnums[j] = false;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (allnums[i]) primes.push_back(i);
    }
    return primes;
}
void precompute(){
    primes=getprimestill_n(MAXN);
}
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    int maxx=0;
    vector<bool> parity(n,true);
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    int s,t; cin>>s>>t;s--,t--;
    if(s==t){
        cout<<1<<endl;
        cout<<s+1<<endl;
        return;
    }
    vector<bool> visi(n,false);
    vector<vector<int>> adj(n);
    int temp=n;
    // vector<int> pri;
    safe_umap<int,int> um;
    vector<int> parent(n,-1);
    for(int x:primes){
        if(x>maxx) break;
        // pri.pb(x);
        visi.pb(false);
        um[x]=temp;
        // vector<int> cur;
        // for(int i=0;i<n;i++){
        //     if(a[i]%x==0){
        //         adj[i].pb(temp);
        //         cur.pb(i);
        //     }
        // }
        // adj.pb(cur);
        adj.pb({});
        parity.pb(false);
        parent.pb(-1);
        temp++;
    }
    for(int i=0;i<n;i++){
        int cur=a[i];
        vector<int> curvec=getFactorsLogN(cur);
        for(int j=0;j<curvec.size();j++){
            adj[i].pb(um[curvec[j]]);
            adj[um[curvec[j]]].pb(i);
        }
    }
    // cout<<pri<<endl;
    //good question
    queue<int> q;q.push(s);
    visi[s]=true;
    bool flag=true;
    while(!q.empty() && flag){
        int cur=q.front();q.pop();
        for(int x:adj[cur]){
            if(!visi[x]){
                parent[x]=cur;
                visi[x]=true;
                if(x==t){
                    flag=false;
                    break;
                }
                q.push(x);
            }
        }
    }
    if(parent[t]==-1){
        cout<<-1<<endl;return;
    }
    int cur=t;
    vector<int> ans;
    while(cur!=s){
        if(parity[cur]) ans.pb(cur+1);
        cur=parent[cur];
    }
    ans.pb(s+1);
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int x:ans) cout<<x<<" ";
    cout<<endl;
}
//tle
// void solve(){
//     int n; cin>>n;
//     vector<int> a(n);
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     int s,t;cin>>s>>t;s--,t--;
//     // vector<vector<int>> adj1(n);
//     // safe_umap<int,vector<int>> adj2;
//     // for(int i=0;i<n;i++){
//     //     int cur=a[i];
//     //     for(int j=1;j*j<=cur;j++){
//     //         if(j*j!=n){
//     //             if(cur/j!=1){
//     //                 adj2[cur/j].pb(i);
//     //                 adj1[i].pb(cur/j);
//     //             }
//     //         }
//     //         if(j!=1){
//     //             adj2[j].pb(i);
//     //             adj1[i].pb(j);
//     //         }
//     //     }
//     // }
    
// }

int32_t main() {
    precompute();
    sieve();
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