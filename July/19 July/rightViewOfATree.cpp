// Given a Binary Tree, find Right view of it. 
// Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

// https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1#

// https://www.youtube.com/watch?v=jCqIr_tBLKs


// modified level order traversal

vector<int> rightView(Node *root)
{
    vector<int> ans; 
    if(!root) {
       return ans;
    }
   
    queue<Node *> queue;
    queue.push(root);
    while(!queue.empty()) {
        int size = queue.size();
        for(int i = 0; i < size; i++) {
            if(i == size - 1) {
               ans.push_back(queue.front() -> data);
            }
            if(queue.front() -> left) {
               queue.push(queue.front() -> left);
            }
            if(queue.front() -> right) {
               queue.push(queue.front() -> right);
            }
            queue.pop();
       }
    }
    return ans;
}