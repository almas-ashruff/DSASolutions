// Given two numbers represented by two linked lists of size N and M. The task is to return a sum list. 
// The sum list is a linked list representation of the addition of two input numbers from the last.

// https://www.algoexpert.io/questions/Sum%20of%20Linked%20Lists
// https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1#

// AlgoExpert Solution
using namespace std;

LinkedList *sumOfLinkedLists(LinkedList *linkedListOne,
                             LinkedList *linkedListTwo) {
  LinkedList *newListHead = new LinkedList(0);
	LinkedList *currentNode = newListHead;
	int carry = 0;
	
	LinkedList *nodeOne = linkedListOne;
	LinkedList *nodeTwo = linkedListTwo;
	
	while(nodeOne || nodeTwo || carry != 0){
		int valueOne = 0, valueTwo = 0, sumOfValues = 0;
		
		if(nodeOne){
			valueOne = nodeOne -> value;
		}
		if(nodeTwo){
			valueTwo = nodeTwo -> value;
		}
		
		sumOfValues = valueOne + valueTwo + carry;
		int newValue = sumOfValues % 10;
		LinkedList *newNode = new LinkedList(newValue);
		currentNode -> next = newNode;
		currentNode = currentNode -> next;
		
		carry = sumOfValues / 10;
		if(nodeOne){
			nodeOne = nodeOne -> next;
		}
		if(nodeTwo){
			nodeTwo = nodeTwo -> next;
		}
		
	}
	
	return newListHead -> next;
}





// GFG Solution

void Reverse(Node *&head)
{
    Node *previousNode = NULL;
    Node *currentNode = head;
    Node *nextNode = NULL;
    while(currentNode)
    {
        nextNode = currentNode -> next;
        currentNode -> next = previousNode;
        previousNode =currentNode;
        currentNode = nextNode;
    }
    head = previousNode;
}

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node *newListHead = new Node(0);
        Node *currentNode = newListHead;
        int carry = 0;
        
        Reverse(first);
        Node* nodeOne = first;
        Reverse(second);
        Node* nodeTwo = second;
        
        while(nodeOne || nodeTwo || carry != 0) {
            int valueOne = 0, valueTwo = 0, sumOfValues = 0;
            if(nodeOne) {
                valueOne = nodeOne -> data;
            }
            if(nodeTwo) {
                valueTwo = nodeTwo -> data;
            }
            sumOfValues = valueOne + valueTwo + carry;
            int newValue = sumOfValues % 10;
            
            Node *newNode = new Node(newValue);
            currentNode -> next = newNode;
            currentNode = currentNode -> next;
            carry = sumOfValues / 10;
            
            if(nodeOne) {
                nodeOne = nodeOne -> next;
            }
            if(nodeTwo) {
                nodeTwo = nodeTwo -> next;
            }
        }
        newListHead = newListHead -> next;
        Reverse(newListHead);
        return newListHead;
    }