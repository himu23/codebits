void SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    prime[1] = false;
  
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

int main() {
    cin.tie(0)->sync_with_stdio(false);
	int a,b; cin>>a>>b;
	int n=a+b+1;
	bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    prime[1] = false;
  
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    int ans=0;
	for(int i=2;i<=a+b;i++){
	    if(prime[i]){
	        ans++;
	    }
	}
	cout<<ans<<endl;
    cerr << "Time : " << 1000 * ((double)clock()) / CLOCKS_PER_SEC << "ms" << endl;
    return 0;
}
