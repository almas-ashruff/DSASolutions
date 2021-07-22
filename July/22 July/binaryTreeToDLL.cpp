// Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. 
// The left and right pointers in nodes are to be used as previous 
// and next pointers respectively in converted DLL. 
// The order of nodes in DLL must be same as Inorder of the given Binary Tree. 
// The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

// https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1#

// Iterative solution
Node * bToDLL(Node *root)
{
    // left is prev pointer and right is next pointer 
    if(!root) {
        return NULL;
    }
    
    Node *curr = root;
    Node *dummy = newNode(0);
    Node *prev  = dummy;
    
    while(curr) { // while current node exists
    
        if(!curr -> left) { // if curr -> left does not exist
            prev -> right = curr; // prev -> next = curr
            curr -> left = prev; // curr -> prev = prev;
            prev = curr; // prev is shifted to next position
            curr = curr -> right; // current is shifted to next position
        } else {
            Node *pred = curr -> left; 
            // predecessor node is the left node of the current node
            
            while(pred -> right && pred -> right != curr) {
            // while predecessor has a right, which does not equal current
                pred = pred -> right; // keep finding the actual predecessor
            }
            
            if(!pred -> right) { // if pred does not have a right
                pred -> right = curr; // pred -> next = current
                curr = curr -> left; // current -> prev = pred
            } else { // if pred has a right which is current
                pred -> right = NULL; // pred -> next is empty
                prev -> right = curr; // prev -> next = current
                curr -> left = prev; // current -> prev = prev
                prev = curr; // prev is shifted
                curr = curr -> right; // current is shifted
            }
        }
    }
    root = dummy -> right;
    root -> left = NULL;
    
    return root;
}


// Recursive solution
Node *prev = NULL;
Node *bToDLL(Node *root)
{
    if (root == NULL)
        return root;
        
    Node *head = bToDLL(root->left);
    if (prev == NULL)
    {
        head = root;
    }
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    bToDLL(root->right);
    return head;
}