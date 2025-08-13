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
    int n,m; cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    pair<int,int> start,end;
    for(int i=0;i<n;i++){
        string s; cin>>s;
        for(int j=0;j<m;j++){
            grid[i][j]=s[j];
            if(s[j]=='A'){
                start.first=i;
                start.second=j;
            }
            if(s[j]=='B'){
                end.first=i;
                end.second=j;
            }
        }
    }
    vector<vector<bool>> visi(n,vector<bool>(m,false));
    // umap<pair<int,int>,pair<int,int>,hash_pair> parent;
    // umap<pair<int,int>,int,hash_pair> tracer;  //haashing didt work
    vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m));
    vector<vector<int>> tracer(n,vector<int>(m));
    vector<vector<int>> dis(n,vector<int>(m,INF));
    dis[start.first][start.second]=0;
    queue<pair<int,int>> q;
    q.push({start.first,start.second});
    while(!q.empty()){
        pair<int,int>p=q.front();q.pop();
        //visi[p.first][p.second]=true;
        int curr=dis[p.first][p.second];
        for(int k=0;k<4;k++){
            int i1=p.first+dx[k];
            int j1=p.second+dy[k];
            if(isinbounds(i1,j1,n,m) && !visi[i1][j1] && (grid[i1][j1]=='.' || grid[i1][j1]=='B')){
                visi[i1][j1]=true;
                parent[i1][j1]={p.first,p.second};
                tracer[i1][j1]=k;
                q.push({i1,j1});
                dis[i1][j1]=curr+1;
            }
        }
    }
    if(dis[end.first][end.second]>=INF){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    cout<<dis[end.first][end.second]<<endl;
    vector<int> ans;
    // queue<pair<int,int>>qu;
    // qu.push({end.first,end.second});
    // while(!qu.empty()){
    //     pair<int,int>p=qu.front(); qu.pop();
    //     ans.push_back(tracer[{p.first,p.second}]);
    //     qu.push(parent[{p.first,p.second}]);
    // } //incorrect keeps looping
    pair<int,int>cur=end;
    while(cur!=start){
        int move=tracer[cur.f][cur.s];
        ans.pb(move);
        cur=parent[cur.f][cur.s];
    } //this way is good
    //reverse(ans.begin(),ans.end());
    vector<char> dires={'R','D','L','U'};
    for(int i=ans.size()-1;i>=0;i--){
        cout<<dires[ans[i]];
    }
    cout<<endl;
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

//// note: Avoid unordered_map<pair<int,int>, ...> for grid BFS.
// Even with custom hash to prevent collisions, it's much slower than 2D arrays.
// Reasons:
// 1. Hashing overhead + pointer chasing hurts performance.
// 2. Dynamic allocations cause cache misses.
// 3. Millions of key constructions in BFS add huge constant factor.
// Use fixed-size 2D vectors for O(1) direct access and cache-friendly speed.
