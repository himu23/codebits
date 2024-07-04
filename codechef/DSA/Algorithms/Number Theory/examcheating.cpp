//n%p=m%p=b  n=ap+b  m=cp+b    n-m=p(a-c)==pd
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
int numdiv(int n){
    double ans=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            ans++;
        }
        if(n==i*i) ans-=0.5;
    }
    return ans*2;
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
	int k; k=1;
	cin>>k;
	while(k--){
	    int n,m; cin>>n>>m;
	    cout<<numdiv(abs(n-m))<<endl;
	}
    cerr << "Time : " << 1000 * ((double)clock()) / CLOCKS_PER_SEC << "ms" << endl;
    return 0;
}
