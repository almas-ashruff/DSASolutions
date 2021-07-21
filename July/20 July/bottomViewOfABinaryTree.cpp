// Given a binary tree, print the bottom view from left to right.
// A node is included in bottom view if it can be seen when we look at the tree from bottom.

// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1#

vector <int> bottomView(Node *root) {
    map<int, vector<int>> map;
    vector<int> ans;
    queue<pair<Node *, int>> q;
    
    if(!root) {
        return ans;
    }
    
    q.push({root, 0}); // node and its horizontal distance
    
    int leftDist = INT_MAX;
    int rightDist = INT_MIN;
    
    while(q.size()) {
        Node *node = q.front().first;
        int hDist = q.front().second;
        q.pop();
        map[hDist].push_back(node -> data);
        
        leftDist = min(leftDist, hDist);
        rightDist = max(rightDist, hDist);
        
        
        if(node -> left){
            q.push({node -> left, hDist - 1});
        }
        if(node -> right){
            q.push({node -> right, hDist + 1});
        }
    }
    
    for(int i = leftDist; i <= rightDist; i++) {
        ans.push_back(map[i][map[i].size() - 1]);
    }
    return ans;
}

