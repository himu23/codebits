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
    ll tempi=a[0], tempa=a[0];
    vector<ll> temp(n+1);
    temp[0]=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        temp[i+1]=temp[i]+a[i];
        tempi=min(tempi,a[i]);
        tempa=max(tempa,a[i]);
    }
    if(tempi==tempa){
        cout<<0<<endl;
        return;
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        if(n%i==0){
            ll cem1=temp[i]-temp[0],cem2=temp[i]-temp[0];
            for(ll j=i;j<=n;j+=i){
                cem1=min(cem1,temp[j]-temp[j-i]);
                cem2=max(cem2,temp[j]-temp[j-i]);
            }
            ans=max(ans,cem2-cem1);
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