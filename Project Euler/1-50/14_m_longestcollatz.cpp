#include <bits/stdc++.h>
using namespace std;
#define ll long long int

unordered_map<ll, int> collatzcount;

void fillcolcount(int n) {
    for (int i = 1; i <= n; i++) {
        ll num = i;
        int steps = 0;
        vector<ll> sequence;

        while (num != 1 && !collatzcount.count(num)) {
            sequence.push_back(num);
            if (num % 2 == 0) num /= 2;
            else num = 3 * num + 1;
            steps++;
        }

        if (collatzcount.count(num)) steps += collatzcount[num];
        else steps++;

        for (int j = 0; j < sequence.size(); j++) {
            collatzcount[sequence[j]] = steps - j;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int maxn;
    cin >> maxn;
    fillcolcount(maxn);

    int ans = 0, anss = 1;
    for (auto it = collatzcount.begin(); it != collatzcount.end(); ++it) {
        int x = it->second;
        int y = it->first;
        if (x > ans) {
            ans = x;
            anss = y;
        }
    }
    cout << anss << endl;
    return 0;
}
