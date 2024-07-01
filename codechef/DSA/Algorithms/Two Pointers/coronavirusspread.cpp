#include <bits/stdc++.h>
using namespace std;

int main() {
	int k;
	cin>>k;
	while(k--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	      cin>>a[i];
	    }
	    sort(a,a+n);
	    int temp,b=n,c=0,count=1;
	    for(int i=0;i<n-1;++i){
	      temp=abs(a[i+1]-a[i]);
	      if(temp<=2){
	        ++count;
	      }
	      else{
	        b=min(b,count);
	        c=max(c,count);
	        count=1;
	      }
	    }
	    b=min(b,count);
	    c=max(c,count);
	    cout<<b<<" "<<c<<endl;
	}
  return 0;
}