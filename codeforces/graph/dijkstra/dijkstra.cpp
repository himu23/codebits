#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

//dijkstra babyyyyyyyyyyyyyyyyyy
int main(){
    ll n,m; cin>>n>>m;
    vector<vector<pair<ll,ll>>> adj(n);
    for(ll i=0;i<m;i++){
        ll u,v,w; cin>>u>>v>>w;
        u--,v--;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq; //dist,node
    pq.push({0,0});
    vector<ll> dist(n,INF);
    dist[0]=0;
    while(!pq.empty()){
        auto [d,u]=pq.top();pq.pop();
        if(d>dist[u]) continue;
        for(auto [v,w]:adj[u]){
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
    if(dist[n-1]==INF) cout<<-1<<endl;
    else cout<<dist[n-1]<<endl;
    return 0;
}