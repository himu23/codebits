#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct Node {
    int val; 
    Node *left;
    Node *right;

    Node(int node_value) {
        val = node_value;
        left = right = NULL;
    }
}; 

class Solution {
  public:
  int heightofbinarytree(Node* root){
    return max(0,depth(root)-1);
  }
  int depth(Node* root){
    if(root==0) return 0;
    int left=depth(root->left);
    int right=depth(root->right);
    return max(right,left)+1;
  }
    
};
//O(n)