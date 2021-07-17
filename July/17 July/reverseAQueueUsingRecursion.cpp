// Given a Queue Q containing N elements. 
// The task is to reverse the Queue. Your task is to complete the function rev(), 
// that reverses the N elements of the queue.

// https://practice.geeksforgeeks.org/problems/queue-reversal/1#

void reverse(queue<int> &q) {
    if(q.empty()) {
        return;
    }
    
    int data = q.front();
    q.pop();
    reverse(q);
    q.push(data);
    return;
}

queue<int> rev(queue<int> q)
{
    reverse(q);
    return q;
}