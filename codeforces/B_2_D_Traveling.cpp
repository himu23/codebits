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
    ll n,k,a,b; cin>>n>>k>>a>>b;
    vector<ll> x(n),y(n);
    for(ll i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    ll ans=abs(x[a-1]-x[b-1])+abs(y[a-1]-y[b-1]);
    ll temp1=abs(x[a-1]-x[0])+abs(y[a-1]-y[0]),temp2=abs(x[b-1]-x[0])+abs(y[b-1]-y[0]);
    for(ll i=1;i<k;i++){
        temp1=min(temp1,abs(x[a-1]-x[i])+abs(y[a-1]-y[i]));
        temp2=min(temp2,abs(x[b-1]-x[i])+abs(y[b-1]-y[i]));
    }
    ans=min(ans,temp1+temp2);
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