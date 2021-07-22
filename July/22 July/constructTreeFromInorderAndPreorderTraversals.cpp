// Given 2 Arrays of Inorder and preorder traversal. 
// Construct a tree and print the Postorder traversal. 

// https://practice.geeksforgeeks.org/problems/construct-tree-1/1#

// https://www.youtube.com/watch?v=oAbSNJ35qAs
// https://www.youtube.com/watch?v=W9irlUOf6lI

// WATCH PEPCODING VIDEO FOR REVISION

Node * buildTreeHelper(int preorder[], int inorder[], int inStart, int inEnd, int preStart, int preEnd) {
    if(preStart > preEnd) {
        return NULL;
    }
    
    int rootData = preorder[preStart];
    Node *root = new Node(rootData);
    
    int rootIndex = -1;
    
    for(int i = 0; i <= inEnd; i++) {
        if(inorder[i] == rootData) {
            rootIndex = i;
            break;
        }
    }
    
    // left subtree
    
    int lPreStart = preStart + 1;
    int lInStart = inStart;
    int lInEnd = rootIndex - 1;
    int lPreEnd = lInEnd - lInStart + lPreStart;
    
    // right subtree
    
    int rPreStart = lPreEnd + 1;
    int rPreEnd = preEnd;
    int rInStart = rootIndex + 1;
    int rInEnd = inEnd;
    
    Node *leftTree = buildTreeHelper(preorder, inorder, lInStart, lInEnd, lPreStart, lPreEnd);
    Node *rightTree = buildTreeHelper(preorder, inorder, rInStart, rInEnd, rPreStart, rPreEnd);
    
    root -> left = leftTree;
    root -> right = rightTree;
    
    return root;
}


Node* buildTree(int in[],int pre[], int n)
{
    return buildTreeHelper(pre, in, 0, n - 1, 0, n -1);
}
