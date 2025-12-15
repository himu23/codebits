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

// void solve() {
//     int n; cin>>n;
//     vector<int> x(n);
//     int minn=INT_MAX,maxx=INT_MIN;
//     for(int i=0;i<n;i++){
//         cin>>x[i];
//         minn=min(minn,x[i]);
//         maxx=max(maxx,x[i]);
//     }
//     vector<int> t(n);
//     int maxt=0;
//     for(int i=0;i<n;i++){
//         cin>>t[i];
//         maxt=max(maxt,t[i]+max(abs(x[i]-minn),abs(x[i]-maxx)));
//     }
//     //bs on minmax, minimum max time taken
//     double l=0,r=INF;
//     double mina=-1,maxa=-1;
//     int temp=60;
//     while(temp--){
//         double m=l+(r-l)/2;
//         double min_x=-INF,max_x=INF;
//         bool flag=true;
//         for(double i=0;i<n;i++){
//             if(m-t[i]<0){flag=false;break;}
//             min_x=max(min_x,x[i]-m+t[i]);
//             max_x=min(max_x,x[i]+m-t[i]);
//         }
//         if(flag && min_x<=max_x){
//             mina=min_x,maxa=max_x;
//             r=m-1;
//         }
//         else l=m+1;
//     }
//     double anspos=(mina+maxa)/2.0;
//     cout<<fixed<<setprecision(6)<<anspos<<endl;
// }
//above got ac;
void solve(){
    int n; cin>>n;
    vector<int> x(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    vector<int> t(n);
    for(int i=0;i<n;i++){
        cin>>t[i];
    }
    //coordinate transformation
    //each person can be split to two ghosts right and left
    //right ghost=xi-ti, left ghost=xi+ti
    //so now the distance(inscluding time) of xo from xi
    //is max of distance from the two ghosts i.e. max(abs(xi-ti-x0),abs(xi+ti-x0));
    //time=ti+abs(xi-x0)==ti+max(xi-x0,x0-xi)==max(ti+xi-x0,ti-xi+x0)
    //==max((ti+xi)-x0,x0-(xi-ti))==max(dist(x0,rigth ghost),dist(x0,left ghost))
    //so the point to minimise the distances from the farthest points(all right and left ghosts of all points)
    //is the mid point of rightmost right ghost and leftmost left ghost
    int mina=INF,maxa=-INF;
    for(int i=0;i<n;i++){
        mina=min(mina,x[i]-t[i]);
        maxa=max(maxa,x[i]+t[i]);
    }
    double ansa=((double)mina+(double)maxa)/2.0;
    cout<<fixed<<setprecision(6)<<ansa<<endl;
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