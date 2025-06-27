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
    ll n,m; cin>>n>>m;
    vector<ll> a(m);
    for(ll i=0;i<m;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<ll> temp;
    temp.push_back(a[0]-1+(n-a[m-1]));
    for(ll i=1;i<m;i++){
        temp.push_back(a[i]-a[i-1]-1);
    }
    sort(temp.begin(),temp.end(),greater<ll>());
    //cout<<temp<<" ";
    for(ll i=0;i<temp.size();i++){
        temp[i]=temp[i]-i*4;
    }
    //cout<<temp<<endl;
    ll ans=0;
    for(ll i=0;i<temp.size();i++){
        if(temp[i]<=0) break;
        if(temp[i]==1) ans+=1;
        else ans+=temp[i]-1;
    }
    //cout<<ans<<" ";
    cout<<n-ans<<endl;
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