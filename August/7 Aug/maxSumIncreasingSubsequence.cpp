// Given an array arr of N positive integers, the task is to find the maximum sum 
// increasing subsequence of the given array.

// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1#

// https://www.algoexpert.io/questions/Max%20Sum%20Increasing%20Subsequence


int maxSumIS(int arr[], int n)  
{  
    vector<int> dp(n, 0);
    
    int maxSum = 0;
    for(int i = 0; i < n; i++) {
        dp[i] = arr[i];
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i] && dp[j] + arr[i] > dp[i]) {
                dp[i] = dp[j] + arr[i];
            }
        }
         maxSum = max(maxSum, dp[i]);
    }
    return maxSum;
} 