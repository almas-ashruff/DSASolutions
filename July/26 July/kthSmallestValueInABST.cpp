// Given a BST and an integer K. Find the Kth Smallest element in the BST. 

// https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1#


void solve(Node *root, int &k,int &ans){
    
    if (!root) {
        return;
    }
    solve(root -> left, k, ans);
    
    // k-- happens only after you reach the lowest right node (greatest value)
    k--;
    if(k == 0) {
        ans = root -> data;
    }
    
    // when run out of greater nodes
    solve(root ->r ight, k, ans);
}

int kthLargest(Node *root, int k)
{
    int ans =-1;
    solve(root, k, ans);
    return ans;
}