// Given K sorted arrays arranged in the form of a matrix of size K*K. 
// The task is to merge them into one sorted array.

// https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1#

// https://www.geeksforgeeks.org/merge-k-sorted-arrays/

typedef pair<int, pair<int,int>> idx;
// p.first --> element value
// p.second.first --> index on parent array -> row
// p.second.second --> index on current array -> column


//Function to merge k sorted arrays.
vector<int> mergeKArrays(vector<vector<int>> arr, int k) {
    vector<int> ans;
    
    priority_queue<idx, vector<idx>, greater<idx>> pq;


    for(int i = 0; i < k; i++) {
        pq.push({arr[i][0], {i, 0}});
        // in the pq, push all the elements from the first column
        // and their rowIdx and columnIdx
    }

    while(pq.size()) { // while pq exists
        auto node = pq.top();
        pq.pop();
        ans.push_back(node.first); // push the smallest val in the ans array
    
        // if an element exists on the right of the smallest element in the matrix
        // push the right element in the pq
        int parentIdx = node.second.first;
        int currentIdx = node.second.second;
    
        if(currentIdx + 1 < k) {
            pq.push({arr[parentIdx][currentIdx + 1], {parentIdx, currentIdx + 1}});
        }
    }
    return ans;
}