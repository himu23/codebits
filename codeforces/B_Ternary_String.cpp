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
    // string s; cin>>s;
    // int n=s.length();
    // //s+='4';
    // // int c1=0,c2=0,c3=0;
    // vector<int> c={0,0,0,0};
    // int l=0,r=0;
    // while(!(c[1]!=0 && c[2]!=0 && c[3]!=0)&&(r<n)){
    //     if(s[r]=='1') c[1]++;
    //     else if(s[r]=='2') c[2]++;
    //     else if(s[r]=='3') c[3]++;
    //     r++;
    // }
    // if(r==n && (c[1]==0 || c[2]==0 || c[3]==0)) {cout<<0<<endl; return;}
    // int ans=r-l;
    // for(int i=r;i<n;i++){
    //     c[s[i]-'0']++;
    //     ans=min(ans,i-l);
    //     while(c[s[l]-'0']>1){
    //         c[s[l]-'0']--;
    //         l++;
    //     }
    //     ans=min(ans,i-l);
    // }
    // //ans=min(ans,r-l);
    // cout<<ans<<endl;
    //my core understanding of sliding window is broken
    //i mostly do first find a valid window then only expand
    //but we should expand and shrink simultaneously
    string s; cin>>s;
    int n=s.length();
    vector<int> cnt={0,0,0,0};
    int l=0,ans=INT_MAX;
    for(int r=0;r<n;r++){
        cnt[s[r]-'0']++;
        while(cnt[1] && cnt[2] && cnt[3]){
            ans=min(ans,r-l+1);
            cnt[s[l]-'0']--;
            l++;
        }
    }
    cout<<(ans==INT_MAX ? 0:ans)<<endl;
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