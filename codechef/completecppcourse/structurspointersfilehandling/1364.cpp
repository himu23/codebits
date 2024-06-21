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
	    sort(a,a+n);
	    int b=0, c=0;
	    for(int i=0;i<n;i++){
	        c+=a[i];
	        if(c>m){
	            c=c-a[i];
	            c=c+ceil(a[i]/2.0);
	            if(c<=m) b++;
	            break;
	        }
	        b++;
	    }
	    cout<<b<<endl;
	}

}
