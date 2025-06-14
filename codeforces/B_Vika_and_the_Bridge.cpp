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
    ll n,k; cin>>n>>k;
    vector<ll> c(n);
    vector<vector<ll>> temp3(n+1);
    for(ll i=0;i<n;i++){
        cin>>c[i];
        temp3[c[i]].push_back(i);
    }
    vector<vector<ll>> temp(n+1);
    for(ll i=0;i<temp3.size();i++){
        if(!temp3[i].empty()){
            for(ll j=0;j<=temp3[i].size();j++){
                if(j==0){
                    temp[i].push_back(temp3[i][j]);
                }
                else if(j==temp3[i].size()){
                    temp[i].push_back(n-temp3[i][j-1]-1);
                }
                else{
                    temp[i].push_back(temp3[i][j]-temp3[i][j-1]-1);
                }
            }
        }
    }
    ll ans=n+1;
    for(ll i=0;i<temp.size();i++){
        if(!temp[i].empty()){
            //cout<<temp[i]<<" ";
            sort(temp[i].begin(),temp[i].end());
            ll temp2=temp[i].back();
            temp[i].pop_back();
            temp2--;
            temp[i].push_back(temp2/2);
            temp[i].push_back((temp2+1)/2);
            sort(temp[i].begin(),temp[i].end());
            ans=min(ans,temp[i].back());
            //cout<<temp[i]<<" ";
        }
    }
    cout<<ans<<endl;
    //cout<<endl;

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