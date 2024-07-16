//DP[i]=max{Ai​,Ai​+DP[i−1]}.
//And Final Answer = max⁡{DP[1],DP[2],…,DP[N]}.
#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    cin >> k;
    while (k--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        vector<int> p, q;
        for (int i = 0; i < n; i++) {
            if (b[i] == 1) {
                p.push_back(a[i]);
            } else {
                q.push_back(a[i]);
            }
        }

        int anp = LLONG_MIN;
        int anq = LLONG_MIN;

        if (!p.empty()) {
            vector<int> dpp(p.size());
            dpp[0] = p[0];
            for (int i = 1; i < p.size(); i++) {
                dpp[i] = max(p[i], p[i] + dpp[i - 1]);
            }
            anp = dpp[0];
            for (int i = 1; i < p.size(); i++) {
                anp = max(anp, dpp[i]);
            }
        }

        if (!q.empty()) {
            vector<int> dpq(q.size());
            dpq[0] = q[0];
            for (int i = 1; i < q.size(); i++) {
                dpq[i] = max(q[i], q[i] + dpq[i - 1]);
            }
            anq = dpq[0];
            for (int i = 1; i < q.size(); i++) {
                anq = max(anq, dpq[i]);
            }
        }

        cout << max(anp, anq) << endl;
    }
    return 0;
}
