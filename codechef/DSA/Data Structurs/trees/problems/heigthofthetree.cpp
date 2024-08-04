#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int maxx=100001;
vector<int>tree[maxx];

void getlon(int &ans, int parent, int d, int node){
    ans=max(ans,d);
    for(int v: tree[node]){
        if(v!=parent){
            getlon(ans, node, d+1, v);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
	int n; cin>>n;
	int m=n-1;
	int a,b;
	while(m--){
	    cin>>a>>b;
	    tree[a].push_back(b);
	    tree[b].push_back(a);
	}
	int ans=0;
	getlon(ans,-1,0,1);
	cout<<ans<<endl;
    return 0;
}
