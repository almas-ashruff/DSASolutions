// Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

// Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you 
// could reach when you always travel preferring the left subtree over the right subtree. 
// Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
// Reverse right boundary nodes: defined as the path from the right-most node to the root. 
// The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree.
// Exclude the root from this as it was already included in the traversal of left boundary nodes.


// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#



// SOLUTION

// 1.Traverse Left
// Concept is traverse left side till you get the leftmost leaf node,
// Don't include the leftmost node in output vector reason is you will encounter 
// the same node while traversing bottom boundary.

// 2.Bottom Boundary
// Include all those nodes which have NULL in left and right side

// 3.Right Boundary
// Traverse till right side till you get the rightmost leaf node,
// Don't include the rightmost node in output vector as it was already there 
// when you traversed for bottom boundary.
// Note : Do not forget corner cases like second left-most node does not have 
// left child but right child exist.




void leafnodes(Node *root, vector<int> &ans){
    if(!root) {
        return;
    }
    
    leafnodes(root -> left, ans);

    //If the current node is leaf node
    if(!root -> left && !root -> right)
        ans.push_back(root -> data);
    
    leafnodes(root -> right, ans);
}

void left_boundary(Node *root, vector<int> &ans){
    if(!root) {
        return;
    }

    //If the node is not the leaf node then push it back
    if(root -> left || root -> right)
        ans.push_back(root->data);
    
    if(root -> left) {
        left_boundary(root -> left, ans);
    }
    else if(root -> right) {
        left_boundary(root -> right,ans);
    }

}

void right_boundary(Node *root, vector<int> &ans){
    if(!root) {
        return;
    }
    

    //Using else if condition because when recursion backtrack it checks for right tree also
    //If at node N it is any internal node then it'll be wrong.
    if(root -> right) {
        right_boundary(root -> right, ans);
    }
    else if(root -> left) {
        right_boundary(root -> left, ans);
    }

    //If the node is not the leaf node then push it back
    if(root -> left || root -> right)
        ans.push_back(root -> data);
}

vector<int> printBoundary(Node *root)
{
    vector<int> ans;
    if(!root) {
        return ans;
    }
    
    ans.push_back(root -> data);
    
    left_boundary(root -> left, ans);
    leafnodes(root, ans);
    right_boundary(root -> right, ans);
    
    return ans;
}