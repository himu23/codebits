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

// Custom hash for unordered_map/set
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    template<typename T, typename U>
    size_t operator()(const pair<T, U>& p) const {
        uint64_t h1 = operator()(static_cast<uint64_t>(p.first));
        uint64_t h2 = operator()(static_cast<uint64_t>(p.second));
        return h1 ^ (h2 << 1);
    }
};
template<typename K, typename V>
using safe_umap = unordered_map<K, V, custom_hash>;
template<typename T>
using safe_uset = unordered_set<T, custom_hash>;



void solve() {
    ll n; cin>>n;
    vector<ll> a(n);
    bool flag=false;
    for(ll i=0;i<n;i++){
        ll temp; cin>>temp;
        if(temp%5==0) flag=true;
        a[i]=temp;
    }
    if(flag){
        for(ll i=0;i<n;i++){
            if(a[i]%5!=0){
                cout<<"No"<<endl;
                return;
            }
            if(a[i]%10==5) a[i]+=5;
        }
        for(ll i=0;i<n;i++){
            if(a[i]!=a[0]){
                cout<<"No"<<endl;
                return;
            }
        }
        cout<<"Yes"<<endl;
        return;

    }
    for(ll i=0;i<n;i++){
        a[i]%=20;
    }
    ll ans=0;
    for(ll i=0;i<n;i++){
        if((a[i]==1) || (a[i]==2) || (a[i]==4) || (a[i]==8) || (a[i]==13) || (a[i]==16) || (a[i]==17) || (a[i]==19)){
            ans+=0;
        }
        else if((a[i]==3) || (a[i]==6) || (a[i]==7) || (a[i]==9) || (a[i]==11) || (a[i]==12) || (a[i]==14) || (a[i]==18)){
            ans+=1;
        }
    }
    if(ans==0 || ans==n){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
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