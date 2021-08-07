// Given an integer N denoting the Length of a line segment. 
// You need to cut the line segment in such a way that the cut length of a line segment 
// each time is either x , y or z. Here x, y, and z are integers.
// After performing all the cut operations, your total number of cut segments must be maximum.

// https://practice.geeksforgeeks.org/problems/cutted-segments1642/1

// https://www.youtube.com/watch?v=z6Lvf8P_fEE

int maximizeTheCuts(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, 0);
    
    for(int i  = 1; i < n + 1; i++) {
        if(i >= x && dp[i - x] != -1) {
            dp[i] = max(dp[i] , 1 + dp[i - x]);
        }
        
        if(i >= y && dp[i - y] != -1) {
            dp[i] = max(dp[i] , 1 + dp[i - y]);
        }
        
        if(i >= z && dp[i - z] != -1) {
            dp[i] = max(dp[i] , 1 + dp[i - z]);
        }
        
        if(dp[i] == 0) {
            dp[i] = -1;
        }
    }
    
    return max(dp[n], 0);
}