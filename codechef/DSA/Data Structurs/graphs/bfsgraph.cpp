#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform BFS
void bfs(int start, vector<bool>& visited, vector<vector<int>>& adjList) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    // Process nodes in the queue
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        // Enqueue unvisited neighbors
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
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

    // Perform BFS starting from node 1
    vector<bool> visited(numNodes + 1, false);
    cout << "BFS traversal: ";
    bfs(1, visited, adjList);

    return 0;
}

//time complexity: O(N+M);
//space complexity: O(N);