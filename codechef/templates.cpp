//
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
const int MOD = 1e9 + 7;
const char nl = '\n';
void test_case(){
    int n;
    cin>>n;
    
    
}
int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int t = 1;
    cin>>t;
    while(t--) test_case();
    return 0;
}
//ceil(a/b)=(a+b−1)/b

int gcd(int a,int b) { // a >= b
  int R;
  while (b > 0)  {
    R = a % b;
    a = b;
    b = R;
  }
  return a;
}
int fastpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
void SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    prime[1] = false;
  
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}
//spf[n]  gives smallest prime factor of n
const int MAXN = 100001;
int spf[MAXN];
void Sieve() {
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;
  
    for (int i = 2; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

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
string binstr(int n){
    if(n==0){
        return "0";
    }
    string binary;
    while(n>0){
        binary=(n%2==0 ? "0":"1")+binary;
        n/=2;
    }
    return binary;
}

int msbp(int n){
    if(n==0) return 0;
    int block=1;
    while(n>>block)block++;
    return block;
}