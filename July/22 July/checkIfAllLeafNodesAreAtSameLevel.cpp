// Given a Binary Tree, check if all leaves are at same level or not.

// https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1#


int height(Node *root) {
    if(!root) { // when reached leaf node
        return 0;
    }
    
    // check height of subtrees
    int leftHeight = height(root -> left);
    int rightHeight = height(root -> right);
    
    if(leftHeight == -1 || rightHeight == -1) {
        return -1;
    } // if any of the subtrees have unequal heights, return -1
    
    if(root -> left && root -> right && leftHeight != rightHeight){ 
    // if left and right nodes exist but they have unequal height, return -1
        return -1;
    } else {
        return 1 + max(leftHeight, rightHeight);
    }
}
bool check(Node *root)
{
    if(height(root) == -1) {
        return false;
    }
    return true;
}