// Given a string str, a partitioning of the string is a palindrome partitioning 
// if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for 
// palindrome partitioning of given string.

// https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1#

// https://www.youtube.com/watch?v=qmTtAbOTqcg

int palindromicPartition(string str)
{
    int n = str.size();
    bool dp[n][n];
    
    for(int g = 0; g < n; g++) {
        for(int i = 0, j = g; j < n; i++, j++) {
            if(g == 0) {
                dp[i][j] = true;
            } else if (g == 1) {
                if(str[i] == str[j]) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = false;
                }
            } else {
                if(str[i] == str[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = false;
                }
            }
        }
    }
    
    
    int ans[n];
    ans[0] = 0;
    
    for(int j = 1; j < n; j++) {
        if(dp[0][j]) {
            ans[j] = 0;
        } else {
            int minCuts = INT_MAX;
            for(int i = j; i >= 1; i--) {
                if(dp[i][j]) {
                    minCuts = min(minCuts, ans[i - 1]);
                }
            }
            ans[j] = minCuts + 1;
        }
    }
    return ans[n - 1];
}