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

void solve() {
    int n; cin>>n;
    vector<int> a(n);
    // vector<int> c0;
    // vector<pair<int,int>> pref(n);
    // int cminus=0,c2=0;
    // for(int i=0;i<n;i++){
    //     cin>>a[i];
    //     // if(a[i]==0) c0.pb(i);
    //     if(a[i]<0) cminus++;
    //     if(a[i]==2 || a[i]==-2) c2++;
    //     if(a[i]==0) cminus=0,c2=0;
    //     pref[i]={cminus%2,c2};
    // }
    // cminus=0,c2=0;
    // vector<pair<int,int>> suff(n);
    // for(int i=n-1;i>=0;i--){
    //     if(a[i]<0) cminus++;
    //     if(a[i]==2 || a[i]==-2) c2++;
    //     if(a[i]==0) cminus=0,c2=0;
    //     suff[i]={cminus%2,c2};
    // }
    // cout<<pref<<endl<<suff<<endl;
    // int l=0,r=0;
    // int curl=n,curr=n-1;
    // int maxx=1;

    // cout<<curl<<" "<<n-1-curr<<endl;
    for(int i=0;i<n;i++) cin>>a[i];
    // vector<vector<int>> temp;
    // vector<int> temp1,temp2;
    vector<pair<int,int>> temp3;
    int temp4=0;
    for(int i=0;i<n;i++){
        // if(a[i]!=0){
        //     // temp1.pb(a[i]);
        // }
        // else{
        //     // temp.pb(temp1);
        //     // temp1=temp2;
        //     temp3.pb({temp4,i-1});
        //     temp4=i+1;
        // }
        // if(i==n-1){
        //     // temp.pb(temp1);
        //     // temp1=temp2;
        //     temp3.pb({temp4,i-1});
        //     temp4=i+1;
        // }
        if(a[i]==0){
            if(i!=0) temp3.pb({temp4,i-1});
            temp4=i+1;
        }
        else if(i==n-1) temp3.pb({temp4,i});
    }
    int maxx=0;
    int ansl=n,ansr=n-1;
    // cout<<temp3<<endl;
    for(int i=0;i<temp3.size();i++){
        // vector<int> curvec=temp[i];
        int curl=temp3[i].fi;
        int curr=temp3[i].se;
        int curpro=0;
        int cur2=0;
        for(int j=curl;j<=curr;j++){
            // curpro*=a[j];
            if(a[j]<0) curpro++;
            if(a[j]==2 || a[j]==-2) cur2++;
        }
        if(curpro%2==0){
            if(cur2>maxx){
                ansl=curl,ansr=curr;
                maxx=cur2;
            }
            continue;
        }
        int temp9=0;
        int templ=0;
        for(int j=curl;j<=curr;j++){
            templ++;
            if(a[j]==2 || a[j]==-2) temp9++;
            if(a[j]<0) break;
        }
        int temp8=0;
        int tempr=0;
        for(int j=curr;j>=curl;j--){
            tempr++;
            if(a[j]==2 || a[j]==-2) temp8++;
            if(a[j]<0) break;
        }
        int temp7=min(temp9,temp8);
        if(cur2-temp7>maxx){
            maxx=cur2-temp7;
            if(temp9>=temp8){
                ansl=curl;
                ansr=curr-tempr;
            }
            else{
                ansl=curl+templ;
                ansr=curr;
            }
        }
    }
    // cout<<binpow(2,maxx)<<endl;
    cout<<ansl<<" "<<n-1-ansr<<endl;
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