// Given a non-empty, singly linked list with head node head, return a middle node of linked list.
// If there are two middle nodes, return the second middle node.

// https://leetcode.com/problems/middle-of-the-linked-list/

ListNode* middleNode(ListNode* head) {
    if(!head || !head -> next) {
        return head;
    }
    ListNode *slow = head, *fast = head;
    
    while(fast -> next && fast -> next -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    if(!fast -> next) {
        return slow;
    }
    return slow -> next;
}