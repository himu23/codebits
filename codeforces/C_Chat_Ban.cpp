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
    ld k,x; cin>>k>>x;
    ld temp=k*(k+1)/2;
    ld temp2=k*(k-1)/2;
    if(x<=temp){
        ld y=x;
        y*=8;
        y++;
        y=sqrt(y);
        y--;
        y/=2;
        y=ceil(y);
        cout<<fixed<<setprecision(0)<<y<<endl;
        return;
    }
    else if(x>=temp+temp2){
        cout<<fixed<<setprecision(0)<<2*k-1<<endl;
        return;
    }
    else{
        //cout<<"hahha"<<endl;
        // x-=temp;
        // cout<<x<<" ";
        // ld temp3= temp2;
        // cout<<temp3<<" ";
        // ld l= k;
        // ld y= x;
        // y+=temp3;
        // y*=2;
        // cout<<y<<" ";
        // y-=l*l;
        // y-=l;
        // cout<<y<<" ";
        // l*=2;
        // l++;
        // cout<<l<<" ";
        // y*=4;
        // y+=l*l;
        // y=sqrt(y);
        // y+=l;
        // y/=2;
        // cout<<"haha"<<" "<<y<<endl;
        x-=temp;
        //cout<<x<<" ";
        x=temp2-x;
        x*=2;
        x-=(k*k-k);
        x*=4;
        x+=(2*k-1)*(2*k-1);
        x=sqrt(x);
        //x+=2*k-1;
        x=(2*k-1)-x;
        x/=2;
        x=ceil(x);
        cout<<fixed<<setprecision(0)<<k+x<<endl;
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