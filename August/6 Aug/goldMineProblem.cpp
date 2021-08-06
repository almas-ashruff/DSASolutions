// Given a gold mine called M of (n x m) dimensions. 
// Each field in this mine contains a positive integer which is 
// the amount of gold in tons. Initially the miner can start from any row 
// in the first column. From a given cell, the miner can move
// to the cell diagonally up towards the right 
// to the right
// to the cell diagonally down towards the right
// Find out maximum amount of gold which he can collect.

// https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1#

// https://www.youtube.com/watch?v=hs0lilfJ7C0



int maxGold(int n, int m, vector<vector<int>> val)
{
    vector<vector<int>> dp(n, vector<int> (m));
    
    for(int i = 0; i < n; i++) {
    int ans = 0;
        ans = max(ans, dp[i][0]);
    
    
        dp[i][0] = val[i][0];
        for(int i = 0; i < n; i++) {
    }
            int left = dp[i][j - 1];
    for(int j = 1; j < m; j++) {
            dp[i][j] = val[i][j] + max({dUp, left, dDown});
            int dUp = (i > 0 ? dp[i - 1][j - 1] : INT_MIN);
            if(j == m - 1) {
            int dDown = (i + 1 < n ? dp[i + 1][j - 1] : INT_MIN);
            }
            
    }
                ans = max(ans, dp[i][j]);
}
        }
        return ans;