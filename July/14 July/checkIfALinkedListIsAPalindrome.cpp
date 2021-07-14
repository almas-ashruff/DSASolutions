// Given a singly linked list of size N of integers. 
// The task is to check if the given linked list is palindrome or not.

// https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1#
// https://www.algoexpert.io/questions/Linked%20List%20Palindrome

// Solution 1
// Reverse the second half of the linked list.
// Compare start node with the second half's start node. 
// Continue for next nodes.

Node *reverse(Node *head) {
    Node *current = head, *previous = NULL, *nextNode = NULL;
    while(current) {
        nextNode = current -> next;
        current -> next = previous;
        previous = current;
        current = nextNode;
    }
    
    return previous;
}


bool isPalindrome(Node *head)
{
    Node *slowNode = head, *fastNode = head;
    
    while(fastNode && fastNode -> next) {
        slowNode = slowNode -> next;
        fastNode = fastNode -> next -> next;
    }
    
    Node *reversedHalf = reverse(slowNode);
    Node *firstHalf = head;
    
    while(reversedHalf) {
        if(reversedHalf -> data != firstHalf -> data) {
            return false;
        }
        reversedHalf = reversedHalf -> next;
        firstHalf = firstHalf -> next;
    }
    return true;
}



// Solution 2
// Use a stack to store the values.
// Compare while popping the stack.

bool isPalindrome(Node *head)
{
    
    stack<int> s;
    Node *temp = head;
    while(temp)
    {
        s.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(!s.empty())
    {
        
    
        if(s.top() !=temp->data)
        {
            return false;
        }
        temp = temp->next;
        s.pop();
        
    }
    return true;
}
