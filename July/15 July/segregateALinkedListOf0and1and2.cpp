// Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. 
// The task is to segregate 0s, 1s, and 2s linked list such that 
// all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

// https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1#


Node* segregate(Node *head) {
        
    if(!head) {
        return head;
    }
    
    Node *currentNode = head;
    
    Node *zero = new Node(0);
    Node *zeroT = zero;
    
    Node *one = new Node(1);
    Node *oneT = one;
    
    Node *two = new Node(2);
    Node *twoT = two;
    
    while(currentNode) {
        if(currentNode -> data == 0) {
            zeroT -> next = currentNode;
            zeroT = zeroT -> next;
        } else if(currentNode -> data == 1) {
            oneT -> next = currentNode;
            oneT = oneT -> next;
        } else {
            twoT -> next = currentNode;
            twoT = twoT -> next;
        }
        currentNode = currentNode -> next;
    }
    
    twoT -> next = NULL;
    oneT -> next = two -> next;
    zeroT -> next = one -> next;
    head = zero -> next;
    
    return head;
}