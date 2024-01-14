//used some brain
//my code works fine on smaller inputs
//but dosent work on extensive inputs
//will solve this again after learning pairs, vectors, and posts.
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0; i<n; i++){
	    cin>>a[i];
	}
	int q[m],w[m];
	string e[m];
	for(int i=0; i<m; i++){
	    cin>>q[i]>>w[i]>>e[i];
	}
	int b[n];
	for(int i=0;i<n;i++){
	    b[i]=w[a[i]-1];
	}
	int r[m];
	for(int i=0; i<m;i++){
	    r[i]=w[i];
	}
	sort(b,b+n,greater<int>());
	for(int i=0;i<n;i++){
	    for(int j=0; j<m; j++){
	        if(b[i]==w[j]){
	            cout<<e[j]<<endl;
	            r[j]=0;
	            break;
	        }
	    }
	}
	sort(r,r+m,greater<int>());
	for(int i=0;i<m-n;i++){
	    for(int j=0;j<m;j++){
	        if(r[i]==w[j] && r[i]!=0){
	            cout<<e[j]<<endl;
	        }
	    }
	}
	

}
