// Given K sorted linked lists of different sizes. 
// The task is to merge them in such a way that after merging 
// they will be a single sorted linked list.

// https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1#
// https://www.youtube.com/watch?v=vhdmB3HKQdI

Node *merge(Node *head1, Node *head2) {
    Node *result = NULL;
    if(head1 == NULL) {
        return head2;
    } 
    if(head2 == NULL) {
        return head1;
    }
    
    if(head1 -> data <= head2 -> data) {
        result = head1;
        result -> next = merge(head1 -> next, head2);
    } else {
        result = head2;
        result -> next = merge(head1, head2 -> next);
    }
    return result;
    
}
Node * mergeKLists(Node *arr[], int k)
{
   int i = 0;
   int last = k - 1;
   int j;
   
   while(last != 0) {
        i = 0;
        j = last;
        while(i < j) {
            arr[i] = merge(arr[i], arr[j]);
            i++;
            j--;
            if(i >= j) {
               last = j;
            }
        }
    }
    return arr[0];
}