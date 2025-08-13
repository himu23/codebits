#include <bits/stdc++.h>
using namespace std;
const int INF=1e6+5;
int main() {
    int n,m; cin>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    while(m--){
        int a,b,w; cin>>a>>b>>w;
        adj[a].push_back({b,w});
    }
    vector<int> dist(n+1,INF);
    dist[1]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        if(d!=dist[u]) continue; //skip outdated entries (>would also work)
        for(auto[v,w]:adj[u]){
            if(dist[v]>d+w){
                dist[v]=d+w;
                pq.push({dist[v],v});
            }
        }
    }
    cout<<dist[n]<<endl;
    return 0;
}