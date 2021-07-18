// Given an integer K and a queue of integers, 
// we need to reverse the order of the first K elements of the queue, 
// leaving the other elements in the same relative order.
// Only following standard operations are allowed on queue.

// enqueue(x) : Add an item x to rear of queue
// dequeue() : Remove an item from front of queue
// size() : Returns number of elements in queue.
// front() : Finds front item.

// https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1#

queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> stack;
    
    int size = q.size() - k;
    
    while(k--) {
        stack.push(q.front());
        q.pop();
    } // push k elements in the stack
    
    while(!stack.empty()) {
        q.push(stack.top());
        stack.pop();
    } // put them back in the queue -> reversing them
    
    while(size--) {
        q.push(q.front());
        q.pop();
    } // push the queue elements in the queue at the back
    
    return q;
}