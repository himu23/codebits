//did the same 1610 problem with vectors and pairs learned mainy things
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}
	int q[m],w[m];
	string e[m];
	for(int i=0;i<m;i++){
	    cin>>q[i]>>w[i]>>e[i];
	}
	for(int i=0;i<n; i++){
	    for(int j=0; j<m; j++){
	        if(a[i]==q[j]){
	            q[j]=m+1;
	        }
	    }
	}
	for(int j=0;j<m;j++){
	    if(q[j]!=m+1){
	        q[j]=0;
	    }
	}
	int r[m];
	for(int i=0;i<m;i++){
	    r[i]=w[i];
	}
	vector<pair<int,int>>v;
	for(int i=0;i<m;i++){
	    v.push_back({q[i],w[i]});
	}
	sort(v.begin(),v.end());
	for(int i=m;i>=0;i--){
	    for(int j=0;j<m;j++){
	        if(v[i].second==r[j]){
	            cout<<e[j]<<endl;
	        }
	    }
	}

}
