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
#define fi first
#define se second
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
    string s; cin>>s;
    vector<ll> temp;
    ll n=s.length();
    ll cnt=1;
    for(ll i=1;i<n;i++){
        if(s[i]!=s[i-1]){
            if(s[i-1]=='o') cnt*=-1;
            temp.pb(cnt);
            cnt=1;
        }
        else cnt++;
    }
    if(s[n-1]=='o') cnt*=-1;
    temp.pb(cnt);
    // cout<<temp<<endl;
    vector<ll> a;
    for(ll i=0;i<temp.size();i++){
        if(temp[i]<0) a.pb(temp[i]);
        else if(temp[i]>1) a.pb(temp[i]-1);
    }
    // cout<<a<<endl;
    vector<ll> temp1,temp2;
    ll cnt1=0;
    for(ll i=0;i<a.size();i++){
        if(a[i]>0){
            temp1.pb(a[i]);
            temp2.pb(cnt1);
        }
        else cnt1+=(a[i]*(-1));
    }
    // cout<<temp1<<endl<<temp2<<endl;
    ll m=temp1.size();
    // ll ans=0;
    // for(ll i=0;i<m;i++){
    //     for(ll j=i+1;j<m;j++){
    //         ll cur=temp1[i]*temp1[j];
    //         cur*=(temp2[j]-temp2[i]);
    //         ans+=cur;
    //     }
    // }
    // cout<<ans<<endl;
    //tle
    if(m==0){
        cout<<0<<endl;
        return;
    }
    vector<ll> temp3(m);
    for(ll i=0;i<m;i++){
        temp3[i]=temp1[i]*temp2[i];
    }
    ll sum1=0,sum2=0;
    vector<ll> temp9(m),temp8(m);
    temp9[0]=0,temp8[m-1]=0;
    for(ll i=1;i<m;i++){
        temp9[i]=temp9[i-1]+temp1[i-1];
        temp8[m-i-1]=temp8[m-i]+temp1[m-i];
    }
    for(ll i=0;i<m;i++){
        sum1+=(temp3[i]*temp9[i]);
        sum2+=(temp3[i]*temp8[i]);
    }
    cout<<sum1-sum2<<endl;
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