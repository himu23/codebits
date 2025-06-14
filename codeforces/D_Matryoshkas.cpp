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
//     ll n; cin>>n;
//     vector<ll> a(n);
//     map<ll,ll> m;
//     for(ll i=0;i<n;i++){
//         cin>>a[i];
//         m[a[i]]++;
//     }
//     vector<vector<ll>> temp;
//     vector<ll> temp2;
//     auto it=m.begin();
//     auto prev=it++;
//     temp2.push_back(prev->second);
//     for(; it!=m.end(); ++it, ++prev){
//         if(it->first-prev->first==1){
//             temp2.push_back(it->second);
//         }
//         else{
//             temp.push_back(temp2);
//             temp2.clear();
//             temp2.push_back(it->second);
//         }
//     }
//     if (!temp2.empty()) temp.push_back(temp2);
//     ll ans=0;
//     for(ll i=0;i<temp.size();i++){
//         vector<ll> v=temp[i];
//         if(v.empty()){
//             continue;
//         }
//         ll maxfre=0;
//         for(ll j=0;j<v.size();j++){
//             maxfre=max(maxfre,v[j]);
//         }
//         ll ans1=0;
//         for(ll j=1;j<=maxfre;j++){
//             ll ans2=0;
//             if(v[0]>=j) ans2++;
//             for(ll k=1;k<v.size();k++){
//                 if(v[k]>=j && v[k-1]<j) ans2++;
//             }
//             ans1+=ans2;
//         }
//         ans+=ans1;
//     }
//     cout<<ans<<endl;
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

// the above code gives tle on test 76.... i want to cry rn

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



void solve() {
    ll n; cin>>n;
    vector<ll> a(n);
    map<ll,ll> m;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        m[a[i]]++;
    }
    vector<vector<ll>> temp;
    vector<ll> temp2;
    auto it=m.begin();
    auto prev=it++;
    temp2.push_back(prev->second);
    for(; it!=m.end(); ++it, ++prev){
        if(it->first-prev->first==1){
            temp2.push_back(it->second);
        }
        else{
            temp.push_back(temp2);
            temp2.clear();
            temp2.push_back(it->second);
        }
    }
    if (!temp2.empty()) temp.push_back(temp2);
    ll ans=0;
    for(ll i=0;i<temp.size();i++){
        vector<ll> v=temp[i];
        if(v.empty()){
            continue;
        }
        ll tom=0;
        for(ll j=1;j<v.size();j++){
            tom+=max(0LL,(v[j-1]-v[j]));
        }
        tom+=v[v.size()-1];
        ans+=tom;
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
