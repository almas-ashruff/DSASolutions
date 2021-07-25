// Given a binary tree of size N, your task is to that 
// find all duplicate subtrees from the given binary tree.

// https://practice.geeksforgeeks.org/problems/duplicate-subtrees/1#

string helper(Node *root, vector<Node *> &ans) {
    if(!root) {
        return "$";
    }
    
    string s = to_string(root -> data);
    
    s = s + "" + helper(root -> right, ans) + "" + helper(root -> left, ans);
    
    stringMap[s]++;
    if(stringMap[s] == 2) {
        ans.push_back(root);
    }        
    return s;
}

vector<Node*> printAllDups(Node* root)
{
    stringMap.clear();
    vector<Node *> ans;
    string s = helper(root, ans);
    return ans;
}