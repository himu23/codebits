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
	    bool flag=0;
	    sort(a,a+n);
	    int i=0,j=0;
	    while(i<n && j<n){
	        int p=abs(a[i]-a[j]);
	        if(p==m){
	            flag=1;
	            break;
	        }
	        if(p>m){
	            i++;
	        }
	        if(p<m){
	            j++;
	        }
	    }
	    if(flag==0){
	        cout<<'0'<<endl;
	    }
	    else{
	        cout<<'1'<<endl;
	    }
	}

}
