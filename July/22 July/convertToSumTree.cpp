// Given a Binary Tree of size N , where each node can have positive or negative values. 
// Convert this to a tree where each node contains the sum of the left and right sub trees 
// of the original tree. The values of leaf nodes are changed to 0.

// https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1#


void toSumTree(Node *node)
{
    sumTreeHelper(node);
}
 
int sumTreeHelper(Node *node) {
    if(!node) {
        return 0;
    }
    
    int temp = node -> data; // store current nodes data
    int leftSum = sumTreeHelper(node -> left);
    int rightSum = sumTreeHelper(node -> right);
    
    node -> data = leftSum + rightSum; // current node data is the sum of the subtrees data
    
    return node -> data + temp; // return temp + subtree data
}