#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n; 
    cin >> n;
    if (n < 0) n = -n;

    // Initialize prime array
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;

    // Sieve of Eratosthenes
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    int consecutive = 0;
    int besta = 0;
    int bestb = 0;

    // Finding best a and b
    for (int a = -n; a <= n; a++) {
        for (int b = -n; b <= n; b++) {
            int len = 0;
            while (true) {
                int value = abs(len * len + a * len + b);
                if (value > n || !prime[value]) break;
                len++;
            }

            if (consecutive < len) {
                consecutive = len;
                besta = a;
                bestb = b;
            }
        }
    }

    cout << besta * bestb << endl;
    return 0;
}
