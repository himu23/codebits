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

vector<int> getbitwise(int n){
    vector<int> ans(31);
    for(int i=30;i>=0;i--){
        if((n&(1<<i))!=0) ans[i]=1;
        else ans[i]=0;
    }
    return ans;
}

void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
       cin>>a[i];
    }
    vector<vector<int>> pref(n,vector<int>(31));
    pref[0]=getbitwise(a[0]);
    for(int i=1;i<n;i++){
        vector<int> temp=getbitwise(a[i]);
        for(int j=0;j<=30;j++){
            pref[i][j]=pref[i-1][j]+temp[j];
        }
    }
    int q; cin>>q;
    while(q--){
        int l,k; cin>>l>>k;
        l--;
        int r=n-1;
        bool found=false;
        while(r>=l){
            int temp=0;
            vector<int> temp2(31);
            if(l==0){
                temp2=pref[r];
            }
            else{
                for(int i=0;i<31;i++){
                    temp2[i]=pref[r][i]-pref[l-1][i];
                }
            }
            for(int i=0;i<31;i++){
                if(temp2[i]==r-l+1){
                    temp+=(1<<i);
                }
            }
            if(temp>k){
                cout<<r+1<<" ";
                found=true;
                break;
            }
            r--;
        }
        if(!found) cout<<-1<<" ";
    }
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