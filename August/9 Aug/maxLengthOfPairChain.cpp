// You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.
// A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.
// Return the length longest chain which can be formed.
// You do not need to use up all the given intervals. You can select pairs in any order.

// https://leetcode.com/problems/maximum-length-of-pair-chain/
// https://practice.geeksforgeeks.org/problems/max-length-chain/1

// https://leetcode.com/problems/maximum-length-of-pair-chain/discuss/816741/C%2B%2B-Simple-and-Clean-Solution-With-Comments

int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end());
    
    vector<int> dp(pairs.size(), 1);
    
    int longest = 1;
    
    for(int i = 1; i < pairs.size(); i++) {
        for(int j = 0; j < i; j++) {
            if((pairs[j][1] < pairs[i][0]) && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                longest = max(longest, dp[i]);
            }
        }
    }
    return longest;
}