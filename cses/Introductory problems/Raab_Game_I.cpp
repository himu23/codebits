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



// // void solve() {
// //     int n,a,b; cin>>n>>a>>b;
// //     if(a+b>n){
// //         cout<<"NO"<<endl;
// //         return;
// //     }
// //     if(a+b==1){
// //         cout<<"NO"<<endl;
// //         return;
// //     }
// //     //int c=n-(a+b);
// //     vector<int> temp1(n);
// //     vector<int> temp2(n);
// //     for(int i=0;i<n;i++){
// //         temp2[i]=i+1;
// //     }
// //     for(int i=a+b-1;i<n;i++){
// //         temp1[i]=i+1;
// //     }
// //     for(int i=0;i<a;i++){
// //         temp1[i]=a+b-i;
// //     }
// //     for(int i=a;i<a+b;i++){
// //         temp1[i]=1+(i-a);
// //     }
// //     cout<<"YES"<<endl;
// //     for(int i=0;i<n;i++){
// //         cout<<temp1[i]<<" ";
// //     }
// //     cout<<endl;
// //     for(int i=0;i<n;i++){
// //         cout<<temp2[i]<<" ";
// //     }
// //     cout<<endl;

// // }

// // int32_t main() {
// //     ios_base::sync_with_stdio(0);
// //     cin.tie(0); cout.tie(0);
// //     int tc = 1;
// //     cin >> tc;
// //     for (int t = 1; t <= tc; t++) {
// //         // cout << "Case #" << t << ": ";
// //         solve();
// //     }
// // }

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



// void solve() {
//     int n,a,b; cin>>n>>a>>b;
//     if(a+b>n){
//         cout<<"NO"<<endl;
//         return;
//     }
//     if((a>0 && b==0) || (a==0 && b>0)){
//         cout<<"NO"<<endl;
//         return;
//     }

//     vector<int> temp1(n);
//     vector<int> temp2(n);
//     for(int i=0;i<n;i++){
//         temp2[i]=i+1;
//     }
//     vector<bool> temp3(n+1,false);
//     int c=n-(a+b);
//     for(int i=a;i<a+c;i++){
//         temp1[i]=temp2[i];
//         temp3[temp2[i]]=true;
//     }
//     for(int i=0;i<a;i++){
//         for(int j=n;j>=temp2[i];j--){
//             if(!temp3[j]){
//                 temp3[j]=true;
//                 temp1[i]=j;
//                 break;
//             }
//         }
//         if(temp1[i]==0){
//             cout<<"NO"<<endl;
//             return;
//         }
//     }
//     for(int i=c+a;i<n;i++){
//         for(int j=1;j<temp2[i];j++){
//             if(!temp3[j]){
//                 temp3[j]=true;
//                 temp1[i]=j;
//                 break;
//             }
//         }
//         if(temp1[i]==0){
//             cout<<"NO"<<endl;
//             return;
//         }
//     }
//     for(int i=1;i<=n;i++){
//         if(!temp3[i]){
//             cout<<"NO"<<endl;
//             return;
//         }
//     }
//     int tem1=0,tem2=0;
//     for(int i=0;i<n;i++){
//         if(temp1[i]>temp2[i]) tem1++;
//         else if(temp2[i]>temp1[i]) tem2++;
//     }
//     if(!(tem1==a && tem2==b)){
//         cout<<"NO"<<endl;
//         return;
//     }
//     cout<<"YES"<<endl;
//     for(int i=0;i<n;i++){
//         cout<<temp1[i]<<" ";
//     }
//     cout<<endl;
//     for(int i=0;i<n;i++){
//         cout<<temp2[i]<<" ";
//     }
//     cout<<endl;

    
// }

// int32_t main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     int tc = 1;
//     cin >> tc;
//     for (int t = 1; t <= tc; t++) {
//         // cout << "Case #" << t << ": ";
//         solve();
//     }
// }


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



void solve() {
    int n,a,b; cin>>n>>a>>b;
    if(a+b>n){
        cout<<"NO"<<endl;
        return;
    }
    if((a==0 && b!=0)||(b==0 && a!=0)){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    int c=n-(a+b);
    for(int i=b+1;i<=a+b;i++){
        cout<<i<<" ";
    }
    for(int i=1;i<=b;i++){
        cout<<i<<" ";
    }
    for(int i=a+b+1;i<=n;i++){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<" ";
    }
    cout<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}