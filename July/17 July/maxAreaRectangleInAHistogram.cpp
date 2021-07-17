// Find the largest rectangular area possible in a given histogram where 
// the largest rectangle can be made of a number of contiguous bars. For simplicity.
// Assume that all bars have the same width and the width is 1 unit.

// https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1#


long long getMaxArea(long long arr[], int n)
{
    if(n == 0) {
        return 0;
    }
    
    if(n == 1) {
        return 1;
    }
    
    // find left Boundaries
    vector<int> leftBoundary(n);
    
    stack<int> lb;
    
    for(int i = 0; i < n; i++) {
        while(!lb.empty() && arr[lb.top()] >= arr[i]) {
            lb.pop();
        }
        
        leftBoundary[i] = lb.empty() ? -1 : lb.top();
        lb.push(i);
    }
    
    // find right Boundaries
    
    vector<int> rightBoundary(n);
    stack<int> rb;
    
    for(int i = n - 1; i >= 0; i--) {
        while(!rb.empty() && arr[rb.top()] >= arr[i]) {
            rb.pop();
        }
        
        rightBoundary[i] = rb.empty() ? n : rb.top();
        rb.push(i);
    }
    
    // find max area
    
    long long maxArea = 0;
    
    for(int i = 0; i < n; i++) {
        int width = rightBoundary[i] - leftBoundary[i] - 1;
        long long area = arr[i] * width;
        
        maxArea = max(maxArea, area);
    }
    
    return maxArea;
}