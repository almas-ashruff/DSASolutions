// You are given a special linked list with N nodes where each node has a next pointer 
// pointing to its next node. 
// You are also given M random pointers, where you will be given M number of pairs 
// denoting two nodes a and b  i.e.  a->arb = b.
// Construct a copy of the given list. The copy should consist of exactly N new nodes, 
// where each new node has its value set to the value of its corresponding original node. 
// Both the next and random pointer of the new nodes should point to new nodes in the copied list 
// such that the pointers in the original list and copied list represent the same list state. 
// None of the pointers in the new list should point to nodes in the original list.
// For example, if there are two nodes X and Y in the original list, where X.random --> Y, 
// then for the corresponding two nodes x and y in the copied list, x.random --> y.
// Return the head of the copied linked list.

// https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1#


Node *copyList(Node *head)
{
    Node *nextNode, *tempNode;
    Node *currentNode = head;
    
    while(currentNode) {
        nextNode = currentNode -> next;
        currentNode -> next = new Node(currentNode -> data);
        currentNode -> next -> next = nextNode;
        currentNode = nextNode;
    }
    
    currentNode = head;
    while(currentNode) {
        currentNode -> next -> arb = (currentNode -> arb) ? currentNode -> arb -> next : NULL;
        currentNode = currentNode -> next -> next;
    }
    
    Node *original = head, *copy = head -> next;
    
    tempNode = copy;
    
    while(original && copy) {
        original -> next = original -> next ? original -> next -> next : original -> next;
        copy -> next = copy -> next ? copy -> next -> next : copy -> next;
        
        original = original -> next;
        copy = copy -> next;
    }
    
    return tempNode;
}