// Given a fence with n posts and k colors, find out the number of ways of painting the fence such that 
// at most 2 adjacent posts have the same color. Since answer can be large return it modulo 10^9 + 7.

// https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1

// https://www.youtube.com/watch?v=7_C9kpXEgdQ

long long countWays(int n, int k){
    if(n == 0) {
        return 0;
    }
    
    if(n == 1) {
        return k;
    }
    
    if(n == 2) {
        return k * k;
    }
    
    long long int mod = 1e9 + 7;
    vector<long long> dp(n + 1, 0);
    
    dp[0] = 0;
    dp[1] = k;
    dp[2] = k * k;
    
    for(int i = 3; i < n + 1; i++) {
        dp[i] = ((k - 1) * (dp[i - 1] + dp[i - 2])) % mod;
    }
    
    return dp[n];
}