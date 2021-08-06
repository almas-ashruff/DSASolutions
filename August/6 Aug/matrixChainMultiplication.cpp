// Given a sequence of matrices, find the most efficient way to multiply 
// these matrices together. The efficient way is the one that involves 
// the least number of multiplications.
// The dimensions of the matrices are given in an array arr[] of size N 
// (such that N = number of matrices + 1) where the ith matrix has 
// the dimensions (arr[i-1] x arr[i]).

// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1#

// https://www.youtube.com/watch?v=pEYwLmGJcvs  !IMP


int matrixMultiplication(int n, int arr[])
{
    n--;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    
    for(int x = 1; x < n + 1; x++) {
        for(int i = 1, j = x; j < n + 1; i++, j++) {
            if(x == 1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = INT_MAX;
                for(int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j]);
                }
            }
        }
    }
    return dp[1][n];
}