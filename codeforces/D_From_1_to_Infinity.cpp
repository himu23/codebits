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

// ll func(ll cur){
//     if(cur==0) return 1;
//     return 45*cur*binpow(10,cur-1);
// }

// void solve() {
//     ll n; cin>>n;
//     if(n<=9){
//         cout<<n*(n+1)/2<<endl;
//         return;
//     }
//     ll pos;
//     ll cur;
//     ll cur2=0;
//     // if(n<=9){pos=n,cur=1;}
//     // else if(n<=189) pos=n-9,cur=2;
//     // else if(n<=2889) pos=n-189,cur=3;
//     // else if(n<=38889) pos=n-2889,cur=4;
//     for(ll i=1;i<=100;i++){
//         ll temp=cur2;
//         cur2=9*pow(10,i-1)*i+cur2;
//         if(n<=cur2){
//             pos=n-temp;
//             cur=i;
//             break;
//         }
//     }
//     ll num=pos/cur;
//     ll num2=pos%cur;
//     num=pow(10,cur-1)+num-1;
//     if(num2==0) num2=cur;
//     else num++;
//     // cout<<num<<endl;
//     // cout<<to_string(num)[num2-1]<<endl;
//     ll sumnum=0;
//     for(ll i=0;i<=num2-1;i++){
//         sumnum+=to_string(num)[i]-'0';
//     }
//     num--;
//     // // cout<<num<<endl;
//     // // cout<<sumnum<<endl;
//     // ll sum=0;
//     // // cout<<cur<<endl;
//     // sum+=45*(cur-1)*binpow(10,cur-2);
//     // // cout<<sum<<endl;
//     // ll starter=binpow(10,cur-1);
//     // // cout<<num<<endl;
//     // // cout<<starter<<endl;
//     // // cout<<num-1<<endl;
//     // num--;
//     // if(num<starter){
//     //     cout<<sum+sumnum<<endl;
//     //     return;
//     // }
//     // ll t1=(num/starter)-1;
    
//     // // cout<<t1<<endl;
//     // // cout<<sumnum+sumofdigitsofallnumsbefore_num(num)<<endl;
//     // // cout<<to_string(num)[num2-1]<<endl;
//     // // ll ans=(ll)(45*(9*(double)cur+1)*pow(10,n-2));
//     // // cout<<ans<<endl;
//     // // cout<<sumnum+sum<<endl;
//     //someting was off i have to find sum of all digits from 0 to num (inclusive)
//     //ans is sumnum + that sum yeah its big my first 1600 problem
//     ll ans=0;
//     string s=to_string(num);
//     vector<ll> digits;
//     for(ll i=0;i<s.length();i++){
//         digits.pb(s[i]-'0');
//     }
//     // cout<<cur<<endl;
//     ll msd=(ll)log10(num)+1;
//     ll mum=num;
//     ll sum=0;
//     for(ll i=0;i<msd;i++){
//         mum/=10;
//         cur--;
//         ll temp=digits[i];
//         ll temp2=(temp)*(temp-1)/2;
//         sum+=(temp2*binpow(10,cur)+temp*func(cur)+temp*mum);
//     }
//     // cout<<digits<<endl;
//     // cout<<num<<endl;
//     // cout<<msd<<endl;
//     cout<<sum+sumnum<<endl;
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

ll func(ll cur){
    if(cur==0) return 0;
    return 45*cur*binpow(10,cur-1);
}

void solve() {
    ll n; cin>>n;
    if(n<=9){
        cout<<n*(n+1)/2<<endl;
        return;
    }
    // if(n==10 || n==11){
    //     cout<<46<<endl;
    //     return;
    // }
    ll pos,cur,cur2=0;
    for(ll i=1;i<=100;i++){
        ll temp=cur2;
        cur2=9*binpow(10,i-1)*i+cur2;
        if(n<=cur2){
            pos=n-temp;
            cur=i;
            break;
        }
    }
    ll num=pos/cur;
    ll num2=pos%cur;
    num=pow(10,cur-1)+num-1;
    if(num2==0) num2=cur;
    else num++;
    ll sumnum=0;
    for(ll i=0;i<=num2-1;i++){
        sumnum+=to_string(num)[i]-'0';
    }
    // cout<<cur<<endl;
    if(num==binpow(10,cur-1)) cur--;
    num--;
    // cout<<num<<" "<<sumnum<<endl;
    string s=to_string(num);
    vector<ll> digits;
    for(ll i=0;i<s.length();i++){
        digits.pb(s[i]-'0');
    }
    ll msd=(ll)log10(num)+1;
    ll mum=num;
    ll sum=0;
    for(ll i=0;i<msd && mum>0;i++){
        cur--;
        mum=mum%(binpow(10,cur));
        ll temp=digits[i];
        ll temp2=(temp)*(temp-1)/2;
        // cout<<temp<<" "<<temp2<<" "<<cur<<" "<<mum<<" "<<msd<<endl;
        sum+=((temp2)*binpow(10,cur)+temp*func(cur)+temp*(mum+1));
    }
    // cout<<sumnum<<endl;
    cout<<sum+sumnum<<endl;
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


///letsssss gooooooo my firt 1600 yeah it was heavy i did it all on my own without seeing tutorial