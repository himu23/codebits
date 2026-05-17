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
struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
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
bool isinbounds(ll x,ll y,ll rows,ll cols){
    return x>=0 && y>=0 && x<rows && y<cols;
}
const ll dx[4]={0,1,0,-1};
const ll dy[4]={1,0,-1,0};
ll modinverse(ll n){
    return binpow(n,MOD-2);
} //works only when mod is prime(& coprime with n)

const ll MAXN = 1e6+5;
bool prime[100];
void solve() {
    int n; cin>>n;
    // int k; cin>>k;
    // string s=to_string(k);
    string s; cin>>s;
    int c2=0,c3=0,c5=0,c7=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1' || s[i]=='4' ||s[i]=='6' ||s[i]=='8' ||s[i]=='9'){cout<<1<<endl<<s[i]<<endl;return;}
        if(s[i]=='2') c2++;
        if(s[i]=='3') c3++;
        if(s[i]=='5') c5++;
        if(s[i]=='7') c7++;        
    }
    // if(n==1){cout<<}
    if(c2>0 && s[0]!='2'){cout<<2<<endl<<s[0]<<'2'<<endl;return;}
    if(c5>0 && s[0]!='5'){cout<<2<<endl<<s[0]<<'5'<<endl;return;}
    //22,33,55,77
    if(c2>1){cout<<2<<endl<<22<<endl;return;}
    if(c3>1){cout<<2<<endl<<33<<endl;return;}
    if(c5>1){cout<<2<<endl<<55<<endl;return;}
    if(c7>1){cout<<2<<endl<<77<<endl;return;}
    if(c2>0 && c7>0){cout<<2<<endl<<27<<endl;return;}
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(!prime[10*(s[i]-'0')+s[j]-'0']){
                cout<<2<<endl<<s[i]<<s[j]<<endl;return;
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for(int i=2;i<100;i++){
        prime[i]=true;
        for(int j=2;j*j<=i;j++){
            if(i%j==0) prime[i]=false;
        }
    }
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
        //cout<<fixed<<setprecision(12)<<
    }
}