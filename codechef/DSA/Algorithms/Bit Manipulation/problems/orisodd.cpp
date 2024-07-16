#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
	int k; k=1;
	cin>>k;
	while(k--){
	    int n,m; cin>>n>>m;
	    int a[n],b[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        b[i]=a[i]%2;
	    }
	    int c=0;
	    for(int i=0;i<m;i++){
	        c+=b[i];
	    }
	    int ans=0;
	    if(c>0) ans++;
	    for(int i=m;i<n;i++){
	        c-=b[i-m];
	        c+=b[i];
	        if(c>0) ans++;
	    }
	    cout<<ans<<endl;
	}
    return 0;
}
