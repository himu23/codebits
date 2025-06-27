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



// void solve() {
//     ll n,x,y; cin>>n>>x>>y;
//     vector<vector<ll>>temp(x,vector<ll>(y,0));
//     vector<ll> a(n);
//     for(ll i=0;i<n;i++){
//        cin>>a[i];
//        temp[a[i]%x][a[i]%y]++;
//     }
//     ll ans=0;
//     for(ll i=0;i<y;i++){
//         ans+=(temp[0][i])*(temp[0][i]-1)/2;
//         if(x%2==0){
//             ans+=(temp[x/2][i])*(temp[x/2][i]-1)/2;
//             for(ll j=1;j<x/2;j++){
//                 ans+=(temp[j][i])*(temp[x-j][i]);
//             }
//         }
//         else{
//             for(ll j=1;j<=x/2;j++){
//                 ans+=(temp[j][i])*(temp[x-j][i]);
//             }
//         }
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

//tle on test 3
//the above aproach is nice one i came up with but its worse than bruteforce
//lets try bruteforce below




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



// void solve() {
//     ll n,x,y; cin>>n>>x>>y;
//     vector<ll> a(n);
//     for(ll i=0;i<n;i++){
//        cin>>a[i];
//     }
//     ll ans=0;
//     for(ll i=0;i<n-1;i++){
//         for(ll j=i+1;j<n;j++){
//             if((a[i]+a[j])%x==0 && (abs(a[i]-a[j]))%y==0) ans++;
//         }
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

//tle on test 5, its brute force




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



// void solve() {
//     ll n,x,y; cin>>n>>x>>y;
//     vector<ll> a(n);
//     unordered_map<ll,unordered_map<ll,ll>> um;
//     for(ll i=0;i<n;i++){
//        cin>>a[i];
//        um[a[i]%x][a[i]%y]++;
//     }
//     ll ans=0;
//     unordered_set<ll> visited;
//     for(auto &outer : um){
//         ll outerkey=outer.first;
//         if(visited.count(outerkey)) continue;

//         ll comp=x-outerkey;
//         visited.insert(outerkey);
//         visited.insert(comp);
//         auto &inner_map=um[outerkey];
//         if(outerkey==0 || (x%2==0 && outerkey==x/2)){
//             for(auto &inner : inner_map){
//                 ll count=inner.second;
//                 ans+=count*(count-1)/2;
//             }
//         }
//         else if(um.count(comp)){
//             for(auto &inner : inner_map){
//                 ll inner_key=inner.first;
//                 ll count1=inner.second;
//                 ll count2=um[comp][inner_key];
//                 ans+=count1*count2;
//             }
//         }
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

//gives tle on test 22 btw it was also kind of bruteforce;
//lets think in modular arithmetics




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



// void solve() {
//     ll n,x,y; cin>>n>>x>>y;
//     vector<ll> a(n);
//     unordered_map<ll,unordered_map<ll,ll>> temp;
//     for(ll i=0;i<n;i++){
//        cin>>a[i];
//        temp[a[i]%y][a[i]%x]++;
//     }
//     ll ans=0;
//     for(auto &[remy,mp]:temp){
//         for(auto &[remx,count]: mp){
//             ll comp=(x-remx)%x;
//             if(remx==comp){
//                 ans+=count*(count-1)/2;
//             }
//             else if(mp.count(comp) && remx<comp){
//                 ans+=count*mp[comp];
//             }
//         }
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

//same shit tle on test 22



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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // https://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(ll x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    ll n,x,y; cin>>n>>x>>y;
    vector<ll> a(n);
    unordered_map<ll, unordered_map<ll, ll, custom_hash>, custom_hash> um;
    for(ll i=0; i<n;i++){
        cin>>a[i];
        um[a[i]%x][a[i]%y]++;
    }
    ll ans=0;
    unordered_set<ll, custom_hash> visited;
    for(auto &outer : um){
        ll outerkey=outer.first;
        if(visited.count(outerkey)) continue;
        ll comp=(x-outerkey)%x;
        visited.insert(outerkey);
        visited.insert(comp);
        auto &inner_map=um[outerkey];
        if(outerkey==0 || (x%2==0 && outerkey==x/2)){
            for(auto &inner : inner_map){
                ll count=inner.second;
                ans+=count*(count-1)/2;
            }
        }
        else if(um.count(comp)){
            for(auto &inner : inner_map){
                ll inner_key=inner.first;
                ll count1=inner.second;
                ll count2=um[comp][inner_key];
                ans+=count1*count2;
            }
        }
    }

    cout<<ans<<endl;
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

//custom hash