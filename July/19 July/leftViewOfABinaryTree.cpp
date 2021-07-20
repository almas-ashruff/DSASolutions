Given a Binary Tree, print Left view of it. 
Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. 
The task is to complete the function leftView(), which accepts root of the tree as argument.

https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#

// https://www.youtube.com/watch?v=jCqIr_tBLKs


// modified level order traversal

vector<int> leftView(Node *root)
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
            if(i == 0) {
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