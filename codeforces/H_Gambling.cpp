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
// #define cntbit(x) __builtin_popcount(x)

// const ll MOD = 1e9 + 7;
// // const ll MOD = 998244353;
// const ll INF = 1e9;
// const ld EPS = 1e-9;

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
// ll modinverse(ll n){
//     return binpow(n,MOD-2);
// }

// const ll MAXN = 1e6 + 5;
// // struct node{
// //     int sum;
// //     int mpref,msuff,mans;
// //     int prefr;
// //     int suffl;
// //     int ansl,ansr;
// //     node():sum(0),mpref(INT_MIN),msuff(INT_MIN),mans(INT_MIN){}
// //     void init(int idx,int val){
// //         sum=val;
// //         mpref=msuff=mans=val;
// //         prefr=suffl=ansl=ansr=idx;
// //     }
// // };
// // node merge(const node& l,const node& r){
// //     node res;
// //     res.sum=l.sum+r.sum;
// //     if(l.mpref>=l.sum+r.mpref){
// //         res.mpref=l.mpref;
// //         res.prefr=l.prefr;
// //     }
// //     else{
// //         res.mpref=l.sum+r.mpref;
// //         res.prefr=r.prefr;
// //     }
// //     if(l.msuff>=l.sum+r.msuff){
// //         res.msuff=l.msuff;
// //         res.suffl=l.suffl;
// //     }
// //     else{
// //         res.msuff=l.sum+r.msuff;
// //         res.suffl=r.suffl;
// //     }

// //     return res;
// // }
// struct segment{
//     struct node{
//         ll sum,prefmax,suffmax,ans;
//     };
//     ll n;
//     vector<node> tree;
//     node merge(const node& l, const node& r){
//         node res;
//         res.sum=l.sum+r.sum;
//         res.prefmax=max(l.prefmax,l.sum+r.prefmax);
//         res.suffmax=max(r.suffmax,r.sum+l.suffmax);
//         res.ans=max({l.ans,r.ans,l.suffmax+r.prefmax});
//         return res;
//     }
//     segment(ll n):n(n){
//         tree.resize(4*n);
//         build(1,0,n-1);
//     }
//     void build(ll i,ll start,ll end){
//         if(start==end){
//             tree[i]={-1,-1,-1,-1};
//             return;
//         }
//         ll mid=(start+end)/2;
//         build(2*i,start,mid);
//         build(2*i+1,mid+1,end);
//         tree[i]=merge(tree[2*i],tree[2*i+1]);
//     }
//     void update(ll i,ll start,ll end,ll idx,ll val){
//         if(start==end){
//             tree[i]={val,val,val,val};
//             return;
//         }
//         ll mid=(start+end)/2;
//         if(idx<=mid) update(2*i,start,mid,idx,val);
//         else update(2*i+1,mid+1,end,idx,val);
//         tree[i]=merge(tree[2*i],tree[2*i+1]);
//     }
//     void set(ll idx,ll val){
//         update(1,0,n-1,idx,val);
//     }
//     ll get_max(){
//         return tree[1].ans;
//     }
// };
// void solve() {
//     ll n; cin>>n;
//     vector<ll> a(n);
//     safe_umap<ll,vector<ll>> pos;
//     for(ll i=0;i<n;i++){
//         cin>>a[i];
//         pos[a[i]].pb(i);
//     }
//     //kadane with segment tree
//     //segment tree
//     segment st(n);
//     ll ans=INT_MIN;
//     ll ansa=a[0];
//     for(auto& [val,idxs]:pos){
//         for(ll idx:idxs) st.set(idx,1);
//         ll cur=st.get_max();
//         if(cur>ans){
//             ans=cur;
//             ansa=val;
//         }
//         for(ll idx:idxs) st.set(idx,-1);
//     }
//     //kadane
//     ll cur=0;
//     ll sum=INT_MIN;
//     ll templ=0;
//     ll ansl=0,ansr=0;
//     for(ll i=0;i<n;i++){
//         ll val;
//         if(a[i]==ansa) val=1;
//         else val=-1;
//         if(cur+val<val){
//             cur=val;
//             templ=i;
//         }
//         else{
//             cur+=val;
//         }
//         if(cur>sum){
//             sum=cur;
//             ansl=templ;
//             ansr=i;
//         }
//     }
//     cout<<ansa<<" "<<ansl+1<<" "<<ansr+1<<endl;
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

//now lets do with segment tree gss snippet

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
// #define cntbit(x) __builtin_popcount(x)

