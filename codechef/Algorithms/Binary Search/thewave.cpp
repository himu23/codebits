//rated 1518
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
    int a[n],b[m];
    foor(i,n){
        cin>>a[i];
    }
    foor(i,m){
        cin>>b[i];
    }
    sort(a,a+n);
    foor(i,m){
        int p=b[i];
        if(binary_search(a,a+n,p)==0){
            int r=n-(ub(a,a+n,p)-a);
            if(r%2==0){
                cout<<"POSITIVE";
            }
            else{
                cout<<"NEGATIVE";
            }
        }
        else{
            cout<<'0';
        }
        cout<<nl;
    }

}
int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int t = 1;
    //cin>>t;
    while(t--) test_case();
    return 0;
}