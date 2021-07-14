// Given a Cirular Linked List of size N, split it into two halves circular lists. 
// If there are odd number of nodes in the given circular linked list then out of the resulting two halved lists, 
// first list should have one node more than the second list. 
// The resultant lists should also be circular lists and not linear lists.

// https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1#


void splitList(Node *head, Node **head1, Node **head2)
{
    Node *slow = head, *fast = head;
    
    while(fast -> next != head && fast -> next -> next != head) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
    *head1 = head;
    *head2 = slow -> next;
    slow -> next = head;
    
    if(fast -> next == head) {
        fast -> next = *head2;
    } else {
        fast -> next -> next = *head2;
    }
}