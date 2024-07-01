#include <bits/stdc++.h>
using namespace std;

int main() {
	int k;
	cin>>k;
	while(k--){
	    int n;
	    cin>>n;
	    int m=2*n;
	    int a[m];
	    for(int i=0;i<m;i++){
	      cin>>a[i];
	    }
	    sort(a,a+m);
	    int ans=a[m-1];
	    int temp;
	    for(int i=0;i<=m-n;i++){
	      temp=a[i+n-1]-a[i];
	      ans=min(temp,ans);
	    }
	    cout<<ans<<endl;
	}

}
