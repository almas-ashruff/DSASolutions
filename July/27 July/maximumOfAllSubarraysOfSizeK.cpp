Given an array arr[] of size N and an integer K. 
Find the maximum for each and every contiguous subarray of size K.

// https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1#

// https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/


vector <int> max_of_subarrays(int *arr, int n, int k) {
    int i;
    
    deque<int> q;
    vector<int> ans;
    
    // find the initial window
    for(i = 0; i < k; i++) {
        while(!q.empty() && q.back() < arr[i]) {
            q.pop_back();
        }
        q.push_back(arr[i]);
    } 
    // The first element in the queue will always have 
    // the largest value in the window. 
    // If the element coming after the largest value are smaller,
    // they can exist in the queue in desc order.
        
    
    ans.push_back(q.front());
    // push the answer from the first window
        
    for(i = 1; i <= n - k; i++) {
        if(q.front() == arr[i - 1]) {
            q.pop_front();
            // pop when the value in the queue is outside the window
        }
        
        // push the largest value in the queue in the correct position 
        // as necessary from the above specified condition
        while(!q.empty() && q.back() < arr[i + k - 1]) {
            q.pop_back();
        }
        q.push_back(arr[i + k - 1]);
        
        // add the largest value from the current window in the answer array.
        // The window will slide in the next iteration
        ans.push_back(q.front());
    }
    
    return ans;
}