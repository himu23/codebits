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

// --- Segment Tree Template (Default: Sum) ---
template<class T>
struct SegTree {
    ll n;
    T ID; 
    vector<T> tree;

    // ID REFERENCE (Identity Element - Pass this to constructor):
    // SUM: 0
    // MIN: 1e18 (or INF)
    // MAX: -1e18
    // GCD: 0
    // XOR: 0

    // --- CHANGE THIS FUNCTION based on the problem ---
    T merge(T a, T b) {
        return a + b;           // Default: SUM
        // return min(a, b);    // Option: MIN
        // return max(a, b);    // Option: MAX
        // return __gcd(a, b);  // Option: GCD
        // return a ^ b;        // Option: XOR
    }

    SegTree(ll _n, T _ID) : n(_n), ID(_ID) {
        tree.resize(4 * n + 1, ID);
    }

    void update(ll node, ll start, ll end, ll idx, T val) {
        if (start == end) {
            // --- CHANGE UPDATE LOGIC IF NEEDED ---
            tree[node] = val;       // Default: Point Assignment (A[i] = val)
            // tree[node] += val;   // Option: Point Addition (A[i] += val)
            return;
        }
        ll mid = (start + end) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, val);
        else update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    T query(ll node, ll start, ll end, ll l, ll r) {
        if (r < start || end < l) return ID;
        if (l <= start && end <= r) return tree[node];
        ll mid = (start + end) / 2;
        return merge(query(2 * node, start, mid, l, r), 
                     query(2 * node + 1, mid + 1, end, l, r));
    }

    void update(ll idx, T val) { update(1, 0, n - 1, idx, val); }
    T query(ll l, ll r) { return query(1, 0, n - 1, l, r); }
};

/*
void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for(auto &x : a) cin >> x;

    // --- 1. INITIALIZATION ---
    
    // FOR SUM (Default): ID is 0
    SegTree<ll> st(n, 0); 
    //    SegTree<ll> st(n, 1e18);  // MIN: ID = Infinity
    //    SegTree<ll> st(n, -1e18); // MAX: ID = -Infinity
    //    SegTree<ll> st(n, 0);     // GCD: ID = 0
    //    SegTree<ll> st(n, 0);     // XOR: ID = 0
    

    // --- 2. BUILD THE TREE ---
    for(int i = 0; i < n; i++) {
        st.update(i, a[i]);
    }

    // --- 3. QUERIES & UPDATES ---
    
    int q; cin >> q;
    while(q--) {
        int type; cin >> type;
        if(type == 1) { 
            // Update: change value at index k to u
            int k, u; cin >> k >> u;
            k--; // Convert 1-based to 0-based
            
            st.update(k, u); 
        } 
        else {
            // Query: Range [l, r]
            int l, r; cin >> l >> r;
            l--; r--; // Convert 1-based to 0-based

            // FOR SUM:
            cout << st.query(l, r) << "\n";// Works for MIN/MAX/GCD/XOR too
        }
    }
}
*/
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    n-=10;
    n*=-1;
    cout<<n*(n-1)/2*6<<endl;

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