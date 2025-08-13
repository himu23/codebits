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
    safe_umap<int,vector<int>> um;
    while(m--){
        int a,b; cin>>a>>b;
        um[a].pb(b);
        um[b].pb(a);
    }
    vector<int> parent(n+1,-1);
    vector<bool> visi(n+1,false);
    for(int i=1;i<=n;i++){
        if(visi[i]) continue;
        visi[i]=true;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int curr=q.front();q.pop();
            for(int x:um[curr]){
                if(!visi[x]){
                    visi[x]=true;
                    parent[x]=curr;
                    q.push(x);
                }
                else if(parent[curr]!=x){
                    //if(parent[curr]==x) continue;
                    //dfs for some reason for this easier i am doing bfs
                    // vector<int> path;
                    // int curt=curr;
                    // while(curt!=x){
                    //     path.pb(curt);
                    //     curt=parent[curt];
                    // }
                    // reverse(path.begin(),path.end());
                    // path.pb(x);
                    // cout<<path.size()<<endl;
                    // for(int y: path){
                    //     cout<<y<<" ";
                    // }
                    // cout<<endl;
                    // return;
                    //the above way fails because x is not a ancestor of curr
                    //so curt will never be equal to x
                    //they are both descendant of a common node like base but x is not ancestor of curr
                    //thats why the above code fails 
                    //for finding a cycle in an undirected graph: on encountring a visited node thats not the parent reconstruct the cycle by:
                    //storing the path from each end point back to the root using parent array
                    //merging at their lowest common ancestor(LCA) : walk until we meet
                    //steps: from u go uo vis parent[] until -1 store all in a set
                    //from v go up vis parent[] until you find a node in u's ancestor set thats the lca
                    set<int> pathofx;
                    int curt=x;
                    while(curt!=-1){
                        pathofx.insert(curt);
                        curt=parent[curt];
                    }
                    curt=curr;
                    while(curt!=-1){
                        if(pathofx.find(curt)!=pathofx.end()){
                            break;
                        }
                        curt=parent[curt];
                    }
                    int temp=curt;
                    vector<int>path1,path2;
                    curt=x;
                    while(curt!=temp){
                        path1.pb(curt);
                        curt=parent[curt];
                    }
                    path1.pb(temp);
                    curt=curr;
                    while(curt!=temp){
                        path2.pb(curt);
                        curt=parent[curt];
                    }
                    reverse(path1.begin(),path1.end());
                    for(int y:path2){
                        path1.pb(y);
                    }
                    path1.pb(temp);
                    cout<<path1.size()<<endl;
                    for(int y:path1){
                        cout<<y<<" ";
                    }
                    cout<<endl;
                    return;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return;
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