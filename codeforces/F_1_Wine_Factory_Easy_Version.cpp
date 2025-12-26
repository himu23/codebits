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
struct Node{
    ll sum;
    ll max_sum;
};
Node merge(Node l,Node r){
    Node res;
    res.sum=l.sum+r.sum;
    res.max_sum=max(r.max_sum,r.sum+l.max_sum);
    return res;
}
struct SegTree{
    ll n;
    vector<Node> tree;
    SegTree(ll size){
        n=size;
        tree.resize(4*n+1);
    }
    void build(vector<ll>& initial_data,ll v, ll tl,ll tr){
        if(tl==tr){
            tree[v]={initial_data[tl],initial_data[tl]};
        }
        else{
            ll tm=(tl+tr)/2;
            build(initial_data,2*v,tl,tm);
            build(initial_data,2*v+1,tm+1,tr);
            tree[v]=merge(tree[2*v],tree[2*v+1]);
        }
    }
    void update(ll v,ll tl, ll tr, ll pos, ll new_val){
        if(tl==tr){
            tree[v]={new_val,new_val};
        }
        else{
            ll tm=(tl+tr)/2;
            if(pos<=tm){
                update(2*v,tl,tm,pos,new_val);
            }
            else{
                update(2*v+1,tm+1,tr,pos,new_val);
            }
            tree[v]=merge(tree[2*v],tree[2*v+1]);
        }
    }
};
void solve() {
    ll n,q; cin>>n>>q;
    vector<ll> a(n);
    ll summ=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        summ+=a[i];
    }
    vector<ll> b(n);
    for(ll i=0;i<n;i++){
        cin>>b[i];
    }
    vector<ll> c(n);
    for(ll i=0;i<n-1;i++){
        cin>>c[i];//connects i-1 to i
    }
    vector<ll> vals(n+1);
    for(ll i=0;i<n;i++){
        vals[i+1]=a[i]-b[i];
    }
    SegTree st(n);
    st.build(vals,1,1,n);
    while(q--){
        ll p,x,y,z; cin>>p>>x>>y>>z;
        p--;
        summ-=a[p];
        a[p]=x,b[p]=y;
        summ+=a[p];
        ll new_val=x-y;
        st.update(1,1,n,p+1,new_val);
        cout<<summ-max(0LL,st.tree[1].max_sum)<<endl;
    }
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