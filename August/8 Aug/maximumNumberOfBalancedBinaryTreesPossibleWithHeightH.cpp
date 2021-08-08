// Given a height h, count the maximum number of balanced binary trees 
// possible with height h. Print the result modulo 10^9 + 7.
// Note : A balanced binary tree is one in which for every node, 
// the difference between heights of left and right subtree is not more than 1.

// https://practice.geeksforgeeks.org/problems/bbt-counter4914/1

// https://www.geeksforgeeks.org/count-balanced-binary-trees-height-h/
// https://www.youtube.com/watch?v=pyO2FJE7G9o

long long int countBT(int h) { 
    if(h == 0 || h == 1) {
        return 1;
    }
    
    long long int mod = 1e9 + 7;
    long long int dp[h + 1];
    
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i = 2; i < h + 1; i++) {
        dp[i] = (((dp[i - 1] * dp[i - 1]) % mod) + ((dp[i - 1] * dp[i - 2] * 2) % mod)) % mod;
    }
    
    return dp[h];
}
