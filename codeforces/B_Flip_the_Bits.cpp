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
    string a,b; cin>>a>>b;
    vector<ll> c(n);
    for(ll i=0;i<n;i++){
        if(a[i]==b[i]) c[i]=0;
        else c[i]=1;
    }
    vector<ll> pref(n);
    pref[0]=c[0];
    for(ll i=1;i<n;i++){
        pref[i]=pref[i-1]+c[i];
    }
    bool flag=true;
    ll temp=0;
    ll cz=0,co=0;
    for(ll i=0;i<n;i++){
        if(a[i]=='0') cz++;
        else co++;
        if(cz==co){
            ll sum;
            if(temp==0) sum=pref[i];
            else sum=pref[i]-pref[temp-1];
            if(!(sum==0 || sum==(i-temp+1))){
                flag=false;
                break;
            }
            temp=i+1;
            cz=0,co=0;
        }
    }
    if(flag && temp<n){
        ll sum=pref[n-1]-(temp==0 ? 0:pref[temp-1]);
        if(!(sum==0 || sum==(n-temp+1))){
            flag=false;
        }
    }
    if(flag) cout<<"YES";
    else cout<<"NO";
    cout<<endl;
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