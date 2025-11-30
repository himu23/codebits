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
#define fi first
#define se second
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

//-------------------------------------



// void solve() {
//     int n,m; cin>>n>>m;
//     vector<vector<int>> temp(m);
//     for(int i=0;i<m;i++){
//         int k; cin>>k;
//         while(k--){
//             int x; cin>>x;
//             x--;
//             temp[i].pb(x);
//         }
//     }
//     //two layer map maybe will do :/
//     vector<int> temp2(n,-1);
//     for(int i=0;i<temp.size();i++){
//         if(temp[i].size()==0) continue;
//         int cur=-1;
//         for(int j=0;j<temp[i].size();j++){
//             if(temp2[temp[i][j]]!=-1){
//                 cur=temp2[temp[i][j]];
//                 break;
//             }
//         }
//         if(cur==-1){
//             cur=temp[i][0];
//         }
//         for(int j=0;j<temp[i].size();j++){
//             temp2[temp[i][j]]=cur;
//         }
//     }
//     umap<int,int> um;
//     for(int i=0;i<n;i++){
//         um[temp2[i]]++;
//     }
//     vector<int> ans(n);
//     for(int i=0;i<n;i++){
//         ans[i]=um[temp2[i]];
//     }
//     cout<<ans<<endl;
// }
//flawed logic
// say 1 2 3 is group 1
// the 4 5 6 is group 4
// then comes this 3 6 shoud make all to same group but mine assigns 6 to group 1
//lets rethink, oh so it is dsu problem i dont know it lets try graphs first
//obviously its a connected components question
//i will implement both bfs and dfs




//--------------------------------------------------





//bfs
// void solve(){
//     int n,m; cin>>n>>m;
//     umap<int,vector<int>> um;
//     for(int i=0;i<m;i++){
//         int k; cin>>k;
//         if(k==0) continue;
//         int a; cin>>a;
//         a--;
//         for(int i=1;i<k;i++){
//             int b; cin>>b;
//             b--;
//             um[a].pb(b);
//             um[b].pb(a);
//         }
//     }
//     vector<bool> visi(n,false);
//     vector<int> color(n,-1);
//     for(int i=0;i<n;i++){
//         if(visi[i]) continue;
//         int cuco=color[i];
//         if(cuco==-1){
//             color[i]=i;
//             cuco=color[i];
//         }
//         visi[i]=true;
//         queue<int> q;
//         q.push(i);
//         while(!q.empty()){
//             int cur=q.front();q.pop();
//             for(int i=0;i<um[cur].size();i++){
//                 if(!visi[um[cur][i]]){
//                     visi[um[cur][i]]=true;
//                     color[um[cur][i]]=cuco;
//                     q.push(um[cur][i]);
//                 }
//             }
//         }
//     }
//     // cout<<color<<endl;
//     umap<int,int> ans;
//     for(int i=0;i<n;i++){
//         ans[color[i]]++;
//     }
//     for(int i=0;i<n;i++){
//         cout<<ans[color[i]]<<" ";
//     }
//     cout<<endl;
// }
//it worked now lets do dfs




//-------------------------------------------





//dfs
// void dfs(int n,int temp,vector<int>& color, umap<int,vector<int>>& um){
//     // int cuco=color[n];
//     // if(cuco==-1){
//     //     color[n]=n;
//     //     cuco=color[n];
//     // }
//     // for(int i=0;i<um[n].size();i++){
        
//     // }
//     // return color[n];
//     color[n]=temp;
//     for(int u:um[n]){
//         if(color[u]==-1){
//             dfs(u,temp,color,um);
//         }
//     }
// }
// void solve(){
//     int n,m; cin>>n>>m;
//     umap<int,vector<int>> um;
//     for(int i=0;i<m;i++){
//         int k; cin>>k;
//         if(k==0) continue;
//         int a; cin>>a;
//         a--;
//         for(int i=1;i<k;i++){
//             int b; cin>>b;
//             b--;
//             um[a].pb(b);
//             um[b].pb(a);
//         }
//     }
//     // vector<bool> visi(n,false);
//     vector<int> color(n,-1);
//     // dfs(0,color,um);
//     int temp=0;
//     for(int i=0;i<n;i++){
//         // color[i]=dfs(i,color,um);
//         if(color[i]==-1){
//             dfs(i,temp,color,um);
//             temp++;
//         }
//     }
//     umap<int,int> ans;
//     for(int i=0;i<n;i++){
//         ans[color[i]]++;
//     }
//     for(int i=0;i<n;i++){
//         cout<<ans[color[i]]<<" ";
//     }
//     cout<<endl;
// }
//now comes dsu



//-------------------------------------------




//dsu

// struct DSU {
//     vector<int> parent;
//     vector<int> size;

//     // Constructor: Initialize parent as itself and size as 1
//     DSU(int n) {
//         parent.resize(n + 1);
//         size.assign(n + 1, 1);
//         iota(parent.begin(), parent.end(), 0); 
//     }

//     // Find function with Path Compression
//     int find(int i) {
//         if (parent[i] == i)
//             return i;
//         return parent[i] = find(parent[i]); 
//     }

//     // Unite function with Union by Size
//     // Returns true if a merge happened, false if already in same set
//     bool unite(int i, int j) {
//         int root_i = find(i);
//         int root_j = find(j);

//         if (root_i != root_j) {
//             // Attach smaller tree to larger tree
//             if (size[root_i] < size[root_j])
//                 swap(root_i, root_j);
            
//             parent[root_j] = root_i;
//             size[root_i] += size[root_j];
//             return true;
//         }
//         return false;
//     }
// };
// //how to use it
// // int main() {
// //     int n = 5;
// //     DSU dsu(n);

// //     dsu.unite(1, 2);
// //     dsu.unite(2, 3);

// //     // Check if connected
// //     if (dsu.find(1) == dsu.find(3)) {
// //         cout << "1 and 3 are in the same component" << endl;
// //     }
    
// //     // Check size of a component
// //     cout << "Size of component containing 1: " << dsu.size[dsu.find(1)] << endl;
    
// //     return 0;
// // }

//above is the template lets do it without struct template

const int N=5e5+5;

int parent[N];
int sizee[N];

void make(int v){
    parent[v]=v;
    sizee[v]=1;
}

int find(int v){
    if(v==parent[v]) return v;
    return parent[v]=find(parent[v]);
}

void unite (int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(sizee[a]<sizee[b]) swap(a,b);
        parent[b]=a;
        sizee[a]+=sizee[b];
    }
}

void solve(){
    int n,m; cin>>n>>m;
    for(int i=0;i<n;i++) make(i);
    for(int i=0;i<m;i++){
        int k; cin>>k;
        if(k==0) continue;
        int a; cin>>a;
        a--;
        for(int i=1;i<k;i++){
            int b; cin>>b;
            b--;
            unite(a,b);
        }
    }
    for(int i=0;i<n;i++){
        cout<<sizee[find(i)]<<" ";
    }
    cout<<endl;
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
