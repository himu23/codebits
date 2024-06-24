//rated: hard //prefix sum
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vl;
#define vsort(v)  sort(v.begin(),v.end())
#define foor(i,b) for (int i = 0; i < (b); i++)
#define fort(i, a, b) for (int i = a; i < (b); i++)
#define trav(a, x) for (auto &a : x)
#define sz(x) (int)(x).size()
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
const char nl = '\n';
void test_case(){
    int n,m;
    cin>>n>>m;
    vi v(n);
    foor(i,n) cin>>v[i];
    vsort(v);
    foor(i,m){
        int x;
        cin>>x;
        int ans=0;
        auto it=lb(v.begin(),v.end(), x);
        ans = v.end() - it;
        vi vec(v.begin(), it);
        sort(vec.rbegin(), vec.rend());
        trav(y,vec){
            int z=y;
            while(z<x && !vec.empty()){
                vec.pop_back();
                z++;
            }
            if(z==x) ans++;

        }
        cout<<ans<<nl;
    }    
}
int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int t = 1;
    cin>>t;
    while(t--) test_case();
    return 0;
}