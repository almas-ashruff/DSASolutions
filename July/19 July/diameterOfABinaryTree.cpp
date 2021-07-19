// Given a Binary Tree, find diameter of it.
// The diameter of a tree is the number of nodes on the 
// longest path between two end nodes in the tree. 
// The diagram below shows two trees each with diameter nine, 
// the leaves that form the ends of a longest path are shaded 
// (note that there is more than one path in each tree of length nine, 
// but no path longer than nine nodes).

// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1#
// https://www.algoexpert.io/questions/Binary%20Tree%20Diameter

// https://www.youtube.com/watch?v=GJg2EYolN-E

int height(Node* root) {
    if(!root) {
        return 0;
    }
    return 1 + max(height(root -> left), height(root -> right));
}

int diameter(Node* root) {
    if(!root) {
        return 0;
    }
    
    int leftOption = diameter(root -> left);
    int rightOption = diameter(root -> right);
    int rootOption = height(root -> left) + height(root -> right) + 1;
    
    return max({leftOption, rightOption, rootOption});
}