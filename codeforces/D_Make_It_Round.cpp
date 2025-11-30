// // #include <bits/stdc++.h>

// // using namespace std;

// // template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
// // template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// // void dbg_out() { cerr << endl; }
// // template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
// // #ifdef LOCAL
// // #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
// // #else
// // #define dbg(...)
// // #endif

// // #define ar array
// // #define ll long long
// // #define ld long double
// // #define sza(x) ((int)x.size())
// // #define all(a) (a).begin(), (a).end()

// // const int MAX_N = 1e5 + 5;
// // const ll MOD = 1e9 + 7;
// // const ll INF = 1e9;
// // const ld EPS = 1e-9;

// // // Custom hash for unordered_map/set
// // struct custom_hash {
// //     static uint64_t splitmix64(uint64_t x) {
// //         x += 0x9e3779b97f4a7c15;
// //         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
// //         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
// //         return x ^ (x >> 31);
// //     }
// //     size_t operator()(uint64_t x) const {
// //         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
// //         return splitmix64(x + FIXED_RANDOM);
// //     }
// //     template<typename T, typename U>
// //     size_t operator()(const pair<T, U>& p) const {
// //         uint64_t h1 = operator()(static_cast<uint64_t>(p.first));
// //         uint64_t h2 = operator()(static_cast<uint64_t>(p.second));
// //         return h1 ^ (h2 << 1);
// //     }
// // };
// // template<typename K, typename V>
// // using safe_umap = unordered_map<K, V, custom_hash>;
// // template<typename T>
// // using safe_uset = unordered_set<T, custom_hash>;

// // pair<ll,ll> get25(ll n){
// //     ll a=0,b=0;
// //     while(n>=0 && n%2==0){
// //         n/=2;
// //         a++;
// //     }
// //     while(n>=0 && n%5==0){
// //         n/=5;
// //         b++;
// //     }
// //     return {a,b};
// // }

// // ll get5(ll n){
// //     ll a=0;
// //     while(n>=5){
// //         n/=5;
// //         a++;
// //     }
// //     return a;
// // }
// // ll get2(ll n){
// //     ll a=0;
// //     while(n>=2){
// //         n/=2;
// //         a++;
// //     }
// //     return a;
// // }
// // void solve() {
// //     ll n,m; cin>>n>>m;
// //     pair<ll,ll> temp=get25(n);
// //     ll temp5=get5(m);
// //     ll temp2=get2(m);
// //     cout<<m<<" "<<temp<<" "<<temp2<<" "<<temp5<<" ";
// //     ll ans=n;
// //     if(temp.first>temp.second){
// //         ll temp9=temp.first-temp.second;
// //         cout<<temp9<<" ";
// //         ans*=pow(5,max(temp5,temp9));
// //         cout<<ans<<" ";
// //         ll temp8=(m/ans)/10;
// //         ans*=pow(10,temp8);
// //     }
// //     else if(temp.first<temp.second){
// //         ll temp9=temp.second-temp.first;
// //         cout<<temp9<<" ";
// //         ans*=pow(2,max(temp2,temp9));
// //         cout<<ans<<" ";
// //         ll temp8=(m/ans)/10;
// //         ans*=pow(10,temp8);
// //     }
// //     else if(temp.first==temp.second){
// //         ll temp8=(m/ans)/10;
// //         cout<<ans<<" ";
// //         ans*=pow(10,temp8);
// //     }
// //     cout<<ans<<endl;
// // }

// // int main() {
// //     ios_base::sync_with_stdio(0);
// //     cin.tie(0); cout.tie(0);
// //     int tc = 1;
// //     cin >> tc;
// //     for (int t = 1; t <= tc; t++) {
// //         // cout << "Case #" << t << ": ";
// //         solve();
// //     }
// // }


// //totally flawed logic;


// #include <bits/stdc++.h>

// using namespace std;

// template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
// template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// void dbg_out() { cerr << endl; }
// template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
// #ifdef LOCAL
// #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
// #else
// #define dbg(...)
// #endif

// #define ar array
// #define ll long long
// #define ld long double
// #define sza(x) ((int)x.size())
// #define all(a) (a).begin(), (a).end()

// const int MAX_N = 1e5 + 5;
// const ll MOD = 1e9 + 7;
// const ll INF = 1e9;
// const ld EPS = 1e-9;

// // Custom hash for unordered_map/set
// struct custom_hash {
//     static uint64_t splitmix64(uint64_t x) {
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }
//     size_t operator()(uint64_t x) const {
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
//     template<typename T, typename U>
//     size_t operator()(const pair<T, U>& p) const {
//         uint64_t h1 = operator()(static_cast<uint64_t>(p.first));
//         uint64_t h2 = operator()(static_cast<uint64_t>(p.second));
//         return h1 ^ (h2 << 1);
//     }
// };
// template<typename K, typename V>
// using safe_umap = unordered_map<K, V, custom_hash>;
// template<typename T>
// using safe_uset = unordered_set<T, custom_hash>;

// int get2(int n){
//     int a=0;
//     while(n>=0 && n%2==0){
//         n/=2;
//         a++;
//     }
//     return a;
// }
// int get5(int n){
//     int a=0;
//     while(n>=0 && n%5==0){
//         n/=5;
//         a++;
//     }
//     return a;
// }
// int pet2(int n){
//     int a=0;
//     while(n>=2){
//         n/=2;
//         a++;
//     }
//     return a;
// }
// int pet5(int n){
//     int a=0;
//     while(n>=5){
//         n/=5;
//         a++;
//     }
//     return a;
// }
// void solve() {
//     int n,m; cin>>n>>m;
//     int temp2=get2(n);
//     int temp5=get5(n);
//     int top2=pet2(m);
//     int top5=pet5(m);
//     int ans=n;
//     if(temp2<temp5){
//         int temp9=temp5-temp2;
//         ans*=pow(2,max(temp2,top2));
//     }
//     else if(temp2>temp5){
//         int temp9=temp2-temp5;
//         ans*=pow(5,max(temp5,top5));
//         ans*=m/ans;
//     }
//     else if(temp2==temp5){
//         ans*=m/ans;
//     }
//     cout<<ans<<endl;
// }

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     int tc = 1;
//     cin >> tc;
//     for (int t = 1; t <= tc; t++) {
//         // cout << "Case #" << t << ": ";
//         solve();
//     }
// }
//long code huh? lets try again
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
    ll n,m; cin>>n>>m;
    ll c2=0,c5=0;
    ll p=n;
    while(p%2==0){
        p/=2;
        c2++;
    }
    p=n;
    while(p%5==0){
        p/=5;
        c5++;
    }
    ll tar=1;
    if(c2>c5) tar=c2-c5;
    if(c5>c2) tar=c5-c2;
    ll tar2=1;
    for(ll i=1;i<=tar;i++){
        if(tar2>m) break;
        if(c2>c5 && tar2*5>m) break;
        if(c5>c2 && tar2*2>m) break;
        if(c2>c5) tar2*=5;
        if(c5>c2) tar2*=2;
    }
    // cout<<tar2<<" ";
    ll temp=m/tar2;
    temp=log10(temp);
    // cout<<temp<<" ";
    temp=binpow(10,temp);
    temp=temp*tar2;
    temp=temp*(m/temp);
    cout<<temp*n<<endl;
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