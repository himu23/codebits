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

// struct hash_pair{
//     size_t operator()(const pair<int, int>& p) const {
//         return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
//     }
// };

// int temp(int n,int i,int j, unordered_map<pair<int,int>,int,hash_pair> &um){
//     // if(um.find({i,j})!=um.end()) return um[{i,j}];
//     // int temp=INT_MAX;
//     // if(i-1>=1 && j-2>=1 && um.count({i-1,j-2})) temp=min(temp,um[{i-1,j-2}]);
//     // if(i-2>=1 && j-1>=1 && um.count({i-2,j-1})) temp=min(temp,um[{i-2,j-1}]);
//     // if(i+1<=n && j-2>=1 && um.count({i+1,j-2})) temp=min(temp,um[{i+1,j-2}]);
//     // if(i+2<=n && j-1>=1 && um.count({i+2,j-1})) temp=min(temp,um[{i+2,j-1}]);
//     // if(i-2>=1 && j+1<=n && um.count({i-2,j+1})) temp=min(temp,um[{i-2,j+1}]);
//     // if(i-1>=1 && j+2<=n && um.count({i-1,j+2})) temp=min(temp,um[{i-1,j+2}]);
//     // if(i+1<=n && j+2<=n && um.count({i+1,j+2})) temp=min(temp,um[{i+1,j+2}]);
//     // if(i+2<=n && j+1<=n && um.count({i+2,j+1})) temp=min(temp,um[{i+2,j+1}]);
//     // if(i==1 && j==1) um[{i,j}]=0;
//     if(i<1 || j<1 || i>n || j>n) return INT_MAX;
//     if(i==1 && j==1) return 0;
//     if(um.find({i,j})!=um.end()) return um[{i,j}];
//     int ans=INT_MAX;
//     vector<pair<int,int>> moves={
//         {i-1,j-2}, {i-2,j-1}, {i+1,j-2}, {i+2,j-1},
//         {i-2,j+1}, {i-1,j+2}, {i+1,j+2}, {i+2,j+1}
//     };
//     for(auto [x,y]:moves){
//         int sub=temp(n,x,y,um);
//         if(sub!=INT_MAX) ans=min(ans,sub+1);
//     }
//     um[{i,j}]=ans;
//     return ans;
// }

// void solve() {
//     int n; cin>>n;
//     unordered_map<pair<int,int>,int,hash_pair> um;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             int ans=temp(n,i,j,um);
//             cout<<ans<<" ";
//         }
//         cout<<endl;
//     }
// }

// int32_t main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     int tc = 1;
//     //cin >> tc;
//     for (int t = 1; t <= tc; t++) {
//         // cout << "Case #" << t << ": ";
//         solve();
//     }
// }

//recursion gave tle
//must be done woth bfs

#include <bits/stdc++.h>

using namespace std;

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

const int MAX_N = 1e5 + 5;
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
template<typename K, typename V>
using safe_umap = unordered_map<K, V, custom_hash>;
template<typename T>
using safe_uset = unordered_set<T, custom_hash>;

//BFS on a gridf

const int dx[8]={-2,-1,1,2,2,1,-1,-2};
const int dy[8]={1,2,2,1,-1,-2,-2,-1};

void solve() {
    int n; cin>>n;
    vector<vector<int>> dist(n,vector<int>(n,-1));

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}