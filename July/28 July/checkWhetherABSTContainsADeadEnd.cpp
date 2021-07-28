// Given a Binary search Tree that contains positive integer values greater then 0. 
// The task is to complete the function isDeadEnd which returns true if the BST contains a dead end 
// else returns false. Here Dead End means, we are not able to insert any element after that node.

// https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

bool solve(Node* root,int min,int max){
    if(!root) {
        return 0;
    }
    if(min == max) {
        return true;
    }
    return solve(root -> left, min, root -> data - 1) 
        || solve(root -> right, root -> data + 1, max);
}


bool isDeadEnd(Node *root) {
    return solve(root, 1, INT_MAX);
}