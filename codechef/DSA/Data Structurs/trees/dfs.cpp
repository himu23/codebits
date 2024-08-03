//Depth-First Search (DFS) is a tree traversal algorithm that explores as far as possible along each branch before backtracking. 
//DFS is often implemented using a recursive approach or a stack data structure.
/*
void dfs(int node){
    // print node or do anything with it...
    for(int child: tree[node]){ // tree is stored as adjacency list
        dfs(child);
    }
}*/

#include <bits/stdc++.h>
using namespace std;

const int maxx = 100005;
vector <int> tree[maxx];

void dfs(int node) {
    cout << node << " ";
    for (auto i: tree[node]) {
        dfs(i);
    }
}

int main() {
    int n;
    cin >> n;
    
    
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
    }
    
    // Start DFS from the root node
    dfs(1);
}
