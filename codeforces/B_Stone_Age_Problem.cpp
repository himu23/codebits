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
    ll n,q; cin>>n>>q;
    vector<int> a(n);
    ll sum=0;
    for(ll i=0;i<n;i++){
       int temp;cin>>temp;
       a[i]=temp;
       sum+=temp;
    }
    int temp2=-1;
    unordered_map<int,int>um;
    while(q--){
        ll m; cin>>m;
        if(m==1){
            ll j,p; cin>>j>>p;
            j--;
            if(temp2==-1){
                sum-=a[j];
                sum+=p;
                a[j]=p;
            }
            else{
                ll temp;
                if(um.count(j)) temp=um[j];
                else temp=temp2;
                sum-=temp;
                sum+=p;
                um[j]=p;
            }
            
        }
        else{
            ll p;cin>>p;
            temp2=p;
            sum=0;
            sum+=(p*n);
            um.clear();
        }
        cout<<sum<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}