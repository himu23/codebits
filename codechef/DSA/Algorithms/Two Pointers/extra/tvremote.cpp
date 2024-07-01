#include <bits/stdc++.h>
using namespace std;

int main() {
	int k;
	cin>>k;
	while(k--){
	    int n,m;
	    cin>>n>>m;
	    vector<pair<int,char>>vi(n+m);
	    for(int i=0;i<n;i++){
	        int x;
	        cin>>x;
	        vi[i].first=x;
	        vi[i].second='f';
	    }
	    for(int i=n;i<n+m;i++){
	        int x;
	        cin>>x;
	        vi[i].first=x;
	        vi[i].second='c';
	    }
	    sort(vi.begin(),vi.end());
	    int ans=0,temp='f';
	    for(int i=0;i<n+m;i++){
	        if(vi[i].second!=temp){
	            ++ans;
	            if(temp=='f') temp='c';
	            else if(temp=='c') temp='f';
	        }
	    }
	    cout<<ans<<endl;
	    
	}

}
