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
    ll n; cin>>n;
    string s; cin>>s;
    vector<ll> p(n);
    for(ll i=0;i<n;i++){
        cin>>p[i];
    }
    
    //if all the chars were distinct its just lcm of sizes of connnected compos
    //sample is so weak
    //no two connected compo shares a char
    
    vector<vector<ll>> adj(n);
    for(ll i=0;i<n;i++){
        adj[p[i]-1].pb(i);
        adj[i].pb(p[i]-1);
    }
    // vector<ll> compos;
    vector<vector<ll>> compos;
    vector<bool> visi(n,false);
    for(ll i=0;i<n;i++){
        if(visi[i]) continue;
        // ll cursum=1;
        vector<ll> temp;
        temp.pb(i);
        visi[i]=true;
        queue<ll> q;
        q.push(i);
        while(!q.empty()){
            ll cur=q.front();q.pop();
            for(ll j=0;j<adj[cur].size();j++){
                if(!visi[adj[cur][j]]){
                    visi[adj[cur][j]]=true;
                    q.push(adj[cur][j]);
                    // cursum++;
                    temp.pb(adj[cur][j]);
                }
            }
        }
        // compos.pb(cursum);
        compos.pb(temp);
    }
    // ll ans=compos[0];
    // for(ll i=1;i<compos.size();i++){
    //     ll temp=gcd(ans,compos[i]);
    //     ans=(ans*compos[i])/temp;
    // }
    // cout<<ans<<endl;

    // cout<<compos<<endl;
    vector<ll> temp1;
    for(ll i=0;i<compos.size();i++){
        string str="";
        vector<ll> cur=compos[i];
        for(ll j=0;j<cur.size();j++){
            str+=s[cur[j]];
            // cur[j]=p[cur[j]]-1;
        }
        string s1=s;
        ll curans=0;
        for(ll j=1;j<=cur.size();j++){
            curans++;
            //
            string s2="";
            for(ll k:cur){
                s2+=s1[p[k]-1];
            }
            for(ll k=0;k<s2.size();k++){
                s1[cur[k]]=s2[k];
            }
            //
            if(s2==str) break;
        }
        temp1.pb(curans);
    }
    ll ans=temp1[0];
    for(ll i=1;i<temp1.size();i++){
        ll temp=gcd(ans,temp1[i]);
        ans=(ans*temp1[i])/temp;
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