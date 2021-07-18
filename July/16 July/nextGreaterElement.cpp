// Given an array arr[ ] of size N having distinct elements, 
// the task is to find the next greater element for each element of the array 
// in order of their appearance in the array.
// Next greater element of an element in the array is the nearest element on the right 
// which is greater than the current element.
// If there does not exist next greater of current element, then next greater element 
// for current element is -1. For example, next greater of the last element is always -1.

// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1#

vector<long long> nextLargerElement(vector<long long> arr, int n){
    vector<long long> ans(n);
    stack<long long> st;
    st.push(arr[n-1]); 
    // pushing the last element in the stack
    
    ans[n - 1] = -1;
    // last element is -1
    
    for(int i = n - 2; i >= 0; i--) {
        while(!st.empty() && arr[i] > st.top()) {
        // if st.top is not greater, pop it
            st.pop();
        }
        if(st.empty()) {
        // if stack is empty, put -1 for that element
        ans[i] = -1;
        } else {
            ans[i] = st.top();
            // else push st.top() in the ans array
        }
        
        st.push(arr[i]);
        // pushing element from array into stack for next for loop
    }
    
    return ans;
}