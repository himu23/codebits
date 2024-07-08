#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define MOD 1000000007

vector<int> vec(1000001, 0);
const int MAXN = 1000001;
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

void getfacts(int n, unordered_map<int, int>& factorCount) {
    while (n != 1) {
        factorCount[spf[n]]++;
        n /= spf[n];
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(false);
    int k;
    cin >> k;
    Sieve();

    while (k--) {
        int n;
        cin >> n;
        int a[n];
        unordered_map<int, int> factorCount;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[i] = x;
            getfacts(x, factorCount);
        }

        int ans = 1;
        for (auto &pair : factorCount) {
            ans = (ans * (pair.second + 1)) % MOD;
        }

        cout << ans << endl;
    }

    cerr << "Time : " << 1000 * ((double)clock()) / CLOCKS_PER_SEC << "ms" << endl;
    return 0;
}
