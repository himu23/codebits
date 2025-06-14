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
    vector<ll> b(n);
    for(ll i=0;i<n;i++){
        cin>>b[i];
    }
    if(n==1){
        cout<<1<<endl;
        return;
    }
    vector<int> a;
    a.push_back(b[0]);
    for(int i=1;i<n;i++){
        if(b[i]!=b[i-1]){
            a.push_back(b[i]);
        }
    }
    if(a.size()==1){
        cout<<1<<endl;
        return;
    }
    //cout<<a.size()<<" ";
    ll ans=2;
    bool increasing=false;
    if(a[0]<a[1]){
        increasing=true;
    }
    for(ll i=1;i<a.size()-1;i++){
        if(a[i+1]==a[i]){
            continue;
        }
        if(a[i]<a[i+1] && !increasing){
            ans++;
        }
        else if(a[i]>a[i+1] && increasing){
            ans++;
        }
        if(a[i]<a[i+1]){
            increasing=true;
        }
        else if(a[i]>a[i+1]){
            increasing=false;
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