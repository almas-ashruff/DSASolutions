// Given a binary tree. Check whether it is a BST or not.
// Note: We are considering that BSTs can not contain duplicate Nodes.

// https://practice.geeksforgeeks.org/problems/check-for-bst/1#

bool BSTChecker(Node *root, int min, int max) {
    if(!root) {
        return true;
    }
    
    if(root -> data >= max || root -> data <= min) {
        return false;
    }
    
    else {
        return BSTChecker(root -> left, min, root -> data) 
        && BSTChecker(root -> right, root -> data, max);
    }
}

bool isBST(Node* root) 
{
    return BSTChecker(root, INT_MIN, INT_MAX);
}