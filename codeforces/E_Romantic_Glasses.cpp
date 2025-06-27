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
//     ll n; cin>>n;
//     vector<ll> a(n);
//     vector<ll> ev;
//     vector<ll> od;
//     for(ll i=0;i<n;i++){
//        cin>>a[i];
//        if(i%2==0) ev.push_back(a[i]);
//        else od.push_back(a[i]);
//     }
//     if(n==1){
//         cout<<"NO"<<endl;
//         return;
//     }
//     // for(int i=1;i<n;i++){
//     //     if(a[i]==a[i-1]){
//     //         cout<<"YES"<<endl;
//     //         return;
//     //     }
//     // }
//     vector<ll> pe(ev.size()+1);
//     pe[0]=0;
//     vector<ll> po(od.size()+1);
//     po[0]=0;
//     for(ll i=1;i<=ev.size();i++){
//         pe[i]=pe[i-1]+ev[i-1];
//     }
//     for(ll i=1;i<=od.size();i++){
//         po[i]=po[i-1]+od[i-1];
//     }
//     pair<ll,ll> end_parity;
//     if(n%2==0){
//         end_parity={0,1};
//     }
//     else{
//         end_parity={0,0};
//     }
//     ll le=1,lo=1;
//     ll re=ev.size(),ro=od.size();
//     while(le<=ev.size() && lo<=od.size() && re>=1 && ro>=1 && le<=re && lo<=ro){
//         if(pe[re]-pe[le-1]==po[ro]-po[lo-1]){
//             cout<<"YES"<<endl;
//             return;
//         }
//         else if(pe[re]-pe[le-1]>po[ro]-po[lo-1]){
//             if(end_parity.first==0 && end_parity.second==1){
//                 le++;
//                 end_parity.first=1, end_parity.second=1;
//             }
//             else if(end_parity.first==0 && end_parity.second==0){
//                 if(a[2*(le-1)]>a[2*(re-1)]){
//                     re--;
//                     end_parity.first=0, end_parity.second=1;
//                 }
//                 else{
//                     le++;
//                     end_parity.first=1, end_parity.second=0;
//                 }
//             }
//             else if(end_parity.first==1 && end_parity.second==0){
//                 re--;
//                 end_parity.first=1, end_parity.second=1;
//             }
//             else if(end_parity.first==1 && end_parity.second==1){
//                 // if(a[2*(lo-1)+1]>a[2*(ro-1)+1]){
//                 //     ro--;
//                 //     end_parity.first=1, end_parity.second=0;
//                 // }
//                 // else{
//                 //     lo++;
//                 //     end_parity.first=0, end_parity.second=1;
//                 // }
//                 ro--;
//                 lo++;
//                 end_parity={0,0};
//             }
//         }
//         else if(pe[re]-pe[le-1]<po[ro]-po[lo-1]){
//             if(end_parity.first==0 && end_parity.second==1){
//                 ro--;
//                 end_parity.first=0, end_parity.second=0;
//             }
//             else if(end_parity.first==0 && end_parity.second==0){
//                 // if(a[2*(le-1)]>a[2*(re-1)]){
//                 //     re--;
//                 //     end_parity.first=0, end_parity.second=1;
//                 // }
//                 // else{
//                 //     le++;
//                 //     end_parity.first=1, end_parity.second=0;
//                 // }
//                 re--;
//                 le++;
//                 end_parity={1,1};
//             }
//             else if(end_parity.first==1 && end_parity.second==0){
//                 lo++;
//                 end_parity.first=0, end_parity.second=0;
//             }
//             else if(end_parity.first==1 && end_parity.second==1){
//                 if(a[2*(lo-1)+1]>a[2*(ro-1)+1]){
//                     ro--;
//                     end_parity.first=1, end_parity.second=0;
//                 }
//                 else{
//                     lo++;
//                     end_parity.first=0, end_parity.second=1;
//                 }
//             }
//         }
//     }
//     cout<<"NO"<<endl;
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


//can't figure out logical error, but my logic seems to work good

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
    ll n; cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
       ll temp;
       cin>>temp;
       if(i%2==1) a[i]=(-1)*temp;
       else a[i]=temp;
    }
    vector<ll> pref(n);
    pref[0]=a[0];
    for(ll i=1;i<n;i++){
        pref[i]=pref[i-1]+a[i];
        if(pref[i]==0){
            cout<<"YES"<<endl;
            return;
        }
    }
    unordered_map<ll,ll>um;
    for(ll i=0;i<n;i++){
        um[pref[i]]++;
        if(um[pref[i]]>=2){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
    
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}