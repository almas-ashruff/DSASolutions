// Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
// Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.

// https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1#

  
Node* merge(Node* head1, Node* head2) {
    Node *dummy = new Node(0);
    Node *temp = dummy;
    
    if(!head1) {
        return head2;
    } 
    if(!head2) {
        return head1;
    }
    while(head1 && head2) {
        if(head1 -> data > head2 -> data) {
            temp -> next = head2;
            temp = temp -> next;
            head2 = head2 -> next;
        } else {
            temp -> next = head1;
            temp = temp -> next;
            head1 = head1 -> next;
        }
    }
    if(head1) {
        temp -> next = head1;
    }
    if(head2) {
        temp -> next = head2;
    }
    return dummy -> next;
}


//Function to sort the given linked list using Merge Sort.
Node* mergeSort(Node* head) {
    if(!head || !head -> next) {
        return head;
    }
    Node *fast = head, *slow = head;
    while(fast -> next && fast -> next -> next) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    
    Node *temp = slow;
    slow = slow -> next;
    temp -> next = NULL;
    return merge(mergeSort(head), mergeSort(slow));
}