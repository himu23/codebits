//#tough....really tough
//took me four months to solve
//perfect binary search question
//lambda expressions
#include <bits/stdc++.h>
using namespace std;
#define int long long int

int optimalcount(int* prf,int x,int t){
    auto getsum = [&](int i,int j){
        if(i==0) return prf[j];
        else return prf[j]-prf[i-1];
    };
    int count=0;
    t--;
    int l=0,r=t;
    while(l<=r){
        int m=l+(r-l)/2;
        if(getsum(m,t)+m<(t-m+1)*x) l=m+1;
        else{
            r=m-1;
            count=t-m+1;
        }
    }
    
    return count;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(false);
	int k; k=1;
	cin>>k;
	while(k--){
	    int n,m; cin>>n>>m;
	    int a[n],b[m];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    for(int i=0;i<m;i++){
	        cin>>b[i];
	    }
	    sort(a,a+n);
        int prf[n];
        prf[0]=a[0];
        for(int i=1;i<n;i++){
            prf[i]=a[i]+prf[i-1];
        }
        for(int i=0;i<m;i++){
            int count=0;
            int x=b[i];
            int* it=lower_bound(a,a+n,x);
            int target=it-a;
            //cout<<target<<endl;
            count+=n-target;
            count+=optimalcount(prf,x,target);
            cout<<count<<endl;
        }
	}
    return 0;
}
