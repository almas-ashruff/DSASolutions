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
    } // if both roots are absent, true
    
    if((root1 && !root2) || (!root1 && root2)) {
        return false;
    } // if only one root is absent and the other root is present
    
    if(root1 -> data != root2 -> data) {
        return false;
    } // if the data of the two roots is not the same 
    
    return (isIsomorphic(root1 -> left, root2 -> left) 
    && isIsomorphic(root1 -> right, root2 -> right)) 
    || (isIsomorphic(root1 -> right, root2 -> left) 
    && isIsomorphic(root1 -> left, root2 -> right));
    

    // pair the children in the same order and by swapping. 
    // If the ans is still true, return true
}