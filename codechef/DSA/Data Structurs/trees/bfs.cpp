//In BFS algorithm, we focus on traversing the tree "breadth-wise", i.e,
//The nodes in the next level are traversed only after all the nodes at the current level/depth have been traversed.
//This property is useful in various applications, such as finding the shortest path.

//more memory intensive than dfs
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int maxx=100005;
vector<int> tree[maxx];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n; cin>>n;
    int a,b;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        tree[a].push_back(b);
    }
    queue<int>qu;
    qu.push(1);
    while(!qu.empty()){
        int temp=qu.front();
        cout<<temp<<" ";
        qu.pop();
        for(int i=0;i<tree[temp].size();i++){
            qu.push(tree[temp][i]);
        }
    }
    return 0;
}
