// Implement a Queue using 2 stacks s1 and s2 .
// A Query Q is of 2 Types
// (i) 1 x (a query of this type means  pushing 'x' into the queue)
// (ii) 2   (a query of this type means to pop element from queue and print the poped element)

// https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1#


int StackQueue :: pop()
{
        if(s1.empty()) {
            return -1;
        }  
        
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        
        int res = s2.top();
        s2.pop();
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return res;
}
