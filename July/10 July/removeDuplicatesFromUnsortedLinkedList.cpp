// Given an unsorted linked list of N nodes. The task is to remove duplicate elements from 
// this unsorted Linked List. When a value appears in multiple nodes, the node which appeared first 
// should be kept, all others duplicates are to be removed.

// https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1#

Node * removeDuplicates( Node *head) 
{
    unordered_set<int> nodeData; 
    // hash set to keep a track of data
    
    if(!head || !head -> next) {
        return head;
    }
    
    Node *currentNode = head;
    Node *deleteNode = NULL;
    
    
    while(currentNode -> next) {
        nodeData.insert(currentNode -> data);
        //  insert currentNode -> data in the set
        if(nodeData.find(currentNode -> next -> data) != nodeData.end()) {
        // check if next node's data exits in the set
            deleteNode = currentNode -> next;
            currentNode -> next = currentNode -> next -> next;
            delete(deleteNode);
        } else { 
        // else, shift current node
            currentNode = currentNode -> next;
        }
    }
    return head;
}