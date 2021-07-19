// Given a binary tree of size N, find its reverse level order traversal. 
// ie- the traversal must begin from the last level.

// https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1#


vector<int> reverseLevelOrder(Node *root) {
    vector<int> ans;
    stack<int> stack;
    if(!root) {
        return ans;
    }
    
    queue<Node *> queue;
    queue.push(root);
    
    while(!queue.empty()) {
        Node *temp = queue.front();
        queue.pop();
        stack.push(temp -> data);
        
        if(temp -> right) { 
            queue.push(temp -> right);
            // right is pushed first because order will be reversed in stack
        }
        
        if(temp -> left) {
            queue.push(temp -> left);
            // left is pushed second
        }
    }
    
    while(!stack.empty()) {
        ans.push_back(stack.top());
        stack.pop();
    }
    return ans;
}