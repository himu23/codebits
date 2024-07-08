#define mod 1000000007
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
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
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