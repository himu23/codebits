// // //author: himu23
// // #include <bits/stdc++.h>
// // // #include<ext/pb_ds/assoc_container.hpp>
// // // #include<ext/pb_ds/tree_policy.hpp>

// // using namespace std;
// // // using namespace __gnu_pbds;
// // // template<typename T>
// // // using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

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
// // #define pb push_back
// // #define umap unordered_map
// // #define f first
// // #define s second
// // #define pai pair<int,int>

// // const int MAX_N = 1e6 + 5;
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
// // struct hash_pair{
// //     size_t operator()(const std::pair<int, int>& p) const {
// //         return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
// //     }
// // };
// // template<typename K, typename V>
// // using safe_umap = unordered_map<K, V, custom_hash>;
// // template<typename T>
// // using safe_uset = unordered_set<T, custom_hash>;
// // ll binpow(ll a, ll b) {
// //     ll res = 1;
// //     while (b > 0) {
// //         if (b & 1) res *= a;
// //         a *= a;
// //         b >>= 1;
// //     }
// //     return res;
// // }
// // void add_self(int& a,int b){
// //     a+=b;
// //     if(a>=MOD) a-=MOD;
// // }
// // bool isinbounds(int x,int y,int rows,int cols){
// //     return x>=0 && y>=0 && x<rows && y<cols;
// // }
// // const int dx[4]={0,1,0,-1};
// // const int dy[4]={1,0,-1,0};

// // void solve() {
// //     int n; cin>>n;
// //     vector<int> a(n);
// //     for(int i=0;i<n;i++){
// //         cin>>a[i];
// //     }
// //     vector<int> b(n);
// //     for(int i=0;i<n;i++){
// //         cin>>b[i];
// //     }
// //     vector<int> c(n);
// //     for(int i=0;i<n;i++){
// //         cin>>c[i];
// //     }
// //     vector<vector<int>> arr;
// //     for(int i=0;i<n;i++){
// //         vector<int> temp;
// //         temp.pb(a[i]);
// //         temp.pb(b[i]);
// //         temp.pb(c[i]);
// //         arr.pb(temp);
// //     }
// //     sort(arr.begin(),arr.end(),greater<>());
// //     cout<<arr<<endl;
// //     int ans=0;
// //     for(int i=0;i<3;i++){
// //         ans+=arr[i][i];
// //     }
// //     cout<<ans<<endl;
// // }

// // int32_t main() {
// //     ios_base::sync_with_stdio(0);
// //     cin.tie(0); cout.tie(0);
// //     int tc = 1;
// //     cin >> tc;
// //     for (int t = 1; t <= tc; t++) {
// //         // cout << "Case #" << t << ": ";
// //         solve();
// //         //cout<<fixed<<setprecision(12)<<
// //     }
// // }
// //flawed logic
// //author: himu23
// #include <bits/stdc++.h>
// // #include<ext/pb_ds/assoc_container.hpp>
// // #include<ext/pb_ds/tree_policy.hpp>

// using namespace std;
// // using namespace __gnu_pbds;
// // template<typename T>
// // using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

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
// #define pb push_back
// #define umap unordered_map
// #define f first
// #define s second
// #define pai pair<int,int>

// const int MAX_N = 1e6 + 5;
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
// struct hash_pair{
//     size_t operator()(const std::pair<int, int>& p) const {
//         return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
//     }
// };
// template<typename K, typename V>
// using safe_umap = unordered_map<K, V, custom_hash>;
// template<typename T>
// using safe_uset = unordered_set<T, custom_hash>;
// ll binpow(ll a, ll b) {
//     ll res = 1;
//     while (b > 0) {
//         if (b & 1) res *= a;
//         a *= a;
//         b >>= 1;
//     }
//     return res;
// }
// void add_self(int& a,int b){
//     a+=b;
//     if(a>=MOD) a-=MOD;
// }
// bool isinbounds(int x,int y,int rows,int cols){
//     return x>=0 && y>=0 && x<rows && y<cols;
// }
// const int dx[4]={0,1,0,-1};
// const int dy[4]={1,0,-1,0};

// void solve() {
//     int n; cin>>n;
//     vector<int> a(n);
//     int ma=0,mb=0,mc=0;
//     int na=0,nb=0,nc=0;
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//         if(a[i]>=ma) {na=i;ma=a[i];}
//     }
//     vector<int> b(n);
//     for(int i=0;i<n;i++){
//         cin>>b[i];
//         if(b[i]>=mb && i!=na) {nb=i;mb=b[i];}
//     }
//     vector<int> c(n);
//     for(int i=0;i<n;i++){
//         cin>>c[i];
//         if(c[i]>=mc && i!=na && i!=nb) {mc=c[i];nc=i;}
//     }
//     int ans=0;
//     vector<int>temp={na,nb,nc};
//     // cout<<temp<<endl;
//     for(int i=0;i<3;i++){
//         for(int j=i+1;j<3;j++){
//             for(int k=j+1;k<3;k++){
//                 ans=max(ans,a[temp[i]]+b[temp[j]]+c[temp[k]]);
//             }
//         }
//     }
//     cout<<ans<<endl;

// }

// int32_t main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     int tc = 1;
//     cin >> tc;
//     for (int t = 1; t <= tc; t++) {
//         // cout << "Case #" << t << ": ";
//         solve();
//         //cout<<fixed<<setprecision(12)<<
//     }
// }
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

void solve() {
    int n; cin>>n;
    vector<int> a(n);
    int a1=0,a2=0,a3=0,a11=0,a22=0,a33=0;
    int b1=0,b2=0,b3=0,b11=0,b22=0,b33=0;
    int c1=0,c2=0,c3=0,c11=0,c22=0,c33=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>a1){
            a3=a2; a33=a22;
            a2=a1; a22=a11;
            a1=a[i]; a11=i;
        }
        else if(a[i]>a2){
            a3=a2; a33=a22;
            a2=a[i]; a22=i;
        }
        else if(a[i]>a3){
            a3=a[i]; a33=i;
        }
    }
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
        if(b[i]>b1){
            b3=b2; b33=b22;
            b2=b1; b22=b11;
            b1=b[i]; b11=i;
        }
        else if(b[i]>b2){
            b3=b2; b33=b22;
            b2=b[i]; b22=i;
        }
        else if(b[i]>b3){
            b3=b[i]; b33=i;
        }
    }
    vector<int> c(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
        if(c[i]>c1){
            c3=c2; c33=c22;
            c2=c1; c22=c11;
            c1=c[i]; c11=i;
        }
        else if(c[i]>c2){
            c3=c2; c33=c22;
            c2=c[i]; c22=i;
        }
        else if(c[i]>c3){
            c3=c[i]; c33=i;
        }
    }
    //queue too long
    vector<int> a111={a11,a22,a33};
    vector<int> b111={b11,b22,b33};
    vector<int> c111={c11,c22,c33};
    int ans=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(a111[i]==b111[j] || a111[i]==c111[k] || b111[j]==c111[k]) continue;
                ans=max(ans,a[a111[i]]+b[b111[j]]+c[c111[k]]);
            }
        }
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