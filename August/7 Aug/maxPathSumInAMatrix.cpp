// Given a NxN matrix of positive integers. 
// There are only three possible moves from a cell Matrix[r][c].

// Matrix [r+1] [c]
// Matrix [r+1] [c-1]
// Matrix [r+1] [c+1]
// Starting from any column in row 0 return the largest sum of any of the paths up to row N-1.

// https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1#

int maximumPath(int n, vector<vector<int>> mat)
{
    int dp[n + 1][n + 1];
    for(int i=0;i<=n;i++) {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            dp[i][j] = mat[i - 1][j - 1] + max({dp[i - 1][j], dp[i - 1][j - 1], dp[i - 1][j + 1]});
        }
    }
    
    int ans = INT_MIN;
    
    for(int i = 0; i < n + 1; i++) {
        ans = max(ans, dp[n][i]);
    }
    
    return ans;
}