// const ll MOD = 1e9 + 7;
// // const ll MOD = 998244353;
// const ll INF = 1e9;
// const ld EPS = 1e-9;

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
// ll modinverse(ll n){
//     return binpow(n,MOD-2);
// }

// const ll MAXN = 1e6 + 5;

// struct Node {
//     long long sum, pref, suff, ans;
// };
// struct SegmentTree {
//     int n;
//     vector<Node> tree;

//     //1) merge operation- gss logic
//     Node merge(const Node& l, const Node& r) {
//         Node res;
//         res.sum = l.sum + r.sum;
//         res.pref = max(l.pref, l.sum + r.pref);
//         res.suff = max(r.suff, r.sum + l.suff);
//         res.ans = max({l.ans, r.ans, l.suff + r.pref});
//         return res;
//     }

//     //2) identity element: for empty ranges
//     Node identity = {0, (long long)-1e18, (long long)-1e18, (long long)-1e18};

//     //3) base element: for left nodes
//     Node make_node(long long val) {
//         return {val, val, val, val};
//     }

//     SegmentTree(int n) : n(n) {
//         tree.resize(4 * n, identity);
//         //call build if initial array exists: build(a,1,0,n-1);
//     }

//     void update(int idx, long long val) {
//         update(1, 0, n - 1, idx, val);
//     }

//     void update(int node, int start, int end, int idx, long long val) {
//         if (start == end) {
//             tree[node] = make_node(val);
//             return;
//         }
//         int mid = (start + end) / 2;
//         if (idx <= mid) update(2 * node, start, mid, idx, val);
//         else update(2 * node + 1, mid + 1, end, idx, val);
//         tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
//     }

//     Node query(int l, int r) {
//         return query(1, 0, n - 1, l, r);
//     }

//     Node query(int node, int start, int end, int l, int r) {
//         if (r < start || end < l) return identity;
//         if (l <= start && end <= r) return tree[node];
//         int mid = (start + end) / 2;
//         return merge(query(2 * node, start, mid, l, r),
//                      query(2 * node + 1, mid + 1, end, l, r));
//     }
// };
// void solve() {
//     int n; cin>>n;
//     vector<int> a(n);
//     //segtree gss
//     SegmentTree st(n);
//     safe_umap<int,vector<int>> um;
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//         st.update(i,-1);
//         um[a[i]].pb(i);
//     }
//     int ansa=a[0];
//     int fans=INT_MIN;
//     for(auto &x:um){ //&x (reference) to access without copying
//         for(int i=0;i<x.se.size();i++){
//             st.update((x.se)[i],1);
//         }
//         if(st.tree[1].ans>fans){
//             ansa=x.fi;
//             fans=st.tree[1].ans;
//         }
//         for(int i=0;i<x.se.size();i++){
//             st.update((x.se)[i],-1);
//         }
//     }
//     //kadane
//     int cur=0;
//     int anss=INT_MIN;
//     int templ=0;
//     int ansl=0,ansr=0;
//     for(int i=0;i<n;i++){
//         if(a[i]==ansa) a[i]=1;
//         else a[i]=-1;
//         if(cur+a[i]<a[i]){
//             cur=a[i];
//             templ=i;
//         }
//         else cur+=a[i];
//         if(cur>anss){
//             anss=cur;
//             ansl=templ;
//             ansr=i;
//         }
//     }
//     cout<<ansa<<" "<<ansl+1<<" "<<ansr+1<<endl;
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
    vector<int> a(n);
    safe_umap<int,vector<int>> um; 
    for(int i=0;i<n;i++){
        cin>>a[i];
        um[a[i]].pb(i);
    }
    int ansa=a[0];
    int ans=INT_MIN;
    int ansl=0,ansr=0;
    for(auto &x:um){
        vector<int> temp=x.se;
        int cur=1;
        int templ=temp[0];
        if(cur>ans){
            ans=cur;
            ansa=x.fi;
            ansl=templ;
            ansr=templ;
        }
        for(int i=1;i<temp.size();i++){
            int prev=temp[i-1];
            int curi=temp[i];
            cur=cur-(curi-prev-1)+1;
            if(cur<1){
                cur=1;
                templ=curi;
            }
            if(cur>ans){
                ans=cur;
                ansl=templ;
                ansr=curi;
                ansa=x.fi;
            }
        }
    }
    cout<<ansa<<" "<<ansl+1<<" "<<ansr+1<<endl;
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