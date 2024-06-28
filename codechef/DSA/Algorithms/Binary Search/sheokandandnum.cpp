//rated 1534
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vl;
#define vsort(v)  sort(v.begin(),v.end())
#define foor(i,b) for(int i = 0; i < (b); i++)
#define fort(i, a, b) for(int i = a; i < (b); i++)
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
int a[465];
void iniarray(){
    int b=0;
foor(i,31){
    fort(j,i+1,31){
        a[b]=pow(2,i)+pow(2,j);
        b++;
    }
}
sort(a, a + 465);
}
void test_case(){
    int n;
    cin>>n;
    if(n==1) cout<<2<<nl;
    else if(n==2) cout<<1<<nl;
    else{
        int f=(lb(a,a+465,n)-a);
        int g=(lb(a,a+465,n)-a)-1;
        int h=(ub(a,a+465,n)-a);
        cout<<min(min(abs(a[g]-n),abs(a[f]-n)),abs(a[h]-n))<<nl;
    }
    
}
int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int t = 1;
    cin>>t;
    iniarray();
    while(t--) test_case();
    return 0;
}