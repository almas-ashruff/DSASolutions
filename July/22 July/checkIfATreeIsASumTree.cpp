// Given a Binary Tree. Return 1 if, for every node X in the tree other than the leaves, its value is 
// equal to the sum of its left subtree's value and its right subtree's value. Else return 0.

// An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. 
// A leaf node is also considered a Sum Tree.

// https://practice.geeksforgeeks.org/problems/sum-tree/1#

int helper(Node *root, bool &res) {
    if(!root) { // when root is null
        return 0;
    }
    
    //sum = sum of left + sum of right
    int sum =  helper(root -> left, res) + helper(root -> right, res);
    
    
    // res is false when sum != root data AND 'both' left and right subtrees exist
    if(sum != root -> data && !(!root -> left && !root -> right)) {
        res = false;
    }
    
    return sum + root -> data;
}

bool isSumTree(Node* root)
{
     bool res = true;
     helper(root, res);
     return res;
}