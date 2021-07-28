// Given a sorted array. Convert it into a Height balanced Binary Search Tree (BST).
// Height balanced BST means a binary tree in which the depth of the left subtree and 
// the right subtree of every node never differ by more than 1.

// https://practice.geeksforgeeks.org/problems/array-to-bst4443/1#

vector<int> sortedArrayToBST(vector<int> &nums) {
    vector<int> ans(nums.size(), 0);
    
    int index = 0;
    
    arrayToBST(nums, ans, 0, nums.size() - 1, index);
    
    return ans;
}

void arrayToBST(vector<int> &nums, vector<int> &ans, int low, int high, int &index) {
    if(low <= high) {
        int mid = low + (high - low) / 2;
        ans[index] = nums[mid];
        index++;
        arrayToBST(nums, ans, low, mid - 1, index);
        arrayToBST(nums, ans, mid + 1, high, index);
    }
}