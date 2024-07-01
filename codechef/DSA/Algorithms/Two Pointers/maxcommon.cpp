//Find the number of elements that are common in both the arrays.
#include <bits/stdc++.h>
using namespace std;

int main() {
	int k;
	cin>>k;
	while(k--){
	    int n;
	    cin>>n;
	    int a[n],b[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    for(int i=0;i<n;i++){
	        cin>>b[i];
	    }
	    sort(a,a+n);
	    sort(b,b+n);
	    int ans=0;
	    int i=0,j=0;
	    while(i<n && j<n){
	        if(a[i]==b[j]){
	            i++,j++;
	            ans++;
	        }
	        else if(a[i]<b[j]){
	            i++;
	        }
	        else if(a[i]>b[j]){
	            j++;
	        }
	    }
	    cout<<ans<<endl;
	    
	}

}
