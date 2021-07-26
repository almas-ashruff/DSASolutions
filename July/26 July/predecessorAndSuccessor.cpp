// There is BST given with root node with key part as integer only. 
// You need to find the inorder successor and predecessor of a given key. 
// In case, if the either of predecessor or successor is not found print -1.

// Input:
// The first line of input contains an integer T denoting the number of test cases. 
// Then T test cases follow. Each test case contains n denoting the number of edges of the BST. 
// The next line contains the edges of the BST. The last line contains the key.

// Output:
// Print the predecessor followed by successor for the given key. 
// If the predecessor or successor is not found print -1.

// https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1#


void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

    if(!root) {
        return;
    } // if root is empty, return
    
    // when root exists
    if(root -> key > key) { // when root is greater than key
        suc = root; // update the successor
        return findPreSuc(root -> left, pre, suc, key); // find the predecessor on left
    } else if(root -> key < key) { // when root is smaller than the key
        pre = root;// update the predecessor
        return findPreSuc(root -> right, pre, suc, key); // find the successor on right
    } else { // when equal
        if(root -> left) { // if left child exists, update predecesor
            findPreSuc(root -> left, pre, suc, key); //
        } 
        if(root -> right) { // if right child exists, update successor
            findPreSuc(root -> right, pre, suc, key);
        }
    }
}