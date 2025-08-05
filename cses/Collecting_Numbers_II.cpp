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
// #define pb push_back
// #define umap unordered_map

// const int MAX_N = 1e5 + 5;
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

// const int dx[4]={0,1,0,-1};
// const int dy[4]={1,0,-1,0};



// void solve() {
//     int n,m; cin>>n>>m;
//     vector<int> a(n);
//     for(int i=0;i<n;i++){
//        cin>>a[i];
//     }
//     vector<pair<int,int>> temp;
//     for(int i=0;i<n;i++){
//         temp.push_back({a[i],i+1});
//     }
//     sort(temp.begin(),temp.end());
//     int ans=1;
//     for(int i=0;i<n-1;i++){
//         if(temp[i].second>temp[i+1].second) ans++;
//     }
//     safe_umap<int,int> temp2;
//     for(int i=0;i<n;i++){
//         temp2[temp[i].second]=temp[i].first;
//     }
//     vector<int> temp3(n);
//     for(int i=0;i<n;i++){
//         temp3[temp[i].first-1]=temp[i].second;
//     }
//     //cout<<temp3<<endl;
//     while(m--){
//         int i1,i2; cin>>i1>>i2;
//         if(i1==i2){
//             cout<<ans<<'\n';
//             continue;
//         }
//         if(i1>i2){
//             swap(i1,i2);
//         }
//         bool f0=false;
//         if(i2==i1+1) f0=true;
//         // int i=min(i1,i2);
//         // int j=max(i1,i2);
//         // if(temp2[j]<temp2[i]) ans--;
//         // else ans++;
//         // cout<<ans<<endl;
//         // i1=a[i],i2=a[j];
//         // a[i]=i2,a[j]=i1; 
//         int a1=temp2[i1],a2=temp2[i2];
//         //cout<<a1<<" "<<a2<<endl;
//         temp2[i1]=a2,temp2[i2]=a1;
//         //vector<int> temp4=temp3;
//         bool f1=false,f2=false,f3=false,f4=false,f5=false,f6=false,f7=false,f8=false;
//         if(a1>0 && temp3[a1]>temp3[a1-1]) f1=true;
//         if(f0 && a2>0 && temp3[a2]>temp3[a2-1]) f2=true;
//         if(a1>0 && temp3[a1]<temp3[a1-1]) f3=true;
//         if(f0 && a2>0 && temp3[a2]<temp3[a2-1]) f4=true;
//         if(!f0 && a1<n-1 && temp3[a1]>temp3[a1+1]) f5=true;
//         if(a2<n-1 && temp3[a2]>temp3[a2+1]) f6=true;
//         if(!f0 && a1<n-1 && temp3[a1]<temp3[a1+1]) f7=true;
//         if(a2<n-1 && temp3[a2]<temp3[a2+1]) f8=true;
//         temp3[a2-1]=i1,temp3[a1-1]=i2;
//         // cout<<temp4<<endl;  
//         // cout<<temp3<<endl;
//         a1--,a2--;
//         // cout<<a1<<" "<<a2<<endl;
//         if(a1>0 && f1 && temp3[a1]<temp3[a1-1]) ans++;
//         if(a2>0 && f2 && temp3[a2]<temp3[a2-1]) ans++;
//         if(a1>0 && f3 && temp3[a1]>temp3[a1-1]) ans--;
//         if(a2>0 && f4 && temp3[a2]>temp3[a2-1]) ans--;
//         if(a1<n-1 && f5 && temp3[a1]<temp3[a1+1]) ans--;
//         if(a2<n-1 && f6 && temp3[a2]<temp3[a2+1]) ans--;
//         if(a1<n-1 && f7 && temp3[a1]>temp3[a1+1]) ans++;
//         if(a2<n-1 && f8 && temp3[a2]>temp3[a2+1]) ans++;
//         cout<<ans<<endl;
//     }
// }

// int32_t main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     int tc = 1;
//     //cin >> tc;
//     for (int t = 1; t <= tc; t++) {
//         // cout << "Case #" << t << ": ";
//         solve();
//     }
// }


#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;

int n,m,cnt,x[maxN],pos[maxN];

void update(int a,int b){
    if(pos[x[a]-1]<=pos[x[a]] && b<pos[x[a]-1]) cnt++;
    if(pos[x[a]-1]>pos[x[a]] && b>=pos[x[a]-1]) cnt--;
    if(pos[x[a]+1]>=pos[x[a]] && b>pos[x[a]+1]) cnt++;
    if(pos[x[a]+1]<pos[x[a]] && b<=pos[x[a]+1]) cnt--;
    pos[x[a]]=b;
    if(pos[x[b]-1]<=pos[x[b]] && a<pos[x[b]-1]) cnt++;
    if(pos[x[b]-1]>pos[x[b]] && a>=pos[x[b]-1]) cnt--;
    if(pos[x[b]+1]>=pos[x[b]] && a>pos[x[b]+1]) cnt++;
    if(pos[x[b]+1]<pos[x[b]] && a<=pos[x[b]+1]) cnt--;
    pos[x[b]]=a;
    swap(x[a],x[b]);
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        pos[x[i]]=i;
    }
    pos[n+1]=n+1;
    cnt=1;
    for(int i=1,ptr=0;i<=n;i++){
        if(ptr>pos[i]) cnt++;
        ptr=pos[i];
    }
    for(int i=0,a,b;i<m;i++){
        cin>>a>>b;
        update(a,b);
        cout<<cnt<<'\n';
    }
}