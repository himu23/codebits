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

// bool customcomparator(pair<ll,ll> a, pair<ll,ll> b){
//     if(a.first != b.first)
//         return a.first<b.first;
//     else
//         return a.second > b.second;
// }

// void solve() {
//     ll n,p; cin>>n>>p;
//     vector<pair<ll,ll>> temp(n);
//     vector<ll> a(n);
//     for(ll i=0;i<n;i++){
//         cin>>a[i];
//     }
//     vector<ll> b(n);
//     for(ll i=0;i<n;i++){
//         cin>>b[i];
//         temp[i]={b[i],a[i]};
//     }
//     sort(temp.begin(),temp.end(), customcomparator);
//     ll temp2=n;
//     ll ans=0;
//     ll temp3=0;
//     while(temp2>0 && temp[temp3].first<p && temp3<n){
//         ans+=p;
//         temp2--;
//         if(temp[temp3].second<temp2){
//             ans+=temp[temp3].first*temp[temp3].second;
//             temp2-=temp[temp3].second;
//         }
//         else{
//             ans+=temp[temp3].first*temp2;
//             temp2=0;
//         }
//         temp3++;
//         if (temp2 <= 0) break;
//     }
//     if(temp2>0){
//         ans+=temp2*p;
//     }
//     cout<<ans<<endl;
// }

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     ll tc = 1;
//     cin >> tc;
//     for (ll t = 1; t <= tc; t++) {
//         // cout << "Case #" << t << ": ";
//         solve();
//     }
// }

//above logic was flawed

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

bool customcomparator(pair<int,int> a, pair<int,int> b){
    if(a.first!=b.first){
        return a.first<b.first;
    }
    else{
        return a.second>b.second;
    }
}

void solve() {
    ll n,p; cin>>n>>p;
    vector<pair<ll,ll>> temp(n);
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    vector<ll> b(n);
    for(ll i=0;i<n;i++){
        cin>>b[i];
        temp[i]={b[i],a[i]};
    }
    sort(temp.begin(),temp.end(),customcomparator);
    ll informed=0;
    ll ans=0;
    if(temp[0].first>=p){
        ans+=n*p;
        informed+=n;
    }
    else{
        informed++;
        ans+=p;
        ll i=0;
        while(informed<n && i<n && temp[i].first<p){
            ll temp2=min(n-informed,temp[i].second);
            ans+= temp2*temp[i].first;
            informed+=temp2;
            i++;
        }
    }
    if(informed<n){
        ans+=p*(n-informed);
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