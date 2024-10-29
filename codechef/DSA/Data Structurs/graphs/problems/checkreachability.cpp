#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int maxx=100005;
vector<int> graphx[maxx];
vector<bool> vis(maxx,0);

void dfs(int n){
    if(vis[n]){
        return;
    }
    vis[n]=true;
    for(auto u: graphx[n]){
        dfs(u);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int a,b;
    while(m--){
        cin>>a>>b;
        graphx[a].push_back(b);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        if(vis[i]){
            cout<<i<<" ";
        }
    }
    return 0;
}
