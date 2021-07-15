// Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
// (i) a next pointer to the next node,
// (ii) a bottom pointer to a linked list where this node is head.
// Each of the sub-linked-list is in sorted order.
// Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
// Note: The flattened list will be printed using the bottom pointer instead of next pointer.

// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1#
// https://www.youtube.com/watch?v=ysytSSXpAI0

// Similar to merging two linked lists

Node *merge(Node *head1, Node *head2) {
    Node *temp = new Node(0);
    Node *result = temp;
    
    while(head1 && head2) {
        if(head1 -> data < head2 -> data) {
            temp -> bottom = head1;
            temp = temp -> bottom;
            head1 = head1 -> bottom;
        } else {
            temp -> bottom = head2;
            temp = temp -> bottom;
            head2 = head2 -> bottom;
        }
    }
    if(head1) {
        temp -> bottom = head1;
    } else {
        temp -> bottom = head2;
    }
    
    return result -> bottom;
}


Node *flatten(Node *root)
{
    if(!root || !root -> next) {
        return root;
    }   
    
    root -> next = flatten(root -> next);
    
    root = merge(root, root -> next);
    
    return root;
}