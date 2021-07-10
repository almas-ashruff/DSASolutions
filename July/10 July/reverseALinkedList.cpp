// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1
// https://www.algoexpert.io/questions/Reverse%20Linked%20List
// https://www.geeksforgeeks.org/reverse-a-linked-list/

// Iterative
LinkedList *reverseLinkedList(LinkedList *head) {
  LinkedList *previousNode = NULL;
	LinkedList *currentNode = head;
	LinkedList *nextNode = NULL;
	while(currentNode != NULL) {
		nextNode = currentNode -> next;
		currentNode -> next = previousNode;
		previousNode = currentNode;
		currentNode = nextNode;
	}
	
	return previousNode;
}

// Recursive
Node* reverse(Node* node)
{
    if (node == NULL)
        return NULL;
    if (node->next == NULL) {
        head = node;
        return node;
    }
    Node* node1 = reverse(node->next);
    node1->next = node;
    node->next = NULL;
    return node;
}