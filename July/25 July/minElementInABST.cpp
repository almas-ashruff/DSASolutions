// Given a Binary Search Tree. The task is to find the minimum element in this given BST.

// https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1

int minValue(Node* root)
{
    while(root -> left) {
        root = root -> left;
    }
    
    return root -> data;
}
