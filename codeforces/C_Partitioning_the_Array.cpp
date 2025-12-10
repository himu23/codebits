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
#define int long long
#define ld long double
#define sza(x) ((int)x.size())
#define aint(a) (a).begin(), (a).end()
#define pb push_back
#define umap unordered_map
#define fi first
#define se second
#define pai pair<int,int>

const int MAX_N = 1e6 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;
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
int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res=(res*a)%MOD;
        a =(a*a)%MOD;
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
    int n; cin>>n;
    vector<int> a(n);
    // int maxx=0;
    set<int> s;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s.insert(a[i]);
        // maxx=max(maxx,a[i]);
    }
    vector<int> facts;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            facts.pb(i);
            if(n/i!=i) facts.pb(n/i);
        }
    }
    if(s.size()==1){
        cout<<facts.size()<<endl;
        return;
    }
    sort(facts.begin(),facts.end());
    // vector<int> prims;
    // int m=n;
    // if(n%2==0) prims.pb(2);
    // while(m%2==0) m/=2;
    // for(int i=3;i*i<=m;i+=2){
    //     if(m%i==0) prims.pb(i);
    //     while(m%i==0) m/=i;
    // }
    // if(m>1) prims.pb(m);
    // cout<<prims<<endl;
    //two pointers for each fact
    // cout<<facts.size()<<" ";
    safe_umap<int,bool> isco;
    for(int i=0;i<facts.size();i++)isco[facts[i]]=false;
    for(int i=0;i<facts.size();i++){
        if(facts[i]==n){
            isco[facts[i]]=true;
            continue;
        }
        if(isco[facts[i]]) continue;
        int cur=facts[i];
        bool flag=false;
        //two pointers;
        int gcdd=abs(a[0]-a[cur]);
        int c0=0;
        for(int i=0;i<n-cur;i++){
            gcdd=gcd(gcdd,abs(a[i]-a[i+cur]));
            if(a[i]==a[i+cur]) c0++;
        }
        if(gcdd>1 || c0==n-cur) flag=true;
        if(flag){
            for(int j=cur;j<=n;j+=cur){
                if(isco.find(j)!=isco.end()){
                    if(!isco[j]) isco[j]=true;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<facts.size();i++){
        if(isco[facts[i]]) ans++;
    }
    cout<<ans<<endl;
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