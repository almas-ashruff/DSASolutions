// Given an array arr[] of size N, check if it can be partitioned into two parts such that 
// the sum of elements in both parts is the same.


// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1#

int equalPartition(int n, int nums[]) {
    int sum = 0;
    for(int i=0;i<n;++i) {
        sum += nums[i];
    }
    
    if(sum % 2 == 1)  { // odd sum
        return false;
    }
    
    bool dp[n + 1][sum / 2 + 1];
    
    // columns -> values given till an index
    // rows -> sum that needs to be formed
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= sum / 2; j++) {
            if(i == 0 || j == 0) {   
            // when sum to be formed is 0 or the given value is 0
            // the sum cannot be formed
                dp[i][j] = false;
            }
            else if(nums[i - 1] > j) {
            // when the current value is greater than the current required sum
            // use the sum formed if the available values did nit include the 
            // current value
                dp[i][j] = dp[i - 1][j];
            }
            else if(nums[i - 1] == j) {
            // if the current value equals the required sum
                dp[i][j] = true;
            }
            else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                // current sum is possible if it was possible 
                // without the current value,
                // or if the sum of 
                // curr req. sum minus current valuen was possible 
                // without the current value
            }
        }
    }
    return dp[n][sum / 2];
}