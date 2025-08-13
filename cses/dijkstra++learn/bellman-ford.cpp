//when to use
// Graph can have negative edge weights.
// Need shortest path (or in High Score’s case, longest path).
// Can also detect negative cycles (or positive cycles if maximizing).
// Complexity: O(n·m) — slower than Dijkstra, but safer for negatives.

//idea:
//we know in a graph with n nodes, the shortest path has at most n-1 edges
//so if we relax all edges n-1 times, all shortest disatnces are found (if no negative cycle)

//algo(shortest path)
//dist[source]=0;
//repeat n-1 times:
//  foreach edge (u,v,w):
//      if dist[u]+w<dist[v]:
//          dist[v]=dist[u]+w;
//realxing=trying to improve dist[v] using u;

//negative cycle detection:
//do a nth iteration. if any distance can still be improved, that vertex si either in or rechale from a negative cycle

//turing it into a maximum path problem(high score)
//for high score: we want maximum sum not minimum
//just flip the comparision: 
//  if(dist[u]+w.dist[v]) dist[v]=dist[u]+w;
//detecting infinite score:
//  if there's a positive cycle rechable from node 1 and leading to n, you can kepp looping and get an infinite score--> answer id -1
//steps: 1. run bellman ford for n-1 iterations(get tentative max scores)
//2. run 1 more iteration: if a node improves mark it as affected by a positive cycle
//  bfs/dfs from these nodes to see if you can reach n
//if yes-->-1
//understood the core concept thanks to abdul bari
#include <bits/stdc++.h>
using namespace std;
const long long INF=4e18;

struct Edge {
    int u, v;
    long long w;
};


bool bellmanford(int n, int m, int src, vector<Edge> &edges, vector<long long> &dist) {
    dist.assign(n + 1, INF);
    dist[src] = 0;

    // Relax edges n-1 times
    for (int i = 1; i <= n - 1; i++) {
        bool updated = false;
        for (auto &e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                updated = true;
            }
        }
        if (!updated) break; // early stop if no update
    }

    // Check for negative cycle
    for (auto &e : edges) {
        if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
            return true; // negative cycle exists
        }
    }
    return false; // no negative cycle
}
int main() {
    int n,m; cin>>n>>m;
    vector<Edge> edges(m);
    for(int i=0;i<m;i++){
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
    }
    vector<long long> dist;
    bool hasnegcycle=bellmanford(n,m,1,edges,dist);
    if(hasnegcycle){
        cout<<"Negative cycle detected"<<endl;
    }
    else{
        for(int i=1;i<=n;i++){
            if(dist[i]==INF) cout<<"INF";
            else cout<<dist[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}