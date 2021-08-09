// Given a 2D matrix M of dimensions RxC. Find the maximum sum subarray in it.

// https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1#

// 2D Kadene 
// https://www.youtube.com/watch?v=yCQN096CwWM

int maximumSumRectangle(int r, int c, vector<vector<int>> mat) {
    int sum = INT_MIN;
    
    for(int i = 0; i < r; i++) {
        vector<int> column(c);
        
        for(int j = i; j < r; j++) {
            for(int col = 0; col< c; col++) {
                column[col] += mat[j][col];
            } 
            sum = max(sum, kadene(column, c));
        }
    }
    return sum;
}

int kadene(vector<int> v, int n) {
    int maxSoFar = INT_MIN;
    int currentMax = 0;
    
    for(int i = 0; i < n; i++) {
        currentMax += v[i];
        maxSoFar = max(maxSoFar, currentMax);
        currentMax = max(0, currentMax);
    }
    
    return maxSoFar;
}