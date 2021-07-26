// Given a Binary search tree. Your task is to complete the function which will 
// return the Kth largest element without doing any modification in Binary Search Tree.

// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1#


void solve(Node *root, int &k,int &ans){
    
    if (!root) {
        return;
    }
    solve(root -> right, k, ans);
    
    // k-- happens only after you reach the lowest right node (greatest value)
    k--;
    if(k == 0) {
        ans = root -> data;
    }
    
    // when run out of greater nodes
    solve(root -> left, k, ans);
}

int kthLargest(Node *root, int k)
{
    int ans =-1;
    solve(root, k, ans);
    return ans;
}