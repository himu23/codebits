//i dont know why this fails on test 2 everything looks good
// #include <bits/stdc++.h>

// using namespace std;

// template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
// template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// void dbg_out() { cerr << endl; }
// template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
// #ifdef LOCAL
// #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
// #else
// #define dbg(...)
// #endif

// #define ar array
// #define ll long long
// #define ld long double
// #define sza(x) ((int)x.size())
// #define all(a) (a).begin(), (a).end()

// const int MAX_N = 1e5 + 5;
// const ll MOD = 1e9 + 7;
// const ll INF = 1e9;
// const ld EPS = 1e-9;



// void solve() {
//     ll n,k,b,s; cin>>n>>k>>b>>s;
//     if(s==0){
//         while(n--){
//             cout<<"0"<<" ";
//         }
//         cout<<endl;
//         return;
//     }
//     vector<ll> temp(n);
//     ll temp2=b/n;
//     ll temp3=b%n;
//     for(ll i=0;i<n;i++){
//         temp[i]=temp2;
//     }
//     ll temp4=0;
//     while(temp3--){
//         temp[temp4]++;
//         temp4++;
//     }
//     ll temp5=0;
//     for(ll i=0;i<n;i++){
//         temp5+=(temp[i]+1)*k-1;
//     }
//     ll temp6=k*b;
//     if(!(s>=temp6 && s<=temp5)){
//         cout<<"-1"<<endl;
//         return;
//     }
//     else{
//         // cout<<"hahaha"<<endl;
//         // return;
//         //cout<<temp6<<" "<<temp5<<endl;
//         // ll temp7=s/k;
//         // if(temp7==b){
//         //     ll m=n-1;
//         //     while(m--){
//         //         cout<<0<<" ";
//         //     }
//         //     cout<<s<<endl;
//         //     return;
//         // }
//         //cout<<0<<" "<<3<<" "<<3<<" "<<3<<" "<<29<<endl;
//         //cout<<temp7<<endl;
//         vector<ll> temp8(n);
//         ll temp9=temp5-s;
//         //cout<<temp9<<" ";
//         bool flag=false;
//         for(ll i=0;i<n;i++){
//             temp8[i]=(temp[i]+1)*k-1;
//             if(temp9>=(k-1) && !flag){
//                 temp8[i]-=(k-1);
//                 temp9-=(k-1);
//             }
//             else if(temp9<(k-1) && !flag && (temp8[i]>=temp9)){
//                 temp8[i]-=temp9;
//                 temp9=0;
//                 flag=true;
//             }
//             cout<<temp8[i]<<" ";
//         }
//         cout<<endl;
//     }
    
// }

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     int tc = 1;
//     cin >> tc;
//     for (int t = 1; t <= tc; t++) {
//         // cout << "Case #" << t << ": ";
//         solve();
//     }
// }

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
    ll n,k,b,s; cin>>n>>k>>b>>s;
    ll temp2=k*b;
    ll temp3=temp2+n*(k-1);
    if(s>temp3 || s<temp2){
        cout<<-1<<endl;
        return;
    }
    vector<ll> ans(n);
    ans[0]=k*b;
    ll temp4=s-k*b;
    for(ll i=0;i<n;i++){
        if(temp4>=(k-1)){
            ans[i]+=k-1;
            temp4-=k-1;
        }
        else{
            ans[i]+=temp4;
            temp4=0;
        }
    }
    for(ll i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return;
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