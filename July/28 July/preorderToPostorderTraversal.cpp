// Given an array arr[] of N nodes representing preorder traversal of BST. 
// The task is to print its postorder traversal.

// https://practice.geeksforgeeks.org/problems/preorder-to-postorder4423/1

Node* constructTree(int pre[], int size) {
    Node *head = newNode(pre[0]);
    Node *curr = head;

    for(int i = 1; i < size; i++) {
        while(curr!=NULL) {
            if(curr->data > pre[i]) {

                if(curr->left == NULL){ 
                    curr->left = newNode(pre[i]); 
                    break;
                } else {
                    curr = curr->left;
                }
            } else {
                if(curr->right == NULL) { 
                    curr->right = newNode(pre[i]); 
                    break;
                } else {
                    curr = curr->right;
                }
            }
        }
        curr = head;
    }
    return head;
}