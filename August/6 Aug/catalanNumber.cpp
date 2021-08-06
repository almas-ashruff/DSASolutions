// Given a number N. The task is to find the Nth catalan number.
// The first few Catalan numbers for N = 0, 1, 2, 3, … are 
// 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …

// https://practice.geeksforgeeks.org/problems/nth-catalan-number0817/1#
// https://www.geeksforgeeks.org/program-nth-catalan-number/



cpp_int findCatalan(int n) 
{
    vector<cpp_int> dp(n + 1, 0);
    
    dp[0] = 1; dp[1] = 1;
    for(int i = 2; i < n + 1; i++) {
        for(int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    
    return dp[n];
}