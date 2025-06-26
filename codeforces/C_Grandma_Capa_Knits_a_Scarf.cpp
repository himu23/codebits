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

bool ispalindrome(string s){
    bool ans=true;
    ll n=s.length();
    for(ll i=0;i<n/2;i++){
        if(s[i]!=s[n-i-1]){
            ans=false;
            break;
        }
    }
    return ans;
}

void solve() {
    ll n; cin>>n;
    string s; cin>>s;
    set<char> st;
    for(ll i=0;i<n;i++){
        st.insert(s[i]);
    }
    if(ispalindrome(s)){
        cout<<0<<endl;
        return;
    }
    ll ans=n;
    for(char x:st){
        string temp=s;
        temp.erase(remove(temp.begin(),temp.end(),x),temp.end());
        if(ispalindrome(temp)){
            // ans=min(ans,(ll)(n-temp.length()));
            vector<ll> temp2(n);
            for(ll i=0;i<n;i++){
                if(s[i]==x) temp2[i]=1;
                else temp2[i]=0;
            }
            ll temp3=0;
            ll l=0,r=n-1;
            while(l<=r && l<n && r>=0){
                if(temp2[l]==0 && temp2[r]==1){
                    r--;
                    temp3++;
                }
                else if(temp2[l]==1 && temp2[r]==0){
                    l++;
                    temp3++;
                }
                else{
                    l++;
                    r--;
                }
            }
            ans=min(ans,temp3);
        }
    }
    if(ans==n) cout<<-1<<endl;
    else cout<<ans<<endl;
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