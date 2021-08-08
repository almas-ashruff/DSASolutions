// Given an array cost[] of positive integers of size N and an integer W, 
// cost[i] represents the cost of ‘i’ kg packet of oranges, the task is to find 
// the minimum cost to buy W kgs of oranges. If it is not possible to buy 
// exactly W kg oranges then the output will be -1

// Note:
// 1. cost[i] = -1 means that ‘i’ kg packet of orange is unavailable
// 2. It may be assumed that there is infinite supply of all available packet types.

// https://practice.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1#


int minimumCost(int cost[], int n, int w) 
{ 
    vector<vector<int>> dp(w + 1, vector<int>(n + 1, INT_MAX));
    
    // dp -> min cost to fill weight with given fruit cost
    // columns -> weights
    // rows -> weight available for the index of the column
    
    
    for(int i = 0; i < w + 1; i++) {
        for(int j = 0; j < n + 1; j++) {
            if(i == 0) {
            // when weight is 0 -> 0 cost
                dp[i][j] = 0;
            } else if (j == 0) {
            // when fruit weight available is 0,
            // Infinite of such available fruits are needed
                dp[i][j] = INT_MAX;
            } else {
                if(cost[j - 1] != -1 && j <= i && dp[i - j][j] != INT_MAX) {
                // if 1. fruit packet is available for that weight, 
                // 2. weight of the packet is less than required weight 
                // and 3. if we include the current packet, the cost of required weight minus
                // the weight of the current packet should not have an infinite cost. 
                // i.e. it should be possible
                    dp[i][j] = min(dp[i][j - 1], cost[j - 1] + dp[i - j][j]);
                    // current cost = min of 1. cost of same weight excluding the current packet
                    // 2. cost of current weight + cost of req. wt. - curr. wt. from the dp
                } else {
                // if req wt. - curr. wt had infinite cost in the dp,
                // current dp value = cost of the same wt. without current packet
                    dp[i][j] = dp[i][j - 1];
                    
                }
            }
        }
    }
    
    return dp[w][n] != INT_MAX ? dp[w][n] : -1;
    // if cost is not infinite, return the cost. else -1
} 