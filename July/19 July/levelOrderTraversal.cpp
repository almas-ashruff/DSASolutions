// Given a binary tree, find its level order traversal.
// Level order traversal of a tree is breadth-first traversal for the tree.

// https://practice.geeksforgeeks.org/problems/level-order-traversal/1#

vector<int> levelOrder(Node* node)
{
    vector<int> ans;
    if(!node) {
        return ans;
    }
    
    queue<Node *> queue;
    queue.push(node);
    while(!queue.empty()) {
        Node *temp = queue.front();
        ans.push_back(temp -> data);
        if(temp -> left) {
            queue.push(temp -> left);
        }
        if(temp -> right) {
            queue.push(temp -> right);
        }
        queue.pop();
    }
    return ans;
}