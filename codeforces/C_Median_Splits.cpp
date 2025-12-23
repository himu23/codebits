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
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //three subarrays
    //atleast two of those should have median<=k
    //a subarray has median<=k iff elements>k <= elements<=k
    //let bi=-1 if ai>k , bi=1 if ai<=k
    vector<int> b(n);
    int summ=0;
    for(int i=0;i<n;i++){
        if(a[i]>k) b[i]=-1;
        else b[i]=1;
        summ+=b[i];
    }
    // cout<<b<<endl;
    //return true if for some i,j atleast two of
    //prefi,prefj-pref(i-1),summ-pref(j-1) is positive
    vector<int> pref(n); pref[0]=b[0];
    vector<int> suff(n); suff[0]=summ;
    for(int i=1;i<n;i++){
        pref[i]=pref[i-1]+b[i];
        suff[i]=summ-pref[i]+b[i];
    }
    // cout<<pref<<endl;
    // cout<<suff<<endl;
    //i and j can be equal
    int l=n+1,r=-1;
    for(int i=0;i<n;i++){
        if(pref[i]>=0){
            l=i;break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(suff[i]>=0){
            r=i;break;
        }
    }
    if(r>=l+2){
        cout<<"YES"<<endl;
        return;
    }
    vector<int> maxx(n);
    int val=pref[n-2];
    for(int i=n-2;i>=0;i--){
        val=max(val,pref[i]);
        maxx[i]=val;
    }
    for(int i=0;i<n-2;i++){
        if(pref[i]>=0 && maxx[i+1]>=pref[i]){
            cout<<"YES"<<endl;
            return;
        }
    }
    vector<int> minn(n);
    val=pref[0];
    for(int i=0;i<n-1;i++){
        val=min(val,pref[i]);
        minn[i]=val;
    }
    for(int i=2;i<n;i++){
        if(suff[i]>=0 && minn[i-2]<=pref[i-1]){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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