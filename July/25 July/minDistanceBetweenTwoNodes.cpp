// Given a binary tree and two node values your task is to find the minimum distance between them.

// https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1#


// Find the lowest common ancestor (LCS)
// Find the distance of the two nodes from the ancestor
// Add the two distances.

Node *LCS(Node *root, int a, int b) {
    if(!root) {
        return NULL;
    }
    
    if(root -> data == a || root -> data == b) {
        return root;
    }
    
    Node *leftNode  = LCS(root -> left, a, b);
    Node *rightNode = LCS(root -> right, a, b);
    
    if(leftNode && rightNode) {
        return root;
    }
    
    return !leftNode ? rightNode : leftNode;
}

int distance(Node *root, int key) {
    if(!root) {
        return 0;
    }
    
    queue<pair<Node *, int>> q;
    
    q.push({root, 0});
    
    while(!q.empty()) {
        Node *temp = q.front().first;
        int dist = q.front().second;
        
        q.pop();
        
        if(temp -> data == key) {
            return dist;
        }
        
        if(temp -> left) {
            q.push({temp -> left, dist + 1});
        }
        
        if(temp -> right) {
            q.push({temp -> right, dist + 1});
        }
    }
}
   
int findDist(Node* root, int a, int b) {
    Node *lcs = LCS(root, a , b);
    
    int d1 = distance(lcs, a);
    int d2 = distance(lcs, b);
    
    return d1 + d2;
}