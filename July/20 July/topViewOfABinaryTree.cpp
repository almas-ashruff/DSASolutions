// Given below is a binary tree. The task is to print the top view of binary tree. 
// Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. 

// https://www.youtube.com/watch?v=LscPXvD1N1A
// https://www.youtube.com/watch?v=DhgD8dyp8RM


vector<int> topView(Node *root)
{
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
        ans.push_back(map[i][0]);
    }
    return ans;
}