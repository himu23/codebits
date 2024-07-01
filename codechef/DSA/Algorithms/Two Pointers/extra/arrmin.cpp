#include <bits/stdc++.h>
using namespace std;

int main() {
	int k;
	cin>>k;
	while(k--){
	    int n,m,p;
	    cin>>n>>m>>p;
	    int a[n],b[m],c[p];
	    for(int i=0;i<n;i++) cin>>a[i];
	    for(int i=0;i<m;i++) cin>>b[i];
	    for(int i=0;i<p;i++) cin>>c[i];
	    int i=0,j=0,k=0;
	    int ans=INT_MAX;
	    while(i<n && j<m && k<p){
	      int temp=max({abs(a[i] - b[j]), abs(b[j] - c[k]), abs(a[i] - c[k])});
	      ans=min(ans,temp);
	      if(a[i]<=b[j] && a[i]<=c[k]){
	        i++;
	      }
	      else if(b[j]<=a[i] && b[j]<=c[k]){
	        j++;
	      }
	      else{
	        k++;
	      }
	    }
	    cout<<ans<<endl;
	}

}