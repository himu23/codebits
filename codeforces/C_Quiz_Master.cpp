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


// void solve() {
//     ll n,m; cin>>n>>m;
//     ll temp=1;
//     for(ll i=1;i<=m;i++){
//         ll cur=gcd(temp,i);
//         temp=(temp*i)/cur;
//     }
//     vector<ll> a(n);
//     for(ll i=0;i<n;i++){
//         cin>>a[i];
//     }
//     sort(a.begin(),a.end());
//     ll l=0;
//     ll cur=1;
//     ll ans=INT_MAX;
//     for(ll r=0;r<n;r++){
//         cur*=a[r];
//         while(cur%temp==0 && l<=r){
//             cur/=a[l];
//             ans=min(ans,a[r]-a[l]);
//             l++;
//         }
//     }
//     if(ans==INT_MAX) cout<<-1<<endl;
//     else cout<<ans<<endl;
// }

const int MAXN = 1e5 + 5;
vector<vector<int>> facts(MAXN);
void init(){
    for(int i=1;i<MAXN;i++){
        for(int j=i;j<MAXN;j+=i){
            facts[j].pb(i);
        }
    }
}

void solve(){
    int n,m; cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> cnt(m+1,0);
    int l=0;
    int ans=INT_MAX;
    sort(a.begin(),a.end());
    int cur=0;
    for(int r=0;r<n;r++){
        for(int j=0;j<facts[a[r]].size();j++){ //wont give tle because it will to max O(n*128)
            if(facts[a[r]][j]>m) break;
            cnt[facts[a[r]][j]]++;
            if(cnt[facts[a[r]][j]]==1) cur++;
        }
        while(cur==m){
            ans=min(ans,a[r]-a[l]);
            for(int j=0;j<facts[a[l]].size();j++){
                if(facts[a[l]][j]>m) break;
                cnt[facts[a[l]][j]]--;
                if(cnt[facts[a[l]][j]]==0) cur--;
            }
            l++;
        }
    }
    if(ans==INT_MAX) cout<<-1<<endl;
    else cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    init();
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
        //cout<<fixed<<setprecision(12)<<
    }
}