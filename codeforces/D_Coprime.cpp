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

// bool customcompa(pair<int,int>a, pair<int,int>b){
//     return a.first+a.second>b.first+b.second;
// }

// void solve() {
//     int n; cin>>n;
//     vector<int> a(n);
//     vector<pair<int,int>>temp;
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     for(int i=n-1;i>=0;i--){
//         for(int j=i;j>=0;j--){
//             temp.push_back({i,j});
//         }
//     }
//     sort(temp.begin(),temp.end(),customcompa);
//     for(int i=0;i<temp.size();i++){
//         if(gcd(a[temp[i].first],a[temp[i].second])==1){
//             //cout<<temp[i].first<<" "<<temp[i].second<<" ";
//             cout<<temp[i].first+temp[i].second+2<<endl;
//             return;
//         }
//     }
//     cout<<-1<<endl;
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



// the above code is good but gives MLE(memory limit execded(my first time)) on test 4

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



// void solve() {
//     int n; cin>>n;
//     vector<int> a(n);
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     for(int sum=2*(n);sum>=2;sum--){
//         for(int i=n;i>=1;i--){
//             int j=sum-i;
//             if(j>i) break;
//             if(j>=1 && j<=n){
//                 if(gcd(a[i-1],a[j-1])==1){
//                     cout<<sum<<endl;
//                     return;
//                 }
//             }
//         }
//     }
//     cout<<-1<<endl;
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


//the above code is also good but it is also giving tle on test 12

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

// vector<vector<int>> generatevector(){
//     vector<vector<int>> ans(1001,vector<int>(1001,0));
//     for(int i=1;i<=1000;i++){
//         for(int j=1;j<=1000;j++){
//             if(gcd(i,j)==1){
//                 ans[i][j]=1;
//             }
//         }
//     }
//     return ans;
// }

// const vector<vector<int>> temp=generatevector();

// void solve() {
//     int n; cin>>n;
//     vector<int> a(n);
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     for(int sum=2*(n);sum>=2;sum--){
//         for(int i=n;i>=1;i--){
//             int j=sum-i;
//             if(j>i) break;
//             if(j>=1 && j<=n){
//                 if(temp[a[i-1]][a[j-1]]==1){
//                     cout<<sum<<endl;
//                     return;
//                 }
//             }
//         }
//     }
//     cout<<-1<<endl;
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


//the above code is giving tle on test 16(not 12 some improvements)

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

vector<vector<int>> generatevector(){
    vector<vector<int>> ans(1001,vector<int>(1001,0));
    for(int i=1;i<=1000;i++){
        for(int j=1;j<=1000;j++){
            if(gcd(i,j)==1){
                ans[i][j]=1;
            }
        }
    }
    return ans;
}

const vector<vector<int>> temp=generatevector();

void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    unordered_map<int,vector<int>> um;
    um[1]={};
    for(int i=n-1;i>=0;i--){
        if(um[a[i]].size()<2 && a[i]!=1){
            um[a[i]].push_back(i);
        }
        if(um[a[i]].size()<=2 && a[i]==1){
            um[a[i]].push_back(i);
        }
    }
    int ans=-1;
    if(um.count(1) && um[1].size()>=2){
        ans=max(ans,um[1][0]+um[1][1]+2);
    }
    for(const auto& [key,value]: um){
        for(const auto& [key2, value2]: um){
            if(temp[key][key2]==1){
                ans=max(ans,value[0]+value2[0]+2);
            }
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}