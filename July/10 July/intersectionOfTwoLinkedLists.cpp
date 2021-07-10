// Given two singly linked lists of size N and M, write a program to get the point 
// where two linked lists intersect each other.

// https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1#
// https://www.youtube.com/watch?v=u4FWXfgS8jw


int intersectPoint(Node* head1, Node* head2)
{
    
    Node *nodeOne = head1, *nodeTwo = head2;
    if(head1 == NULL || head2 == NULL) 
        return -1;

    while(nodeOne != nodeTwo) {
        if(nodeOne == NULL) {
            nodeOne = head2;
        } else {
            nodeOne = nodeOne -> next;
        }
        if(nodeTwo == NULL) {
            nodeTwo = head1;
        } else {
            nodeTwo = nodeTwo -> next;
        }
    }
    
    return nodeOne;
}