// Given a binary tree you need to check if it follows max heap property or not.

// https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1#


bool isHeap(struct Node * root)
{
    if(!root || (!root -> left && !root -> right)) {
        return true;
    }
    
    if(!root -> left && root -> right) {
        return false;
    }
    
    if((root -> left && root -> data < root -> left -> data) 
        || (root -> right && root -> data < root -> right -> data)) {
            return false;
        }
    return isHeap(root -> left) && isHeap(root -> right);
}