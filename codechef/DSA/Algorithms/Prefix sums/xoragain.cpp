//learned and used some properties of xor
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
	int k; k=1;
	cin>>k;
	while(k--){
	    int n,m; cin>>n>>m;
	    string s;
	    cin>>s;
	    int ans=0;
	    int temp=0;
	    for(int i=0;i<n-m+1;i++){
	        temp=temp^(s[i]-'0');
	    }
	    if(temp==1) ans++;
	    for(int i=n-m+1;i<n;i++){
	        temp=temp^(s[i-(n-m+1)]-'0');
	        temp=temp^(s[i]-'0');
	        if(temp==1) ans++;
	    }
	    cout<<ans<<endl;
	}
    cerr << "Time : " << 1000 * ((double)clock()) / CLOCKS_PER_SEC << "ms" << endl;
    return 0;
}
