#include <bits/stdc++.h>
using namespace std;

// Given two sequences, find the length of longest subsequence present in both of them. 
// Both the strings are of uppercase.

// https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1
// https://www.algoexpert.io/questions/Longest%20Common%20Subsequence


// Create a dp that compares the characters of two strings.
// If both cars are same, the current value in the dp = value in the dp (longest subsequence) if the last char is removed from both strings + 1
// Else, value in the dp = max of the two comparisions -> without the last char of each string (top and left)
int lcs(int x, int y, string s1, string s2)
{
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    
    for(int i = 1; i < s1.size() + 1; i++) {
        for(int j = 1; j < s2.size() + 1; j++) {
            if(s1[i - 1] == s2[j - 1]) { 
            // string is compared of one index prior since the first row and column of the dp is 0, so it does not match the index
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[s1.size()][s2.size()];
}