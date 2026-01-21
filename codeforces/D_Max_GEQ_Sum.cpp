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

// Sparse Table for GCD / Min / Max
struct SparseTable {
    vector<vector<ll>> stmin;
    vector<vector<ll>> stmax;
    vector<ll> bin_log;
    ll K;
    // ll oper(ll x, ll y) {
    //     return gcd(x, y); //max(x, y) or min(x, y)
    // }
    SparseTable(const vector<ll>& a) {
        ll n = a.size();
        bin_log.resize(n + 1);
        bin_log[1] = 0;
        for (ll i = 2; i <= n; i++)
            bin_log[i] = bin_log[i / 2] + 1;
        K = bin_log[n] + 1;
        stmin.assign(n, vector<ll>(K));
        stmax.assign(n, vector<ll>(K));
        for (ll i = 0; i < n; i++){
            stmin[i][0] = a[i];
            stmax[i][0] = a[i];
        }
        for (ll j = 1; j < K; j++) {
            for (ll i = 0; i + (1 << j) <= n; i++) {
                stmin[i][j] = min(stmin[i][j - 1], stmin[i + (1 << (j - 1))][j - 1]);
                stmax[i][j] = max(stmax[i][j - 1], stmax[i + (1 << (j - 1))][j - 1]);

            }
        }
    }
    ll querymin(ll L, ll R) {
        ll j = bin_log[R - L + 1];
        return min(stmin[L][j], stmin[R - (1 << j) + 1][j]);
    }
    ll querymax(ll L, ll R) {
        ll j = bin_log[R - L + 1];
        return max(stmax[L][j], stmax[R - (1 << j) + 1][j]);
    }
};
void solve() {
    ll n; cin>>n;
    vector<ll> a(n+1);
    a[0]=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<ll> pref(n+1);
    pref[0]=0;
    for(ll i=1;i<=n;i++){
        pref[i]=pref[i-1]+a[i];
    }
    vector<ll> left(n+1,0),right(n+1,n);
    stack<ll> s;
    for(ll i=1;i<=n;i++){
        while(!s.empty() && a[s.top()]<=a[i]) s.pop();
        if(!s.empty()) left[i]=s.top();
        s.push(i);
    }
    while (!s.empty()) s.pop(); //
    for(ll i=n;i>=1;i--){
        while(!s.empty() && a[s.top()]<a[i]) s.pop();
        if(!s.empty()) right[i]=s.top()-1;
        s.push(i);
    }
    // cout<<left<<endl<<right<<endl<<endl;
    // for(ll i=1;i<=n;i++){
    //     if(a[i]<pref[right[i]]-pref[left[i]]){cout<<"NO"<<endl;return;}
    // }
    SparseTable st=pref;
    for(ll i=1;i<=n;i++){
        ll temp1=st.querymax(i,right[i]);
        ll temp2=st.querymin(left[i],i-1);
        if(temp1-temp2>a[i]){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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