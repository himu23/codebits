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

int countdivisions(int a,int b){
    int ans=0;
    while(a){
        a/=b;
        ans++;
    }
    return ans;
}

void solve() {
    int a,b; cin>>a>>b;
    if(b>a){
        cout<<1<<endl;
        return;
    }
    bool flag=false;
    if(b==1){
        b++;
        flag=true;
    }
    int temp=countdivisions(a,b)+b-b;;
    for(int i=b+1;i<INT_MAX;i++){
        int temp2=countdivisions(a,i)+i-b;
        if(temp2>temp){
            if(flag) cout<<temp+1<<endl;
            else cout<<temp<<endl;
            return;
        }
        temp=temp2;
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