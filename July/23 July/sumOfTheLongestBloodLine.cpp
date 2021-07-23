// Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), 
// that find the sum of all nodes on the longest path from root to leaf node.
// If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.

// https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1#

int maxSum, maxHeight;

void solve(Node *root, int height, int sum) {
    if(!root) {
        return;
    }
    
    sum += root -> data; // sum with the above nodes and current data
    
    if(height >= maxHeight) { // if height equals or exceeds current max height
        maxHeight = height;
        maxSum = max(sum, maxSum);
    }
    
    // add child nodes to the maxsum
    solve(root -> left, height + 1, sum);
    solve(root -> right, height + 1, sum);
}

int sumOfLongRootToLeafPath(Node *root)
{
    maxHeight = 0;
    maxSum = 0;
    // initialize the two values to 0
    
    solve(root, 0, 0);
    
    return maxSum;
}