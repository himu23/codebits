//my intellect is increasing
//Devu wants to know how many houses are safe for him to escape from the cops.
//Help him in getting this information.
#include <bits/stdc++.h>
using namespace std;

int main() {
	int k;
	cin>>k;
	while(k--){
	    int m,x,y,z;
	    cin>>m>>x>>y;
	    z=x*y;
	    int a[m],b[100];
	    for(int i=0; i<100;i++){
	        b[i]=i+1;
	    }
	    for(int i=0; i<m;i++){
	        cin>>a[i];
	    }
	    for(int i=0; i<m;i++){
	        for(int j=0; j<100; j++){
	            if(b[j]>=max(1,a[i]-z) && b[j]<=min(100,a[i]+z)){
	                b[j]=0;
	            }
	        }
	    }
	    int count=0;
	    for(int i=0; i<100; i++){
	        if(b[i]!=0){
	            count++;
	        }
	    }
	    cout<<count<<endl;
	}

}
