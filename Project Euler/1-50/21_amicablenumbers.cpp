#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int sumofdiv(int n)
{
    int sum = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
            sum += n / i;
            if (i * i == n)
                sum -= i;
        }
    }
    return sum + 1;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int k;
    k = 1;
    // cin>>k;
    while (k--)
    {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 4; i <= n; i++)
        {
            int temp = sumofdiv(i);
            if (temp != i && temp < n && sumofdiv(temp) == i)
            {
                ans += i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}