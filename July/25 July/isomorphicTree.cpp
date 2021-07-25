// Given two Binary Trees. Check whether they are Isomorphic or not.

// Note: 
// Two trees are called isomorphic if one can be obtained from another by a series of flips, 
// i.e. by swapping left and right children of several nodes. 
// Any number of nodes at any level can have their children swapped. 
// Two empty trees are isomorphic.
// For example, the following two trees are isomorphic with the following sub-trees flipped: 
// 2 and 3, NULL and 6, 7 and 8.

// https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1#

bool isIsomorphic(Node *root1,Node *root2)
{
    if(!root1 && !root2) {
        return true;
    }
    
    if((root1 && !root2) || (!root1 && root2)) {
        return false;
    }
    
    if(root1 -> data != root2 -> data) {
        return false;
    }
    
    return (isIsomorphic(root1 -> left, root2 -> left) 
    && isIsomorphic(root1 -> right, root2 -> right)) 
    || (isIsomorphic(root1 -> right, root2 -> left) 
    && isIsomorphic(root1 -> left, root2 -> right));
    
}