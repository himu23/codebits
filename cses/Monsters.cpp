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
    vector<pair<int,int>> mosters;
    pair<int,int> hero;
    for(int i=0;i<n;i++){
        string s; cin>>s;
        for(int j=0;j<m;j++){
            grid[i][j]=s[j];
            if(s[j]=='M'){
                mosters.pb({i,j});
            }
            if(s[j]=='A') hero={i,j};
        }
    }
    if(hero.f==0 || hero.s==0 || hero.f==n-1 || hero.s==m-1){
        cout<<"YES"<<endl;
        cout<<0<<endl;
        return;
    }
    int nummos=mosters.size();
    //vector<vector<pair<int,int>>> pathsofhero;
    vector<vector<int>> disfrommos(n,vector<int>(m,INF));
    vector<vector<bool>> visi(n,vector<bool>(m,false));
    queue<pair<int,int>> q;
    for(int i=0;i<nummos;i++){
        q.push({mosters[i].f,mosters[i].s});
        disfrommos[mosters[i].f][mosters[i].s]=0;
        visi[mosters[i].f][mosters[i].s]=true;
    }
    while(!q.empty()){
        pair<int,int> cur=q.front();q.pop();
        int temp=disfrommos[cur.f][cur.s];
        //visi[cur.f][cur.s]=true;
        for(int k=0;k<4;k++){
            int i1=cur.f+dx[k];
            int j1=cur.s+dy[k];
            if(isinbounds(i1,j1,n,m) && grid[i1][j1]!='#' && !visi[i1][j1]){
                visi[i1][j1]=true;
                disfrommos[i1][j1]=temp+1;
                q.push({i1,j1});
            }
        }
    }
    vector<vector<int>> disfromhero(n,vector<int>(m,INF));
    vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m,{-1,-1}));
    vector<vector<int>> move(n,vector<int>(m));
    vector<vector<bool>> vis(n,vector<bool>(m));
    q.push(hero);
    disfromhero[hero.f][hero.s]=0;
    vis[hero.f][hero.s]=true;
    while(!q.empty()){
        pair<int,int>cur=q.front();q.pop();
        int temp=disfromhero[cur.f][cur.s];
        for(int k=0;k<4;k++){
            int i1=cur.f+dx[k];
            int j1=cur.s+dy[k];
            if(isinbounds(i1,j1,n,m) && !vis[i1][j1] && disfrommos[i1][j1]>temp+1 && grid[i1][j1]!='#'){
                q.push({i1,j1});
                vis[i1][j1]=true;
                disfromhero[i1][j1]=temp+1;
                move[i1][j1]=k;
                parent[i1][j1]={cur.f,cur.s};
                if(i1==0 || j1==0 || i1==n-1 || j1==m-1){
                    cout<<"YES"<<endl;
                    vector<int>path;
                    pair<int,int> curt={i1,j1};
                    while(curt!=hero){
                        path.pb(move[curt.f][curt.s]);
                        curt=parent[curt.f][curt.s];
                    }
                    reverse(path.begin(),path.end());
                    cout<<path.size()<<endl;
                    vector<char> dire={'R','D','L','U'};
                    for(int i=0;i<path.size();i++){
                        cout<<dire[path[i]];
                    }
                    cout<<endl;
                    return;
                }
            }
        }
    }
    cout<<"NO"<<endl;
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