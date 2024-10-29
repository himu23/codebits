#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to perform DFS
void dfs(int node, vector<bool>& visited, vector<vector<int>>& adjList) {
    // Mark the current node as visited
    visited[node] = true;
    
    // Process the current node (print or do other operations)
    cout << node << " ";

    // Explore all unvisited neighbors
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, adjList);
        }
    }
}

// Function to initialize DFS and handle disconnected components
void dfsHandler(int numNodes, vector<vector<int>>& adjList) {
    vector<bool> visited(numNodes + 1, false);

    // Iterate through all nodes to handle disconnected components
    for (int i = 1; i <= numNodes; ++i) {
        if (!visited[i]) {
            dfs(i, visited, adjList);
        }
    }
}

int main() {
   
    int numNodes, numEdges;
    cin >> numNodes >>  numEdges;
    vector<vector<int>> adjList(numNodes + 1);

    // Adding edges to the graph
    for(int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
       adjList[u].push_back(v);
       adjList[v].push_back(u);
    }

    // Perform DFS
    cout << "DFS traversal: ";
    dfsHandler(numNodes, adjList);

    return 0;
}

/*time complexity:
    //The time complexity of DFS is O(V + E), where V is the number of vertices (nodes) and E is the number of edges in the graph.
    //Each vertex and edge is visited once in the worst-case scenario.
*/
/*space complexity:
    //The space complexity of DFS is O(V) for the recursive implementation and O(V + E) for the iterative implementation using a stack.
    //The space required is proportional to the maximum depth of the recursion stack or the maximum size of the stack.
*/