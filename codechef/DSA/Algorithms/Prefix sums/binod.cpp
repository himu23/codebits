#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	int k;
	cin>>k;
	while(k--){
	    int n,q;
	    cin>>n>>q;
	    vector<int>a(n);
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    vector<vector<int>>prec(n+1,vector<int>(60,0));
	    for(int i=0;i<n;i++){
	        for(int j=0;j<60;j++){
	            prec[i+1][j]=prec[i][j]+((a[i] >> j) & 1);
	        }
	    }
	    while(q--){
	        int k,l1,r1,l2,r2;
	        cin>>k>>l1>>r1>>l2>>r2;
	        int s1=prec[r1][k]-prec[l1-1][k];
	        int s2=prec[r2][k]-prec[l2-1][k];
	        int u1=r1-l1+1-s1;
	        int u2=r2-l2+1-s2;
	        cout<<(s1*u2+s2*u1)<<endl;
	    }
	}
	return 0;

}