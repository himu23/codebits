//bitwise xor and and
#include <bits/stdc++.h>
using namespace std;

int msbp(int n){
    if(n==0) return 0;
    int block=1;
    while(n>>block)block++;
    return block;
}
int main() {
	int k;
	cin>>k;
	while(k--){
	    int n;
	    cin>>n;
	    vector<int>a(n);
	    for(int i=0;i<n;++i){
	        cin>>a[i];
	    }
	    vector<vector<int>>prec(n+1,vector<int>(32,0));
	    for(int i=0;i<n;i++){
	        int b=msbp(a[i]);
	        for(int j=0;j<32;j++){
	            prec[i+1][j]=prec[i][j]+(b==j);
	        }
	    }
	    int q; cin>>q;
	    while(q--){
	        int l,r,x;
	        cin>>l>>r>>x;
	        int b=msbp(x);
	        int ans=r-l+1-(prec[r][b]-prec[l-1][b]);
	        cout<<ans<<endl;
	    }
	}
    return 0;
}
