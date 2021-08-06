// Given two integers n and r, find nCr. Since the answer may be very large, 
// calculate the answer modulo 10^9+7.

// https://practice.geeksforgeeks.org/problems/ncr1019/1#

// geeksforgeeks.org/compute-ncr-p-set-1-introduction-and-dynamic-programming-solution/

int nCr(int n, int r){
    long long int mod = 1e9 + 7;
    
    vector<vector<int>> dp(n + 1, vector<int>(r + 1, -1));
    return helper(n, r, dp) % mod;
}

int helper(int n, int r, vector<vector<int>> &dp) {
    int mod = 1e9 + 7;
    
    if(r > n) {
        dp[n][r] = 0;
        return dp[n][r];
    }
    
    if(r == 0 || r == n) {
        dp[n][r] = 1;
        return dp[n][r];
    }
    
    if(r == 1) {
        dp[n][r] = n % mod;
        return dp[n][r];
    }
    
    if(dp[n][r] != -1) {
        return dp[n][r] % mod;
    }
    
    dp[n][r] = (helper(n - 1, r - 1, dp) + helper(n - 1, r, dp)) % mod;
    
    return dp[n][r];
    
}