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
    vector<vector<pair<int,int>>> a(n,vector<pair<int,int>>(n));
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            a[i][j].first=s[j]-'0';
            a[i][j].second=1;
        }
    }
    int m=n/2;
    vector<vector<int>> temp;
    for(int i=0;i<m;i++){
        vector<int> temp2;
        int b=i+1;
        for(int j=b-1;j<n-(b-1);j++){
            for(int k=b-1;k<n-(b-1);k++){
                if(j==b-1 && a[j][k].second==1){
                    temp2.push_back(a[j][k].first);
                    a[j][k].second=0;
                }
                else if(k==n-(b-1)-1 && a[j][k].second==1){
                    temp2.push_back(a[j][k].first);
                    a[j][k].second=0;
                }
            }
        }
        vector<int>temp3;
        for(int j=b-1;j<n-(b-1);j++){
            for(int k=b-1;k<n-(b-1);k++){
                if(k==b-1 && a[j][k].second==1){
                    temp3.push_back(a[j][k].first);
                    a[j][k].second=0;
                }
                else if(j==n-(b-1)-1 && a[j][k].second==1){
                    temp3.push_back(a[j][k].first);
                    a[j][k].second=0;
                }
            }
        }
        reverse(temp3.begin(),temp3.end());
        temp2.insert(temp2.end(),temp3.begin(),temp3.end());
        temp.push_back(temp2);
    }
    int ans=0;
    for(int i=0;i<temp.size();i++){
        int ans1=0;
        vector<int> v=temp[i];
        int h=v.size();
        int g=(h+3)/4;
        if(g==0) g=1;
        vector<vector<int>> temp2(g);
        for(int j=0;j<h;j++){
            temp2[j%g].push_back(v[j]);
        }
        for(int j=0;j<g;j++){
            vector<int> w=temp2[j];
            int ans2=0;
            int countone=0,countzero=0;
            for(int k=0;k<w.size();k++){
                if(w[k]==1) countone++;
            }
            countzero=w.size()-countone;
            ans2=min(countone,countzero);
            ans1+=ans2;
        }
        ans+=ans1;
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