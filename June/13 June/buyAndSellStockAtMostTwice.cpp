#include <bits/stdc++.h>
using namespace std;

// You are given an prices prices where prices[i] is the price of a given stock on the ith day.
// Find the maxValimum profit you can achieve. You may complete at most two transactions.

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// https://www.youtube.com/watch?v=kSfPhRHULgs

// DP solution-

// First iteration finds out the maximum profit, going right to left, for a given index.
// Second iteration finds the maximum profit, goinf left to right, and adds it to the previous max profit till a particular index.

// Important -
// This solution works because the first loop calculates the maximum profit that can be made
// from trading shares after the current index
// And
// the second loop calculates the maximum profit that could be made trading till before the current index.



int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<int> dp(n);
    // stores the max profits till a particular index.


    int maxVal = prices[n - 1]; // max value for the first iteration, initialized with the last value.
    int minVal = prices[0]; // min value for the second iteration, initialized with the 0th value.

    // The array is iterated over twice.

    // First time, the maximum value of profit till a particular index is calculated and stored, going right to left.

    for(int i = n - 2; i >= 0; i--) {
        if(prices[i] > maxVal) {
            maxVal = prices[i]; // Max value is updated
        }
        dp[i] = max(dp[i + 1], maxVal - prices[i]); 
        // maximum profit till a current index is the maximum of the previous index,
        // and the difference of the maximum value and the current share price.

        // BASICALLY, MAX PROFIT TILL NOW IF COMPULSORY MIN BUYING DATE WAS TODAY
    }


    // Second time, the maximum value of profit till a particular index is calculated and stored, going left to right.
    for(int i = 1; i < n; i++) {
        if(prices[i] < minVal) {
            minVal = prices[i]; // Min value is updated
        }
        dp[i] = max(dp[i - 1], dp[i] + (prices[i] - minVal));
        // maximum profit is the max of profit till previous index, and the current profit from 
        // the previous iteration plus the difference of the current price and minimum price before the current index.

        // BASICALLY, MAX PROFIT TILL NOW IF COMPULSORY MAX SELLING DATE WAS TODAY
    }
    return dp[n - 1];
}