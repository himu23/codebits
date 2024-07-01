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
	    bool flag=1;
	    int m=ceil(static_cast<double>(n)/2);
	    int temp=1;
	    for(int i=0;i<m;i++){
	      if(a[i]!=a[n-i-1]){
	        flag=0;
	        break;
	      }
	      if(a[i]!=a[i+1] && i!=m-1){
	        temp++;
	      }
	      if(abs(a[i+1]-a[i])>1){
	        flag=0;
	        break;
	      }
	    }
	    if(flag && (temp==7 && a[0]==1)){
	      cout<<"yes";
	    }
	    else{
	      cout<<"no";
	    }
	    cout<<endl;
	}

}
