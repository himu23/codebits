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
#define int long long
#define ld long double
#define sza(x) ((int)x.size())
#define aint(a) (a).begin(), (a).end()
#define pb push_back
#define umap unordered_map
#define fi first
#define se second
#define pai pair<int,int>

const int MAX_N = 1e6 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;
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
int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res=(res*a)%MOD;
        a =(a*a)%MOD;
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

int findkids(int i,vector<bool> &visi, vector<vector<int>>& tree,vector<int>&kids){
    visi[i]=true;
    // if(tree[i].size()==1){
    //     kids[i]=0;
    //     return kids[i];
    // }      
    // IMP: dont write this in bfs its redundaut and will make the code fail when the tree struct is line
    //as the dfs wont get started since the parent node also has one connection
    int ans=0;
    for(int j=0;j<tree[i].size();j++){
        if(!visi[tree[i][j]]) ans+=findkids(tree[i][j],visi,tree,kids)+1;
    }
    kids[i]=ans;
    return kids[i];
}

// int findtourkids(int i,vector<bool>&visi,vector<vector<int>> & tree, vector<int>& tourkids,vector<bool>& isto){
//     visi[i]=true;
//     int ans=0;
//     for(int j=0;j<tree[i].size();j++){
//         if(!visi[tree[i][j]]){
//             ans+=findtourkids(tree[i][j],visi,tree,tourkids,isto);
//             if(!isto[tree[i][j]]) ans++;
//         }
//     }
//     tourkids[i]=ans;
//     return ans;
// }

void solve() {
    int n,k; cin>>n>>k;
    vector<vector<int>> tree(n);
    for(int i=1;i<n;i++){
        int a,b; cin>>a>>b;
        a--,b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    if(n==2 && k==1){cout<<1<<endl; return;} 
    vector<bool> visi1(n,false);
    vector<int> parents(n);
    parents[0]=0;
    queue<int> q;
    q.push(0);
    visi1[0]=true;
    while(!q.empty()){
        int cur=q.front();q.pop();
        int cur1=parents[cur];
        for(int i=0;i<tree[cur].size();i++){
            if(!visi1[tree[cur][i]]){
                visi1[tree[cur][i]]=true;
                q.push(tree[cur][i]);
                parents[tree[cur][i]]=cur1+1;
            }
        }
    }
    // cout<<parents<<endl;
    // vector<bool> isto(n,false);
    vector<int> kids(n,-1);
    vector<bool> visi(n,false);
    int kidsof1=findkids(0,visi,tree,kids);
    // cout<<kids<<endl;
    vector<pair<int,int>> temp1(n);
    for(int i=0;i<n;i++){
        temp1[i]={parents[i]-kids[i],i};
    }
    vector<int> scores(n);
    for(int i=0;i<n;i++){
        scores[i]=parents[i]-kids[i];
    }
    sort(temp1.begin(),temp1.end(),[&](const pair<int,int>&a,const pair<int,int>&b){
        //if(a.fi==b.fi) return parents[a.se]<parents[b.se];
        return scores[a.se]>scores[b.se];
    });
    // k=n-k;
    // for(int i=0;i<k;i++){
    //     isto[temp1[i].se]=true;
    // }
    // cout<<isto<<endl;
    // vector<int> tourkids(n,0);
    // for(int i=0;i<n;i++) visi[i]=false;
    // int touristkidsof1=findtourkids(0,visi,tree,tourkids,isto);
    int ans=0,ans1=0;
    // k=n-k;
    for(int i=0;i<k;i++){
        ans+=scores[temp1[i].se];
        // if(isto[i]) ans1+=tourkids[i];
    }
    // cout<<parents<<endl;
    // cout<<tourkids<<endl;
    cout<<ans<<endl;
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