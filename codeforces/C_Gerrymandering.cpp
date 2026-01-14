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
    string s,t; cin>>s>>t;
    // int ans=0;
    // int cur=0;
    // //3 in each row;
    // for(int i=0;i<n-2;i+=3){
    //     int cnt1=0,cnt2=0;
    //     for(int j=i;j<i+3;j++){
    //         if(s[i]=='A') cnt1++;
    //         if(t[i]=='A') cnt2++;
    //     }
    //     if(cnt1>=2) cur++;
    //     if(cnt2>=2) cur++;
    // }
    // ans=max(ans,cur);cur=0;
    // //two in top, 1 in bottom in first block;
    // for(int i=0;i<n-2;i+=3){
    //     int cnt1=0,cnt2=0;
    //     if(s[i]=='A') cnt1++;
    //     if(s[i+1]=='A') cnt2++;
    //     if(s[i+2]=='A') cnt2++;
    //     if(t[i]=='A') cnt1++;
    //     if(t[i+1]=='A') cnt1++;
    //     if(t[i+2]=='A') cnt2++;
    //     if(cnt1>=2) cur++;
    //     if(cnt2>=0) cur++;
    // }
    // ans=max(ans,cur);cur=0;
    // //two in bottom, 1 in top in first block;
    // for(int i=0;i<n-2;i+=3){
    //     int cnt1=0,cnt2=0;
    //     if(s[i]=='A') cnt1++;
    //     if(s[i+1]=='A') cnt1++;
    //     if(s[i+2]=='A') cnt2++;
    //     if(t[i]=='A') cnt1++;
    //     if(t[i+1]=='A') cnt2++;
    //     if(t[i+2]=='A') cnt2++;
    //     if(cnt1>=2) cur++;
    //     if(cnt2>=0) cur++;
    // }
    // ans=max(ans,cur);cur=0;
    // for(int i=0;i<n-2;i+=3){
    //     //all three cases for each block of len 3
    //     int cur=0,curans=0;
    //     int cnt1=0,cnt2=0;
    //     for(int j=i;j<i+3;j++){
    //         if(s[i]=='A') cnt1++;
    //         if(t[i]=='A') cnt2++;
    //     }
    //     if(cnt1>=2) cur++;
    //     if(cnt2>=2) cur++;
    //     curans=max(curans,cur);
    //     //
    //     cnt1=0,cnt2=0;
    //     if(s[i]=='A') cnt1++;
    //     if(s[i+1]=='A') cnt2++;
    //     if(s[i+2]=='A') cnt2++;
    //     if(t[i]=='A') cnt1++;
    //     if(t[i+1]=='A') cnt1++;
    //     if(t[i+2]=='A') cnt2++;
    //     if(cnt1>=2) cur++;
    //     if(cnt2>=0) cur++;
    //     curans=max(curans,cur);cur=0;
    //     //
    //     cnt1=0,cnt2=0;
    //     if(s[i]=='A') cnt1++;
    //     if(s[i+1]=='A') cnt1++;
    //     if(s[i+2]=='A') cnt2++;
    //     if(t[i]=='A') cnt1++;
    //     if(t[i+1]=='A') cnt2++;
    //     if(t[i+2]=='A') cnt2++;
    //     if(cnt1>=2) cur++;
    //     if(cnt2>=0) cur++;
    //     curans=max(curans,cur);cur=0;
    //     ans+=curans;
    // }
    //broken profile dp
    vector<vector<int>> dp(n+1,vector<int>(3,INT_MIN));
    dp[0][0]=0;
    auto value=[&](char a,char b,char c)->int{
        int cnt=(a=='A')+(b=='A')+(c=='A');
        return cnt>=2;
    };
    for(int i=0;i<n;i++){
        if(dp[i][0]!=INT_MIN){
            if(i+2<n){
                int votes=value(s[i],s[i+1],s[i+2])+value(t[i],t[i+1],t[i+2]);
                dp[i+3][0]=max(dp[i+3][0],dp[i][0]+votes);
            }
            if(i+1<n){
                int votes=value(s[i],s[i+1],t[i]);
                dp[i+1][1]=max(dp[i+1][1],dp[i][0]+votes);
            }
            if(i+1<n){
                int votes=value(s[i],t[i],t[i+1]);
                dp[i+1][2]=max(dp[i+1][2],dp[i][0]+votes);
            }
        }
        if(dp[i][1]!=INT_MIN){
            if(i+3<n){
                int votes=value(s[i+1],s[i+2],s[i+3])+value(t[i],t[i+1],t[i+2]);
                dp[i+3][1]=max(dp[i+3][1],dp[i][1]+votes);
            }
            if(i+1<n){
                int votes=value(t[i],t[i+1],s[i+1]);
                dp[i+2][0]=max(dp[i+2][0],dp[i][1]+votes);
            }
        }
        if(dp[i][2]!=INT_MIN){
            if(i+3<n){
                int votes=value(s[i],s[i+1],s[i+2])+value(t[i+1],t[i+2],t[i+3]);
                dp[i+3][2]=max(dp[i+3][2],dp[i][2]+votes);
            }
            if(i+1<n){
                int votes=value(s[i],s[i+1],t[i+1]);
                dp[i+2][0]=max(dp[i+2][0],dp[i][2]+votes);
            }
        }
    }
    cout<<dp[n][0]<<endl;
    // cout<<ans<<endl;
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