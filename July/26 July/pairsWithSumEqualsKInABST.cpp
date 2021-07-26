// Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x. 
// Your task is to complete the function countPairs(), 
// that returns the count of all pairs from both the BSTs whose sum is equal to x.

// https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1

void inorder(Node *root, unordered_map<int, int> &ans){
    if(!root) {
        return;
    }
    inorder(root -> left, ans);
    ans[root -> data]++;
    inorder(root -> right, ans);
}

int countPairs(Node* root1, Node* root2, int x) {
    int count = 0;
    unordered_map<int, int> ans, ans2;
    inorder(root1, ans);
    inorder(root2, ans2);
    for(auto p: ans){
        if(ans2[x - p.first]){
            count++;
        }
    }
    return count;
}