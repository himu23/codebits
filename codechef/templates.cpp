#include "bits/stdc++.h"
using namespace std;
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