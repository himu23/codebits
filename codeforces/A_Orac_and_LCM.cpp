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

// vector<ll> getprimestill_n(ll n) {
//     vector<ll> primes;
//     vector<bool> allnums(n + 1, true);
//     allnums[0] = allnums[1] = false;

//     for (ll i = 2; i * i <= n; i++) {
//         if (!allnums[i]) continue;
//         for (long long j =i * i; j <= n; j += i) {
//             allnums[j] = false;
//         }
//     }

//     for (ll i = 2; i <= n; i++) {
//         if (allnums[i]) primes.push_back(i);
//     }
//     return primes;
// }

void solve() {
    int n; cin>>n;
    vector<int> a(n);
    // int maxx=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        // maxx=max(maxx,a[i]);
    }
    // // vector<int> temp;
    // int ans=a[0]*a[1]/gcd(a[1],a[0]);
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         // temp.pb(a[i]*a[j]/gcd(a[i],a[j]));
    //         ans=gcd(ans,a[i]*a[j]/gcd(a[i],a[j]));
    //     }
    // }
    // // cout<<temp<<endl;
    // cout<<ans<<endl;


    //min of pairwise max's== second smallest element
    // int temp=sqrt(maxx)+1;
    // vector<int> prims=getprimestill_n(maxx);
    // cout<<prims<<endl;
    // vector<vector<int>> temp2 (n,vector<int>(prims.size(),0));
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<prims.size();j++){
    //         int cur=0,cur1=prims[j];
    //         int temp3=a[i];
    //         while(temp3%cur1==0){
    //             temp3/=cur1;
    //             cur++;
    //         }
    //         temp2[i][j]=cur;
    //     }
    // }


    ll ans=1;

    // for(int j=0;j<prims.size();j++){
    //     int min1=INT_MAX,min2=INT_MAX;
    //     for(int i=0;i<n;i++){
    //         int cur=0,cur1=prims[j];
    //         int temp3=a[i];
    //         while(temp3%cur1==0){
    //             temp3/=cur1;
    //             cur++;
    //         }
    //         if(cur<min1){
    //             min2=min1;
    //             min1=cur;
    //         }
    //         else if(cur<min2) min2=cur;
    //     }
    //     ans*=binpow(prims[j],min2);
    // }
    safe_umap<int,vector<int>> um;
    for(int i=0;i<n;i++){
        int cur=a[i];
        safe_umap<int,int> um1;
        while(cur%2==0){
            um1[2]++;
            cur/=2;
        }
        for(int j=3;j*j<=cur;j+=2){
            while(cur%j==0){
                um1[j]++;
                cur/=j;
            }
        }
        if(cur>1) um1[cur]++;
        for(auto paa:um1){
            um[paa.fi].pb(paa.se);
        }
        // for(auto paa:um){
        //     if(um1.find(paa.fi)!=um1.end()) um[paa.fi].pb(um1[paa.fi]);
        //     else um[paa.fi].pb(0);
        // }
    }
    // int maxx=0;
    // for(auto paa:um){
    //     maxx=max(maxx,(int)paa.se.size());
    // }
    // for(auto paa:um){
    //     int cur=(int)paa.se.size();
    //     cur=maxx-cur;
    //     for(int i=0;i<cur;i++){
    //         um[paa.fi].pb(0);
    //     }
    // }
    // safe_umap<int,int> missingzeros;
    // for(auto paa:um){
    //     int cur=(int) paa.se.size();
    //     cur=maxx-cur;
    //     missingzeros[paa.fi]=cur;
    // }
    for(auto paa:um){
        int missingzeros=n-um[paa.fi].size();
        if(missingzeros>=2){
            continue;
        }
        bool flag=false;
        if(missingzeros==1) flag=true;

        int cur=paa.fi;
        vector<int> temp=paa.se;
        int min1=INT_MAX,min2=INT_MAX;
        for(int i=0;i<temp.size();i++){
            if(temp[i]<=min1){
                min2=min1;
                min1=temp[i];
            }
            else if(temp[i]<=min2){
                min2=temp[i];
            }
        }
        if(flag) ans*=(ll)binpow(cur,min1);
        else ans*=(ll)binpow(cur,min2);
    }
    //gives mle cuz of pushing all those zeros making a prefect rectangle matrix
    // use the size of the vector to deduce how many zeros are missing

    // for(int j=0;j<prims.size();j++){
    //     int min1=INT_MAX,min2=INT_MAX;
    //     for(int i=0;i<n;i++){
    //         if(temp2[i][j]<min1){
    //             min2=min1;
    //             min1=temp2[i][j];
    //         }
    //         else if(temp2[i][j]<min2) min2=temp2[i][j];
    //     }
    //     if(min2==INT_MAX) min2=min1;
    //     ans*=binpow(prims[j],min2);
    // }
    cout<<ans<<endl;
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