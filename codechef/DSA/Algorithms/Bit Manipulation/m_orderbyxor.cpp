#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
	int k; k=1;
	cin>>k;
	while(k--){
	    int a,b,c; cin>>a>>b>>c;
	    int ans=0;
	    for(int i=29;i>=0;--i){
	        int x=(1<<i)^a;
	        int y=(1<<i)^b;
	        int z=(1<<i)^c;
	        if(x<y &&y<z){
	            a=x;
	            b=y;
	            c=z;
	            ans^=(1<<i);
	            break;
	        }
	        else if(x<min(y,z) || max(x,y)<z){
	            a=x;
	            b=y;
	            c=z;
	            ans^=(1<<i);
	        }
	    }
	    if(a<b && b<c) cout<<ans;
	    else cout<<-1;
	    cout<<endl;
	}
    return 0;
}
