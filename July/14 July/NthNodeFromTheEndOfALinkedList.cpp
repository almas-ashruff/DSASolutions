// Given a linked list consisting of L nodes and given a number N. 
// The task is to find the Nth node from the end of the linked list.

// https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

int getNthFromLast(Node *head, int n)
{
       if(!head) {
           return -1;
       }
       
       Node *currentNode = head, *previousNode = head;
       
       int count = 0;
       
       while(currentNode) {
           count++;
           currentNode = currentNode -> next;
       }
       
       if(n > count) {
           return -1;
       }
       
       for(int i = 0; i < (count - n); i++) {
           previousNode = previousNode -> next;
       }
       return previousNode -> data;
}