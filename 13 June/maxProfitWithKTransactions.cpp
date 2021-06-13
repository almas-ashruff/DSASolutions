#include <bits/stdc++.h>
using namespace std;

// AlgoExpert - Very Hard
// You are given an integer array prices where prices[i] is 
// the price of a given stock on the ith day, and an integer k.
// Find the maximum profit you can achieve. 
// You may complete at most k transactions.

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// https://practice.geeksforgeeks.org/problems/maximum-profit4657/1
// Solution - 

int maxProfitWithKTransactions(vector<int> prices, int k) {
  if(prices.size() == 0){
		return 0;
	}
	vector<vector<int>> profits(k + 1, vector<int> (prices.size(), 0));
	
    // t = transaction, d = day
    // profits[t][d] = profit at transaction number t on day d
    // first row = 0, because we are having 0 transactions at t = 0.
    // first column  = 0, as we are having 0 transactions as there is just one value

	for(int t = 1; t < k + 1; t++) {
		int maxThusFar = INT_MIN;
		// max thus far is either 
        // (i) same as previous max thus far.
        // (ii) if we bought the share at the current price today ( the part with minus prices[d - 1]) 
        //  ... + max profit till the previous day for one less transaction
		for(int d = 1; d < prices.size(); d++) {
			maxThusFar = max(maxThusFar, profits[t - 1][d - 1] - prices[d - 1]);
			profits[t][d] = max(profits[t][d - 1], maxThusFar + prices[d]);
            
            // Now, we either don't sell the stock we bought when we calculated maxThusFar
            // Or we do. 
            // Case 1 - we will have same profit as one less day as we haven't sold anything
            // Case 2 - We will add current Selling price to max thus far

		}
	}
	return profits[k][prices.size() - 1];
}


