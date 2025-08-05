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
#define pb push_back
#define umap unordered_map

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
struct hash_pair{
    size_t operator()(const std::pair<int, int>& p) const {
        return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
    }
};
template<typename K, typename V>
using safe_umap = unordered_map<K, V, custom_hash>;
template<typename T>
using safe_uset = unordered_set<T, custom_hash>;

const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};

bool isboxed(int i, int j,int &n, vector<vector<bool>> &visi){
    int count=0;
    if(i+1<n && visi[i+1][j]) count++;
    if(i-1>=0 && visi[i-1][j]) count++;
    if(j+1<n && visi[i][j+1]) count++;
    if(j-1>=0 && visi[i][j-1]) count++;
    return count>=3;
}

void dfs(int i,int j, int count,int &n,int &ans,vector<vector<bool>> &visi){
    if(i>n-1 || j>n-1 || i<0 || j<0 || visi[i][j]) return;
    if(count>48){
        return;
    }
    visi[i][j]=true;
    if(isboxed(i,j,n,visi)){
        visi[i][j]=false;
        return;
    }
    if(count==48){
        ans++;
        visi[i][j]=false;
        return;
    }
    if ((i > 0 && i < n-1 && !visi[i-1][j] && !visi[i+1][j] && visi[i][j-1] && visi[i][j+1]) ||
    (j > 0 && j < n-1 && !visi[i][j-1] && !visi[i][j+1] && visi[i-1][j] && visi[i+1][j])) {
    visi[i][j] = false;
    return;
    }
    dfs(i+1,j,count+1,n,ans,visi);
    dfs(i,j+1,count+1,n,ans,visi);
    dfs(i-1,j,count+1,n,ans,visi);
    dfs(i,j-1,count+1,n,ans,visi);
    visi[i][j]=false;
}

void solve() {
    int n;
    // cin>>n;
    n=7;
    int ans=0;
    vector<vector<bool>> visi(n,vector<bool>(n,false));
    visi[0][0]=true;
    dfs(0,1,1,n,ans,visi);
    dfs(1,0,1,n,ans,visi);
    cout<<ans<<endl;
    
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    std::thread([](){
        solve();
    }).join();
}
