// Given a binary tree, find its height.

// https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

int height(struct Node* node){
    if(!node) {
        return 0;
    }
    
    return max(height(node -> left) + 1, height(node -> right) + 1);
}