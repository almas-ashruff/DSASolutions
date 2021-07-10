// https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1
// https://www.youtube.com/watch?v=354J83hX7RI
// Given a linked list of N nodes. The task is to check if the linked list has a loop. 
// Linked list can contain self loop.



bool detectLoop(Node* head)
{
    if(!head || !head -> next) {
        return false;
    }
    
    Node *slow = head;
    Node *fast = head;
    while(fast -> next && fast -> next -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast) {
            return true;
        }
    }
    return false;
}