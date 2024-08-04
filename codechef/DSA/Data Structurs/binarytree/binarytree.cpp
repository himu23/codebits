//at most two children: referred to as the left child and the right child;
//1) full binary tree: every node must have either 0 or 2 child nodes
//2) complete binary tree: all the levels should be completly filled, except possibly the last level and all the nodes in the last level must be as left as possible;
//3) balanced binary tree: the maximum depth of a node in the left subtree and the of right subtree must not differ than more than 1 for all the nodes in the tree;

//similar to a linked list the node contains an integer value and left/right pointers for children nodes. if there is no node oresent at left/right pointer it is initialized as null;
#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
};

node* node_new(int val){
    node* temp = new node();
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int main() {
    // Creating our root node
    node* root = node_new(0);
    // Assigning node '1' to the left of '0'
    root->left = node_new(1);
    // Assigning node '2' to the right of '0'
    root->right = node_new(2);
    // Similarly for the child nodes of the left(1)
    root->left->left = node_new(3);
    root->left->right = node_new(4);
    cout<<"The tree is created!\n";
    return 0;
}