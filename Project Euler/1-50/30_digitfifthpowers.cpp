#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
  unsigned int exponent;
  std::cin >> exponent;

  // result
  unsigned int sum = 0;

  // there can't be a number with 8 digits (or more) which fulfils the condition for exponent=6
  // if all digits are 9s, then
  // 7 digits: 7 * 9^6 = 3720087
  // 8 digits: 8 * 9^6 = 4251528
  for (unsigned int i = 2; i <= 7*9*9*9*9*9*9; i++)
  {
    // sum of i's digits to the power of "exponent"
    unsigned int thisSum = 0;

    // split current number into its digit
    unsigned int reduce = i;
    while (reduce > 0)
    {
      // take the right-most digit
      unsigned int digit = reduce % 10;
      // and remove it
      reduce /= 10;

      // compute digit^exponent, could use pow() as well
      unsigned int power = 1;
      for (unsigned int j = 1; j <= exponent; j++)
        power *= digit;

      // add to thisSum
      thisSum += power;
    }

    // sum of digits^n equal to the original number ?
    if (thisSum == i)
      sum += i;
  }

  // and we're done
  std::cout << sum << std::endl;
  return 0;
}