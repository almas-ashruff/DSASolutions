https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
https://www.youtube.com/watch?v=Of0HPkk3JgI
https://www.youtube.com/watch?v=Of0HPkk3JgI


// Recursive solution

struct node *reverse (struct node *head, int k)
{ 
    node *currentNode = head;
    node *previousNode = NULL;
    node *nextNode = NULL;
    int count = 0;
    while(currentNode != NULL && count < k) {
        nextNode = currentNode -> next;
        currentNode -> next = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
        count++;
    }
    
    node *nextHead = NULL;
    if(currentNode != NULL) {
        nextHead = reverse(currentNode, k);
    }
    
    head -> next = nextHead;
    return previousNode;
}