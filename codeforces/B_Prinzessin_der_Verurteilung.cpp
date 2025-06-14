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

vector<string> vec;
void fill_vector(){
    for(int i=97;i<=122;i++){
        string s="";
        s+=char(i);
        vec.push_back(s);
    }
    for(int i=97;i<=122;i++){
        string s="a";
        s+=char(i);
        vec.push_back(s);
    }
    for(int i=97;i<=122;i++){
        string s="b";
        s+=char(i);
        vec.push_back(s);
    }
    for(int i=97;i<=122;i++){
        string s="c";
        s+=char(i);
        vec.push_back(s);
    }
    for(int i=97;i<=122;i++){
        string s="d";
        s+=char(i);
        vec.push_back(s);
    }
    for(int i=97;i<=122;i++){
        string s="e";
        s+=char(i);
        vec.push_back(s);
    }
    for(int i=97;i<=122;i++){
        string s="f";
        s+=char(i);
        vec.push_back(s);
    }
    for(int i=97;i<=122;i++){
        string s="g";
        s+=char(i);
        vec.push_back(s);
    }
    for(int i=97;i<=122;i++){
        string s="h";
        s+=char(i);
        vec.push_back(s);
    }
    for(int i=97;i<=122;i++){
        string s="i";
        s+=char(i);
        vec.push_back(s);
    }
    for(int i=97;i<=122;i++){
        string s="j";
        s+=char(i);
        vec.push_back(s);
    }
    for(int i=97;i<=122;i++){
        string s="k";
        s+=char(i);
        vec.push_back(s);
    }for(int i=97;i<=122;i++){
        string s="l";
        s+=char(i);
        vec.push_back(s);
    }for(int i=97;i<=122;i++){
        string s="m";
        s+=char(i);
        vec.push_back(s);
    }for(int i=97;i<=122;i++){
        string s="n";
        s+=char(i);
        vec.push_back(s);
    }for(int i=97;i<=122;i++){
        string s="o";
        s+=char(i);
        vec.push_back(s);
    }for(int i=97;i<=122;i++){
        string s="p";
        s+=char(i);
        vec.push_back(s);
    }for(int i=97;i<=122;i++){
        string s="q";
        s+=char(i);
        vec.push_back(s);
    }for(int i=97;i<=122;i++){
        string s="r";
        s+=char(i);
        vec.push_back(s);
    }for(int i=97;i<=122;i++){
        string s="s";
        s+=char(i);
        vec.push_back(s);
    }for(int i=97;i<=122;i++){
        string s="t";
        s+=char(i);
        vec.push_back(s);
    }for(int i=97;i<=122;i++){
        string s="u";
        s+=char(i);
        vec.push_back(s);
    }for(int i=97;i<=122;i++){
        string s="v";
        s+=char(i);
        vec.push_back(s);
    }for(int i=97;i<=122;i++){
        string s="w";
        s+=char(i);
        vec.push_back(s);
    }for(int i=97;i<=122;i++){
        string s="x";
        s+=char(i);
        vec.push_back(s);
    }for(int i=97;i<=122;i++){
        string s="y";
        s+=char(i);
        vec.push_back(s);   
    }for(int i=97;i<=122;i++){
        string s="z";
        s+=char(i);
        vec.push_back(s);
    }for(int i=97;i<=122;i++){
        string s="aa";
        s+=char(i);
        vec.push_back(s);
    }for(int i=97;i<=122;i++){
        string s="ab";
        s+=char(i);
        vec.push_back(s);
    }for(int i=97;i<=122;i++){
        string s="ac";
        s+=char(i);
        vec.push_back(s);
    }for(int i=97;i<=122;i++){
        string s="ad";
        s+=char(i);
        vec.push_back(s);
    }for(int i=97;i<=122;i++){
        string s="ae";
        s+=char(i);
        vec.push_back(s);
    }for(int i=97;i<=122;i++){
        string s="af";
        s+=char(i);
        vec.push_back(s);
    }//
}

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    for(int i=0;i<vec.size();i++){
        size_t pos=s.find(vec[i]);
        if(pos == string::npos){
            cout<<vec[i]<<endl;
            return;
        }
    }

}

int main() {
    fill_vector();
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}