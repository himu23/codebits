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

// Sparse Table for GCD / Min / Max
struct SparseTable {
    vector<vector<int>> st;
    vector<int> bin_log;
    int K;
    int oper(int x, int y) {
        return gcd(x, y); //max(x, y) or min(x, y)
    }
    SparseTable(const vector<int>& a) {
        int n = a.size();
        bin_log.resize(n + 1);
        bin_log[1] = 0;
        for (int i = 2; i <= n; i++)
            bin_log[i] = bin_log[i / 2] + 1;
        K = bin_log[n] + 1;
        st.assign(n, vector<int>(K));
        for (int i = 0; i < n; i++)
            st[i][0] = a[i];
        for (int j = 1; j < K; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = oper(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int query(int L, int R) {
        int j = bin_log[R - L + 1];
        return oper(st[L][j], st[R - (1 << j) + 1][j]);
    }
};

struct SegmentTree {
    int n;
    vector<int> tree;

    // 1. Merge Operation: Change this to min, max, sum, etc.
    int merge(int a, int b) {
        return gcd(a, b); // std::gcd is C++17 compatible
    }

    // 2. Identity Element: 0 for GCD, INF for Min, -INF for Max, 0 for Sum
    int identity = 0;

    SegmentTree(const vector<int>& a) {
        n = a.size();
        tree.resize(4 * n);
        if (n > 0) build(a, 1, 0, n - 1);
    }

    void build(const vector<int>& a, int node, int start, int end) {
        if (start == end) {
            tree[node] = a[start];
        } else {
            int mid = (start + end) / 2;
            build(a, 2 * node, start, mid);
            build(a, 2 * node + 1, mid + 1, end);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return identity; // Completely outside
        }
        if (l <= start && end <= r) {
            return tree[node]; // Completely inside
        }
        int mid = (start + end) / 2;
        int p1 = query(2 * node, start, mid, l, r);
        int p2 = query(2 * node + 1, mid + 1, end, l, r);
        return merge(p1, p2);
    }
};
/*
Operation,  Static Array (No Updates),  Dynamic Array (Updates)
Sum,        Prefix Sum,                 Segment Tree / Fenwick Tree
XOR,        Prefix XOR,                 Segment Tree / Fenwick Tree
Min / Max,  Sparse Table,               Segment Tree
GCD,        Sparse Table,               Segment Tree
Bitwise OR/AND,Sparse Table,            Segment Tree
*/
void solve() {
    int n,q; cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> b(n);
    for(int i=0;i<n-1;i++){
        b[i]=abs(a[i]-a[i+1]);
    }
    // SparseTable st(b);
    SegmentTree st(b);
    while(q--){
        int l,r; cin>>l>>r;
        l--,r--,r--;
        if(r<l){cout<<0<<" ";continue;};
        if(r==l){cout<<b[r]<<" ";continue;}
        cout<<st.query(l,r)<<" ";
    }
    //feature       segment tree    sparse table
    //precomutation O(N)            O(NlogN)
    //query time    O(logN)         O(1)
    //update        O(logN)         expensive
    //memory        O(N)            O(NlogN)
    cout<<endl;
    //i.e. segment trees for dynamic arrays and sparse table for static
    //segment tree
    //root [0,n-1]
    //left [l,mid]
    //right [m+1,r]
    //gcd of parents is simply the gcd of two children
    //
    //sparse table
    //uses dp and bit manipulation
    //st[i][j] stores gcd of the range starting at index i with length 2^j
    //range covered: [i,i+2^j -1]
    //gcd of length 2^j == gcd(first half of lenght 2^j-1,second half)
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