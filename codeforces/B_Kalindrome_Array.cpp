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

// vector<ll> removex(vector<ll>& a, ll x){
//     vector<ll> ans=a;
//     ans.erase(remove(ans.begin(),ans.end(),x), ans.end());
//     return ans;
// }

// bool ispalindrome(vector<ll>& temp){
//     bool ans=true;
//     for(ll i=0;i<temp.size()/2;i++){
//         if(temp[i]!=temp[temp.size()-1-i]) ans=false;
//     }
//     return ans;
// }

// void solve() {
//     ll n; cin>>n;
//     set<ll> s;
//     vector<ll> a(n);
//     for(ll i=0;i<n;i++){
//         cin>>a[i];
//         s.insert(a[i]);
//     }
//     for(ll x : s){
//         vector<ll> temp=removex(a, x);
//         if(ispalindrome(temp)){
//             cout<<"YES"<<endl;
//             return;
//         }
//     }
//     cout<<"NO"<<endl;
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



//above is good but gives tle on test2

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

vector<int> removex(vector<int>& a, int x){
    vector<int> ans=a;
    ans.erase(remove(ans.begin(),ans.end(),x), ans.end());
    return ans;
}

bool ispalindrome(vector<int>& temp){
    bool ans=true;
    for(int i=0;i<temp.size()/2;i++){
        if(temp[i]!=temp[temp.size()-1-i]) ans=false;
    }
    return ans;
}


void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=0, r=n-1;
    while(l<n && r>=0 && l<=r){
        if(a[l]==a[r]){
            l++,r--;
        }
        else{
            break;
        }
    }
    vector<int> temp=a;
    vector<int> temp1=removex(temp,a[l]);
    bool flag1=ispalindrome(temp1);
    temp=a;
    vector<int> temp2=removex(temp,a[r]);
    bool flag2=ispalindrome(temp2);
    if(flag1 || flag2){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
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