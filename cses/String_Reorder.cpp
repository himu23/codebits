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
//     //int n; cin>>n;
//     string s; cin>>s;
//     int n=s.length();
//     umap<char,int> freq;
//     for(int i=0;i<n;i++){
//         freq[s[i]]++;
//         if(freq[s[i]]>(n+1)/2){
//             cout<<-1<<endl;
//             return;
//         }
//     }
//     priority_queue<pair<char,int>,vector<pair<char,int>>,greater<pair<char,int>>> pq;
//     for(auto x:freq){
//         //int temp=-1*x.second;
//         pq.push({x.first,-1*x.second});
//     }
//     char temp3;
//     int temp4=0;
//     // vector<pair<char,int>> temp5={};
//     // vector<pair<char,int>> temp6={};
//     while(!pq.empty()){
//         // if(temp4!=0 && pq.top().first==temp3) {
//         //     temp5.push_back(pq.top());
//         //     pq.pop();
//         // }
//         // pair<char,int> temp2=pq.top();
//         // pq.pop();
//         // cout<<temp2.first;
//         // temp3=temp2.first;
//         // temp4++;
//         // temp2.second++;
//         // if(temp2.second!=0) pq.push(temp2);
//         // for(int i=0;i<temp5.size();i++){
//         //     pq.push(temp5[i]);
//         // }
//         // temp5=temp6;
//         vector<pair<char,int>> temp5;
//         bool flag=false;
//         while(!pq.empty()){
//             pair<char,int> temp2=pq.top();pq.pop();
//             if(temp4!=0 && temp2.first==temp3){
//                 temp5.push_back(temp2);
//                 continue;
//             }
//             cout<<temp2.first;
//             temp3=temp2.first;
//             temp4++;
//             temp2.second++;
//             if(temp2.second!=0) pq.push(temp2);
//             flag=true;
//             break;
//         }
//         for(auto p:temp5) pq.push(p);
//         if(!flag){
//             cout<<-1<<endl;
//             return;
//         }
//     }
//     // vector<pair<int,char>> temp;
//     // for(auto x:freq){
//     //     temp.push_back({-1*x.second,x.first});
//     // }
//     // sort(temp.begin(),temp.end());
//     // for(int i=0;i<temp.size();i++)
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

//i dont know it was wrng somehow
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



void solve(){
    string s; cin>>s;
    int n=s.length();
    vector<int> freq(26);
    for(char c:s){
        freq[c-'A']++;
    }
    string ans;
    while((int) ans.length()<n){
        pair<int,int> big{0,0};
        for(int x : freq){
            if(x>big.first){
                big={x,big.first};
            }
            else if(x>big.second){
                big.second=x;
            }
        }
        bool flag=false;
        for(int i=0;i<26;i++){
            if(freq[i]>0 && (ans.empty() || ans.back()!=('A'+i))){
                freq[i]--;
                ans+=('A'+i);
                //can i still finish
                int rem=n-(int)ans.length();
                bool canfinish=true;
                if(freq[i]>rem/2){
                    canfinish=false;
                }
                if((freq[i]+1==big.first ? big.second : big.first)>(rem+1)/2){
                    canfinish=false;
                }
                // for(int j=0;j<26;j++){
                //     if(i!=j){
                //         if(freq[j]>(rem+1)/2){
                //             canfinish=false;
                //             break;
                //         }
                //     }
                //     else{
                //         if(freq[j]>rem/2){
                //             canfinish=false;
                //             break;
                //         }
                //     }
                // }
                if(canfinish){
                    flag=true;
                    break;
                }
                else{
                    freq[i]++;
                    ans.pop_back();
                }
            }
        }
        if(!flag) break;
    }
    if(ans.empty()){
        cout<<-1<<endl;
    }
    else{
        cout<<ans<<endl;
    }
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