// Given a binary tree, find out whether it contains a 
// duplicate sub-tree of size two or more, or not.

// https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1


unordered_map<string, int> count; 
// to store all possible substrings 

string helper(Node *root) {
    if(!root) {
        return "";
    }
    string left = helper(root -> left); 
    // recursion over left
    string right = helper(root -> right);
    // recursion over right
    
    count[left + right + root -> data]++;
    // increase the count of the substring
    
    return left + right + root -> data;
    // return the substring
    
}


int dupSub(Node *root) {
     helper(root); // call helper on root
     
     for(auto str : count) { // for every pair in the map
         if(str.first.size() > 1 && str.second > 1) {
            // if the substring has a size >= 2, 
            // and the count of the substring is greater than one
             return true;
         }
     }
     return false;
}