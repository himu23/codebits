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
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define umap unordered_map
#define f first
#define s second
#define pai pair<int,int>

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
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
    size_t operator()(const std::pair<int, int>& p) const {
        return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
    }
};
template<typename K, typename V>
using safe_umap = unordered_map<K, V, custom_hash>;
template<typename T>
using safe_uset = unordered_set<T, custom_hash>;
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}
void add_self(int& a,int b){
    a+=b;
    if(a>=MOD) a-=MOD;
}
bool isinbounds(int x,int y,int rows,int cols){
    return x>=0 && y>=0 && x<rows && y<cols;
}
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};

void solve() {
    ll n; cin>>n;
    vector<ll> a(n);
    ll sum=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%3!=0){cout<<0<<endl; return;}
    // vector<ll> prefix(n,0);
    // vector<ll> suffix(n,0);
    // prefix[0]=a[0];
    // suffix[n-1]=a[n-1];
    // for(ll i=1;i<n;i++){
    //     prefix[i]=prefix[i-1]+a[i];
    //     suffix[n-i-1]=suffix[n-i]+a[n-i-1];
    // }
    // // cout<<prefix<<endl;
    // // cout<<suffix<<endl;
    // sum/=3;
    // vector<ll> jj;
    // vector<ll> ii;
    // for(ll i=n-1;i>=0;i--){
    //     if(suffix[i]==sum) jj.pb(i);
    //     if(prefix[n-1-i]==sum) ii.pb(n-1-i);
    // }
    // // for(ll i=0;i<n;i++){
    // //     if(prefix[i]==sum) ii.pb(i);
    // // }
    // // cout<<ii<<endl;
    // // cout<<jj<<endl;
    // ll ans=0;
    // bool flag=false;
    // for(ll i=0;i<ii.size();i++){
    //     if(flag) break;
    //     for(ll j=0;j<jj.size();j++){
    //         if(jj[j]-ii[i]>1) ans++;
    //         else{
    //             if(j==0) flag=true;
    //             break;
    //         }
    //     }
    // }
    // cout<<ans<<endl;
    //tle
    vector<ll> prefix(n,0);
    prefix[0]=a[0];
    for(ll i=1;i<n;i++){
        prefix[i]=prefix[i-1]+a[i];
    }
    sum/=3;
    vector<ll> dp(n,0);
    dp[n-1]=0;
    for(ll i=n-2;i>=0;i--){
        if(prefix[i]==2*sum) dp[i]=dp[i+1]+1;
        else dp[i]=dp[i+1];
    }
    ll ans=0;
    for(ll i=0;i<n-2;i++){
        if(prefix[i]==sum) ans+=dp[i+1];
    }
    cout<<ans<<endl;
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