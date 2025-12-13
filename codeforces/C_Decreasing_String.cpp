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
// #define sza(x) ((ll)x.size())
// #define all(a) (a).begin(), (a).end()
// #define pb push_back
// #define umap unordered_map
// #define fi first
// #define se second
// #define pai pair<ll,ll>

// const ll MAX_N = 1e6 + 5;
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
//     size_t operator()(const std::pair<ll, ll>& p) const {
//         return std::hash<ll>()(p.first) ^ (std::hash<ll>()(p.second) << 1);
//     }
// };
// template<typename K, typename V>
// using safe_umap = unordered_map<K, V, custom_hash>;
// template<typename T>
// using safe_uset = unordered_set<T, custom_hash>;
// ll binpow(ll a, ll b) {
//     ll res = 1;
//     while (b > 0) {
//         if (b & 1) res=(res*a)%MOD;
//         a =(a*a)%MOD;
//         b >>= 1;
//     }
//     return res;
// }
// void add_self(ll& a,ll b){
//     a+=b;
//     if(a>=MOD) a-=MOD;
// }
// bool isinbounds(ll x,ll y,ll rows,ll cols){
//     return x>=0 && y>=0 && x<rows && y<cols;
// }
// const ll dx[4]={0,1,0,-1};
// const ll dy[4]={1,0,-1,0};

// void solve() {
//     string s; cin>>s;
//     int p; cin>>p;
//     int n=s.length();
//     // int temp=n*(n+1)-2*p;
//     // // cout<<temp<<" ";
//     // temp=(temp+sqrt(1+4*temp))/2;
//     // // cout<<temp<<" ";
//     // int rem=p-(n*(n+1)-temp*(temp+1))/2;
//     // //find the char at rem index after removing (n-temp) chars
//     // temp=n-temp;
//     // cout<<temp<<" "<<rem<<endl;

//     //dont try to find which string the char belong to using maths and quadratic equations in o(1)
//     //as you will anyway have to construct that string by removing each valid char in o(n)

//     //you can always binary search on prefix sums as they are monotonic
//     vector<vector<char>> strs;
//     vector<int> lens;
//     int temp=0;
//     vector<char> curstr;
//     for(char c:s) curstr.pb(c);
//     while(curstr.size()>0){
//         temp+=curstr.size();
//         strs.pb(curstr);
//         lens.pb(temp);
//         vector<char> curtemp;
//         int idx=curstr.size()-1;
//         for(int i=0;i<curstr.size()-1;i++){
//             if(curstr[i]-'a'>curstr[i+1]-'a') {idx=i;break;}
//         }
//         for(int i=0;i<curstr.size();i++){
//             if(i!=idx) curtemp.pb(curstr[i]);
//         }
//         curstr=curtemp;
//     }
//     int l=0,r=lens.size()-1;
//     int idx=-1;
//     while(l<=r){
//         int m=l+(r-l)/2;
//         if(lens[m]>=p){
//             idx=m;
//             r=m-1;
//         }
//         else l=m+1;
//     }
//     int temp9=0;
//     if(idx-1>=0) temp9=lens[idx-1];
//     int rem=p-temp9-1;
//     // cout<<rem<<" ";
//     if(rem>=0) cout<<strs[idx][rem];
//     else cout<<strs[idx-1][strs[idx-1].size()-1];
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
//sadly it gives tle else why would it be 1600
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
    string s; cin>>s;
    int p; cin>>p;
    int n=s.length();
    stack<char> st;
    // st.push(s[0]);
    // vector<char> temp;
    // for(int i=1;i<n;i++){
    //     if(s[i]-'a'<st.top()-'a'){
    //         temp.pb(st.top());
    //         st.pop();
    //         st.push(s[i]);
    //     }
    // }
    //the nth char that will leave
    //now finding the n
    int temp1=0;
    int temp2=n;
    int idx=-1;
    while(temp1+temp2<p){
        temp1+=temp2;
        temp2--;
        idx++;
    }
    idx++;
    string res="";
    int cnt=0;
    for(int i=0;i<s.length();i++){
        if(st.empty()) {st.push(s[i]);continue;}
        while(cnt<idx && !st.empty() && s[i]-'a'<st.top()-'a'){
            st.pop(); cnt++;
            // st.push(s[i]);
        }
        // if(s[i]-'a'>=st.top()-'a') st.push(s[i]);
        st.push(s[i]);
    }
    while(cnt<idx){
        st.pop();
        cnt++;
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    int rem=p-temp1;
    cout<<res[rem-1];
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