#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
const ll MAXN = 1e6;

long long fac[MAXN + 1];
long long inv[MAXN + 1];

/** Computes x^n modulo m in O(log n) time. */
long long exp(long long x, long long n, long long m) {
	x %= m;  // note: m * m must be less than 2^63 to avoid ll overflow
	long long res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}
	return res;
}

/** Precomputes n! from 0 to MAXN. */
void factorial(long long m) {
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % m; }
}

/**
 * Precomputes all modular inverse factorials
 * from 0 to MAXN in O(n + log n) time
 */
void inverses(long long m) {
	inv[MAXN] = exp(fac[MAXN], m - 2, m);
	for (int i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % m; }
}

/** Computes nCr mod p */
long long choose(long long n, long long r, long long m) {
	return fac[n] * inv[r] % m * inv[n - r] % m;
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
	int k; k=1;
	cin>>k;
	factorial(mod);
	inverses(mod);
	while(k--){
	    ll n,m;
	    cin>>n>>m;
	    cout<<choose(n,m,mod)<<endl;
	    
	}
    //cerr << "Time : " << 1000 * ((double)clock()) / CLOCKS_PER_SEC << "ms" << endl;
    return 0;
}
