// Given a Binary Search Tree (BST) and a range l-h(inclusive), 
// count the number of nodes in the BST that lie in the given range.

// The values smaller than root go to the left side
// The values greater and equal to the root go to the right side

// https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1#

void solve(Node *root,int l,int h,int &count)
{
    if(!root) {
        return;
    }
    
    solve(root -> left, l, h, count);
    if(root -> data >= l && root -> data <= h) {
        count++;
    }
    solve(root -> right, l, h, count);
}

int getCount(Node *root, int l, int h)
{
    if(!root) {
        return 0;
    }
        
    int count = 0;
    solve(root, l, h, count);
    return count;
}