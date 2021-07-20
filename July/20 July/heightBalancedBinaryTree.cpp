// Given a binary tree, find if it is height balanced or not. 
// A tree is height balanced if difference between heights of 
// left and right subtrees is not more than one for all nodes of tree. 

// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1#

// https://www.algoexpert.io/questions/Height%20Balanced%20Binary%20Tree


int height(Node *root) {
    if(!root) {
        return 0;
    }
    
    return 1 + max(height(root -> left), height(root -> right));
}


bool isBalanced(Node *root)
{
    if(!root) {
        return true;
    }
    
    int leftHeight = height(root -> left);
    int rightHeight = height(root -> right);
    
    return abs(leftHeight - rightHeight) <= 1 && isBalanced(root -> left) && isBalanced(root -> right);
}
