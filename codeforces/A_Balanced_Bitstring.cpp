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
// template<typename K, typename V>
// using safe_umap = unordered_map<K, V, custom_hash>;
// template<typename T>
// using safe_uset = unordered_set<T, custom_hash>;

// vector<int> gettemp(int n){
//     vector<int> factors;
//     for(int i=1;i*i<=n;i++){
//         if(n%i==0){
//             if(i%2==0) factors.push_back(i);
//             if(i!=n/i){
//                 if((n/i)%2==0) factors.push_back(n/i);
//             }
//         }
//     }
//     return factors;
// }

// bool gettemp9(vector<int>& a, int f){
//     int n=a.size();
//     for(int i=1;i<=f;i++){
//         vector<vector<int>> temp;
//         vector<int> temp2;
//         for(int j=0;j<i;j++){
//             temp2.push_back(a[j]);
//         }
//         temp.push_back(temp2);
//         temp2.clear();
//         int temp5=n/f;
//         int temp6=i;
//         while(temp5--){
//             for(int j=temp6;j<temp6+f;j++){
//                 temp2.push_back(a[j]);
//             }
//             temp6+=f;
//             temp.push_back(temp2);
//             temp2.clear();
//         }
//         for(int j=temp6;j<n;j++){
//             temp2.push_back(a[j]);
//         }
//         temp.push_back(temp2);
//         temp2.clear();
//         int temp4=0;
//         for(int j=0;j<temp.size();j++){
//             vector<int> temp3=temp[j];
//             int c1=0,c0=0;
//             for(int k=0;k<temp3.size();k++){
//                 if(temp3[k]==1) c1++;
//                 if(temp3[k]==0) c0++;
//             }
//             if((c1==0)||(c0==0)){
//                 temp4++;
//             }
//         }
//         if(temp4==temp.size()){
//             return true;
//         }
//     }
//     return false;
    
//     //i guess its flawed

//     // vector<vector<int>> temp5(f);
//     // for(int i=0;i<n;i++){
//     //     temp5[i%f].push_back(a[i]);
//     // }
//     // int temp4=0;
//     // for(int i=0;i<f;i++){
//     //     vector<int> temp6=temp5[i];
//     //     int c1=0,c0=0;
//     //     for(int j=0;j<temp6.size();j++){
//     //         if(temp6[j]==0) c0++;
//     //         else if(temp6[j]==1) c1++;
//     //     }
//     //     if((c1==0)||(c0==0)){
//     //         temp4++;
//     //     }
//     // }
//     // if(temp4==f) return true;
//     // else return false;
// }

// void solve() {
//     int n,k; cin>>n>>k;
//     string s; cin>>s;
//     vector<int> a(n);
//     for(int i=0;i<n;i++){
//         if(s[i]=='1') a[i]=1;
//         else if(s[i]=='0') a[i]=0;
//         else if(s[i]=='?') a[i]=2;
//     }
//     int c1=0,c0=0,c2=0;
//     for(int i=0;i<k;i++){
//         if(a[i]==1) c1++;
//         else if(a[i]==2) c2++;
//         else if(a[i]==0) c0++;
//     }
//     // //cout<<c1<<c2<<c0<<endl;
//     // //cout<<r<<endl;
//     if(n==k){
//         if(max(c1,c0)-min(c1,c0)>c2){
//             cout<<"NO"<<endl;
//             return;
//         }
//         else{
//             if((c2-max(c1,c0)+min(c1,c0))%2==0){
//                 cout<<"YES"<<endl;
//                 return;
//             }
//             else{
//                 cout<<"NO"<<endl;
//                 return;
//             }
//         }
//     }
//     vector<int> temp = gettemp(k);
//     int ans=0;
//     for(int i=0;i<temp.size();i++){
//         int f=temp[i];
//         f/=2;
//         bool temp9=gettemp9(a,f);
//         if(!temp9) continue;
//         else{
//             ans++;
//             break;
//         }
//     }
//     if(ans>0) cout<<"YES"<<endl;
//     else cout<<"NO"<<endl;
//     return;
// }

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     int tc = 1;
//     cin >> tc;
//     for (int t = 1; t <= tc; t++) {
//         // cout << "Case #" << t << ": ";
//         solve();
//     }
// }


// // i unnessarilly overcomplicated it lets redo it

// // #include <bits/stdc++.h>

// // using namespace std;

// // template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
// // template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// // void dbg_out() { cerr << endl; }
// // template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
// // #ifdef LOCAL
// // #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
// // #else
// // #define dbg(...)
// // #endif

// // #define ar array
// // #define ll long long
// // #define ld long double
// // #define sza(x) ((int)x.size())
// // #define all(a) (a).begin(), (a).end()

// // const int MAX_N = 1e5 + 5;
// // const ll MOD = 1e9 + 7;
// // const ll INF = 1e9;
// // const ld EPS = 1e-9;

// // // Custom hash for unordered_map/set
// // struct custom_hash {
// //     static uint64_t splitmix64(uint64_t x) {
// //         x += 0x9e3779b97f4a7c15;
// //         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
// //         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
// //         return x ^ (x >> 31);
// //     }
// //     size_t operator()(uint64_t x) const {
// //         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
// //         return splitmix64(x + FIXED_RANDOM);
// //     }
// //     template<typename T, typename U>
// //     size_t operator()(const pair<T, U>& p) const {
// //         uint64_t h1 = operator()(static_cast<uint64_t>(p.first));
// //         uint64_t h2 = operator()(static_cast<uint64_t>(p.second));
// //         return h1 ^ (h2 << 1);
// //     }
// // };
// // template<typename K, typename V>
// // using safe_umap = unordered_map<K, V, custom_hash>;
// // template<typename T>
// // using safe_uset = unordered_set<T, custom_hash>;



