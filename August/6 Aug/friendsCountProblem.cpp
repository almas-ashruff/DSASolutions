// Given N friends, each one can remain single or can be paired up with 
// some other friend. Each friend can be paired only once. 
// Find out the total number of ways in which friends can remain single 
// or can be paired up.
// Note: Since answer can be very large, return your answer mod 10^9+7.

// https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1#

// https://www.youtube.com/watch?v=SHDu0Ufjyk8

int countFriendsPairings(int n) 
{ 
    
    if(n < 3) {
        return n;
    }
    vector<long long int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    
    long long int mod = 1e9 + 7;
    for(int i = 3; i < n + 1; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] * (i - 1)) % mod;
    }
    
    return dp[n];
}