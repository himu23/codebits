#include <iostream>
#include <vector>
#include <unordered_set>
#define ll long long int
#define mod 1000000007
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> A(n + 1, vector<int>(n + 1));
    vector<vector<vector<int>>> fr(n + 1, vector<vector<int>>(n + 1, vector<int>(10, 0)));
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> A[i][j];
        }
    }
    // Building the prefix frequency array
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            for (int k = 0; k < 10; ++k){
                fr[i][j][k] = fr[i - 1][j][k] + fr[i][j - 1][k] - fr[i - 1][j - 1][k];
            }
            fr[i][j][A[i][j] - 1]++;
        }
    }
    int q;
    cin >> q;
    while (q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = 0;
        for (int k = 0; k < 10; ++k){
            int count = fr[x2][y2][k] - fr[x1 - 1][y2][k] - fr[x2][y1 - 1][k] + fr[x1 - 1][y1 - 1][k];
            if (count > 0){
                ans++;
            }
        }
        cout << ans << endl;
    }
    cerr << "Time : " << 1000 * ((double)clock()) / CLOCKS_PER_SEC << "ms" << endl;
    return 0;
}