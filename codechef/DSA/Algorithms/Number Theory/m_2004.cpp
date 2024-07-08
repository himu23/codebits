//tough, you have to comeup with the following
//int ans = Y - X - (tot_primes_till[Y] - tot_primes_till[X + 1]);

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7;
bool prime[MAXN + 5];
int tot_primes_till[MAXN + 5];

void sieve()
{
     int n = MAXN;
     fill(begin(prime), end(prime), true);
     prime[0] = prime[1] = false;

     for (int i = 2; i <= n; i++)
     {
          tot_primes_till[i] = tot_primes_till[i - 1];

          if (!prime[i])
               continue;

          tot_primes_till[i]++;

          for (int j = 2 * i; j <= n; j += i)
          {
               prime[j] = false;
          }
     }
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     sieve();
     int tests;
     cin >> tests;

     while (tests--)
     {
          int X, Y;
          cin >> X >> Y;

          int ans = Y - X - (tot_primes_till[Y] - tot_primes_till[X + 1]);
//i would have never guessed this

          cout << ans << "\n";
     }
}