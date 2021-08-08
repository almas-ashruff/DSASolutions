// Given two strings. The task is to find the length of the longest common substring.

// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1#

// https://www.youtube.com/watch?v=NvmJBCn4eQI

int longestCommonSubstr (string s1, string s2, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    
    int maxLen = 0;
    
    // comparing the suffix of each possible prefix of both strings for 
    // possible match
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < m + 1; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLen = max(maxLen, dp[i][j]);
            }
        }
    }
    return maxLen;
}