// // void solve() {
// //     int n,k; cin>>n>>k;
// //     string s; cin>>s;
// //     int c1=0,c0=0,c2=0;
// //     for(int i=0;i<k;i++){
// //         if(s[i]=='1') c1++;
// //         else if(s[i]=='0') c0++;
// //         else c2++;
// //     }
// //     if(max(c1,c0)-min(c1,c0)>c2){
// //         cout<<"NO"<<endl;
// //         return;
// //     }
// //     else{
// //         if((c2-max(c1,c0)+min(c1,c0))%2==0){}
// //         else{
// //             cout<<"NO"<<endl;
// //             return;
// //         }
// //     }
// //     vector<vector<int>> temp(k);
// //     for(int i=0;i<n;i++){
// //         temp[i%k].push_back(s[i]);
// //     }
// //     for(int i=0;i<k;i++){
// //         int b1=0,b0=0;
// //         for(int j=0;j<temp[i].size();j++){
// //             if(temp[i][j]=='0') b0++;
// //             else if(temp[i][j]=='1') b1++;
// //         }
// //         if((b1!=0)&&(b0!=0)){
// //             cout<<"NO"<<endl;
// //             return;
// //         }
// //     }
// //     cout<<"YES"<<endl;

// // }

// // int main() {
// //     ios_base::sync_with_stdio(0);
// //     cin.tie(0); cout.tie(0);
// //     int tc = 1;
// //     cin >> tc;
// //     for (int t = 1; t <= tc; t++) {
// //         // cout << "Case #" << t << ": ";
// //         solve();
// //     }
// // }

//fuck everything and fuck me

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
// template<typename K, typename V>
// using safe_umap = unordered_map<K, V, custom_hash>;
// template<typename T>
// using safe_uset = unordered_set<T, custom_hash>;



// void solve() {
//     int n,k; cin>>n>>k;
//     string s; cin>>s;
//     vector<int> a(n);
//     for(int i=0;i<n;i++){
//         if(s[i]=='1') a[i]=1;
//         else if(s[i]=='0') a[i]=0;
//         else a[i]=2;
//     }
//     for(int i=0;i<n-k;i++){
//         if((a[i]==0 && a[i+k]==1)||(a[i]==1 && a[i+k]==0)){
//             cout<<"NO"<<endl;
//             return;
//         }
//         if(a[i]==2 && a[i+k]==2) continue;
//         else if(a[i]==2 && a[i+k]!=2) a[i]=a[i+k];
//         else if(a[i]!=2 && a[i+k]==2) a[i+k]=a[i];
//     }
//     int c1=0,c0=0;
//     for(int i=0;i<n;i++){
//         if(a[i]==1) c1++;
//         else if(a[i]==0) c0++;
//     }
//     if(c1==c0) cout<<"YES";
//     else cout<<"NO";
//     cout<<endl;
//     return;
// }

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     int tc = 1;
//     cin >> tc;
//     for (int t = 1; t <= tc; t++) {
//         // cout << "Case #" << t << ": ";
//         solve();
//     }
// }

//yet another flawed logic what is wrong with me

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
template<typename K, typename V>
using safe_umap = unordered_map<K, V, custom_hash>;
template<typename T>
using safe_uset = unordered_set<T, custom_hash>;



void solve() {
    int n,k; cin>>n>>k;
    string s; cin>>s;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        if(s[i]=='1') a[i]=1;
        else if(s[i]=='0') a[i]=0;
        else a[i]=2;
    }
    for(int i=0;i<n-k;i++){
        if((a[i]==0 && a[i+k]==1)||(a[i]==1 && a[i+k]==0)){
            cout<<"NO"<<endl;
            return;
        }
        if(a[i]==2 && a[i+k]==2) continue;
        else if(a[i]==2 && a[i+k]!=2) a[i]=a[i+k];
        else if(a[i]!=2 && a[i+k]==2) a[i+k]=a[i];
    }
    for(int i=n-1;i>=k;i--){
        if((a[i]==0 && a[i-k]==1)||(a[i]==1 && a[i-k]==0)){
            cout<<"NO"<<endl;
            return;
        }
        if(a[i]==2 && a[i-k]==2) continue;
        else if(a[i]==2 && a[i-k]!=2) a[i]=a[i-k];
        else if(a[i]!=2 && a[i-k]==2) a[i-k]=a[i];
    }
    //cout<<"hahahaha"<<endl;
    int c1=0,c0=0,c2=0;
    for(int i=0;i<k;i++){
        if(a[i]==1) c1++;
        else if(a[i]==0) c0++;
        else if(a[i]==2) c2++;
    }
    if(max(c1,c0)-min(c1,c0)>c2){
        cout<<"NO"<<endl;
    }
    else if(max(c1,c0)-min(c1,c0)==c2){
        cout<<"YES"<<endl;
    }
    else{
        c2-=(max(c1,c0)-min(c1,c0));
        if(c2%2==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}