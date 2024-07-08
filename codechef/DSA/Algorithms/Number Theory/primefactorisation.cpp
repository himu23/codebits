#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
int spf[MAXN+1];
vector<int> V;

void Sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        // Initialising the spf of each number as the number itself
        spf[i] = i;
  
    for (int i = 2; i * i < MAXN; i++) {
        // checking if i is prime or has been marked before
        if (spf[i] == i) {
            // marking SPF for all numbers divisible by i
            for (int j = 2 * i; j < MAXN; j += i)
                // marking spf[j] only if it hasn't been marked earlier
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

int main() {
	int n;
	cin >> n;
	
    Sieve();
	V = getFactorization(n);
	for(int i=0; i<V.size(); i++){
	    cout << V[i] << endl;
	}
	return 0;
}