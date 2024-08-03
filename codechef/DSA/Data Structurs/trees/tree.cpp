//tree is a non linear data structure that follows a hierarchial pattern.
//Each point has it's successors (or children) and predecessors (parent or ancestors).
/*
// Node(or vertice): The vertices in a tree are called nodes. They may contain data such as an integer value, or their children nodes.
// Edges: As in general polygons, edges connect vertices (or in this case nodes).
// Root: The node at the top, which is an ancestor for all other nodes is called the root (yes, the tree we study in data structures is kind of an inverted real life tree where root is at the top and branching takes place as we go down).
// Leaves: The nodes with no children, i.e., the nodes in the last layer are called leaf nodes.
// Depth of a node: Length of the path from root to node.
// Height of a node: Length of path from the nearest leaf to the node.
// Degree of a node: The number of children the node has
// Heigth of a tree: the number of edges on the longest downward path


*/

//for a tree with n nodes: number of edges= n-1;

//there are two ways to store and represent a tree
// 1) adjacency matrix: Suppose there are N nodes in a tree, we create a N x N matrix where matrix[i][j] represents there is a directed node from node i to node j.
// Note that matrix[1][3]=1 but matrix[3][1]=0 because there is a directed edge from 1 to 3 and not vice-versa.
// 2) adjacency list: in list represention for a node i, we store children of the node, This approach is more space efficient than adjacency matrix when number of edges are significantly less than vertices.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // This is our adjacency list
    vector < int > tree[n];
    
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        
        // Adding an edge from u to v
        tree[u].push_back(v);
        
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < tree[i].size(); j++) {
            cout << tree[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

//adjacency matrix is easy