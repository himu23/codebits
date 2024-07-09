//1868  //div 3 threshold question
//ummda... maja aa gaya
//did all by mysely without hinting anything from editorial
#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int MAXN = 300001;
vector<int>nc2(MAXN);
void getpref(){
    nc2[2]=1;
    for(int i=3;i<MAXN;i++){
        nc2[i]=nc2[i-1]+i-1;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(false);
	int k; k=1;
	getpref();
	cin>>k;
	while(k--){
	    int n,q; cin>>n>>q;
	    int a[n],b[q];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    for(int i=0;i<q;i++){
	        cin>>b[i];
	    }
	    sort(a,a+n);
	    vector<int>prf(n-2);
	    prf[0]=nc2[n-1];
	    for(int i=1;i<n-2;i++){
	        prf[i]=prf[i-1]+nc2[n-1-i];
	    }
	    /*for(int i=0;i<q;i++){
	        int x=b[i];
	        int j=n;
	        while(x>0 && j>=2){
	            j--;
	            x=x-nc2[j];
	        }
	        cout<<a[n-j-1]<<endl;
	    }*/
	    for(int i=0;i<q;i++){
	        int x=b[i];
	        auto it=lower_bound(prf.begin(),prf.end(),x);
	        int j=it-prf.begin();
	        //cout<<j<<" ";
	        cout<<a[j]<<endl;
	    }
	}
    return 0;
}
