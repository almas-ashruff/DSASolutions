// Given an array A[] of size N, find the longest subsequence such that 
// difference between adjacent elements is one.

// https://practice.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1#

int longestSubsequence(int n, int arr[])
{
    vector<int> dp(n, 1);
    int maxSeq = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(abs(arr[j] - arr[i]) == 1 && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
            
            maxSeq = max(maxSeq, dp[i]);
        }
    }
    return maxSeq;
}