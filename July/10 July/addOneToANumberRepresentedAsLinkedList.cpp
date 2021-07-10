// A number N is represented in Linked List such that each digit corresponds to a node in linked list. 
// You need to add 1 to it.
// https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1#


// SOLUTION

// If last node's data is not 9 then just add 1 to it and return head.
// If last node's data is 9 then you have to do some steps mentioned below:-
// Reverse the List. and handle the first node.
// For First Node: Set carry as 1 and temp -> data as 0 and move ahead.

// Just check where the data is 9 and carry is 1 and make that data equal to zero 
// ... and move forward with carry 1.
// If data is not 9 but carry is 1 then just temp- > data++.
// Nothing needs to be done when carry is 0 you can break..
// Do this till List is fully traversed or you can stop as soon as carry becomes 0 
// ... because no further nodes would need to be updated .
// After traversing, Reverse the list again and return the head.

// Special Case:
// If there is a list of type 9->9->9->9 then a carry will be generated at last.
// your current list would contain 0->0->0->0. So, just create a node having data equal to 1 at the head(new list : 1->0->0->0->0) and return the head.
// Or you could create a function off bool type that tells us whether all the numbers in the list are 9 or not. If true then just create a node with value 1 and add it to the head and set data of all other nodes in list as 0.


void Reverse(Node *&head)
{
    Node *previousNode = NULL;
    Node *currentNode = head;
    Node *nextNode = NULL;
    while(currentNode)
    {
        nextNode = currentNode -> next;
        currentNode -> next = previousNode;
        previousNode =c urrentNode;
        currentNode=nextNode;
    }
    head = previousNode;
}

Node* addOne(Node *head)
{
    Node *temp = head;
    while(temp -> next)
    {
        temp = temp -> next;
    }
    if(temp -> data==9)
    {
        Reverse(head);
        int carry = 1;
        temp = head;
        temp -> data = 0;
        temp = temp -> next;
        while(temp)
        {
            if(carry == 1)
            {
                if(temp -> data == 9)
                {
                    temp -> data = 0;
                    carry = 1;
                }
                else
                {
                    temp -> data++;
                    carry = 0;
                }
            }
            temp = temp -> next;
        }

        Reverse(head);

        if(carry == 1)
        {
            Node *n = new Node(1);
            n -> next=head;
            head = n;
        }
        return head;
    }
    else
    {
        temp -> data++;
        return head;
    }
}