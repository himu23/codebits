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
    ll a,b; cin>>a>>b;
    if(a==b){
        cout<<0<<endl;
        return;
    }
    if (a<b) swap(a,b);
    if(a%b!=0){
        cout<<-1<<endl;
        return;
    }
    ll r=a/b;
    if ((r & (r - 1)) != 0) {
        cout << -1 << "\n";
        return;
    }

    ll ops = 0;
    while (r % 8 == 0) r /= 8, ops++;
    while (r % 4 == 0) r /= 4, ops++;
    while (r % 2 == 0) r /= 2, ops++;

    cout << ops << endl;
    return;
    // if(a>b){
    //     int ans=0;
    //     bool flag=false;
    //     while(a%8==0 && !flag){
    //         a/=8;
    //         ans++;
    //         if(a==b){
    //             flag=true;
    //             cout<<ans<<endl;
    //             return;
    //         }
    //     }
    //     while(a%4==0 && !flag){
    //         a/=4;
    //         ans++;
    //         if(a==b){
    //             flag=true;
    //             cout<<ans<<endl;
    //             return;
    //         }
    //     }
    //     while(a%2==0 && !flag){
    //         a/=2;
    //         ans++;
    //         if(a==b){
    //             flag=true;
    //             cout<<ans<<endl;
    //             return;
    //         }
    //     }
    //     if(!flag){
    //         cout<<-1<<endl;
    //         return;
    //     }
    //     else{
    //         cout<<ans<<endl;
    //         return;
    //     }
    // }
    
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