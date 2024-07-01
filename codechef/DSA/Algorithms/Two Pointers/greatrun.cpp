#include <bits/stdc++.h>
using namespace std;

int main() {
	int k;
	cin>>k;
	while(k--){
	    int n,m;
	    cin>>n>>m;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int b=0;
	    for(int i=0;i<m;i++){
	        b+=a[i];
	    }
	    int ans=b;
	    int i=0,j=m;
	    while(j<n){
	        b=b-a[i]+a[j];
	        i++;
	        j++;
	        ans=max(ans,b);
	    }
	    cout<<ans<<endl;
	}

}
