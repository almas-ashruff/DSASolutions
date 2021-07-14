// Given a singly linked list, remove all the nodes which have a greater value on its following nodes.
// https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1#

Node *reverse(Node *head) {
    if(!head || !head -> next) {
        return head;
    }
    
    Node *prevNode = NULL, *currentNode = head, *nextNode = NULL;
    while(currentNode) {
        nextNode = currentNode -> next;
        currentNode -> next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    return prevNode;
}


Node *compute(Node *head)
{
    // Reverse the linked list, store the new head
    // Make a currentNode
    Node *currentNode = reverse(head);
    head = currentNode;
    
    while(currentNode -> next) {
        if(currentNode -> next -> data < currentNode -> data) {
            Node *temp = currentNode -> next;
            currentNode -> next = currentNode -> next -> next;
            delete(temp);
            // if the next value to the current node is smaller, delete
        } else {
            currentNode = currentNode -> next;
        }
    }
    // reverse again and return 
    return reverse(head);
}