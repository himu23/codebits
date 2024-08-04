//BST: it is a special type of tree where for every node, the left child of that node is smaller then the node and the right child is greater.
/*Time Complexity for Search, Insert, Delete operations:
    Binary Tree - O(n)
    Binary Search Tree - O(h)
    where h is the height of tree which is log2(n) in best case when the tree is balanced.
*/

//A fully-skewed tree is functionally just a linked list, the height of the tree is equal to the total number of nodes,
//thus the time complexity of search operation in this tree is N.
// for balanced bst it is O(log(N));

#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node * left;
    node * right;
};

node * node_new(int val) {
    node * temp = new node();
    temp -> val = val;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

node * root;

void insert(int element) {
    if (root == NULL) {
        // Assigning first element of array as root
        root = node_new(element);
        return;
    }
    node * current = root;
    
    // We start traversal to insertion position from root
    while (1) {
        if (element < current -> val) {
            // If the value is lesser, we find in left subtree where to insert
            if (current -> left == NULL) {
                cout << "Inserting " << element << " in left of " << current -> val << "\n";
                current -> left = node_new(element);
                break;
                // End the loop when insertion is done
            }
            else {
                // Repeat the process for left subtree which is also a BST
                current = current -> left;
            }
        }
        else {
            if (current -> right == NULL) {
                cout << "Inserting " << element << " in right of " << current -> val << "\n";
                current -> right = node_new(element);
                break;
            }
            else {
                current = current -> right;
            }
        }
    }
}


class Solution {
  public:
    bool searchInBST(node* root, int x) {
        // return true if x is present
        if(root==NULL){
            return false;
        }
        if(root->val==x){
            return true;
        }
        return searchInBST(root->left,x) || searchInBST(root->right,x);
    }
};

int main() {
    vector < int > arr = {8, 3, 10, 1, 6, 14};
    root = NULL;
    for (int i = 0; i < 6; i++) {
        insert(arr[i]);
    }
    cout << "The BST is created!";
    return 0;
}