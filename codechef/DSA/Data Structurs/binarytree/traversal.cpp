/*
void preOrder(node root) {
    if (root == null) {
        return
    }
    print(root->value)
    preOrder(root->left)
    preOrder(root->right)
}
*/

//Traversing a binary tree is involves visiting all the nodes in the tree in a specific order.
//Pre-order traversal involves visiting the root node first,
//then recursively visiting the left subtree, and finally the right subtree.
/*
class Solution {
  public:
    void preOrderTraversal(Node* root) {
        // your code goes here
        if(root==NULL){
            return;
        }
        cout<<root->val<<" ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
    void postOrderTraversal(Node* root) {
        // your code goes here
        if(root==NULL){
            return;
        }
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout<<root->val<<" ";
    }
    void inOrderTraversal(Node* root) {
        // your code goes here
        if(root==NULL){
            return;
        }
        inOrderTraversal(root->left);
        cout<<root->val<<" ";
        inOrderTraversal(root->right);
    }
};
*/

//post order traversal: Post-order traversal involves visiting the left subtree first, then the right subtree, and finally the root node.
//This method is useful for deleting the tree and freeing up the space, as it ensures that child nodes are processed before their respective parent nodes.
//4, 5, 2, 3, 1

//inorder traversal: In-order traversal involves visiting the left subtree first, then the root node, and finally the right subtree.
//4, 2, 5, 1, 3