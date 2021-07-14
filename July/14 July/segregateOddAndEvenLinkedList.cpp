// Given a link list of size N, modify the list such that all the even numbers 
// appear before all the odd numbers in the modified list. 
// The order of appearance of numbers within each segregation 
// should be same as that in the original list.

// https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1#

// Basically, get all the even nodes at the start, and add the odd nodes after the even nodes. 
// Then return the head of the new linked list (first even node).

Node* divide(int N, Node *head){
    if(!head || !head -> next) {
        return head;
    }
    
    Node *currentNode = head;
    Node *evenHead = new Node(0);
    Node *even = evenHead;
    Node *oddHead = new Node(0);
    Node *odd = oddHead;
    
    while(currentNode) {
        if(currentNode -> data % 2 == 0) {
            even -> next = currentNode;
            even = even -> next;
        } else {
            odd -> next = currentNode;
            odd = odd -> next;
        }
        
        currentNode = currentNode -> next;
    }
    
    if(!evenHead -> next) {
        return oddHead -> next; // if no even node exists
    }
    
    even -> next = oddHead -> next; // last even node's next is the first odd node
    odd -> next = NULL; // terminating the linked list with a NULL value
    return evenHead -> next;
}