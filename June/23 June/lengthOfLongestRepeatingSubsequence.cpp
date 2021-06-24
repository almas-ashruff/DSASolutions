#include <bits/stdc++.h>
using namespace std;

// https://www.algoexpert.io/questions/Subarray%20Sort

// Given a string, find the length of the longest repeating subsequence such that 
// the two subsequences don't have same string character at the same position, 
// i.e., any i'th character in the two subsequences shouldn't have the same index in the original string.

// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1#
// https://www.youtube.com/watch?v=oL7GCrcdaJI

// Find the LCS of the string with itself, 
// such that the comparing characters are not at the same index.

// Steps - 
// 1. Create a dp of n+1, n+1 length. The 0th Row and Column will contain the null character.
// 2. Check if the character at index i is equal to the char at index j, when i != j.
// 3. If true, add 1 to the diagonally previous value and store in the i * j index of the dp.
// 4. If false, find the max from the previous or top value and store in the current index. 


int LongestRepeatingSubsequence(string str){
    int n = str.size();
    int dp[n + 1][n + 1]
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if(str[i - 1] == str[j - 1] && i != j) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}