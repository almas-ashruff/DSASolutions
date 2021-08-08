// Given a set of N items, each with a weight and a value, and a weight limit W. 
// Find the maximum value of a collection containing any of the N items 
// any number of times so that the total weight is less than or equal to W.

// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1#

int knapSack(int n, int w, int val[], int wt[])
{
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < w + 1; j++) {
            if(wt[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i][j - wt[i - 1]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][w];
}