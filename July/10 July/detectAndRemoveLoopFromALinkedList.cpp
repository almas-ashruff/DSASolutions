// Given a linked list of N nodes such that it may contain a loop.
// Remove the loop from the linked list, if it is present.  

// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#
// https://www.youtube.com/watch?v=_BG9rjkAXj8


void removeLoop(Node* head)
{
    if(!head || !head -> next) {
        return;
    } // if the head is null or the second node is null, no cycle can exist as cycle does not have null
    
    Node *slow = head;
    Node *fast = head;
    
    while(fast -> next && fast -> next -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast) {
        // detects if a cycle exists in the linked list -> when fast and null
            break;
        }
    }
    
    if(slow == fast){ // if cycle exists
        slow = head;
        if(slow != fast) { // if cycle does not start at head
            while(slow -> next != fast -> next) {
                slow = slow -> next;
                fast = fast -> next;
            }
            fast -> next = NULL;
        } else { // if cycle start at head
            while(fast -> next != slow) {
                fast = fast -> next;
            }
            fast -> next = NULL;
        }
    }
    return;
}