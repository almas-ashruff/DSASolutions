Given a Binary Tree with all unique values and two nodes value n1 and n2. 
The task is to find the lowest common ancestor of the given two nodes. 
We may assume that either both n1 and n2 are present in the tree or none of them is present. 

// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1#

Node* lca(Node* root ,int n1 ,int n2 )
{
    if(!root) {
        return NULL;
    } // when a null value is encountered, Null is returned
    
    if(root -> data == n1 || root -> data == n2) {
        return root;
    } // when the gien value is found, return it.
    
    Node *node1 = lca(root -> left, n1, n2);
    Node *node2 = lca(root -> right, n1, n2);
    
    if(node1 && node2) {
        return root;
    } 
    // the node at which both child nodes are returning something, 
    // it is the answer
    
    
    // once that ans node is found, all other top nodes are useless,
    // since only one side of the tree will return a value
    if(node1) {
        return node1;
    } else {
        return node2;
    }
}