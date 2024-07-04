#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}
	int b[n],c[n];
	b[0]=a[0],c[n-1]=a[n-1];
	for(int i=1;i<n;i++){
	    b[i]=__gcd(a[i],b[i-1]);
	    c[n-i-1]=__gcd(a[n-i-1],c[n-i]);
	}
	int ans=0;
	for(int i=0;i<n;i++){
	    if(i==0){
	        ans=max(ans,c[1]);
	    }
	    if(i==n-1){
	        ans=max(ans,b[n-2]);
	    }
	    else{
	        ans=max(ans,__gcd(b[i-1],c[i+1]));
	    }
	}
	cout<<ans<<endl;
	
}