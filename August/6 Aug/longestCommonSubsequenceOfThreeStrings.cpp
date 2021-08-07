// Given 3 strings A, B and C, the task is to find the 
// longest common sub-sequence in all three given sequences.

// https://practice.geeksforgeeks.org/problems/lcs-of-three-strings0028/1#

// https://www.youtube.com/watch?v=86F87X8iRd0

int LCSof3 (string a, string b, string c, int n1, int n2, int n3)
{
    
    vector<vector<vector<int>>> dp(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, 0)));
    
    for(int i = 1; i < n1 + 1; i++) {
        for(int j = 1; j < n2 + 1; j++) {
            for(int k = 1; k < n3 + 1; k++) {
                if(a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1]) {
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                } else {
                    dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                }
            }
        }
    }
    return dp[n1][n2][n3];
}