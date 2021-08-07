// Given a binary matrix mat of size n * m, find out the maximum size square sub-matrix with all 1s.

// https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1#

// https://www.youtube.com/watch?v=UagRoA3C5VQ

int maxSquare(int n, int m, vector<vector<int>> mat){
    vector<vector<int>> dp(n, vector<int>(m, 0));
    
    int ans = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = mat[i][j];
            } else {
                if(mat[i][j]) {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                } 
            }
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}