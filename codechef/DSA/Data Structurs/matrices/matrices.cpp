// a(row,column);
//square and rectangular matrix;
//identity, symmetric, sparse(most of the elements are zero);

//matrix multiplication
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> v(n + m - 1);


    for (int i = 0; i < n; ++i) {
        int x = i, y = 0;
        while (x < n && y < m) {
            v[i].push_back(a[x][y]);
            ++x;
            ++y;
        }
    }

    for (int j = 1; j < m; ++j) {
        int x = 0, y = j;
        while (x < n && y < m) {
            v[n - 1 + j].push_back(a[x][y]);
            ++x;
            ++y;
        }
    }


    for (auto &diag : v) {
        sort(diag.begin(), diag.end());
    }

    vector<vector<int>> b(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        int x = i, y = 0, d = i;
        while (x < n && y < m) {
            b[x][y] = v[d][x - i];
            ++x;
            ++y;
        }
    }

    for (int j = 1; j < m; ++j) {
        int x = 0, y = j, d = n - 1 + j;
        while (x < n && y < m) {
            b[x][y] = v[d][x];
            ++x;
            ++y;
        }
    }


    for (const auto &row : b) {
        for (const auto &val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}

