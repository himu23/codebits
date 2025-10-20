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

const int N = 200000;
vector<vector<int>> pfac(N + 1); // prime factors of each number

void preprocessfactors() {
    for (int i = 2; i <= N; i++) {
        if (!pfac[i].empty()) continue;
        for (int j = i; j <= N; j += i)
            pfac[j].push_back(i);
    }
}

void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    vector<pair<int,int>> c;
    for(int i=0;i<n;i++){
        c.pb({b[i],a[i]});
    }
    sort(c.begin(),c.end());
    umap <int,int> um;
    for(int i=0;i<n;i++){
        for(int p: pfac[a[i]]){
            um[p]++;
            if(um[p]>1){
                cout<<0<<endl;
                return;
            }
        }
    }
    ll ans=INT_MAX;
    bool flag=false;
    for(int i=0;i<n;i++){
        if(flag) break;
        for(int p:pfac[c[i].s+1]){
            if(um[p]>0){
                ans=1LL*c[i].f;
                flag=true;
                break;
            }
        }
    }
    umap<int,int> um2;
    for(int i=1;i<n;i++){
        for(int p: pfac[c[i].s]){
            um2[p]++;
        }
    }
    for(auto pa : um2){
        int cur=c[0].s;
        //if(pa.f>cur) break;
        int temp=cur%pa.f;
        temp=pa.f-temp;
        ans=min(ans,1LL*c[0].f*temp);
    }
    //cout<<ans<<endl;
    ans=min(ans,1LL*(c[0].f+c[1].f));
    cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    preprocessfactors();
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
        //cout<<fixed<<setprecision(12)<<
    }
}