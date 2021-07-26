// Given a Binary Tree, write a function to populate next pointer for all nodes. 
// The next pointer for every node should be set to point to inorder successor.

// https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1

Node* prev=NULL;
void populateNext(Node *root)
{
    if(!root){
        return;
    }
    
    populateNext(root->left);
    if(prev){
        prev -> next = root;
    }
    prev = root;
    populateNext(root -> right);
}