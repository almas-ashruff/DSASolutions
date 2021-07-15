// Given a doubly linked list of n elements. 
// The task is to reverse the doubly linked list.

// https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1#


Node* reverseDLL(Node * head)
{
    Node *currentNode = head;
    Node *nextNode = NULL;
    
    while(currentNode) {
        nextNode = currentNode -> next;

        if(!nextNode) { // when currentNode is the last node
            head = currentNode;
        }

        currentNode -> next = currentNode -> prev;
        currentNode -> prev = nextNode;
        currentNode = currentNode -> prev;
    }
    return head;
}