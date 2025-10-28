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
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    // if(n==1){
    //     if(a[0]==1) cout<<0<<endl;
    //     else cout<<1<<endl;
    //     return;
    // }
    // int l=0;
    // int ans=1;
    // for(int r=1;r<n;r++){
    //     if(a[r-1]!=a[r]){
    //         if(a[r-1]==1){
    //             ans=max(ans,r-l);
    //             l=r;
    //         }
    //         else if(a[r-1]==0 && l!=0){
    //             ans=max(ans,2+r-l);
    //             l=r;
    //         }
    //         else if(a[r-1]==0 && l==0){
    //             ans=max(ans,1+r-l);
    //             l=r;
    //         }
    //     }
    // }
    // if(a[n-1]==0 && l!=0){
    //     ans=max(ans,n-l+1);
    // }
    // else if(a[n-1]==0 && l==0){
    //     ans=max(ans,n);
    // }
    // else if(a[n-1]==1){
    //     ans=max(ans,n-l);
    // }
    // cout<<ans<<endl;
    // // totally flawed logic
    // bool flag=false;
    // for(int i=0;i<n;i++){
    //     if(a[i]==0){flag=true;break;}
    // }
    // if(!flag){
    //     cout<<n-1;
    //     return;
    // }
    // vector<int> temp;
    // int cnt=1;
    // for(int i=1;i<n;i++){
    //     if(a[i-1]!=a[i]){
    //         if(a[i-1]==1) temp.pb(-1*cnt);
    //         else temp.pb(cnt);
    //         cnt=1;
    //     }
    //     else cnt++;
    // }
    // if(a[n-1]==1) temp.pb(-1*cnt);
    // else temp.pb(cnt);
    // // cout<<temp<<endl;
    // int ans=INT_MAX;
    // // int a0=0;
    // for(int i=0;i<temp.size();i++){
    //     if(temp[i]<0){
    //         ans=min(ans,temp[i]);
    //     }
    //     // else a0=max(a0,temp[i]);
    // }
    // if(ans<0) ans*=-1;
    // // cout<<ans<<endl;
    // // int t0=0;
    // if(ans==INT_MAX) ans=0;
    // for(int i=0;i<temp.size();i++){
    //     if(temp[i]>0){
    //         int temp2,temp3;
    //         if(i!=0) temp2=temp[i-1]*-1;
    //         else temp2=0;
    //         if(i!=temp.size()-1) temp3=temp[i+1]*-1;
    //         else temp3=0;
    //         ans=max(ans,temp[i]+temp2+temp3);
    //     }
    // }
    // cout<<ans<<endl;
    //i did a harder version of this problem ,
    //i thought i had to give max length of contigous contaiing only ones
    // in this i have to flip a subarray to get max ones in the entire array
    // imagine this in a contest and you werent able to solve this just because you read it incorrectly
    // vector<int> b(n);
    // int sum=0;
    // for(int i=0;i<n;i++){
    //     sum+=a[i];
    //     if(a[i]==0) b[i]=1;
    //     else b[i]=-1;
    // }
    // vector<int> pref(n+1,0);
    // pref[0]=0;
    // // pref[1]=b[0];
    // for(int i=1;i<=n;i++){
    //     pref[i]=pref[i-1]+b[i-1];
    // }
    // int curmin=0;
    // int curmax=INT_MIN;
    // int ans=INT_MIN;
    // for(int i=1;i<=n;i++){
    //     curmax=pref[i];
    //     ans=max(ans,curmax-curmin);
    //     curmin=min(curmin,pref[i]);
    // }
    // // cout<<ans<<endl;
    // // ans=max(ans,curmax-curmin);
    // // cout<<ans<<endl;
    // sum+=ans;
    // // if(ans>0) sum+=ans;
    // cout<<sum<<endl;
    // this was one method using prefix sum 
    //lets do using kadanes algo dp
    vector<int> b(n);
    for(int i=0;i<n;i++){
        if(a[i]==0) b[i]=1;
        else b[i]=-1;
    }
    vector<int> dp(n);
    dp[0]=b[0];
    int ans=b[0];
    for(int i=1;i<n;i++){
        dp[i]=max(dp[i-1]+b[i],b[i]);
        ans=max(ans,dp[i]);
    }
    cout<<ans+sum<<endl;

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