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
    set<ll>s;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        s.insert(a[i]);
    }
    ll ge=a[0], go=a[1];
    for(ll i=0;i<n;i++){
        if(i%2==0){
            ge=gcd(ge,a[i]);
        }
        else{
            go=gcd(go,a[i]);
        }
    }
    //cout<<ge<<" "<<go<<endl;
    if(s.size()==1){
        cout<<0<<endl;
        return;
    }
    bool flage=true, flago=true;
    for(ll i=0;i<n;i++){
        if(i%2==0){
            if(a[i]%go==0) flago=false;
        }
        else{
            if(a[i]%ge==0) flage=false;
        }
    }
    if(flage){
        cout<<ge<<endl;
    }
    else if(flago){
        cout<<go<<endl;
    }
    else if(!flage && !flago){
        cout<<0<<endl;
    }
    return;
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