#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        vector<int> b(n), c(n);
        b[0] = a[0];
        c[n-1] = a[n-1];
        for (int i = 1; i < n; i++) {
            b[i] = __gcd(a[i], b[i-1]);
            c[n-i-1] = __gcd(a[n-i-1], c[n-i]);
        }
        int ans = sum;
        for (int i = 0; i < n; i++) {
            int g;
            if (i == 0) {
                g = c[1];
            } else if (i == n-1) {
                g = b[n-2];
            } else {
                g = __gcd(b[i-1], c[i+1]);
            }
            ans = min(ans, 1 + (sum - a[i]) / g);
        }
        cout << ans << endl;
    }
    return 0;
}