// Given an array of integers arr[] and a number K.
// You can pair two numbers of the array if the difference between them is strictly less than K. 
// The task is to find the maximum possible sum of such disjoint pairs. 
// The Sum of P pairs is the sum of all 2P numbers of pairs.

// https://practice.geeksforgeeks.org/problems/pairs-with-specific-difference1533/1#

// https://www.youtube.com/watch?v=luzDD2FdCz0


int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
{
    long long int sum = 0;
    
    sort(arr, arr + n);
    
    vector<int> dp(n);
    dp[0] = 0;
    
    dp[1] = arr[1] - arr[0] < k ? arr[1] + arr[0] : 0;
    
    for(int i = 2; i < n; i++) {
        if(arr[i] - arr[i - 1] < k) {
            dp[i] = max(arr[i] + arr[i - 1] + dp[i - 2], dp[i - 1]);
        } else {
            dp[i] = dp[i - 1];
        }
    }
    return dp[n - 1];
}