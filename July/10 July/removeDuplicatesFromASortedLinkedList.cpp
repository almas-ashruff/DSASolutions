Given a singly linked list consisting of N nodes. The task is to remove duplicates 
(nodes with duplicate values) from the given list (if exists).
Note: Try not to use extra space. Expected time complexity is O(N). 
The nodes are arranged in a sorted way.

// https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1#



Node *removeDuplicates(Node *head)
{
    if(!head || !head -> next) {
        return head;
    }
    
    Node *currentNode = head;
    Node *deleteNode = NULL;
    while (currentNode -> next) {
        if(currentNode -> data == currentNode -> next -> data) {
            deleteNode = currentNode -> next;
            currentNode -> next = currentNode -> next -> next;
            delete(deleteNode);
        } else { 
        // !important - else condition is necessary because what if the next to next value is the same 
            currentNode = currentNode -> next;
        }
    }
    return head;
}