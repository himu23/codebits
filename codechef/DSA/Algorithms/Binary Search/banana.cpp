//rated 1781
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

int binarySearch(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Avoid potential overflow

        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }

    return -1; // Target not found
}

bool banana(vi& v, ld val, ll m){
    ll sum=0;
    trav(a, v){
        sum+=ceil(a/val);
    }
    return sum<=m;
}
void test_case(){
    ll n,m;
    cin>>n>>m;
    vi v(n);
    foor(i,n){
        cin>>v[i];
    }
    ll first=1, last=1e9;
    while(first<last){
        ll mid=first+(last-first)/2;
        if(banana(v,mid,m)) last=mid;
        else first=mid+1;
    }
    cout<<first<<nl;
}
int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int t = 1;
    cin>>t;
    while(t--) test_case();
    return 0;
}