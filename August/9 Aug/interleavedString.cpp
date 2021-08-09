// Given strings A, B, and C, find whether C is formed by an interleaving of A and B.

// An interleaving of two strings S and T is a configuration where they are 
// divided into non-empty substrings such that:

// S = S1 + S2 + ... + SN
// T = T1 + T2 + ... + TM
// |N - M| <= 1
// The interleaving is S1 + T1+ S2 + T2 + S3 + T3 + ... or T1 + S1+ T2 + S2 + T3 + S3 ...
// Note: a + b is the concatenation of strings a and b.

// Return true if C  is formed by an interleaving of A and B, else return false.

// https://practice.geeksforgeeks.org/problems/interleaved-strings/1#


// https://leetcode.com/problems/interleaving-string/
// https://leetcode.com/problems/interleaving-string/discuss/31879/My-DP-solution-in-C%2B%2B


bool isInterleave(string s1, string s2, string s3) 
{
    if(s3.size() != s2.size() + s1.size()) {
        return false;
    }
    
    bool dp[s1.size() + 1][s2.size() + 1];
    
    for(int i = 0; i < s1.size() + 1; i++) {
        for(int j = 0; j < s2.size() + 1; j++) {
            if(i == 0 && j == 0) { // if both strings are empty
                dp[i][j] = true;
            } else if(i == 0) { // if first string is empty
                dp[i][j] = dp[i][j - 1] && (s2[j - 1] == s3[j - 1]);
            } else if(j == 0) { // if second string is empty
                dp[i][j] = dp[i - 1][j] && (s1[i - 1] == s3[i - 1]);
            } else {
                dp[i][j] = (dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1]))
                    || (dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]));
            } 
        }
    }
    return dp[s1.size()][s2.size()];
}