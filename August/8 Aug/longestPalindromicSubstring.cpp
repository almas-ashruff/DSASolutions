// Given a string s, return the longest palindromic substring in s.

// https://leetcode.com/problems/longest-palindromic-substring/


string longestPalindrome(string s) {
    int n = s.size();
    int start = 0, end = 0;
    
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    // dp[i][j] indicates whether substring s starting at index i 
    // and ending at j is palindrome
    
    
    for(int i = n - 1; i >= 0; i--){
    // keep increasing the possible palindrome string
        for(int j = i; j < n; j++) {
        // find the max palindrome within this window of (i,j)
            dp[i][j] = s[i] == s[j] && ((j - i) < 2 || dp[i + 1][j - 1]);
            // chars at i and j should match
            // if window is less than or equal to 2, 
            // palindrome
            
            if(dp[i][j] && (j - i > end - start)) {
				start = i;
				end = j;
			} 
        }
    }
    return n == 0 ? "": s.substr(start, end - start + 1); 
}