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
    int n; cin>>n;
    vector<int> a(n);
    int maxnum=INT_MIN;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxnum=max(maxnum,a[i]);
    }
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
        maxnum=max(maxnum,b[i]);
    }
    unordered_map<int,int> um1;
    unordered_map<int,int> um2;
    int temp2=1;
    for(int i=1;i<n;i++){
        if(a[i]== a[i-1]) temp2++;
        else{
            um1[a[i-1]]=max(um1[a[i-1]],temp2);
            temp2=1;
        }
    }
    um1[a[n-1]]=max(um1[a[n-1]],temp2);
    temp2=1;
    for(int i=0;i<n;i++){
        if(b[i]==b[i-1]) temp2++;
        else{
            um2[b[i-1]]=max(um2[b[i-1]],temp2);
            temp2=1;
        }
    }
    um2[b[n-1]]=max(um2[b[n-1]],temp2);
    int ans=0;
    for(int i=1;i<=maxnum;i++){
        ans=max(ans,um1[i]+um2[i]);
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